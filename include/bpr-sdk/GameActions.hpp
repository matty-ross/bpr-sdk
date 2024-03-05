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


    struct ResetPlayerVehicleOnTrackAction
    {
        static constexpr int32_t k_GameActionID = 3;
        
        float Speed;
    };
}
