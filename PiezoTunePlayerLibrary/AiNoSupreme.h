#include "Note.h"
#include "Duration.h"

// const int AI_NO_SUPREME_TUNE[] = {
//     NOTE_D4, NOTE_E4, NOTE_FS4,
//     NOTE_B3, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_D4,
//     NOTE_E4, NOTE_FS4, NOTE_G4,
//     NOTE_FS4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4,
//     NOTE_FS4, NOTE_G4, NOTE_A4,
//     NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_D4, NOTE_FS4,
//     NOTE_G4, NOTE_A4, NOTE_B4,
//     NOTE_D5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_FS4,
//     NOTE_FS5, NOTE_G5, NOTE_A5,
//     NOTE_D5, NOTE_D5, NOTE_FS5, NOTE_D5, NOTE_FS5,
//     NOTE_G5, NOTE_A5, NOTE_B5,
//     NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_E5,
//     NOTE_FS5, NOTE_G5, NOTE_A5,
//     NOTE_D5, NOTE_D5, NOTE_FS5, NOTE_D5, NOTE_FS5,
//     NOTE_G5, NOTE_A5, NOTE_B5,
//     NOTE_D6, NOTE_D6, NOTE_B5, NOTE_A5, NOTE_FS5,
//     NOTE_A4, REST, NOTE_AS4, REST, NOTE_AS4, REST, NOTE_G4, REST, NOTE_A4, REST, NOTE_A4, REST,
//     NOTE_A4, REST, NOTE_AS4, REST, NOTE_AS4, REST, NOTE_G4, REST, NOTE_A4, REST, NOTE_A4, REST,
//     NOTE_A4, REST, NOTE_AS4, REST, NOTE_G4, REST, NOTE_A4, REST,
//     NOTE_A4, REST, NOTE_AS4, REST, NOTE_G4, REST, NOTE_F4, REST,
//     NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4,
//     NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_E4,
//     NOTE_C4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4,
//     NOTE_C5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5,
//     NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5,
//     NOTE_C5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_F6
// };

// const float AI_NO_SUPREME_DURATIONS[] = {
//     QUARTER, QUARTER, HALF,
//     QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
//     QUARTER, QUARTER, HALF,
//     QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
//     QUARTER, QUARTER, HALF,
//     QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
//     QUARTER, QUARTER, HALF,
//     QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
//     QUARTER, QUARTER, HALF,
//     QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
//     QUARTER, QUARTER, HALF,
//     QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
//     QUARTER, QUARTER, HALF,
//     QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
//     QUARTER, QUARTER, HALF,
//     QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
//     HALF, EIGHTH, HALF, EIGHTH, QUARTER, EIGHTH, HALF, EIGHTH, HALF, EIGHTH, QUARTER, EIGHTH,
//     HALF, EIGHTH, HALF, EIGHTH, QUARTER, EIGHTH, HALF, EIGHTH, HALF, EIGHTH, QUARTER, EIGHTH,
//     HALF, EIGHTH, WHOLE, EIGHTH, HALF, EIGHTH, WHOLE, EIGHTH,
//     HALF, EIGHTH, WHOLE, EIGHTH, HALF, EIGHTH, WHOLE, EIGHTH,
//     EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
//     EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
//     EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
//     EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
//     EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
//     EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH
// };

const int AI_NO_SUPREME_TUNE[] = {
    NOTE_GS4, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_C5,
    NOTE_GS4, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_C5,
    NOTE_GS4, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_C5,
    NOTE_GS4, NOTE_GS4, NOTE_AS4, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS4, NOTE_C5,
    NOTE_GS3, NOTE_AS3, NOTE_CS4,
    NOTE_GS3, NOTE_GS3, NOTE_CS4, NOTE_DS4,
    NOTE_GS4, NOTE_C5, NOTE_GS4, NOTE_C5,
    NOTE_DS4, NOTE_DS4, NOTE_D4, NOTE_CS4, NOTE_C4,
    NOTE_C4, NOTE_F4, NOTE_AS4, NOTE_C5, NOTE_F5, NOTE_AS5, NOTE_C6, NOTE_C6, REST, NOTE_C6, NOTE_C6
};

const float AI_NO_SUPREME_DURATIONS[] = {
    QUARTER, QUARTER, QUARTER,
    QUARTER, EIGHTH, QUARTER, HALF,
    QUARTER, EIGHTH, QUARTER, HALF,
    QUARTER, EIGHTH, QUARTER, HALF,
    QUARTER, QUARTER, QUARTER,
    QUARTER, EIGHTH, QUARTER, HALF,
    QUARTER, EIGHTH, QUARTER, HALF,
    QUARTER, QUARTER, QUARTER,
    QUARTER, EIGHTH, QUARTER, HALF,
    QUARTER, EIGHTH, QUARTER, HALF,
    QUARTER, EIGHTH, QUARTER, HALF,
    QUARTER, QUARTER, QUARTER, QUARTER,
    QUARTER, EIGHTH, QUARTER, HALF,
    EIGHTH, EIGHTH, EIGHTH,
    EIGHTH, EIGHTH, EIGHTH, EIGHTH,
    QUARTER, QUARTER, QUARTER, QUARTER,
    EIGHTH, QUARTER, QUARTER, QUARTER, HALF,
    QUARTER, QUARTER, QUARTER, QUARTER, QUARTER, QUARTER, EIGHTH, EIGHTH, QUARTER, EIGHTH, EIGHTH
};

// TIMESTAMP: 0:53
/**
 * References
 * 1. Kobayashi-san Chi no Maid Dragon S OP - "Ai no Supreme" | Piano Arrangement [Synthesia+Sheets] by Sakura Melodies: https://www.youtube.com/watch?v=dxH4w3Ptqps
 * 2. Ai no Supreme - Kobayashi-san Chi no Maid Dragon Season 2 OP | fhána (piano) by Anime Pro - Anime on Piano: https://www.youtube.com/watch?v=tvxmcW0GKbg
 */