#include <bitset>
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
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    vector<int> p;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        p.push_back(a);
    }
    int one_count = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        one_count += a;
    }
    int out = one_count % 2 == 0;
    set<int> set_p(p.begin(), p.end());
    vector<set<int>> connected;
    while (!set_p.empty()) {
        auto it = set_p.begin();
        set<int> seen;
        seen.insert(*it);
        int next_num = p[*it - 1];
        set_p.erase(set_p.find(*it));
        while (seen.find(next_num) == seen.end()) {
            set_p.erase(set_p.find(next_num));
            seen.insert(next_num);
            next_num = p[next_num - 1];
        }
        connected.push_back(seen);
    }
    if (connected.size() > 1) {
      out += connected.size();
    }
    printf("%d", out);
}
