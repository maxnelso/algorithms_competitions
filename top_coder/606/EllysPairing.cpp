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

class EllysPairing {
  public: int getMax(int M, vector <int> count, vector <int> first, vector <int> mult, vector <int> add);
};

int EllysPairing::getMax(int M, vector <int> count, vector <int> first, vector <int> mult, vector <int> add) {
  pair<int, int> majority;
  majority.first = -1;
  majority.second = 0;
  for (int i = 0; i < count.size(); i++) {
    unsigned int num = first[i];
    for (int j = 0; j < count[i]; j++) {
      if (majority.second == 0) {
        majority.first = num;
        majority.second = 1;
      } else {
        if (majority.first == num) {
          majority.second++;
        } else {
          majority.second--;
        }
      }
      num = (num * mult[i] + add[i]) & (M - 1);
    }
  }
  int c = 0;
  int n = 0;
  for (int i = 0; i < count.size(); i++) {
    unsigned int num = first[i];
    for (int j = 0; j < count[i]; j++) {
      if (num == majority.first) {
        c++;
      }
      n++;
      num = (num * mult[i] + add[i]) & (M - 1);
    }
  }
  if (c> (n + 1) / 2) {
    if (n % 2 == 1) {
      return n /2 - (c - n/2 - 1);
    } else {
      return n /2 - (c - n/2);
    }
  } else {
    return n /2;
  }
}

int main () {
  EllysPairing dummy;
  int result;

  int test0 = 16;
  static const int arr1[] = {4, 7};
  vector<int> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  static const int arr2[] = {5, 3};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  static const int arr3[] = {2, 3};
  vector<int> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  static const int arr4[] = {1, 0};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  result = dummy.getMax(test0, test1, test2, test3, test4);
  if (result == 5) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 5, result);
  }

  int test5 = 8;
  static const int arr6[] = {6, 4, 3};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  static const int arr7[] = {0, 3, 2};
  vector<int> test7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
  static const int arr8[] = {3, 7, 5};
  vector<int> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  static const int arr9[] = {0, 3, 2};
  vector<int> test9(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]));
  result = dummy.getMax(test5, test6, test7, test8, test9);
  if (result == 5) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 5, result);
  }

  int test10 = 128;
  static const int arr11[] = {42, 13, 666, 17, 1337, 42, 1};
  vector<int> test11(arr11, arr11 + sizeof(arr11) / sizeof(arr11[0]));
  static const int arr12[] = {18, 76, 3, 122, 0, 11, 11};
  vector<int> test12(arr12, arr12 + sizeof(arr12) / sizeof(arr12[0]));
  static const int arr13[] = {33, 17, 54, 90, 41, 122, 20};
  vector<int> test13(arr13, arr13 + sizeof(arr13) / sizeof(arr13[0]));
  static const int arr14[] = {66, 15, 10, 121, 122, 1, 30};
  vector<int> test14(arr14, arr14 + sizeof(arr14) / sizeof(arr14[0]));
  result = dummy.getMax(test10, test11, test12, test13, test14);
  if (result == 1059) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 1059, result);
  }

  int test15 = 1048576;
  static const int arr16[] = {4242, 42, 9872, 13, 666, 21983, 17, 1337, 42, 1};
  vector<int> test16(arr16, arr16 + sizeof(arr16) / sizeof(arr16[0]));
  static const int arr17[] = {19, 18, 76, 42, 3, 112, 0, 11, 11, 12};
  vector<int> test17(arr17, arr17 + sizeof(arr17) / sizeof(arr17[0]));
  static const int arr18[] = {27, 33, 10, 8, 17, 9362, 90, 41, 122, 20};
  vector<int> test18(arr18, arr18 + sizeof(arr18) / sizeof(arr18[0]));
  static const int arr19[] = {98, 101, 66, 15, 10, 144, 3, 1, 5, 1};
  vector<int> test19(arr19, arr19 + sizeof(arr19) / sizeof(arr19[0]));
  result = dummy.getMax(test15, test16, test17, test18, test19);
  if (result == 16232) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 16232, result);
  }


}
