#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef unsigned int uint;
typedef map <uint, uintptr_t> selfmap;
typedef set <uintptr_t> selfset;

uint valid_path(selfmap *part, uint final_part, selfset *seen_parts) {
    if (seen_parts->find(reinterpret_cast<uintptr_t>(part)) != seen_parts->end()) {
        return 0;
    }
    seen_parts->insert(reinterpret_cast<uintptr_t>(part));
    if (part->find(final_part) != part->end()) {
        return 1;
    } else {
        for (auto p : *part) {
            if (valid_path(reinterpret_cast<selfmap *>(p.second), final_part, seen_parts)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    uint n_parts, final_part;
    cin >> n_parts >> final_part;
    if (final_part == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    selfmap *parts = new selfmap [n_parts];
    for (uint j = 0; j < n_parts; ++j) {
        for (uint i = 0; i < n_parts; ++i) {
            uint a;
            cin >> a;
            if (a == 1) {
                parts[j][i] = reinterpret_cast<uintptr_t>(&parts[i]);
            }
        }
    }
    selfset seen_parts;
    if (valid_path(&parts[0], final_part - 1, &seen_parts)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    delete [] parts;
    return 0;
}
