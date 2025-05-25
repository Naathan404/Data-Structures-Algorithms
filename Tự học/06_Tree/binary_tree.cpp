#include <iostream>
using namespace std;

struct Tree
{
    int data;
    Tree* left;
    Tree* right;
};

Tree* makeNode(int value)
{
    Tree* newNode = new Tree;
    if(newNode == NULL)
        return NULL;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// struct Tree
// {
//     Tree* root = NULL;
// };
void AddNode(Tree*& root)
{

}

void Preorder(Tree* root)
{
    int cunt = 0;
    if(root != NULL)
    {
        cunt++;
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main()
{
    

    return 0;
}