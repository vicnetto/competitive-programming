#include <bits/stdc++.h>

using namespace std;

int main (){
	int t;
	scanf("%d", &t);

	for (int j = 0; j < t; j++) {
		int numb[3];
		scanf("%d %d %d", &numb[0], &numb[1], &numb[2]);
		int n = sizeof(numb)/ sizeof(numb[0]);

		sort(numb, numb + n);

		printf("Case %d: %d\n", j + 1, numb[1]);
	}

	return 0;
}
