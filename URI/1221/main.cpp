#include <bits/stdc++.h>
#include <math.h>

using namespace std;

bool is_prime(int number) {
    if (number == 1) {
        return false;
    }

    for (int i = 2; i < int(sqrt(number)) + 1; i++) {
        if (number % i == 0) 
            return false;
    }

    return true;
}

int n;

int main () {
    int number;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &number);
        cout << (is_prime(number) ? "Prime" : "Not Prime") << endl;
    }
}