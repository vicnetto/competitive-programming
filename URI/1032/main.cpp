#include <bits/stdc++.h>
#include <vector>

using namespace std;

int find_prime (int n) {
    for (int i = 2; i < sqrt(n) + 1; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main () {
    int qnt;
    vector<int> players;

    scanf("%d", &qnt);

    for (int i = 0; i < qnt; i++) {
        players.push_back(i + 1);
    }

    int prime = 2;
    int currPos = 0;

    while(players.size() != 1) {
        for (int i = 0; i < players.size(); i++) {
            cout << players.at(i);
        }
        cout << endl;

        if (currPos + prime - 1 >= players.size()) {
            currPos = currPos - (prime - (int(prime / players.size()) * players.size())) - 1;
            currPos = abs(currPos);
        } else
            currPos = currPos + prime - 1;

        cout << currPos << " " << prime << endl;

        players.erase(players.begin() + currPos);

        prime++;
        while(!find_prime(prime))
            prime++;

        cout << "-------------" << endl;
    }

    //cout << players.at(0) << endl;
    return 0;
}