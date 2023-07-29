# Welcome to Lovely Secret
***

## Description
The project "lovely_secret" is an implementation of the famous game Mastermind. The game involves a secret code composed of four distinct pieces from a set of nine different colors. The player has ten attempts to guess the secret code. After each input, the game provides feedback to the player in the form of the number of well-placed pieces and the number of misplaced pieces.
## How to play
1. Open the terminal.
2. Navigate to the folder containing the game files.
3. Type make and press Enter to compile the program.
4. To play the game with a randomly generated secret code
```
TYPE ./my_mastermind -c AND PRESS ENTER.
```
5. To play the game with a specific secret code, replace [CODE] with the desired 4-digit code and
``` 
type ./my_mastermind -c [CODE] in the terminal, then press Enter.
```
6. By default, the player has 10 attempts to find the secret code. To specify a different number of attempts, add the -t [ATTEMPTS] flag after the secret code. For example, to play with 5 attempts,
```
type ./my_mastermind -c [CODE] -t 5 and press Enter.
```
7. After each input, the game will indicate the number of well-placed pieces and the number of misplaced pieces.
The game will continue until the player finds the correct code or runs out of attempts.
8. If the player finds the code, the game will display "Congratz! You did it!"
9. If the player enters an invalid code, the game will display the number of well-placed pieces and misplaced pieces, helping the player to refine their guess.
10. To exit the game at any time, press Ctrl + D.
Enjoy the challenge and have fun playing Mastermind!


## Installation
1. C Compiler: The game is written in C, so you need a C compiler to compile the source code.
Make: The project comes with a Makefile to simplify compilation.
2. Standard C Library: The game uses standard C library functions, such as printf, write, read, rand, time, atoi, and strcmp. These are typically included with the C compiler.

**Enjoy playing the Mastermind game and see if you can crack the secret code!**
