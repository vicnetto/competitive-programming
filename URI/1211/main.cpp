#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int main () {
    int n;
    char newline;
    string current;

    while(cin >> n) {
        scanf("%c", &newline);

        vector<string> numbers;
        int qnt = 0;

        for (int i = 0; i < n; i++) {
            getline(cin, current);
            numbers.push_back(current);
        }

        for (int i = 1; i < numbers.size(); i++) {
            string current = numbers.at(i - 1);
            string comp = numbers.at(i);

            for (int j = 0; j < current.size(); j++) {
                if (current[j] == comp[j]) {
                    qnt++;
                }
                else
                    break;
            }
        }

        cout << qnt << endl;
    }

    return 0;
}