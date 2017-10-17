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

struct Equation {
  string variable;
  string a;
  string b;
  string operand;
};

set_value 
map<string, Equation> equations;
map<string, int> known;

bitset get_value(string s) {
  if (known.find(s) != known.end()) {
    return known[s];
  }
  bitset a_value = get_value(equations[s].a);
  int b_value = get_value(equations[s].b);
  int value;
  if (equations[s].operand == "XOR") {
    value = a_value ^ b_value;
  } else if (equations[s].operand == "OR") {
    value = a_value | b_value;
  } else if (equations[s].operand == "AND") {
    value = a_value & b_value;
  } else {
    value = equations[s].a;
  }
  known[s] = value;
}

int process_string(string s) {
  known.clear();
}

int main () {
}
