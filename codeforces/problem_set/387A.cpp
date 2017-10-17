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

vector<string> &split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}
vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  char c[256];
  scanf("%s", c);
  string s(c);
  char d[256];
  scanf("%s", d);
  string t(d);
  vector<string> s_time = split(s, ':');
  vector<string> t_time = split(t, ':');
  int s_hour = atoi(s_time[0].c_str());
  int s_minute = atoi(s_time[1].c_str());
  int t_hour = atoi(t_time[0].c_str());
  int t_minute = atoi(t_time[1].c_str());
  while (t_hour > 0 || t_minute > 0) {
    t_minute--;
    s_minute--;
    if (t_minute == -1) {
      t_hour--;
      t_minute = 59;
    }
    if (s_minute == -1) {
      s_hour = ((s_hour - 1) + 24) % 24;
      s_minute = 59;
    }
  }
  if (s_hour < 10) {
    printf("0%d", s_hour);
  } else {
    printf("%d", s_hour);
  }
  printf(":");
  if (s_minute < 10) {
    printf("0%d", s_minute);
  } else {
    printf("%d", s_minute);
  }

}
