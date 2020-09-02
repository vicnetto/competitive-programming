#include <bits/stdc++.h>
#include <vector>
#include <sstream>

#define C 51

using namespace std;

int main () {
    int t, n;
    char delim = ' ';
    string name, indivNames, frequency, indivFreq;
    vector<pair<string, string>> data;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int counter = 0;
        data.clear();
        scanf("%d", &n);

        if (n != 0) {
            cin.ignore(); 
            getline(cin, name);
            getline(cin, frequency);

            if (count(name.begin(), name.end(), ' ')) {
                stringstream ss1(name);
                stringstream ss2(frequency);

                while (ss1 >> indivNames) {
                    counter++;
                    ss2 >> indivFreq;
                    data.push_back(make_pair(indivNames, indivFreq));
                }
            } else
                data.push_back(make_pair(name, frequency));

            bool first = true;

            for (int j = 0; j < data.size(); j++) {
                string local = data.at(j).second;
                int numberAbsent = count(local.begin(), local.end(), 'A');
                int numberTotal = count(local.begin(), local.end(), 'P') + numberAbsent;
                float operation = (numberTotal - numberAbsent) * 100 / numberTotal;

                if (operation < 75) {
                    if (!first) 
                        cout << " ";

                    cout << data.at(j).first;
                    first = false;
                }
            }

        }

        cout << endl;
    }

    return 0;
}