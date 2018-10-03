
#include <iostream>
using namespace std;
#include <queue>

template <class T>
class TreeNode
{
    public:
        T data;
        TreeNode *left;
        TreeNode *right;
    public:
        TreeNode(T data)
        {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

template <class T>
class Tree
{
    private:
        TreeNode<T> * root;
    public:
        Tree();
        void insert(T value);
        void BFS()const;
        //void preOrder()const;
        //void inOrder()const;
        //void postOrder()const;
        ~Tree();
};

template<class T>
Tree<T>::Tree()
{
    this -> root = NULL;
}

template<class T>
Tree<T>::~Tree()
{
    
}

template<class T>
void Tree<T>::insert(T value)
{
    if (!this -> root) 
        this -> root = new TreeNode<T>(value);
    else
    {
        queue<TreeNode<T> *> Q;
        Q.push(this -> root);
        while(true)
        {
            TreeNode<T> * p = Q.front();
            cout<<"(*) "<<p -> data<<" "<<p -> left<<" "<<p-> right<<endl;
            if(p -> left == NULL)
            {
                p -> left = new TreeNode<T>(value);
                return;
            }else
            {
                Q.push(p->left);
            }
            if(p -> right == NULL)
            {
                p -> right = new TreeNode<T>(value);
                return;
            }else
            {
                Q.push(p->right);
            }
        }
    }
}

template<class T>
void Tree<T>::BFS()const
{
    queue<TreeNode<T> *> Q;
    Q.push(this -> root);
    while(!Q.empty())
    {
        cout<<Q.front() -> data<<" ";
        if(Q.front()->left!=NULL)
            Q.push(Q.front()->left);
        if(Q.front()->right!=NULL)
            Q.push(Q.front()->right);
        Q.pop();
    }
}

int main()
{
	Tree<int> a;

	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);

	a.BFS();
}

