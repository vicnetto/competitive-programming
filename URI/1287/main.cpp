#include <bits/stdc++.h>

using namespace std;

int main () {
    string current;

    while(getline(cin, current)) {
        for (int i = 0; i < current.size(); i++) {
            if (current.at(i) == 'l')
                current.at(i) = '1';

            if (current.at(i) == 'O' || current.at(i) == 'o')
                current.at(i) = '0';

            if (current.at(i) == ',' || current.at(i) == ' ') {
                current.erase(current.begin() + i);
                i--;
            }
        }

        // For a future possible reader, be careful using the stoi() function,
        // by default, for some reason, it automatically ignores some letters,
        // i really don't know why.

        // Try the following case:
        // 5a
        // 1I1I1
        // Good Luck!

        try {
            bool error = false;
            for (int i = 0; i < current.size(); i++) {
                if (current.at(i) < '0' || current.at(i) > '9') {
                    cout << "error" << endl;
                    error = true;
                    break;
                }
            }

            if (!error) {
                int number = stoi(current);

                if (number >= 0)
                    cout << number << endl;
                else
                    cout << "error" << endl;
            }
        }
        catch (exception e) {
            cout << "error" << endl;
        }
    }

    return 0;
}