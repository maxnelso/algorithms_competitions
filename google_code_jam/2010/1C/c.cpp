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

string FILENAME = "C-sample";

int main () {
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    printf("Case #%d: ", case_id);
    int m, n;
    scanf("%d %d", &m, &n);
    int larg[512][512];
    int board[512][512];
    for (int i = 0; i < m; i++) {
      larg[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
      larg[0][j] = 1;
    }
    for(int i=0; i<m; ++i){
      char s[500];
      scanf("%s", s);
      string row(s);
      int next=0;
      for(int j=0; j<n/4; ++j){
        char c=s[j];
        if(isdigit(c))
          c-='0';
        else
          c=c-'A'+10;
        for(int k=3; k>=0; --k){
          board[i][next++]=((c>>k) & 1);
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i - 1][j] != board[i][j] &&
            board[i][j - 1] != board[i][j] &&
            board[i - 1][j - 1] == board[i][j]) {
          larg[i][j] = 1 + min(larg[i - 1][j],
                               larg[i][j - 1],
                               larg[i - 1][j - 1]);
        }
      }
    }
  }
  fflush(stdout);
}
