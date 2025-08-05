# Resonant Bloom

A glowing ember that listens in the dark — this RGB LED reacts to sound with a flare of red light, blooming brighter the louder it hears.

## Summary
This project uses an RGB LED to create a warm, ember-like visual effect that only activates in darkness. When it hears sound, it glows — softly or brightly, depending on volume. It fades back to black when silence or light returns.

## Features
- Red-orange light mapped to sound intensity
- Only activates in low light (like a hidden ember)
- Smooth analog control via `analogWrite`
- Responsive feedback loop using dual sensors

## Components Used
- 1x Arduino Uno (or compatible)
- 1x RGB LED (common cathode)
- 3x 220Ω resistors (one for each color channel)
- 1x Photoresistor (A0)
- 1x Sound sensor (A3)
- Breadboard + jumper wires

## Core Logic Highlights
- Sound and light levels read via analog pins
- `map()` used to convert sound value into PWM brightness (10-255)
- LED glows red with a hint of green (warm ember tone)
- Shuts off completely when ambient light exceeds 500
- Loops every 100ms for real-time responsiveness

## Media
_gif or short video demo coming soon_