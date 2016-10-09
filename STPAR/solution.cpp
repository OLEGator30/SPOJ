#include <iostream>
#include <vector>

using namespace std;

int main(int /*argc*/, char ** /*argv*/) {
    while (true) {
        size_t nTrucks;
        cin >> nTrucks;

        if (nTrucks == 0) {
            return 0;
        }

        vector<size_t> sideTrucks;
        sideTrucks.reserve(nTrucks);
        size_t lastTruck = 0;
        for (size_t truck = 0; truck < nTrucks; ++truck) {
            size_t truckId;
            cin >> truckId;

            sideTrucks.push_back(truckId);

            while (!sideTrucks.empty() && sideTrucks.back() == lastTruck + 1) {
                lastTruck = sideTrucks.back();
                sideTrucks.pop_back();
            }
        }

        cout << (sideTrucks.empty() ? "yes" : "no") << endl;
    }
}
