#include<bits/stdc++.h>
using namespace std;

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
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<strings> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> ans = s.groupAnagrams(v);
    for(auto x : ans){
      for(auto y : x){
      cout<<y<<" ";
      }
    cout<<"\n";
    }
    return 0;
}

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

