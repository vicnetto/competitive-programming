#include <bits/stdc++.h>
#include <set>
#include <string>

#define ALPHASIZE ('z' - 'a' + 1)

using namespace std;

int findNext (string current, int begin, bool is_alpha) {
    bool found = false;
    int actual = begin;

    while (!found && actual <= current.size()) {
        char letter = current[actual];

        if (is_alpha) {
            if (letter >= 'a' && letter <= 'z')
                found = true;
            else
                actual++;
        } else {
            if (letter < 'a' || letter > 'z')
                found = true;
            else
                actual++;
        }
    }

    return actual;
}

int main () {
    set<string> dict[ALPHASIZE];

    string current;

    while(getline(cin, current)) {
        if (current.size() == 0) 
            continue;

        transform(current.begin(), current.end(), current.begin(), ::tolower); 

        bool first = true;
        int found_begin = 0, found_end = 0, begin = 0;
        while(true) {
            found_begin = findNext(current, begin, true);
            found_end = findNext(current, found_begin, false);
            begin = found_end + 1;

            if (found_begin == found_end)
                break;

            string new_word = current.substr(found_begin, found_end - found_begin);
            dict[new_word[0] - 'a'].insert(new_word);
        }
    }

    for (int i = 0; i < 26; i++) {
        set<string>::iterator it;
        for (it = dict[i].begin(); it != dict[i].end(); ++it) {
            cout << *it << endl;
        }
    }

    return 0;
}