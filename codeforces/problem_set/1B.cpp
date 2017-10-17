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
#define print_vector(a) for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}}
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (i == a.size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  for (int j = 0; j < n; ++j) {
    char c[256];
    scanf("%s", c);
    string s(c);
    bool first = false;
    bool could_be = false;
    bool seen_c = false;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'C') {
        seen_c = true;
      }
      if (i == 0 && s[0] == 'R') {
        could_be = true;
        if (!isdigit(s[i+1])) {
          first = true;
          break;
        }
      } else if (could_be && !isdigit(s[i])) {
        if (s[i] != 'C') {
          first = true;
          break;
        }
      }
    }
    if (!seen_c) {
      first = true;
    }
    if (!could_be) {
      first = true;
    }
    if (first) {
      int sum = 0;
      string d = "";
      int first = -1;
      for (int i = s.size() - 1; i >= 0; --i) {
        if (isalpha(s[i]) && first == -1) {
          first = i;
          sum = s[i] - 'A' + 1;
        } else if (isalpha(s[i])) {
          sum += pow(26, (first - i)) * (s[i] - 'A' + 1);
        } else {
          d = s[i] + d;
        }
      }
      istringstream ss(d);
      int value;
      ss >> value;
      printf("R%dC%d\n", value, sum);
    } else {
      string row = "";
      string col = "";
      bool in_row = false;
      bool in_col = false;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') {
          in_row = true;
        } else if (s[i] == 'C') {
          in_row = false;
          in_col = true;
        } else if (in_row) {
          row = row + s[i];
        } else {
          col = col + s[i];
        }
      }
      istringstream ss(col);
      int value;
      ss >> value;
      string answer = "";
      while (value / 26 != 0) {
        int rem = value % 26;
        char f;
        if (rem == 0) {
          value--;
          f = 'Z';
        } else {
          f = ('A' - 1 + rem);
        }
        answer = f + answer;
        value = value / 26;
      }
      int rem = value % 26;
      if (rem != 0) {
        char f = ('A' - 1 + rem);
        answer = f + answer;
      }
      printf("%s%s\n", answer.c_str(), row.c_str());
    }
  }

}
