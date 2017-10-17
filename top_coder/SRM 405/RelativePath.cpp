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

class RelativePath {
  public: string makeRelative(string path, string currentDir);
};

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
string RelativePath::makeRelative(string path, string currentDir) {
  vector<string> path_list = split(path, '/');
  vector<string> current_dir_list = split(currentDir, '/');
  int start_index = -1;
  for (int i = 0; i < min(current_dir_list.size(), path_list.size()); ++i) {
    if (current_dir_list[i] != path_list[i]) {
      start_index = i;
      break;
    }
  }
  string out = "";
  if (start_index == -1) {
    if (current_dir_list.size() > path_list.size()) {
      return "Shouldn't happen";
    } else if (current_dir_list.size() < path_list.size()) {
      for (int i = current_dir_list.size(); i < path_list.size(); ++i) {
        out += path_list[i] + "/";
      }
      out.pop_back();
    } else {
      return "";
    }
    return out;
  }
  for (int i = start_index; i < current_dir_list.size(); ++i) {
    out += "../";
  }
  for (int i = start_index; i < path_list.size(); ++i) {
    out += path_list[i] + "/";
  }
  out.pop_back();
  return out;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { "/home/top/data/file", "/home/user/pictures" }, {"../../top/data/file"} },
    { { "/home/user/movies/title", "/home/user/pictures" }, {"../movies/title"} },
    { { "/file", "/" }, {"file"} },
    { { "/file/file", "/" }, {"file/file"} },
    { { "/a/b/a/b/a/b", "/a/b/a/a/b/a/b" }, {"../../../../b/a/b"} },
    { { "/root/root/root", "/root" }, {"root/root"} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        string p0;string p1;

        string run(RelativePath* x) {
            return x->makeRelative(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<RelativePath>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            500, 1407086985, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
