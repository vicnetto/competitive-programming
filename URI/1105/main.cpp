#include <bits/stdc++.h>
#include <tuple>

using namespace std;

int main () {
    int nBanks, nDebts;

    cin >> nBanks;
    cin >> nDebts;

    while (nBanks != 0 && nDebts != 0) {
        int bankBalance[nBanks];
        
        for (int i = 0; i < nBanks; i++)
            scanf("%d", &bankBalance[i]);

        tuple<int, int, int> transactions;

        int current[3];
        for (int i = 0; i < nDebts; i++) {
            scanf("%d", &current[0]);
            scanf("%d", &current[1]);
            scanf("%d", &current[2]);

            transactions = make_tuple(current[0], current[1], current[2]);

            bankBalance[get<1>(transactions) - 1] += get<2>(transactions);
            bankBalance[get<0>(transactions) - 1] -= get<2>(transactions);
        }

        bool isNegative = false;
        for (int i = 0; i < nBanks; i++) {
            if (bankBalance[i] < 0) {
                isNegative = true;
                break;
            }
        }

        cout << (isNegative ? "N" : "S") << endl;

        cin >> nBanks;
        cin >> nDebts;
    }

    return 0;
}