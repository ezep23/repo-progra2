#include <iostream>
using namespace std;

#include <string.h>
#include <cctype>


inline bool sonIguales(const string& a, const string& b) {
    if (a.size() != b.size()) return false;

    for (size_t i = 0; i < a.size(); ++i) {
        if (tolower(a[i]) != tolower(b[i])) {
            return false;
        }
    }
    return true;
}
