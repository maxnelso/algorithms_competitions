#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>
#define print_vector(a) for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}}
using namespace std;

int main () {
  int n;
  scanf("%d", &n);
  string out = "";
  for (int i = 0; i < 2*n + 1; i++) {
    string s = "";
    int spaces = 2*abs(n - i);
    for (int j = 0; j < spaces; ++j) {
      s = s + " ";
    }
    int m = n - abs(n-i);
    for (int j = 0; j < 2*m + 1; ++j) {
      stringstream ss;
      ss << m - abs(m - j);
      s = s + ss.str();
      if (j != 2*m) {
        s = s + " ";
      }
    }
    if (i != 2*n) {
      s = s + "\n";
    }
    out = out + s;
  }
  printf("%s", out.c_str());
  fflush(stdout);
}
