//
// Created by Shishir Garg on 23/12/22.
//
#include<iostream>
using namespace std;
class TrieNode{
    bool isTerminal;
    TrieNode **children;
    char data;
    TrieNode(char data){
        this->data=data;
        isTerminal=false;
        children=new TrieNode * [26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie{
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode('\0');
    }
    void insertWord(TrieNode *root, string word){
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];

        }
        else{
            child=new TrieNode* (word[0]);
            root->children[index]=child;
        }
        insertWord(child,word.substr(1));

    }

    void removeWord(TrieNode *root, string word){
        if(word.size()==0) {
            root->isTerminal == false;
            return;
        }

        TrieNode *child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];

        }
        else
            return;
        removeWord(child, word.substr(1));

        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL)
                    return;
            }
            delete child;
            root->children[index]=NULL;
        }


    }
};