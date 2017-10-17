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

class CombinationLockDiv1 {
  public: int minimumMoves(vector <string> P, vector <string> Q);
};

int CombinationLockDiv1::minimumMoves(vector <string> P, vector <string> Q) {
  stringstream ss;
  copy(P.begin(), P.end(), ostream_iterator<string>(ss, ""));
  string S = ss.str();
  ss.str("");
  copy(Q.begin(), Q.end(), ostream_iterator<string>(ss, ""));
  string T = ss.str();
  int ds[T.size()];
  for (int i = 0; i < T.size(); i++) {
    int start = S[i] - '0';
    int end = T[i] - '0';
    //i'm bad
    int up = 0;
    while (start != end) {
      start = (start + 1) % 10;
      up++;
    }
    int down = 0;
    start = S[i] - '0';
    while (start != end) {
      start = (start - 1);
      if (start < 0) {
        start = start + 10;
      }
      down++;
    }
    ds[i] = min(up, down);
  }
  int result = 0;
  for (int i = 0; i < T.size(); i++) {
    if (ds[i] == 0) {
      continue;
    } else if (ds[i] < 0) {
      while (ds[i] != 0) {
        result++;
        for (int j = i; j < T.size(); j++) {
          if (ds[j] < 0) {
            ds[j]++;
          } else {
            break;
          }
        }
      }
    } else {
      while (ds[i] != 0) {
        result++;
        for (int j = i; j < T.size(); j++) {
          if (ds[j] > 0) {
            ds[j]--;
          } else {
            break;
          }
        }
      }
    }
  }
  return result;

}

int main () {
  CombinationLockDiv1 dummy;
  int result;

  static const string arr0[] = {"123"};
  vector<string> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  static const string arr1[] = {"112"};
  vector<string> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  result = dummy.minimumMoves(test0, test1);
  if (result == 1) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 1, result);
  }

  static const string arr2[] = {"1"};
  vector<string> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  static const string arr3[] = {"7"};
  vector<string> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  result = dummy.minimumMoves(test2, test3);
  if (result == 4) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 4, result);
  }

  static const string arr4[] = {"6", "07"};
  vector<string> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  static const string arr5[] = {"", "60", "7"};
  vector<string> test5(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]));
  result = dummy.minimumMoves(test4, test5);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }

  static const string arr6[] = {"1234"};
  vector<string> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  static const string arr7[] = {"4567"};
  vector<string> test7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
  result = dummy.minimumMoves(test6, test7);
  if (result == 3) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 3, result);
  }

  static const string arr8[] = {"020"};
  vector<string> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  static const string arr9[] = {"909"};
  vector<string> test9(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]));
  result = dummy.minimumMoves(test8, test9);
  if (result == 2) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 2, result);
  }

  static const string arr10[] = {"4423232218340"};
  vector<string> test10(arr10, arr10 + sizeof(arr10) / sizeof(arr10[0]));
  static const string arr11[] = {"6290421476245"};
  vector<string> test11(arr11, arr11 + sizeof(arr11) / sizeof(arr11[0]));
  result = dummy.minimumMoves(test10, test11);
  if (result == 19) { //wrong
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 19, result);
  }


}
