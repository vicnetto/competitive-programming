#include <bits/stdc++.h>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> combinations (int x, int y, int z) {
    vector<vector<int>> finalvec;
    deque<int> half;

    half.push_back(x);
    half.push_back(y);
    half.push_back(z);

    for (int i = 0; i < half.size() * 2; i++) {
        if (i == half.size()) {
            int savef = half.front();
            int savee = half.back();

            half.pop_front();
            half.pop_back();
            half.push_front(savee);
            half.push_back(savef);
        }

        half.push_back(half.front());
        half.pop_front();

        vector<int> temp;
        for (int j = 0; j < half.size(); j++) {
            temp.push_back(half.at(j));
        }
        finalvec.push_back(temp);
    }

    return finalvec;
}

int main () {
    while (true) {
        int princes[6];
        int result = 1;

        int tmp = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%d", &princes[i]);

            if (princes[i] == 0)
                tmp++;
        }
        
        if (tmp == 5)
            break;

        vector<vector<int>> possiblePlays = combinations(princes[0], princes[1], princes[2]);

        for (int i = 0; i < possiblePlays.size(); i++) {
            int wins = 2;
            if (princes[3] < possiblePlays.at(i).at(0))
                wins--;

            if (princes[4] < possiblePlays.at(i).at(1))
                wins--;

            if (wins == 0) {
                result = -1;
                break;
            }
            else if (wins == 1)
                result = result > possiblePlays.at(i).at(2) + 1 ? result : possiblePlays.at(i).at(2) + 1;
        }

        for (int i = 0; i < 5; i++) {
            if (result == princes[i]) {
                i = -1;
                result++;
            }

            if (result >= 53) {
                result = -1;
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}