#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void insertNode(TreeNode* root,int x){
        if(x < root->val){
            if(root->left == NULL){
                root->left = createNode(x);
            }
            else{
                insertNode(root->left, x);
            }
        }
        else{
            if(root->right == NULL){
                root->right = createNode(x);
            }
            else{
                insertNode(root->right, x);
            }
        }
    }
    TreeNode* createNode(int x){
        TreeNode *temp = new TreeNode(x);
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& v) {
        TreeNode *root = NULL;
        for(auto val : v){
            if(root==NULL){
                root = createNode(val);
            }
            else{
                insertNode(root,val);
            }
        }
        return root;
    }
    void Print(TreeNode* root){
        if(root!=NULL){
            cout<<root->val<<" ";
            Print(root->left);
            Print(root->right);
        }
        else{
            cout<<"NULL ";
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector< int >v = {8,5,1,7,10,12};
    TreeNode* root = s.bstFromPreorder(v);
    s.Print(root);
    return 0;
}
