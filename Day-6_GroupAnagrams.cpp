class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        
        if(strs.size() == 0) return v;
        
        map<string,vector<string>> dict;
        for(string s: strs){
            string sorted = s;
            sort(sorted.begin(),sorted.end());
            dict[sorted].push_back(s);
        }
        map<string,vector<string>>::iterator it;
        for(it=dict.begin();it!=dict.end();it++){
            v.push_back(it->second);
        }
        return v;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = s.groupAnagrams(v);
    for(auto x : ans){
      for(auto y : x){
      cout<<y<<" ";
      }
    cout<<"\n";
    }
    return 0;
}
