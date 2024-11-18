//
// Created by elysium.hosack on 11/18/2024.
//

#ifndef CSI281_HUFFMANCODING_BINARYSEARCHTREE_H
#define CSI281_HUFFMANCODING_BINARYSEARCHTREE_H

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node *left;
        Node *right;
        explicit Node(): data(nullptr), left(nullptr), right(nullptr) {}
    };
    Node *root;
public:
    BinaryTree(): root(new Node()) {}

    void insert(Node *node, T *data) {
        if (node == nullptr) {
            node = new Node(data);
        } else {
            if (*data < *node->data) {
                insert(node->left, data);
            } else {
                insert(node->right, data);
            }
        }
    }

};


#endif //CSI281_HUFFMANCODING_BINARYSEARCHTREE_H
