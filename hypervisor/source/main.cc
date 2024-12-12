#include <efi.hh>
#include <efil.hh>

efi::Status UefiMain(efi::Handle imageHandle, efi::SystemTable* systemTable)
{
    efil::Initialize(imageHandle, systemTable);
    efil::InitializeGraphics();
    efil::gfx::ClearScreen(128, 0, 0);
    efil::gfx::GraphicsTest();

    efil::LogString("Hello World!");
    while(1);

    return 0;
}
