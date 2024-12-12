#pragma once

#include <efi/primitives.hh>

namespace efi
{
    using BootServices = struct
    {
        TableHeader Header;

        void (*RaiseTPL)();
        void (*RestoreTPL)();
        void (*AllocatePages)();
        void (*FreePages)();
        void (*GetMemoryMap)();
        void (*AllocatePool)();
        void (*FreePool)();
        void (*CreateEvent)();
        void (*SetTimer)();
        void (*WaitForEvent)();
        void (*SignalEvent)();
        void (*CloseEvent)();
        void (*CheckEvent)();
        void (*InstallProtocolInterface)();
        void (*ReinstallProtocolInterface)();
        void (*UninstallProtocolInterface)();
        void (*HandleProtocol)();
        void* Reserved;
        void (*RegisterProtocolNotify)();
        void (*LocateHandle)();
        void (*LocateDevicePath)();
        void (*InstallConfigurationTable)();
        void (*LoadImage)();
        void (*StartImage)();
        void (*Exit)();
        void (*UnloadImage)();
        void (*ExitBootServices)();
        void (*GetNextMonotonicCount)();
        void (*Stall)();
        void (*SetWatchdogTimer)();
        void (*ConnectController)();
        void (*DisconnectController)();
        void (*OpenProtocol)();
        void (*CloseProtocol)();
        void (*OpenProtocolInformation)();
        void (*ProtocolsPerHandle)();
        void (*LocateHandleBuffer)();
        Status (*LocateProtocol)(const Guid* protocol, void* registration, void** interface);
        void (*InstallMultiplePorotocolInterfaces)();
        void (*UninstallMultipleProtocolInterfaces)();
        void (*CalculateCRC32)();
        void (*CopyMemory)();
        void (*SetMemory)();
        void (*CreateEventEx)();
    };
}
