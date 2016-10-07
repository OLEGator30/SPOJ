#include <iostream>
#include <deque>

using namespace std;

int main(int /*argc*/, char ** /*argv*/) {
    size_t nHotels, money;
    cin >> nHotels;
    cin >> money;

    size_t curSum = 0;
    size_t maxSum = 0;
    deque<size_t> curWindow;
    for (size_t hotel = 0; hotel < nHotels; ++hotel) {
        size_t cost;
        cin >> cost;

        curSum += cost;
        curWindow.push_back(cost);

        while (curSum > money) {
            size_t removedCost = curWindow.front();
            curSum -= removedCost;
            curWindow.pop_front();
        }

        if (curSum > maxSum) {
            maxSum = curSum;
        }
    }

    cout << maxSum << endl;

    return 0;
}
