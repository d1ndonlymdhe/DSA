#include <iostream>
#include <vector>
using namespace std;

class HNode
{
public:
    int value;
    int level;
    HNode *left;
    HNode *right;

    HNode(int v, int level)
    {
        this->value = v;
        this->left = NULL;
        this->right = NULL;
        this->level = level;
    }
    HNode(vector<int> values)
    {
        this->value = values[0];
        this->left = NULL;
        this->right = NULL;
        this->level = 0;
        int maxLevel = 1;
        for (int i = 1; i < values.size(); i++)
        {
            insert(values[i], 1);
        }
    }
    bool insert(int v, int level)
    {

        if (left == NULL)
        {
            left = new HNode(v, level);
            balancer();
            return true;
        }
        else if (right == NULL)
        {
            right = new HNode(v, level);
            balancer();
            return true;
        }
        vector<HNode *> leaves;
        findPartialLeaves(&leaves);
        int l = leaves[0]->level;
        for (int i = 1; i < leaves.size(); i++)
        {
            if (leaves[i]->level < l)
            {
                leaves[i]->insert(v, leaves[i]->level + 1);
                balancer();
                return true;
            }
        }
        leaves[0]->insert(v, leaves[0]->level + 1);
        balancer();
        return false;
    }

    void findPartialLeaves(vector<HNode *> *leaves)
    {
        if (this->left == NULL && this->right == NULL)
        {
            leaves->push_back(this);
            return;
        }
        if (this->left == NULL || this->right == NULL)
        {
            leaves->push_back(this);
        }
        if (this->left)
            this->left->findPartialLeaves(leaves);
        if (this->right)
            this->right->findPartialLeaves(leaves);
    }

    int size(int initSize = 0)
    {
        int s = initSize + 1;
        if (this->left)
        {
            s = this->left->size(s);
        }
        if (this->right)
        {
            s = this->right->size(s);
        }
        return s;
    }

    void balancer()
    {
        if (right)
        {
            if (right->value > value)
            {
                int t = right->value;
                right->value = this->value;
                this->value = t;
            }
            right->balancer();
        }
        if (left)
        {
            if (left->value > value)
            {
                int t = left->value;
                left->value = this->value;
                this->value = t;
            }
            left->balancer();
        }
    }

    void preorder()
    {
        cout << this->value << endl;
        if (this->left)
        {
            this->left->preorder();
        }
        if (this->right)
        {
            this->right->preorder();
        }
    }
};

int main()
{
    HNode *h = new HNode({42, 23, 74, 11, 65, 58, 94, 36, 99, 87});
    h->preorder();
}