# Buzzer Motion

A silent watcher that screams when something moves - a PIR-triggered alarm that flashes and buzzes the moment a presence is detected.

## Summary
This project uses a PIR motion sensor to detect movement and trigger an alert: an LED turns on and a buzzer sounds for one second. It’s a simple but powerful “first security system” build that teaches clean input → decision → output logic.

## Features
- Motion detection using a PIR sensor
- Instant audible + visual alert (buzzer + LED)
- Serial Monitor debug output (“Motion Detected!”)
- Simple timing window (1 second alarm pulse)

## Components Used
- 1x Arduino Uno (or compatible)
- 1x PIR motion sensor (signal)
- 1x Buzzer (active buzzer recommended)
- 1x LED (or Arduino pin 13 onboard LED)
- Breadboard + jumper wires

## Core Logic Highlights
- PIR signal read with `digitalRead()` on pin **2**
- LED output on pin **13** (onboard LED works great)
- Buzzer output on pin **8**
- When motion goes HIGH:
  - prints debug info to Serial
  - turns LED + buzzer on for 1000ms
  - then turns both off again
- Loop delay of 100ms to keep readings stable

## Media
_gif or short video demo coming soon_
