#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

bool checkLength(string binary);
bool checkNumerical(string binary);
bool checkBinary(string binary);
string dottedDecimal(string binary);
string dottedIPtobinary(string dotted);
string decimaltobinary(string decimal);


int main(int argc, char* argv[]){
    //Open inputstream file
    ifstream file(argv[1]);
    if(!file.is_open()){
        cout<<"File could not be opened, please try again";
        return 0;
    }

    //Make outputstream file 
    ofstream myAnswers;
    myAnswers.open("SzepesiAnswers.txt");

    //Process input file
    string binary;
    while(getline(file, binary)){
        //cout<<binary<<" ";
        //Check if input is 32 bits long
        if(!checkLength(binary)){
            cout<<"input is longer than 32 bits.\n";
            continue;
        }

        //Check if input is numerical
        if(!checkNumerical(binary)){
            cout<<"input is not numerical.\n";
            continue;
        }

        //Check if input is binary
        if(!checkBinary(binary)){
            cout<<"input is not binary.\n";
            continue;
        }

        string IPboilerplate = "IP address: ";
        cout<<IPboilerplate<<dottedDecimal(binary);

        cout<<dottedIPtobinary(dottedDecimal(binary))<<"\n";
    }

    
    myAnswers<<"Writing this to my answers file.\n";
    myAnswers.close();
    return 0;
}

bool checkLength(string binary){
    return binary.length() == 32;
}

bool checkNumerical(string binary){
    for(int i = 0; i<binary.length(); i++){
        if(!isdigit(binary[i]))
            return false;
    }
    return true;
}

bool checkBinary(string binary){
    for(int i = 0; i<binary.length(); i++){
        if(binary[i]!='0' && binary[i]!='1')
            return false; 
    }
    return true;
}

string dottedDecimal(string str){
    
    int j = 0;
    string dottedIP;
    string ip[4];
    for(int i =0; i<4; i++){
        int decimal =  128 * (str[i*8]-48) + 
                        64 * (str[i*8+1]-48) + 
                        32 * (str[i*8+2]-48) + 
                        16 * (str[i*8+3]-48) + 
                        8 * (str[i*8+4]-48) + 
                        4 * (str[i*8+5]-48) + 
                        2 * (str[i*8+6]-48) + 
                        1 * (str[i*8+7]-48);
        ip[i] = to_string(decimal);
    }

    dottedIP = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
    return dottedIP;

}

string dottedIPtobinary(string dotted){
    string undottedIP[4];
    string binary;
    int n = 0;
    for(int i = 0; i<dotted.length(); i++){
        if(dotted[i] != '.')
            undottedIP[n] += dotted[i];
        else
            n++;        
    }

    for(int i = 0; i<4; i++)
        binary += decimaltobinary(undottedIP[i]);    

    return binary;
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