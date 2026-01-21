#include <bits/stdc++.h>

using namespace std;


struct Node {
    map<char, Node*> children;
    bool isValidWord;
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* current = root;
        for(char c: word) {
            if(current->children.count(c) == 0) {
                current->children[c] = new Node();
            }
            current = current->children[c];
        }     
        current->isValidWord = true;
    }
    
    bool search(string word) {
        Node* current = root;
        for(char c: word) {
            if(current->children.count(c) == 1) {
                current = current->children[c];
            } else {
                return false;
            }
        }     
        return current->isValidWord;
    }
    
    bool startsWith(string prefix) {
        Node* current = root;
        for(char c: prefix) {
            if(current->children.count(c) == 1) {
                current = current->children[c];
            } else {
                return false;
            }
        }     
        return true;
    }
};