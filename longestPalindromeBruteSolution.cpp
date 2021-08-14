class Solution {
public:
    //showing TLE
    string longestPalindrome(string s) {
        string ans = "";
        int maxlen = 1; 
        if(s.size() == 1)
            return s;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < s.size(); j++){
                string s1 = s.substr(i, j+1);
                string temp = s1;
                //cout<<temp<<endl;
                reverse(temp.begin(), temp.end());
                if(s1 == temp && ans.size() < temp.size()){
                        //maxlen = temp.size();
                        ans = temp;
                    
                }
            }
            
        }
        return ans;
    }
};