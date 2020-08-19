#include <bits/stdc++.h>

int clockwise (int numb1, int numb2) {
	int td;

	if (numb2 < numb1) td = numb1 - numb2;
	else if (numb2 > numb1) td = 40 - numb2 + numb1;
	else td = 0;
	
	return td * 9;
}

int main () {
	int init, numb1, numb2, numb3;
	int td = 3;

	while(scanf("%d %d %d %d", &init, &numb1, &numb2, &numb3)) {
		if (init == 0 && numb1 == 0 && numb2 == 0 && numb3 == 0) return 0;

		td = 360 * 3;

		td += clockwise(init, numb1);
		td += clockwise(numb2, numb1);
		td += clockwise(numb2, numb3);
		
		printf("%d\n", td);
	}

	return 0;
}
