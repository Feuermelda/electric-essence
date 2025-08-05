# Alarm Candle

A minimalistic LED project that simulates a resettable candle using button presses. The LED remains on by default, flickers with each press, and turns off after the third press for 10 seconds — before relighting itself.

## Summary
This sketch tracks how many times you've "blown out" the candle (via button press). After three presses, the LED turns off for a full 10 seconds — like a dramatic, ceremonial extinguishing — and then resets itself. A short flicker after each press adds a tactile feedback loop.

## Features
- LED always on by default (like a candle)
- Flickers three times on each press
- After three presses, LED turns off for 10 seconds
- Automatically resets to on after timeout
- Uses `INPUT_PULLUP` — no external resistor needed for the button

## Components Used
- 1x Arduino Uno (or compatible)
- 1x LED (preferable warm white or yellow)
- 1x 220Ω resistor
- 1x Push button (connected directly with internal pull-up)
- Breadboard + jumper wires

## Core Logic Highlights
- Button presses tracked with `pressCount`
- Triple press triggers timed LED shutdown via `delay(10000)`
- Flicker effect done with a quick `for` loop of `digitalWrite()` + `delay()`
- Clean state detection with `lastButtonState` and `INPUT_PULLUP`

## Media
_Circuit diagram and flicker video coming soon_