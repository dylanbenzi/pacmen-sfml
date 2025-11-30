![Pacman icon](g)
# Pacmen SFML

A classic Pac-Man game implementation built with C++ and SFML 3.

## Features

- **Classic Pac-Man gameplay** with authentic arcade mechanics
- **Four unique ghosts** with AI behaviors:
  - **Blinky** (Red) - Aggressive chaser
  - **Pinky** (Pink) - Ambusher
  - **Inky** (Cyan) - Strategic flanker
  - **Clyde** (Orange) - Unpredictable patrol
- **Authentic game mechanics**:
  - Ghost scatter/chase mode cycling
  - Tunnel wrapping
  - Staggered ghost release from ghost house
  - Cornering tolerance for smooth controls
- **Comprehensive audio** - Original Pac-Man sound effects including:
  - Start music
  - Pellet eating sounds
  - Siren progressions
- **JSON-based configuration** - Easily customizable game parameters
- **Resource management system** - Efficient loading and caching of assets

## Requirements

- CMake 3.28 or higher
- C++17 compatible compiler
- Git (for fetching dependencies)

### Platform-Specific Dependencies

#### Linux (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install \
    libxrandr-dev \
    libxcursor-dev \
    libxi-dev \
    libudev-dev \
    libfreetype-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev
```

## Building

### Using CMake (Command Line)

```bash
# Configure the project
cmake -B build

# Build the project
cmake --build build

# Run the game
./build/bin/main
```

### Using an IDE

This project supports CMake integration with popular IDEs:

- **VS Code** - Use the [CMake extension](https://code.visualstudio.com/docs/cpp/cmake-linux)
- **Visual Studio** - Open as a [CMake project](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio)
- **CLion** - Has built-in [CMake support](https://www.jetbrains.com/clion/features/cmake-support.html)
- **Qt Creator** - Supports [CMake projects](https://doc.qt.io/qtcreator/creator-project-cmake.html)

## Controls

- **W / Up Arrow** - Move up
- **A / Left Arrow** - Move left
- **S / Down Arrow** - Move down
- **D / Right Arrow** - Move right

## Project Structure

```
pacmen-sfml/
├── src/
│   ├── main.cpp           # Entry point
│   ├── Game.cpp/h         # Main game loop and initialization
│   ├── Entity.cpp/h       # Base entity class with animations
│   ├── Pacman.cpp/h       # Pac-Man entity
│   ├── Ghost.cpp/h        # Base ghost class with AI
│   ├── Blinky.cpp/h       # Red ghost implementation
│   ├── Pinky.cpp/h        # Pink ghost implementation
│   ├── Inky.cpp/h         # Cyan ghost implementation
│   ├── Clyde.cpp/h        # Orange ghost implementation
│   ├── MazeMap.cpp/h      # Maze rendering and collision
│   └── ResourceManager.cpp/h  # Asset loading
├── assets/
│   ├── fonts/             # Game fonts
│   ├── sounds/            # Sound effects
│   ├── textures/          # Sprite sheets and graphics
│   └── game/
│       ├── config.json    # Game configuration and level data
│       ├── maze.txt       # Maze walls data
│       └── pellets.txt    # Pellet placement data
├── CMakeLists.txt         # Build configuration
└── README.md
```

## Configuration

The game uses `assets/game/config.json` for configuration, which includes:

- **Game constants** - Frame rate, tile size, base speeds, point values
- **Bonus fruit** - Appearance timing and point values
- **Level specifications** - 21 levels (1-20 plus 21+) with:
  - Pac-Man and ghost speeds
  - Vulnerable mode duration
  - Scatter/chase timing patterns
  - Ghost house release logic
  - Bonus fruit types and values

## Architecture

### Entity System
The game uses an inheritance-based entity system:
- `Entity` - Base class with animation, movement, and rendering
- `Pacman` - Player-controlled entity
- `Ghost` - AI-controlled entities with behavior modes

### Ghost AI
Ghosts operate in multiple modes:
- **Scatter** - Move to designated corners
- **Chase** - Pursue Pac-Man using unique targeting strategies
- **Vulnerable** - Flee from Pac-Man when energizer is eaten
- **In Box** - Wait in ghost house before release

### Resource Management
`ResourceManager` handles loading caching of:
- Textures with runtime scaling
- Sound buffers
- Fonts
- Map data files

## Dependencies

The project automatically fetches these dependencies via CMake FetchContent:

- **SFML 3.0.2** - Graphics, audio, and window management
- **nlohmann/json 3.11.3** - JSON parsing for configuration

## Acknowledgments

- Original Pac-Man game design by Toru Iwatani (Namco)
- Built with [SFML](https://www.sfml-dev.org/)
- Font: [Press Start 2P](https://fonts.google.com/specimen/Press+Start+2P)
- Graphics and sounds: [The Spriters Resource](https://www.spriters-resource.com/arcade/pacman/)
- Game reference from [The Pac-Man Dossier](https://pacman.holenet.info/)
- Project structure based on the [SFML CMake Template](https://github.com/SFML/cmake-sfml-project)
