#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    char newline;
    bool first = false;

    while(cin >> n && n != 0) {
        scanf("%c", &newline);
        string line[n];
        int max_size = 0;

        if (first)
            cout << endl;
        first = true;

        for (int i = 0; i < n; i++) {
            getline(cin, line[i]);

            max_size = max_size < line[i].size() ? line[i].size() : max_size;
        }
        
        for (int i = 0; i < n; i++) {
            string current = line[i];
            line[i].clear();

            char* ptr = strtok(&current[0], " ");
            while(ptr != NULL) {
                line[i].append(ptr);
                line[i].append(" ");
                ptr = strtok(NULL, " ");
            }
            line[i].erase(line[i].end() - 1);

            int times = 0;
            if (line[i].size() != max_size) {
                times = max_size - line[i].size();
                while (times--) 
                    cout << " ";
                cout << line[i] << endl;
            } else
                cout << line[i] << endl;
        }
    }

    return 0;
}