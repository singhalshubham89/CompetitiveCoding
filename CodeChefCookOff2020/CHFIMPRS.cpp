#include <bits/stdc++.h>
using namespace std;
void disp(vector<vector<int>> matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            mp[matrix[i][j]]++;
        }
    }
    int flag = 1;
    if (m == 1)
    {
        disp(matrix, n, m);
    }
    else if (m % 2 == 0)
    {
        for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        {
            if ((itr->second) % 2 == 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            auto itr = mp.begin();
            int count = itr->second;
            int num = itr->first;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m / 2; j++)
                {
                    ans[i][j] = num;
                    ans[i][m - j - 1] = num;
                    count -= 2;
                    if (count == 0)
                    {
                        ++itr;
                        if (itr != mp.end())
                        {
                            count = itr->second;
                            num = itr->first;
                        }
                    }
                }
            }
            disp(ans, n, m);
        }
    }
    else
    {
        int odd = 0;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        {
            if ((itr->second) % 2 == 1)
            {
                 odd++;
            }
        }
        // cout<<" ODD "<<odd<<endl;
        if (odd > n)
        {
            flag = 0;
        }
        else
        {
            auto itr = mp.begin();
            int count = itr->second;
            int num = itr->first;
            vector<int> rem;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m / 2; j++)
                {
                    
                    while (count == 0 || count == 1)
                    {
                        if (count){
                            rem.push_back(num);
                            //cout<<num<<" "<<endl;
                        }
                            
                        ++itr;
                        if (itr != mp.end())
                        {
                            count = itr->second;
                            num = itr->first;
                        }
                    }
                    ans[i][j] = num;
                    ans[i][m - j - 1] = num;
                    count -= 2;
                }
            }
            //disp(ans, n, m);
            for (int i = 0, j = 0; i < n; i++, j++)
            {
                if (j < rem.size())
                    ans[i][m / 2] = rem[j];
                else
                {
                    if (count == 0)
                    {
                        ++itr;
                        if (itr != mp.end())
                        {
                            count = itr->second;
                            num = itr->first;
                        }
                    }
                    ans[i][m/2] = num;
                    count--;
                }
            }
            disp(ans, n, m);
        }
    }
    if (flag == 0)
        cout << -1 << endl;
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