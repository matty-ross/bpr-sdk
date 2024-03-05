#pragma once


#include <cstdint>


namespace BPR
{
    bool GameEventQueue_AddGameEvent(void* gameEventQueue, const void* gameEvent, int32_t gameEventID, uint32_t gameEventSize)
    {
        bool result = false;
        
        __asm
        {
            push dword ptr [gameEventSize]
            push dword ptr [gameEventID]
            push dword ptr [gameEvent]
            mov ecx, dword ptr [gameEventQueue]
            
            mov eax, 0x004E3F70
            call eax

            mov byte ptr [result], al
        }

        return result;
    }

    
    struct SetupPlayerVehicleEvent
    {
        static constexpr int32_t k_GameEventID = 0;

        alignas(0x10) float Position[3];
        alignas(0x10) float Direction[3];
        uint64_t VehicleID;
        uint64_t WheelID;
    };

    struct TeleportPlayerVehicleEvent
    {
        static constexpr int32_t k_GameEventID = 1;

        alignas(0x10) float Position[3];
        alignas(0x10) float Direction[3];
    };

    struct ChangePlayerVehicleEvent
    {
        static constexpr int32_t k_GameEventID = 2;

        uint64_t VehicleID;
        uint64_t WheelID;
        bool ResetPlayerCamera;
        bool KeepResetSection;
    };
}
