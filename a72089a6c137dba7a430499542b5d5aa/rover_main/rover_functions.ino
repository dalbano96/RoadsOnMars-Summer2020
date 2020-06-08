/*
 * Speed should be a floating point value [-1,1].
 * i.e. 0.5 means 50% speed in the forward direction, -0.25 would be 25% speed backwards
 * Time is a value in milliseconds (1000 milliseconds in 1 second)
 */
#define E1 6
#define E2 5
#define M1 8
#define M2 7
#define trigPin 2
#define echoPin 3

void rover_right_track(float s) {
    if (s > 1.0) s = 1.0;
    if ( s < -1.0) s = -1.0;
    int spd = 255 * s;
    analogWrite(E1, abs(spd));
    digitalWrite(M1, (spd >= 0 ? LOW: HIGH));
}
void rover_left_track(float s) {
    if (s > 1.0) s = 1.0;
    if ( s < -1.0) s = -1.0;
    int spd = 255 * s;
    analogWrite(E2, abs(spd));
    digitalWrite(M2, (spd >= 0 ? LOW: HIGH));
}
void rover_drive(float s, int time) {
    if (s > 1.0) s = 1.0;
    if ( s < -1.0) s = -1.0;
    int spd = 255 * s;
    rover_right_track(spd);
    rover_left_track(spd);
    delay(time);
    rover_stop();
}
void rover_rotate_clockwise(float s, int time) {
    if (s > 1.0) s = 1.0;
    if ( s < -1.0) s = -1.0;
    int spd = 255 * s;
    rover_right_track(-spd);
    rover_left_track(spd);
    delay(time);
    rover_stop();
}
void rover_rotate_counter_clockwise(float s, int time) {
    if (s > 1.0) s = 1.0;
    if ( s < -1.0) s = -1.0;
    int spd = 255 * s;
    rover_right_track(spd);
    rover_left_track(-spd);
    delay(time);
    rover_stop();
}
void rover_stop() {
    rover_right_track(0);
    rover_left_track(0);
}
// Call this to end the mission
void mission_end() {
    rover_stop();
    exit(0);
}

void setup_hcsr04() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
float readDistance() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  float duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  float distance = duration*0.034/2;
  return distance;
}
