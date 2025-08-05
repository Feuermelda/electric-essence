# Moodlight Quartet

A reactive RGB moodlight that shifts colors based on your presence and the ambient light. It blooms gently when alone in the dark, flares up when you get close, and dances in color when the room is lit.

## ✨ Summary
Moodlight Quartet is an interactive LED project that responds to motion and light with four distinct RGB states. Using an ultrasonic sensor and a light sensor, the device chooses which color logic to display, ranging from peaceful rainbow fades to alert-style blinking. It’s a light with mood and memory.

## Features
- Rainbow fade when it's dark and still
- Bright red-orange flare when motion is detected in the dark
- Blue-yellow crossfade when it's bright and still
- Orange-green blinking when motion is detected in light
- Designed for minimal components and expressive color logic

## Components Used
- 1x Arduino Uno (or Nano)
- 1x RGB LED (common cathode)
- 3x 220Ω resistors
- 1x Photoresistor (A0)
- 1x Ultrasonic sensor (HC-SR04 or similar)
- Jumper wires + breadboard

## Core Logic Highlights
- Reads ambient light from A0 (threshold at 500)
- Detects proximity using `trigPin` / `echoPin` (threshold at 20cm)
- Four total states based on light + distance combos
- Uses `map()` and `analogWrite()` for smooth PWM fading
- Includes custom `rainbow()` and `blueyellowfade()` functions for expressive animation

## Media
_Circuit diagram, mode dmeo GIFs, and fade animations coming soon_