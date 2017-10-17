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

class WinterAndCandies {
  public: int getNumber(vector <int> type);
};

int WinterAndCandies::getNumber(vector <int> type) {
  int counts[52];
  int K = 50;
  memset(counts, 0, sizeof(counts));
  for (int i = 0; i < type.size(); i++) {
    counts[type[i]]++;
  }
  int result = 0;
  for (int i = 1; i <= K; i++) {
    int c = 1;
    for (int j = 1; j <= i; j++) {
      c *= counts[j];
    }
    result += c;
  }
  return result;
}

int main () {
  WinterAndCandies dummy;
  int result;

  static const int arr0[] = {1, 3, 2};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  result = dummy.getNumber(test0);
  if (result == 3) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 3, result);
  }

  static const int arr1[] = {1, 1, 2};
  vector<int> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  result = dummy.getNumber(test1);
  if (result == 4) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 4, result);
  }

  static const int arr2[] = {1, 3, 2, 5, 7, 4, 5, 4};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  result = dummy.getNumber(test2);
  if (result == 9) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 9, result);
  }

  static const int arr3[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  vector<int> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  result = dummy.getNumber(test3);
  if (result == 62) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 62, result);
  }

  static const int arr4[] = {2};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  result = dummy.getNumber(test4);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }


}
