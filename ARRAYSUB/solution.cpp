#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main(int /*argc*/, char ** /*argv*/) {
    size_t arraySize;
    cin >> arraySize;

    vector<size_t> values;
    values.reserve(arraySize);
    for (size_t i = 0; i < arraySize; ++i) {
        size_t val;
        cin >> val;

        values.push_back(val);
    }

    size_t windowSize;
    cin >> windowSize;

    multiset<size_t> orderedWindow;
    deque<size_t> window;
    for (size_t i = 0; i < windowSize; ++i) {
        orderedWindow.insert(values[i]);
        window.push_back(values[i]);
    }

    cout << *orderedWindow.rbegin();
    for (size_t i = windowSize; i < arraySize; ++i) {
        orderedWindow.erase(orderedWindow.find(window.front()));
        window.pop_front();

        orderedWindow.insert(values[i]);
        window.push_back(values[i]);

        cout << " " << *orderedWindow.rbegin();
    }
    cout << endl;

    return 0;
}
