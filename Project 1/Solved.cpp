#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
vector<vector<int>> edges;
vector<vector<int>> edges2;
vector<int> dp;

void dfs(vector<int> order)
{

    for (size_t i = order.size() - 1; i > 0; i--)
    {

        for (size_t j = 0; j < edges2[order[i]].size(); j++)
        {
            dp[(edges2[order[i]][j])] = max(dp[(edges2[order[i]][j])], dp[(order[i])] + 1);
        }
    }
}

vector<int> topOrder(int n, vector<int> sc)
{

    vector<int> Q;
    for (int i = 1; i <= n; i++)
    {
        if (sc[i] == 0)
        {
            Q.push_back(i);
        }
    }
    vector<int> L;

    while (!Q.empty())
    {
        int u = Q[0];
        Q.erase(Q.begin());
        L.push_back(u);
        for (size_t i = 0; i < edges[u].size(); i++)
        {
            sc[edges[u][i]] -= 1;
            if (sc[edges[u][i]] == 0)
                Q.push_back(edges[u][i]);
        }
    }
    return L;
}

int getLongest(int n, vector<int> order)
{
    int longest = 0;
    dp = vector<int>(n + 1, 0);

    dfs(order);

    for (size_t i = 1; i < dp.size(); i++)
    {
        longest = max(longest, dp[i]);
    }
    return longest + 1;
}

int getsc(vector<int> sc, int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sc[i] == 0)
            s++;
    }
    return s;
}

int main()
{

    int n;
    int e;
    if (scanf("%d %d", &n, &e))
        ;

    edges = vector<vector<int>>(n + 1, vector<int>());
    edges2 = vector<vector<int>>(n + 1, vector<int>());
    vector<int> sc = vector<int>(n + 1, 0);
    int i = 0;
    while (i < e)
    {
        int a, b;
        if (scanf("%d %d", &a, &b))
        {
            i++;
            sc[b] += 1;
            edges[a].push_back(b);
            edges2[b].push_back(a);
        }
    }
    int s;
    s = getsc(sc, n);
    vector<int> T = topOrder(n, sc);

    cout << s << " " << getLongest(n, T) << "\n";
    return 0;
}