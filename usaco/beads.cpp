/*
 ID: max_valnelso1
 LANG: C++
 PROG: beads
*/
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
using namespace std;

#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

int main(int argc, char* argv[]) {
  setbuf(stdout, NULL);
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
  int num_beads;
  scanf("%d", &num_beads);
  char c_beads[100000];
  scanf("%s", c_beads);
  string beads(c_beads);
  beads = beads + beads;
  size_t b_index = beads.find("b");
  size_t r_index = beads.find("r");
  bool red = true;
  int red_count = 0;
  int blue_count = 0;
  int max_val = 0;
  int ending_whites = 0;
  if (b_index == beads.npos || r_index == beads.npos) {
    printf("%d\n", (int) beads.size() /2);
    return 0;
  }
  if (b_index < r_index) {
    red = false;
  }
  for (string::iterator it = beads.begin(); it != beads.end(); it++) {
    char c = *it;
    if (red) {
      if (c == 'w' || c == 'r') {
        red_count++;
      } else {
        int test = red_count + blue_count - ending_whites;
        if (test > max_val) {
          max_val = test;
        }
        blue_count = 1;
        red = false;
        string::iterator backwards = it;
        ending_whites = 0;
        while (backwards > beads.begin()) {
          backwards--;
          if (*backwards == 'w') {
            ending_whites++;
            blue_count++;
          } else {
            break;
          }
        }
      }
    } else {
      if (c == 'w' || c == 'b') {
        blue_count++;
      } else {
        int test = red_count + blue_count - ending_whites;
        if (test > max_val) {
          max_val = test;
        }
        red_count = 1;
        string::iterator backwards = it;
        ending_whites = 0;
        while (backwards > beads.begin()) {
          backwards--;
          if (*backwards == 'w') {
            ending_whites++;
            red_count++;
          } else {
            break;
          }
        }
        red = true;
      }
    }
  }
  printf("%d\n", min((int) beads.size() /2, max_val));
  return(0);

}
