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
  int n;
  scanf("%d", &n);
  printf("hio");
  bool adjacent[10000][10000];
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adjacent[a-1][b-1] = true;
  }
  vector<bool> have;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    have.push_back(a);
  }
  vector<bool> want;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    want.push_back(a);
  }
  queue<int> q;
  q.push(0);
  vector<int> out;
  vector<bool> seen_out(n);
  fill(seen_out.begin(), seen_out.end(), false);
  printf("hio");
  while (!q.empty()) {
    int node = q.front();
    printf("Looking at %d", node);
    seen_out[node] = true;
    q.pop();
    if (want[node] != have[node]) {
      bool getting = want[node];
      out.push_back(node);
      have[node] = getting;
      queue<int> children;
      children.push(node);
      vector<bool> seen(n);
      fill(seen.begin(), seen.end(), false);
      while (!children.empty()) {
        int child = children.front();
        seen[child] = true;
        have[child] = !have[child];
        children.pop();
        for (int i = 0; i < n; i++) {
          if (adjacent[i][child] && i != node && !seen[i]) {
            children.push(i);
          }
        }
        for (int i = 0; i < n; i++) {
          if (adjacent[child][i] && i != node && !seen[i]) {
            children.push(i);
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (adjacent[i][node] && !seen_out[i]) {
        q.push(i);
      }
    }
    for (int i = 0; i < n; i++) {
      if (adjacent[node][i] && !seen_out[i]) {
        q.push(i);
      }
    }
  }
  printf("%d\n", out.size());
  for (int i = 0; i < out.size(); i++) {
    printf("%d\n", out[i] + 1);
  }
}
