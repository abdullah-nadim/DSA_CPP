#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left,*right;
    Node()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
    Node(int a)
    {
        data=a;
        left=NULL;
        right=NULL;
    }
};
class BST
{
public:
    Node *root,*parentptr,*currentptr,*ptr;
    BST()
    {
        root=NULL;
    }
    void insert(int x)
    {
        ptr= new Node(x);
        if(root==NULL)
        {
            root = ptr;
        }
        else
        {
            parentptr=new Node();
            currentptr=root;
            while(currentptr!=NULL)
            {
                parentptr=currentptr;
                if(x<currentptr->data)
                {
                    currentptr=currentptr->left;
                }
                else
                {
                    currentptr=currentptr->right;
                }
            }

            if(x<parentptr->data)
            {
                parentptr->left=ptr;
            }
            else
            {
                parentptr->right=ptr;
            }
        }
    }
    void preOrder(struct Node* node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    bool search(struct Node *node,int x)
    {
        if(node==NULL)
        {
            cout<<x<<" is Not Found\n";
            return false;
        }
        else if(node->data==x)
            {
                cout<<x<<" is Found\n";
                return true;}
        else
        {
            if(x<node->data)
            {
                search(node->left,x);
            }
            else
            {
                search(node->right,x);
            }
        }
    }

Node* inorderSucc(Node* node)
{
    Node* curr = node;
    while(curr && curr->left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}
    Node* deleteNode(struct Node *node, int x)
{

        if(x<node->data)
    {
        node->left=deleteNode(node->left,x);
    }
    else if(x>node->data){
            node->right=deleteNode(node->right,x);

    }
    else
    {
        if(node->left==NULL){
                Node* temp=node->right;
        free(node);
        cout<<x<<" is deleted\n";
        return temp;
    }
    else if(node->right ==NULL)
    {
        Node* temp=node->left;
        free(node);
        cout<<x<<" is deleted\n";
        return temp;
    }
    Node* temp=inorderSucc(node->right);
    node->data=temp->data;
    node->right= deleteNode(node->right,temp->data);
    cout<<x<<" is deleted\n";
    }
    return node;
}
/*Node* deleteNode(struct Node* root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else {

        if (root->left == NULL and root->right == NULL)
            return NULL;

        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
    }
}*/
};

int main()
{
    BST b;
    int no,value;
    char y='y';
    while(y=='y'||y=='Y')
        {
     cout<<"What do you want to do?\n1. Insert \n2. Search\n3. Traverse \n4. Delete\n";
     cin>>no;
    switch(no)
    {
    case 1:
        cout<<"Enter the value: \n";
        cin>>value;
        b.insert(value);
        break;
    case 2:
        cout<<"Enter the value: \n";
        cin>>value;
        b.search(b.root,value);
        break;
    case 3:
         b.preOrder(b.root);
        break;
    case 4:
        cout<<"Enter the value: \n";
        cin>>value;
        if(b.search(b.root,value)==true)
        {
            b.deleteNode(b.root,value);
            break;}
        else{
            cout<<"Can't delete\n";
            break;
            }

    default:
        cout<<"Invalid Input\n";
    }
    cout<<"\nDo you wanna continue?(y/n)\n";
    cin>>y;
        }
}
