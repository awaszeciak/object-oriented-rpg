# RPG C++ – Object Oriented Game

## Project Description

This project is a console-based RPG game written in C++, designed to demonstrate object-oriented programming concepts and modular code structure.

The game includes:
- character system (Character, Elf, SantaClauss)
- army system (ElfArmy, SantaArmy)
- battle system between armies
- inventory system (Inventory, Item)
- quest system (Quest, Reward, QuestTimer)
- action management (ActionQueue)

The project is divided into multiple modules (libraries), improving code organization and scalability.

---

## Project Structure

### Core Game

Folders:

Library responsible for handling actions:

- `Action` – represents a single action
- `ActionQueue` – queue of actions (FIFO)
- `Hero` – special character executing actions

 allows managing sequences of actions in the game

---

### questlib


Extended quest system:

- `Quest_v2`, `SubQuest_v2`
- `Reward_v2`, `RewardType_v2`
- `QuestTimer_v2`
- `questFunctions_v2`

provides a more advanced quest mechanism

---

## OOP Concepts Used

The project demonstrates:

- **Inheritance**
  - `Elf` and `SantaClauss` inherit from `Character`

- **Polymorphism**
  - shared methods for different object types

- **Encapsulation**
  - internal data hidden inside classes

- **Modularity**
  - separation into libraries (`actionlib`, `questlib`)

---

## Game Mechanics

- Characters are grouped into armies
- Armies can fight each other (`battleArmies`)
- Characters have:
  - stats
  - inventory
- Player actions are managed via `ActionQueue`
- Quests provide rewards and progression

---

## How to Run

### Requirements
- C++17+
- CMake

---

### Build

```bash
mkdir build
cd build
cmake ..
make
