#define PULSE_PIN A0 // Pin where the pulse sensor is connected
#define THRESHOLD 540 // Threshold for detecting a heartbeat

long lastBeat = 0;    // Time of the last beat in milliseconds
long currentBeat = 0; // Time of the current beat in milliseconds
int bpm = 0;          // Beats per minute

// Moving average variables
const int numReadings = 5; // Number of readings for smoothing
int bpmReadings[numReadings] = {0}; // Array to store BPM readings
int index = 0;           // Current index in the array
int total = 0;           // Sum of all readings in the array

void setup() {
  Serial.begin(9600); // Initialize Serial communication
  pinMode(PULSE_PIN, INPUT); // Set the pulse pin as input
  Serial.println("Pulse Monitor Ready!");
}

void loop() {
  int pulseValue = analogRead(PULSE_PIN); // Read pulse sensor value

  // Detect if the value exceeds the threshold, indicating a heartbeat
  if (pulseValue > THRESHOLD) {
    long now = millis();
    if (now - lastBeat > 300) { // Ignore noise (minimum 300ms between beats)
      currentBeat = now; // Capture the current beat time
      int rawBpm = 60000 / (currentBeat - lastBeat); // Calculate raw BPM
      lastBeat = currentBeat; // Update the last beat time

      // Update moving average
      total -= bpmReadings[index];          // Subtract the oldest value
      bpmReadings[index] = rawBpm;         // Add the new BPM value
      total += bpmReadings[index];          // Update the total
      index = (index + 1) % numReadings;   // Move to the next index

      bpm = total / numReadings; // Calculate the smoothed BPM

      // Print the smoothed BPM to the Serial Monitor
      Serial.print("Smoothed BPM: ");
      Serial.println(bpm);
    }
  }
}
