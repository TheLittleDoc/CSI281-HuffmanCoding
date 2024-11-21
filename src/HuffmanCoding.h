//
// Created by elysium.hosack on 11/18/2024.
//

#ifndef CSI281_HUFFMANCODING_HUFFMANCODING_H
#define CSI281_HUFFMANCODING_HUFFMANCODING_H
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include "MinHeapNode.h"

using namespace std;

class HuffmanCoding {
private:
    string text;
    char[] characters;
    vector<int> freq;
    vector<string> codes;
    MinHeapNode *root;
    string encodedText;
    string decodedText;

    void frequencies() {
        for (char c : text) {
            freq[c]++;
        }
    }
public:
    HuffmanCoding(string text) : text(std::move(text)) {
        frequencies();


        encode();
    }

    void encode() {
        priority_queue<MinHeapNode, vector<MinHeapNode>, greater<>> minHeap;
        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) {
                minHeap.emplace(i, freq[i], nullptr, nullptr);
            }
        }
    }

};

#endif //CSI281_HUFFMANCODING_HUFFMANCODING_H
