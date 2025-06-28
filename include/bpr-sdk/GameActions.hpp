#pragma once


#include <cstdint>


namespace BPR
{
    // bool __thiscall CgsModule::VariableEventQueue<13312, 16>::AddEvent(const CgsModule::Event*, int32_t, int32_t)
    inline bool GameActionQueue_AddGameAction(void* gameActionQueue, const void* gameAction, int32_t gameActionID, int32_t gameActionSize)
    {
        bool result = false;
        
        __asm
        {
            push dword ptr [gameActionSize]
            push dword ptr [gameActionID]
            push dword ptr [gameAction]
            mov ecx, dword ptr [gameActionQueue]
            
            mov eax, 0x004C0590
            call eax

            mov byte ptr [result], al
        }

        return result;
    }


    enum class VehicleType
    {
        Invalid = -1,
        Car = 0,
        Motorbike = 1,
        Plane = 2,
    };

    enum class BoostType
    {
        Speed = 0,
        Aggression = 1,
        Stunt = 2,
        None = 3,
        Locked = 4,
    };

    // BrnWorld::CarControl
    enum class PlayerVehicleDriver
    {
        None = 0,
        Player = 1,
        AI = 2,
    };

    // BrnPhysics::Deformation::DeformationResetType
    enum class DeformationType
    {
        None = -1,
        Event = 0,
        VehicleSelect = 1,
    };

    // BrnGameState::GameStateModuleIO::ResetPlayerCarAction::CarSelectType
    enum class VehicleSelectType
    {
        DontDrop = 0,
        DropNormal = 1,
        DropShutdown = 2,
    };


    // BrnGameState::GameStateModuleIO::ResetPlayerCarAction
    struct GameAction_ResetPlayerVehicle
    {
        // BrnGameState::GameStateModuleIO::EGameActionType::E_ACTION_RESET_PLAYER_CAR
        static constexpr int32_t ID = 0;

        alignas(16) float Position[4];
        alignas(16) float Direction[4];
        uint64_t VehicleID;
        uint64_t WheelID;
        int32_t PlayerScoringIndex;
        float DeformationAmount;
        DeformationType DeformationType;
        VehicleSelectType VehicleSelectType;
        VehicleType VehicleType;
        bool InVehicleSelect;
        bool VehicleSelectDontStreamAudio;
        bool ResetPlayerCamera;
        bool KeepResetSection;
        bool Unknown1;
        int32_t Unknown2;
    };

    // BrnGameState::GameStateModuleIO::ResetPlayerCarOnTrackAction
    struct GameAction_ResetPlayerVehicleOnTrack
    {
        // BrnGameState::GameStateModuleIO::EGameActionType::E_ACTION_RESET_PLAYER_CAR_ON_TRACK
        static constexpr int32_t ID = 3;
        
        float Speed;
    };

    // BrnGameState::GameStateModuleIO::SetupNetworkCarAction
    struct GameAction_SetupNetworkVehicle
    {
        // BrnGameState::GameStateModuleIO::EGameActionType::E_ACTION_SETUP_NETWORK_CAR
        static constexpr int32_t ID = 5;
        
        alignas(16) float Position[4];
        alignas(16) float At[4];
        uint64_t VehicleID;
        uint64_t WheelID;
        int32_t ActiveRaceVehicleIndex;
        int32_t PlayerScoringIndex;
        float DeformationAmount;
    };

    // BrnGameState::GameStateModuleIO::SetPlayerCarDriverAction
    struct GameAction_SetPlayerVehicleDriver
    {
        // BrnGameState::GameStateModuleIO::EGameActionType::E_ACTION_SET_PLAYER_CAR_DRIVER
        static constexpr int32_t ID = 7;

        PlayerVehicleDriver PlayerVehicleDriver;
        struct
        {
            float Position[3];
            float Rotation[3];
            float Dimension[3];
        } DriveThruBoxRegion;
        float MaxResetSpeed;
        bool IsDriveThru;
    };

    // BrnGameState::GameStateModuleIO::PauseSimulationAction
    struct GameAction_PauseSimulation
    {
        // BrnGameState::GameStateModuleIO::EGameActionType::E_ACTION_PAUSE_SIMULATION
        static constexpr int32_t ID = 100;
    };

    // BrnGameState::GameStateModuleIO::UnpauseSimulationAction
    struct GameAction_UnpauseSimulation
    {
        // BrnGameState::GameStateModuleIO::EGameActionType::E_ACTION_UNPAUSE_SIMULATION
        static constexpr int32_t ID = 101;
    };

    // BrnGameState::GameStateModuleIO::SetBoostAction
    struct GameAction_SetBoost
    {
        // BrnGameState::GameStateModuleIO::EGameActionType::E_ACTION_SET_BOOST
        static constexpr int32_t ID = 197;
        
        int32_t ActiveRaceVehicleIndex;
        struct
        {
            bool InfiniteBoost : 1;
            bool BoostAmount : 1;
            bool BoostSegments : 1;
            bool BoostEarningEnabled : 1;
            bool BoostMessagesEnabled : 1;
            bool EmptyBoost : 1;
        } Flags;
        float BoostAmount;
        int32_t BoostSegments;
        bool InfiniteBoost;
        bool BoostEarningEnabled;
        bool BoostMessagesEnabled;
    };

    // BrnGameState::GameStateModuleIO::SendCarStatsAction
    struct GameAction_UpdateVehicleStats
    {
        // BrnGameState::GameStateModuleIO::EGameActionType::E_ACTION_UPDATE_CAR_STATS
        static constexpr int32_t ID = 230;
        
        int32_t Speed;
        int32_t Strength;
        int32_t BoostLossLevel;
        int32_t BoostLevel;
        float DamageLimit;
        BoostType BoostType;
    };
}
