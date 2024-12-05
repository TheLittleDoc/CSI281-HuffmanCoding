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
#include <unordered_map>
#include "Node.h"

using namespace std;

class HuffmanCoding {
private:
    unordered_map<char, uint> freqs;
    vector<string> codes;
    Node *root;
    string encodedText;
    string decodedText;

    void frequencies() {
        for(char ch: decodedText)
        {
            freqs[ch]++;
        }
    }
    struct comparison
    {
        bool operator()(Node* l, Node* r)
        {
            return l->frequency > r->frequency;
        }
    };
public:
    HuffmanCoding(string text) : decodedText(std::move(text)) {
        frequencies();


        encode();
    }

    void encode() {
        priority_queue<Node*, vector<Node*>, comparison> pq;
        for (auto newPair: freqs)
        {
            pq.push(new Node(newPair.first, newPair.second));
        }
        while (pq.size() != 1)
        {
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();
            pq.push(new Node(left, right));
        }
        root = pq.top();

    }
 string getEncode() const {
     return encodedText;
 }

 string getDecode() const {
     return decodedText;
 }
};

#endif //CSI281_HUFFMANCODING_HUFFMANCODING_H
