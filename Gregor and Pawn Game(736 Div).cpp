#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string en, gn;
        int en0 = 0, en1 = 0, gn1 = 0;
        cin>>en;
        cin>>gn;
         for(int i = 0; i < n; i++){
            if(gn[i] == '1' && en[i] == '0'){
                gn[i] = '0';
                en0++;
            }
        }
        for(int i = 0; i < n; i++){
            if(gn[i] == '0')
                continue;
            if(i != 0 && gn[i] == '1' && en[i-1] == '1')
            {
                en0++;
                en[i-1] = '0';
                gn[i] = '0';
            }
            else if(i != n-1 && gn[i] == '1' && en[i+1] == '1'){
                en0++;
                en[i+1] = '0';
                gn[i] = '0';
            }
        }
        cout<<en0<<endl;
    }
    return 0;
}