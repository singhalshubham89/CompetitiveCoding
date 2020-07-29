#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<char> stk;
    char inp;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        if (stk.size() < 2)
            stk.push_back(inp);
        else if (inp == stk[stk.size() - 1] && inp == stk[stk.size() - 2])
        {
            stk.push_back(inp);
        }
        else
        {
            int first = stk.back();
            stk.pop_back();
            int second = stk.back();
            stk.pop_back();
            if (first == inp || second == inp)
            {
                stk.push_back(inp);
            }
            else
            {
                stk.push_back(first);
            }
        }
    }
    if (stk.size() == 1)
        cout << 'Y' << endl;
    else
    {
        cout << 'N' << endl;
    }
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