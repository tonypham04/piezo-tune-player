/**
 * Piezo Tune Player
 *
 * This sketch is a fan cover to the song 'Aozora no Rhapsody' by fhána from the anime 'Miss Kobayshi's Dragon Maid'.
 * Using a piezo buzzer the main melody for the song is played.
 *
 * @author Tony Pham
 */

 // TODO: Move the tune to a separate file (C++ class for tunes?)
 // TODO: Create a separate function for playing tunes? void playTune(int*, int*) or void playTune(Tune)?
 // TODO: Fix some timing issues (in particular the chorus)

#include "Playlist.h"

/* Global Variables */
const int PIEZO_PIN = 15;
int tuneLength;

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
 * 4. Music video to the original song: https://www.youtube.com/watch?v=maKok2RItxM
 */
