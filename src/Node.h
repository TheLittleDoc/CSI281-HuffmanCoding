//
// Created by elysium.hosack on 11/18/2024.
//

#ifndef CSI281_HUFFMANCODING_MINHEAPNODE_H
#define CSI281_HUFFMANCODING_MINHEAPNODE_H



struct Node {
    char data;
    unsigned frequency;

    Node *left;
    Node *right;

    Node(char data, unsigned freq): data(data), frequency(freq), left(nullptr), right(nullptr) {}
    Node(Node *left, Node *right): data('\0'), frequency(left->frequency + right->frequency), left(left), right(right) {}
    Node(unsigned freq, Node *left, Node *right): data('\0'), frequency(freq), left(left), right(right) {}
};



#endif //CSI281_HUFFMANCODING_MINHEAPNODE_H
