#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k, num, loss = 0;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>num;
        if(num > k)
            loss += num-k;

    }
    cout<<loss<<"\n";
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