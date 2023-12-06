// To solve the problem, it was necessary to quickly support deletions. For this, one could maintain two stacks: 
// one with the positions of uppercase letters and one with the positions of lowercase letters. 
// Then, when deleting, one needs to somehow mark that the character at this position should not be output.
// Input:
// 12
// ARaBbbitBaby
// YetAnotherBrokenKeyboard
// Bubble
// Improbable
// abbreviable
// BbBB
// BusyasaBeeinaBedofBloomingBlossoms
// CoDEBARbIES
// codeforces
// bobebobbes
// b
// TheBBlackbboard

// Output:  
// ity
// YetnotherrokenKeoard
// le
// Imprle
// revile

// usyasaeeinaedofloominglossoms
// CDARIES
// codeforces
// es

// helaoard

#include<bits/stdc++.h>
using namespace std;

void typing(){
        string s;
        cin>>s;
        stack<int> lower, upper;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'b'){
                s[i] = ' ';
                if(!lower.empty()){
                    s[lower.top()] = ' ';
                    lower.pop();
                }
                continue;
            }
            if(s[i] == 'B'){
                s[i] = ' ';
                if(!upper.empty()){
                    s[upper.top()] = ' '; 
                    upper.pop();
                }
                continue;
            }
            if(s[i] >= 'a' && s[i] <= 'z')
                lower.push(i);
            else
                upper.push(i);           
        }

        s.erase(remove(s.begin(), s.end(), ' '), s.end());

        cout<<s<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--)
       typing();
    return 0;
}

//TLE executed code
// #include<bits/stdc++.h>
// using namespace std;
 
// typedef long long ll;
 
// void typing(){
//         string s;
//         cin>>s;
//         std::vector<char> v;
        
//         int check2 = 0, check1 = 0;
//         for(ll i = 0; i < s.size(); i++){
//             if(s[i] != 'b' && s[i] != 'B')
//                 v.push_back(s[i]);
 
//             else if(s[i] =='B'){
//                 for(int itr = v.size()-1; itr >= 0; itr--){
//                       if(v[itr] >= char(65) && v[itr] <= char(90)){
//                         v.erase(v.begin() + itr);
//                         check1 = 1;
//                     }
//                     if(check1 == 1){
//                         check1 = 0;
//                         break;
//                     }
//                 }
//             }
 
//             else if(s[i] =='b'){
//                 for(int itr = v.size()-1; itr >= 0; itr--){
//                       if(v[itr] >= char(97) && v[itr] <= char(122)){
//                         v.erase(v.begin() + itr);
//                         check2 = 1;
//                     }
//                     if(check2 == 1){
//                         check2 = 0;
//                         break;
//                     }
//                 }
//             }
 
//         }
 
//         if(v.empty())
//             cout<<" "<<endl;
//         else{
//         for(int i = 0; i < v.size(); i++)
//             cout<<v[i];
//         cout<<endl;
//         }
// }
