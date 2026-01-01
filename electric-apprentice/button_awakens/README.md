# Button Awakens

The “button saga” - one simple input, turned into multiple interaction styles: classic press, toggle control, press-length detection, and a timed combo trigger.

## Summary
Button Awakens is a progressive project series where each version expands what a single button can *mean*. It starts with direct control (press = LED on), then evolves into stateful toggling, short vs long press behavior, and finally a secret combo pattern triggered by multiple presses within a time window.

## Versions (file mapping)
- **button_awakens_v1.ino - Classic Press**
  - Hold button = LED on, release = LED off (direct input → output control)
- **button_awakens_v2.ino - Toggle Mode**
  - Each new press flips the LED state (on/off) using edge detection + state memory
- **button_awakens_v3.ino - Short vs Long Press**
  - Short press = LED turns on briefly
  - Long press = LED blinks (press-duration logic using `millis()`)
- **button_awakens_v4.ino - Combo Trigger**
  - Detects a timed press pattern (double press within a timeout)
  - Triggers a “success” output (green LED) as a secret combo reward

## Features
- Internal pull-up input wiring (`INPUT_PULLUP`)
- Edge detection (detect “new press” vs “still held”)
- State memory (toggle logic)
- Press-duration detection (short vs long press)
- Timed combo logic (multi-press within a window)
- Optional Serial debug output (v4)

## Components Used
- 1x Arduino Uno (or compatible)
- 1x Push button
- 1–2x LEDs (onboard LED on pin 13 works, plus external LED for combo in v4)
- Resistors (if using external LEDs)
- Breadboard + jumper wires

## Core Logic Highlights
- **v1:** simplest mapping - button LOW → LED HIGH
- **v2:** toggling using `ledState = !ledState` only when press transitions HIGH → LOW
- **v3:** measures how long the button is held using `millis()` to branch behavior
- **v4:** counts presses and resets after a timeout; triggers combo action on the target count

## Media
_gif or short demo clip coming soon_
