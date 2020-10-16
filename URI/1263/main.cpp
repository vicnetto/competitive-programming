#include <bits/stdc++.h>

using namespace std;

int main () {
    string current;

    while(getline(cin, current)) {
        char last = '1';
        bool last_is = false;
        int qnt = 0;

        char *ptr = strtok(&current[0], " ");
        while(ptr != NULL) {
            ptr[0] = tolower(ptr[0]);

            if (ptr[0] == last && !last_is) {
                qnt++;
                last_is = true;
            } else if (ptr[0] != last)
                last_is = false;

            last = ptr[0];

            ptr = strtok(NULL, " ");
        }

        cout << qnt << endl;
    }

    return 0;
}