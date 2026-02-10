#include <bits/stdc++.h>
using namespace std;
int main(int argc , char*argv[]){
// handling invalid command line args
 if(argc!=2){
   cerr<<"Missing arguments"<<endl;
   return 0;
 }
 // extracting file name using command line args
 const char* filename = argv[1];
// declaration of ifstream()
 ifstream inputfile(filename);
 if (!inputfile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 0;
  }
  string line;
  int linenumber = 1;
  // extracting content from inputfile using ifstream() and getline function
  while(getline(inputfile , line)){
    cout<<linenumber<<". "<<line<<endl;
    linenumber++;
  }
   // closing file after operation
  inputfile.close();
 return 0;
}
