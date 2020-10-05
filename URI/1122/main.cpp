#include <bits/stdc++.h>
#include <utility>

#define S 42

using namespace std;

int size;
int flux;
int vect[S];
char elements[S];

bool findAllPossible (int value, int sum, int actual) {
    sum += value;

    if (size == actual)
        return sum == flux ? true : false;

    bool first = findAllPossible(vect[actual + 1], sum, actual + 1);
    bool second = findAllPossible(-vect[actual + 1], sum, actual + 1);

    if (first == true || second == true) {
        if (first == true) {
            if (elements[actual + 1] != '?' && elements[actual + 1] != '-')
                elements[actual + 1] = '+';
            else
                elements[actual + 1] = '?';
        } else {
            if (elements[actual + 1] != '?' && elements[actual + 1] != '+')
                elements[actual + 1] = '-';
            else
                elements[actual + 1] = '?';
        }

        if (first == true && second == true) {
            elements[actual + 1] = '?';
        }

        return true;
    }

    return false;
}

int main () {
    while (scanf("%d %d", &size, &flux)) {
        if (size == 0 && flux == 0)
            return 0;

        vect[0] = 0;
        elements[0] = 'X';

        for (int i = 1; i <= size; i++) {
            scanf("%d", &vect[i]);
            elements[i] = '*';
        }

        findAllPossible(vect[0], 0, 0);

        if (elements[1] != '*') {
            for (int i = 1; i <= size; i++) {
                cout << elements[i] << " ";
            }
        } else {
            cout << '*';
        }

        cout << endl;
    }

    return 0;
}