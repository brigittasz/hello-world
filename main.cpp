#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool checkLength(string binary);
bool checkNumerical(string binary);
bool checkBinary(string binary);
string dottedDecimal(string binary);

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
        cout<<binary<<" ";
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
        cout<<"is 32 bits long, numerical and binary.\n";

        string str = dottedDecimal(binary);
        cout<<'0'-48;
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
    
    int counter = 0;
    int decimal = 0;
    for(int i =0; i<4; i++){
        for(int j = 0; j<8; j++){
            cout<<counter<<" "<<counter++<<"\n";
            cout<<counter<<"\n";
        }
    }
    return "temp;";

}

// int binaryToDecimal(string binary){

// }



