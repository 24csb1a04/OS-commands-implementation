#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;
int main() {
    DIR* dirp;
    struct dirent* dp;
    // opening proc directory using opendir()
    dirp = opendir("/proc");
    if (dirp == NULL) {
        cerr << "Error opening /proc directory: " << strerror(errno) <<endl;
        return 0;
    }
    int count = 0;
    // iterating through directory and reading content using readdir()
    while ((dp = readdir(dirp)) != NULL) {
           count++; // incrementing count for number of processes
    }
    cout<<"Total running processes: "<<count<<endl;
    // closing directory at end of operation.
    closedir(dirp);
    return 0;
}

