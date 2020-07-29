#include <bits/stdc++.h>
using namespace std;

bool isItPossible(int i, vector<int> &fuel, int cost, int fuelleft, int m, vector<int> &dp)
{
    // cout << i << " " << fuel[i] << " " << cost << " " << fuelleft << endl;
    if (i == fuel.size() - 1)
    {
        dp[i] = min(dp[i], cost);
        return dp[i];
    }
    if (dp[i] > cost)
    {
        dp[i] = cost;
        //relaod fuel
        if (fuel[i] != 0)
            isItPossible(i + 1, fuel, cost + fuel[i], m - 1, m, dp);
        //take fuel
        if (fuelleft != 0)
            isItPossible(i + 1, fuel, cost, fuelleft - 1, m, dp);
    }
    return dp[i];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> fuel(n);
    vector<int> dp(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        cin >> fuel[i];
    }
    int ans = isItPossible(0, fuel, 0, m, m, dp);
    if (ans != INT_MAX)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}