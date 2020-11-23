#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

string decimaltobinary(string decimal);


int main(int argc, char* argv[]){
  cout<<decimaltobinary("127");
}

string decimaltobinary(string decimal){
    int binary[8];
    int dec = stoi(decimal);

    binary[0] = dec/128;
    dec -= binary[0] * 128;
    binary[1] = dec/64;
    dec -= binary[1] * 64;


    binary[2] = dec/32;
    dec -= binary[2] * 32;
    binary[3] = dec/16;
    dec -= binary[3] * 16; 

    binary[4] = dec/8; 
    dec -= binary[4] * 8; 
    binary[5] = dec/4;
    dec -= binary[5] * 4; 

    binary[6] = dec/2; 
    dec -= binary[6] * 2;
    binary[7] = dec;

    string bin;
    for (int i: binary) {
        bin += to_string(i);
    }

    return bin; 
}