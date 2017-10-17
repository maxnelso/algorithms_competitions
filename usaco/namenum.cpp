/*
 ID: maxnelso1
 LANG: C++
 PROG: namenum
*/
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
using namespace std;

#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

map<string, bool> dictionary;
map<int, string> phone;
bool found = false;


void helper(string number, int current_digit, string result) {
  if (current_digit == number.size()) {
    if (dictionary.find(string(result)) == dictionary.end()) {
      return;
    }
    found = true;
    printf("%s\n", result.c_str());
    return;
  }
  for (int i = 0; i < 3; ++i) {
    int digit = number[current_digit] - '0';
    result[current_digit] = phone[digit][i];
    helper(number, current_digit + 1, result);
  }
}

int main(int argc, char* argv[]) {
  setbuf(stdout, NULL);
  phone[2] = "ABC";
  phone[3] = "DEF";
  phone[4] = "GHI";
  phone[5] = "JKL";
  phone[6] = "MNO";
  phone[7] = "PRS";
  phone[8] = "TUV";
  phone[9] = "WXY";
  FILE* file = freopen("dict.txt", "r", stdin);
  string name;
  while (!feof(file)) {
    char new_name[100];
    scanf("%s", new_name);
    name = new_name;
    dictionary[name] = true;
  }
  freopen("namenum.in", "r", stdin);
  freopen("namenum.out", "w", stdout);
  char number[100];
  scanf("%s", number);
  string num(number);
  string result(num.size(), 'a');
  helper(num, 0, result);
  if (!found) {
    printf("NONE\n");
  }
  return(0);

}
