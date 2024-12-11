#pragma once

#include <efi.hh>

namespace efil
{
    void Initialize(efi::Handle imageHandle, efi::SystemTable* systemTable);

    void LogWideString(const wchar_t* string);
    void LogString(const char* string);
}
