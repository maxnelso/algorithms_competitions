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

string FILENAME = "C-small-practice";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int run_simulation(int hd, int ad, int hk, int ak, int b, int d, int b_times, int d_times) {
  int max_hd = hd;
  bool healed_last_turn = false;
  int turns = 0;
  while (true) {
    // Debuffs
    turns++;
    if (ad >= hk) {
      return turns;
    }
    if (d_times > 0) {
      if (ak - d >= hd) {
        hd = max_hd;
        if (healed_last_turn) {
          return -1;
        }
        healed_last_turn = true;
      } else {
        ak -= d;
        d_times--;
        healed_last_turn = false;
      }
    } else {
      // Buffs and attacks
      if (ak >= hd) {
        if (healed_last_turn) {
          return -1;
        }
        hd = max_hd;
        healed_last_turn = true;
      } else {
        if (b_times > 0) { // Buff
          ad += b;
          b_times--;
          healed_last_turn = false;
        } else { // Attack
          hk -= ad;
          if (hk <= 0) {
            return turns;
          }
          healed_last_turn = false;
        }
      }
    }
    hd -= ak;
  }
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    printf("Case #%d: ", case_id);
    int hd, ad, hk, ak, b, d;
    scanf("%d %d %d %d %d %d", &hd, &ad, &hk, &ak, &b, &d);
    if (hd <= ak - d && hk > ad) {
      printf("IMPOSSIBLE\n");
      continue;
    }
    int best = -1;
    for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        int test = run_simulation(hd, ad, hk, ak, b, d, i, j);
        if (test == -1) {
          continue;
        }
        if (best == -1 || test < best) {
          best = test;
        }
      }
    }
    if (best == -1) {
      printf("IMPOSSIBLE\n");
    } else {
      printf("%d\n", best);
    }
  }
  fflush(stdout);
}
