#include <bits/stdc++.h>
#include <utility>

using namespace std;

pair<int, int> fib (int n) {
    pair<int, int> value;

    if (n == 0)
        return make_pair(1, 0);

    if (n == 1)
        return make_pair(1, 1);

    pair<int, int> x = fib(n - 1);
    pair<int, int> y = fib(n - 2);

    return make_pair((1 + x.first + y.first), (x.second + y.second));
}

int main () {
    int n, i;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &i);

        pair<int, int> result = fib(i);

        cout << "fib(" << i << ") = " << result.first - 1 << " calls = " << result.second << endl;
    }

    return 0;
}