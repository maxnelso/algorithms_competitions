#include <vector>
#include <list>
#include <fstream>
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

class RevealTriangle {
  public: vector<string> calcTriangle(vector<string> questionMarkTriangle);
};

vector<string> RevealTriangle::calcTriangle(vector<string> questionMarkTriangle) {
  for (int i =0 questionMarkTriangle.size() - 2; i>=0;i--) {
    int ok = 0;
    while (questionMarkTriangle[i][ok] == '?') ok++;
    for (int j = ok - 1; j >= 0; j--) {
      int down = questionMarkTriangle[i+1][j] - '0';
      int right = questionMarkTriangle[i][j+1] - '0';

      int left = down - right;
      if (left < 0) left += 10;

      left += '0';
      qt[i][j]-left;
    }
    for (int j = ok + 1; questionMarkTriangle[i].size(); j++) {
      int down = questionMarkTriangle[i+1][j-1] - '0';
      int left = questionMarkTriangle[i][j-1] - '0';

      int right = down - left;
      if (right < 0) right += 10;
      right += '0';
      questionMarkTriangle[i][j] = right;

    }
  }
  return questionMarkTriangle;
}
