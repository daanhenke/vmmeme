#include <efil.hh>
#include <efi.hh>
#include "private.hh"

namespace efil
{
    efi::protocol::GraphicsOutputProtocol* GraphicsOutput = nullptr;

    void InitializeGraphics()
    {
        auto result = SystemTable->BootServices->LocateProtocol(&efi::guids::GraphicsOutputProtocol, nullptr, reinterpret_cast<void**>(&GraphicsOutput));
        if (result != 0)
        {
            LogString("Failed to locate graphics output protocol\n");
            return;
        }

        auto maxMode = GraphicsOutput->Mode->MaxMode;
        efi::u32 bestMode = 0;
        efi::u32 bestWidth = 0;
        efi::protocol::GraphicsOutputModeInformation* modeInfo;
        efi::u64 modeSize = 0;
        for (efi::u32 i = 0; i < maxMode; i++)
        {
            result = GraphicsOutput->QueryMode(GraphicsOutput, i, &modeSize, &modeInfo);
            if (result != 0)
            {
                LogString("Failed to query graphics output mode\n");
            }

            if (modeInfo->HorizontalResolution > bestWidth)
            {
              bestMode = i;
              bestWidth = modeInfo->HorizontalResolution;
            }
        }

        result = GraphicsOutput->SetMode(GraphicsOutput, bestMode);
        if (result != 0)
        {
            LogString("Failed to set graphics output mode\n");
        }
    }

    namespace gfx
    {
        void ClearScreen(efi::u8 red, efi::u8 green, efi::u8 blue)
        {
            efi::protocol::GraphicsOutputBltPixel pixel;
            pixel.Red = red;
            pixel.Green = green;
            pixel.Blue = blue;

            auto result = GraphicsOutput->Blt(
                GraphicsOutput,
                &pixel,
                efi::protocol::GraphicsOutputBltOperation::VideoFill,
                0, 0, 0, 0,
                GraphicsOutput->Mode->ModeInformation->HorizontalResolution,
                GraphicsOutput->Mode->ModeInformation->VerticalResolution,
                0
            );

            if (result != 0)
            {
                LogString("Failed to blt\n");
            }
        }

        void GraphicsTest()
        {
            for (auto x = 0; x < GraphicsOutput->Mode->ModeInformation->HorizontalResolution; x++)
            {
                for (auto y = 0; y < GraphicsOutput->Mode->ModeInformation->VerticalResolution; y++)
                {
                    DrawPixel(x, y, x, 0, y);
                }
            }
        }

        void DrawPixel(int x, int y, efi::u8 red, efi::u8 green, efi::u8 blue)
        {
                        efi::protocol::GraphicsOutputBltPixel pixel;
            pixel.Red = red;
            pixel.Green = green;
            pixel.Blue = blue;

            auto result = GraphicsOutput->Blt(
                GraphicsOutput,
                &pixel,
                efi::protocol::GraphicsOutputBltOperation::VideoFill,
                0, 0, x, y,
                1, 1,
                0
            );

            if (result != 0)
            {
                LogString("Failed to blt\n");
            }
        }
    }
}
