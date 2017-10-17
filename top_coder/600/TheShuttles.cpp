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

class TheShuttles {
  public: int getLeastCost(vector <int> cnt, int baseCost, int seatCost);
};

int TheShuttles::getLeastCost(vector <int> cnt, int baseCost, int seatCost) {
  int maximum = 0;
  for (int i = 0; i < cnt.size(); i++) {
    maximum = max(maximum, cnt[i]);
  }
  int best_cost = 1000000000;
  for (int i = 1; i <= maximum; i++) {
    int cost = 0;
    for (int j = 0; j < cnt.size(); j++) {
      int num_shuttles = (int) ceil(cnt[j] / (float) i);
      cost += num_shuttles * (baseCost + i * seatCost);
    }
    best_cost = min(best_cost, cost);
  }
  return best_cost;
}

int main () {
  TheShuttles dummy;
  int result;

  static const int arr0[] = {9};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  int test1 = 30;
  int test2 = 5;
  result = dummy.getLeastCost(test0, test1, test2);
  if (result == 75) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 75, result);
  }

  static const int arr3[] = {9, 4};
  vector<int> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  int test4 = 30;
  int test5 = 5;
  result = dummy.getLeastCost(test3, test4, test5);
  if (result == 150) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 150, result);
  }

  static const int arr6[] = {9, 4};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  int test7 = 10;
  int test8 = 5;
  result = dummy.getLeastCost(test6, test7, test8);
  if (result == 105) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 105, result);
  }

  static const int arr9[] = {51, 1, 77, 14, 17, 10, 80};
  vector<int> test9(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]));
  int test10 = 32;
  int test11 = 40;
  result = dummy.getLeastCost(test9, test10, test11);
  if (result == 12096) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 12096, result);
  }


}
