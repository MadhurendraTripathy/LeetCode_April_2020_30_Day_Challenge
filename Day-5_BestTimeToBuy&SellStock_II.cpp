#inclue<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                prof+=(prices[i]-prices[i-1]);
            }
        }
        return prof;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<int> v = {7,1,5,3,6,4};
    s.maxProfit(v);    
    return 0;
}
