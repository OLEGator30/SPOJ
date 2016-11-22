#include <stack>
#include <cctype>
#include <iostream>

using namespace std;

typedef unsigned int uint;

int main(int /*argc*/, char ** /*argv*/) {
    uint nExpressions;
    cin >> nExpressions;
    char symbol = cin.get(); // for '\n'

    stack<char> operators;
    for (uint expression = 0; expression < nExpressions; ++expression) {
        while (true) {
            symbol = cin.get();

            if (symbol == '\n') {
                break;
            } else if (isalpha(symbol)) {
                cout << symbol;
            } else if (symbol == ')') {
                while (operators.top() != '(') {
                    cout << operators.top();
                    operators.pop();
                }
                operators.pop(); // pop '('
            } else { // operators and '('
                operators.push(symbol);
            }
        }

        cout << endl;
    }

    return 0;
}
