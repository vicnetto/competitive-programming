#include <bits/stdc++.h>

using namespace std;

int main () {
    string first, second;
    int currentI, currentJ, currentMAX;
while(getline(cin, first)) {
        getline(cin, second);

        int max = 0;

        for(int i = 0; i < second.size(); i++) {
            for(int j = 0; j < first.size(); j++) {
                if (second[i] == first[j]) {
                    currentI = i + 1;
                    currentJ = j + 1;
                    currentMAX = 1;

                    while(second[currentI] == first[currentJ] && currentI < second.size() && currentJ < first.size()) {
                        currentI += 1;
                        currentJ += 1;
                        currentMAX += 1;
                    }

                    if (max < currentMAX)
                        max = currentMAX;
                }
            }
        }

        printf("%d\n", max);
    }

    return 0;
}