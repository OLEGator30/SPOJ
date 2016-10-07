#include <iostream>
#include <vector>

using namespace std;

int main(int /*argc*/, char ** /*argv*/) {
    ios_base::sync_with_stdio(false); // performance hack

    size_t nTests;
    cin >> nTests;

    for (size_t test = 0; test < nTests; ++test) {
        size_t storageSize, nUpdates;
        cin >> storageSize;
        cin >> nUpdates;

        vector<size_t> storage(storageSize, 0);

        for (size_t update = 0; update < nUpdates; ++update) {
            size_t left, right, value;
            cin >> left;
            cin >> right;
            cin >> value;

            storage[left] += value;
            if (right + 1 < storageSize) {
                storage[right + 1] -= value;
            }
        }

        size_t cumSum = 0;
        for (auto& item : storage) {
            cumSum += item;
            item = cumSum;
        }

        size_t nQueries;
        cin >> nQueries;

        for (size_t query = 0; query < nQueries; ++query) {
            size_t idx;
            cin >> idx;

            cout << storage[idx] << endl;
        }
    }

    return 0;
}
