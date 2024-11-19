#pragma once


#include <cstdint>


namespace BPR
{
    bool GameActionQueue_AddGameAction(void* gameActionQueue, const void* gameAction, int32_t gameActionID, uint32_t gameActionSize)
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


    struct GameAction_ResetPlayerVehicle
    {
        enum class DeformationType
        {
            None = -1,
            Event = 0,
            VehicleSelect = 1,
        };

        enum class VehicleSelectType
        {
            DontDrop = 0,
            DropNormal = 1,
            DropShutdown = 2,
        };

        enum class VehicleType
        {
            Invalid = -1,
            Car = 0,
            Motorbike = 1,
            Plane = 2,
        };

        alignas(16) float Position[3];
        alignas(16) float Direction[3];
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

        static constexpr int32_t GetID()
        {
            return 0;
        }

        static constexpr uint32_t GetSize()
        {
            return 0x50;
        }
    };

    struct GameAction_ResetPlayerVehicleOnTrack
    {
        float Speed;

        static constexpr int32_t GetID()
        {
            return 3;
        }

        static constexpr uint32_t GetSize()
        {
            return 0x4;
        }
    };

    struct GameAction_SetPlayerVehicleDriver
    {
        enum class PlayerVehicleDriver
        {
            None = 0,
            Player = 1,
            AI = 2,
        };

        PlayerVehicleDriver PlayerVehicleDriver;
        struct
        {
            float Position[3];
            float Rotation[3];
            float Dimension[3];
        } DriveThruBoxRegion;
        float MaxResetSpeed;
        bool IsDriveThru;

        static constexpr int32_t GetID()
        {
            return 7;
        }

        static constexpr uint32_t GetSize()
        {
            return 0x30;
        }
    };

    struct GameAction_SetBoost
    {
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

        static constexpr int32_t GetID()
        {
            return 197;
        }

        static constexpr uint32_t GetSize()
        {
            return 0x14;
        }
    };

    struct GameAction_UpdateVehicleStats
    {
        enum class BoostType
        {
            Speed = 0,
            Aggression = 1,
            Stunt = 2,
            None = 3,
            Locked = 4,
        };
        
        int32_t Speed;
        int32_t Strength;
        int32_t BoostLossLevel;
        int32_t BoostLevel;
        float DamageLimit;
        BoostType BoostType;

        static constexpr int32_t GetID()
        {
            return 230;
        }

        static constexpr uint32_t GetSize()
        {
            return 0x18;
        }
    };
}
