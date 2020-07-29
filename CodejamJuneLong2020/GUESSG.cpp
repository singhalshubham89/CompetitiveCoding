#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
     int st = 1;
     int end = n;
    while(st <= end && st >= 1)
    {
        int mid = (st+end)/2;
        char prev;
        char cur;
        char finalreply;
        cout<<mid<<endl;
        cin>>cur;
        if(cur == 'E')
            break;
        int flag = 1;
        for(int i = 1; i <= 4 && flag; i++)
        {
            prev = cur;
            cout<<st<<endl;
            cin>>cur;
            if(cur == 'L')
            {
                finalreply = prev;
                break;
            }
            for(int j = 0; j < i && flag; j++)
            {
                prev = cur;
                cout<<mid<<endl;
                cin>>cur;
                if(prev == cur)
                {
                    finalreply = prev;
                    flag = 0;
                    break;
                }
                else if(cur =='E')
                {
                    finalreply = 'E';
                    flag = 0;
                    break;
                }
            }
        }
        if(finalreply == 'G')
        {
            st = mid+1;
        }
        else if(finalreply == 'E')
        {
            break;
        }
        else
        {
            end = mid-1;
        }
        
    }
    
}
int main(){

    solve();

}