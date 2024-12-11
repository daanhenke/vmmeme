#pragma once

#include <efi/primitives.hh>

namespace efi
{
    using BootServices = struct
    {
        TableHeader Header;
    };
}
