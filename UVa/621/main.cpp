#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

int main () {
	int t;
	scanf("%d", &t);

	while (t--) {
		char result = '@';
		string str;
		setbuf(stdin, NULL);
		getline(cin, str);

		cout << str << endl;

		if (str.length() == 1)
			if (str.at(0) == '1' || str.at(0) == '4')
				result = '+';

		if (str.length() >= 2) {
			if (str.length() == 2 && str.at(0) == '7' && str.at(1) == '8')
				result = '+';

			if (str.at(str.length() - 1) == '5' && str.at(str.length() - 2) == '3')
				result = '-';
		}

		printf("%c\n", result);
	}
	return 0;
}
