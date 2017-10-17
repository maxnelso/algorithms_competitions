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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (j == a[0].size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

string FILENAME = "test";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    int n, d;
    scanf("%d %d", &n, &d);
    vector<int> nums;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      nums.push_back(a);
    }
    vector<vector<int> > counts(n, vector<int> (d+1));
    for (int i = 0; i < n - 1; i++) {
      counts[i][0] = 0;
    }
    counts[n-1][0] = 1; // start with just the first array
    for (int i = 1; i <= d; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k <= j; k++) {
          counts[k][i] += counts[j][i-1];
        }
      }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) { //size
      for (int j = 0; j < n - i + 1; j++) { //start
        vector<int>::const_iterator first = nums.begin() + j;
        vector<int>::const_iterator last = nums.begin() + j + i;
        vector<int> vec(first, last);
        sum += counts[i-1][d]* accumulate(vec.begin(), vec.end(), 0) % 1000000009;
      }
    }
    printf("%d\n", sum);
  }
  fflush(stdout);
}
