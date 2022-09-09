#include "../headers/functions.h"

char complement(char ch){
    if(ch=='A') return 'T';
    if(ch=='T') return 'A';
    if(ch=='C') return 'G';
    if(ch=='G') return 'C';
}

vector<vector<int>> palindromicComplement(string &primer){
    /*
        Searches for complementarity of four nucleotide
        continuous subsequences.

        => Unordered map for optimisation

    */
    vector<vector<int>> res;
    int n=primer.length();
    for(int i=0;i<=n-4;i++){
        for(int j=n-1;j>=n-7;j--){
            if(checkPalindrome(primer,i,i+3,j-3,j)) res.push_back({i,i+3,j-3,j});
        }
    }
    return res;
}

vector<vector<int>> repeatingNucleoSequence(string &primer){
    /*
        Returns the starting index and count of any
        continuous subsequence with repeating nucleotides
        with length greater than or equal to three.
    */
    vector<vector<int>> res;
    char ch=primer[0];
    int n=primer.length();
    int idx=0,cnt=0;
    while(idx<n){
        if(primer[idx]==ch) cnt++,idx++;
        else{
            if(cnt>=3) res.push_back({idx-cnt,cnt});
            ch=primer[idx];
            cnt=0;
        }
    }
    if(cnt>=3) res.push_back({idx-cnt,cnt});
    return res;
}

bool checkPalindrome(string &str,int x1,int y1,int x2,int y2){
    for(int i=x1,j=y2;i<=y1,j>=x2;i++,j--){
        if(complement(str[i])!=str[j]) return false;
    }
    return true;
}

int checkDNA(string &DNA){
    int n=DNA.length();
    for(int i=0;i<n;i++){
        if(DNA[i]!='A'&&DNA[i]!='T'&&DNA[i]!='G'&&DNA[i]!='C') return 0;
    }
    return 1;
}

float percentGCcontent(string &DNA){
    int n=DNA.length();
    int countGC=0,countAT=0;
    for(int i=0;i<n;i++){
        if(DNA[i]=='G'||DNA[i]=='C') countGC++;
        else countAT++;
    }
    float res=((float)(countGC)/n);
    return res;
}

float percentMismatch(string &DNA,string &primer,int startPos,int endPos){
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

float meltingTemperature(string &DNA, string &primer,int startPos,int endPos){
    // Tm=81.5+0.41(%GC)−675/N−%mismatch
    // N = Number of Nucleotides,
    // %GC = %GC content.

    int n=DNA.length();
    float misMatch=percentMismatch(DNA,primer,startPos,endPos);
    float percentGC=percentGCcontent(DNA);
    float temp=(81.5)+(0.41*percentGC)-(675/n)-misMatch;
    return temp;
}


