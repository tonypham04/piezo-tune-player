/**
 * Piezo Tune Player
 *
 * This sketch is a fan cover to the song 'Aozora no Rhapsody' by fhána from the anime 'Miss Kobayshi's Dragon Maid'.
 * Using a piezo buzzer the main melody for the song is played.
 *
 * @author Tony Pham
 */
 // TODO: Add a new tune (Sasageyo, Kaikai Kitan, no. 1)?
 // TODO: Add support for a 7-segment (updates to: Fritzing, README, circuit, sketch)
 // TODO: In the serial monitor add "NOW PLAYING ________ " when playing a tune?
 // TODO: Fix some timing issues (in particular the chorus for Miss Kobayashi Op 1)

#include "Playlist.h"
#include "Error.h"

/* Constants for 7-Segment Display */
const byte DIGITAL_ZERO = {B00000011};
const byte DIGITAL_ONE = {B10011111};
const byte DIGITAL_TWO = {B00100101};
const byte DIGITAL_THREE = {B00001101};
const byte DIGITAL_FOUR = {B10011001};
const byte DIGITAL_FIVE = {B01001001};
const byte DIGITAL_SIX = {B01000001};
const byte DIGITAL_SEVEN = {B00011111};
const byte DIGITAL_EIGHT = {B00000001};
const byte DIGITAL_NINE = {B00001001};

/* Global Variables */
const int PIEZO_PIN = 15;
const int SER = 17;
const int LATCH = 18;
const int SRCLK = 19;

void setup()
{
  pinMode(PIEZO_PIN, OUTPUT);
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(SRCLK, OUTPUT);

  digitalWrite(SER, LOW);
  digitalWrite(LATCH, LOW);
  digitalWrite(SRCLK, LOW);
}

void loop()
{
  testDigitalNumbers();
}

/**
 * This function plays a tune using the piezo buzzer.
 * @param piezoPin - Pin corresponding to the piezo buzzer.
 * @param tuneNotes[] - Array containing the notes of the tune.
 * @param tuneDurations[] - Array containing the duration each note should be played.
 * @param numNotes - The number of notes (needs to be provided as when passed into a function an array is treated as a pointer to the start of the array)
 */
void playTune(const int piezoPin, const int tuneNotes[], const float tuneDurations[], const int numNotes)
{
  for (int i = 0; i < numNotes; i++)
  {
    tone(piezoPin, tuneNotes[i]);
    delay(1000 * tuneDurations[i]);
    noTone(piezoPin);
  }
}

/**
 * This function plays one specific tune from the selection of available tunes.
 * If the specified tune is not available, a cover of "Game Over" theme from Super Mario Sunshine is played on the piezo buzzer.
 * @param tune - Integer representation of a tune
 */
void playSelectTune(int tune)
{
  int missKobayashiOpTuneLength;
  int superMarioSunshineGameOverTuneLength;
  int aiNoSupremeLength;
  switch(tune)
  {
    case MISS_KOBAYASHI_OP:
      missKobayashiOpTuneLength = sizeof(missKobayashiOpTune) / sizeof(missKobayashiOpTune[0]);
      playTune(PIEZO_PIN, missKobayashiOpTune, missKobayashiOpDurations, missKobayashiOpTuneLength);
      break;
    case AI_NO_SUPREME:
      aiNoSupremeLength = sizeof(AI_NO_SUPREME_TUNE) / sizeof(AI_NO_SUPREME_TUNE[0]);
      playTune(PIEZO_PIN, AI_NO_SUPREME_TUNE, AI_NO_SUPREME_DURATIONS, aiNoSupremeLength);
      break;
    default:
      superMarioSunshineGameOverTuneLength = sizeof(SUPER_MARIO_SUNSHINE_GAME_OVER_TUNE) / sizeof(SUPER_MARIO_SUNSHINE_GAME_OVER_TUNE[0]);
      playTune(PIEZO_PIN, SUPER_MARIO_SUNSHINE_GAME_OVER_TUNE, SUPER_MARIO_SUNSHINE_GAME_OVER_DURATIONS, superMarioSunshineGameOverTuneLength);
      break;
  }
}

/**
 * Updates the 7-segment display with the specified number.
 */
void updateSevenSegmentDisplay(int numToDisplay)
{
  digitalWrite(LATCH, LOW);
  switch(numToDisplay)
  {
    case 1:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_ONE);
      break;
    case 2:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_TWO);
      break;
    case 3:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_THREE);
      break;
    case 4:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_FOUR);
      break;
    case 5:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_FIVE);
      break;
    case 6:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_SIX);
      break;
    case 7:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_SEVEN);
      break;
    case 8:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_EIGHT);
      break;
    case 9:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_NINE);
      break;
    default:
      shiftOut(SER, SRCLK, LSBFIRST, DIGITAL_ZERO);
      break;
  }
  digitalWrite(LATCH, HIGH);
}

/* DEBUG/TEST FUNCTIONS */

/**
 * This test function confirms that the playSelectTune function will play an error tune when the specified tune is not available.
 */
void testPlaySelectTuneDefault()
{
  playSelectTune(SUPER_MARIO_SUNSHINE_GAME_OVER);
}

/**
 * This test function confirms that the digital constants are correct representations of their respective numbers by cycling through the numbers 0-9 and displaying them on the 7-segment display.
 */
void testDigitalNumbers()
{
  // There are 10 numbers to test from 0-9
  for (int i = 0; i <= 9; i++)
  {
      updateSevenSegmentDisplay(i);
      delay(1000);
  }
}

/**
 * References
 * 1. 'Aozora no Rhapsody' played with Synthesia uploaded by 'MyReminiscence': https://www.youtube.com/watch?v=sG9tKEV510s
 * 2. 'Project 12 - Piezo Sounder Melody Player' from the 'Beginning Arduino' textbook written by Michael Roberts
 * 3. Physics of Music - Notes: https://pages.mtu.edu/~suits/notefreqs.html
 * 4. Music video to the original song: https://www.youtube.com/watch?v=maKok2RItxM
 */
