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
// the given function is used to extract process name
string get_process_name(const string& pid_str) {
    // using proc directory for path
    string comm_path = "/proc/" + pid_str + "/comm";
   // using ifstream to extract text
    ifstream comm_file(comm_path);
    string name;
    if (comm_file.is_open()) {
        getline(comm_file, name);
        comm_file.close();
        if (!name.empty() && name.back() == '\n') {
            name.pop_back();
        }
    } else {
        // if name is not extracted it names the process as unkown
        name = "<unknown>";
    }
    return name;
}
    
int main() {
    DIR* dirp;
    struct dirent* dp;
    // using opendir to open proc directory
    dirp = opendir("/proc");
    if (dirp == NULL) {
        cerr << "Error opening /proc directory: " << strerror(errno) <<endl;
        return 0;
    }

    cout << "PID\tProcess Name" <<endl;
    cout << "---\t------------" <<endl;
   // iterating through the proc directory and reading using readdir()
    while ((dp = readdir(dirp)) != NULL) {
            string pid_str = dp->d_name;
            string process_name = get_process_name(pid_str);
            cout << pid_str << "\t" << process_name <<endl;
    }
   // closing directory using closedir
    closedir(dirp);
    return 0;
}
