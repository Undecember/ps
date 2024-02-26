#ifndef __WEB_H__
#define __WEB_H__

#include <curl/curl.h>
#include <cstdlib>
#include <string>
using std::string;
#include <vector>
using std::vector, std::pair;
#include <myhtml/api.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, string *userp);
string getHTML(const string& url);
vector<pair<string, string>> getTests(const string& url);

#endif
