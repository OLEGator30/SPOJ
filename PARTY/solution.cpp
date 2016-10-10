#include <iostream>
#include <vector>

using namespace std;

struct TParty {
    size_t Fee;
    size_t Fun;

    explicit TParty(size_t fee = 0, size_t fun = 0)
        : Fee(fee)
        , Fun(fun)
    {}

    bool operator<(const TParty& other) const {
        return this->Fun < other.Fun;
    }

    TParty operator+(const TParty& other) const {
        return TParty(this->Fee + other.Fee, this->Fun + other.Fun);
    }
};

int main(int /*argc*/, char ** /*argv*/) {
    while (true) {
        size_t budget, nParties;
        cin >> budget >> nParties;

        if (budget == 0 && nParties == 0) {
            return 0;
        }

        vector<TParty> parties;
        parties.reserve(nParties);
        vector<vector<TParty>> optimalMatrix;
        optimalMatrix.reserve(nParties + 1);
        for (size_t i = 0; i < nParties; ++i) {
            size_t fee, fun;
            cin >> fee >> fun;

            parties.emplace_back(fee, fun);
            optimalMatrix.push_back(vector<TParty>(budget + 1));
        }
        optimalMatrix.push_back(vector<TParty>(budget + 1));

        for (size_t party = 0; party <= nParties; ++party) {
            for (size_t money = 0; money <= budget; ++money) {
                if (party > 0 && money > 0) {
                    if (money < parties[party - 1].Fee) {
                        optimalMatrix[party][money] = optimalMatrix[party - 1][money];
                    } else {
                        optimalMatrix[party][money] = max(
                            optimalMatrix[party - 1][money],
                            optimalMatrix[party - 1][money - parties[party - 1].Fee] + parties[party - 1]
                        );
                    }
                }
            }
        }

        while (optimalMatrix.back()[budget - 1].Fun == optimalMatrix.back()[budget].Fun) {
            --budget;
        }

        cout << optimalMatrix.back()[budget].Fee << " " << optimalMatrix.back()[budget].Fun << endl;
    }
}
