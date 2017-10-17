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
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

struct variable {
  string name;
  string bit_string;
  string a;
  string b;
  string op;
  bool known;
  bool currently_known;
};

template<typename Out>
void split(const std::string &s, char delim, Out result) {
  std::stringstream ss;
  ss.str(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    *(result++) = item;
  }
}


std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  map<string, variable> variables;
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    vector<string> tokens = split(line, ' ');
    if (tokens.size() == 3) {
      variable v;
      v.currently_known = true;
      v.known = true;
      v.name = tokens[0];
      v.bit_string = tokens[2];
      variables[v.name] = v;
    } else {
      variable v;
      v.known = false;
      v.currently_known = false;
      v.name = tokens[0];
      v.a = tokens[2];
      v.op  = tokens[3];
      v.b = tokens[4];
      variables[v.name] = v;
    }
  }
  string min_s = "";
  string max_s = "";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      bool looking_for_min = false;
      char out = '0';
      if (j == 0) {
        looking_for_min = true;
        out = '1';
      }
      while (true) {
        bool flag = true;
        for (auto& p: variables) {
          variable& v = p.second;
          if (v.currently_known) {
            continue;
          }
          variable& a = variables[v.a];
          variable& b = variables[v.b];
          if (!a.currently_known || !b.currently_known) {
            flag = false;
            continue;
          }

        }
        if (flag) {
          break;
        }
      }
    }
  }
}
