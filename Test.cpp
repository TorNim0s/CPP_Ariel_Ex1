#include "doctest.h"
#include "mat.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) { // not always work, if i send beack for mat(3,3,'@','|') -> @@@@|@@@@ it will send tru but this isn't true the \n is missing.
	std::erase(input, ' '); // added a test case in the last good tests to show that this is not a good test
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


/*
--------------------------------------
Good cases
--------------------------------------
*/

TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));
	/* Add more test here */
}

TEST_CASE("Test 1"){
    CHECK(mat(9,7, '|', '!') == "|||||||||\n"
								"|!!!!!!!|\n"
								"|!|||||!|\n"
								"|!|!!!|!|\n"
								"|!|||||!|\n"
                                "|!!!!!!!|\n"
                                "|||||||||");
}

TEST_CASE("Test 2"){
    CHECK(mat(1,1, '@', '#') == "@");
}

TEST_CASE("Test 3"){
    CHECK(mat(1,21,'!', '@') == "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!\n"
                                "!");
}

TEST_CASE("Test 4"){
    CHECK(mat(21,1, '>', '^') == ">>>>>>>>>>>>>>>>>>>>>");
}

TEST_CASE("Test 5"){
    CHECK(mat(3, 3, '1', '4') == "111\n"
                                 "141\n"
                                 "111");
}

TEST_CASE("Test 6"){
    CHECK(nospaces(mat(11, 11, '+', '-')) == nospaces(  "+++++++++++\n"
													    "+---------+\n"
													    "+-+++++++-+\n"
													    "+-+-----+-+\n"
													    "+-+-+++-+-+\n"
													    "+-+-+-+-+-+\n"
                                                        "+-+-+++-+-+\n"
                                                        "+-+-----+-+\n"
                                                        "+-+++++++-+\n"
                                                        "+---------+\n"
													    "+++++++++++"));
}

TEST_CASE("Test 7"){
    CHECK(mat(11, 11, '.', '9') ==  "...........\n"
                                    ".999999999.\n"
                                    ".9.......9.\n"
                                    ".9.99999.9.\n"
                                    ".9.9...9.9.\n"
                                    ".9.9.9.9.9.\n"
                                    ".9.9...9.9.\n"
                                    ".9.99999.9.\n"
                                    ".9.......9.\n"
                                    ".999999999.\n"
                                    "...........");
}

TEST_CASE("Test 8"){
    CHECK(mat(5,3, 'z', '&') == "zzzzz\n"
                                "z&&&z\n"
                                "zzzzz");
}

TEST_CASE("Test 9"){
    CHECK(mat(5,5,'#', '#') ==  "#####\n"
                                "#####\n"
                                "#####\n"
                                "#####\n"
                                "#####");
}

TEST_CASE("Test 10"){
    CHECK(mat(7,3,'#', '/') ==  "#######\n"
                                "#/////#\n"
                                "#######");
}

TEST_CASE("Test 11"){
    CHECK(mat(7,3,'/', '\\') ==  "///////\n"
                                "/\\\\\\\\\\/\n"
                                "///////");
}


TEST_CASE("Test 12") {
      CHECK(mat(3, 3, '\0', '@') == "\0\0\0\n"
                                    "\0@\0\n"
                                    "\0\0\0");
}
TEST_CASE("Test 13") {
    CHECK(mat(3, 3, '!', '\n') ==   "!!!\n"
                                    "!\n!\n"
                                    "!!!");
}
TEST_CASE("Test 14") {
    CHECK(mat(3,3 , '\r', '\n') ==  "\r\r\r\n"
                                    "\r\n\r\n"
                                    "\r\r\r");
}

//Test to show that nospace isn't good
TEST_CASE("Nospace not good"){
    CHECK(nospaces(mat(3,3, '!', '@')) == nospaces("!!!!@!!!!")); // get True but the right one isn't what we want.
    CHECK(mat(3,3, '!', '@') != "!!!!@!!!!"); // here we will see that they are not the same without the function nospace therefore this is not the output we want.
}

/*
--------------------------------------
Bad cases
--------------------------------------
*/

TEST_CASE("Test 15") {
    CHECK_THROWS(mat(2, 2, '!', '!')); // cannot get an even number in row or column or both
}

TEST_CASE("Test 16") {
    CHECK_THROWS(mat(2, 4, '!', '^')); // cannot get an even number in row or column or both
}

TEST_CASE("Test 17") {
    CHECK_THROWS(mat(12, 5, '@', '^')); // cannot get an even number in row or column or both
}

TEST_CASE("Test 18") {
    CHECK_THROWS(mat(7, 18, '&', '4')); // cannot get an even number in row or column or both
}

TEST_CASE("Test 19") {
    CHECK_THROWS(mat(-3, 5, '#', '$')); // cannot get a negetive number in row or column or both
}

TEST_CASE("Test 20") {
    CHECK_THROWS(mat(7, -5, '#', '$')); // cannot get a negetive number in row or column or both
}

TEST_CASE("Test 21") {
    CHECK_THROWS(mat(-5, -3, '!', '@')); // cannot get a negetive number in row or column or both
}

TEST_CASE("Test 22") {
    CHECK_THROWS(mat(0, 5, '%', '&')); // cannot give size 0 for column or row or both
}

TEST_CASE("Test 23") {
    CHECK_THROWS(mat(7, 0, ')', '9')); // cannot give size 0 for column or row or both
}


TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%')); // cannot get an even number in row or column or both 
}
