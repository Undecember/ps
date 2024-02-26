#include "web.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, string *userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string getHTML(const string& url) {
    CURL *curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

vector<pair<string, string>> getTests(const string& url) {
    string html = getHTML(url);
    myhtml_t* myhtml = myhtml_create();
    myhtml_init(myhtml, MyHTML_OPTIONS_DEFAULT, 1, 0);
    myhtml_tree_t* tree = myhtml_tree_create();
    myhtml_tree_init(tree, myhtml);

    myhtml_parse(tree, MyENCODING_UTF_8, html.c_str(), html.size());

    vector<pair<string, string>> samples;
    for (int i = 1;; ++i) {
        string inputId = "sample-input-" + to_string(i);
        string outputId = "sample-output-" + to_string(i);

        myhtml_collection_t* inputCollection = myhtml_get_nodes_by_tag_id(tree, NULL, myhtml_string_make(tree, inputId.c_str(), inputId.size()), NULL);
        myhtml_collection_t* outputCollection = myhtml_get_nodes_by_tag_id(tree, NULL, myhtml_string_make(tree, outputId.c_str(), outputId.size()), NULL);

        if (inputCollection->length == 0 || outputCollection->length == 0) {
            myhtml_collection_destroy(inputCollection);
            myhtml_collection_destroy(outputCollection);
            break;
        }

        const char* inp = myhtml_node_text(inputCollection->list[0], NULL);
        const char* out = myhtml_node_text(outputCollection->list[0], NULL);

        samples.push_back({inp ? inp : "", out ? out : ""});

        myhtml_collection_destroy(inputCollection);
        myhtml_collection_destroy(outputCollection);
    }

    myhtml_tree_destroy(tree);
    myhtml_destroy(myhtml);

    return samples;
}
