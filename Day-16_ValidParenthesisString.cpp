#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
    int oc=0,cc=0,sc=0;
   for(auto c :  s){
       if(c=='(') oc++;
       else if(c==')'){
           cc++;
           if(cc>oc+sc){
               return false;
           }
       }
       else sc++;
   }
    oc=0;cc=0;sc=0;
    reverse(s.begin(),s.end());
    for(auto c :  s){
       if(c==')') oc++;
       else if(c=='('){
           cc++;
           if(cc>oc+sc){
                return false;
           }
       }
       else sc++;
   }
    return true;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    string str = "()*()(*)";
    cout<<s.checkValidString(str)<<"\n";
    return 0;
}
