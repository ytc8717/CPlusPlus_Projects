//
// Created by Yun-Ting Chen on 2/22/2020.
//
// Driver class to test all the functions
//

#include "skiplist.h"
#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

int TotalPassed = 0;
int TotalTests = 0;

template <typename T> string isOK(const T &got, const T &expected) {
    ++TotalTests;
    if (got == expected) {
        ++TotalPassed;
        return "OK: ";
    } else {
        cout << "    Got   " << got << "\n expected " << expected << endl;
        return "ERR: ";
    }
}

void test02() {
    SkipList Skip(3);
    stringstream Ss;
    Ss << Skip;
    cout << isOK(Ss.str(), "Level: 2 -- -2147483648, 2147483647, \n"s +
                           "Level: 1 -- -2147483648, 2147483647, \n"s +
                           "Level: 0 -- -2147483648, 2147483647, \n"s)
         << "Empty SkipList of Depth=3" << endl;
    srand(100);
    Skip.add(10);
    Skip.add(30);
    Skip.add(5);
    Skip.add(25);
    Ss.str("");
    Ss << Skip;
    cout << isOK(Ss.str(),
                 "Level: 2 -- -2147483648, 25, 2147483647, \n"s +
                 "Level: 1 -- -2147483648, 5, 10, 25, 30, 2147483647, \n"s +
                 "Level: 0 -- -2147483648, 5, 10, 25, 30, 2147483647, \n"s)
         << "SkipList of Depth=3 with 10, 30, 5, 25" << endl;
    cout << isOK(Skip.contains(10), true) << "Contains 10" << endl;
    cout << isOK(Skip.contains(30), true) << "Contains 30" << endl;
    cout << isOK(Skip.contains(71), false) << "Does not contain 71" << endl;
}

void test01() {
    SkipList Skip;
    stringstream Ss;
    Ss << Skip;
    cout << isOK(Ss.str(), "Level: 0 -- -2147483648, 2147483647, \n"s)
         << "Empty SkipList" << endl;
    Skip.add(10);
    Skip.add(30);
    Skip.add(5);
    Skip.add(25);
    Ss.str("");
    Ss << Skip;
    cout << isOK(Ss.str(),
                 "Level: 0 -- -2147483648, 5, 10, 25, 30, 2147483647, \n"s)
         << "Added 10, 30, 5, 25," << endl;
}

void test04() {

    SkipList s(5);

    for (int i = 0; i < 20; ++i) {

        int number = rand() % 100;

        s.add(number);

        cout << "After adding " << number << endl;

        cout << s << endl;

    }

}

int main() {
    cout << "Because of the random nature of SkipList, "
         << "the skip list levels may not match" << endl;
    // Set the random seed for easy debugging
    // NOLINTNEXTLINE
    srand(424242);
    test01();
    test02();
    test04();
    cout << "Passed: " << TotalPassed << "/" << TotalTests << endl;
    return 0;
}
