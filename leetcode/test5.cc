#include<iostream>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
void swap(TreeNode* node1,TreeNode* node2){
    if(!node1 || !node2)
        return;
    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
}
void help(TreeNode* root1,TreeNode* left,TreeNode* root2,TreeNode* right){
    if(!left && !right)
        return;
    if(!left && right){
        root1->left = right;
        root2->right = nullptr;
        help(right,right->left,right,right->right);
    }
    if(left && !right){
        root2->right = left;
        root1->left = nullptr;
        help(left,left->left,left,left->right);
    }
    if(left && right){
        swap(left,right);
        help(left,left->left,right,right->right);
        help(right,right->left,left,left->right);
    }

}
TreeNode* invertTree(TreeNode* root) {
    if(!root )
        return root;
    help(root,root->left,root,root->right);
    return root;
}
int main(){
    TreeNode node3(2);
    TreeNode node1(1);
    node1.left  = nullptr;
    node1.right = &node3;
    invertTree(&node1);
    return 0;
}
