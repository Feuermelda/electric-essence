# Shadow Memory

An ambient LED that remembers sound in the dark. The LED blooms when it hears a sound in low light — and stays lit until the light returns.

## Summary
This sketch extends the original Memory Bloom by giving the LED a kind of "memory." Instead of turning off immediately, it holds onto its blooming state once triggered — like a shadow that lingers after a sound is heard in the dark. It only resets when the light returns.

## Features
- dual-trigger: sound + darkness
- Memory behavior using a boolean state variable
- LED stays on even if sound disappears
- Resets only on bright light ("sunrise" effect)
- Smooth and organic interaction timing

## Components Used
- 1x Arduino Uno (or compatible)
- 1x LED
- 1x 220Ω resistor
- 1x Photoresistor (A0)
- 1x Sound sensor (A3)
- Breadboard + jumper wires

## Core Logic Highlights
- `isBlooming` boolean stores whether the LED is “alive”
- Trigger condition: `lightVal < 500 && soundVal > 86`
- Reset condition: `lightVal > 700`
- LED controlled using a ternary `digitalWrite(isBlooming ? HIGH : LOW)`
- Loop runs every 100 ms for responsiveness

## 🖼 Media
_Circuit diagram and shadow demo coming soon_