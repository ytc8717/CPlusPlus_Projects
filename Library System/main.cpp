//
// Created by Yun-Ting Chen 1/13/2020
//
// This is the driver class for Library class
// used to test the functions within the Library class
//

#include "library.h"

#include <cassert>
#include <iostream>


using namespace std;

void test1() {
    // add library
    Library Libs("UWB");
    Library Lib2("CSS");
    Library Lib3("Stem");

    // add books
    Libs.addBook("Don Quixote");
    Libs.addBook("In Search of Lost Time");
    Libs.addBook("Ulysses");
    Libs.addBook("The Odyssey");

    Lib2.addBook("Book1");

    // list all books in library
    Libs.listAllBooks();
    Lib2.listAllBooks();
    Lib3.listAllBooks();

    cout << endl;

    // display library info
    // test overload method
    cout << Libs << endl;
    cout << Lib2 << endl;
    cout << Lib3 << endl;

    // should generate already in library message and return true
    bool Result = Libs.isInLibrary("The Odyssey");
    assert(Result);

    // cannot add book twice, result should be false
    Result = Libs.addBook("The Odyssey");
    assert(!Result);

    // test remove, result should be true
    Result = Libs.removeBook("The Odyssey");
    assert(Result);

    // not in library, result should be false
    Result = Libs.isInLibrary("The Odyssey");
    assert(!Result);

    // cannot remove twice, result should be false
    Result = Libs.removeBook("The Odyssey");
    assert(!Result);
}

void testAll() {
    test1();
    cout << "Successfully completed all tests." << endl;
}

// main driver to test all methods
int main() {
    testAll();
    return 0;
}