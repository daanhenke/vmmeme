#pragma once

#include <efi.hh>

namespace efil::gfx
{
    void GetResolution(int& width, int& height);
    void ClearScreen(efi::u8 red = 0, efi::u8 green = 0, efi::u8 blue = 0);
    void DrawImage();
    void GraphicsTest();
    void DrawPixel(int x, int y, efi::u8 red, efi::u8 green, efi::u8 blue);
}
