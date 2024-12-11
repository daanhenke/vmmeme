#pragma once

#include <stdint.h>

namespace efi
{
    using Handle = void*;

    using u8    = uint8_t;
    using u16   = uint16_t;
    using u32   = uint32_t;
    using u64   = uint64_t;

    using s8    = int8_t;
    using s16   = int16_t;
    using s32   = int32_t;
    using s64   = int64_t;

    using Status = u64;

    using Time = struct
    {
        u16 Year;
        u8  Month;
        u8  Day;
        u8  Hour;
        u8  Minute;
        u8  Second;
        u8  _pad0;
        u32 Nanosecond;
        s16 Timezone;
        u8  Daylight;
        u8  _pad1;
    };

    using TableHeader = struct
    {
        u64 Signature;
        u32 Revision;
        u32 HeaderSize;
        u32 CRC32;
        u32 Reserved;
    };
}
