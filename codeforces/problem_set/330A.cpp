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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[0].size(); j++) { if (i == a.size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

int main () {
  int r, c;
  scanf("%d %d", &r, &c);
  vector< string > cake;
  for (int i = 0; i < r; ++i) {
    char d[256];
    scanf("%s", d);
    string s(d);
    cake.push_back(s);
  }
  vector<vector<bool> > seen(r, vector<bool>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      seen[i][j] = false;
    }
  }
  int result = 0;
  for (int i = 0; i < r; ++i) {
    bool found = false;
    for (int j = 0; j < c; ++j) {
      if (cake[i][j] == 'S') {
        found = true;
        break;
      }
    }
    if (!found) {
      for (int j = 0; j < c; ++j) {
        if (!seen[i][j]) {
          result++;
        }
        seen[i][j] = true;
      }
    }
  }
  for (int j = 0; j < c; ++j) {
    bool found = false;
    for (int i = 0; i < r; ++i) {
      if (cake[i][j] == 'S') {
        found = true;
        break;
      }
    }
    if (!found) {
      for (int i = 0; i < r; ++i) {
        if (!seen[i][j]) {
          result++;
        }
        seen[i][j] = true;
      }
    }
  }
  printf("%d", result);
  fflush(stdout);
}
