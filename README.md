# ***Vertune***

**Vertune** is a fast-paced, minimalistic platformer where you jump on enemies and collect coins. Master your timing, avoid dying, and see how far you can go. Simple, fun, and easy to pick up — perfect for a quick challenge!

## Features

- **Fluid platforming:** Tight controls and responsive movement make every jump and movement feel satisfying.  
- **Dynamic levels:** Every level is randomly generated to make sure you are enjoying the game even after many runs.  
- **Highscore challenges:** Compete against yourself and others by aiming for the highest score.  
- **Cross-platform:** Play on Windows and on the web via Emscripten.  

## Controls

- Arrow keys / AD to move sideways  
- Space / Up / W to jump

## Build Instructions

### Prerequisites(Only for web build)
- You need to have emscripten installed and em++ in your path
- Make sure you have a 64-bit cl.exe in your path. You can do that either by calling vcvarsall.bat x64 in your current command prompt or by opening a x64 Native Tools Command Prompt

### Building

- For windows build: Call build.bat from the root directory of the project
- For web build: Call build-web.bat from the root directory of the project
