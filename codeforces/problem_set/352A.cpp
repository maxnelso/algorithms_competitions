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
  int n;
  scanf("%d", &n);
  int fives = 0;
  int zeroes = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a == 5) {
      fives++;
    } else {
      zeroes++;
    }
  }
  /*
  for (int i = 0; i <= fives; ++i) {
    for (int j = 0; j <= zeroes; ++j) {
      vector<int> nums;
      for (int k = 0; k < i; ++k) {
        nums.push_back(5);
      }
      for (int k = 0; k < j; ++k) {
        nums.push_back(0);
      }
      sort(nums.begin(), nums.end());
      do {
        
      } while (next_permutation(nums.begin(), nums.end()));
    }
  }
  */
  if (fives / 9 >= 1 && zeroes >= 1)  {
    for (int i = 0; i < fives / 9; ++i) {
      printf("555555555");
    }
    for (int i = 0; i < zeroes; ++i) {
      printf("0");
    }
  } else if (zeroes >= 1) {
    printf("0");
  } else {
    printf("-1");
  }
  setvbuf(stdout, NULL, _IONBF, 0);
}
