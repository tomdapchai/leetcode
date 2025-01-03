#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, vector<int>> adjacent(vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> res;
    for (const vector<int> &edge : edges)
    {
        res[edge[0]].push_back(edge[1]);
        res[edge[1]].push_back(edge[0]);
    }
    return res;
}

// find the farthest node form a random node, then store the distance from between them
pair<int, int> dfs(int node, unordered_map<int, vector<int>> &adjacent, vector<bool> &visited)
{
    visited[node] = true;
    pair<int, int> farthest = {node, 0};

    for (int neighbor : adjacent.at(node))
    {
        if (!visited[neighbor])
        {
            auto result = dfs(neighbor, adjacent, visited);
            if (result.second + 1 > farthest.second)
            {
                farthest = {result.first, result.second + 1};
            }
        }
    }
    return farthest;
}

int calculateDiameter(vector<vector<int>> &edges)
{
    if (edges.empty())
        return 0;

    auto adjList = adjacent(edges);
    int n = adjList.size();

    vector<bool> visited(n + 1, false);
    // find farthest node from 0
    auto firstDFS = dfs(0, adjList, visited);

    fill(visited.begin(), visited.end(), false);
    // find the distance - diameter
    auto secondDFS = dfs(firstDFS.first, adjList, visited);

    return secondDFS.second;
}
int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    int dia1 = calculateDiameter(edges1);
    int dia2 = calculateDiameter(edges2);

    return max({(int)ceil((float)dia1 / 2) + (int)ceil((float)dia2 / 2) + 1, dia1, dia2});
}

int main()
{
    std::vector<std::vector<int>> edges1 = {
        {0, 1},
        {2, 0},
        {3, 2},
        {3, 6},
        {8, 7},
        {4, 8},
        {5, 4},
        {3, 5},
        {3, 9}};
    vector<vector<int>> edges2 = {
        {0, 1}, {0, 2}, {0, 3}};
    vector<int> nodes = {1, 2, 3, 4, 5, 6, 7};
    vector<int> traverse = {};
    vector<int> path = {};
    vector<vector<int>> totalPath;
    int res = minimumDiameterAfterMerge(edges1, edges2);

    cout << "res " << res << endl;

    /* for (int i : path)
    {
        cout << i << ",";
    } */
    /* vector<int> res = dfsHelper(5, nodes, edges1, traverse);
    res.push_back(5);
    res.erase(res.begin());
    for (int i : res)
    {
        cout << i << " ";
    } */
    /* int res = dfsHelper(0, nodes, edges1, traverse, path) - 1;
    cout << "res " << res << endl;
    cout << "Final Path" << endl;

    for (int p : path)
    {
        cout << p << " ";
    }
    cout << endl; */

    return 0;
}