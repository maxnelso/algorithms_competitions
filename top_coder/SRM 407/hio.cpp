#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <queue>
#define oo 1000000000
 
using namespace std;
 
int dx[2] = {-1,1};
 
class CheapestRoute {
public:
 
    int a[100+20][100+20];
    pair<int,int> F[100 +20][100 +20]; 
 
  vector <int> routePrice(vector <int> cost, vector <int> enterC, 
                                   vector <int> exitC, int tPrice)
  {
         int n = cost.size();
         int i,j,k,num;
         
         memset(a,0,sizeof(a));
         for (i=0; i<enterC.size(); i++)
           a[ enterC[i] ] [ exitC[i] ] = 1;
         
         for (i=0; i<=n; i++)
           for (j=0; j<=n; j++)
             F[i][j] = make_pair(-1,-1);
         
         F[0][0] = make_pair(0,0); // chi phi , do dai
         
         queue < pair<int,int> > Q; // vi tri , lan teleport
         Q.push(make_pair(0,0));
         
         while (!Q.empty())
         {
               pair<int,int> state = Q.front();
               Q.pop();
               
               i = state.first;
               num = state.second;
               
               int old_cost = F[i][num].first, old_d = F[i][num].second;
               
               // left, right
               for (k=0; k<2; k++)
                if (i+dx[k]>=0 && i+dx[k]<n && cost[i+dx[k]]!=-1 ) // ok
                {
                      pair<int,int> new_state = make_pair(i+dx[k], num);
                      pair<int,int> new_cost = make_pair(old_cost+cost[i+dx[k]], old_d+1);
                      if (F[i+dx[k]][num].first==-1 || F[i+dx[k]][num] > new_cost )
                      {
                           F[i+dx[k]][num] = new_cost;
                           Q.push(new_state);
                      }
                }               
               
             // teleport
             if (num<n)
             {
               for (j=0; j<n; j++)
                 if (a[i][j] && cost[j]!=-1)
                 {
                     // cout<<cost[j]<<endl;
                 
                      pair<int,int> new_state = make_pair(j, num+1);
                      pair<int,int> new_cost = make_pair(old_cost+tPrice+num, old_d+1);
                      if (F[j][num+1].first==-1 || F[j][num+1] > new_cost )
                      {
                           F[j][num+1] = new_cost;
                           Q.push(new_state);
                      }
                 }
             }
               
         }
         
         pair<int,int> z = make_pair(oo,oo);         
         for (j=0; j<=n; j++)
           if (F[n-1][j].first!=-1)
             if (F[n-1][j]<z)
               z = F[n-1][j];
         
         vector<int> r;      
         if (z.first==oo) return r;
         r.push_back(z.first);
         r.push_back(z.second);
         return r;                          
    }
  
  
};