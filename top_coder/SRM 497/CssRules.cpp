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
#define print_vector(a) cout << "{"; for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << ",";}} cout << "}n";
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (j == a[0].size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

class CssRules {
  public: int getMinimalCssRuleCount(vector<string> xthml);
};

int CssRules::getMinimalCssRuleCount(vector<string> xthml) {
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
    { { {"<b id='x' style='color:red'></b>"} }, {1} },
    { { {"<b id='x' style='color:red'>","<b id='y' style='color:red'>","<b id='z' style='color:red'>","</b></b></b>"} }, {2} },
    { { {"<b id='x' style='color:red'>","<b id='y' style='color:red'>","<b id='w' style='color:red'>","</b>","</b>","<u id='z' style='color:red'>","</u>","</b>"} }, {3} },
    { { {"<b id='x' style='color:red'>","<i id='y' style='color:black'>","<u id='w' style='color:white'>","</u>","</i>","<u id='z' style='color:yellow'>","</u>","</b>"} }, {4} },
    { { {"<b id='x' style='col","or:red'></b>","<b id=","'xx' style='color",":red'></b>"} }, {2} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<string> p0;

        int run(CssRules* x) {
            return x->getMinimalCssRuleCount(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<CssRules>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            550, 1399700003, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
