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
  string names[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  n--;
  int start = 0;
  int power = 0;
  while (start <= n) {
    start = start + 5 * (pow(2, power));
    power++;
  }
  power--;
  start = start - 5 * (pow(2, power));
  int index = -1;
  while (start <= n) {
    index++;
    start += pow(2, power);
  }
  printf("%s", names[index].c_str());
  fflush(stdout);
}
