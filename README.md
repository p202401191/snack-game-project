# Snake Game

## Overview
This is a simple snake game built in C++ where you control a snake which moves in a grid and eats food to grow larger. The game is over if the snake collides with the wall or itself. The game has different modes and grid sizes.

---

## Instructions and Rules

1. *Movement*: You control the snake using the following keys:
    - *W* or *Up Arrow*: Go Up
    - *S* or *Down Arrow*: Go Down
    - *A* or *Left Arrow*: Go Left
    - *D* or *Right Arrow*: Go Right

2. The game features different modes or easy medium and hard after starting the game.
 - Before starting the game, one chooses the difficulty,
    - Easy: Press e
    - Medium: Press m
    - Hard: Press h
  
   Each mode corresponds with how fast the snake moves.

3. Grid size options:
   - Small: Press 1 (The 15x15 grid)
   - Medium: Press 2 (20x25 grid)
   - Large: Press 3 (25x40 grid)
   
4. Goal: Eat food to grow the snake. Food gives you points. The game ends when you crash into a wall or yourself.

---  

## Code Explanation

### Data structures used

1. **Vector of pairs (vector<pair<int, int>> snake): It contains the cell positions of the snake's body on the grid. The first integer of a pair stands for the x coordinate for one segment of the snake's body, while the second integer is for the y coordinate.

2. *Integer variables* (int frontX, frontY, foodX, foodY): These integers indicate the position of the snake's head and the food on the grid.

3. *Boolean variables* (bool gameRunning): This flag indicates whether the game will be running or not; it will stop when this option becomes false.

4. *Score and high score*:
   - int score: Keeps track of the current score of the player.
   - int highscore: Keeps track of the highest score that day. 

### Methods and Functions

1. *initialize()*:
   - This is the method that initializes the state of the game, such as where the snake starts, and causes the food to appear for the first time in the game.

2. *draw()*:
   - The method clears the screen and takes care of redrawing the whole grid, snake, food, and wall. It shows the score.

3. *input()*:
   - Check for the user inputs which control the snake's direction. Movement is controlled by the WASD keys and the arrow keys.

4. *update()*:
   - Updates the position of the snake in connection with the current direction. It sees if there have been any collisions with the wall or with the snake's own body and subsequently updates the game state. It also takes care of eating the food, adding the score, and increasing the size of the snake.

5. *foodPlace()*:
   - Generates a new food item on the grid at a random position that is not occupied by the snake. The food could be chosen randomly from two varieties ($ and %) and has different points.

6. *run()*:
   - The main game loop itself. This has flow control for the game; it allows the user to set the difficulty level and grid size, initializes the game, and continues calling draw, input, and update functions until the game is over. 

## Data Structure and Object Structure

1. *SnakeBody Vector*: A snake's body is represented as a vector of pairs of integers. Each segment of the snake is a pair of integers, with the first integer representing the x-coordinate and the second integer representing the y-coordinate. The head of the snake lies at the front in the vector hierarchy with the rest of the body segments concerned with movement.

2. **Game Class (SnakeGame): The SnakeGame class is indeed the class that wraps the entire game. It controls the game state, with the functions for setting the grid size, placing bodies and food, scoring the game, and taling into account the core game logic. The class functions include creating the actual game, updating the game state, handling user input, and displaying the game.

---

## Code Structure

- *Global Variables*: Some global variables have been defined to control Sonal's snake game, e.g., food type, playerName, se, and sss.

- *SnakeGame Class*: This class takes care of the logic of the game. It has functions for rendering the game board, getting player input, updating the snake position, processing foods, and managing the state of the game.

- *Game Flow*: The main function begins with obtaining the name of the user and the game board. It initiates a game loop, whereas the user can keep playing until they decide otherwise to quit.

---

## Compatibility
The game is to be played on *Windows Operating System* via console.
