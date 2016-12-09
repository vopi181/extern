//
// Created by vopi on 9/25/16.

//

#include "vmem.h"
#include <sys/stat.h>
#include <unistd.h>

int vmem::showpid() {
  if (pid != 0) {
    return pid;
  } else
    cout << "proc not found!!" << endl;
  exit(0);
}

int vmem::checkroot() {
  if (getuid() != 0) {

    cout << "this needs to be run as root! its for your own safety!" << endl;
    exit(0);
  } else
    return true;
}

uint32_t vmem::getmodule(const char *modname) {
  snprintf(cmd, 256, "grep \"%s\" /proc/%i/maps | head -n 1 | cut -d \"-\" -f1",
           modname, pid);
  maps = popen(cmd, "r");
  if (maps) {
    if (fscanf(maps, "%08lx", &result))
      ;
  }
  pclose(maps);
  return result;
}

uint32_t vmem::getpid(const char *name) {
  snprintf(buf, 512, "pidof -s %s", name);
  maps = popen(buf, "r");
  if (maps) {
    if (fgets(buf, 512, maps))
      ;
  }
  pid = strtoul(buf, NULL, 10);
  pclose(maps);
  return pid;
}
void vmem::read(void *adr, void *bb, size_t size) {
  loc[0].iov_base = bb;
  loc[0].iov_len = size;
  remo[0].iov_base = adr;
  remo[0].iov_len = size;
  (process_vm_readv(pid, loc, 1, remo, 1, 0) == (signed)size);
}

void vmem::write(void *adr, void *bb, size_t size) {
  loc[0].iov_base = bb;
  loc[0].iov_len = size;
  remo[0].iov_base = adr;
  remo[0].iov_len = size;
  (process_vm_writev(pid, loc, 1, remo, 1, 0) == (signed)size);
}

int vmem::readinteg(const char *filename, int number, string style) {
  fstream file(filename);
  string ln;
  if (file.is_open()) {
    for (int i = 1; getline(file, ln); i++) {
      if (i == number) {
        int result = 0;
        if (style == "dec") {
          result = stoi(ln);
        } else if (style == "hex") {
          result = stoi(ln, nullptr, 16);
        } else {
          file.close();
          return 0;
        }
        file.close();
        return result;
      }
    }
  }
  return 0;
}
char *vmem::readtxt(const char *filename, int number) {
  fstream file(filename);
  string ln;
  if (file.is_open()) {
    for (int i = 1; getline(file, ln); i++) {
      if (i == number) {
        char *result = new char[ln.length() + 1];
        strcpy(result, ln.c_str());
        file.close();
        return result;
      }
    }
  }
  return 0;
}
float vmem::readfloat(const char *filename, int number) {
  fstream file(filename);
  string ln;
  if (file.is_open()) {
    for (int i = 1; getline(file, ln); i++) {
      if (i == number) {
        size_t sizetyp;
        float result = stof(ln, &sizetyp);
        file.close();
        return result;
      }
    }
  }
  return 0;
}
bool vmem::fexists(const std::string &name) {
  struct stat buffer;
  return (stat(name.c_str(), &buffer) == 0);
}