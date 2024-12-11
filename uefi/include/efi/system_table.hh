#pragma once

#include <efi/boot_services.hh>
#include <efi/runtime_services.hh>

#include <efi/protocol/simple_text_input.hh>
#include <efi/protocol/simple_text_output.hh>

namespace efi
{
    using SystemTable = struct
    {
        TableHeader Header;
        wchar_t*                            FirmwareVendor;
        u32                                 FirmwareRevision;

        Handle                              ConsoleInHandle;
        protocol::SimpleTextInputProtocol*  ConsoleIn;

        Handle                              ConsoleOutHandle;
        protocol::SimpleTextOutputProtocol* ConsoleOut;

        Handle                              ConsoleErrorHandle;
        protocol::SimpleTextOutputProtocol* ConsoleError;

        u64                                 ConfigurationTableEntryCount;
        void*                               ConfigurationTable;
    };
}
