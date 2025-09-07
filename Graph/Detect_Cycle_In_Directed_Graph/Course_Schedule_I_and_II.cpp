#include <bits/stdc++.h>
using namespace std;
/*
Input: N = 4, P = 3, prerequisites = [[1,0],[2,1],[3,2]]
Output: Yes
Explanation: To do task 1 you should have completed task 0, and to do task 2 you should have finished task 1, and to do task 3 you should have finished task 2. So it is possible.
*/
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        
         int V = N;
        
        
       vector<int>adj[V];
       for(auto &it  : prerequisites)
       {
        adj[it.first].push_back(it.second);
       }
       vector<int>inDegree(V,0);
        for (int  i = 0; i < V; i++)
        {
            for(auto &it : adj[i])
            {
                inDegree[it]++;
            }
        }
        queue<int>q;
       for (int i = 0; i < N; i++)
       {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
       }
       vector<int>topo;
       while(!q.empty())
       {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto &it : adj[node])
        {
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
       }
       if(topo.size() == N) return true;
       else return false;
        
    }
};