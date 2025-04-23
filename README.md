# Huffman Encoding File Compressor

This is a C++ project that performs file compression using the Huffman Encoding algorithm.  
It takes a text file as input, analyzes character frequencies, builds a Huffman tree, and outputs a compressed binary file.

## Features
- Compress any `.txt` file using Huffman coding
- Output a compressed binary file (`.huff`)
- Optional: decompress back to the original file
- Uses priority queues, trees, and binary file handling

## Getting Started
```bash
g++ main.cpp -o compressor
./compressor input.txt
