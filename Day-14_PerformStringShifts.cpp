#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void leftShift(string &s,int n){
        while (n--) {
            char lastChar = s[0];
            for(int i=0;i<(int)s.length()-1;i++){
                s[i]=s[i+1];
            }
            s[(int)s.length()-1]=lastChar;
        }
    }
    void rightShift(string &s,int n){
        while (n--) {
            char firstChar = s[s.length()-1];
            for(int i=(int)s.length()-1;i>0;i--){
                s[i]=s[i-1];
            }
            s[0]=firstChar;
        }
    }
    string stringShift(string s, vector< vector<int> >& shift) {
        int lsc=0,rsc=0;
        for(vector<int>v : shift){
            if(v[0]==0){
                lsc+=v[1];
            }
            else{
                rsc+=v[1];
            }
        }
        lsc>rsc?leftShift(s, lsc-rsc):rightShift(s, rsc-lsc);
        return s;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    string str = "abcdefg";
    vector<vector<int>>v = {{1,1},{1,1},{0,2},{1,3}};
    cout<<s.stringShift(str,v)<<"\n";
    return 0;
}
