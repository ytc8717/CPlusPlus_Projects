//
// Created by Yun-Ting Chen on 3/11/2020.
//
// this class is represent the implementation for the ThreadedBST
//

#include "TBST.h"

// constructor
TBST::TBST() {
    root = NULL;
}

// insert element to the tree
bool TBST::insert(int key) {
    Node* p = root;
    Node*par = nullptr;
    while (p!= nullptr)
    {
        if(key == (p->data))
        {
            return false;
        }
        par = p;
        if(key < p->data)
        {
            if(p->lthread == false)
                p = p->left;
            else
                break;
        } else{
            if(p->rthread == false)
            {
                p = p->right;
            } else{
                break;
            }
        }
    }
    Node* tmp = new Node();
    tmp->data = key;
    tmp->lthread = true;
    tmp->rthread = true;

    if(par == nullptr)
    {
        root = tmp;
        tmp->left = nullptr;
        tmp->right = nullptr;
    } else if (key < (par->data))
    {
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = false;
        par->left = tmp;
    } else{
        tmp->left = par;
        tmp->right = par->right;
        par->rthread = false;
        par->right = tmp;
    }
    return true;
}

// remove element from tree
bool TBST::remove(int key) {
    Node* par = NULL,*p = root;
    int found = 0;
    while(p!= nullptr)
    {
        if(key == p->data)
        {
            found = 1;
            break;
        }
        par = p;
        if(key < p->data)
        {
            if(p->lthread == false)
                p = p->left;
            else
                break;
        } else{
            if(p->rthread == false)
                p = p->right;
            else
                break;
        }
    }
    if(found == 0)
        return false;
    else if(p->lthread == false && p->rthread == false)
        root = caseC(root,par,p);
    else if(p->lthread == false)
        root = caseB(root,par,p);
    else if(p->rthread == false)
        root = caseB(root,par,p);
    else
        root = caseA(root,par,p);
    return true;
}

// only Right Child (used for remove function)
TBST::Node *TBST::caseA(TBST::Node *root, TBST::Node *par, TBST::Node *ptr) {
    if (par == NULL)
        root = NULL;
    else if (ptr == par->left) {
        par->lthread = true;
        par->left = ptr->left;
    }
    else {
        par->rthread = true;
        par->right = ptr->right;
    }
    free(ptr);
    return root;
}
// only Left Child (used for remove function)
TBST::Node *TBST::caseB(TBST::Node *root, TBST::Node *par, TBST::Node *ptr) {
    Node* child;
    if (ptr->lthread == false)
        child = ptr->left;
    else
        child = ptr->right;
    if (par == NULL)
        root = child;
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;
    Node* s = inSucc(ptr);
    Node* p = inPred(ptr);
    if (ptr->lthread == false)
        p->right = s;
    else {
        if (ptr->rthread == false)
            s->left = p;
    }
    free(ptr);
    return root;
}
// two Children (used for remove function)
TBST::Node *TBST::caseC(TBST::Node *root, TBST::Node *par, TBST::Node *ptr) {
    Node* parsucc = ptr;
    Node* succ = ptr->right;
    while (succ->left != NULL) {
        parsucc = succ;
        succ = succ->left;
    }
    ptr->data = succ->data;
    if (succ->lthread == true && succ->rthread == true)
        root = caseA(root, parsucc, succ);
    else
        root = caseB(root, parsucc, succ);
    return root;
}
// returns inorder successor using left and right children
TBST::Node *TBST::inSucc(TBST::Node *ptr) {
    if (ptr->rthread == true)
        return ptr->right;
    ptr = ptr->right;
    while (ptr->right)
        ptr = ptr->left;
    return ptr;
}
// returns inorder successor using rthread
TBST::Node *TBST::inorderSuccessor(TBST::Node *ptr) {
    if (ptr->rthread == true)
        return ptr->right;
    ptr = ptr->right;
    while (ptr->lthread == false)
        ptr = ptr->left;
    return ptr;
}
// returns inorder predecessor using lthread
TBST::Node *TBST::inPred(TBST::Node *ptr) {
    if (ptr->lthread == true)
        return ptr->right;
    ptr = ptr->left;
    while (ptr->rthread);
    ptr = ptr->right;
    return ptr;
}
// inorder traversal to print out the tree
void TBST::inorder() {
    if (root == NULL)
        cout << "Tree is empty";
    Node* ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = inorderSuccessor(ptr);
    }
}
// search for element in tree
bool TBST::search(int key) {
    Node* p = root;
    while(p!= nullptr)
    {
        if(p->data < key)
        {
            if(p->rthread)
                return false;
            p = p->right;
        } else if (p->data > key)
        {
            if(p->lthread)
                return false;
            p = p->left;
        } else{
            return true;
        }
    }
}
// check of tree is empty
bool TBST::isEmpty() const {
    return (root == NULL);
}
