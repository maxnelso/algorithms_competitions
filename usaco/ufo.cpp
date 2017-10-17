/*
 ID: maxnelso1
 PROG: ride
 LANG: C++
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
char buf1[100000];
char buf2[100000];

int main(int argc, char* argv[]) {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string comet;
    string group;
    scanf("%s\n%s", buf1, buf2);
    comet = buf1;
    group = buf2;
    int comet_count = 1;
    int group_count = 1;
    for (int i = 0; i < comet.size(); i++) {
      comet_count *= (comet[i] - 'A' + 1);
      comet_count %= 47;
    }
    for (int i = 0; i < group.size(); i++) {
      group_count *= (group[i] - 'A' + 1) % 47;
      group_count %= 47;
    }
    comet_count == group_count ? printf("GO\n") : printf("STAY\n");
    return(0);

}
