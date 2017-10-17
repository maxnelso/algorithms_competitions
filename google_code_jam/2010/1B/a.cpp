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
using namespace std;

string FILENAME = "A-sample";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

struct Tree {
  vector<Tree*> children;
  string name;
};

vector<Tree*> roots;

pair<Tree*, bool> helper(string s, Tree* root) {
  pair<Tree*, bool> ret;
  for (int i = 0; i < root->children.size(); i++) {
    if (root->children[i]->name == s) {
      ret = make_pair(root->children[i], false);
      return ret;
    }
  }
  Tree* dir = new Tree();
  dir->name = s;
  root->children.push_back(dir);
  return make_pair(dir, true);
}

int add_directory(string s) {
  size_t pos = 0;
  string token;
  s = s.substr(1);
  char delim = '/';
  vector<string> dirs;
  while ((pos = s.find(delim)) != string::npos) {
    token = s.substr(0, pos);
    dirs.push_back(token);
    s.erase(0, pos + 1);
  }
  dirs.push_back(s);
  int count = 0;
  Tree* added;
  pair<Tree*, bool> r;
  for (int i = 0; i < dirs.size(); i++) {
    if (i == 0) {
      bool found = false;
      for (int j = 0; j < roots.size(); j++) {
        if (roots[i]->name == dirs[i]) {
          found = true;
          added = roots[i];
          break;
        }
      }
      if (!found) {
        added = new Tree();
        added->name = dirs[i];
        roots.push_back(added);
        count++;
      }
    } else {
      r = helper(dirs[i], added);
      if (r.second) {
        count++;
      }
      added = r.first;
    }
  }
  return count;
}



int main () {
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    printf("Case #%d: ", case_id);
    int n,m;
    scanf("%d %d", &n, &m);
    vector<string> builtin(n);
    for (int i = 0; i < n; i++) {
      char tmp[101];
      scanf("%s", tmp);
      string s(tmp);
      add_directory(s);
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
      char tmp[101];
      scanf("%s", tmp);
      string s(tmp);
      count += add_directory(s);
    }
    printf("%d\n", count);
    roots.clear();
  }
  fflush(stdout);
}
