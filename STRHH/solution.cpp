#include <iostream>
#include <string>

using namespace std;

int main(int /*argc*/, char ** /*argv*/) {
    size_t nTests;
    cin >> nTests;
    for (size_t test = 0; test < nTests; ++test) {
        string str;
        cin >> str;

        for (size_t i = 0; i < str.size() / 2; i += 2) {
            cout << str[i];
        }
        cout << endl;
    }

    return 0;
}
