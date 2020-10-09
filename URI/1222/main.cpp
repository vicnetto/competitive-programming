#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

void count_page (string poem, int &pages, int &lines, int &wrote, int &lines_per_page, int &lines_size) {
    
    int actual = poem[wrote + lines_size] == ' ' ? wrote + lines_size + 1 : wrote + lines_size;
    cout << "Actual: " << actual << endl;
    cout << "poem[actual]: " << poem[actual] << endl;

    if (actual > poem.size()) {
        lines++;
        wrote = poem.size();
    } else if (poem[actual] != ' ') {
        cout << "1" << endl;
        lines += 1;

        int location = poem.find_last_of(" ", actual);

        cout << location << endl;

        wrote = location + 1;

    } else {
        cout << "2" << endl;

        lines += 1;
        wrote += lines_size + 1;
    }

    if (lines > lines_per_page) {
        pages++;
        lines = 1;
    }

    //cout << "Lines: " << lines << endl;

    cout << poem.substr(0, wrote) << endl;
}

int main () {
    int n_words, lines_per_page, lines_size;
    char newline;
    bool finished = false;
    string poem;

    while(cin >> n_words && cin >> lines_per_page && cin >> lines_size) {
        scanf("%c", &newline);

        int pages = 1, lines = 0, wrote = 0;
        //lines_size--;
        getline(cin, poem);

        while(finished == false) {
            if (wrote >= poem.size()) {
                break;
            }

            cout << "Wrote: " << wrote << endl;
            count_page(poem, pages, lines, wrote, lines_per_page, lines_size);
            cout << "Wrote: " << wrote << endl;
        }

        cout << pages << endl;
    }

    return 0; 
}