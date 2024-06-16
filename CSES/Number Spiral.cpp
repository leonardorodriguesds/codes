#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long y, x;
        cin >> y >> x;

        long long maior = max(y, x);
        long long diagonal = maior * maior;

        if (maior % 2 == 0) { // Quadrado par
            if (y == maior) diagonal -= x - 1;
            else diagonal -= maior - y;
        } else { // Quadrado ímpar
            if (x == maior) diagonal -= y - 1;
            else diagonal -= maior - x;
        }

        cout << diagonal << endl;
    }

    return 0;
}