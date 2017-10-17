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
#include <unordered_set>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

const int ALPHA = 30;
bool good[ALPHA];

struct node {
  node* child[ALPHA];
  node() {
    for (int i = 0; i < ALPHA; i++) {
      child[i] = NULL;
    }
  }

  int cnt() {
    int ans = 1;
    for (int i = 0; i < ALPHA; i++) {
      if (child[i] != NULL) {
        ans += child[i]->cnt();
      }
    }
    return ans;
  }
};

int main () {
  string s, alphabet;

  cin >> s >> alphabet;
  for (int i = 0; i < alphabet.size(); i++) {
    good[i] = alphabet[i] == '1';
  }

  int k;
  scanf("%d", &k);

  node* root = new node();
  for (int i = 0; i < s.size(); i++) {
    int bad = 0;
    node* current = root;
    for (int j = i; j < s.size(); j++) {
      if (!good[s[j] - 'a']) {
        bad++;
      }

      if (bad > k) {
        break;
      }

      int c = s[j] - 'a';
      if ((current->child)[c] == NULL) {
        (current->child)[c] = new node();
      }
      current = (current->child)[c];
    }
  }

  cout << (root->cnt()) - 1 << endl;
}
