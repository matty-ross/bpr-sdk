#pragma once


#include <cstdint>


namespace BPR
{
    uint64_t ResourceID_GetHash(const char* string)
    {
        uint64_t id = 0;
        
        __asm
        {
            mov ecx, dword ptr [string]

            mov eax, 0x008FD5B0
            call eax

            mov dword ptr [id + 0x0], eax
            mov dword ptr [id + 0x4], edx
        }

        return id;
    }
    
    void* ResourcePool_FindResource(void* resourcePool, bool allowNoRef, uint8_t status, int32_t* index, uint64_t id)
    {
        void* resource = nullptr;
        
        __asm
        {
            push dword ptr [id + 0x4]
            push dword ptr [id + 0x0]
            push dword ptr [index]
            push byte ptr [status]
            push byte ptr [allowNoRef]
            mov ecx, dword ptr [resourcePool]
            
            mov eax, 0x008F12A0
            call eax

            mov dword ptr [resource], eax
        }

        return resource;
    }
}
