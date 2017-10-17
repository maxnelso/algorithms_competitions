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

class ColorfulCoinsEasy {
  public: string isPossible(vector <int> values);
};

string ColorfulCoinsEasy::isPossible(vector <int> values) {
  bool choices[200001];
  fill(begin(choices), end(choices), false);
  int n = values.size();
  for (int i = 0; i < n - 1; i++) {
    bool found = false;
    for (int d = values[i+1] / values[i] - 1; d >=1; d--) {
      if (!choices[d]) {
        choices[d] = true;
        found = true;
        break;
      }
    }
    if (!found) {
      return "Impossible";
    }
  }
  return "Possible";
}

int main () {
  ColorfulCoinsEasy dummy;
  string result;

  static const int arr0[] = {1};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  result = dummy.isPossible(test0);
  if (result == "Possible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Possible", result.c_str());
  }

  static const int arr1[] = {1, 3};
  vector<int> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  result = dummy.isPossible(test1);
  if (result == "Possible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Possible", result.c_str());
  }

  static const int arr2[] = {1, 2, 4};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  result = dummy.isPossible(test2);
  if (result == "Impossible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Impossible", result.c_str());
  }

  static const int arr3[] = {1, 5, 15, 90};
  vector<int> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  result = dummy.isPossible(test3);
  if (result == "Possible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Possible", result.c_str());
  }

  static const int arr4[] = {1, 4, 20, 60, 180, 1440, 5760};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  result = dummy.isPossible(test4);
  if (result == "Impossible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Impossible", result.c_str());
  }

  static const int arr5[] = {1, 7, 21, 105, 630, 3150, 18900};
  vector<int> test5(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]));
  result = dummy.isPossible(test5);
  if (result == "Possible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Possible", result.c_str());
  }

  static const int arr6[] = {1, 10, 30, 300, 900, 9000, 18000};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  result = dummy.isPossible(test6);
  if (result == "Impossible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Impossible", result.c_str());
  }

  static const int arr7[] = {1, 2, 10, 40, 200, 1000, 4000, 20000};
  vector<int> test7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
  result = dummy.isPossible(test7);
  if (result == "Impossible") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "Impossible", result.c_str());
  }


}
