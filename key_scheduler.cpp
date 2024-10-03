#include "key_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

string shift_left(string sub_key){
    int n = sub_key.length();
    char temp = sub_key[0];
for(int i = 0; i < n-1; i++)
{
    
    sub_key[i] = sub_key[i + 1];
    cout << sub_key[i]<< endl;
}
sub_key[n-1] = temp;
    return sub_key;
} 

// Shift schedule for each round
int SHIFT_SCHEDULE[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

string PC1Apply(string key) {
    string permuted_key = "";
    for (int i = 0; i < 56; i++) {
        permuted_key += key[PC1[i] - 1];
    }
    return permuted_key;
}


string PC2Apply(string combined) {
    string sub_key = "";
    for (int i = 0; i < 48; i++) {
        sub_key += combined[PC2[i] - 1];  
    }
    return sub_key;
}

vector<string> key_gen(string key) {
    vector<string> sub_keys;
    string permuted_key = PC1Apply(key);
    string C = permuted_key.substr(0, 28);
    string D = permuted_key.substr(28, 28);

    for (int round = 0; round < 16; round++) {
        for (int shift = 0; shift < SHIFT_SCHEDULE[round]; shift++) {
            C = shift_left(C);
            D = shift_left(D);
        string combined = C + D;
        string sub_key = PC2Apply(combined);
        sub_keys.push_back(sub_key);
    }

    return sub_keys;
}
}