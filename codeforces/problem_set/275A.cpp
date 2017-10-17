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
  int matrix[3][3];
  bool grid[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int a;
      scanf("%d", &a);
      matrix[i][j] = a;
      grid[i][j] = true;
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < matrix[i][j]; ++k) {
        grid[i][j] = !grid[i][j];
        if (i + 1 < 3) {
          grid[i+1][j] = !grid[i+1][j];
        }
        if (i - 1 >= 0) {
          grid[i-1][j] = !grid[i-1][j];
        }
        if (j + 1 < 3) {
          grid[i][j+1] = !grid[i][j+1];
        }
        if (j - 1 >= 0) {
          grid[i][j-1] = !grid[i][j-1];
        }
      }
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      printf("%d", grid[i][j]);
    }
    printf("\n");
  }
}
