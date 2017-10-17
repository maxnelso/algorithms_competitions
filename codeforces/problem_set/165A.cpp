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
  vector<pair<int, int> > coords;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    coords.push_back(make_pair(a, b));
  }
  int result = 0;
  for (int i = 0; i < n; ++i) {
    bool left = false, right = false, bottom = false, top = false;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        pair<int, int> a = coords[i];
        pair<int, int> b = coords[j];
        if (a.second == b.second && a.first > b.first) {
          left = true;
        }
        if (a.second == b.second && a.first < b.first) {
          right = true;
        }
        if (a.first == b.first && a.second > b.second) {
          top = true;
        }
        if (a.first == b.first && a.second < b.second) {
          bottom = true;
        }
      }
    }
    if (left && right && bottom && top) {
      result++;
    }
  }
  printf("%d", result);
}
