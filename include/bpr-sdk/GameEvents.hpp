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
        alignas(0x10) float Position[3];
        alignas(0x10) float Direction[3];
        uint64_t VehicleID;
        uint64_t WheelID;

        static constexpr int32_t GetID()
        {
            return 0;
        }

        static constexpr uint32_t GetSize()
        {
            return 0x30;
        }
    };

    struct GameEvent_TeleportPlayerVehicle
    {
        alignas(0x10) float Position[3];
        alignas(0x10) float Direction[3];

        static constexpr int32_t GetID()
        {
            return 1;
        }

        static constexpr uint32_t GetSize()
        {
            return 0x20;
        }
    };

    struct GameEvent_ChangePlayerVehicle
    {
        uint64_t VehicleID;
        uint64_t WheelID;
        bool ResetPlayerCamera;
        bool KeepResetSection;

        static constexpr int32_t GetID()
        {
            return 2;
        }

        static constexpr uint32_t GetSize()
        {
            return 0x18;
        }
    };
}
