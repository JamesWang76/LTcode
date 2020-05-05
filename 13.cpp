#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;
int romanToInt(string s);

/**
 * Just concern the substract operation of calculating the Roman string.
 */ 

int main(){
    romanToInt("XIXI");
}

int romanToInt(string s) {
    map<char, int> table; 
    map<char, int>::iterator it ; 
    int sum = 0, tmp=0;
    int len = s.size();

    table.insert(pair<char, int>('I', 1)); 
    table.insert(pair<char, int>('V', 5)); 
    table.insert(pair<char, int>('X', 10)); 
    table.insert(pair<char, int>('L', 50)); 
    table.insert(pair<char, int>('C', 100)); 
    table.insert(pair<char, int>('D', 500)); 
    table.insert(pair<char, int>('M', 1000)); 
    
    for(int i=0;i<len;i++){
        it = table.find(s[i]);
        itValue = it->second;
        if(s[i] == 'I'&& i < len-1){
            if(s[i+1] == 'V' || s[i+1] == 'X') 
                itValue *= -1;
        }

        else if(s[i] == 'X'&& i < len-1){
            if(s[i+1] == 'L' || s[i+1] == 'C') 
                itValue *= -1;
        }

        if(s[i] == 'C'&& i < len-1){
            if(s[i+1] == 'D' || s[i+1] == 'M') 
                itValue *= -1;
        }
        sum += itValue;
    }
    return 0;
}
