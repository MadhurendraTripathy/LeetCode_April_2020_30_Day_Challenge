#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int>right(n);
        vector<int>left(n);
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){
            left[i] = nums[i-1]*left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i] = nums[i+1]*right[i+1];
        }
        for(int i=0;i<n;i++){
            nums[i]=left[i]*right[i];
        }
        return nums;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<int> v = {1,2,3,4};
    vector<int> ans;
    ans = s.productExceptSelf(v);
    for(auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}
