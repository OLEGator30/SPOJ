#include <iostream>
#include <unordered_map>

using namespace std;

size_t BestExchange(size_t coin, unordered_map<size_t, size_t>& memory) {
    auto ptr = memory.find(coin);
    if (ptr != memory.end()) {
        return ptr->second;
    }

    if (coin == 0) {
        return memory[0] = 0;
    }

    return memory[coin] = max(
        coin,
        BestExchange(coin / 2, memory) + BestExchange(coin / 3, memory) + BestExchange(coin / 4, memory)
    );
}

int main(int /*argc*/, char ** /*argv*/) {
    size_t coin;
    unordered_map<size_t, size_t> memory;
    while (cin >> coin) {
        cout << BestExchange(coin, memory) << endl;
    }

    return 0;
}
