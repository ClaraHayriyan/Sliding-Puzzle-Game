# Sliding-Puzzle-Game
Sliding Puzzle  A console application for the sliding puzzle game.

## Description

An interactive console application, with a menu, in wich the game mode can be selected,
and asynchronous user input processing, wich provides an opportunity to restart
or to quit the game at any moment while playing.

## Getting Started

### Requirements

* Linux o.s.
* g++
* ncurses library

### Compilation

You can install the ncurses library by using this command:

```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

The code can be compiled with the provided makefile using the standard `make`
command.

If compiling the code manually, include the following flag:

```
-lncurses
```

### Executing program

Run the program using the following command.
```
./slidingpuzzle
```
