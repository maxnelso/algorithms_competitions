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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;
int SUBSTRING_MAX = 5000;

string FILENAME = "c1";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int main () {
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  string dummy;
  for (int case_id = 1; case_id <= testcases; case_id++) {
    getline(cin, dummy);
    int n;
    scanf("%d", &n);
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      nums.push_back(a);
    }
    bool seen[100006];
    memset(seen, 0, 100006);
    int start = 0;
    int end = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (seen[nums[i]]) {
        if (start == 0) {
          start = i;
        }
        end = i;
      }
      seen[nums[i]] = true;
    }
    string s = "";
    for (int i = 0; i < nums.size(); i++) {
      if (i < start || i > end) {
        s += to_string(nums[i]) + " ";
      }
    }
    s = s.substr(0, s.size() - 1);
    printf("%s\n", s.c_str());
  }
  fflush(stdout);
}
