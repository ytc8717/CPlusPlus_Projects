//
// Created by Yun-Ting Chen on 4/20/2020.
//
// This is the implementation for binary search tree(BST)
//

#include "BST.h"

/*
 * read the file to load the data to vector
 */
void BST::readFile(string fileName) {
    ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        exit(EXIT_FAILURE);
    }

    int num;
    file >> num;
    while (file) {
        nodes.push_back(num);
        file >> num;
    }
}

/*
 * constructor
 */
BST::BST() {
}

/*
 * used to create new node
 */
BST::Node *BST::create(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->right = temp->left = nullptr;
    return temp;
}

/*
 * add data to tree
 */
void BST::insert(int data) {
    insertHelper(root, data);
}

/*
 * helper function for insert
 */
void BST::insertHelper(BST::Node *&root, int data) {
    if (root == nullptr)
        root = create(data);
    else if (root->data > data)
        insertHelper(root->left, data);
    else insertHelper(root->right, data);
}

/*
 * display tree data
 */
void BST::displayInorder() {
    inorder(root);
}

/*
 * helper function to print tree data (inorder)
 */
void BST::inorder(BST::Node *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

/*
 * helper function to get max height
 */
int BST::maxHeight(BST::Node *root) {
    if (root == nullptr) {
        return 0;
    } else {
        // compute depth of each subtree
        int lDepth = maxHeight(root->left);
        int rDepth = maxHeight(root->right);

        // return larger one
        if (lDepth > rDepth)
            return (lDepth + 1);
        else return rDepth + 1;
    }
}

/*
 * get max height
 */
int BST::getMaxHeight() {
    return maxHeight(root);
}

/*
 * helper function to get min height
 */
int BST::minHeight(BST::Node *root) {
    // if nothing return 0
    if (root == nullptr)
        return 0;
    // if only root node return 1
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    // if left subtree is null, go for right subtree
    if (!root->left)
        return minHeight(root->right) + 1;
    // if right subtree is null, go for left subtree
    if (!root->right)
        return minHeight(root->left) + 1;
        // use the smallest one
    else {
        int lDepth = minHeight(root->left);
        int rDepth = minHeight(root->right);
        if (lDepth < rDepth)
            return lDepth + 1;
        return rDepth + 1;
    }
}

/*
 * get smallest height
 */
int BST::getMinHeight() {
    return minHeight(root);
}

/*
 * helper function for count total nodes in tree
 */
int BST::CountNodes(BST::Node *root) {
    // if nothing return 0
    if (root == nullptr)
        return 0;
    // count the left subtree
    if (root->left != nullptr) {
        count = count + 1;
        count = CountNodes(root->left);
    }
    // count the right subtree
    if (root->right != nullptr) {
        count = count + 1;
        count = CountNodes(root->right);
    }
    return count;
}

/*
 * return total nodes
 */
int BST::getTotalNodes() {
    return CountNodes(root);
}

/*
 * helper function to check if tree is balanced
 */
bool BST::checkBalanced(BST::Node *root) {
    if (!root)
        return true;
    // compute height for right and left subtree
    int leftHt = maxHeight(root->left);
    int rightHt = maxHeight(root->right);

    if (abs(leftHt - rightHt) > 1)
        return false;
    return checkBalanced(root->left) && checkBalanced(root->right);
}

/*
 * check if tree is balanced
 */
bool BST::isBalanced() {
    if (checkBalanced(root))
        cout << "True";
    else
        cout << "False";
    return checkBalanced(root);
}

/*
 * helper function to check if tree is complete
 */
bool BST::checkComplete(BST::Node *root) {
    // if tree is empty return false
    if (root == nullptr)
        return false;
    // create an empty queue and enqueue root node
    list<Node *> queue;
    queue.push_back(root);
    // pointer to store current node
    Node *front = nullptr;
    // to make end of the full nodes
    bool flag = false;
    // if queue is not empty
    while (queue.size()) {
        // pop front node
        front = queue.front();
        queue.pop_front();
        // if encountered a non-full node
        // and current node is not a leaf
        // tree is not complete
        if (flag && (front->left || front->right))
            return false;
        // if left child node is empty & right chile node exists
        // tree is not complete
        if (front->left == nullptr && front->right)
            return false;

        if (front->left)
            queue.push_back(front->left);
        else
            flag = true;

        if (front->right)
            queue.push_back(front->right);
        else
            flag = true;
    }
    return true;
}

/*
 * check if tree is complete
 */
bool BST::isComplete() {
    if (checkComplete(root))
        cout << "True";
    else
        cout << "False";
    return checkComplete(root);
}

/*
 * constructor that takes in the file name to read in
 */
BST::BST(string fileName) {
    readFile(fileName);
    // build up BST
    for (int num:nodes) {
        insert(num);
    }
}

