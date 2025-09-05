#include<bits/stdc++.h>
using namespace std;
class Solution {
private :
bool check(int start,int V,vector<vector<int>>&graph,int color[])
{
    queue<int>q;
    q.push(start);
    color[start] = 0; // intitial color 0
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : graph[node])
         {
            //if the adjacent nodes is not yet colored
            //you will give the opposite color of the node
            if(color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            //if the adjacent guy having the same color 
            //someone did color it on the same path then  return false
            else if(color[it] == color[node])
            {
                return false;
            }
         }
    }
    return true;
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V] ;
        for(int i=0;i<V;i++)
        {
            color[i] = -1;
        }

        //since it can have V different components
        for(int i=0;i<V;i++)
        {
            if(color[i] == -1)
            {
                if(check(i,V,graph,color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};