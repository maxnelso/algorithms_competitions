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
#define print_vector(a) cout << "{"; for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << ",";}} cout << "}\n";
using namespace std;

string FILENAME = "A-small-attempt3";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    int n, l;
    scanf("%d %d", &n, &l);
    vector<string> initial;
    vector<string> initial_fixed;
    for (int i = 0; i < n; ++i) {
      char c[256];
      scanf("%s", c);
      string s(c);
      initial.push_back(s);
      initial_fixed.push_back("");
    }
    vector<string> want;
    for (int i = 0; i < n; ++i) {
      char c[256];
      scanf("%s", c);
      string s(c);
      want.push_back(s);
    }
    bool possible = true;
    int result = 0;
    sort(initial.begin(), initial.end());
    sort(want.begin(), want.end());
    for (int i = 0; i < l; ++i) {
      bool need_flip = false;
      int initial_ones = 0;
      int want_ones = 0;
      sort(initial_fixed.begin(), initial_fixed.end());
      for (int j = 0; j < n; ++j) {
        if (initial[j][i] == '1') {
          initial_ones++;
        }
        if (want[j][i] == '1') {
          want_ones++;
        }
      }
      if (initial_ones != want_ones) {
        if (initial_ones + want_ones != n) {
          possible = false;
          break;
        } else {
          for (int j = 0; j < n; ++j) {
            if (initial[j][i] == '1') {
              initial_fixed[j] = initial_fixed[j] + '0';
            } else {
              initial_fixed[j] = initial_fixed[j] + '1';
            }
          }
          result++;
        }
      } else  { //ambiguous
        // try it the same
        bool good = true;
        for (int j = 0; j < n; ++j) {
          string fix = initial_fixed[j];
          fix = fix + initial[j][i];
          if (fix != want[j].substr(0, i+1)) {
            good = false;
            break;
          }
        }
        if (!good) {
          good = true;
          result++;
          for (int j = 0; j < n; ++j) {
            string fix = initial_fixed[j];
            if (initial[j][i] == '1') {
              fix = fix + '0';
            } else {
              fix = fix + '1';
            }
            if (fix != want[j].substr(0, i+1)) {
              good = false;
            }
            initial_fixed[j] = fix;
          }
          if (!good) {
            possible = false;
            break;
          }
        } else {
          for (int j = 0; j < n; ++j) {
            initial_fixed[j] = initial_fixed[j] + initial[j][i];
          }
        }
      }
    }
    sort(initial_fixed.begin(), initial_fixed.end());
    sort(want.begin(), want.end());
    for (int i = 0; i < n; ++i) {
      if (initial_fixed[i] != want[i]) {
        possible = false;
        break;
      }
    }
    if (!possible) {
      printf("Case #%d: NOT POSSIBLE\n", case_id);
    } else {
      printf("Case #%d: %d\n", case_id, result);
    }
  }
  fflush(stdout);
}
