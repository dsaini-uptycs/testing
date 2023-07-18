#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <dirent.h>
#include <pwd.h>
using namespace std;

struct UserInfo {
    uid_t uid;
    string username;
};

struct ProcessInfo {
    pid_t pid;
    string processName;
};

class SystemInfo {
public:
    virtual ~SystemInfo() {}
    virtual vector<UserInfo> getAllUsers() const = 0;
    virtual vector<ProcessInfo> getAllProcesses() const = 0;
};

void printUsers(const SystemInfo& systemInfo);
void printProcesses(const SystemInfo& systemInfo);

#endif
