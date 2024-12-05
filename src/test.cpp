#include "Node.h"
//test.cpp
//Noah Maywar

#include "HuffmanCoding.h"
#include "catch.h"
#include <string>
#include <iostream>

using namespace std;

TEST_CASE("Huffman Coding") {
    string input = "Hello World I Love You";
    HuffmanCoding huffman(input);

    string encoded = huffman.getEncode();
    string decoded = huffman.getDecode();

    REQUIRE(decoded == input);
}

TEST_CASE("Huffman Coding with letters") {
    string input = "aaaaabbbbcccdde";
    HuffmanCoding huffman(input);

    string encoded = huffman.getEncode();
    string decoded = huffman.getDecode();

    REQUIRE(decoded == input);
}

TEST_CASE("Huffman Coding with just repeats letters") {
    string input = "aaaaaa";
    HuffmanCoding huffman(input);

    string encoded = huffman.getEncode();
    string decoded = huffman.getDecode();

    REQUIRE(decoded == input);
}
TEST_CASE("Huffman Coding with no input") {
    string input = "";
    HuffmanCoding huffman(input);

    string encoded = huffman.getEncode();
    string decoded = huffman.getDecode();

    REQUIRE(decoded == input);
}

TEST_CASE("Huffman Coding with numbers") {
    string input = "1010101111000002322454235243";
    HuffmanCoding huffman(input);

    string encoded = huffman.getEncode();
    string decoded = huffman.getDecode();

    REQUIRE(decoded == input);
}

TEST_CASE("Huffman Coding with numbers and letters") {
    string input = "101aaaaabbbbcccdde0101111000002322aaaaabbbbcccdde454235243";
    HuffmanCoding huffman(input);

    string encoded = huffman.getEncode();
    string decoded = huffman.getDecode();

    REQUIRE(decoded == input);
}

TEST_CASE("Huffman Coding with special characters") {
    string input = "&(*!#$&%@&#!($&^";
    HuffmanCoding huffman(input);

    string encoded = huffman.getEncode();
    string decoded = huffman.getDecode();

    REQUIRE(decoded == input);
}
TEST_CASE("Huffman Coding with numbers, letters, and special characters") {
    string input = "101aaaaabb&(*!#$&%@&#!($&^bbcccdde0101111000002322&(*!#$&%@&#!($&^aaaaabbbbcccdde454235243";
    HuffmanCoding huffman(input);

    string encoded = huffman.getEncode();
    string decoded = huffman.getDecode();

    REQUIRE(decoded == input);
}

