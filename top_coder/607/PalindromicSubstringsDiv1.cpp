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
using namespace std;

class PalindromicSubstringsDiv1 {
  public: double expectedPalindromes(vector <string> S1, vector <string> S2);
};

double memo[5000][5000];

double palindrone_prob(string s, int i, int j) {
  int i = 0;
  int j = s.size() - 1;
  double p = 1;
  while (i < j) {
    if (i == j) { // odd
      break;
    }

    if (s[i] != s[j] && s[i] != '?' && s[j] != '?') {
      return 0;
    } else if (s[i] != s[j] && s[i] == '?' ||
               s[i] != s[j] && s[j] == '?' ||
               s[i] == s[j] && s[i] == '?') {
      p = p * (1/26.0);
    } else {
      p = p;
    }
    i++;
    j--;
  }
  return p;
}
double PalindromicSubstringsDiv1::expectedPalindromes(vector <string> S1, vector <string> S2) {
  stringstream ss;
  memset(memo, -1, sizeof(memo);
  copy(S1.begin(), S1.end(), ostream_iterator<string>(ss, ""));
  copy(S2.begin(), S2.end(), ostream_iterator<string>(ss, ""));
  string s = ss.str();
  double result = 0;
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 0; j < s.size() - i + 1; j++) {
      string sub = s.substr(j, i);
      if (memo[j][j+i-1] != -1) {
        result += memo[j][j+i-1];
      } else {
        int p = palindrone_prob(sub);
        memo[j][j+i]-
        result += palindrone_prob(sub);
      }
    }
  }
  return result;
}


int main () {
  PalindromicSubstringsDiv1 dummy;
  double result;

  static const string arr0[] = {"a", "a", ""};
  vector<string> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  static const string arr1[] = {"a"};
  vector<string> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  result = dummy.expectedPalindromes(test0, test1);
  if (result == 6.0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %f, outputted %f\n", 6.0, result);
  }

  static const string arr2[] = {"z??"};
  vector<string> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  static const string arr3[] = {};
  vector<string> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  result = dummy.expectedPalindromes(test2, test3);
  if (result == 3.115384615384615) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %f, outputted %f\n", 3.115384615384615, result);
  }

  static const string arr4[] = {"ab", "c"};
  vector<string> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  static const string arr5[] = {"??", "a?"};
  vector<string> test5(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]));
  result = dummy.expectedPalindromes(test4, test5);
  if (result == 7.315088757396449) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %f, outputted %f\n", 7.315088757396449, result);
  }

  static const string arr6[] = {};
  vector<string> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  static const string arr7[] = {"?"};
  vector<string> test7(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]));
  result = dummy.expectedPalindromes(test6, test7);
  if (result == 1.0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %f, outputted %f\n", 1.0, result);
  }

  static const string arr8[] = {"ab?def", "?"};
  vector<string> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  static const string arr9[] = {"f??a"};
  vector<string> test9(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]));
  result = dummy.expectedPalindromes(test8, test9);
  if (result == 12.545971779699588) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %f, outputted %f\n", 12.545971779699588, result);
  }


}
