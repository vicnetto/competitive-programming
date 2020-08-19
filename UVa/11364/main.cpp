#include <bits/stdc++.h>
#include <cmath>

int main () {
	int k;

	scanf("%d", &k);

	while (k--) {
	int max = -1, min = INT_MAX, n, numb, dist, qnt;
		
		scanf("%d", &n);
		qnt = n;
		
		while (n--) {
			scanf("%d", &numb);
			if (numb < min) min = numb;
			else if (numb > max) max = numb;
		}

		if (n == 1) dist = 0;
		dist = 2 * (max - min);

		printf("%d\n", dist);
	}

	return 0;
}
