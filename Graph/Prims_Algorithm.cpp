#include<bits/stdc++.h>
using namespace  std;
//MST 
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
     //V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
       vector<pair<int,int>>adj[V];
       for(auto it : edges)
       {
        //undirected graph
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
       } 

       priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater< pair<int,pair<int,int>> >>pq;

       pq.push({0,{0,-1}});   //   {edgeWeight,{currentNode,currentNodeParent}}
       
       vector<int>visited(V,0);
      int sum = 0;
      vector<pair<int,int>>MST;
      // O(E)
       while (!pq.empty())
       {
        auto it = pq.top();    // log(E)
          int edgeW = it.first;
          int node = it.second.first;
          int parent = it.second.second;
         pq.pop();

         if(visited[node] == 1) continue;
         
            visited[node] = 1;
            sum = sum + edgeW;
            if(parent != -1)                                                                                                                                                                                    
            {
                MST.push_back({parent,node});
            }
            //E * logE
            for(auto it : adj[node])
            {
                if(!visited[it.first])
                {
                   pq.push({it.second,{it.first,node}});
                }
            }
         

       }
       return sum;
       
    }
};