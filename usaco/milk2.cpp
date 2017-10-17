/*
 ID: maxnelso1
 LANG: C++
 PROG: milk2
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
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);
  int farmers;
  scanf("%d", &farmers);
  bool intervals[1000000] = {false};
  for (int i = 0; i < farmers; i++) {
    int beginning, end;
    scanf("%d %d", &beginning, &end);
    for (int j = beginning; j < end; j++) {
      intervals[j] = true;
    }
  }
  bool milking = intervals[0];
  int longest_milking, longest_not_milking = 0;
  int count = 0;
  int starting_index = 0;
  for (int i = 0; i < sizeof(intervals) / sizeof(intervals[0]); i++) {
    if (intervals[i]) {
      starting_index = i;
      break;
    }
  }
  for (int i = starting_index; i < sizeof(intervals) / sizeof(intervals[0]); i++) {
    if (milking && !intervals[i]) {
      if (count > longest_milking) {
        longest_milking = count;
      }
      count = 1;
      milking = false;
    } else if (!milking && intervals[i]) {
      if (count > longest_not_milking) {
        longest_not_milking = count;
      }
      count = 1;
      milking = true;
    } else {
      count++;
    }
  }
  printf("%d %d\n", longest_milking, longest_not_milking);
  return(0);

}
