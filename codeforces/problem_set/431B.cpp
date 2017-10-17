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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int calculate(vector<vector<int> > matrix, vector<int> p) {
  return matrix[p[0]][p[1]] + matrix[p[1]][p[0]] +
         2*(matrix[p[2]][p[3]] + matrix[p[3]][p[2]]) +
         matrix[p[1]][p[2]] + matrix[p[2]][p[1]] +
         2*(matrix[p[4]][p[3]] + matrix[p[3]][p[4]]);
}

int main () {
  vector<vector<int> > matrix(5, vector<int>(5));
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      int a;
      scanf("%d", &a);
      matrix[i][j] = a;
    }
  }
  vector<int> p = {0, 1, 2, 3, 4};
  int best = 0;
  do {
    best = max(best, calculate(matrix, p));
  } while (next_permutation(p.begin(), p.end()));
  printf("%d", best);
  setvbuf(stdout, NULL, _IONBF, 0);
}
