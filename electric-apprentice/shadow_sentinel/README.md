# Shadow Sentinel (+ Ultrasonic Variant)

A stealthy night guardian - it only reacts when it’s dark, and then checks for presence (motion or proximity) before triggering an alert.

## Summary
Shadow Sentinel is a “smart activation” project: instead of reacting all the time, it first asks **“Is it dark enough?”** using an LDR (light sensor). Only then does it enable detection logic. This makes it feel like a real device: quiet during the day, active at night.

There are two versions:
- the classic **motion-based sentinel** (PIR)
- an **ultrasonic proximity sentinel** (distance-based)

## Files (what each does)
- **shadow_sentinel.ino - Shadow Sentinel (PIR)**
  - Uses an LDR to detect darkness
  - When dark, a PIR sensor detects motion → triggers output
- **shadow_sentinel_ultrasonic.ino - Shadow Sentinel (Ultrasonic)**
  - Uses an LDR to detect darkness
  - When dark, an ultrasonic sensor checks distance → triggers output when something is close

## Features
- “Only active in the dark” gating logic (LDR threshold)
- Sensor fusion behavior: **Light condition + Detection condition**
- Two detection styles:
  - Motion detection (PIR)
  - Proximity detection (Ultrasonic distance)
- Clear decision-making structure: **if dark → then detect → then react**

## Components Used
- 1x Arduino Uno (or compatible)
- 1x LDR (photoresistor) + resistor (voltage divider)
- **Variant A:** PIR motion sensor
- **Variant B:** HC-SR04 ultrasonic sensor
- 1x LED (or onboard LED) and/or buzzer (depending on your outputs)
- Breadboard + jumper wires

## Core Logic Highlights
- Reads ambient light level and compares to a threshold
- If it’s bright: outputs stay off (sentinel “sleeps”)
- If it’s dark: sentinel “wakes” and checks:
  - PIR HIGH (motion) **or**
  - distance < limit (ultrasonic)
- Triggers a visible/audible response only when both conditions are satisfied

## Notes / Tweaks
- Calibrate the LDR threshold by printing readings to Serial and testing in your room lighting.
- For ultrasonic mode, tune the distance threshold to avoid false triggers from walls/furniture.

## Media
_gif or short demo clip coming soon_
