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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (j == a[0].size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> points;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    points.push_back(a);
  }
  vector<pair<int, int> > segments;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    segments.push_back(make_pair(a, b));
  }
  vector<int> out;
  map<pair<int, int>, int> diff;
  for (int i = 0; i < m; i++) {
    diff[segments[i]] = 0;
  }
  out.push_back(0);
  for (int i = 0; i < m; i++) {
    if (segments[i].first <= points[0] && segments[i].second >= points[0]) {
      diff[segments[i]]++;
    }
  }
  for (int i = 1; i < n; i++) {
    int has_to_be = 5; //sentinel value
    for (int j = 0; j < m; j++) {
      if (segments[j].first <= points[i] && segments[j].second >= points[i]) {
        if (diff[segments[j]] == 1) {
          if (has_to_be == 1) {
            printf("-1");
            return 1;
          }
          has_to_be = -1;
        }
        if (diff[segments[j]] == -1) {
          if (has_to_be == -1) {
            printf("1");
            return 1;
          }
          has_to_be = 1;
        }
      }
    }
    if (has_to_be == 5) {
      has_to_be = 1;
    }
    if (has_to_be == 1) {
      out.push_back(0);
    } else {
      out.push_back(1);
    }
    for (int j = 0; j < m; j++) {
      if (segments[i].first >= points[0] && segments[i].second <= points[0]) {
        diff[segments[j]] = diff[segments[j]] + has_to_be;
      }
    }
  }
  print_vector(out);
}
