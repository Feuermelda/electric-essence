# Birthday Cake

## Summary
A whimsical candle simulation that lets you light each "candle" (LED) with a button press and blow them out with your breath. The candles flicker realistically based on the intensity of sound detected by the microphone.

## Features
- Button-controlled progressive lighting of 5 LEDs (candles)
- Microphone-based flickering simulation
- Sound treshold to simulate "blowing out" candles
- Resets automatically for reuse

## Components Used
- Arduino UNO R3 (Elegoo-compatible clone)
- 5x LED diodes 
- 5x 220Ω resistors
- 1x Button
- 1x Sound Sensor Module (analog mic)
- Breadboard + jumper wires

## Core Logic Highlights
- Dual `while` loops: one for lighting, one for flickering/blow-out mode
- Dynamic `analogWrite()` with randomized flicker ranges
- Sound tresholds mapped for both flickering and full extinguish

## Media
<!-- To insert images, place them in the repo and use:
![alt text](relative/path/to/image_or_gif.jpg) -->
[Birthday Cake Demo](link/comes/later)<br>
...will be added soon!
