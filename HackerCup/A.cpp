#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<char> incoming(n), outgoing(n);
    for (int i = 0; i < n; i++)
    {
        cin >> incoming[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> outgoing[i];
    }
    vector<vector<char>> ans(n, vector<char>(n, 'N'));
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 'Y';
        for (int j = i + 1; j < n; j++)
        {
            if (ans[i][j - 1] == 'Y' && outgoing[j - 1] == 'Y' && incoming[j] == 'Y')
                ans[i][j] = 'Y';
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (ans[i][j + 1] == 'Y' && outgoing[j + 1] == 'Y' && incoming[j] == 'Y')
                ans[i][j] = 'Y';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << endl;
    }
}
int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ":" << endl;
        solve();
    }
}