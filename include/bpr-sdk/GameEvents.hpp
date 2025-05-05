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


    struct GameEvent_SetupPlayerVehicle
    {
        static constexpr int32_t GetID()
        {
            return 0;
        }

        alignas(16) float Position[3];
        alignas(16) float Direction[3];
        uint64_t VehicleID;
        uint64_t WheelID;
    };

    struct GameEvent_TeleportPlayerVehicle
    {
        static constexpr int32_t GetID()
        {
            return 1;
        }

        alignas(16) float Position[3];
        alignas(16) float Direction[3];
    };

    struct GameEvent_ChangePlayerVehicle
    {
        static constexpr int32_t GetID()
        {
            return 2;
        }

        uint64_t VehicleID;
        uint64_t WheelID;
        bool ResetPlayerCamera;
        bool KeepResetSection;
    };
}
