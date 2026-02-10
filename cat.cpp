#include <bits/stdc++.h>
using namespace std;
int main(int argc , char*argv[]){
  // handling invalid command line args
  if(argc!=2){
    cerr<<"Missing arguments"<<endl;
    return 0;
  }
  // extracting filename from command line args
  const char* filename = argv[1];
   // opening file using fopen()
  FILE* file_fgetc = fopen(filename, "rb");
    if (file_fgetc == nullptr) {
        fprintf(stderr, "Error opening file %s for fgetc().\n", filename);
    } else {
        int character;
        // appending characters to file by iterating using fgetc() 
        while ((character = fgetc(file_fgetc)) != EOF) {
            putchar(character);
        }
        // closing file after operation using fclose()
        fclose(file_fgetc);
    }
  return 0;
}
