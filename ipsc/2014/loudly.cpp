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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

string FILENAME = "s2";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int score_word(string word, bool asterisk) {
  int score = 2;
  for (int i = 0; i < word.size(); i++) {
    if (!isupper(word[i])) {
      score = 1;
      break;
    }
  }
  if (asterisk) {
    score *= 3;
  }
  return score;
}

bool is_word(string word) {
  if (word.size() == 0) {
    return false;
  }
  for (int i = 0; i < word.size(); i++) {
    if (!isalpha(word[i])) {
      return false;
    }
  }
  return true;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  string delims = ",.:;'\"!?- \n";
  for (int case_id = 1; case_id <= testcases; case_id++) {
    int n;
    scanf("%d", &n);
    float best = 0;
    int best_i = 0;
    bool asterisk = false;
    string a;
    getline(cin, a);
    for (int word = 0; word < n; word++) {
      string s;
      getline(cin, s);
      int word_count = 0;
      int score = 0;
      string current_word = "";
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
          if (!asterisk) {
            asterisk = true;
          } else {
            if (is_word(current_word)) {
              score += score_word(current_word, asterisk);
              current_word = "";
              word_count++;
            }
            asterisk = false;
          }
        } else if (delims.find(s[i]) != string::npos) {
          if (is_word(current_word)) {
            score += score_word(current_word, asterisk);
            current_word = "";
            word_count++;
          }
        } else {
          current_word += s[i];
        }
      }
      float average = (float) score / word_count;
      if (average > best) {
        best = average;
        best_i = word + 1;
      }
    }
    printf("%d\n", best_i);
  }
  fflush(stdout);
}
