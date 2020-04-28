#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>&v){
        int rows = (int)v.size();
        if(rows==0) return 0;
        int cols = (int)v[0].size();
        int maxArea = 0;
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,0));
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++){
                if(v[i-1][j-1]=='1'){
                    dp[i][j] = 1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                    maxArea = max(maxArea,dp[i][j]);
                }
            }
        }
        return maxArea*maxArea;
    }
};

int main(){
    FAST_IO;
    int rows,cols;cin>>rows>>cols;
    vector<vector<char>>v(rows,vector<char>(cols));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>v[i][j];
        }
    }
    Solution s;
    cout<<s.maximalSquare(v)<<"\n";
    return 0;
}
