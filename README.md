# Cub3D

Cub3D is a simple 3D game engine project inspired by classic raycasting games like Wolfenstein 3D. The project is usually developed as part of the 42 school curriculum and focuses on learning computer graphics fundamentals, particularly raycasting, 2D/3D math, and basic game mechanics using the MinilibX graphical library.

## Features

- **Raycasting engine:** Renders a 3D environment from a 2D map using raycasting techniques.
- **Textured walls and colored floors/ceilings:** Supports custom wall textures and adjustable colors.
- **Player movement:** Move and rotate the player with keyboard controls.
- **Map parsing:** Loads and validates 2D maps from configuration files.
- **Windowed display:** Uses the MinilibX library for window and image management (X11-based).
- **Minimal dependencies:** Designed for educational use and easy compilation on Linux.

## Screenshots


## Requirements

- GCC or Clang
- Make
- X11 development libraries (`xorg`)
- XShm extension (`libxext-dev`)
- BSD utility functions (`libbsd-dev`)
- Linux operating system with X11 server

## Building

1. **Clone the repository:**
   ```sh
   git clone https://github.com/matde-je/Cub3D.git
   cd Cub3D
   ```

2. **Build the project:**
   ```sh
   make
   ```

   This will compile both the MinilibX library (in `minilibx-linux/`) and the Cub3D source files (in `src/`).

## Running

After building, run the main executable (often `cub3d` or similar) with a map file as an argument:

```sh
./cub3d path/to/map.cub
```

## Controls

- `W/A/S/D` — Move the player forward, left, backward, and right.
- `←/→` (Arrow keys) — Rotate the player's view.
- `ESC` — Exit the game.

## Map Format

The `.cub` map file describes the environment layout, player start position, textures, and colors.
> *(Refer to your project instructions for detailed map file format.)*

## Attributions

- **MinilibX**: Included for X11 graphics. See [`minilibx-linux/README.md`](minilibx-linux/README.md) for more details.
- **Textures**: Some textures are from the SimonKraft Minecraft texture pack ([planetminecraft.com](https://www.planetminecraft.com/texture-pack/simonkraft/)).

## License

This project is licensed under [The Unlicense](./UNLICENSE).  
See the [UNLICENSE](./UNLICENSE) file for details.

---

*This project is for educational purposes and is part of the 42 school curriculum.*
