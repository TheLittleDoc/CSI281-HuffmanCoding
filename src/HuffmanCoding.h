//
// Created by elysium.hosack on 11/18/2024.
//

#ifndef CSI281_HUFFMANCODING_HUFFMANCODING_H
#define CSI281_HUFFMANCODING_HUFFMANCODING_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "BinaryTree.h"

using namespace std;

class HuffmanCoding {
private:
    int length;
    char *characters;
    BinaryTree<char> *tree;
    vector<pair<char, int>> sortedFrequencies;
    string toEncode;
public:
    HuffmanCoding(string toEncode): toEncode(toEncode) {
        length = 0;
        characters = new char[toEncode.length()];
        for (char c : toEncode) {
            bool found = false;
            for (int i = 0; i < length; i++) {
                if (characters[i] == c) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                characters[length++] = c;
            }
        }
        sortedFrequencies = vector<pair<char, int>>();
        for (int i = 0; i < length; i++) {
            sortedFrequencies.push_back(make_pair(characters[i], 0));
        }
        for (char c : toEncode) {
            for (int i = 0; i < length; i++) {
                if (characters[i] == c) {
                    sortedFrequencies[i].second++;
                    break;
                }
            }
        }
        sort(sortedFrequencies.begin(), sortedFrequencies.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        });
        tree = new BinaryTree<char>();
        for(auto &p : sortedFrequencies) {
            tree->insert(p.first);
        }


    } 

    void decode();
    void print();
};


#endif //CSI281_HUFFMANCODING_HUFFMANCODING_H
