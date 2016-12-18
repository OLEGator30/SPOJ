#include <iostream>
#include <memory>
#include <string>
#include <array>

using namespace std;

using uint = unsigned int;

class TTrie {
    struct TTrieNode {
        bool hasChildren = false;
        array<unique_ptr<TTrieNode>, 10> data;
    } Trie;

public:
    TTrie() {
        Trie.hasChildren = true;
    }

    bool AddNumber(const string& number) {
        auto triePtr = &Trie;
        bool isSuffix = true;
        bool wasSuffix = true;
        for (const char symbol : number) {
            const auto idx = symbol - '0';

            if (!triePtr->data[idx]) {
                if (wasSuffix && !triePtr->hasChildren) {
                    return true;
                }

                isSuffix = false;
                wasSuffix = false;

                triePtr->hasChildren = true;
                triePtr->data[idx].reset(new TTrieNode);
            }

            triePtr = triePtr->data[idx].get();
        }

        return isSuffix;
    }
};

int main(int /*argc*/, char ** /*argv*/) {
    uint nTests;
    cin >> nTests;

    for (uint test = 0; test < nTests; ++test) {
        uint nNumbers;
        cin >> nNumbers;

        TTrie trie;
        bool yes = true;
        for (uint iNumber = 0; iNumber < nNumbers; ++iNumber) {
            string phoneNumber;
            cin >> phoneNumber;

            if (yes && trie.AddNumber(phoneNumber)) {
                yes = false;
            }
        }

        cout << (yes ? "YES" : "NO") << endl;
    }

    return 0;
}
