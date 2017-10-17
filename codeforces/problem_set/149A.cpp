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
using namespace std;

int main () {
  int n;
  scanf("%d", &n);
  vector<int> months;
  for (int i = 0; i < 12; ++i) {
    int x;
    scanf("%d", &x);
    months.push_back(x);
  }
  sort(months.rbegin(), months.rend());
  int index = 0;
  int total = 0;
  while (total < n) {
    total += months[index++];
    if (index == 12 && total < n) {
      printf("-1");
      return 0;
    }
  }
  printf("%d", index);
  fflush(stdout);
}
