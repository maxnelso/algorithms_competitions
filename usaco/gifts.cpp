/*
 ID: maxnelso1
 LANG: C++
 PROG: gift1
*/
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
using namespace std;

#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

int main(int argc, char* argv[]) {
    setbuf(stdout, NULL);
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int np;
    map<string, int> amounts;
    vector<string> names;
    scanf("%d", &np);
    for (int case_id = 0; case_id < np; case_id++) {
      char name[15];
      scanf("%s", name);
      amounts.insert(pair<string,int>(string(name), 0));
      names.push_back(string(name));
    }
    for (int i = 0; i < names.size(); i++) {
      char giver_array[15];
      scanf("%s", giver_array);
      string giver(giver_array);
      int gift_amount, num_names;
      scanf("%d %d", &gift_amount, &num_names);
      if (num_names !=0) {
        gift_amount /= num_names;
        amounts[giver] -= gift_amount * num_names;
      }
      for (int j = 0; j < num_names; j++) {
        char name[15];
        scanf("%s", name);
        string str_name(name);
        amounts[str_name] += gift_amount;
      }
    }
    for (vector<string>::iterator it= names.begin(); it != names.end(); it++) {
      printf("%s %d\n", it->c_str(), amounts[*it]);
    }
    return(0);
}
