#include <bits/stdc++.h>
using namespace std;
void solve()
{
    map<int, int> mp;
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    int ans = 0, p, x;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> x;
        v.push_back({p, x});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        p = v[i].first;
        x = v[i].second;
        int t1, t2;
        if (mp.find(p - x) == mp.end())
            t1 = p - x;
        else
        {
            int s = mp[p - x];
            t1 = s;
        }
        if (mp.find(p) == mp.end())
            t2 = p;
        else
        {
            int s = mp.find(p)->second;
            t2 = s;
        }

        if (mp.find(p + x) != mp.end() && p + x - mp[p + x] > p + x - t2)
        {
            t2 = mp[p + x];
        }
        if (mp.find(p) != mp.end() && p - mp[p] > p - t1)
        {
            t1 = mp[p];
        }
        mp[p] = t1;
        mp[p + x] = t2;
        // cout << i << endl;
        // cout << p << " " << t1 << endl;
        // cout << p + x << " " << t2 << endl;
        ans = max(ans, p - t1);
        ans = max(ans, p + x - t2);
        // cout << ans << "\n\n";
    }
    cout << ans << endl;
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