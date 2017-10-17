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

class SpamChecker {
  public: string spamCheck(string judgeLog, int good, int bad);
};

string SpamChecker::spamCheck(string judgeLog, int good, int bad) {
  int result = 0;
  for (int i = 0; i < judgeLog.size(); ++i) {
    if (judgeLog[i] == 'x') {
      result -= bad;
    } else {
      result += good;
    }
    if (result < 0) {
      return "SPAM";
    }
  }
  return "NOT SPAM";
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  SpamChecker dummy;
  string result;

  string test0 = "ooooxxxo";
  int test1 = 2;
  int test2 = 3;
  result = dummy.spamCheck(test0, test1, test2);
  if (result == "SPAM") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "SPAM", result.c_str());
  }

  string test3 = "ooooxxxo";
  int test4 = 3;
  int test5 = 4;
  result = dummy.spamCheck(test3, test4, test5);
  if (result == "NOT SPAM") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "NOT, result.c_str());
  }

  string test6 = "xooooooooooooooooooooooooooo";
  int test7 = 1000;
  int test8 = 1;
  result = dummy.spamCheck(test6, test7, test8);
  if (result == "SPAM") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "SPAM", result.c_str());
  }

  string test9 = "oxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
  int test10 = 1000;
  int test11 = 1;
  result = dummy.spamCheck(test9, test10, test11);
  if (result == "NOT) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "NOT, result.c_str());
  }

  string test12 = "ooxoxoxooxoxxoxoxooxoxoxoxxoxx";
  int test13 = 15;
  int test14 = 17;
  result = dummy.spamCheck(test12, test13, test14);
  if (result == "SPAM") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "SPAM", result.c_str());
  }

  string test15 = "oooxoxoxoxoxoxooxooxoxooxo";
  int test16 = 16;
  int test17 = 18;
  result = dummy.spamCheck(test15, test16, test17);
  if (result == "NOT SPAM") {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %s, outputted %s\n", "NOT, result.c_str());
  }


}
