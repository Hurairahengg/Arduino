int buzzerPin = 7;      // Define the buzzer pin
int startPin = 2;       // Define the start of the wire pin
int endPin = 10;        // Define the end of the wire pin
int togglePin = 3;      // Define the toggle button pin
int ledPin = 11;        // Define the LED pin

int buzzerMelody[] = {
  261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};

int touchCounter = 0;
bool gameStarted = false;

void setup() {
  pinMode(buzzerPin, OUTPUT);         // Set the buzzer pin as an output
  pinMode(startPin, OUTPUT);    // Set the start of the wire pin as an input with internal pull-up resistor
  pinMode(endPin, INPUT_PULLUP);      // Set the end of the wire pin as an input with internal pull-up resistor
  pinMode(togglePin, INPUT_PULLUP);   // Set the toggle button pin as an input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);            // Set the LED pin as an output
}

void loop() {
  if (digitalRead(endPin) == HIGH) {
    // End of the wire is touched
    touchCounter++;                   // Increment touch counter

    if (touchCounter >= 3 && gameStarted) {
      // Game over, reset the game
      touchCounter = 0;
      gameStarted = false;
      playGameOverMelody();            // Play the game over melody
      digitalWrite(ledPin, LOW);       // Turn off the LED
      delay(200);                      // Debounce delay
    } else if (touchCounter == 1 && gameStarted) {
      playFirstTouchMelody();          // Play the melody for the first touch
      delay(200);                      // Delay for 0.2 seconds before the second touch can be registered
    } else if (touchCounter == 2 && gameStarted) {
      playSecondTouchMelody();         // Play the melody for the second touch
      delay(200);
    }
  }

  if (digitalRead(togglePin) == LOW && !gameStarted) {
    // Toggle button is pressed and the game hasn't started yet
    gameStarted = true;
    countdown();                       // Start the countdown sequence
  }
}

void countdown() {
  playCountdownMelody(3);              // Play the melody for "3"
  delay(500);
  playCountdownMelody(2);              // Play the melody for "2"
  delay(500);
  playCountdownMelody(1);              // Play the melody for "1"
  delay(500);
  playCountdownMelody(0);              // Play the melody for "GO"
  delay(500);
}

void playGameOverMelody() {
  for (int i = sizeof(buzzerMelody) / sizeof(buzzerMelody[0]) - 1; i >= 0; i--) {
    int noteDuration = 1000 / noteDurations[i];
    tone(buzzerPin, buzzerMelody[i], noteDuration);
    delay(noteDuration * 0.7);
    noTone(buzzerPin);
    delay(50);
  }
}

void playFirstTouchMelody() {
  tone(buzzerPin, 440, 200);
  delay(200);
  noTone(buzzerPin);
}

void playSecondTouchMelody() {
  tone(buzzerPin, 494, 200);
  delay(200);
  noTone(buzzerPin);
}

void playCountdownMelody(int number) {
  if (number > 0) {
    tone(buzzerPin, 1000 - (number * 100), 500);
  } else {
    tone(buzzerPin, 523, 500);
  }
  delay(500);
  noTone(buzzerPin);
}
