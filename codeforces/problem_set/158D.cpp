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
  vector<int> sculptures;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    sculptures.push_back(a);
  }
  float interior_angle = (n-2)*180.0 / n;
  int result = accumulate(sculptures.begin(), sculptures.end(), 0);
  if (sculptures.size() > 4) {
    for (int i = 2; i <= n / 3; ++i) {
      if ((n % i) == 0 ) {
        int number_of_sides = n / i;
        int diff = n / number_of_sides;
        for (int j = 0; j < diff; ++j) {
          int sum = 0;
          for (int k = 0; k < n; k = k + diff) {
            sum += sculptures[k+j];
          }
          result = max(sum, result);
        }
      }
    }
  }
  printf("%d", result);

}
