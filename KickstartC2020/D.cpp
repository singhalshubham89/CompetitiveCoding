#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n, q;
  cin>>n>>q;
  vector<int> a(n);
  vector<int> psum(n+1, 0);
  vector<int> finalsum(n+1, 0);
  for(int i = 0; i < n; i++){
      cin>>a[i];
      psum[i+1] = a[i]+psum[i];
  }

  for(int i = 1; i <= n; i++){
      finalsum[i] = psum[i]+finalsum[i-1];
  }
  
  int ans = 0;
  while(q--){
      char op;
      cin>>op;
      if(op == 'Q'){
          int l, r;
          cin>>l>>r;
          int temp = finalsum[r]-finalsum[l-1];
        //   int temp = 0;
        //   for(int i =1, j =l-1; j < r; i++, j++) {
        //       if(i%2 == 0){
        //         temp += (a[j]*i*-1);
        //       }else{
        //           temp += a[j]*i;
        //       }
        //       cout<<i<<" "<<temp<<endl;
        //   }
        cout<<temp<<endl;
          ans += temp;
      }else{
          int idx;
          cin>>idx;
          cin>>a[idx-1];
      }
      
  }
  cout<<ans<<endl;
}
int main(){

    int t;
    cin>>t;
    for(int i = 1; i <= t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

}