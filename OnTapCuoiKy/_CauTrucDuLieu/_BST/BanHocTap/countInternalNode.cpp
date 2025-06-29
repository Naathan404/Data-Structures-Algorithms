#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int CountInternalNode(TreeNode* T)
{
    if(!T) return 0;
    if(!T->left && !T->right) return 0;
    return 1 + CountInternalNode(T->left) + CountInternalNode(T->right);
}

int main()
{

}