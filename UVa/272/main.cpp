#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main () {
	string str, sub; 
	bool open = false;
	vector<string> v;

	for (string str1 = ""; getline(cin, str1);) 
		v.push_back(str1);

	for (int i = 0; i < v.size(); i++) {
		str = v.at(i);

		for (int j = 0; j <= str.length() - 1; j++) {
			if (str.at(j) == '"') {
				if (open) {sub = "''"; open = false;}
				else {sub = "``"; open = true;}
				str.replace(j, 1, sub);
			}
		}
		
		printf("%s", str.c_str());
		if (v.size() != i) printf("\n");
	}

	return 0;
}
