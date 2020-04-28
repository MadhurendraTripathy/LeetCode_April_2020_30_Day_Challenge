#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=max){
                max=sum;
                //cout<<max;
            }
            if(sum<0){
                sum=0;   
            }
        }
        return max;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<int>v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(v)<<"\n";
    return 0;
}
