#pragma once


#include <cstdint>


namespace BPR
{
    struct Resource
    {
        void* Memory[3];
    };
    
    
    uint64_t ResourceID_GetHash(const char* resourceName)
    {
        uint64_t id = 0;
        
        __asm
        {
            mov ecx, dword ptr [resourceName]

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
            movzx eax, byte ptr [status]
            push eax
            movzx eax, byte ptr [allowNoRef]
            push eax
            mov ecx, dword ptr [resourcePool]
            
            mov eax, 0x008F12A0
            call eax

            mov dword ptr [resource], eax
        }

        return resource;
    }

    Resource* PoolModule_FindResource(const char* resourceName)
    {
        uint64_t resourceId = ResourceID_GetHash(resourceName);

        for (int i = 0; i < 128; ++i)
        {
            uintptr_t resourcePool = *reinterpret_cast<uintptr_t*>(0x013FC8E0) + 0x64E628 + i * 0x1D8;
            
            int32_t poolId = *reinterpret_cast<int32_t*>(resourcePool + 0x118);
            if (poolId != -1)
            {
                void* resourceEntry = ResourcePool_FindResource(reinterpret_cast<void*>(resourcePool), false, 2, nullptr, resourceId);
                if (resourceEntry != nullptr)
                {
                    return reinterpret_cast<Resource*>(reinterpret_cast<uintptr_t>(resourceEntry) + 0x28);
                }
            }
        }

        return nullptr;
    }
}
