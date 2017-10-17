#include <bitset>
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
#include <climits>
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

struct node {
  int current_balance;
  int previous;
  int depth;
  vector<int> path;
};

int main () {
  vector<int> weights;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      weights.push_back(i + 1);
    }
  }
  int m;
  scanf("%d", &m);

  stack<node> q;
  node start;
  start.current_balance = 0;
  start.previous = 0;
  start.depth = 1;
  start.path = vector<int>();
  q.push(start);
  while (!q.empty()) {
    node n = q.top();
    q.pop();
    if (n.depth == m + 1) {
      printf("YES\n");
      for (int i = 0; i < n.path.size(); i++) {
        printf("%d ", n.path[i]);
      }
      return 0;
    }
    for (int i = 0; i < weights.size(); i++) {
      if (n.depth % 2 == 0) {
        if (n.current_balance + weights[i] > 0 && weights[i] != n.previous) {
          node new_node;
          new_node.path = n.path;
          new_node.path.push_back(weights[i]);
          new_node.depth = n.depth + 1;
          new_node.previous = weights[i];
          new_node.current_balance = n.current_balance + weights[i];
          q.push(new_node);
        }
      } else {
        if (n.current_balance - weights[i] < 0 && weights[i] != n.previous) {
          node new_node;
          new_node.path = n.path;
          new_node.path.push_back(weights[i]);
          new_node.depth = n.depth + 1;
          new_node.previous = weights[i];
          new_node.current_balance = n.current_balance - weights[i];
          q.push(new_node);
        }
      }
    }
  }
  printf("NO");
}
