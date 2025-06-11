#pragma once


#include <cstdint>


namespace BPR
{
    // bool __thiscall CgsModule::VariableEventQueue<5120, 16>::AddEvent(const Event* lpEvent, int32_t liEventId, int32_t liEventSize)
    inline bool GameEventQueue_AddGameEvent(void* gameEventQueue, const void* gameEvent, int32_t gameEventID, uint32_t gameEventSize)
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


    // BrnGameState::GameStateModuleIO::SetupPlayerCarEvent
    struct GameEvent_SetupPlayerVehicle
    {
        // BrnGameState::GameStateModuleIO::EGameEventType::E_EVENT_SETUP_PLAYER_CAR
        static constexpr int32_t GetID()
        {
            return 0;
        }

        alignas(16) float Position[3];
        alignas(16) float Direction[3];
        uint64_t VehicleID;
        uint64_t WheelID;
    };

    // BrnGameState::GameStateModuleIO::TeleportPlayerCarEvent
    struct GameEvent_TeleportPlayerVehicle
    {
        // BrnGameState::GameStateModuleIO::EGameEventType::E_EVENT_TELEPORT_PLAYER_CAR
        static constexpr int32_t GetID()
        {
            return 1;
        }

        alignas(16) float Position[3];
        alignas(16) float Direction[3];
    };

    // BrnGameState::GameStateModuleIO::ChangePlayerCarEvent
    struct GameEvent_ChangePlayerVehicle
    {
        // BrnGameState::GameStateModuleIO::EGameEventType::E_EVENT_CHANGE_PLAYER_CAR
        static constexpr int32_t GetID()
        {
            return 2;
        }

        uint64_t VehicleID;
        uint64_t WheelID;
        bool ResetPlayerCamera;
        bool KeepResetSection;
    };

    // BrnGameState::GameStateModuleIO::ChangeNetworkCarEvent
    struct GameEvent_ChangeNetworkVehicle
    {
        // BrnGameState::GameStateModuleIO::EGameEventType::E_EVENT_CHANGE_NETWORK_CAR
        static constexpr int32_t GetID()
        {
            return 7;
        }

        uint64_t PlayerID;
        uint64_t VehicleID;
        uint64_t WheelID;
        float DeformationAmount;
    };
}
