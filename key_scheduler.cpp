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

vector<string> key_gen(string key){
    vector<string> sub_keys;
    //write code from here
    
    return sub_keys;
}
