#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("Test 1 : Fraction Constructer :- "){
    //throws an exception
    CHECK_THROWS(Fraction(1,0));
    //(-2/2)=-1
    CHECK_NOTHROW(Fraction(-2,2));
    //(8/4)=2
    Fraction a(8,4);
    CHECK(a==2);
    //(-8/-4)=2
    CHECK_NOTHROW(Fraction(-8,-4));
    //(1/3)=1/3
    Fraction f0(1,3);
    CHECK(f0 == Fraction(1,3));
    //(-1/3)=-1/3
    Fraction f1(-1,3);
    CHECK(f1 == Fraction(-1,3));
    //(1/-3)=-1/3
    Fraction f2(1,-3);
    CHECK(f2 == Fraction(1,-3));
}
TEST_CASE("Test 2 : Check reduce() func :- "){
    Fraction t(18,9);
    CHECK(t==2);

    Fraction s(6,5);
    CHECK(s==1.2);

    Fraction z(-18,9);
    CHECK(z==-2);

    Fraction w(-6,5);
    CHECK(w==-1.2);

    Fraction y(18,-9);
    CHECK(y==-2);

    Fraction x(6,-5);
    CHECK(x==-1.2);

    Fraction a(0,8);
    CHECK(a==0);

    Fraction b(0,-8);
    CHECK(b==0);

}
TEST_CASE("Test 3 : ++ & -- & += & -= & /= & *= "){
    Fraction f8(1,2);
    Fraction f9(1,10);
    //return 1.5
    CHECK(++f8==1.5);
    //return 1/2
    CHECK(f8++ ==0.5);
    //return (-0.9)
    CHECK(--f9 == -0.9);
    //return (0.1)
    CHECK(f9-- == 0.1);
    f8+=f9;
    CHECK(f8==Fraction(3,5));
    f8-=f9;
    CHECK(f8==Fraction(1,2));
    f8*=f9;
    CHECK(f8==Fraction(1,20));
    f8/=f9;
    CHECK(f8==Fraction(1,2));
}

TEST_CASE("Test 4 : operators (+) (-) (*) (/) (==) "){
    Fraction x(1,4);
    Fraction y(1,8);
    CHECK(x+x==0.5);
    CHECK(x+0.5==0.75);
    CHECK(0.5+x==0.75);
    CHECK(y+y==0.25);
    CHECK(y+0.5==0.625);
    CHECK(0.5+y==0.625);
    CHECK(x*x==0.0625);
    CHECK(x*0.5==0.125);
    CHECK(0.5*x==0.125);
    CHECK(x/x==1);
    CHECK(x/0.5==0.5);
    CHECK(0.5/x==2);
    CHECK(x-x==0);
    CHECK(x-0.5==-0.25);
    CHECK(0.5-x==0.25);
    CHECK(x-0.25==0);
    CHECK(x+y == 0.375);
    CHECK(x-y == 0.125);
    CHECK(x*y == 0.03125);
    CHECK(x/y == 2);
    CHECK(x==0.25);
    CHECK_FALSE(x==y);
}

TEST_CASE("Test 5 : Zero Check :- "){
    //(0/-3)=0
    CHECK_NOTHROW(Fraction (0,-3));
    //(0/3)=0
    CHECK_NOTHROW(Fraction (0,3));
    //throws an exception
    CHECK_THROWS(Fraction(2,0));
    Fraction x(0,5);
    CHECK(x==0);
    Fraction y(5,5);
    CHECK(y+0==y);
    CHECK(y*0==y);
    CHECK_THROWS(y/0);
}

TEST_CASE("TEST 6 : Comparison operators : "){
    Fraction x(3,4);
    Fraction y(2,9);
    CHECK((x>y)==true);
    CHECK((x<y)==false);
    CHECK((x>=y)==true);
    CHECK((x<=y)==false);
    CHECK((x==y)==false);
    CHECK((x!=y)==true);
 }
TEST_CASE("Test 7 : I/O operators "){
    Fraction x(2,3);
    Fraction y(3,4);
    CHECK_NOTHROW(cout << x << endl);
    CHECK_NOTHROW(cout << x << endl);
}
