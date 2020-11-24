#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


int maxprefix(string dotted);

int main(int argc, char* argv[]){
    cout<<maxprefix("1.0.0.0/8")<<" ";
    cout<<maxprefix("1.0.100.0/24")<<" ";
    cout<<maxprefix("All else")<<" ";

}

int maxprefix(string dotted){
    string max = "";
    bool count = false;
    for(int i = 0; i<dotted.length(); i++){
        if(dotted[i] == '/'){
            count = true;
            continue;
        }
        if(count)
            max += dotted[i];
    }
    if(!count)
        return 0;

    return stoi(max);
}