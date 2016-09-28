#include <iostream>
#include "include/vmem.h"
#include "include/vmem.cpp"
#include <string>
#include <errno.h>
#include <sys/ptrace.h>
int main()
{
vmem m;
pid_t pid;
pid = m.getpid("testing.out");
cout << pid << endl;
auto addr = 0x7ffcf5396c98;
long ret = ptrace(PTRACE_ATTACH, pid, NULL, NULL);
cout << "ptrace Status: " << ret << endl;
cout << "Errno: " << errno << endl;
ret = ptrace(PTRACE_TRACEME, pid, NULL, NULL);
cout << "ptrace Status: " << ret << endl;
cout << "Errno: " << errno << endl;
ret = ptrace(PTRACE_PEEKDATA, pid, addr, NULL);
cout << "ptrace Status: " << ret << endl;
cout << "Errno: " << errno << endl;
ret = ptrace(PTRACE_DETACH, pid, NULL, NULL);
cout << "ptrace Status: " << ret << endl;
cout << "Errno: " << errno << endl;
return 0;
}