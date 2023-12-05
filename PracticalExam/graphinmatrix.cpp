#include <bits/stdc++.h>
using namespace std;

int N = 1e3 + 10;
int main(int argc, char const *argv[])
{
int graph[N][N];
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    return 0;
}
