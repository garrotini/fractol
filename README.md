

https://github.com/user-attachments/assets/e8f0dd0a-e798-4f8b-af21-0166b238ae0c

# fractol

A fractal explorer written in C using MiniLibX. Renders the Mandelbrot set,
custom Julia sets, and preset Julia variants with smooth HSV coloring.

This is a project from the 42 school curriculum: [cmanuel-](https://profile.intra.42.fr/users/cmanuel-) — 42


## Features

- **Mandelbrot set** rendering
- **Julia set** with user-defined complex constants
- **julia_mods** — preset Julia constants (charcoal, dragon, root, flowers, pokemon)
- Smooth escape-time coloring with an HSV mapping
- Zoom, pan, iteration-count control, and live color switching

## Usage

```sh
./fractol mandelbrot
./fractol julia <real> <imag>    # real and imag between -2 and 2
./fractol julia_mods
```

Example:

```sh
./fractol julia 0.285 0.01
```

## Controls

| Keys                          | Action                        |
| ----------------------------- | ----------------------------- |
| Arrows / WASD                 | Pan the view                  |
| Mouse scroll up / `i`         | Zoom in                       |
| Mouse scroll down / `o`       | Zoom out                      |
| `0`                           | Reset zoom and position       |
| `1`–`5`                       | Set iterations (42, 242, 442, 642, 842) |
| `e` / `+`                     | Increase iterations by 10     |
| `q` / `-`                     | Decrease iterations by 10     |
| `z` / `x` / `c` / `v`         | Switch max color              |
| `g` `h` `j` `k` `l`           | Switch preset in `julia_mods` |

## Build

```sh
make
```

The Makefile automatically clones and builds
[minilibx-linux](https://github.com/42Paris/minilibx-linux) if it is not
already present.

Other targets:

```sh
make clean    # remove object files
make fclean   # also remove the executable
make ffclean  # also remove the minilibx directory
```

## Requirements

- Linux with X11
- `gcc`, `make`, `git`
- X11 development libraries (`libX11-dev`, `libxext-dev`)
- XWayland support if running under Wayland

## Project structure

```
.
├── inc/            # header files
├── src/            # sources (main, rendering, fractals, events, utils)
├── Makefile
└── minilibx-linux/ # cloned automatically by make
```

## Demo

This demo was made using a Debian 12 VM, that I create for developing graphic projects for 42 as I needed to use somehow old libraries and dependencies.
I build a few shell scripts to setup the VM, and documented it here: https://github.com/garrotini/set_deb12


((HERE GOES THE FRACTOL VIDEO))

[![fractol.mp4](https://github.com/user-attachments/assets/85f97751-1326-4b5a-9b2a-a6a9d1258aee)](https://github.com/user-attachments/assets/82320d83-c51e-4658-84b6-e0db648acf42)




## license
This project is part of the 42 school curriculum.

