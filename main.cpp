#include<iostream>
#include<fstream>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

// Node structure each node will have character and freq and we will put in the pq based on the freq
struct Node{
    char c;
    int freq;
    Node* left,* right;

    Node(char c, int f) {
        this->c = c;
        this->freq = f;
    }

};

// another custom comparator
struct compare{
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

// custom comparator this one is dynamic 
auto comp = [&](Node* a, Node*b) {
    return a->freq > b->freq;
};

//build huffman tree 
Node* buildHuffmanTree(unordered_map<char,int>&freq_map) {
    priority_queue<Node*, vector<Node*>, decltype(comp)>pq(comp);

    for(auto it: freq_map) {
        pq.push(new Node(it.first, it.second));;
    }

    while(pq.size() > 1) {
        Node*left = pq.top();pq.pop();
        Node* right = pq.top();pq.pop();

        Node* combined = new Node('\0', left->freq + right->freq);

        combined->left = left;
        combined->right = right;

        pq.push(combined);

    }

    return pq.top();
        
}

// TODO: Generate Huffman Codes.


int main() {
    string filename = "input.txt";
    std::ifstream my_file(filename);

    if(!my_file.is_open()) {
        cout << "Couldn't open file an error occured" << endl;
        return 1;
    }

    unordered_map<char, int>freq;
    char ch;

    while(my_file.get(ch)) {
        freq[ch]++;
    }

    my_file.close();

    cout << "Characters Frequenciesn in the file: " << filename << ":\n";
    for(auto it: freq) {
        if(it.first == ' ') {
            cout << "' ' (space): " << it.second << "\n" << endl;
        }else if(it.first == '\n') {
            cout << "'\\n' (newline): " << it.second  << endl;
        }else {
            cout << "'" << it.first << "': " << it.second << endl; 
        }
    }
    return 0;
}