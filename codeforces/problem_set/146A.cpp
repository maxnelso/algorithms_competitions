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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (i == a.size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  char c[256];
  scanf("%s", c);
  string s(c);
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '4' && s[i] != '7') {
      printf("NO");
      return 0;
    }
  }
  string f = s.substr(0, n/2);
  string r = s.substr(n/2);
  int first_sum = 0;
  int second_sum = 0;
  for (int i = 0; i < n/2; ++i) {
    first_sum += f[i] - '0';
    second_sum += r[i] - '0';
  }
  if (first_sum == second_sum) {
    printf("YES");
  } else {
    printf("NO");
  }
}
