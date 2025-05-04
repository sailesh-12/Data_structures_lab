#include<iostream>
using namespace std;

class Tree{
    private:
    struct Node{
        struct Node *left;
        int data;
        struct Node *right;
    };
    public:
       struct Node *root;
       Tree()
       {
           root=NULL;
       }
       Node* insertion(Node*,int);
       void inorder(Node*);
       void preorder(Node*);
       void postorder(Node*);
       void search(Node*,int);
};

Tree::Node* Tree::insertion(Node* root,int key)
{
    if(root==NULL)
    {
        Node *newnode=new Node();
        newnode->data=key;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
        return root;
    }
    else{
        if(key < root->data)
        {
            root->left=insertion(root->left,key);
        }
        else{
            root->right=insertion(root->right,key);
        }
    }
    return root;
}
void Tree::inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void Tree::preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void Tree::postorder(Node *root)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void Tree::search(Node *root,int key)
{
        if(root==NULL){
            cout<<"Element is not found"<<endl;
            return;
        }
        if(root->data == key)
        {
            cout<<"Element is Found"<<endl;
            return;
        }
        if(root->data<key)
        {
           
                search(root->right,key);
        }
        else{
            search(root->left,key);
        }
}
int main()
{
    Tree t1;
    while(1)
    {
        int choice,n;
        cout<<"\n1.Insertion\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit"<<endl;
        cout<<"Enter a choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter a value to be inserted\n";
            cin>>n;
            t1.root=t1.insertion(t1.root,n);
            break;
        case 2:
             t1.inorder(t1.root);
             break;
        case 3:
             t1.preorder(t1.root);
             break;
        case 4:
             t1.postorder(t1.root);
             break;
        case 5:
             cout<<"Enter a value to be searched\n";
             cin>>n;
             t1.search(t1.root,n);
             break;
        default:
            cout<<"Invalid Option"<<endl;
            exit(1);
        }
    }
}