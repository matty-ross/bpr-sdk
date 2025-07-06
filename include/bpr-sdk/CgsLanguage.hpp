#pragma once


#include <cstdint>


namespace BPR
{
    // CgsLanguage::LanguageManager::ParameterFormatType
    enum class TextFormatType
    {
        Text = 0,                     // "text" -> "text"
        TimeOfDay = 1,                // "12345.6789" -> "03:25 am"
        HoursMinutesSeconds = 2,      // "12345.6789" -> "03:25:46"
        MinutesSecondsHundredths = 3, // "12345.6789" -> "205:45,68"
        MinutesSeconds = 4,           // "12345.6789" -> "205:46"
        SecondsHundredths = 5,        // "12345.6789" -> "12345.68"
        SecondsHundredthsLong = 6,    // "12345.6789" -> "12345.68 Seconds"
        Seconds = 7,                  // "12345.6789" -> "12346"
        SecondsLong = 8,              // "12345.6789" -> "12346 Seconds"
        MinutesSecondsMidText = 9,    // "12345.6789" -> "205 Min 46 Secs"
        IdLookup = 10,                // "CAR_PUSMC01" -> "Cavalry"
        IdLookupToUpper = 11,         // "CAR_PUSMC01" -> "CAVALRY"
        Unknown1 = 12,                // "12345.6789" -> "12,345.67"
        Integer = 13,                 // "12345.6789" -> "12,345"
        LargeInteger = 14,            // "12345.6789" -> "12,345"
        IntegerNoSeparator = 15,      // "12345.6789" -> "12345"
        Percentage = 16,              // "12345.6789" -> "12345%"
        Money = 17,                   // "12345.6789" -> "$12,345"
        AutoDistance = 18,            // "12345.6789" -> "12.3 km"
        AutoDistanceLong = 19,        // "12345.6789" -> "12.3 Kilometers"
        SmallDistance = 20,           // "12345.6789" -> "12,346 m"
        SmallDistanceLong = 21,       // "12345.6789" -> "12,346 Meters"
        SmallDistanceRounded = 22,    // "12345.6789" -> "12,350 m"
        LargeDistance = 23,           // "12345.6789" -> "12.3 km"
        LargeDistanceLong = 24,       // "12345.6789" -> "12.3 Kilometers"
        Unknown2 = 25,                // "12345.6789" -> "12,345 "
    };

    
    // bool __thiscall CgsLanguage::LanguageManager::FormatText(char*, uint32_t, const char*, CgsLanguage::LanguageManager::ParameterFormatType)
    inline bool LanguageManager_FormatText(char* buffer, uint32_t bufferSize, const char* text, TextFormatType format)
    {
        bool result = false;

        __asm
        {
            push dword ptr [format]
            push dword ptr [text]
            push dword ptr [bufferSize]
            push dword ptr [buffer]
            mov ecx, dword ptr ds:[0x013FC8E0]
            add ecx, 0x7A0E34

            mov eax, 0x0089BA90
            call eax

            mov byte ptr [result], al
        }

        return result;
    }
}
