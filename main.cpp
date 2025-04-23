#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;

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