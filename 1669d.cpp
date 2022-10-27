//BPM-22-2 Lebkova Marina
//https://codeforces.com/contest/1669/problem/D

#include <iostream>
#include <string>

int main() {
  int test = 0;
  std::cin >> test;
  for (int iTest = 0; iTest < test; iTest += 1) {
    int n;
    std::string str = "";
    std::cin >> n >> str;
    bool b = false;
    bool r = false;
    bool ans = false;
    if (n == 1) {
      if (str == "W") {
        ans = true;
      }
      else {
        ans = false;
      }
    }
    else {
      for (int i = 0; i < n; i += 1) {
	if (str[i] == 'B') {
          b = true;
	}
	else if (str[i] == 'R') {
	  r = true;
	}
	if (i == n - 1) {
	  if ((r && b) || (!r && !b)) {
	    ans = true;
	  }
	  else {
	    ans = false;
          }
	}
        else if (str[i] == 'W') {
	  if ((r && b) || (!r && !b)) {
            ans = true;
	  }
	  else {
	    ans = false;
          }
	  b = false;
          r = false;
	}
      }
    }
    std::cout << (ans ? "yes" : "no") << '\n';
  }
  return 0;
}
