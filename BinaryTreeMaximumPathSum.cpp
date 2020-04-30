#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* CreateNode(int x){
    TreeNode* nn = new TreeNode(x);
    return nn;
}

void insertNode(TreeNode* root,int x){
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        if(temp->left==NULL){
            temp->left  = CreateNode(x);break;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
            temp->right  = CreateNode(x);break;
        }
        else{
            q.push(temp->right);
        }
    }
}

TreeNode* ConstructTree(vector<int> v){
    TreeNode* root=NULL;
    if(v.empty()) return root;
    if(root==NULL){
        root=CreateNode(v[0]);
    }
    if(v.size()==1){
        return root;
    }
    for(int i=1;i<v.size();i++){
        insertNode(root, v[i]);
    }
    return root;
}


class Solution {
    int answer=INT_MIN;
public:
    int dfsTravel(TreeNode* root){
        if(root==NULL) return 0;
        int left_sum = dfsTravel(root->left);
        int right_sum = dfsTravel(root->right);
        answer=max((root->val+left_sum+right_sum),answer);
        return max(0,root->val+max(left_sum,right_sum));
    }
    int maxPathSum(TreeNode* root) {
        dfsTravel(root);
        return answer;
    }
};

int main(){
    FAST_IO;
    vector<int>v={1,4,3,4};
    TreeNode* root = ConstructTree(v);
    Solution s;
    cout<<s.maxPathSum(root)<<"\n";
    return 0;
}
