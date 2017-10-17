/*
 ID: maxnelso1
 LANG: C++
 PROG: transform
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

#define ASSERT(x) {if (!(x)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

vector<string> rotate_90(vector<string> m) {
  vector<string> out(m[0].size());
  for (int i = 0; i < m[0].size(); i++) {
    out.push_back(string(m[0].size(), 0));
  }
  for (int i = 0; i < m[0].size(); i++) {
    string s;
    for (int j = 0; j < m[i].size(); j++) {
      s = s + m[m[0].size() - j - 1][i];
    }
    out[i] = s;
  }
  return out;
}

vector<string> reflect(vector<string> m) {
  vector<string> out(m[0].size());
  for (int i = 0; i < m[0].size(); i++) {
    out.push_back(string(m[0].size(), 0));
  }
  for (int i = 0; i < m[0].size(); i++) {
    string s;
    for (int j = 0; j < m[i].size(); j++) {
      s = s + m[i][m[0].size()-j-1];
    }
    out[i] = s;
  }
  return out;
}

int same_matrices(vector<string> m1, vector<string> m2) {
  for (int i = 0; i < m1.size(); i++) {
    for (int j = 0; j < m1.size(); j++) {
      if (m1[i][j] != m2[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  setbuf(stdout, NULL);
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);
  int size;
  scanf("%d", &size);
  vector<string> original;
  vector<string> transformed;
  for (int i = 0; i < size; i++) {
    char row[10];
    scanf("%s", row);
    original.push_back(string(row));
  }
  for (int i = 0; i < size; i++) {
    char row[10];
    scanf("%s", row);
    transformed.push_back(string(row));
  }
  if (same_matrices(transformed, rotate_90(original))) {
    printf("1\n");
    return(0);
  }
  if (same_matrices(transformed, rotate_90(rotate_90(original)))) {
    printf("2\n");
    return(0);
  }
  if (same_matrices(transformed, rotate_90(rotate_90(rotate_90(original))))) {
    printf("3\n");
    return(0);
  }
  if (same_matrices(transformed, reflect(original))) {
    printf("4\n");
    return(0);
  }
  if (same_matrices(transformed, rotate_90(reflect(original))) ||
     (same_matrices(transformed, rotate_90(rotate_90(reflect(original))))) ||
     (same_matrices(transformed, rotate_90(rotate_90(rotate_90(reflect(original))))))) {
    printf("5\n");
    return(0);
  }
  if (same_matrices(transformed, original)) {
    printf("6\n");
    return(0);
  }
  printf("7\n");
  return(0);

}
