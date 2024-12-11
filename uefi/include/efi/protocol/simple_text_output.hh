#pragma once

namespace efi::protocol
{
    using SimpleTextOutputProtocol = struct _SimpleTextOutputProtocol
    {
        Status (*Reset)(_SimpleTextOutputProtocol* self, bool extendedVerification);
        Status (*OutputString)(_SimpleTextOutputProtocol* self, const wchar_t* string);
    };
}
