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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> puzzles;
  for (int i = 0; i < m; ++i) {
    int a;
    scanf("%d", &a);
    puzzles.push_back(a);
  }
  sort(puzzles.begin(), puzzles.end());
  int best = puzzles[n-1] - puzzles[0];
  for (int i = 0; i <= m - n; ++i) {
    if (puzzles[i+n-1] - puzzles[i] < best) {
      best = puzzles[i+n-1] - puzzles[i];
    }
  }
  printf("%d", best);
  fflush(stdout);
}
