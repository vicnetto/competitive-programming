#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

void printSizes (vector<int> v1, int qnt) {
        for (int i = 0; i < qnt; i++) {
            printf("%d ", v1.at(i));
        }
        printf("\n");
}

bool myfunction (int i, int j) { return i > j; }

int main () {
    int width, height;

    while (scanf("%d %d", &width, &height) && width != 0 && height != 0) {
        int lenght, qnt;
        vector<int> initialsizes;
        int local, missing, tmp;
        int lowest = INT_MAX;

        scanf("%d", &lenght);
        scanf("%d", &qnt);
        
        for (int i = 0; i < qnt; i++) {
            scanf("%d", &local);
            initialsizes.push_back(local * lenght);
        }

        sort(initialsizes.begin(), initialsizes.end());

        //printSizes(initialsizes, qnt);

        for (int n = 0; n < 2; n++) {
            vector<int> sizes = initialsizes;
            int finished = 0, woodsperheight = 0;
            tmp = width;
            width = height;
            height = tmp;

            for (int i = 0; i < height; i++) {
                for (int j = sizes.size() - 1; j >= 0; j--) {
                    local = sizes.at(j);
                    sizes.erase(sizes.begin() + j);

                    missing = (width * 100) - local;

                    if (missing < 0)
                        continue;

                    if (missing == 0) {
                        finished++;
                        woodsperheight++;
                        break;
                    }

                    if (missing > 0) {
                        auto lower = lower_bound(sizes.begin(), sizes.end(), missing);

                        if (lower != sizes.end()) {
                            finished++;
                            woodsperheight += 2;
                            tmp = sizes.size();
                            sizes.erase(sizes.begin() + distance(sizes.begin(), lower));
                            j = tmp;
                            break;
                        }
                    }
                }
            }

            if (finished == height)
                lowest = woodsperheight < lowest ? woodsperheight : lowest;
        }

        if (lowest == INT_MAX)
            printf("impossivel\n");
        else
            printf("%d\n", lowest);

    }
    
    return 0;
}