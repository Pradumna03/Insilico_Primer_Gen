#include "./headers/input.h"
#include "./headers/functions.h"

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
