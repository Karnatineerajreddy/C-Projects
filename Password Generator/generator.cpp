#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include <random>
using namespace std;

string password_generator(int size=16,int num=4, int symb=1){
    string resultPassword="";
    string number="1234567890";
    string alphabet="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    string symbol="~!#$%-&=?/@";
    srand(time(0));
    while(size){
        resultPassword+=alphabet[rand() % alphabet.size()];
        size--;

        if(num && size){
            resultPassword +=number[rand() % number.size()];
            size--;
            num--;
        }
        if(symb && size){
            resultPassword +=symbol[rand() % symbol.size()];
            size--;
            symb--;
        }
        
    }
    string formatted="";
        for(int i=0;i<resultPassword.size();i++){
            formatted+=resultPassword[i];
            if((i+1)%4==0 && (i+1)!=resultPassword.size()) formatted+='-';
        }
    cout << formatted << endl;
}
int main(){
    password_generator();
    return 0;
}
