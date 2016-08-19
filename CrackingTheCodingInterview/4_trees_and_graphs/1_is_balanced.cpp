#include <algorithm>

struct Node
{
    Node* left;
    Node* right;
};

int getHeight(Node* node, bool& balanced)
{
    if (!node)
    {
        balanced = true;
        return 0;
    }

    bool balancedLeft;
    int heightLeft = getHeight(node->left, balancedLeft);
    bool balancedRight;
    int heightRight = getHeight(node->right, balancedRight);

    balanced = balancedLeft && balancedRight && abs(heightLeft - heightRight) <= 1;
    return std::max(heightLeft, heightRight) + 1;
}

bool isBalanced(Node* root)
{
    bool balanced;
    getHeight(root, balanced);
    return balanced;
}

int main(int argc, char* argv[])
{
    Node* tree1 = new Node{ 
        new Node{ 
            new Node{ 
                new Node{ nullptr, nullptr }, 
                new Node{ nullptr, nullptr } },
            new Node{ 
                new Node{ nullptr, nullptr },
                nullptr } },
        new Node{ 
            new Node{ 
                new Node{ nullptr, nullptr },
                new Node{ nullptr, nullptr } },
            new Node{ 
                new Node{ nullptr, nullptr },
                new Node{ 
                    new Node{ nullptr, nullptr },
                    nullptr } } } }; 

    bool b = isBalanced(tree1);

    Node* tree2 = new Node{ 
        new Node{ 
            new Node{ 
                new Node{ nullptr, nullptr }, 
                new Node{ nullptr, nullptr } },
            new Node{ 
                new Node{ nullptr, nullptr },
                nullptr } },
        new Node{ 
            new Node{ 
                new Node{ nullptr, nullptr },
                new Node{ nullptr, nullptr } },
            new Node{ 
                new Node{ nullptr, nullptr },
                new Node{ 
                    new Node{ new Node{ nullptr, nullptr }, nullptr },
                    nullptr } } } }; 

    b = isBalanced(tree2);

	return 0;
}

