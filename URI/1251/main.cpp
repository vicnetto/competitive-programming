#include <bits/stdc++.h>

using namespace std;

bool comp (pair<char, int> x, pair<char, int> y) {
    if (x.second == y.second)
        return x.first > y.first;

    return x.second < y.second;
}

int main () {
    string input;
    bool first = true;

    while(getline(cin, input)) {
        vector<pair<char, int>> qty;

        if (!first)
            cout << endl;
        first = false;

        for (int i = 0; i < input.size(); i++) {
            int j;
            for (j = 0; j < qty.size(); j++) {
                if (qty.at(j).first == input[i]) {
                    qty.at(j).second += 1;  
                    break;
                }
            }

            if (j == qty.size())
                qty.push_back(make_pair(input[i], 1));
        }

        sort(qty.begin(), qty.end(), comp);

        for (int i = 0; i < qty.size(); i++) {
            cout << int(qty.at(i).first) << " " << qty.at(i).second << endl;
        }
    }

    return 0;
}