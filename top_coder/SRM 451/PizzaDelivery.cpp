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

class PizzaDelivery {
  public: int deliverAll(vector<string> terrain);
};

int PizzaDelivery::deliverAll(vector<string> terrain) {
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
    { { {"3442211","34$221X","3442211"} }, {8} },
    { { {"001000$","$010X0$","0010000"} }, {13} },
    { { {"001000$","$010X0$","0010000","2232222","2222222","111$111"} }, {-1} },
    { { {"001000$","$010X0$","0010000","1232222","2222222","111$111"} }, {28} },
    { { {"X$$","$$$"} }, {14} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<string> p0;

        int run(PizzaDelivery* x) {
            return x->deliverAll(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<PizzaDelivery>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            1000, 1403665595, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
