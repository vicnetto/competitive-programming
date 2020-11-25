#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    char newline;

    scanf("%d", &n);
    scanf("%c", &newline);

    for(int i = 0; i < n; i++) {
        string phrase;
        getline(cin, phrase);

        for (int j = phrase.size() / 2 - 1; j >= 0; j--)
            cout << phrase.at(j);
        
        for (int j = phrase.size() - 1; j >= phrase.size() / 2; j--)
            cout << phrase.at(j);

        cout << endl;
    }

    return 0;
}