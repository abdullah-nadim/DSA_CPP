#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void postOrder(struct Node* node)
{
    if (node == NULL)
        return;

    postOrder(node->left);

    postOrder(node->right);

    cout << node->data << " ";
}
void inOrder(struct Node* node)
{
    if (node == NULL)
        return;

    inOrder(node->left);

    cout << node->data << " ";

    inOrder(node->right);
}


void preOrder(struct Node* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";

    preOrder(node->left);

    preOrder(node->right);
}
void findChild(struct Node* node,int value)
{
     if(node==NULL)
        return;
     if(node->data==value)
     {
         if(node->left==NULL)
            {cout<<"NO left child.\n";}
         else
            {cout<<"Left child: "<<node->left->data<<endl;}
         if(node->right==NULL)
                {cout<<"NO right child.\n";}
         else
            cout<<"Right child: "<<node->right->data<<endl;
     }
     else
     {
        findChild(node->left,value);
        findChild(node->right,value);
     }

}
void findParent(struct Node *node, int value,int parent)
{
    if(node==NULL)
        return;
    if(node->data==value)
    {
        if(parent==-1)
            cout<<"NO parent. Its the root";
        else
            cout<<"Parent is:"<<parent<<endl;
    }
    else
    {
        findParent(node->left,value,node->data);
        findParent(node->right,value,node->data);
    }
}

int main()
{
    struct Node *root = new Node(11);
    root->left             = new Node(5);
    root->right         = new Node(14);
    root->left->left     = new Node(4);
    root->left->right = new Node(9);

    int no,value;
    char y='y';
    while(y=='y'||y=='Y')
        {
     cout<<"What do you want to do?\n1. Preorder traversal  \n2. Inorder traversal \n3. Postorder traversal \n4. find child\n5. find parent\n";
     cin>>no;
    switch(no)
    {
    case 1:
         cout << "\nPreorder traversal of binary tree is \n";
    preOrder(root);
        break;
    case 2:
       cout << "\nInorder traversal of binary tree is \n";
    inOrder(root);
        break;
    case 3:
         cout << "\nPostorder traversal of binary tree is \n";
        postOrder(root);
        break;
    case 4:
        cout<<"\nEnter the value of node to find child: \n";
        cin>>value;
        findChild(root,value);
        break;
    case 5:
        cout<<"\nEnter the value of node to find Parent: \n";
        cin>>value;
        findParent(root,value,-1);
        break;
    default:
        cout<<"Invalid Input\n";
    }
    cout<<"\nDo you wanna continue?(y/n)\n";
    cin>>y;
        }

    return 0;
}
