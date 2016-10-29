#include <iostream>

using namespace std;

int main(int /*argc*/, char ** /*argv*/) {
    ios_base::sync_with_stdio(false); // performance hack

    size_t nTests;
    cin >> nTests;

    char buffer[1000000];
    char digit;
    cin.get(digit); // for '\n'

    for (size_t test = 0; test < nTests; ++test) {
        size_t len = 0;
        bool allNines = true;
        while (cin.get(digit)) {
            if (digit == '\n') {
                break;
            }

            buffer[len] = digit;
            ++len;

            if (digit != '9') {
                allNines = false;
            }
        }

        if (allNines) {
            cout << '1';
            for (size_t i = 0; i < len - 1; ++i) {
                cout << '0';
            }
            cout << '1' << endl;
            continue;
        }

        bool increased = false;
        size_t i, j, middle;
        if (len % 2) {
            middle = len / 2;
            i = middle - 1;
            j = middle + 1;
        } else {
            middle = len / 2 - 1;
            i = middle;
            j = middle + 1;
        }
        for (; j < len; --i, ++j) {
            if (buffer[i] > buffer[j]) {
                increased = true;
                break;
            } else if (buffer[i] < buffer[j]) {
                increased = false;
                break;
            }
        }

        if (!increased) {
            while (buffer[middle] == '9') {
                buffer[middle] = '0';
                --middle;
            }
            buffer[middle] += 1;
        }

        for (size_t i = 0, j = len - 1; i < len / 2; ++i, --j) {
            buffer[j] = buffer[i];
            cout << buffer[i];
        }
        for (size_t i = len / 2; i < len; ++i) {
            cout << buffer[i];
        }
        cout << endl;
    }

    return 0;
}
