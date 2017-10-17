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
  vector<int> distances;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    distances.push_back(a);
  }
  int s, d;
  scanf("%d %d", &s, &d);
  s--;
  d--;
  int left = 0;
  int li = 0;
  int right = 0;
  int ri = s;
  int mod = s;
  while (mod != d) {
    int x = (s-li-1);
    li++;
    mod = ((x % n) + n) % n;
    left += distances[mod];
  }
  while ((ri % n) != d) {
    right += distances[ri%n];
    ri++;
  }
  printf("%d", min(left, right));
  fflush(stdout);
}
