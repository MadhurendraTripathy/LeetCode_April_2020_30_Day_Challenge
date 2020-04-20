#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int low=0,high = (int)(nums.size())-1;
        int first = nums[0];
        while(low<=high){
            int mid = low+(high-low)/2;
            int value = nums[mid];
            if(value == target){
                return mid;
            }
            bool current_isbig = value>=first;
            bool target_isbig = target>=first;
            if(current_isbig == target_isbig){
                if(value<target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(current_isbig){
                    low = mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    int target = 0;
    vector<int> v = {4,5,6,7,0,1,2};
    cout<<s.search(v, target)<<"\n";
    return 0;
}
