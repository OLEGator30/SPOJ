#include <iostream>
#include <vector>

using namespace std;

int main(int /*argc*/, char ** /*argv*/) {
    size_t nTests;
    cin >> nTests;

    for (size_t test = 0; test < nTests; ++test) {
        size_t height, width;
        cin >> height >> width;

        size_t maxCumValue = 0;
        vector<size_t> prevCumRow(width);
        for (size_t h = 0; h < height; ++h) {
            vector<size_t> curCumRow(width);
            for (size_t w = 0; w < width; ++w) {
                size_t val;
                cin >> val;

                for (int i = -1; i <= 1; ++i) {
                    if ((i == -1 && w == 0) || (i == 1 && w == width - 1)) {
                        continue;
                    }
                    if (curCumRow[w] < prevCumRow[w + i]) {
                        curCumRow[w] = prevCumRow[w + i];
                    }
                }

                curCumRow[w] += val;

                if (maxCumValue < curCumRow[w]) {
                    maxCumValue = curCumRow[w];
                }
            }

            prevCumRow = curCumRow;
        }

        cout << maxCumValue << endl;
    }

    return 0;
}
