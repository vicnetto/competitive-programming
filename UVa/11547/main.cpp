#include <bits/stdc++.h>

int main () {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, sepNumber;
		float result;
		scanf("%d", &n);

		result = (float) n * 567;
		result /= 9;
		result += 7492;
		result *= 235;
		result /= 47;
		result -= 498;

		if (result >= 0 && result <= 9) sepNumber = 0;
		else sepNumber =  ((int) result / 10) % 10;

		printf("%d\n", abs(sepNumber));
	}
	return 0;
}
