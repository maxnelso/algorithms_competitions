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

using namespace std;

string FILENAME = "test";



int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    printf("Case #%d: ", case_id);
    int ac, aj;
    scanf("%d %d", &ac, &aj);
    char mins[720 * 2];
    memset(mins, 'B', sizeof(mins));
    int low = 720 * 2 + 10;
    for (int i = 0; i < ac; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      low = min(low, a);
      for (int j = a; j < b; j++) {
        mins[j] = 'C';
      }
    }
    for (int i = 0; i < aj; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      low = min(low, a);
      for (int j = a; j < b; j++) {
        mins[j] = 'J';
      }
    }
    int swaps = 0;
    char caretaker = 'X';
    for (int i = 0; i < 720 * 2; i++) {
      if (mins[i] == 'B') {
        continue;
      } else if (mins[i] == 'C') {
        if (caretaker == 'X') {
          caretaker = 'J';
        } else if (caretaker == 'C') {
          caretaker = 'J';
          swaps++;
        }

      } else if (mins[i] == 'J') {
        if (caretaker == 'X') {
          caretaker = 'C';
        } else if (caretaker == 'J') {
          caretaker = 'C';
          swaps++;
        }
      }
    }
    printf("%d\n", swaps);

  }
  fflush(stdout);
}
