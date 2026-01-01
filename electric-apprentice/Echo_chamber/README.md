# Echo Chamber

A sensor fusion “truth test” - it only reacts when **both** motion *and* sound agree something is happening.

## Summary
Echo Chamber combines two independent sensor signals into one decision. Instead of triggering on motion OR sound (which can cause false alarms), it requires **motion + a loud noise within the same moment** before activating the output. The result feels more intentional, like a device that “listens and watches” before responding.

## Features
- Dual-sensor logic: PIR motion + sound sensor
- Reduced false triggers by requiring *both* conditions
- Adjustable sound threshold (easy to tune)
- Clear decision structure: detect → validate → react

## Components Used
- 1x Arduino Uno (or compatible)
- 1x PIR motion sensor
- 1x Sound sensor module (analog output)
- 1x LED and/or buzzer (depending on your output pins)
- Breadboard + jumper wires

## Core Logic Highlights
- Reads PIR motion with `digitalRead()` (motion present / not present)
- Reads sound level with `analogRead()` and compares to a threshold
- Triggers only when:
  - motion is detected **AND**
  - sound level is above threshold
- Great intro to **multi-condition systems** and “confidence gating”

## Notes / Tweaks
- If it triggers too easily, raise the sound threshold.
- If it misses claps, lower the threshold slightly and test using Serial Monitor readings.
- For an even smarter version later: add a short time window (e.g., “sound within 2 seconds after motion”).

## Media
_gif or short demo clip coming soon_
