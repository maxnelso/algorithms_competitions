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
#include <climits>
using namespace std;

class PackingBallsDiv1 {
  public: int minPacks(int K, int A, int B, int C, int D);
};

int PackingBallsDiv1::minPacks(int K, int A, int B, int C, int D) {
  long long int X[K];
  X[0] = A;
  int result = 0;
  for (int i = 1; i < K; i++) {
    X[i] = (X[i-1] * B + C) % D + 1;
  }
  for (int i = 0; i < K; i++) {
    result += X[i] / K;
    X[i] = X[i] % K;
  }
  sort(X, X + K);
  int others = INT_MAX;
  for (int i = 0; i < K; i++) {
    if (X[i] + K - (i + 1) < others) {
      others = X[i] + K - (i + 1);
    }
  }
  return result + others;
}

int main () {
  PackingBallsDiv1 dummy;
  int result;

  int test0 = 3;
  int test1 = 4;
  int test2 = 2;
  int test3 = 5;
  int test4 = 6;
  result = dummy.minPacks(test0, test1, test2, test3, test4);
  if (result == 4) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 4, result);
  }

  int test5 = 1;
  int test6 = 58;
  int test7 = 23;
  int test8 = 39;
  int test9 = 93;
  result = dummy.minPacks(test5, test6, test7, test8, test9);
  if (result == 58) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 58, result);
  }

  int test10 = 23;
  int test11 = 10988;
  int test12 = 5573;
  int test13 = 4384;
  int test14 = 100007;
  result = dummy.minPacks(test10, test11, test12, test13, test14);
  if (result == 47743) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 47743, result);
  }

  int test15 = 100000;
  int test16 = 123456789;
  int test17 = 234567890;
  int test18 = 345678901;
  int test19 = 1000000000;
  result = dummy.minPacks(test15, test16, test17, test18, test19);
  if (result == 331988732) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 331988732, result);
  }


}
