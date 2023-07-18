#include "system_info_impl.h"

vector<UserInfo> SystemInfoImpl::getAllUsers() const {
    vector<UserInfo> users;
    struct passwd* pw;

    setpwent();
    while ((pw = getpwent()) != nullptr) {
        UserInfo userInfo;
        userInfo.uid = pw->pw_uid;
        userInfo.username = pw->pw_name;
        users.push_back(userInfo);
    }
    endpwent();

    return users;
}

vector<ProcessInfo> SystemInfoImpl::getAllProcesses() const {
    vector<ProcessInfo> processes;

    DIR* dir = opendir("/proc");
    if (dir != nullptr) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_DIR) {
                pid_t pid = atoi(entry->d_name);
                if (pid != 0) {
                    ProcessInfo processInfo;
                    processInfo.pid = pid;

                    string commPath = string("/proc/") + entry->d_name + "/comm";
                    ifstream commFile(commPath.c_str());
                    if (commFile.is_open()) {
                        getline(commFile, processInfo.processName);
                        commFile.close();
                        processes.push_back(processInfo);
                    }
                }
            }
        }
        closedir(dir);
    }

    return processes;
}
