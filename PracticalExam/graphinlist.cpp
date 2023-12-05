#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[5];
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    return 0;
}

// // weighted
// #include <bits/stdc++.h>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int n, m;
//     cin >> n >> m;

//     vector << pair < int, int >> graph1[N + 1];
//     for (int i = 0; i < m; i++)
//     {
//         int v1, v2, wt;
//         cin >> v1 >> v2 >> wt;

//         graph[v1][v2] = 1;
//         graph[v2][v1] = 1;

//         graph1[v1].push_back({v2, wt});
//         graph1[v2].push_back({v1, wt});
//     }

//     return 0;
// }

// // directed
// #include <bits/stdc++.h>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> graph1[N];
//     for (int i = 0; i < m; i++)
//     {
//         int v1, v2;
//         cin >> v1 >> v2;

//         graph[v1][v2] = 1;
//         graph[v2][v1] = 1;

//         graph1[v1].push_back(v2);
//     }

//     return 0;
// }
