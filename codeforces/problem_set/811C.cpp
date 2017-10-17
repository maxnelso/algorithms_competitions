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
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

struct node {
  vector<node*> children;
  int max_value;
};

node* make_tree(vector<int>& nums, int start) {
  int end = start;
  node* n = new node();
  for (int i = start + 1; i < nums.size(); i++) {
    if (nums[i] == nums[start]) {
      end = i;
    }
  }

  int real_end = end;
  set<int> seen;
  for (int i = start; i < end; i++) {
    if (nums[i] != nums[start]) {
      for (int j = other_start; j < 
    }
  }

}

int main () {
  int n;
  scanf("%d", &n);
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  set<int> seen;
  for (int i = 0; i < nums.size(); i++) {
    if (seen.find(nums[i])) {
      continue;
    }
  }
}
