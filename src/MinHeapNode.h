//
// Created by elysium.hosack on 11/18/2024.
//

#ifndef CSI281_HUFFMANCODING_MINHEAPNODE_H
#define CSI281_HUFFMANCODING_MINHEAPNODE_H



struct MinHeapNode {
    char data;
    unsigned frequency;

    MinHeapNode *left;
    MinHeapNode *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = nullptr;
        this->data = data;
        this->frequency = freq;
    }
    MinHeapNode(MinHeapNode *left, MinHeapNode *right)
    {
        this->data = '\0';
        this->frequency = left->frequency + right->frequency;
        this->left = left;
        this->right = right;
    }

};



#endif //CSI281_HUFFMANCODING_MINHEAPNODE_H
