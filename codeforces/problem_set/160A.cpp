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
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    v.push_back(a);
  }
  sort(v.begin(), v.end(), greater<int>());
  for (int i = 1; i <= n; i++) {
    if (accumulate(v.begin(), v.begin() + i, 0) > accumulate(v.begin() + i, v.end(), 0)) {
      printf("%d", i);
      return 0;
    }
  }
  fflush(stdout);
}
