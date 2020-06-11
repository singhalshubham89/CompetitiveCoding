#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        vector<int> a(3), b(3);
        vector<int> dist;
        cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
        int ans = 0;
        for(int i = 0; i < 3; i++){
            if(a[i] != b[i])
            {
                dist.push_back(a[i]);
                dist.push_back(b[i]);
            }
        }
        while(dist.size() > 0){
            if(dist.size() == 2){
                ans++;
                break;
            }
            int maxsub = 0;
            int totalmaxsub = 0;
            for(int i = 0; i < dist.size(); i += 2){
                int countsub = 0;
                int sub = dist[i+1]-dist[i];
                for(int j = 0; j < dist.size(); j += 2){
                    if(sub+dist[j] == dist[j+1])
                        countsub++;
                }
                if(totalmaxsub < countsub)
                {
                    totalmaxsub = countsub;
                    maxsub = sub;
                }
                if(countsub == dist.size()/2)
                {
                    break;
                }
            }
            int maxmul = 0;
            int totalmaxmul = 0;
            for(int i = 0; i < dist.size(); i += 2){
                if(dist[i] == 0 || (abs(dist[i+1])%abs(dist[i])) != 0)
                    continue;
                int countmul = 0;
                int mul = dist[i+1]/dist[i];
                for(int j = 0; j < dist.size(); j += 2){
                    if(mul*dist[j] == dist[j+1] )
                        countmul++;
                }
                if(totalmaxmul < countmul)
                {
                    totalmaxmul = countmul;
                    maxsub = mul;
                }
                if(countmul == dist.size()/2)
                {
                    break;
                }
            }
            if(totalmaxmul == dist.size()/2 || totalmaxsub == dist.size()/2){
                ans += 1;
                break;
            }
            else if(totalmaxmul == (dist.size()/2)-1 || totalmaxsub == (dist.size()/2)-1){
                ans += 2;
                break;
            }
            int x = dist[2] - dist[0];
            int y = dist[3] - dist[1];
            if(x != 0 && (abs(y)%abs(x)) == 0){
                x = y/x;
                y = dist[1] - (dist[0]*x);
                int count = 0;
                for(int i = 2; i < dist.size(); i += 2){
                    if((dist[i]*x)+y == dist[i+1])
                        count++;
                }
                if(count == 2){
                    ans += 2;
                    break;
                }
                count = 0;
                if(x != 0 && (abs(dist[1])%abs(x)) == 0){
                     y = x;
                     x = (dist[1]/y)-dist[1];
                     for(int i = 2; i < dist.size(); i += 2){
                        if((dist[i]+x)*y == dist[i+1])
                            count++;
                    }
                    if(count == 2){
                        ans += 2;
                        break;
                    }
                }
            }
            if( dist[0] != 0 && abs(dist[1])%abs(dist[0]) == 0 && dist[3]-(dist[2]*(dist[1]/dist[0])) == dist[5]-(dist[4]*(dist[1]/dist[0]))){
                ans += 2;
                break;
            }
            
            if(  dist[2] != 0 && abs(dist[3])%abs(dist[2]) == 0 && dist[1]-(dist[0]*(dist[3]/dist[2])) == dist[5]-(dist[4]*(dist[3]/dist[2]))){
                ans += 2;
                break;
            }
            if(  dist[4] != 0 && abs(dist[5])%abs(dist[4]) == 0 && dist[3]-(dist[2]*(dist[5]/dist[4])) == dist[1]-(dist[0]*(dist[5]/dist[4]))){
                ans += 2;
                break;
            }
            int temp  = dist[1]-dist[0];
            if( dist[2]+temp != 0 && dist[4]+temp != 0 && abs(dist[3])%abs(dist[2]+temp) == 0 && abs(dist[5])%abs(dist[4]+temp) == 0 &&  dist[3]/(dist[2]+temp) == dist[5]/(dist[4]+temp)){
                ans += 2;
                break;
            }
            temp  = dist[3]-dist[2];
            if( dist[0]+temp != 0 && dist[4]+temp != 0 && abs(dist[1])%abs(dist[0]+temp) == 0 && abs(dist[5])%abs(dist[4]+temp) == 0 &&  dist[1]/(dist[0]+temp) == dist[5]/(dist[4]+temp)){
                ans += 2;
                break;
            }
            temp  = dist[5]-dist[4];
            if( dist[2]+temp != 0 && dist[0]+temp != 0 && abs(dist[3])%abs(dist[2]+temp) == 0 && abs(dist[1])%abs(dist[0]+temp) == 0 &&  dist[3]/(dist[2]+temp) == dist[1]/(dist[0]+temp)){
                ans += 2;
                break;
            }
            ans += 3;
            break;
        }
        cout<<ans<<endl;
        
    }
    //cout<<0%0<<endl;
    cout<<0%1<<endl;
}