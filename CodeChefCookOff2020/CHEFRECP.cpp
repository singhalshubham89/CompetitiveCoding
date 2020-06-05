#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<int> jar;
    set<int> sz;
    vector<int> arr(n);
    int prev = -1;
    int count = 0;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (prev != arr[i])
        {
            if (jar.find(prev) != jar.end())
            {
                flag = 0;
                break;
            }
            else
            {
                if (count > 0)
                {
                    sz.insert(count);
                    jar.insert(prev);
                }
                //cout<<count<<" "<<prev<<endl;
                prev = arr[i];
                count = 1;
            }
        }
        else
        {
            count++;
        }
    }
    if (jar.find(prev) == jar.end())
    {
        //cout<<count<<" "<<prev<<endl;
        sz.insert(count);
        jar.insert(prev);
    }else{
        flag = 0;
    }
    //cout<<sz.size()<<" "<<jar.size()<<endl;
    if (flag == 1 && sz.size() == jar.size())
        cout << "YES\n";
    else
    {
        cout << "NO\n";
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