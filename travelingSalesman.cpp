#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n; // number of nodes
int dist[20][20]; // distance matrix
int memo[20][1 << 16]; // memoization array for dp

// TSP dp function
int tsp(int pos, int mask) {
    if (mask == (1 << n) - 1) // base case: all nodes visited
        return dist[pos][0];

    if (memo[pos][mask] != -1) // memoization
        return memo[pos][mask];

    int ans = INF;

    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) { // node i not visited
            ans = min(ans, dist[pos][i] + tsp(i, mask | (1 << i)));
        }
    }

    memo[pos][mask] = ans; // store the result
    return ans;
}

int main() {
    memset(memo, -1, sizeof(memo)); // initialize memoization array with -1

    // input distance matrix
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int ans = tsp(0, 1); // start from node 0 and visit node 0
    cout << "The cost of most efficient tour = " << ans << "\n";

    return 0;
}
