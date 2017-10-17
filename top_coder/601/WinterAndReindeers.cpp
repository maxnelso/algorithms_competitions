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

class WinterAndReindeers {
  public: int getNumber(vector <string> allA, vector <string> allB, vector <string> allC);
};

int WinterAndReindeers::getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
  string A = accumulate(allA.begin(), allA.end(), string(""));
  string B = accumulate(allB.begin(), allB.end(), string(""));
  string C = accumulate(allC.begin(), allC.end(), string(""));
}

int main () {
  WinterAndReindeers dummy;
  int result;

  static const string arr0[] = {"X"};
  vector<string> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  static const string arr1[] = {"X",  "Y"};
  vector<string> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  static const string arr2[] = {"X"};
  vector<string> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  result = dummy.getNumber(test0, test1, test2);
  if (result == 1) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 1, result);
  }

  static const string arr3[] = {"ABCXD"};
  vector<string> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  static const string arr4[] = {"BCDEF"};
  vector<string> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  static const string arr5[] = {"CD"};
  vector<string> test5(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]));
  result = dummy.getNumber(test3, test4, test5);
  if (result == 3) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 3, result);
  }

  static const string arr6[] = {"WE",  "LOVE"};
  vector<string> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  static const string arr7[] = {"WORKING",  "FOR",  "SANTA"};
  vector<string> test7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
  static const string arr8[] = {"JK"};
  vector<string> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  result = dummy.getNumber(test6, test7, test8);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }

  static const string arr9[] = {"ABCDE"};
  vector<string> test9(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]));
  static const string arr10[] = {"CDEAB"};
  vector<string> test10(arr10, arr10 + sizeof(arr10) / sizeof(arr10[0]));
  static const string arr11[] = {"B"};
  vector<string> test11(arr11, arr11 + sizeof(arr11) / sizeof(arr11[0]));
  result = dummy.getNumber(test9, test10, test11);
  if (result == 2) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 2, result);
  }

  static const string arr12[] = {"ABCABDEGAXAHDJBAAHFJDXBB",  "ABHFHCDALFDJDBBA",  "BABBAXAXXX"};
  vector<string> test12(arr12, arr12 + sizeof(arr12) / sizeof(arr12[0]));
  static const string arr13[] = {"ABLOCBAXBAHAJDXBIJKA",  "JBABCDAHKFIUDALPJAH",  "AABACX"};
  vector<string> test13(arr13, arr13 + sizeof(arr13) / sizeof(arr13[0]));
  static const string arr14[] = {"AXBADXBBAB",  "CDD"};
  vector<string> test14(arr14, arr14 + sizeof(arr14) / sizeof(arr14[0]));
  result = dummy.getNumber(test12, test13, test14);
  if (result == 23) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 23, result);
  }


}
