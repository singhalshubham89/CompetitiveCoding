#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   int test;
   cin>>test;
   while(test--){
       vector<ll> a(3);
       for(int i = 0; i < 3; i++){
           cin>>a[i];
       }
       ll temp;
       vector<ll> d;
       for(int i = 0; i < 3; i++){
           cin>>temp;
           if(temp != a[i]){
               d.push_back(a[i]);
               d.push_back(temp);
           }
       }
       ll ans = d.size()/2;
       ll count;
       if(ans > 1){
           ll maxcount = 0;
           for(int i = 0; i < d.size(); i += 2){
               count = 0;
               if(d[i] != 0 && abs(d[i+1])%abs(d[i]) == 0){
                   ll mul = d[i+1]/d[i];
                   for(int j = 0; j <  d.size(); j += 2){
                        if(d[j]*mul == d[j+1])
                            count++;
                   }
               }
               maxcount = max(maxcount, count);
           }
           
           ll prevmaxcount = maxcount;  
           maxcount = 0;
           for(int i = 0; i < d.size(); i += 2){
                   count = 0;
                   ll sub = d[i+1]-d[i];
                   for(int j = 0; j <  d.size(); j += 2){
                        if(d[j]+sub == d[j+1])
                            count++;
                   }
                   maxcount = max(maxcount, count);
           }
           //cout<<ans<<" "<<prevmaxcount<<" "<<maxcount<<endl;
           if(maxcount == ans || prevmaxcount == ans)
            ans = 1;
           else if(maxcount == ans-1 || prevmaxcount == ans-1)
            ans = 2;
           
           if(ans > 2){
               vector<int> diff;
               for(int i = 0; i < d.size(); i += 2){
                   
                   diff.push_back(d[i+1] - d[i]);
               }
               if(diff[0]+diff[1] == diff[2] || diff[1]+diff[2] == diff[0] ||diff[0]+diff[2] == diff[1])
                    ans = 2;

               vector<int> mul;
               for(int i = 0; i < d.size(); i += 2){
                   if(d[i] != 0 && abs(d[i+1])%abs(d[i]) == 0)
                        mul.push_back(d[i+1]/d[i]);
               }
               if(mul.size() == 3)
               {
                  if(mul[0]*mul[1] == mul[2] || mul[1]*mul[2] == mul[0] || mul[0]*mul[2] == mul[1])
                            ans = 2;   
                }
                

               for(int i = 0; i < d.size(); i += 2){
                   ll den = d[(i+2)%d.size()]-d[i];
                   ll num = d[(i+3)%d.size()]-d[i+1];
                   ll flag;
                   if(den != 0 && abs(num)%abs(den) == 0){
                       ll x = num/den;
                       ll y = d[i+1]-(x*d[i]);
                       count = 0;
                       flag = 0;
                       for(int j = 0; j <  d.size(); j += 2){
                        if((d[j]*x)+y == d[j+1])
                            count++;
                        else if(d[j]*x == d[j+1])
                            flag++;
                        else if(d[j]+y == d[j+1])
                            flag++;
                       }
                       if(count == 3 || (count == 2 && flag == 1))
                         ans = 2;
                       if(x != 0 && abs(d[i+1])%abs(x) == 0){
                            count = 0;
                            flag = 0;
                            y = (d[i+1]/x)-d[i];
                            for(int j = 0; j <  d.size(); j += 2){
                                if((d[j]+y)*x == d[j+1])
                                    count++;
                                else if(d[j]+y == d[j+1])
                                    flag++;
                                else if(d[j]*x == d[j+1])
                                    flag++;
                            }
                            //cout<<count<<" "<<flag<<" "<<x<<" "<<y<<" "<<i<<endl;
                            if(count == 3 || (count == 2 && flag == 1) )
                                ans = 2;
                       }
                   }
               }
               for(int i = 0; i < d.size(); i += 2){
                   if(d[i] != 0&& abs(d[i+1])%abs(d[i]) == 0){
                       int x  = d[i+1]/d[i];
                       for(int j = 0; j < d.size(); j+= 2){
                           if(j == i)
                             continue;
                            int y = d[j+1]-d[j];
                            for(int k = 0; k < d.size(); k+= 2){
                                if(k == i || k == j)
                                    continue;
                                else if((d[k]*x)+y == d[k+1] || (d[k]+y)*x == d[k+1])
                                    ans = 2;
                            }
                       }
                   }
               }
           }
       }
     cout<<ans<<endl;
   }
}