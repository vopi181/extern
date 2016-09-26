#include <iostream>
#include "include/vmem.h"
#include "include/vmem.cpp"
#include <string>
#include <errno.h>


using namespace std;



int main() {
    char* testing = ("testing");
    vmem m;
    char* testingadr = "0x7ffc814fc7f4";

    pid_t pid = 2725;
    cout << pid << endl;
    struct iovec local[1];
    struct iovec remote[1];
    char* buf1;
    ssize_t nread;

    local[0].iov_base = buf1;
    local[0].iov_len = sizeof(buf1);
    remote[0].iov_base = (void *) testingadr;
    remote[0].iov_len = sizeof(buf1);

    nread = process_vm_readv(pid, local, 2, remote, 1, 0);
    cout << errno;
    cout << nread;





}