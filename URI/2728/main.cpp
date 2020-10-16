#include <bits/stdc++.h>

using namespace std;

int main () {
    string current;

    while(getline(cin, current)) {
        vector<string> vec;

        char *ptr = strtok(&current[0], "-");
        int sum = 0;
        for(int i = 0; ptr != NULL; i++) {
            char character = i == 0 ? 'c' : i == 1 ? 'o' : i == 2 ? 'b' : i == 3 ? 'o' : 'l';

            ptr[0] = tolower(ptr[0]);
            ptr[strlen(ptr) - 1] = tolower(ptr[strlen(ptr) - 1]);
            if (ptr[0] == character || ptr[strlen(ptr) - 1] == character)
                sum++;
            ptr = strtok(NULL, "-");
        }

        cout << (sum  < 5 ? "BUG" : "GRACE HOPPER") << endl;
    }

    return 0;
}