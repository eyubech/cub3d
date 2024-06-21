# Cub3D Project - README

## Overview

Cub3D is a 3D game engine built from scratch using low-level C programming. It implements raycasting to create a pseudo-3D perspective, similar to early 90s games like Wolfenstein 3D. This project is a collaborative effort by two developers, aiming to demonstrate our proficiency in C and our understanding of computer graphics principles.


## Features

- **Raycasting Engine**: Utilizes raycasting to render a 3D-like environment from a 2D map.
- **Customizable Maps**: Supports custom map creation with a simple text file format.
- **Basic Game Mechanics**: Includes player movement and basic collision detection.
- **Texture Mapping**: Implements texture mapping for walls to enhance visual realism.
- **Keyboard Controls**: Allows navigation through the 3D world using keyboard inputs.
- **Pause and Map Toggle**: Adds functionality to pause the game and toggle the map display.

## Getting Started

### Prerequisites

- GCC compiler
- Make
- [CODAM MLX library]([https://gi](https://github.com/codam-coding-college/MLX42))


### Running the Game

After building the project, you can run the game using:
```sh
./cub3d path/to/your/mapfile.cub
```

### Controls


 - W: Move forward
 - S: Move backward
 - A: Strafe left
 - D: Strafe right
 - Left Arrow: Turn left (or mouse)
 - Right Arrow: Turn right (or mouse)
 - P: Pause the game
 - M: Show/Hide the map
 - C: Enable/Disable mouse control
 - ESC: Exit the game


### Map File Format


The map files are simple text files with the .cub extension. The format is as follows:

- 0: Empty space
- 1: Wall
- N, S, E, W: Player's starting position and orientation (North, South, East, West)
#### Example:
```
1111111111
1000000001
1000010001
100N010001
1000000001
1111111111
```


### Project Structure


- src/: Source code files.
- include/: Header files.
- maps/: Example map files.
- textures/: Texture images used in the game.
- Makefile: Build script.

  
### Contributing


Fork the repository.
Create your feature branch (git checkout -b feature/your-feature).
Commit your changes (git commit -am 'Add your feature').
Push to the branch (git push origin feature/your-feature).
Create a new Pull Request.


### Authors


- [Ayoub ech-chetyouy](https://github.com/eyubech)
- [Noura El Moussaoui](https://github.com/NouraElMoussaoui)


  
###  License



This project is licensed under the MIT License - see the LICENSE file for details.


###  Pictures

#### Start game
[
![Screenshot from 2024-06-21 23-06-18](https://github.com/eyubech/cub3d/assets/76597998/ce7b05cc-c3dd-42fc-812f-a45421fdc76e)
](url)

#### Pause
[
![Screenshot from 2024-06-21 23-06-29](https://github.com/eyubech/cub3d/assets/76597998/f986fe56-a572-4768-8bac-10c644dfc9de)
](url)


#### Hide Map
[
![Screenshot from 2024-06-21 23-06-38](https://github.com/eyubech/cub3d/assets/76597998/60bd90a1-f7e2-4d45-b736-f16e038918c3)
](url)






