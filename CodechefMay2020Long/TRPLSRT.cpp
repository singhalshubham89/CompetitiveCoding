#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> val;
    map<int, int> pos;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp != i + 1)
        {
            val[temp] = i + 1;
            pos[i+1] = temp;
        }
    }
    int pi1, pi2, pi3;
    map<int, int>::iterator itr = pos.begin();
    map<int, int>::iterator itr1;
    map<int, int>::iterator itr2;
    int flag = 1;
    vector<vector<int>> ans;
    for (; itr != pos.end(); ++itr)
    {
        if (itr->first != itr->second)
        {
            itr1 = itr;
            ++itr1;
            if(itr1 == pos.end())
            {
                flag = 0;
                break;
            }else if(itr->first == itr1->second)
                ++itr1;
            if(itr1 == pos.end())
            {
                flag = 0;
                break;
            }
            itr2 = val.find(itr->first);
            itr2 = pos.find(itr2->second);
            itr2->second = itr1->second;
            itr1->second = itr->second;
            itr->second = itr->first;
            val[itr->second] = itr->first;
            val[itr1->second] = itr1->first;
            val[itr2->second] = itr2->first;
            ans.push_back({itr->first, itr1->first, itr2->first});
        }
        if(!flag)
            break;
    }

    if (ans.size() > k || !flag)
        cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
        }
    }
}
int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}