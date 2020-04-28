#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
set<int>st;
bool isHappy(int n) {
    cout<<n<<endl;
        if(st.find(n)!=st.end()){
            set<int>::iterator it;
            // cout<<"set elements are : ";
            // for(it = st.begin();it!=st.end();it++){
            //     cout<<*it<<endl;
            // }
            // cout<<n<<" found in set, terminating and returning false"<<endl;
            return false;
        }
        else if(n==1){
            // cout<<" found n=1,terminating and returning true"<<endl;
            return true;
        } 
        else if(n/10==0){
            // cout<<"n = "<<n<<" is a single digit so passing "<<n*n<<endl;
            int num = n*n;
            st.insert(n);
            return isHappy(num);
        } 
        else{
            int n_copy = n;
            int num=0;
            while(n>0){
                num+=(pow(n%10,2));
                n/=10;
            }
            // cout<<"n = "<<n<<" is a mutidigit digit so passing "<<num<<endl;
            st.insert(n_copy);
            return (isHappy(num));
        }
}
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    int n = 19;
		cout<<s.isHappy(n)<<"\n";
    return 0;
}
