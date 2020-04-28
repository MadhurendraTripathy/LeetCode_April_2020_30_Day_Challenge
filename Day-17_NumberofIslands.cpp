#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reduce(vector<vector<char>>&v,int i,int j,int r, int c){
        v[i][j] = '0';
        if(j+1<c){ //right
            if(v[i][j+1]=='1') reduce(v, i, j+1, r, c);
        }
        if(j-1>=0){ //left
            if(v[i][j-1]=='1') reduce(v, i, j-1, r, c);
        }
        if(i-1>=0){ //up
            if(v[i-1][j]=='1') reduce(v, i-1, j, r, c);
        }
        if(i+1<r){ //bottom
            if(v[i+1][j]=='1') reduce(v, i+1, j, r, c);
        }
}
    int numIslands(vector<vector<char>>& v) {
        if(v.empty()||v[0].empty()){
            return 0;
        }
       int r = (int)v.size();
        int c = (int)v[0].size();
        int count = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(v[i][j]=='1'){
                    count++;
                    reduce(v,i,j,r,c);
                }
            }
        }
        return count;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<vector<char>>v={ {'1','1','1','1','0'},
                            {'1','1','0','1','0'},
                            {'1','1','0','0','0'},
                            {'0','0','0','0','0'} };
    cout<<s.numIslands(v)<<"\n";
    return 0;
}
