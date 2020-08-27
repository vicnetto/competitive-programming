#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    string s;

    while(getline(cin, s)) {
        int right = 0, left = 0;
        vector<char> allBrackets;
        setbuf(stdin, NULL);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                allBrackets.push_back(s[i]);
                left++;
            }

            if (s[i] == ')') {
                allBrackets.push_back(s[i]);
                right++;
            }
        }

        bool isCorrect = false;

        if (right == left) {
            int isOpen = 0;
            isCorrect = true;

            for (int i = 0; i < allBrackets.size(); i++) {
                if (allBrackets.at(i) == '(') isOpen++;
                if (allBrackets.at(i) == ')') {
                    if (!isOpen) {
                        isCorrect = false;
                        break;
                    } else
                        isOpen--;
                }
            }
        }

        cout << (isCorrect == true ? "correct" : "incorrect") << endl;
    }

    return 0;
}