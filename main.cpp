#include<bits/stdc++.h>

using namespace std;

void printUsage(){
    //  Default Temperature Range: 75-85 C
    //  Default G/C content: 40-60 %
    cout<<"Usage: ./primer <input_file(DNA sequence)> <Temperature_range(optional)> <G/C content(%)(optional)>\n";
    cout<<"DNA sequence: a single string of upprcase letters in the set: [A,T,G,C]\n";
    cout<<"Temperature_range: temp_low-temp_high\n";
    cout<<"G/C content: gc_low-gc_high\n";
    return;
}

int checkDNA(string DNA){
    int n=DNA.length();
    for(int i=0;i<n;i++){
        if(DNA[i]!='A'&&DNA[i]!='T'&&DNA[i]!='G'&&DNA[i]!='C') return 0;
    }
    return 1;
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

float percentGCcontent(string DNA){
    int n=DNA.length();
    int countGC=0,countAT=0;
    for(int i=0;i<n;i++){
        if(DNA[i]=='G'||DNA[i]=='C') countGC++;
        else countAT++;
    }
    float res=((float)(countGC)/n);
}

float percentMismatch(string DNA,string primer,int startPos,int endPos){
    int n=DNA.length(),cnt=0;
    string compDNA="";
    for(int i=startPos;i<endPos;i++){
        if(DNA[i]=='A') compDNA+='T';
        if(DNA[i]=='T') compDNA+='A';
        if(DNA[i]=='G') compDNA+='C';
        if(DNA[i]=='C') compDNA+='G';
    }
    int m=primer.length();
    for(int i=0;i<m;i++){
        if(compDNA[i]!=primer[i]) cnt++;
    }
    float res=(float)(cnt)/m;
    return res;
}

float meltingTemperature(string DNA, string primer,int startPos,int endPos){
    // Tm=81.5+0.41(%GC)−675/N−%mismatch
    // N = Number of Nucleotides,
    // %GC = %GC content.

    int n=DNA.length();
    float misMatch=percentMismatch(DNA,primer,startPos,endPos);
    float percentGC=percentGCcontent(DNA);
    float temp=(81.5)+(0.41*percentGC)-(675/n)-misMatch;
    return temp;
}

int main(int argc,char* argv[]){
    string DNA="";
    int temp_low=75,temp_high=85;
    int gc_low=40,gc_high=60;
    if(argc<=1 || argc>4){
        printUsage();
        exit(0);
    }else{
        if(argc>=2){
            ifstream input_file;
            input_file.open(argv[1]);
            if (input_file.fail()) {
                throw runtime_error("Failed to open file\n");
            }
            getline(input_file, DNA);
            if(checkDNA(DNA)==0){
                cout<<"Invalid input for DNA!!\n";
                printUsage();
                exit(0);
            }
        }
        if(argc>=3){
            if(convertInp(temp_low,temp_high,argv[2])==0){
                cout<<"Invalid input for temperature range!!\n";
                printUsage();
                exit(0);
            }
        }
        if(argc>=4){
            if(convertInp(gc_low,gc_high,argv[3])==0){
                cout<<"Invalid input for G/C range!!\n";
                printUsage();
                exit(0);
            }
        }
    }
    cout<<DNA<<"\n"<<temp_low<<" "<<temp_high<<"\n"<<gc_low<<" "<<gc_high<<"\n";
    return 0;
}
