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

int id = 1;

using namespace std;

struct Block {
  int id;
  int index;
  int size;
};

int main () {
  int t, m;
  scanf("%d %d", &t, &m);
  vector<Block> memory;
  for (int j = 0; j < t; j++) {
    char c[20];
    scanf("%s", c);
    string s(c);
    if (s == "alloc") {
      int n;
      scanf("%d", &n);
      /*
      if (n == 99) {
        printf("hello");
      }
      */
      // empty case
      if (memory.empty()) {
        int available_memory = m;
        if (available_memory >= n) {
          Block block = {id++, 0, n};
          memory.push_back(block);
          printf("%d\n", block.id);
        } else {
          printf("NULL\n");
        }
        continue;
      }
      // start to first block
      if (!memory.empty()) {
        int available_memory = memory[0].index;
        if (available_memory >= n) {
          Block block = {id++, 0, n};
          memory.insert(memory.begin(), block);
          printf("%d\n", block.id);
          continue;
        }
      }
      // between each block
      bool found = false;
      for (int i = 0; i < (int) memory.size() - 1; i++) {
        int free_start = memory[i].index + memory[i].size;
        int free_end = memory[i + 1].index;
        int available_memory = free_end - free_start;
        if (available_memory >= n) {
          Block block = {id++, free_start, n};
          memory.insert(memory.begin() + i, block);
          printf("%d\n", block.id);
          found = true;
          break;
        }
      }
      if (found) {
        continue;
      }
      // last block to end
      if (!memory.empty()) {
        int free_start = memory[memory.size() - 1].index + memory[memory.size() - 1].size;
        int free_end = m;
        int available_memory = free_end - free_start;
        if (available_memory >= n) {
          Block block = {id++, free_start, n};
          memory.push_back(block);
          printf("%d\n", block.id);
          continue;
        }
      }
      printf("NULL\n");
    }  else if (s == "erase") {
      int erase_id;
      scanf("%d", &erase_id);
      bool found = false;
      for (auto it = memory.begin(); it != memory.end();) {
        if (it->id == erase_id) {
          it = memory.erase(it);
          found = true;
        } else {
          it++;
        }
      }
      if (!found) {
        printf("ILLEGAL_ERASE_ARGUMENT\n");
      }
    } else if (s == "defragment") {
      if (!memory.empty()) {
        memory[0].index = 0;
        for (int i = 1; i < memory.size(); i++) {
          int ending_point = memory[i - 1].index + memory[i - 1].size;
          memory[i].index = ending_point;
        }
      }
    }
  }
}
