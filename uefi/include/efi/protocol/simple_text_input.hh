#pragma once

namespace efi::protocol
{
    using SimpleTextInputProtocol = struct _SimpleTextInputProtocol
    {
        Status (*Reset)(_SimpleTextInputProtocol* self, bool extendedVerification);
    };
}
