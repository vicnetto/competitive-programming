#include <bits/stdc++.h>
#include <tgmath.h>

using namespace std;

int main () {
	int k, n, m, ans;
	float ans1, ans2;

	scanf("%d", &k);

	while (k--) {
		scanf("%d %d", &n, &m);

		n -= 2; m -= 2;

		ans1 = (float) n / 3;
		ans2 = (float) m / 3;
		ans = ceil(ans1) * ceil(ans2);
		printf("%d\n", ans);
	}
}
