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
  int i;
  int left;
  int right;
};

int main () {
  int n;
  scanf("%d", &n);
  vector<node*> nodes;
  vector<node*> starts;
  for (int i = 0; i < n; i++) {
    node* new_node = new node();
    int a, b;
    scanf("%d %d", &a, &b);
    new_node->left = a - 1;
    new_node->right = b - 1;
    new_node->i = i;
    if (a == 0) {
      starts.push_back(new_node);
    }
    nodes.push_back(new_node);
  }

  // Get end
  node* end = starts[0];
  while (end->right != -1) {
    end = nodes[end->right];
  }

  for (int i = 1; i < starts.size(); i++) {
    end->right = starts[i]->i;
    starts[i]->left = end->i;
    // Get end
    end = starts[i];
    while (end->right != -1) {
      end = nodes[end->right];
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d %d\n", nodes[i]->left + 1, nodes[i]->right + 1);
  }
}
