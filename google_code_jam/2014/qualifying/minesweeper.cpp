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
#define print_vector(a) cout << "{"; for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << ",";}} cout << "}\n";
using namespace std;

string FILENAME = "C-sample";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

vector<pair<int, int> > get_neighbors(vector<vector<int> > &matrix, int i, int j, int r, int c) {
  vector<pair<int, int> > neighbors;
  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      if (!(dy == 0 && dx == 0)) {
        int new_x = i + dx;
        int new_y = j + dy;
        printf("Attempting (%d, %d)\n", new_x, new_y);
        if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c && matrix[new_x][new_y] != -1) {
          neighbors.push_back(make_pair(new_x, new_y));
        }
      }
    }
  }
  return neighbors;
}

int get_num_neigbors(vector<vector<int> > &matrix, int i, int j, int r, int c) {
  int result = 0;
  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      if (dy != 0 and dx != 0) {
        int new_x = i + dx;
        int new_y = j + dy;
        if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c && matrix[new_x][new_y] == -1) {
          result++;
        }
      }
    }
  }
  return result;
}

int main () {
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    printf("Case #%d: ", case_id);
    int r, c, m;
    scanf("%d %d %d", &r, &c, &m);
    vector< vector<int> > matrix;
    for (int i = 0; i < r; ++i) {
      vector<int> new_row;
      for (int j = 0; j < c; ++j) {
        new_row.push_back(-2);
      }
      matrix.push_back(new_row);
    }
    int row = 0;
    int col = 0;
    bool bad = false;
    if (m > r*c) {
      printf("Impossible\n");
      continue;
    }
    if ((m % r ) == r - 1) { //bad
      if ((m % c) == c - 1) { // really bad!
        printf("REALLY BAD\n");
        while (m > 0) {
          matrix[row][col] = -1;
          m--;
          row++;
          if (row > r - 3) {
            row = 0;
            col++;
          }
          if (col > c - 3) {
            bad = true;
            printf("Impossible\n");
            break;
          }

        }
      } else { // do it column wise
        printf("doing it column wise");
        while (m > 0) {
          matrix[row][col] = -1;
          m--;
          col++;
          if (col > c - 1) {
            col = 0;
            row++;
          }
          if (row > r - 1) {
            bad = true;
            printf("Impossible\n");
            break;
          }
        }
      }
    } else {
      printf("doing it row wise");
      while (m > 0) {
        matrix[row][col] = -1;
        m--;
        row++;
        if (row > r - 1) {
          row = 0;
          col++;
        }
        if (col > c - 1) {
          bad = true;
          printf("Impossible\n");
          break;
        }
      }
    }
    printf("Before everything\n");
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (matrix[i][j] == -1) {
          printf("*");
        } else {
          printf(".");
        }
      }
      printf("\n");
    }
    if (!bad) {
      queue<pair<int, int> > q;
      vector<bool> seen(r*c);
      fill(seen.begin(), seen.end(), 0);
      pair<int, int> start = make_pair(r - 1, c - 1);
      q.push(start);
      int index = r * start.first + start.second;
      seen[index] = true;
      while (q.size() > 0) {
        pair<int, int> node = q.back();
        q.pop();
        int num_neighbors = get_num_neigbors(matrix, node.first, node.second, r, c);
        matrix[node.first][node.second] = num_neighbors;
        if (num_neighbors == 0) {
          vector<pair<int, int> > neighbors = get_neighbors(matrix, node.first, node.second, r, c);
          for (int i = 0; i < neighbors.size(); ++i) {
            pair<int, int> new_node = neighbors[i];
            int index = r * new_node.first + new_node.second;
            if (seen[index] == false) {
              seen[index] = true;
              printf("Adding (%d, %d)\n", new_node.first, new_node.second);
              q.push(new_node);
            }
          }
        }
      }
      bool found = false;
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (matrix[i][j] == -2) {
            printf("BAD at (%d, %d)", i, j);
            found = true;
            break;
          }
          printf("%d", matrix[i][j]);
        }
        printf("\n");
      }
      if (!false) {
        string out = "";
        for (int i = 0; i < r; ++i) {
          for (int j = 0; j < c; ++j) {
            if (matrix[i][j] == -2) {
              out = out + "?";
            } else if (matrix[i][j] == -1) {
              out = out + "*";
            } else if (j == c - 1 && i == r - 1) {
              out = out + "c";
            } else {
              out = out + ".";
            }
          }
          out = out + "\n";
        }
        printf("%s", out.c_str());
      } else {
        printf("Impossible\n");
      }
    }
  }
  fflush(stdout);
}
