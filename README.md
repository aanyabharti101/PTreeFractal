# PTreeFractal

An interactive recursive fractal visualization built in C++ using SFML graphics, geometric transformations, and trigonometric recursion.

This project generates a Pythagorean Tree fractal by recursively attaching squares to parent squares using mathematically computed rotations and scaling relationships. The visualization supports dynamic recursion depth, customizable branch angles, and interactive keyboard controls.

---

## Features

- Recursive Pythagorean Tree generation
- Real-time SFML rendering
- Interactive keyboard controls
- Adjustable recursion depth
- Dynamic angle manipulation
- Trigonometric geometric transformations
- Depth-based color gradients
- Configurable fractal parameters
- Built with modern C++20

---

## How It Works

The program begins with a base square and recursively generates two child squares at each level.

Each child square:
- rotates relative to its parent
- scales using trigonometric ratios
- attaches precisely to the parent square’s top corners

The implementation uses:

- recursive rendering
- SFML transformation matrices
- coordinate-space rotation
- trigonometric scaling
- geometric vector offsets

For a square with side length `S` and angle `θ`:

- left child size = `S × cos(θ)`
- right child size = `S × sin(θ)`

This preserves the geometric structure of the classical Pythagorean Tree fractal.

---

## Example Usage

### Build

```bash
make
```

### Run

```bash
./PTree 120 3
```

- `120` = base square side length in pixels
- `3` = recursion depth (number of recursive tree levels)

Optional angle parameter:

```bash
./PTree 120 3 45
```

- `45` = branching angle in degrees

---

## Interactive Controls

| Key | Action |
|---|---|
| Right Arrow | Increase recursion depth |
| Left Arrow | Decrease recursion depth |
| Up Arrow | Increase branch angle |
| Down Arrow | Decrease branch angle |

---

## Algorithms & Concepts

- Recursive graphics generation
- Fractal geometry
- Transformation matrices
- Trigonometry
- Coordinate-space rotation
- Vector mathematics
- Interactive rendering
- Event-driven graphics programming

---

## Graphics Implementation

Each square is represented using:

```cpp
sf::RectangleShape
```

The program repositions each square’s origin to the bottom-left corner so rotations occur around the correct geometric pivot point.

SFML transformations are used to:
- rotate child branches
- compute transformed corner coordinates
- align recursive squares precisely
- preserve fractal continuity

---

## Visual Features

- Multi-level recursive fractal rendering
- Dynamic depth-based coloring
- Real-time parameter adjustments
- Smooth geometric scaling
- Non-clipping adaptive window sizing

---

## Technologies

- C++20
- SFML Graphics Library
- GNU Make
- STL
- Recursive algorithms

---

## Project Structure

```txt
PTree.cpp
PTree.hpp
main.cpp
Makefile
README.md
```

| File | Purpose |
|---|---|
| `PTree.cpp` | Recursive fractal rendering logic |
| `PTree.hpp` | PTree class definition |
| `main.cpp` | SFML window and interaction handling |
| `Makefile` | Build automation |

---

## Challenges

One of the most difficult parts of the project was correctly aligning the right child square using rotated coordinate systems and geometric offsets.

Additional challenges included:
- handling rotation origins correctly
- computing transformed corner positions
- preventing branch misalignment
- debugging recursive geometric placement

---

## Author

Aanya Bharti  
Computer Science & Mathematics  
University of Massachusetts Lowell
