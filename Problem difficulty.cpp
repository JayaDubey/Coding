#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a[4]; int f = 0;      //difficulty level
	    for(int i = 0; i < 4; i++)
	    cin>>a[i];
	    for(int i = 0; i < 3; i++){
	        for(int j = i+1; j < 4; j++){
	            if(a[i] == a[j])
	                f++;
	        }
	            if(f==3){
	                cout<<0<<endl;
	                break;
	            }
	            else if(f == 1){
	                cout<<2<<endl;    
	                break;
	            }
	            else if(f > 1){
	            cout<<1<<endl;    
	            break;
	            }
	    }
	   if(f == 0)
	   cout<<2<<endl;
	}
	return 0;
}
