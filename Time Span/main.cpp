//
// Created by Yun-Ting Chen on 1/26/2020.
//
// Created by Yun-Ting Chen on 1/26/2020.
//
// This class (driver class) is used to test out all the functions in TimeSpan class.
//

#include "timespan.h"
#include <cassert>
#include <sstream>

using namespace std;

// testing constructor
void test1() {
    TimeSpan ts(1, 20, 30);
    stringstream ss;
    ss << ts;
    assert(ss.str() == "1:20:30");

    TimeSpan ts2(4, -20, -90);
    ss.str("");
    ss << ts2;
    assert(ss.str() == "3:38:30");

    TimeSpan ts3(1.5, 30.5, -90);
    ss.str("");
    ss << ts3;
    assert(ss.str() == "1:59:00");

    TimeSpan ts4(0, 0.07, 0);
    ss.str("");
    ss << ts4;
    assert(ss.str() == "0:00:04");

    TimeSpan ts5(0, 0, 60.5);
    ss.str("");
    ss << ts5;
    assert(ss.str() == "0:01:00");

    TimeSpan ts6(0, 0, 61.5);
    ss.str("");
    ss << ts6;
    assert(ss.str() == "0:01:01");

    TimeSpan ts7(1.5, -10, 93);
    ss.str("");
    ss << ts7;
    assert(ss.str() == "1:21:33");

    TimeSpan ts8(1.5);
    ss.str("");
    ss << ts8;
    assert(ss.str() == "1:30:00");

    TimeSpan ts9(0, -1, -43);
    ss.str("");
    ss << ts9;
    assert(ss.str() == "-0:01:43");

    TimeSpan ts10(-1.5, 10, -93);
    ss.str("");
    ss << ts10;
    assert(ss.str() == "-1:21:33");
}

// testing equality, addition, subtraction, multiplication
void test2() {
    TimeSpan ts(1, 20, 30);
    TimeSpan ts2(1, 20, 30);
    TimeSpan ts3(0, 0, 0);
    assert(ts == ts2);
    assert(!(ts != ts2));
    assert(ts != ts3);
    assert((ts + ts + ts) == (ts2 * 3));
    assert((ts * 5) == (ts2 * 4) + ts2);
    assert((ts * 5) == (ts2 * 6) - ts2);
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    assert((ts - ts2) == ts3);
    assert((ts3 * 5) == ts3);
}

// Broken test
void test3() {
    TimeSpan ts0(0, 0, 0);
    TimeSpan ts1(0, 0, 1);
    TimeSpan ts2 = ts0 - ts1;
    stringstream ss;
    ss << ts2;
    assert(ss.str() != "-1:59:59");
    assert(ss.str() == "-0:00:01");
}

// test greater, less, greater or equal, less or equal operators
void test4()
{
    TimeSpan ts(1, 2, 3);
    TimeSpan ts2(-1,-2,-3);
    TimeSpan ts3(1,2,3);
    assert(ts > ts2);
    assert(ts2 < ts);
    assert(!(ts < ts2));
    assert(ts2 <= ts);
    assert(ts >= ts2);
    assert(ts >= ts3);
    assert(ts <= ts3);
}

void test5()
{
    cout << "*************** Operator Test **************" << endl;
    TimeSpan ts(1, 0, 0);
    TimeSpan ts2(0, 1, 0);
    cout << ts << " and " << ts2 << endl;
    cout << "Expected: 1:00:00 and 0:01:00" << endl;
    ts += ts2;
    cout << ts << " expecting 1:01:00 "<< endl;
    stringstream ss;
    ss << ts;
    assert(ss.str() == "1:01:00");
    ts -= ts2;
    ts -= ts2;
    ss << ts;
    cout << ts << " expecting 0:59:00" << endl;
    assert(ss.str() == "0:59:00");
}

// test all tests
void testAll() {
    test1();
    test2();
    test3();
    test4();
    test5();
}

// driver main function
int main() {
    testAll();
    cout << "Passed all tests. Done." << std::endl;
    return 0;
}