#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio();cin.tie(NULL);cout.tie(NULL);

class LRUCache {
    int MAX;
    deque<int>q;
    map<int,int>mp;
public:
    LRUCache(int capacity) {
        MAX = capacity;
    }
    
    int get(int key) {
        auto it = find(q.begin(), q.end(), key);
        if(it==q.end()){
            return -1;
        }
        q.erase(it);
        q.push_front(key);
        return mp[key];
    }
    
    void put(int key, int value) {
        auto it = find(q.begin(),q.end(),key);
        if(it==q.end()){
            if(q.size()+1<=MAX){
                q.push_front(key);
                mp[key]=value;
            }
            else{
                int k = q.back();
                q.pop_back();
                mp.erase(k);
                q.push_front(key);
                mp[key] = value;
            }
        }
        else{
            mp[key] = value;
            q.erase(it);
            q.push_front(key);
        }
    }
};
int main(){
    FAST_IO;
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout<<cache->get(1)<<"\n";       // returns 1
    cache->put(3, 3);    // evicts key 2
    cout<<cache->get(2)<<"\n";       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cout<<cache->get(1)<<"\n";       // returns -1 (not found)
    cout<<cache->get(3)<<"\n";       // returns 3
    cout<<cache->get(4)<<"\n";       // returns 4
    return 0;
}
