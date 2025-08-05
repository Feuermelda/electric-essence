# Memory Bloom

A poetic LED circuit that reacts to both darkness and sound. The LED lights up like a bloom - only when it "hears" something in the dark.

## Summary
This project combines a light sensor and a sound sensor to create a reactive LED that only lights up under specific ambient conditions. It responds to the world quietly — glowing only when the room is dim and it hears a sound.

## Features
- LED activation based on dual conditions: low light & sound
- Uses analog thresholds for subtle responsiveness
- Simple feedback via onboard serial monitor
- Feels organic and mood-based

## Components Used
- 1x Arduino Uno (or compatible)
- 1x LED
- 1x 220Ω resistor
- 1x Photoresistor (connected to A0)
- 1x Microphone sound sensor (connected to A3)
- Jumper wires + breadboard

## Core Logic Highlights
- Reads `lightVal` from A0 and `soundVal` from A3
- If `lightVal < 500` **and** `soundVal > 86`, the LED turns on
- If it becomes bright, the LED turns off regardless of sound
- Behavior loops every 100ms

## Media
_Circuit diagram and bloom demo coming soon_