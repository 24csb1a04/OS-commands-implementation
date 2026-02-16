#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    // handling invalid command line args
    if (argc != 2) {
        cerr<<” Invalid Args”<<endl;
        return 0;
    }
     // extracting file name form command line args
    const char* file_to_delete = argv[1];
    // using remove() to delete file
    if (remove(file_to_delete) == 0) {
        cout << "File deleted sucessfully." << file_to_delete <<endl;
    } else {
          // handling errors such as absence of file
        cerr << "Error deleting file: " << file_to_delete <<endl;
        return 0;
    }

    return 0;
}
