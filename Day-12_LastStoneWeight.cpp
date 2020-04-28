#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==2){
            return abs(stones[1]-stones[0]);
        }
        sort(stones.begin(),stones.end());
        //cout<<"sorted\n";
        while(stones.size()>1){
            if(stones.size()==1) break;
            int y=stones.back();
            stones.pop_back();
            int x=stones.back();
            stones.pop_back();
            //cout<<"x="<<x<<" y="<<y<<"\n";
            if(x!=y){
                //cout<<"x!=y therefore pushing "<<y-x<<"\n";
                stones.push_back(y-x);
                sort(stones.begin(),stones.end());
            }
            if(stones.size()==2){
            return abs(stones[1]-stones[0]);
        }
            if(stones.size()==1) break;
        }
        return stones[0];
    }
};

//driver code
int main(){
    FAST_IO;
    Solution s;
    vector<int> v = {2,7,4,1,8,1};
    cout<<s.lastStoneWeight(v)<<"\n";
    return 0;
}
