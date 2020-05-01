#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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
public:
    bool compareByDFSTravel(TreeNode* root,int idx , vector<int>& arr){
        if(root==NULL){
            return false;
        }
        if(idx>=arr.size()||root->val!=arr[idx]){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            return ((arr[idx]==root->val) && (idx==arr.size()-1));
        }
        bool left_tree = compareByDFSTravel(root->left,idx+1,arr);
        bool right_tree = compareByDFSTravel(root->right,idx+1,arr);
        return (left_tree||right_tree);
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return compareByDFSTravel(root,0,arr);
    }
};

int main(){
    FAST_IO;
    vector<int>v={8,3,NULL,2,1,5,4};
    vector<int> v1= {8};
    TreeNode* root = ConstructTree(v);
    Solution s;
    cout<<s.isValidSequence(root, v1)<<"\n";
    return 0;
}
