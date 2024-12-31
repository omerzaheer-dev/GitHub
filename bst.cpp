#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

    bool search(int value) {
        return searchRec(root, value);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

    Node* findMin() {
        return findMinRec(root);
    }

    Node* findMax() {
        return findMaxRec(root);
    }

    int height() {
        return heightRec(root);
    }

    bool isEmpty() {
        return root == nullptr;
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    Node* deleteRec(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteRec(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRec(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMinRec(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    bool searchRec(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value < node->data) {
            return searchRec(node->left, value);
        } else if (value > node->data) {
            return searchRec(node->right, value);
        }
        return true;
    }

    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    void preorderRec(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    void postorderRec(Node* node) {
        if (node != nullptr) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }

    Node* findMinRec(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* findMaxRec(Node* node) {
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    int heightRec(Node* node) {
        if (node == nullptr) {
            return -1;
        }
        int leftHeight = heightRec(node->left);
        int rightHeight = heightRec(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    BinarySearchTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(13);
    tree.insert(18);

    cout << "In-order Traversal: ";
    tree.inorder();

    cout << "Pre-order Traversal: ";
    tree.preorder();

    cout << "Post-order Traversal: ";
    tree.postorder();

    cout << "Search 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    cout << "Minimum value in BST: " << tree.findMin()->data << endl;
    cout << "Maximum value in BST: " << tree.findMax()->data << endl;

    cout << "Height of the tree: " << tree.height() << endl;

    cout << "Is the tree empty? " << (tree.isEmpty() ? "Yes" : "No") << endl;

    tree.deleteNode(15);
    cout << "After deleting 15, In-order Traversal: ";
    tree.inorder();

    tree.deleteNode(5);
    cout << "After deleting 5, In-order Traversal: ";
    tree.inorder();

    return 0;
}
