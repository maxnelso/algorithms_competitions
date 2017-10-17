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

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int k, n1, n2, n3, t1, t2, t3;
  scanf("%d %d %d %d %d %d %d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
  int washing_tick = t1;
  int drying_tick = t2;
  int folding_tick = t3;
  queue<int> nowhere;
  queue<int> washing;
  queue<int> drying;
  queue<int> folding;
  for (int i = 0; i < k; ++i) {
    nowhere.push(0);
  }
  for (int i = 0; i < MIN(nowhere.size(), n1); ++i) {
    nowhere.pop();
    washing.push(t1);
  }
  int current_time = 0;
  printf("HIO\n");
  while (nowhere.size() != 0 || washing.size() != 0 || drying.size() != 0 || folding.size() != 0) {
    int washing_time = 10000000;
    int drying_time = 10000000;
    int folding_time = 10000000;
    if (washing.size() > 0) {
      washing_time = washing.front();
    }
    if (drying.size() > 0) {
      drying_time = drying.front();
    }
    if (folding_time.size() > 0) {
      folding_time = folding.front();
    }
    current_time = MIN(MIN(washing_time, folding_time), drying_time);
    printf("%d\n", current_time);
    if (current_time == folding_time) {
      for (int i = 0; i < folding.size(); ++i) {
        if (folding.front() == current_time) {
          folding.pop();
        } else {
          break;
        }
      }
    } else if (current_time == drying_time) {
      for (int i = 0; i < drying.size(); ++i) {
        if (drying.front() == current_time) {
          drying.pop_back();
        }
        folding.push(((folding.size() / n3) + 1) * (current_time + t3));
      }
    } else if (current_time == ) {
      for (int i = 0; i < MIN(washing.size(), n1); ++i) {
        washing.pop_back();
        if (drying.size() == 0) {
          t2 = current_time + drying_tick;
        }
        drying.push_back(true);
      }
      for (int i = 0; i < MIN(nowhere.size(), n1); ++i) {
        nowhere.pop_back();
        washing.push_back(true);
      }
      if (nowhere.size() == 0 && washing.size() == 0) {
        t1 += 1000000;
      } else {
        t1 += washing_tick;
      }
    }
  }
  printf("%d", current_time);
}
