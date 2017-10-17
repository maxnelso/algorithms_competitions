#include <bitset>
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
  vector<string> names;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char c[256];
    scanf("%s", c);
    string s(c);
    char d[256];
    scanf("%s", d);
    string t(d);
    string z = s + ' ';
    z += t;
    names.push_back(z);
  }
  vector<int> permutation;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    permutation.push_back(a);
  }
  vector<string> handles;
  bool good = true;
  for (int i = 0; i < permutation.size(); ++i) {
    int index = permutation[i] - 1;
    if (i == 0) {
      istringstream iss(names[index]);
      vector<string> split;
      do {
        string sub;
        iss >> sub;
        split.push_back(sub);
      } while (iss);
      if (split[0].compare(split[1]) < 0) {
        handles.push_back(split[0]);
      } else {
        handles.push_back(split[1]);
      }
    } else {
      string best;
      istringstream iss(names[index]);
      vector<string> split;
      do {
        string sub;
        iss >> sub;
        split.push_back(sub);
      } while (iss);
      if (split[0].compare(split[1]) < 0) {
        if (split[0].compare(handles[i-1]) > 0) {
          best = split[0];
        } else {
          best = split[1];
        }
      } else {
        if (split[1].compare(handles[i-1]) > 0) {
          best = split[1];
        } else {
          best = split[0];
        }
      }
      if (best.compare(handles[i-1]) <= 0) {
        printf("NO");
        good = false;
        break;
      } else {
        handles.push_back(best);
      }
    }
  }
  if (good) {
    printf("YES");
  }
}
