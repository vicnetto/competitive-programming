#include <bits/stdc++.h>

using namespace std;

int main () {
	int k, n1, n2;
	string str;

	scanf("%d", &k);

	while (k--) {
		scanf("%d %d", &n1, &n2);
		n1 > n2 ? str = ">" : n1 < n2 ? str = "<" : str = "=";

		printf("%s\n", str.c_str());
	}

	return 0;
}
