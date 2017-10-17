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

template <typename T>
string join(const T& v, const string& delim) {
  ostringstream s;
  for (const auto& i : v) {
    if (&i != &v[0]) {
      s << delim;
    }
    s << i;
  }
  return s.str();
}

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
  int n;
  scanf("%d", &n);
  string dir = "/";
  for (int i = 0; i < n; ++i) {
    char c[256];
    scanf("%s", c);
    string s(c);
    if (s == "pwd") {
      printf("%s\n", dir.c_str());
    } else {
      if (s == "cd") {
        char d[256];
        scanf("%s", d);
        string new_d(d);
        if (new_d[0] == '/') { //absolute
          vector<string> spl = split(new_d, '/');
          vector<string> original;
          for (int j = 0; j < spl.size(); ++j) {
            if (spl[j] == "..") {
              original.pop_back();
            } else {
              original.push_back(spl[j]);
            }
          }
          dir = join(original, string("/"));
          dir = dir + "/";
        } else { //relative
          vector<string> spl = split(new_d, '/');
          vector<string> original = split(dir, '/');
          for (int j = 0; j < spl.size(); ++j) {
            if (spl[j] == "..") {
              original.pop_back();
            } else {
              original.push_back(spl[j]);
            }
          }
          dir = join(original, string("/"));
          dir = dir + "/";
        }
      }
    }
  }
  fflush(stdout);
}
