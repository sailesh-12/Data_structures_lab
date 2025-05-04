#include <iostream>
#include <vector>
#include <queue>
#include<stack>
using namespace std;

class Tree {
private:
    struct Node {
        Node *left;
        int data;
        Node *right;
    };

public:
    Node *root;
    string expression;

    Tree() {
        root = NULL;
        expression="";
    }
    
    Node* create();
	void inorderdisplay(Node *root);
    void preorderdisplay(Node *root);
    void postorderdisplay(Node *root);
    vector<vector<int>> levelorderdisplay(Node *root);
    void search(int n, Node *root);
    void constructExpressionTree(string expression);
    void deletionInBinarytree(Node *root,int key);
};

Tree::Node* Tree::create() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node *newnode = new Node();  // Use `new` instead of `malloc`
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    cout << "Enter the left child of " << data << endl;
    newnode->left = create();

    cout << "Enter the right child of " << data << endl;
    newnode->right = create();

    return newnode;
}



void Tree::deletionInBinarytree(Node *root, int key)
{
    if(root==NULL){
        cout<<"Element is not found"<<endl;
        return;
    }
    if(root->left->data == key){
        if(root->left->left==NULL){
            root->left=root->left->right;
            return;
        }
        else{
            root->left=root->left->left;
            return;
        }
    }
    if(root->right->data == key){
        if(root->right->right==NULL){
            root->right=root->right->left;
            return;
        }else{
            root->right=root->right->right;
            return;
        }
    }
    deletionInBinarytree(root->left,key);
    deletionInBinarytree(root->right,key);

}
void Tree::constructExpressionTree(string expression) {
    stack<Node*> st;
    for (char ch : expression) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            Node* node = new Node();
            node->data = ch;
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
            st.push(node);
        } else {
            Node* node = new Node();
            node->data = ch ;
            node->left = NULL;
            node->right = NULL;
            st.push(node);
        }
    }
    root = st.top();
}
void Tree::preorderdisplay(Node *root)
{
    if (root == NULL) 
    {
        return ;
    }
    cout<<root->data<<" ";
    preorderdisplay(root->left);
    preorderdisplay(root->right);
}
void Tree::postorderdisplay(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderdisplay(root->left);
    postorderdisplay(root->right);
    cout<<root->data<<" ";
}
void Tree::inorderdisplay(Node *root) {
	if (root == NULL) {
		return;
	}
	inorderdisplay(root->left);
	cout << root->data << " ";
	inorderdisplay(root->right);
}

vector<vector<int>> Tree::levelorderdisplay(Node *root) {
    queue<Node *> qu;
    vector<vector<int>> res;
    if(root == NULL) {
        return res;
    }
    qu.push(root);
    int max=INT32_MIN;
    while(!qu.empty())
    {
        int size = qu.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            Node *node=qu.front();
            qu.pop();
            if(max<node->data)
            {
                max=node->data;
            }
            if(node->left!=NULL) {
                qu.push(node->left);
            }
            if(node->right!=NULL) {
                qu.push(node->right);
            }
            level.push_back(node->data);
        }
        res.push_back(level);
    }
    cout<<max<<endl;
    return res;
}

void Tree::search(int n, Node *root) {
    Node *temp = root;
    //Using Inorder Traversal
    if(root==nullptr)
    {
        return;
    }else{
        search(n,root->left);
        if(root->data==n)
        {
            cout<<"Element found";
            return;
        }
        search(n,root->right);
    }

}
int main()
{
    Tree t;
    int ch;

    while (true) {
        cout << "\n1. Create Tree\n2. Display Inorder\n3. Display Preorder\n4. Display Postorder\n5. Display Levelorder\n6. Search\n7. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                t.root = t.create(); 
                break;

            case 2:
                cout << "Inorder Traversal: ";
                t.inorderdisplay(t.root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                t.preorderdisplay(t.root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                t.postorderdisplay(t.root);
                cout << endl;
                break;
            case 5:
                {
                    vector<vector<int>> res1 = t.levelorderdisplay(t.root);
                    cout << "Level Order Traversal: " << endl;
                    for (int i = 0; i < res1.size(); i++) {
                        for (int j = 0; j < res1[i].size(); j++) {
                            cout << res1[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;

            case 6:
                int n;
                cout << "Enter the element to be searched: ";
                cin >> n;
                t.search(n,t.root);
                return 0;

            case 7:
                cout << "Enter the element to be deleted: ";
                cin >> n;
                t.deletionInBinarytree(t.root,n);
                cout << "Binary Tree deleted successfully." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
                break;
                exit(0);
        }
    }

    return 0;
}