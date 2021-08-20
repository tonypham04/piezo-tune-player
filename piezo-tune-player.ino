/**
 * Piezo Tune Player
 *
 * This sketch is a fan cover to the song 'Aozora no Rhapsody' by fhána from the anime 'Miss Kobayshi's Dragon Maid'.
 * Using a piezo buzzer the main melody for the song is played.
 *
 * @author Tony Pham
 */

/* Note sounds frequencies */
#define REST 0
#define NOTE_G3 196
#define NOTE_AS3 233
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_C4 262
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440

 /* Note durations */
#define WHOLE 1.0
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.125

/* Global Variables */
const int PIEZO_PIN = 15;
int tuneLength;

/* Tune Variables */
const int missKobayashiOpTune[] = {
  NOTE_C5, NOTE_D5, NOTE_C5,
  NOTE_C4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5,
  REST,
  NOTE_D5, NOTE_C5,
  NOTE_C4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5,
  REST,
  NOTE_D5, NOTE_D5, NOTE_C5,
  NOTE_C4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5,
  REST,
  NOTE_D5, NOTE_C5,
  NOTE_C4, NOTE_A4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3,
  NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_AS3
};
const float missKobayashiOpDurations[] = {
  QUARTER, QUARTER, QUARTER,
  QUARTER, EIGHTH, EIGHTH, QUARTER, EIGHTH, EIGHTH,
  QUARTER,
  HALF, QUARTER,
  QUARTER, EIGHTH, EIGHTH, QUARTER, EIGHTH, EIGHTH,
  QUARTER,
  QUARTER, QUARTER, QUARTER,
  QUARTER, EIGHTH, EIGHTH, QUARTER, EIGHTH, EIGHTH,
  QUARTER,
  HALF, QUARTER,
  QUARTER, HALF, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  QUARTER, QUARTER, QUARTER, HALF,
  QUARTER, QUARTER, QUARTER, HALF
};

void setup() {
  pinMode(PIEZO_PIN, OUTPUT);
  tuneLength = sizeof(missKobayashiOpTune) / sizeof(missKobayashiOpTune[0]);
}

void loop() {
  for (int i = 0; i < tuneLength; i++) {
    tone(PIEZO_PIN, missKobayashiOpTune[i]);
    delay(1000 * missKobayashiOpDurations[i]);
    noTone(PIEZO_PIN);
  }
  delay(500);
}

/**
 * References
 * 1. 'Aozora no Rhapsody' played with Synthesia uploaded by 'MyReminiscence': https://www.youtube.com/watch?v=sG9tKEV510s
 * 2. 'Project 12 - Piezo Sounder Melody Player' from the 'Beginning Arduino' textbook written by Michael Roberts
 * 3. Physics of Music - Notes: https://pages.mtu.edu/~suits/notefreqs.html
 */
