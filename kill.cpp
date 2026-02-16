#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <sys/types.h>
#include <cerrno>
#include <cstring>
using namespace std;
int main(int argc, char* argv[]) {
    // handling invalid command line args
    if (argc != 2) {
        cerr <<"Mssing arguments"<< endl;
        return 0;
    }
     // extracting pid
    long pid_long = atol(argv[1]);
    pid_t pid = static_cast<pid_t>(pid_long);
// killing process using SIGKILL signal    
if (kill(pid, SIGKILL) == -1) {
        cerr << "Error terminating process " << pid<<endl;
        return 0;
    } else {
        cout << "Process " << pid << " terminated successfully with SIGKILL." <<endl;
    }

    return 0;
}
