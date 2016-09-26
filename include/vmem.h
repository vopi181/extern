//
// Created by vopi on 9/25/16.
// thanks to Vincent Canfield for most of the source for this mememory helper class ideas
//
#ifndef VMEM_H_INCLUDED
#define VMEM_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
#include <thread>
#include <chrono>
#include <sys/uio.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;
class vmem{
private:
    struct iovec loc[1];
    struct iovec remo[1];
    pid_t pid;
    char buf[512];
    char cmd[256];
    FILE *maps;
    long unsigned int result = 0;
public:
    int showpid();
    int checkroot();
    uint32_t getmodule(const char* modname);
    uint32_t getpid(const char * name);
    void read(void* adr, void* bb, size_t size);
    void write(void* adr, void* bb, size_t size);
    char * readtxt(const char * filename, int number);
    int readinteg(const char * filename, int number, string style);
    float readfloat(const char * filename, int number);
    bool fexists(const std::string& name);
};
#endif