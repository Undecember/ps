#include <iostream>
using std::cout, std::cerr, std::endl;
#include <fstream>
using std::ifstream, std::ofstream;

#include "str.h"
#include "web.h"

string cf_path;
int curr = 0;

int parse_arg(int argc, char* argv[]);
void help();
void test();
void load_problem(int arg);
void submit();

int main(int argc, char* argv[]) {
    ifstream is(".boj_curr");
    if (is.is_open()) is >> curr;
    switch(int arg = parse_arg(argc, argv)) {
        case -1: // parse failed
            help();
            break;
        case 0: // boj test
            test();
            break;
        case 1: // boj submit
            submit();
            break;
        default: // boj [problem id]
            load_problem(arg);
            break;
    }
    return 0;
}

int parse_arg(int argc, char* argv[]) {
    if (argc != 3) return -1;
    cf_path = argv[1];
    if (!strcmp(argv[2], "test")) return 0;
    if (!strcmp(argv[2], "submit")) return 1;
    int id = atoi(argv[2]);
    if (id) return id;
    return -1;
}

void help() {
    static const char* help_msg = R"(
Usage : boj [command]

Commands : test, submit, load

Examples :
    * boj test
        Test your solution in local.
    * boj submit
        Submit your solution.
    * boj 1024
        Load boj problem 1024 with tests and set 1024 to current problem.
)";
    cerr << help_msg << endl;
}

void test() {
    if (!curr) {
        cerr << "Please select problem first." << endl;
        return;
    }
    system("mkdir -p .tests && rm -rf test && mkdir test && cp .tests/* test/");
    system(("cp " + to_string(curr) + ".cpp test/test.cpp").c_str());
    system(("cd test && " + cf_path + " test && cd ..").c_str());
    system("rm -rf test");
}

void load_problem(int arg) {
    string sarg = to_string(arg);
    string url = "https://www.acmicpc.net/problem/" + sarg;
    system(("xdg-open " + url + " > /dev/null 2>&1 &").c_str());
    if (!ifstream(sarg + ".cpp").is_open()) {
        system(("mkdir " + sarg + " && cd " + sarg + " && " + cf_path + " gen && cd ..").c_str());
        system(("mv " + sarg + "/* ./ && rm -rf " + sarg).c_str());
    }
    auto tests = getTests(url);
    system("rm -rf .tests && mkdir .tests");
    ofstream os;
    int i = 0;
    for (auto &test : tests) {
        i++;
        os.open(".tests/testI" + to_string(i) + ".txt");
        os << test.first;
        os.close();
        os.open(".tests/testO" + to_string(i) + ".txt");
        os << test.second;
        os.close();
    }
    os.open(".boj_curr");
    os << arg;
    os.close();
    cout << i << " tests loaded." << endl;
}

void submit() {
    if (!curr) {
        cerr << "Please select problem first." << endl;
        return;
    }
    string url = "https://www.acmicpc.net/submit/" + to_string(curr);
    system(("xdg-open " + url + " > /dev/null 2>&1 &").c_str());
}
