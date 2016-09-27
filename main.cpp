#include <iostream>
#include "include/vmem.h"
#include "include/vmem.cpp"
#include <string>
#include <errno.h>


using namespace std;



int main() {
    const char* testing = ("testing.out");
    vmem m;
    const char* testingadr = "0x7ffd8031495c";

    pid_t pid;
    pid = m.getpid(testing);
    cout << pid << endl;
    struct iovec local[1];
    struct iovec remote[1];
    
    char* buf1 = new char[8];
    float nread[2]{0,0};

    local[0].iov_base = buf1;
    local[0].iov_len = 8;
    remote[0].iov_base = (void *) 0x7fff0ba2aebc;
    remote[0].iov_len = 8;

    //nread = process_vm_readv(pid, local, 1, remote, 1, 0);
    m.read((void*) 0x7fff0ba2aebc, &nread, sizeof(nread));
    cout << errno << endl;
    cout << nread << endl;
    //cout << buf1 << endl;





}