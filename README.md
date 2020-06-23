# Rover Functions Documentation
The rover is using what is called a tank drive configuration.
## Movement
### Move Right or Left Track
The most basic movement we have is to move the left and right treads forward or backwards at a speed
```c++
rover_right_track(speed);
rover_left_track(speed);
```
Where *speed* is a floating point number in the range the range [-1,1]. 0.5 means 50% speed and -0.25 means 25% speed but backwards.
### Move Forward / Backward
```c++
rover_drive(speed, time);
```
Where *speed* is a floating point number in the range the range [-1,1]. 0.5 means 50% speed and -0.25 means 25% speed but backwards.

Where *time* is an integer number that describes the number of milliseconds (1000 milliseconds in 1 seconds) to do the action.
### Turning
```c++
rover_rotate_clockwise(speed, time);
rover_rotate_counter_clockwise(speed, time);
```
Where *speed* is a floating point number in the range the range [-1,1]. 0.5 means 50% speed and -0.25 means 25% speed but backwards.

Where *time* is an integer number that describes the number of milliseconds (1000 milliseconds in 1 seconds) to do the action.
### Stop
```c++
rover_stop();
```
Takes no arguments and stops the rover from moving
## Other
### End Mission
```c++
end_mission();
```
This function should be the last line of code in the *loop* section. This function will stop the rover from moving and end the mission.
