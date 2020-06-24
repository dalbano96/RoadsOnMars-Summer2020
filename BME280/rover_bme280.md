# BME 280
## Plug It In
Look at the side of the board to see the pin labels.

Vin --> 5V


GND --> GND


SCL --> A5


SDA --> A4

## Install Library
Click on the Sketch menu, select the Include Library option, and click Manage Libraries.

![add library](https://i.imgur.com/kaWa3II.png)

Now search for *bme280* and install the library by Adafruit.

![library search](https://i.imgur.com/qjUE4MW.png)

Next search for *adafruit unified sensor*, I had to scoll down to the last option to find the right library and then click install.

![unified sensor](https://i.imgur.com/9UDTXVz.png)
## Using the Library
We must several lines of code to our file to use the BME280, the first is above the *setup* function and the second is within it.
```c++
#include <Adafruit_Sensor.h> // a library to control the sensor
#include <Adafruit_BME280.h> // another library that uses the first library

Adafruit_BME280 bme;

void setup() {
    bme.begin();
}
```
### Temperature
Temperature is measured in floating point using Centigrade.
```c++
float t = bme.readTemperature();
```
### Humidity
Humidity is measured is a floating point value that represents a percentage.
```c++
int h = bme.readHumidity();
```
### Pressure
Pressure is measure as an integer, in Pascals.
```c++
float p = bme.readPressure();
```
