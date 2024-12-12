#pragma once

#include <efi.hh>

namespace efi::protocol
{
    enum class GraphicsPixelFormat
    {
        RedGreenBlueReserved8BitPerColor,
        BlueGreenRedReserved8BitPerColor,
        BitMask,
        BltOnly,
        Max
    };

    using PixelBitmask = struct
    {
        u32 RedMask;
        u32 GreenMask;
        u32 BlueMask;
        u32 ReservedMask;
    };

    using GraphicsOutputModeInformation = struct
    {
        u32 Version;
        u32 HorizontalResolution;
        u32 VerticalResolution;
        GraphicsPixelFormat PixelFormat;
        PixelBitmask PixelInformation;
        u32 PixelsPerScanLine;
    };

    using GraphicsOutputProtocolMode = struct
    {
        u32 MaxMode;
        u32 Mode;
        GraphicsOutputModeInformation* ModeInformation;
        u64 SizeOfInfo;
        u64 FrameBufferBaseAddress;
        u64 FrameBufferSize;
    };

    using GraphicsOutputBltPixel = struct
    {
        u8 Blue;
        u8 Green;
        u8 Red;
        u8 Reserved;
    };

    enum class GraphicsOutputBltOperation
    {
        VideoFill,
        VideoToBltBuffer,
        BufferToVideo,
        VideoToVideo,
        Max
    };

    using GraphicsOutputProtocol = struct _GraphicsOutputProtocol
    {
        Status (*QueryMode)(_GraphicsOutputProtocol* self, u32 modeNumber, u64* sizeOfInfo, GraphicsOutputModeInformation** modeInformation);
        Status (*SetMode)(_GraphicsOutputProtocol* self, u32 modeNumber);
        Status (*Blt)(_GraphicsOutputProtocol* self, GraphicsOutputBltPixel* bltBuffer, GraphicsOutputBltOperation operation, u64 sourceX, u64 sourceY, u64 destX, u64 destY, u64 width, u64 height, u64 delta);
        GraphicsOutputProtocolMode* Mode;
    };
}
