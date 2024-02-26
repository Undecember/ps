#include <iostream>
using std::cerr, std::endl;
#include <format>
using std::format;

#include "web.h"

int parse_arg(int argc, char* argv[]);
void help();
void test();
void load_problem(int arg);

int main(int argc, char* argv[]) {
    switch(int arg = parse_arg(argc, argv)) {
        case -1: // parse failed
            help();
            break;
        case 0: // boj test
            test();
            break;
        case 1: // boj submit
            cerr << "Not implemented yet." << endl;
            break;
        default: // boj [problem id]
            load_problem(arg);
            break;
    }
    return 0;
}

int parse_arg(int argc, char* argv[]) {
    if (argc != 2) return -1;
    if (!strcmp(argv[1], "test")) return 0;
    if (!strcmp(argv[1], "submit")) return 1;
    int id = atoi(argv[1]);
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
        Load boj problem 1024 with tests.
)";
    cerr << help_msg << endl;
}

void test() {

}

void load_problem(int arg) {
    auto tests = getTests("https://icpc.me/" + to_string(arg));
}
