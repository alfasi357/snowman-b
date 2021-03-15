#include <iostream>
#include "snowman.hpp"
#include <string>
#include <string.h>
using namespace std;
using namespace ariel;

string nospaces(string input) {
    input.erase(remove(input.begin(),input.end(), ' '), input.end());
    input.erase(remove(input.begin(),input.end(), '\t'), input.end());
    input.erase(remove(input.begin(),input.end(), '\n'), input.end());
    input.erase(remove(input.begin(),input.end(), '\r'), input.end());
	return input;
}
bool com(string str1 ,string str2){
    for(int i=0;i<(int)str1.length(); i++){
    if(str1.at(i)!=str2.at(i)){ 
    printf("the index is: %d\nthe char is: %c\n",i,str1.at(i));
    return false;
    }
    }
    return true;
}
int main(){
   int a = 32142412;
    std:: string str=ariel::snowman(a);
    std:: string check="_/_\\\\(..-)(:)(\"\")";
    std:: cout << str << endl;
     str=nospaces(str);
     bool flag= com(str,check);
    std::cout<<"\nflag is: " << flag<<endl;
    std:: cout<< "\n" << str << "\n"<< check << "\n";
    return 0;
}