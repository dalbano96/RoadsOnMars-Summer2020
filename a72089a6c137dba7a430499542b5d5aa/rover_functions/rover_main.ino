void setup() {

}

void loop() {
  rover_drive(0.5, 600);
  rover_rotate_clockwise(0.5, 2000);
  rover_drive(-0.5, 600);
  mission_end();
}
