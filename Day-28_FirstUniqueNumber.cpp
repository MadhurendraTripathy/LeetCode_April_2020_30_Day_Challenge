#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class FirstUnique {
public:
    list<int>l;
    map<int, int>mp;
    FirstUnique(vector<int>& nums) {
        for(int n : nums){
            mp[n]++;
            l.push_back(n);
        }
    }
    
    int showFirstUnique() {
        
        while(!l.empty() && mp[l.front()]>1){
            l.pop_front();
        }
        
        if(l.empty()) return -1;
        
        return l.front();
    }
    
    void add(int n) {
        mp[n]++;
        if(mp[n]==1){
            l.push_back(n);
        }
    }
};

int main(){
    FAST_IO;
    vector<int> nums = {2,3,5};
    FirstUnique* obj = new FirstUnique(nums);
    cout<<obj->showFirstUnique()<<"\n";
    obj->add(5);
    cout<<obj->showFirstUnique()<<"\n";
    obj->add(2);
    cout<<obj->showFirstUnique()<<"\n";
    obj->add(3);
    cout<<obj->showFirstUnique()<<"\n";
    return 0;
}
