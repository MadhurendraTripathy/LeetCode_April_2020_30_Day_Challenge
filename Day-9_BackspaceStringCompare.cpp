#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])) stk.push(s[i]);
            else{
                if(!stk.empty()){
                    stk.pop();
                }
            }
        }
        string s_copy="";
        while(!stk.empty()){
            s_copy.push_back(stk.top());
            stk.pop();
        }
        for(int i=0;i<t.length();i++){
            if(isalpha(t[i])) stk.push(t[i]);
            else{
                if(!stk.empty()){
                    stk.pop();
                }
            }
        }
        string t_copy="";
        while(!stk.empty()){
            t_copy.push_back(stk.top());
            stk.pop();
        }
        if(t_copy==s_copy){
            return true;
        }
        return false;
        }
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    string s1="ab##";
    string s2="c#d#";
    cout<<s.backspaceCompare(s1, s2)<<"\n";
    return 0;
}

