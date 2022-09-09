#include "../headers/input.h"

void printUsage(){
    //  Default Temperature Range: 75-85 C
    //  Default G/C content: 40-60 %
    cout<<"Usage: ./primer <input_file(DNA sequence)> <Temperature_range(optional)> <G/C content(%)(optional)>\n";
    cout<<"DNA sequence: a single string of upprcase letters in the set: [A,T,G,C]\n";
    cout<<"Temperature_range: temp_low-temp_high\n";
    cout<<"G/C content: gc_low-gc_high\n";
    return;
}

int stringToNum(string num){
    int n=num.length();
    int res=0;
    for(int i=0;i<n;i++){
        if(num[i]>='0'&&num[i]<='9'){
            res+=(int)(num[i]-'0');
            res*=10;
        }else return -1;
    }
    res/=10;
    return res;
}

int convertInp(int& low,int& high,string inp){
    int idx=0,n=inp.length();
    string num="";
    while(idx<n&&inp[idx]!='-'){
        num+=inp[idx];
        idx++;
    }
    low=stringToNum(num);
    if(low==-1) return 0;
    num="";
    idx++;
    while(idx<n&&inp[idx]!='-'){
        num+=inp[idx];
        idx++;
    }
    high=stringToNum(num);
    if(high==-1||idx!=n) return 0;
    return 1;
}
