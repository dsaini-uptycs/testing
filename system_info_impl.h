#ifndef SYSTEM_INFO_IMPL_H
#define SYSTEM_INFO_IMPL_H

#include "system_info.h"

class SystemInfoImpl : public SystemInfo {
public:
    vector<UserInfo> getAllUsers() const override;
    vector<ProcessInfo> getAllProcesses() const override;
};

#endif
