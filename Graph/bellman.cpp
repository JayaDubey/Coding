// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dis(n, INT_MAX);
	    dis[0] = 0;
	    for(int i = 0; i < n-1; i++){
	        for(int j = 0; j < edges.size(); j++){
	            if(dis[edges[j][0]] != INT_MAX && dis[edges[j][0]] + edges[j][2] < dis[edges[j][1]])
	            dis[edges[j][1]] = dis[edges[j][0]] + edges[j][2];
	        }
	    }
	   int flag = 0;
	    for(int j = 0; j < edges.size(); j++){
	            if(dis[edges[j][0]] != INT_MAX && dis[edges[j][0]] + edges[j][2] < dis[edges[j][1]]){
	            flag = 1;
	            break;
	        }
	        }
	if(!flag) {
        for(int i = 0;i<n;i++) {
            cout << i << " " << dis[i] << endl;
        }
    }
	    return flag;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
