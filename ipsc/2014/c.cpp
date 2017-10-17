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

string FILENAME = "test";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

vector<int> process(vector<int> nums) {
  bool done = false;
  int end = 0;
  int size = 0;
  for (int i = 1; i <= SUBSTRING_MAX; i++) {
    for (int j = 0; j < nums.size(); j++) {
      if (j + 2 * i <= nums.size()) {
        bool good = true;
        for (int k = 0; k < i; k++) {
          if (nums[j+k] != nums[j+k+i]) {
            good = false;
            break;
          }
        }
        if (good) {
          end = j;
          size = i;
          done = true;
        }
      }
    }
    if (done) {
      break;
    }
  }
  vector<int> out(nums.size() - size);
  int index = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (i <= end || i > end + size) {
      out[index++] = nums[i];
    }
  }
  print_container(out);
  return out;
}

int main () {
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".outt").c_str(), "w", stdout);
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
    int last = nums.size() + 1;
    while (nums.size() != last) {
      last = nums.size();
      nums = process(nums);
    }
    string s = "";
    for (int i = 0; i < nums.size(); i++) {
      s += to_string(nums[i]) +" ";
    }
    s = s.substr(0, s.size() - 1);
    printf("%s\n", s.c_str());
  }
  fflush(stdout);
}
