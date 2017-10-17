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

int bestRectangle(vector<string> board, char tile) {
}

class ApplesAndPears {
  public: int getArea(vector<string> board, int K);
};

int ApplesAndPears::getArea(vector<string> board, int K) {
  char tiles[3] = {'A', 'P', '.'};
  int best = 0;
  for (int i = 0; i < 3; i++) {
    char corner_tile = tiles[i];
  }
  return 0;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {".A","P."}, 0 }, {1} },
    { { {".A","P."}, 1 }, {2} },
    { { {".PP","PPA","PAP"}, 3 }, {6} },
    { { {"A.P.PAAPPA","PPP..P.PPP","AAP.A.PAPA","P.PA.AAA.A","...PA.P.PA","P..A.A.P..","PAAP..A.A.","PAAPPA.APA",".P.AP.P.AA","..APAPAA.."}, 10 }, {21} },
    // Your custom test goes here:
    //{ { {}, }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<string> p0;int p1;

        int run(ApplesAndPears* x) {
            return x->getArea(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<ApplesAndPears>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1401931670, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
