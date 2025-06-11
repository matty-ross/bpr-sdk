#pragma once


#include <cstdint>


namespace BPR
{
    // CgsID CgsIDCompress(const char* lcpString)
    inline uint64_t CgsID_Compress(const char* string)
    {
        uint64_t id = 0;

        __asm
        {
            mov ecx, dword ptr [string]

            mov eax, 0x0086CED0
            call eax

            mov dword ptr [id + 0x0], eax
            mov dword ptr [id + 0x4], edx
        }

        return id;
    }

    // void CgsIDUnCompress(CgsID lID, char* lcpString)
    inline void CgsID_Uncompress(uint64_t id, char* string)
    {
        __asm
        {
            mov ecx, dword ptr [string]
            push dword ptr [id + 0x4]
            push dword ptr [id + 0x0]

            mov eax, 0x0086CE40
            call eax
            add esp, 0x8
        }
    }

    // void CgsIDConvertToString(CgsID lID, char* lpcString)
    inline void CgsID_ConvertToString(uint64_t id, char* string)
    {
        __asm
        {
            mov ecx, dword ptr [string]
            push dword ptr [id + 0x4]
            push dword ptr [id + 0x0]

            mov eax, 0x0086CE00
            call eax
            add esp, 0x8
        }
    }
}
