//
// Created by Yun-Ting Chen on 1/13/2020.
//
// This class represent a library system with base of 100 books capacity
//

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <string>

// Only for class code, OK to use namespace
using namespace std;

static const int MAX = 100;

// Library holds books - can add, remove and list books
class Library {
    // display all books in library
    friend ostream &operator<<(ostream &Out, const Library &Lib);

public:
    // constructor with default name
    explicit Library(const string &Name);

    // destructor
    virtual ~Library();

    // add a new book
    // return true if successful, false if
    // book already in library
    bool addBook(const string &BookName);

    // remove a book
    // return true if successfully removed
    // false if book not in library
    bool removeBook(const string &BookName);

    // list all books
    void listAllBooks() const;

    // true if book found in library
    bool isInLibrary(const string &BookName) const;

private:
    string libraryName;
    int numberOfBooks;
    string books[MAX]; // array of books

    // method to find book in the array
    int findBook(const string& name)const ;
};

#endif  // ASS1_LIBRARY_H
