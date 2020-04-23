#define<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ull rangeBitwiseAnd(ull m, ull n) {
        if(m==0){
            return 0;
        }
        if(m==n) return m;
        int count = 0;
        while(m!=n){
            n>>=1;
            m>>=1;
            count++;
            cout<<m<<" "<<n<<"\n";
        }
        return m<<count;
    }
};
int main(){
    ios_base::sync_with_stdio();cin.tie(NULL);cout.tie(NULL);
    ull m,n;
    cin>>m>>n;
    Solution s;
    cout<<s.rangeBitwiseAnd(m, n)<<"\n";
    return 0;
}
