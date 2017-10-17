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

class MaxMinTreeGame {
  public: int findend(vector <int> edges, vector <int> costs);
};

int MaxMinTreeGame::findend(vector <int> edges, vector <int> costs) {
  int n = edges.size() + 1;
  vector<int> degrees(n, 0);
  for (int i = 0; i < edges.size(); i++) {
    degrees[edges[i]]++;
    degrees[i+1]++;
  }
  int best = 0;
  for (int i = 0; i < n; i++) {
    if (degrees[i] == 1) {
      best = max(best, costs[i]);
    }
  }
  return best;
}

int main () {
  MaxMinTreeGame dummy;
  int result;

  static const int arr0[] = {0};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  static const int arr1[] = {4,6};
  vector<int> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  result = dummy.findend(test0, test1);
  if (result == 6) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 6, result);
  }

  static const int arr2[] = {0,1};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  static const int arr3[] = {4,6,5};
  vector<int> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  result = dummy.findend(test2, test3);
  if (result == 5) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 5, result);
  }

  static const int arr4[] = {0,1,2,3};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  static const int arr5[] = {0,1,0,1,0};
  vector<int> test5(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]));
  result = dummy.findend(test4, test5);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }

  static const int arr6[] = {0,0,0};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  static const int arr7[] = {5,1,2,3};
  vector<int> test7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
  result = dummy.findend(test6, test7);
  if (result == 3) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 3, result);
  }

  static const int arr8[] = {0,0};
  vector<int> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  static const int arr9[] = {3,2,5};
  vector<int> test9(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]));
  result = dummy.findend(test8, test9);
  if (result == 5) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 5, result);
  }


}
