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
  char c[256];
  scanf("%s", c);
  string s(c);
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '4' && s[i] != '1') {
      printf("NO");
      return 0;
    }
    if (i < s.size() - 2) {
      if (s[i] == '1' && s[i+1] == '4' && s[i+2] == '4') {
        i = i + 2;
        continue;
      }
    }
    if (i < s.size() - 1) {
      if (s[i] == '1' && s[i+1] == '4') {
        i = i + 1;
        continue;
      }
    }
    if (s[i] != '1') {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
}
