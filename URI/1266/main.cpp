#include <bits/stdc++.h>

using namespace std;

int main () {
    int n_post;

    while (scanf("%d", &n_post) && n_post != 0) {
        int temp, pos = -1, postQt = 0;
        bool all_posts[n_post], first = true, last_is_empty = false, reset = false;

        for (int i = 0; i < n_post; i++) {
            scanf("%d", &temp);
            all_posts[i] = temp;
 
            if (first && all_posts[i] == true) {
                pos = i;
                first = false;
            }
        }

        for (int i = pos + 1; i != pos; i++) {
            if (pos + 1 == n_post && !reset) {
                i = 0;
                reset = true;
            }

            if (!all_posts[i] && last_is_empty) {
                all_posts[i] = true;
                postQt++;
                last_is_empty = false;
            } else if (!all_posts[i]) {
                last_is_empty = true;
            }
            else {
                last_is_empty = false;
            }

            if (i >= n_post - 1) {
                i = -1;

                if (pos == -1)
                    pos = 1;
            }
        }

        cout << postQt << endl;
    }
    return 0;
}