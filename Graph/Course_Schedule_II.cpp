#include <bits/stdc++.h>
using namespace std;
/*
Input: n = 4, prerequisites[][] = [[1, 0], [2, 0], [3, 1], [3, 2]]
Output: true
Explanation: There are a total of 4 tasks to pick. To pick task 3 you should have finished both tasks 1 and 2. Both tasks 1 and 2 should be pick after you finished task 0. So one correct task order is [0, 1, 2, 3]. Another correct ordering is [0, 2, 1, 3]. Returning any of these order will result in an output of true.
*/
class Solution {
  public:
    vector<int> findOrder(int V, vector<vector<int>> prerequisites) {
      
        vector<int>adj[V];
        for(auto &it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
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
       for (int i = 0; i < V; i++)
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
       if(topo.size() == V) return topo;
       else return {};
    }
};