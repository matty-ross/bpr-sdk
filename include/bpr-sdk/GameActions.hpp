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
}
