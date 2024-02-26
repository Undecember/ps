#include "str.h"

#include <sstream>
using std::ostringstream;

string to_string(int x) {
    ostringstream os;
    os << std::dec << x;
    return os.str();
}
