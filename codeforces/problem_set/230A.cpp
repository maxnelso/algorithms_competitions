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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[0].size(); j++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}} cout << endl; }
using namespace std;

int main () {
  int s, n;
  scanf("%d %d", &s, &n);
  vector<pair<int, int> > dragons;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    dragons.push_back(make_pair(x, y));
  }
  sort(dragons.begin(), dragons.end());
  bool good = true;
  for (int i = 0; i < n; ++i) {
    if (s > dragons[i].first) {
      s += dragons[i].second;
    } else {
      good = false;
      break;
    }
  }
  good ? printf("YES") : printf("NO");
  fflush(stdout);
}
