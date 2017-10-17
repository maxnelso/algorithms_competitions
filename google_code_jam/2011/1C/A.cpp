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

string FILENAME = "A-large-practice";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int main () {
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    int r, c;
    scanf("%d %d", &r, &c);
    vector<char> rows(c);
    vector<vector<char> > matrix(r, rows);
    for (int i = 0; i < r; ++i) {
      char c[256];
      scanf("%s", c);
      string s(c);
      for (int j = 0; j < s.size(); ++j) {
        matrix[i][j] = s[j];
      }
    }
    bool impossible = false;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (matrix[i][j] == '#') {
          matrix[i][j] = '/';
          if (i < r - 1 && matrix[i+1][j] == '#') {
            matrix[i+1][j] = '\\';
          } else {
            impossible = true;
            break;
          }
          if (j < c - 1 && matrix[i][j+1] == '#') {
            matrix[i][j+1] = '\\';
          } else {
            impossible = true;
            break;
          }
          if (i < r - 1 && j < c - 1 && matrix[i+1][j+1] == '#') {
            matrix[i+1][j+1] = '/';
          } else {
            impossible = true;
            break;
          }
        }
      }
      if (impossible) {
        break;
      }
    }
    printf("Case #%d:\n", case_id);
    if (impossible) {
      printf("Impossible\n", case_id);
    } else {
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          printf("%c", matrix[i][j]);
        }
        printf("\n");
      }
    }
  }
  fflush(stdout);
}
