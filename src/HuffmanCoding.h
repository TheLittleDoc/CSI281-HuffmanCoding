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
#include <bitset>
#include "Node.h"

using namespace std;

class HuffmanCoding {
private:
    unordered_map<char, int> freqs;
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

    void createCodes(Node* root, string str,
                    unordered_map<char, string>& huffmanCode)
    {
        if (root == nullptr)
            return;

        // Found a leaf node
        if (!root->left && !root->right) {
            huffmanCode[root->data] = str;
        }

        createCodes(root->left, str + "0", huffmanCode);
        createCodes(root->right, str + "1", huffmanCode);
    }

    string convertTreeToText(unordered_map<char, string>& huffmanCode) {
        string serializedTree;
        for (auto pair : huffmanCode) {
            serializedTree += pair.second;
            serializedTree += pair.first;
        }
        return serializedTree;
    }

    string serializedTree(Node* node) {
        string treeData;
        //traverse tree (node-left-right) and store data
        //if node is internal, store 1, if leaf store 0 and the character in binary
        if (node == nullptr)
        {
            return "";
        }
        if (!node->left && !node->right)
        {
            treeData += "0";
            treeData += bitset<8>(node->data).to_string();
        }
        else
        {
            treeData += "1";
        }
        treeData += serializedTree(node->left);
        treeData += serializedTree(node->right);
        return treeData;
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

        unordered_map <char, string> huffmanCode;
        createCodes(root, "", huffmanCode);

        cout << "Huffman Codes:\n";
        for (auto pair : huffmanCode) {
            cout << pair.first << ": " << pair.second << "\n";
        }
        cout << "Ascii Coding:\n";
        for(char ch: decodedText)
        {
            //as binary
            cout << bitset<8>(ch);
        }
        cout << "\nEncoded Text:\n";
        for (char ch: decodedText) {
            cout << huffmanCode[ch];
            encodedText += huffmanCode[ch];
        }
        cout << "\n";
        cout << "Serialized Tree:\n";
        cout << convertTreeToText(huffmanCode) << "\n";
        cout << serializedTree(root) << "\n";

        //combine and store





    }

};

#endif //CSI281_HUFFMANCODING_HUFFMANCODING_H
