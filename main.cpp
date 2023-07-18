#include "system_info.h"
#include "system_info_impl.h"

void printUsers(const SystemInfo& systemInfo) {
    vector<UserInfo> users = systemInfo.getAllUsers();
    cout << "\n######################################## All Users\n";
    cout << "UID\t\tUser" << endl;
    for (const auto& user : users) {
        cout << user.uid << "\t:\t" << user.username << endl;
    }
    cout << endl;
}

void printProcesses(const SystemInfo& systemInfo) {
    vector<ProcessInfo> processes = systemInfo.getAllProcesses();
    cout << "\n######################################## Process\n";
    cout << "PID\t\tProcess" << endl;
    for (const auto& process : processes) {
        cout << process.pid << "\t:\t" << process.processName << endl;
    }
}

int main() {
    SystemInfoImpl systemInfo;

    while (true) {
        printUsers(systemInfo);
        printProcesses(systemInfo);
        this_thread::sleep_for(chrono::seconds(5));
    }

    return 0;
}
