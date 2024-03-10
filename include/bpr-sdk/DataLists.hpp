#pragma once


#include <cstdint>


namespace BPR
{
    void* VehicleList_GetVehicleData(void* vehicleList, int32_t vehicleIndex)
    {
        void* vehicleData = nullptr;

        __asm
        {
            push dword ptr [vehicleIndex]
            mov ecx, dword ptr [vehicleList]
            
            mov eax, 0x004B7050
            call eax

            mov dword ptr [vehicleData], eax
        }

        return vehicleData;
    }

    void* VehicleList_GetVehicleData(void* vehicleList, uint64_t vehicleID)
    {
        void* vehicleData = nullptr;
        
        __asm
        {
            push dword ptr [vehicleID + 0x4]
            push dword ptr [vehicleID + 0x0]
            mov ecx, dword ptr [vehicleList]
            
            mov eax, 0x004B7080
            call eax

            mov dword ptr [vehicleData], eax
        }

        return vehicleData;
    }

    int32_t VehicleList_GetVehicleIndex(void* vehicleList, uint64_t vehicleID)
    {
        int32_t vehicleIndex = -1;
        
        __asm
        {
            push dword ptr [vehicleID + 0x4]
            push dword ptr [vehicleID + 0x0]
            mov ecx, dword ptr [vehicleList]
            
            mov eax, 0x004B70D0
            call eax

            mov dword ptr [vehicleIndex], eax
        }

        return vehicleIndex;
    }


    int32_t WheelList_FindWheelIndexFromName(void* wheelList, const char* wheelName)
    {
        int32_t wheelIndex = -1;

        __asm
        {
            push dword ptr [wheelName]
            mov ecx, dword ptr [wheelList]
            
            mov eax, 0x004E2A10
            call eax

            mov dword ptr [wheelIndex], eax
        }

        return wheelIndex;
    }


    void* ChallengeList_GetChallengeData(void* challengeList, uint64_t challengeID)
    {
        void* challengeData = nullptr;
        
        __asm
        {
            push dword ptr [challengeID + 0x4]
            push dword ptr [challengeID + 0x0]
            mov ecx, dword ptr [challengeList]

            mov eax, 0x004B6ED0
            call eax

            mov dword ptr [challengeData], eax
        }

        return challengeData;
    }

    int32_t ChallengeList_GetChallengeIndex(void* challengeList, uint64_t challengeID)
    {
        int32_t challengeIndex = -1;
        
        __asm
        {
            push dword ptr [challengeID + 0x4]
            push dword ptr [challengeID + 0x0]
            mov ecx, dword ptr [challengeList]
            
            mov eax, 0x004B6F20
            call eax

            mov dword ptr [challengeIndex], eax
        }

        return challengeIndex;
    }
}
