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
  int result = 0;
  for (int i = 0; i < n; ++i) {
    char c[256];
    scanf("%s", c);
    string s(c);
    if (s.find("++") != string::npos) {
      result++;
    }
    if (s.find("--") != string::npos) {
      result--;
    }
  }
  printf("%d", result);
  fflush(stdout);
}
