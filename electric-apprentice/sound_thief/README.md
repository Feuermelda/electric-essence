# Sound Thief

A tiny “sound trap” - clap (or any loud noise) to steal the silence and make the LED glow for a moment.

## Summary
Sound Thief reads an analog sound sensor and triggers an LED when the volume crosses a threshold. To prevent constant re-triggering from the same noise burst, it uses a simple lockout flag: once triggered, it won’t trigger again until the sound level drops back below the threshold.

## Features
- Analog sound sensing via `analogRead()` on **A0**
- Threshold trigger (default: **85**)
- “One-shot” activation using a `triggered` flag
- 2-second LED glow window after a loud sound
- Serial Monitor output for live calibration/debugging

## Components Used
- 1x Arduino Uno (or compatible)
- 1x Sound sensor module (analog output)
- 1x LED (or Arduino pin 13 onboard LED)
- Breadboard + jumper wires

## Core Logic Highlights
- Reads sound level: `soundState = analogRead(A0)`
- Prints values to Serial at **9600 baud** (great for choosing the right threshold)
- Triggers only if:
  - `soundState >= 85` **and** `triggered == false`
- After triggering:
  - LED turns on for **2000ms**
  - LED turns off
  - stays locked until sound drops below the threshold again
- Small cooldown: `delay(50)` for stability

## Notes / Tweaks
- If it triggers too easily, raise the threshold (e.g. 120–200 depending on your sensor).
- If it misses claps, lower the threshold slightly and watch the Serial values while testing.

## Media
_gif or short demo clip coming soon_
