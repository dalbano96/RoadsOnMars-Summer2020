# Ultrasonic Sensor
## Plug It In
Look at the side of the board to see the pin labels.

Vcc --> 5V


Trig --> 2


Echo --> 3


Gnd --> GND

## C++ Code
```
void setup() {
    setup_hcsr04();
}
void loop() {
    float d = readDistance();
}
```
