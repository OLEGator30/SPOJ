#include <iostream>
#include <unordered_map>

using namespace std;

int main(int /*argc*/, char ** /*argv*/) {
    ios_base::sync_with_stdio(false); // performance hack

    unsigned int nTests;
    cin >> nTests;

    for (char test = 0; test < nTests; ++test) {
        unsigned int nAttempts;
        cin >> nAttempts;

        unordered_map<int, unsigned int> numberToCount;
        for (unsigned int i = 0; i < nAttempts; ++i) {
            int attempt;
            cin >> attempt;
            numberToCount[attempt] += 1;
        }

        bool no = true;
        for (const auto& item : numberToCount) {
            if (item.second > nAttempts / 2) {
                cout << "YES " << item.first << endl;
                no = false;
                break;
            }
        }
        if (no) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
