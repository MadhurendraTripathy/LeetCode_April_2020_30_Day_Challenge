#include<bits/stdc++.h>
using namespace std;

class BinaryMatrix {
public:
    vector<vector<int>>v = {{0,0,0,1},{0,0,1,1},{0,1,1,1}};
    int get(int x, int y){
        return v[x][y];
    }
    vector<int> dimensions(){
        return {(int)v.size(),(int)v[0].size()};
    }
};

class Solution {
public:
    int start(int x, int y, BinaryMatrix &bm,int result, int rows,int cols){
        int val = bm.get(x,y);
        if(x==rows-1 && y==0){
            if(val==1){
                result = min(result,y);
            }
            else if(result == cols+1) result = -1;
            else return result;
        }
        //cout<<"v["<<x<<"]["<<y<<"]="<<val<<"\n";
        if(val==1){ // Move Left
            result = min(result,y);
            if(y-1>=0) return start(x,y-1,bm,result,rows,cols);
        }
        
        else{ //    Move Down
            if(x+1<=rows-1) return start(x+1,y,bm,result,rows,cols);
        }
        return result==cols+1?-1:result;
    }
    int leftMostColumnWithOne(BinaryMatrix &bm) {
        int rows,cols;
        rows = bm.dimensions()[0];
        cols = bm.dimensions()[1];
        int result = cols+1;
        int x=0,y=cols-1;
        return start(x,y,bm,result,rows,cols);
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    BinaryMatrix bm;
    cout<<s.leftMostColumnWithOne(bm)<<"\n";
    return 0;
}
