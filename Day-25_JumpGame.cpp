#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& v) {
        int n = (int)v.size();
        int max_location = 0;
        for(int i=0;i<n;i++){
            max_location = max(max_location,(i+v[i]));
            if(max_location == i) break;
        }
        return max_location>=n-1;
    }
};

int main(){
    FAST_IO;
    vector<int>v = {2,3,1,1,4};
    Solution s;
    s.canJump(v)?cout<<"YES\n":cout<<"NO\n";
    return 0;
}
