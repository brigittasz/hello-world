#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string binary(string dotted);

int main(int argc, char* argv[]){
  string temp = binary("1.0.0.0");
}

string binary(string dotted){
    string undottedIP[4];
    int n = 0;
    for(int i = 0; i<32; i++){
        if(dotted[i] != '.')
            undottedIP[n] += dotted[i];
        else
            n++;        
    }
    
    for(int i = 0; i<4; i++)
        cout<<undottedIP[i]<<" ";

    return undottedIP[0];
}
