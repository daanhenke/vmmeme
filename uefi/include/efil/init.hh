#pragma once

#include <efi.hh>

namespace efil
{
    void Initialize(efi::Handle imageHandle, efi::SystemTable* systemTable);
    void InitializeGraphics();
    void InitializeConsole();
}
