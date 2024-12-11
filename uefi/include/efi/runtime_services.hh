#pragma once

#include <efi/primitives.hh>

namespace efi
{
    using RuntimeServices = struct
    {
        TableHeader Header;

        Status (*GetTime)(Time* time, void* capabilities); // TODO: Add capabilities type
        Status (*SetTime)(Time* time);
    };
}
