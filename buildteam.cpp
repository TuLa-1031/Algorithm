/*
            Building teams (Graph traversal)
There are n pupils in Uolevi's class, and m friendships between them.
Your task is to divide the pupils into two teams in such a way that no
two pupils in a team are friends. You can freely choose the sizes of
the teams.

    Input
The first input line has two integers n and m: the number of pupils 
and friendships. The pupils are numbered 1,2,\dots,n. Then, there are
m lines describing the friendships. Each line has two integers a and b:
pupils a and b are friends. Every friendship is between two different
pupils. You can assume that there is at most one friendship between any
two pupils.

    Output
Print an example of how to build the teams. For each pupil, print "1" or
"2" depending on to which team the pupil will be assigned. You can print
any valid team. If there are no solutions, print "IMPOSSIBLE".

Constraints
1 <= n <= 10^5
1 <= m <= 2x10^5
1 <= a,b <= n

Example
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2
*/

#include <bits/stdc++.h>
using namespace std;
const int mxN = 10e5+1;

bool poss, vis[mxN], team[mxN];
int n, m, a, b;
vector<int> g[mxN];

void dfs(int u, int p = 0) {
    for (int v : g[u]) {
        if (v != p) {
            if (!vis[v]) {
                team[v] = !team[u];
                vis[v] = true;
                dfs(v, u);
            } else
                if (team[v] == team[u]) poss = false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    poss = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
    if (!poss) printf("IMPOSSIBLE");
    else
        for (int i = 1; i <= n; i++)
            printf("%d%c", (team[i] ? 1 : 2), (" \n")[i==n]);
    return 0;
}