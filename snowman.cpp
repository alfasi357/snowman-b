#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <array>
#include <algorithm>

using namespace std;
namespace ariel{

const int five = 5;
const int six = 6;
const int eight = 8;
const int ten = 10;
const int seven = 7;

string hat(int x){
if (x==1){
return "_===_";}
if (x==2){
return " ___\n.....";}
if (x==3){
return "   _\n/_\\ ";}
if (x==4) {
return " ___\n(_*_)";}
return "make tidy";
}
char nosemouth(int x){
if (x==1){
return ',';}
if (x==2){
return '.';}
if (x==3){
return '_';}
if (x==4) {
return ' ';} 
return 'm';
}
char lefteye(int x){
if (x==1){
return '.';}
if (x==2){
return 'o';}
if (x==3){
return 'O';}
if (x==4){
return '-';}  
return 'm';   
}
char righteye(int x){
return lefteye(x);    
}
char leftarm(int x){
if (x==1){
return '<';}
if (x==2){
return '\\';}
if (x==3){
return '/';}
if (x==4) {
return '+';}  
return 'm';  
}
char rightarm(int x){
if (x==1){
return '>';}
if (x==2){
return '/';}
if (x==3){
return '\\';}
if (x==4) {
return '+'; }
return 'm';
}

string torso(int x){
if (x==1){
return " : ";}
if (x==2){
return "] [";}
if (x==3){
return "> <";}
if (x==4) {
return "   ";}
return "make tidy";
}

string base(int x){
if (x==1){
return " : ";}
if (x==2){
return "\" \"";}
if (x==3){
return "___";}
if (x==4) {
return "   ";}
return "make tidy";
}

int length(int x){   
if(x/(int)pow(ten,seven)<1 || x/(int)pow(ten,seven)>4){
return 0;}
return 1;
}


string snowman(int x){
char lefteye1=' ';
char righteye1=' ';
char leftarm1=' ';
char rightarm1=' ';
char nose1=' ';
string hat1;
string torso1;
string base1;
if(length(x)==0){
throw out_of_range{"x must have eight digits"};}
int p = seven;
int y = x;
int index = 0;
int counter = 0;
array<int , eight> arr{};
while(y!=0||counter<eight){
counter++;    
int t = y/(int)pow(ten,p);
arr.at(index)=t;
if(t>4||t<1){
throw out_of_range{"every digit must be between 1 and 4"};}
y = y-t*(int)pow(ten,p);
p--;
index++;
}
//1,000,000
int la = 0;
int ra = 0;
int nm = 0;
int le = 0;
int re = 0;
int ha = 0;
int to = 0;
int ba = 0;
la = arr.at(4);
ra = arr.at(five);
ha = arr.at(0);
nm = arr.at(1);
le = arr.at(2);
re = arr.at(3);
to = arr.at(six);
ba = arr.at(seven);

hat1 = hat(ha);
nose1 = nosemouth(nm); 
lefteye1 = lefteye(le);
righteye1 = righteye(re);
leftarm1 = leftarm(la);
rightarm1 = rightarm(ra);
torso1 = torso(to);
base1 = base(ba);
std:: string ans;

if((la==1||la==3)&&ra!=2){
//leftarm is 1 or 3, right arm isn"t 2
ans= " " + hat1 + "\n" + " " + "(" + lefteye1 + nose1 + righteye1 + ")" + "\n" + leftarm1 + "(" + torso1 + ")"+ rightarm1 + "\n" + " " + "(" + base1 + ")";
}

else if((la==1||la==3)&&ra==2){
//leftarm is 1 or 3, right arm is 2
ans= " " + hat1 + "\n" + " " + "(" + lefteye1 + nose1 + righteye1 + ")" + rightarm1 + "\n" + leftarm1 + "(" + torso1 + ")" + "\n"+ " " + "(" + base1 + ")";
}

else if(la==2&&ra!=2){
//left arm is 2, right arm isn"t 2
ans= " " + hat1 + "\n" + leftarm1 + "(" + lefteye1 + nose1 + righteye1 + ")" + "\n" + " " + "(" + torso1 + ")" + rightarm1 + "\n" + " " + "(" + base1 + ")";
}

else if(la==2&&ra==2){
//left arm is 2, right arm is 2
ans= " " + hat1 + "\n" + leftarm1 + "(" + lefteye1 + nose1 + righteye1 + ")" + rightarm1 + "\n" + " " + "(" + torso1 + ")" + "\n" + " " + "(" + base1 + ")";
}

else if(la==4&&ra!=2){
//left arm is 4, right arm isn"t 2
ans= hat1 + "\n" + "(" + lefteye1 + nose1 + righteye1 + ")" + "\n" + "(" + torso1 + ")" + rightarm1 + "\n" + "(" + base1 + ")";
}

else if(la==4&&ra==2){
//left arm is 4, right arm is 2
ans= hat1 + "\n" + "(" + lefteye1 + nose1 + righteye1 + ")" + rightarm1 + "\n" + "(" + torso1 + ")" + "\n" + "(" + base1 + ")";
}
ans.erase(remove(ans.begin(),ans.end(), '+'), ans.end());
return ans;
}
};