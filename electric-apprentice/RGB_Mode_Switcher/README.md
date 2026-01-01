# RGB Mode Switcher

A multi-personality RGB light - one build idea explored through several sketches: smooth fades, rainbow cycles, mood lighting, and a mode-button controller.

## Summary
RGB Mode Switcher is my “RGB mastery” project family. Instead of one single sketch, I built multiple focused versions to learn different control styles: time-based animations, smooth fades, user-controlled mood lighting, potentiometer-controlled speed, and finally a mode-button version that switches behaviors like a real device.

## Files (what each sketch does)
- **RGB_Mode_Switcher.ino - Mode Button (main controller)**
  - A button cycles through multiple RGB modes (state machine style).
- **color_rainbow_fade.ino - Rainbow Fade**
  - Smooth color transitions through RGB spectra (animation + blending).
- **color_mood_light.ino - Mood Light**
  - A calmer, slower lighting mode (ambient fades / steady moods).
- **potentiometer-controlled_rainbow_speed.ino - Pot-Speed Rainbow**
  - The potentiometer controls animation speed (analog input → timing control).

## Features
- PWM color mixing (true RGB control, not just on/off)
- Multiple lighting behaviors (fade, rainbow, mood, user-tuned speed)
- Button-driven mode switching (device-style interaction)
- Potentiometer control (analog input as a “knob”)

## Components Used
- 1x Arduino Uno (or compatible)
- 1x RGB LED (common anode or common cathode - depends on wiring)
- 3x resistors (one per color channel)
- 1x Push button (for mode switching)
- 1x Potentiometer (for speed control in the pot version)
- Breadboard + jumper wires

## Core Logic Highlights
- Uses PWM output to blend Red/Green/Blue intensities
- Uses timing-based animation loops for fades/cycles
- Mode-button version stores a `mode` state and changes behavior on each new press
- Potentiometer version maps analog values to speed/delay to make the rainbow “spin” faster or slower

## Notes / Tweaks
- If colors look “inverted” or weird, you’re likely using common anode vs common cathode wiring - flip the logic (or invert PWM values).
- If button switching feels jumpy, add debouncing or press-edge detection (like in Button Awakens v2).

## Media
_gif or short demo clip coming soon_
