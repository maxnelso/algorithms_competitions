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

class MagicalStringDiv1 {
  public: int getLongest(string S);
};

int MagicalStringDiv1::getLongest(string S) {
  int best = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '>') {
      int right_count = 0;
      int left_count = 0;
      for (int j = 0; j < S.size(); j++) {
        if (j <= i && S[j] == '>') {
          right_count++;
        }
        if (j > i && S[j] == '<') {
          left_count++;
        }
      }
      best = max(best, min(right_count, left_count) * 2);
    }
  }
  return best;
}

int main () {
  MagicalStringDiv1 dummy;
  int result;

  string test0 = "<><><<>";
  result = dummy.getLongest(test0);
  if (result == 4) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 4, result);
  }

  string test1 = ">>><<<";
  result = dummy.getLongest(test1);
  if (result == 6) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 6, result);
  }

  string test2 = "<<<>>>";
  result = dummy.getLongest(test2);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }

  string test3 = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>";
  result = dummy.getLongest(test3);
  if (result == 24) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 24, result);
  }


}
