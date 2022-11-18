//
// Created by Yun-Ting Chen on 1/13/2020.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"
#include <iostream>

// constructor with default name
Library::Library(const string &Name) {
    libraryName = Name;
    numberOfBooks = 0;
}

// destructor
// nothing on heap
Library::~Library() {
    // destructor
}

// method to check if book is in library
// true if book found in library
// false if not in library
bool Library::isInLibrary(const string &BookName) const {
    if(findBook(BookName) == -1)
    {
        return false;
    } else{
        return true;
    }
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName) {
    bool result = false;
    if(BookName == "" || numberOfBooks == 100 || isInLibrary(BookName) == true)
    {
        result = false;
    }
    else{
        numberOfBooks++;
        books[numberOfBooks-1] = BookName;
        result = true;
    }
    return result;
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName) {
    bool result = false;
    if(numberOfBooks == 0)
    {
        result = false;
    }
    if(isInLibrary(BookName) == true)
    {
        books[findBook(BookName)] = books[numberOfBooks-1];
        numberOfBooks--;
        result = true;
    }
    return result;
}

// list all books
void Library::listAllBooks() const {
    for(int i = 0; i < numberOfBooks; i++)
    {
        cout << books[i] << endl;
    }
}

// operator overload
// print out the library info and books
ostream &operator<<(ostream &Out, const Library &Lib) {
    Out << Lib.libraryName << ": " << Lib.numberOfBooks << " books" << endl;
    Lib.listAllBooks();
    return Out;
}

// private method that finds books in library
// return -1 if not found
// if found, return index of the book
int Library::findBook(const string &name) const {
    int result = -1;
    for(int i = 0; i < numberOfBooks; i++)
    {
        if(name == books[i])
        {
            result = i;
        }
    }
    return result;
}
