
#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int pax, link;
vector<vector<int>> matrix;
vector<vector<int>> reverse_matrix;
vector<bool> visited;
stack<int> Stack;
vector<vector<int>> scc_matrix;
vector<int> scc_id;
vector<vector<int>> sccs;
vector<int> current_scc, longest_path, dp;

void PrintVector(vector<int> v)
{
    int index = 0;
    for (int i : v)
    {
        // if (index != 0)
        cout << "index: " << index << " - " << i << endl;
        index++;
    }
}
void printMatrix(vector<vector<int>> matriz)
{
    for (int i = 0; i <= pax; ++i)
    {
        cout << "Adjacencias do vertice " << i << ": ";
        for (int neighbor : matriz[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

void DFS(int v)
{
    // Create a stack for DFS
    stack<int> dfs_stack;

    // Push the current source node.
    dfs_stack.push(v);

    while (!dfs_stack.empty())
    {
        // Pop a vertex from stack and print it
        v = dfs_stack.top();
        dfs_stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[v])
        {
            current_scc.push_back(v);
            visited[v] = true;
        }

        // Get all adjacent vertices of the popped vertex v
        // If an adjacent has not been visited, then push it to the stack.
        for (int i = 0; i < static_cast<int>(reverse_matrix[v].size()); i++)
        {
            int neighbor = reverse_matrix[v][i];
            if (!visited[neighbor])
            {
                dfs_stack.push(neighbor);
            }
        }
    }
}

void fillOrder(int v)
{
    // Create a stack for DFS
    stack<int> dfs_stack;

    // Push the current source node.
    dfs_stack.push(v);

    while (!dfs_stack.empty())
    {
        v = dfs_stack.top();

        if (!visited[v])
        {
            visited[v] = true;
        }

        bool has_unvisited_neighbor = false;
        for (int i = 0; i < static_cast<int>(matrix[v].size()); i++)
        {
            int neighbor = matrix[v][i];
            if (!visited[neighbor])
            {
                dfs_stack.push(neighbor);
                has_unvisited_neighbor = true;
                break;
            }
        }

        if (!has_unvisited_neighbor)
        {
            dfs_stack.pop();
            Stack.push(v);
        }
    }
}
void findSCCs(int V)
{
    sccs.push_back(vector<int>());
    visited.assign(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            fillOrder(i);

    visited.assign(V, false);

    while (!Stack.empty())
    {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v])
        {
            current_scc.clear();
            DFS(v);
            // cout << endl;
            sccs.push_back(current_scc);
        }
    }
}
void buildSCCMatrix()
{
    scc_matrix.resize(sccs.size());
    scc_id.resize(pax + 1);

    for (int i = 0; i < static_cast<int>(sccs.size()); i++)
    {
        for (int node : sccs[i])
        {
            scc_id[node] = (sccs[i].size() == 1) ? node : i;
        }
    }

    for (int i = 0; i < static_cast<int>(matrix.size()); i++)
    {
        for (int j = 0; j < static_cast<int>(matrix[i].size()); j++)
        {
            int u = scc_id[i];
            int v = scc_id[matrix[i][j]];
            if (u != v)
            {
                scc_matrix[u].push_back(v);
            }
        }
    }
}
int DFS_final(int node)
{
    if (dp[node] != -1)
    {
        if (node > static_cast<int>(dp.size()))
            return 0;
        return dp[node];
    }

    dp[node] = 0;
    for (int i = 0; i < static_cast<int>(scc_matrix[node].size()); i++)
    {
        dp[node] = max(dp[node], 1 + DFS_final(scc_matrix[node][i]));
    }
    return dp[node];
}
int findMaxDepth()
{
    int maxDepth = 0;
    dp = vector<int>(scc_matrix.size(), -1);

    for (int start = 0; start < static_cast<int>(scc_matrix.size()); start++)
    {
        maxDepth = max(maxDepth, DFS_final(start));
    }

    return maxDepth;
}
int main()
{
    time_t start, end;
    time(&start);
    scanf("%d %d", &pax, &link);
    matrix.resize(pax + 1);
    reverse_matrix.resize(pax + 1);
    visited.resize(pax, false);
    longest_path.resize(scc_matrix.size(), -1);

    for (int i = 1; i < link + 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        matrix[x].push_back(y);
        reverse_matrix[y].push_back(x);
    }
    findSCCs(pax);
    buildSCCMatrix();
    cout << findMaxDepth() << endl;
    time(&end);
    double time_taken_ins = double(end - start);
    cout << "\nTime taken by intake data : " << fixed
         << time_taken_ins << setprecision(25) << endl;
    return 0;
}