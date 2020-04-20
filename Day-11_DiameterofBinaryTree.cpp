#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createNode(int x){
    TreeNode *temp = new TreeNode(x);
    return temp;
}

void insertNode(TreeNode* root,int x){
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        if(temp->left==NULL){
            temp->left  = createNode(x);break;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
            temp->right  = createNode(x);break;
        }
        else{
            q.push(temp->right);
        }
    }
}

TreeNode* createTree(vector<int> &v){
    TreeNode* root = NULL;
    for(auto x : v){
        if(root==NULL){
            root = createNode(x);
        }
        else{
            insertNode(root, x);
        }
    }
    return root;
}

class Solution {
public:
    int ans = INT_MIN;
    int findDia(TreeNode* root){
        if(root==NULL) return 0;
        if(root->right==NULL && root->left==NULL) return 0;
        int leftMax=0;
        if(root->left)
            leftMax = 1 + findDia(root->left);
        int rightMax=0;
        if(root->right)
            rightMax = 1 + findDia(root->right);
        if(ans<leftMax+rightMax){
            ans=leftMax+rightMax;
        }
        return max(leftMax,rightMax);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->right==NULL && root->left==NULL) return 0;
        return max(ans,findDia(root));
    }
};


//driver code
int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<int> v = {1,2,3,4,5,7,9,100,200,200,400,-1}; //{1,2,3,4,5};
    TreeNode *root = createTree(v);
    cout<<s.diameterOfBinaryTree(root)<<"\n";
    return 0;
}
