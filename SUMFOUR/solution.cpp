#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int /*argc*/, char ** /*argv*/) {
    ios_base::sync_with_stdio(false); // performance hack

    size_t nQuadruplets;
    cin >> nQuadruplets;

    vector<int> listA, listB, listC, listD;
    listA.reserve(nQuadruplets);
    listB.reserve(nQuadruplets);
    listC.reserve(nQuadruplets);
    listD.reserve(nQuadruplets);
    for (size_t quadruplet = 0; quadruplet < nQuadruplets; ++quadruplet) {
        int value;
        cin >> value;
        listA.push_back(value);
        cin >> value;
        listB.push_back(value);
        cin >> value;
        listC.push_back(value);
        cin >> value;
        listD.push_back(value);
    }

    unordered_map<int, size_t> sumAB;
    sumAB.reserve(nQuadruplets * nQuadruplets);
    for (size_t i = 0; i < nQuadruplets; ++i) {
        for (size_t j = 0; j < nQuadruplets; ++j) {
            ++sumAB[listA[i] + listB[j]];
        }
    }

    size_t result = 0;
    for (size_t i = 0; i < nQuadruplets; ++i) {
        for (size_t j = 0; j < nQuadruplets; ++j) {
            auto it = sumAB.find(-(listC[i] + listD[j]));
            if (it != sumAB.end()) {
                result += it->second;
            }
        }
    }
    cout << result << endl;

    return 0;
}
