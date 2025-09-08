#include<bits/stdc++.h>
using namespace std;
class Solution
{

private:
    // works for multiple components as well
    vector<int> topoSort(int V, vector<vector<int>> adj)
    {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }

public:
    string findOrder(vector<string> &words)
    {

        int N = words.size();

        unordered_set<char> charSet;
        for (int i = 0; i < words.size(); i++)
        {
            for (char &ch : words[i])
            {
                charSet.insert({ch});
            }
        }
        int V = charSet.size(); // total vertices in graph
        //******************************************************************************** */
       // vector<int> adj[V];  causing segmentation fault in this  because we are doing this   adj[s1[j] - 'a'].push_back(s2[j] - 'a'); 
  vector<vector<int>>adj(V);
        for (int i = 0; i < N - 1; i++) // N-1 since I need pairs
        {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a'); // s1 -> s2  but we want to store it in  0->1
                    break;
                }
            }
        }
        // now graph is ready

        vector<int> topo = topoSort(V, adj);
        string ans = "";
        for (auto it : topo)
        {
            ans = ans + char(it + 'a');
        }

        return ans;
    }
};