#include <iostream>
#include <algorithm>
#include <string>

int main() {
	int test = 0;
	std::cin >> test;
	for (int iTest = 0; iTest < test; iTest += 1) {
		int n;
		int k;
		std::string str = "";
		std::cin >> n >> k >> str;
		int min_draw = 0;
		int cur_draw = 0;
		for (int iSt = 0; iSt < k; iSt += 1) {
			if (str[iSt] == 'W') {
				min_draw += 1;
			}
		}
		cur_draw = min_draw;
		if (min_draw > 0) {
			for (int iSt = 0; iSt < (n - k); iSt += 1) {
				if (str[iSt] == 'W') {
					cur_draw -= 1;
				}
				if (str[iSt + k] == 'W') {
					cur_draw += 1;
				}
				min_draw = std::min(min_draw, cur_draw);
			}
		}
		std::cout << min_draw << '\n';
	}
	return 0;
}
