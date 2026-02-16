#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    // handling invalid command line args
    if (argc != 2) {
        cerr<<”Invalid args. ”<<endl;
        return 0;
    }
    // extracting filename from command line args
    const char* file_to_delete = argv[1];
    // confirming from user
    cout<<"Are you sure you want to delete file> (y/n):"<<endl;
    string s;
    cin>>s;
     // handling non-yes inputs
    if(s!="Y" && s!="y"){
       return 0;
    }
     //  using remove() to delete file
    if (remove(file_to_delete) == 0) {
        cout << "File deleted sucessfully." << file_to_delete <<endl;
    } else {
        // handling errors such as absence of file from directory
        cerr << "Error deleting file: " << file_to_delete <<endl;
        return 0;
    }

    return 0;
}
