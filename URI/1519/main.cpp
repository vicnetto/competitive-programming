#include <bits/stdc++.h>

using namespace std;

int main () {
    string intire;

    while(getline(cin, intire) && intire != ".") {
        map<string, int> words;
        vector<string> all;
        map<string, int>::iterator it;

        char *ptr = strtok(&intire[0], " ");
        while(ptr != NULL) {
            all.push_back(ptr);
            it = words.find(ptr);
            if (it == words.end())
                words.insert(make_pair(ptr, 1));
            else
                it->second += 1;

            ptr = strtok(NULL, " ");
        }

        for (it = words.begin(); it != words.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }

        for (int i = 0; i < all.size(); i++) {
            it = words.find(all.at(i));
            it++;

            if(it != end) {
                //cout << it->first << " " << all.at(i) << endl;
                int j = i + 1;

                if ((it++)->first[0] == all.at(i)[0]) {
                    cout << "Tem outro" << endl;
                } else
                    cout  << all.at(i)[0] << ". ";
            }
        }

        cout << endl;
    }

    return 0;
}