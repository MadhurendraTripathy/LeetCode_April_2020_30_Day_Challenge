class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int,int>mp;
        for(int num:arr){
            if(mp.find(num)==mp.end()){
                mp[num]=1;
            }
            else{
                mp[num]++;
            }
        }
        int count=0;
        map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            //cout<<it->first<<" -> "<<it->second<<"\n";
            if(mp.find((it->first)+1)!=mp.end()){
                count+=(it->second);
            }
        }
        return count;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<int> v = {1,3,2,3,5,0};
    cout<<s.countElements(v)<<"\n";
    return 0;
}

