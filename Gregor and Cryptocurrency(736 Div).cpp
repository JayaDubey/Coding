#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
    int t;
    cin>>t;
    int f = 0;
    while(t--){
        ll p;
        cin>>p;
        for(ll a = 2; a <= p; a++){
            for(ll b = a+1; b <= p; b++){
                if(p%a == p%b){
                    cout<<a<<" "<<b<<endl;
                    f = 1;
                    break;
                }
            }
            if(f == 1)
                break;
        }
    }
    return 0;
}