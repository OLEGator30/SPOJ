#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline bool IsDistAllowed(const vector<size_t>& stalls, size_t nCows, size_t dist) {
    size_t prevStallIdx = 0;
    size_t prevStallNum = stalls[prevStallIdx];
    size_t curStallIdx = prevStallIdx;
    size_t curStallNum = prevStallNum;

    for (size_t cow = 1; cow < nCows; ++cow) {
        while (curStallNum - prevStallNum < dist) {
            ++curStallIdx;
            if (stalls.size() > curStallIdx) {
                curStallNum = stalls[curStallIdx];
            } else {
                return false;
            }
        }

        prevStallIdx = curStallIdx;
        prevStallNum = curStallNum;
    }

    return true;
}

inline size_t LargestMinDist(const vector<size_t>& stalls, size_t nCows) {
    const size_t maxDist = (stalls.back() + 1 /*from zero*/) / (nCows - 1) + 1 /*round up*/;

    size_t left = 0;
    size_t right = maxDist + 1 /*larger than max possible value*/;

    while (right > left) {
        const size_t mid = left + (right - left) / 2;

        if (IsDistAllowed(stalls, nCows, mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return right - 1 /*right is the lowest possible value*/;
}

int main(int /*argc*/, char ** /*argv*/) {
    size_t nTests;
    cin >> nTests;

    for (size_t test = 0; test < nTests; ++test) {
        size_t nStalls, nCows;
        cin >> nStalls;
        cin >> nCows;

        vector<size_t> stalls;
        for (size_t i = 0; i < nStalls; ++i) {
            size_t stallIdx;
            cin >> stallIdx;
            stalls.push_back(stallIdx);
        }
        sort(stalls.begin(), stalls.end());

        cout << LargestMinDist(stalls, nCows) << endl;
    }

    return 0;
}
