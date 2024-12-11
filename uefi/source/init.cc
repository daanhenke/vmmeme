#include <efil.hh>
#include "private.hh"

namespace efil
{
    efi::Handle         ImageHandle = nullptr;
    efi::SystemTable*   SystemTable = nullptr;

    void Initialize(efi::Handle imageHandle, efi::SystemTable* systemTable)
    {
        ImageHandle = imageHandle;
        SystemTable = systemTable;
    }
}
