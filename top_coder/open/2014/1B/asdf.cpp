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

class WolvesAndSheep {
  public: int getmin(vector <string> field);
};

int WolvesAndSheep::getmin(vector <string> field) {
  bool rows[20];
  memset(rows, false, sizeof(rows));
  bool cols[20];
  memset(cols, false, sizeof(cols));
  int result = 0;
  for (int j = 0; j < field[0].size(); ++j) { // cols
    int min_index = 10000;
    for (int i = 0; i < field.size(); ++i) { // rows
      if (field[i][j] == 'W') {
        char prev = '.';
        char next = '.';
        int next_index = 0;
        int prev_index = 0;
        for (int k = 0; k < field.size(); ++k) {
          if (k < i) {
            prev = field[k][j];
            prev_index = k;
          } else if (k > i) {
            if (field[k][j] != '.') {
              next = field[k][j];
              next_index = k;
              break;
            }
          }
        }
        if (prev == 'S') {
          bool found = false;
          for (int k = j; k >= prev_index; --k) {
            if (rows[k]) {
              found = true;
              break;
            }
          }
          if (!found) {
            rows[prev_index] = true;
            printf("%d %d\n", i, j);
            result++;
          }
        }
        if (next == 'S') {
          bool found = false;
          for (int k = j; k <= next_index; ++k) {
            if (rows[k]) {
              found = true;
              break;
            }
          }
          if (!found) {
            rows[next_index] = true;
            printf("%d %d %d??\n", i, j, next_index);
            result++;
          }
        }
      }
    }
  }
  /*
  for (int i = 0; i < field.size(); ++i) { // rows
    for (int j = 0; j < field[0].size(); ++j) { // cols
      if (field[i][j] == 'W') {
        char prev = '.';
        char next = '.';
        for (int k = 0; k < field[0].size(); ++k) {
          if (k < j) {
            prev = field[i][k];
          } else if (k > j) {
            if (field[i][k] != '.') {
              next = field[i][k];
              break;
            }
          }
        }
        if (prev == 'S') {
          result++;
        }
        if (next == 'S') {
          result++;
        }
      }
    }
  }
  */
  return result;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);  WolvesAndSheep dummy;
  int result;

  static const string arr0[] = {"W.WSS",  "WW.S.",  ".SSS.",  "SSS.S",  ".SS.S"};
  vector<string> test0(arr0, arr0 + sizeof(arr0) / sizeof(arr0[0]));
  result = dummy.getmin(test0);
  if (result == 2) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 2, result);
  }

  static const string arr1[] = {".....",  ".....",  "....."};
  vector<string> test1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
  result = dummy.getmin(test1);
  if (result == 0) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 0, result);
  }

  static const string arr2[] = {".SS",  "...",  "S..",  "W.W"};
  vector<string> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
  result = dummy.getmin(test2);
  if (result == 1) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 1, result);
  }

  static const string arr3[] = {"WWWSWWSSWWW",  "WWSWW.SSWWW",  "WS.WSWWWWS."};
  vector<string> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
  result = dummy.getmin(test3);
  if (result == 10) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 10, result);
  }

  static const string arr4[] = {".W.S.W.W",  "W.W.S.W.",  ".S.S.W.W",  "S.S.S.W.",  ".S.W.W.S",  "S.S.W.W.",  ".W.W.W.S",  "W.W.S.S."};
  vector<string> test4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
  result = dummy.getmin(test4);
  if (result == 7) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 7, result);
  }

  static const string arr5[] = {"W.SSWWSSSW.SS",  ".SSSSW.SSWWWW",  ".WWWWS.WSSWWS",  "SS.WSS..W.WWS",  "WSSS.SSWS.W.S",  "WSS.WS...WWWS",  "S.WW.S.SWWWSW",  "WSSSS.SSW...S",  "S.WWSW.WWSWSW",  ".WSSS.WWSWWWS",  "..SSSS.WWWSSS",  "SSWSWWS.W.SSW",  "S.WSWS..WSSS.",  "WS....W..WSS."};
  vector<string> test5(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]));
  result = dummy.getmin(test5);
  if (result == 24) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 24, result);
  }

  static const string arr6[] = {"WW..SS",  "WW..SS",  "......",  "......",  "SS..WW",  "SS..WW"};
  vector<string> test6(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]));
  result = dummy.getmin(test6);
  if (result == 2) {
    printf("\033[1;32mPASSED\033[0m\n");
  } else {
    printf("\033[1;31mFAILED\033[0m: Expected value was %d, outputted %d\n", 2, result);
  }


}
