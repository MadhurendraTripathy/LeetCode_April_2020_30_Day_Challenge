#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector< vector<int> >& v) {
        int rows = (int)v.size();
        int cols = (int)v[0].size();
        int dp[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = v[0][0];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i-1>=0 && j-1>=0){
                    dp[i][j] = (v[i][j] + min(dp[i-1][j],dp[i][j-1]));
                }
                else if(i-1>=0 && j-1<0){
                    dp[i][j] = v[i][j]+dp[i-1][j];
                }
                else if(j-1>=0 && i-1<0){
                    dp[i][j] = v[i][j]+dp[i][j-1];
                }
            }
        }
        
        return dp[rows-1][cols-1];
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<vector<int>> v = { {1,3,1},
                              {1,5,1},
                              {4,2,1} };
    cout<<s.minPathSum(v)<<"\n";
    return 0;
}
