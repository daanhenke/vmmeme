#include <efil.hh>
#include "private.hh"

namespace efil
{
    void LogWideString(const wchar_t* string)
    {
        SystemTable->ConsoleOut->OutputString(SystemTable->ConsoleOut, string);
    }

    void LogString(const char* string)
    {
        wchar_t buffer[1024];

        auto bufferIndex = 0;
        auto stringIndex = 0;

        while (string[stringIndex] != '\0')
        {
            auto chr = string[stringIndex++];
            buffer[bufferIndex++] = static_cast<wchar_t>(chr);

            if (bufferIndex > 1023)
            {
                buffer[bufferIndex] = L'\0';
                LogWideString(buffer);
                bufferIndex = 0;
            }
        }

        buffer[bufferIndex] = L'\0';
        LogWideString(buffer);
    }
}
