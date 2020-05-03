#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x, y;
    string m;
    int mx = 0, my = 0;
    cin >> x >> y >> m;
    int i = 0;
    int found = 0;
    
    if (mx == x && my == y)
    {
        found = 1;
    }
    for (i = 0; i < m.size() && !found; i++)
    {

        switch (m[i])
        {
        case 'N':
            y += 1;
            break;

        case 'S':
            y -= 1;
            break;

        case 'W':
            x -= 1;
            break;

        case 'E':
            x += 1;
            break;
        }
        if(abs(x)+abs(y) <= i+1){
            found = 1;
        }
        //cout<<x<<" "<<y<<" "<<mx<<" "<<my<<endl;
    }
    if(found)
        cout<<i<<endl;
    else
        cout<<"IMPOSSIBLE\n";
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