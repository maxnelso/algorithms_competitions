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

class WordAbbreviation {
  public: vector<string> getAbbreviations(vector<string> words);
};

vector<string> WordAbbreviation::getAbbreviations(vector<string> words) {
  vector<string> out;
  for (int i = 0; i < words.size(); ++i) {
    for (int j = 1; j <= words[i].size(); j++) {
      bool good = true;
      for (int k = 0; k < words.size(); k++) {
        if (k != i) {
          string sub(words[i].begin(), words[i].begin() + j);
          if (sub.size() <= words[k].size() && words[k].find(sub) == 0) {
            printf("%s is a substring of %s\n", sub.c_str(), words[k].c_str());
            good = false;
            break;
          }
        }
      }
      if (good) {
        out.push_back(string(words[i].begin(), words[i].begin() + j));
        break;
      }
    }
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
    { { {"abc","def","ghi"} }, { {"a","d","g"} } },
    { { {"aaab","aaac","aaad"} }, { {"aaab","aaac","aaad"} } },
    { { {"top","coder","contest"} }, { {"t","cod","con"} } },
    { { {"bababaaaaa","baaabaababa","bbabaaabbaaabbabaabaabbbbbaabb","aaababababbbbababbbaabaaaaaaaabbabbbaaab","baaaaabaababbbaabbbabbababbbabbbbbbbbab"} }, { {"bab","baaab","bb","a","baaaa"} } },
    { { {"oneword"} }, { {"o"} } },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<string> p0;

        vector<string> run(WordAbbreviation* x) {
            return x->getAbbreviations(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<WordAbbreviation>(
            getTestCases<input, Tester::output<vector<string>>>(), disabledTest, 
            250, 1406601049, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
