// User Function Template
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {

        vector<vector<vector<int>>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min - heap
        vector<int> dist(V, (int)1e9);
        dist[src] = 0;

        pq.push({0, src});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &it : adj[node]) // it - storing pairs in form of vector
            {
                int edgeWeight = it[1];
                int adjacentNode = it[0];
                if (dis + edgeWeight < dist[adjacentNode])
                {
                    dist[adjacentNode] = dis + edgeWeight;
                    pq.push({dist[adjacentNode], adjacentNode});
                }
            }
        }
        return dist;
    }
    vector<int> dijkstra_Using_Set(int V, vector<vector<int>> &edges, int src)
    {

        vector<vector<vector<int>>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        set<pair<int, int>> st;
        vector<int> dist(V, (int)1e9);
        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty())
        {
            auto it = *(st.begin()); // iterator pointing at the address
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (dis + edgeWeight < dist[adjNode])
                {
                    // erase if it existed
                    if (dist[adjNode] == 1e9)
                        st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

/*
🔹 Meaning of Template Arguments

priority_queue< T, Container, Comparator >

pair<int,int>
→ Each element in the heap is a pair<int,int> (two integers).

vector<pair<int,int>>
→ The underlying container used to store the heap is a vector of pairs.

greater<pair<int,int>>
→ Normally, priority_queue in C++ is max-heap.
With greater, it becomes a min-heap, ordered by the first element of the pair.
*/