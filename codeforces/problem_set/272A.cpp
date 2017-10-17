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
  vector<int> nums;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  int start = -1;
  for (int i = 0; i < n; ++i) {
    start = (start + nums[i]) % (n + 1);
  }
  int result = 0;
  for (int i = 1; i <= 5; ++i) {
    int other = (start + i) % (n + 1);
    if (other != 0) {
      result++;
    }
  }
  printf("%d", result);
}
