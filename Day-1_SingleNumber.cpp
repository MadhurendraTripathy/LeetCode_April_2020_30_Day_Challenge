class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int exor = nums[0];
        for(int i=1;i<(int)nums.size();i++){
            exor^=nums[i];
        }
        return exor;
    }
};
//driver code
int main(){
	ios_base::sync_with_stdio();//faster io
	cin.tie(NULL);
	cout.tie(NULL);
	Solution s;
	vector<int>nums = {4,1,2,1,2};
	cout<<s.singleNumber(v)<<"\n";
	return 0;
}
