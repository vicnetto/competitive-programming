#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int actualNumb;

bool find_max (string a, string b) {
    if (actualNumb + 1 == a.size() || actualNumb + 1 == b.size())
        return true;

    if (a.at(actualNumb) < b.at(actualNumb))
        return true;

    else if (a.at(actualNumb) > b.at(actualNumb))
        return false;

    actualNumb++;
    bool value = find_max(a, b);

    actualNumb = 0;
    return value;
}

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

        sort(numbers.begin(), numbers.end(), find_max);

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