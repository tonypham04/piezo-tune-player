#include "Note.h"
#include "Duration.h"

const int SUPER_MARIO_SUNSHINE_GAME_OVER_TUNE[] = {
    NOTE_A6, NOTE_AS6, NOTE_B6,
    REST,
    NOTE_GS4, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4,
    REST,
    NOTE_E4,
    REST,
    NOTE_CS4,
    REST,
    NOTE_FS4, NOTE_GS4, NOTE_FS4,
    NOTE_F4, NOTE_G4, NOTE_F4,
    NOTE_E4, NOTE_D4, NOTE_E4
};

const float SUPER_MARIO_SUNSHINE_GAME_OVER_DURATIONS[] = {
    EIGHTH, EIGHTH, EIGHTH,
    HALF,
    QUARTER, QUARTER, EIGHTH, QUARTER, QUARTER, QUARTER, QUARTER,
    QUARTER,
    QUARTER,
    QUARTER,
    QUARTER,
    QUARTER,
    EIGHTH, QUARTER, EIGHTH,
    QUARTER, QUARTER, EIGHTH,
    EIGHTH, EIGHTH, WHOLE
};

/**
 * References
 * 1. 20 CLASSIC Mario "Game Over" Themes on Piano by Hari Sivan (2:16 is Super Mario Sunshine version): https://www.youtube.com/watch?v=RiLQbORTTK8
 * */