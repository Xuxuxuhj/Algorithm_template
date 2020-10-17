//#include<bits/stdc++.h>
#include<vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

//前序遍历
//递归
void preorder1(TreeNode* node)
{
    if(node==nullptr)
        return;
    //do sth.
    preorder1(node->left);
    preorder1(node->right);
}

//非递归
vector<int> preorder2(TreeNode* root)
{
    vector<int> res;
    vector<TreeNode*> call;
    if(root!=nullptr)
        call.push(root);
    while(!call.empty())
    {
        TreeNode* t=call.back();
        call.pop_back();
        if(t!=nullptr)
        {
            if(t->right)
            {
                call.push_back(t->left);
            }
            if(t->left)
            {
                call.push_back(t->right);
            }
            call.push_back(t);
            call.push_back(nullptr);
        }
        else{
            res.push_back(call.back());
            call.pop_back();
        }
    }
    return res;
}
