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
#define print_vector(a) cout << "{"; for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << ", ";}} cout << "}
";using namespace std;

class EllysNumberGuessing {
  public: int getNumber(vector <int> guesses, vector <int> answers);
};

int EllysNumberGuessing::getNumber(vector <int> guesses, vector <int> answers) {
}

int main () {
  EllysNumberGuessing dummy;
  int result;

  static const int arr0[] = {600, 594};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  static const int arr1[] = {6, 12};
  vector<int> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  result = dummy.getNumber(test0, test1);
  if (result == 606) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 606, result);
  }

  static const int arr2[] = {100, 50, 34, 40};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  static const int arr3[] = {58, 8, 8, 2};
  vector<int> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  result = dummy.getNumber(test2, test3);
  if (result == 42) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 42, result);
  }

  static const int arr4[] = {500000, 600000, 700000};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  static const int arr5[] = {120013, 220013, 79987};
  vector<int> test5(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]));
  result = dummy.getNumber(test4, test5);
  if (result == -2) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", -2, result);
  }

  static const int arr6[] = {500000000};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  static const int arr7[] = {133742666};
  vector<int> test7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
  result = dummy.getNumber(test6, test7);
  if (result == -1) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", -1, result);
  }

  static const int arr8[] = {76938260, 523164588, 14196746, 296286419, 535893832, 41243148, 364561227, 270003278, 472017422, 367932361, 395758413, 301278456, 186276934, 316343129, 336557549, 52536121, 98343562, 356769915, 89249181, 335191879};
  vector<int> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  static const int arr9[] =  41243148, 364561227, 270003278, 472017422, 367932361,;
  vector<int> test9(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]));
  result = dummy.getNumber(test8, test9);
  if (result == 543212345) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 543212345, result);
  }

  static const int arr10[] = {42};
  vector<int> test10(arr10, arr10 + sizeof(arr10) / sizeof(arr10[0]));
  static const int arr11[] = {42};
  vector<int> test11(arr11, arr11 + sizeof(arr11) / sizeof(arr11[0]));
  result = dummy.getNumber(test10, test11);
  if (result == 84) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 84, result);
  }

  static const int arr12[] = {999900000};
  vector<int> test12(arr12, arr12 + sizeof(arr12) / sizeof(arr12[0]));
  static const int arr13[] = {100001};
  vector<int> test13(arr13, arr13 + sizeof(arr13) / sizeof(arr13[0]));
  result = dummy.getNumber(test12, test13);
  if (result == 999799999) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 999799999, result);
  }


}
