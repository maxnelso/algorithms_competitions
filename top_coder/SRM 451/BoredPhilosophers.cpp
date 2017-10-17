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

class BoredPhilosophers {
  public: vector<int> simulate(vector<string> text, int N);
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

vector<int> BoredPhilosophers::simulate(vector<string> text, int N) {
  vector<int> out;
  string s;
  for (int i = 0; i < text.size(); ++i) {
    s += text[i];
  }
  vector<string> words = split(s, ' ');
  for (int i = 1; i <= N; i++) {
    map<vector<string>, bool> seen;
    for (int j = 0; j < words.size() - i + 1; j++) {
      vector<string> consecutive;
      for (int k = 0; k < i; k++) {
        consecutive.push_back(words[j+k]);
      }
      if (seen.find(consecutive) == seen.end()) {
        seen[consecutive] = true;
      }
    }
    out.push_back(seen.size());
  }
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
    { { {"hello world"}, 2 }, { {2,1} } },
    { { {"aaa bbb aaa bbb aaa aaa"}, 4 }, { {2,3,3,3} } },
    { { {"remember"," t","o concatenate ","the"," ","text"}, 1 }, { {5} } },
    { { {"a a a a a a a b a a b a a a b b a b a a a b a b"}, 6 }, { {2,4,7,11,14,17} } },
    { { {"aa ababaa c cbbcbc cabcbcb ba bccc ababb","c cabcba caa ababaa c cbbcbc cabcbcb ba ","bccc ababbc cabcba c bbcbab","b aaaa cbccaaa bccc ababbc cabcba c bbcb","ab cbcaca"}, 7 }, { {15,17,18,19,20,20,20} } },
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<string> p0;int p1;

        vector<int> run(BoredPhilosophers* x) {
            return x->simulate(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<BoredPhilosophers>(
            getTestCases<input, Tester::output<vector<int>>>(), disabledTest, 
            500, 1403664908, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
