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

class WakingUpEasy {
  public: int countAlarms(vector <int> volume, int S);
};

int WakingUpEasy::countAlarms(vector <int> volume, int S) {
  int count = 0;
  for (int i = 0; i < 10010; i++) {
    S -= volume[i%volume.size()];
    count++;
    if (S <= 0) {
      break;
    }
  }
  return count;
}

int main () {
  WakingUpEasy dummy;
  int result;

  static const int arr0[] = {5, 2, 4};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  int test1 = 13;
  result = dummy.countAlarms(test0, test1);
  if (result == 4) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 4, result);
  }

  static const int arr2[] = {5, 2, 4};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  int test3 = 3;
  result = dummy.countAlarms(test2, test3);
  if (result == 1) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 1, result);
  }

  static const int arr4[] = {1};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  int test5 = 10000;
  result = dummy.countAlarms(test4, test5);
  if (result == 10000) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 10000, result);
  }


}
