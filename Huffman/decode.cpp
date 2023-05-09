#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct MinHeapNode {

    // One of the input characters
    char data;

    // Frequency of the character
    unsigned freq;

    // Left and right child
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {

    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

// Traverses the Huffman tree and builds a lookup table
// that maps each character to its corresponding Huffman code
void buildLookupTable(MinHeapNode* root, string code, unordered_map<char, string>& lookup)
{
    if (!root)
        return;

    if (root->data != '$')
        lookup[root->data] = code;

    buildLookupTable(root->left, code + "0", lookup);
    buildLookupTable(root->right, code + "1", lookup);
}

string encode(MinHeapNode* root, string str)
{
    unordered_map<char, string> lookup;
    buildLookupTable(root, "", lookup);

    string encodedString = "";
    for (char c : str)
        encodedString += lookup[c];

    return encodedString;
}

// Decodes a string using the Huffman codes generated
// by the HuffmanCodes function
string decode(MinHeapNode* root, string encodedString)
{
    string decodedString = "";
    MinHeapNode* curr = root;
    for (char c : encodedString) {
        if (c == '0')
            curr = curr->left;
        else
            curr = curr->right;
        if (curr->data != '$') {
            decodedString += curr->data;
            curr = root;
        }
    }
    return decodedString;
}

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Build the Huffman tree
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(arr[i], freq[i]));
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    // Encode a sample string
    string str = "abacabad";
    string encodedStr = encode(minHeap.top(), str);
    cout << "Encoded string: " << encodedStr << endl;

    // Decode the encoded string
    string decodedStr = decode(minHeap.top(), encodedStr);
    cout << "Decoded string: " << decodedStr << endl;

    return 0;
}
