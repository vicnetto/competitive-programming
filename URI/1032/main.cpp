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
    int n;

    while(scanf("%d", &n) && n != 0) {
        int qnt = n;
        vector<int> players;

        for (int i = 0; i < qnt; i++) {
            players.push_back(i + 1);
        }

        int prime = 2;
        int currPos = 0;

        while(players.size() != 1) {
            if (currPos + prime - 1 >= players.size()) {
                currPos = currPos + (prime - (int(prime / players.size()) * players.size()) - 1);
                currPos = abs(currPos);

                if (currPos >= players.size())
                    currPos -= players.size();
            } else
                currPos = currPos + prime - 1;

            players.erase(players.begin() + currPos);
            if (currPos == players.size())
                currPos = 0;

            prime++;
            while(!find_prime(prime))
                prime++;

        }

        cout << players.at(0) << endl;
    }

    return 0;
}