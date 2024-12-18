# Dungeon Adventure Game

## Gameplay
- Explore the dungeon, fight creatures, and collect items.
- Commands:
  - `look`: View details about the current room.
  - `move [direction]`: Move to a different room (e.g., `move up`).
  - `pickup`: Pick up items in the room.
  - `equip [item]`: Equip a weapon or armor.
  - `attack`: Fight creatures in the room.
  - `save [filename]`/`load [filename]`: Save or load your progress.
  - `inventory`: View your items.
  - `map`: Display the dungeon map.
  - `playerinfo`: View player stats.
  - `dungeoninfo`: View remaining monsters.
  - `exit`: Quit the game.

## Code Structure
- **`game.h`**: Header file defining data structures (`Player`, `Room`, `Creature`, etc.) and function prototypes.
- **`game.c`**: Main source file implementing the game logic, commands, and mechanics.

## Game Logic
- The dungeon consists of a 4x4 grid of rooms.
- Players start in Room 1 and navigate the dungeon, encountering creatures and collecting items.
- The game ends when all creatures are defeated.
## Requirments
-GCC compiler or a similar C compiler

### Installation

1. Clone the repository to your local machine:
   
   git clone https://github.com/gokman3/Ceng209--TEXT-BASED-DUNGEON-GAME
   
2. Navigate to the project directory:
   
   cd Ceng209--TEXT-BASED-DUNGEON-GAME-main
   
3. Use the Makefile to compile the game:
   
   mingw32-make -f Makefile.mak

### Execution
./dungeon



   


