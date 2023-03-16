//
// Created by Yun-Ting Chen on 2/22/2020.
//
// implementations of doubly linked list (SkipList)
//
//

#include <climits>
#include <cstdlib>
#include <iostream>

#include "skiplist.h"

using namespace std;

// print out skiplist levels and elements
ostream &operator<<(ostream &Out, const SkipList &SkipL) {
    SkipList::SNode* curr = nullptr;
    for (int i{SkipL.Depth - 1}; i >= 0; i--) {
        Out << "Level: " << i << " -- ";
        curr = SkipL.FrontGuards[i];
        while (curr != nullptr) {
            Out << curr->Data << ", ";
            curr = curr->Next;
        }
        Out << std::endl;
    }
    return Out;
}

// SNode constructor
SkipList::SNode::SNode(int Data) : Data(Data){
    this->Next = nullptr;
    this->Prev = nullptr;
    this->UpLevel = nullptr;
    this->DownLevel = nullptr;
}

// Constructor - creates rear and front guards
SkipList::SkipList(int Depth) : Depth(Depth){
    FrontGuards = new SNode *[Depth];
    RearGuards = new SNode *[Depth];

    FrontGuards[0] = new SNode(INT_MIN);
    RearGuards[0] = new SNode(INT_MAX);
    FrontGuards[0]->Next = RearGuards[0];
    RearGuards[0]->Prev = FrontGuards[0];

    for (int i{1}; i < Depth; i++) {
        // Create nodes
        FrontGuards[i] = new SNode(INT_MIN);
        RearGuards[i] = new SNode(INT_MAX);

        // Set nodes down level
        FrontGuards[i]->DownLevel = FrontGuards[i - 1];
        RearGuards[i]->DownLevel = RearGuards[i - 1];

        // Set last nodes up level
        FrontGuards[i - 1]->UpLevel = FrontGuards[i];
        RearGuards[i - 1]->UpLevel = RearGuards[i];

        // Set nodes next and prev
        FrontGuards[i]->Next = RearGuards[i];
        RearGuards[i]->Prev = FrontGuards[i];
    }
}

// 50% it returns true or false
bool SkipList::alsoHigher() const {
    return rand() % 2 == 1;
}

// add data to list
// return true if success
// no duplicate
bool SkipList::add(int Data) {
    // make new node with data
    SNode* newNode = new SNode(Data);
    // node for adding to other layers
    SNode* higher;
    // cannot add if it is already in list
    if (contains(Data)) {
        cout << "Duplicate";
        return false;
    }
        // cannot add int min and int max since they are already the guards
    else if (Data == INT_MIN || Data == INT_MAX) {
        return false;
    } else {
        int level = 0;
        // add to level 0
        addBefore(newNode, findNext(Data, level));
        level++;
        // add to upper levels based on coin flip
        // level should be 1 at this point
        while (alsoHigher() && level < Depth) {
            higher = new SNode(Data);
            addBefore(higher, findNext(Data, level));
            higher->DownLevel = newNode;
            newNode->UpLevel = higher;
            newNode = higher;
            level++;
        }
    }
    return true;
}

// Adds a new node before the current node
void SkipList::addBefore(SkipList::SNode *NewNode, SkipList::SNode *NextNode) {
    NewNode->Prev = NextNode->Prev;
    NewNode->Next = NextNode;
    NextNode->Prev->Next = NewNode;
    NextNode->Prev = NewNode;
}

// Destructor
SkipList::~SkipList() {
    SNode *curr = FrontGuards[0]->Next;
    SNode *nextNode;
    while (curr != RearGuards[0]) {
        nextNode = curr->Next;
        this->remove(curr->Data);
        curr = nextNode;
    }
    for (int i{0}; i < Depth; i++) {
        delete FrontGuards[i];
        delete RearGuards[i];
    }
    delete[] FrontGuards;
    delete[] RearGuards;
}

// return true if successfully removed
bool SkipList::remove(int Data) {
    if (!this->contains(Data)) {
        return false;
    }
    int level{Depth - 1};
    SNode *curr;
    while (level >= 0) {
        curr = FrontGuards[level];
        while (curr != nullptr) {
            if (curr->Data == Data) {
                SNode *next = curr->Next;
                SNode *prev = curr->Prev;
                next->Prev = prev;
                prev->Next = next;
                delete curr;
                curr = next;
            }
            curr = curr->Next;
        }
        level--;
    }
    return true;
}

// return true if found in
bool SkipList::contains(int Data) {
    return(find(Data) != nullptr);
}

// gets the node with specified Data in the given level
// pre-condition: node is in the list. Data, level
// post-condition: finds next item in list
SkipList::SNode *SkipList::findNext(int Data, int level) const {
    // start at top left
    SNode *current = FrontGuards[Depth - 1];
    int currentLevel = Depth - 1;
    while (current->Next != RearGuards[0]) {
        // if greater than next, make current next
        if (Data > current->Next->Data) {
            current = current->Next;
        } else if (current->Next->Data > Data) {
            // checks if the level is at level specified
            if (currentLevel == level) {
                // returns the next node for that level
                return current->Next;
            } else {
                current = current->DownLevel;
                currentLevel--;
            }
        } else if (current->DownLevel != nullptr) {
            current = current->DownLevel;
            currentLevel--;
        } else {
            return current->Next;
        }
    }
    return current->Next;
}

// finds the node with specified Data (top layer).
// returns nullptr if there is no such node
// pre-condition: node is in list
// post-condition: node is found
SkipList::SNode *SkipList::find(int Data) const{
    // start at top left
    SNode* current = FrontGuards[Depth - 1];
    // stops at bottom right
    while (current != RearGuards[0]) {
        // return node if it has correct Data
        if (current->Data == Data) {
            return current;
            // if Data is greater than next AND it is not rearguard, go to next
        } else if (Data >= current->Next->Data && current->Next->Data != INT_MAX) {
            current = current->Next;
            // if there is something below, go to it
        } else if (current->DownLevel != nullptr) {
            current = current->DownLevel;
        } else {
            current = RearGuards[0];
        }
    }
    return nullptr;
}
