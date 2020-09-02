#include <bits/stdc++.h>

using namespace std;

int fib (int n) {
    int f[n + 2];

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int main () {
    int n;
    string initial;
    getline(cin, initial);
    n = stoi(initial, nullptr, 10);

    for (int i = 0; i < n; i++) {
        string binQueue;

        setbuf(stdin, NULL);
        getline(cin, binQueue);
        int i_bin = bitset<10010>(binQueue).to_ulong();
        printf("%d\n", i_bin);
        int fibNumber = fib(i_bin);

        if (fibNumber / 10 == 0) {
            cout << "00" << fibNumber << endl;
        } else if (fibNumber / 10 < 10) {
            cout << "0" << fibNumber << endl;
        } else {
            cout << fibNumber << endl;
        }

    }

    return 0;
}