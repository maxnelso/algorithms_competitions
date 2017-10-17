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

class TypoCoderDiv1 {
  public: int getmax(vector <int> D, int X);
};

int TypoCoderDiv1::getmax(vector <int> D, int X) {
    const int BROWN = 2200;
    int f[D.size() + 1][BROWN];
    memset(f, 0, sizeof(f));
    for (int i = D.size(); i >= 0; i--) {
        for (int x = 0; x < BROWN; x++) {
            if (i == D.size()) {
                //base 
                f[i][x] = 0;
            } else {
                // { x < 2200 }
                // up:
                if (x + D[i] >= BROWN) {
                    if (i + 1 < D.size()) {
                        // become brown, must be "ciel" after the next match
                        if (x + D[i] - D[i+1] < BROWN) {
                            // can do it
                            f[i][x] = 2 + f[i + 2][std::max(0, x + D[i] - D[i+1]) ];
                        }
                    } else {
                        // one final rating change:
                        f[i][x] = 1;
                    }
                } else {
                    f[i][x] = f[i + 1][x + D[i]];
                }
                // down:
                f[i][x] = std::max(f[i][x], f[i + 1][ max(0, x - D[i]) ] );
            }
        }
    };
    cout << f[0][X] << endl;
    return f[0][X];
}

int main () {
  TypoCoderDiv1 dummy;
  int result;

  static const int arr0[] = {100,200,100,1,1};
  vector<int> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  int test1 = 2000;
  result = dummy.getmax(test0, test1);
  if (result == 3) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 3, result);
  }

  static const int arr2[] = {0,0,0,0,0};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  int test3 = 2199;
  result = dummy.getmax(test2, test3);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }

  static const int arr4[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
  vector<int> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  int test5 = 0;
  result = dummy.getmax(test4, test5);
  if (result == 1) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 1, result);
  }

  static const int arr6[] = {1000000000,1000000000,10000,100000,2202,1};
  vector<int> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  int test7 = 1000;
  result = dummy.getmax(test6, test7);
  if (result == 4) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 4, result);
  }

  static const int arr8[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
  vector<int> test8(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]));
  int test9 = 2199;
  result = dummy.getmax(test8, test9);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }

  static const int arr10[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
  vector<int> test10(arr10, arr10 + sizeof(arr10) / sizeof(arr10[0]));
  int test11 = 1223;
  result = dummy.getmax(test10, test11);
  if (result == 29) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 29, result);
  }

  static const int arr12[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
  vector<int> test12(arr12, arr12 + sizeof(arr12) / sizeof(arr12[0]));
  int test13 = 1328;
  result = dummy.getmax(test12, test13);
  if (result == 20) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 20, result);
  }


}
