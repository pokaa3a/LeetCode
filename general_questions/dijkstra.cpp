#include <iostream>
#include <vector>
#include <queue>

// Dijkstra computes the shortest paths from node K to all the other nodes
class Dijkstra
{
public:
    vector<int> shortestPaths(vector<vector<int>>& cost, int N, int K)
    {
        // cost[i] = {u, v, weight}
        // N: # of nodes
        // K: source node

        // graph[u][v] == cost from u to v
        vector<vector<int>> graph(N, vector<int>(N, INT_MAX));
        for (auto x : cost)
        {
            int u = x[0], v = x[1], w = x[2];
            graph[u][v] = w;
        }

        vector<int> distance(N, INT_MAX);   // distance from K to any node
        distance[K] = 0;

        // pq[i] = (cost, node-id)
        priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, K));

        while (!pq.empty())
        {
            int w = pq.top().first;     // cost
            int u = pq.top().second;    // node
            pq.pop();

            for (int v = 0; v < N; ++v)
            {
                if (graph[u][v] != INT_MAX && w + graph[u][v] < distance[v])
                {
                    distance[v] = w + graph[u][v];
                    pq.push(make_pair(distance[v], v));
                }
            }
        }
        return distance;
    }
};

int main()
{

}