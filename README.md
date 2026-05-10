# Interactive Colorful Smoke Simulation

A beautiful real-time interactive smoke effect built with openFrameworks. Click or drag your mouse to create colorful smoke that follows your cursor, swirls naturally with Perlin noise, and slowly fades away. Multiple overlapping smoke clouds with different colors create stunning visual effects.

## ✨ Features

- **Real-time colorful smoke** generation
- **Mouse interaction**: Click to spawn new smoke, Drag to continuously spray
- **Natural movement** using Perlin noise (turbulence)
- **Mouse attraction** — smoke gently follows your cursor
- **Smooth fading** with life-based alpha and size
- **Live GUI controls** for easy tweaking
- **Performance optimized** particle system

## 🛠️ Tools & Libraries

- **C++**
- **[openFrameworks](https://openframeworks.cc/)** (v0.12.1 or later)
- **ofxGui** (included with openFrameworks)

## 🚀 How to Run

### 1. Prerequisites
- Install [openFrameworks](https://openframeworks.cc/download/) (recommended v0.12.1)
- Make sure you have a C++ compiler setup (Xcode on macOS, Visual Studio on Windows, etc.)

### 2. Setup the Project
1. Clone or download this repository into your `openFrameworks/apps/myApps/` folder
2. Open the project in your IDE:
   - **macOS**: Open `.xcodeproj`
   - **Windows**: Open `.sln`
   - **Linux**: Open `Makefile`
3. Build and run (usually `Command + R` on macOS)

### 3. Controls

| Input              | Action                            |
|--------------------|-----------------------------------|
| **Left Click**     | Create new colorful smoke         |
| **Click + Drag**   | Continuously spray smoke          |
| **Spacebar**       | Clear all smoke                   |
| **GUI Panel**      | Adjust parameters in real-time    |

### GUI Parameters

- **Background Alpha** — Trail / fade strength
- **Particles per Click** — How many particles per smoke burst
- **Turbulence** — How chaotic/natural the smoke moves

## Project Structure
src/
├── main.cpp
├── ofApp.h
├── ofApp.cpp
├── mover.hpp
└── mover.cpp

## Built For

This project was created as a **Final Project** for a Nature of Code / Creative Coding course using openFrameworks.
