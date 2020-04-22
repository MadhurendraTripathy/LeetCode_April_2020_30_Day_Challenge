#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio();cin.tie(NULL);cout.tie(NULL);

class Solution {
public:
    int subarraySum(vector<int>& v, int K) {
        map<int,int>mp;
        int count = 0,sum=0;
        int n = (int)v.size();
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(sum == K){
                count++;
            }
            if(mp.find(sum-K)!=mp.end()){
                count+=mp[sum-K];
            }
            mp[sum]++;
        }
        return count;
    }
};

int main(){
    FAST_IO;
    int k = 2;
    vector<int> v;
    v={1,1,1};
    Solution s;
    cout<<s.subarraySum(v, k)<<"\n";
    return 0;
}
