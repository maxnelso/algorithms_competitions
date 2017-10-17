/*
 ID: maxnelso1
 LANG: C++
 PROG: friday
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
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);
  int n;
  scanf("%d", &n);
  int days[7] = {0};
  int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day = -1;
  int start_year = 1900;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sizeof(months)/sizeof(months[0]); j++) {
      for (int k = 1; k <= months[j]; k++) {
        if (j == 1 && k == 28) {
          if (((start_year+i) % 4 == 0)) {
            if (((start_year+i) % 100 != 0) || (start_year+i) % 400 == 0) {
              day++;
              if (k == 13) {
                days[day % 7]++;
              }
            }
          }
        }
        day++;
        if (k == 13) {
          days[day % 7]++;
        }
      }
    }
  }
  for (int i = 5; i < sizeof(days)/sizeof(days[0])+5; i++) {
    if (i != sizeof(days)/sizeof(days[0])+4) {
      printf("%d ", days[i%7]);
    }
    else {
      printf("%d\n", days[i%7]);
    }
  }
  return(0);

}
