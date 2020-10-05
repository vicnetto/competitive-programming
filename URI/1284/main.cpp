#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 81

using namespace std;

int alphabet = ('z' - 'a') + 1;

bool myComp(string a, string b){
    return strcasecmp(a.c_str(), b.c_str() ) <= 0;
}

int main () {
    int n;
    string nStr;
    setbuf(stdin, NULL);

    while(getline(cin, nStr)) {
        if (cin.eof())
            return 0;

        n = stoi(nStr);
        cout << "Numero: " << n << endl;
        string s[n];
        vector<string> all[('z' - 'a') + 1];

        for(int i = 0; i < n; i++) {
            getline(cin, s[i]);
            all[int(s[i][0]) - 'a'].push_back(s[i]);
        }
        
        for (int i = 0; i < alphabet; i++) {
            if (all[i].size() != 0) {
                sort(all[i].begin(), all[i].end(), myComp);

                for (int j = 0; j < all[i].size(); j++) {
                    cout << all[i].at(j) << endl;
                }


            }
        }
    }
}