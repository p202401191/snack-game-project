## Analysis of Data Structures 

In the context of the snake game, multiple data structures are employed to facilitate the functioning of the game grid, the movement of the snake, the positioning of food, and the general state of the game. Let us review some of the important data structures that are present in the code. 

### 1. **Grid Representation** 

The game grid is treated as a representation, it is not a data structure on its own. The grid's width and height are determined by the variables gridWidth and gridHeight which are set based on the grid size selected. 

- Boundaries of the grid are represented by the symbols “#” and empty space is represented by “ “. 

- The game does not explicitly 2D array the grid. Instead, the game calculations rely on grid positions and drawing of the grid, and these actions are performed on every game loop. 

### 2. **Snake Representation** 

The snake is constructed from a **vector of pairs**, more specifically a `vector<pair<int, int>> snake;`. 

- Each pair corresponds to one segment of the snake’s body in the grid. 

- The first element from the pair represents the **x-coordinate** (horizontal position) of the snake segment. 

- The second element from the pair represents the **y-coordinate** (vertical position) of the snake segment.

Each time a snake consumes food, its body elongates by adding new segments at the tail of the snake with the command `snake.push_back({frontX, frontY})`. When the player inputs a command to move the snake, the head of the snake shifts toward the direction of the command, while the rear neck part of the snake gets detached to create the illusion of movement with the command `snake.erase(snake.begin())`.





### 3. **Food Representation**  

The actual food’s position on the grid is specified with the help of two variables, `foodX` and `foodY`, which indicate the food's placement on the grid and type. The `foodtype` variable is given the task of determining if the food is of normal type (denoted by "$") or a special type (denoted by "%").  

- The snake head collides with the food (`frontX == foodX && frontY == foodY`) which results in the snake consuming it with both the head and tail. This elevates its length by one segment.    

- These are performed respectively in random order. The `foodPlace()` function repositions the food to a new location where it does not intersect or overlap with any part of the snakes body.  <br>  

### 4. **Game State**  

These states of the game are controlled with multiple integer and boolean variables: 

- **gameRunning**: This is a boolean statement that is true by default and will only change to false if the snake hits a wall or if it collides with itself.  

- **score**: An integer that is increased every time the player gets a certain amount of points. So, consumption of food by the snake will increase the score and in cases of special food, boost it even more. 

- **highscore**: This integer memory stores the current highest amount of points achieved by the player in the present game state session. 

### 5. **Direction of Movement**

The variable ‘direction’ determines the movement of the snake and an integer value is updated according to user input. 

- ‘0’ means **upwards**. 
- ‘1’ means **rightwards**. 
- ‘2’ means **downwards**. 
- ‘3’ means **leftwards**. 

Players utilize the arrow keys on the keyboard or ‘W’, ‘A’, ‘S’, ‘D’ to update the direction. The snake may only make a turn if it does not move straight into the body of the snake.



### 6. **Randomization For Food Placement** 

Food placement occurs randomly utilizing the function rand() and the seed is set to the current time using the function srand(time(0)). This ensures that food appears at different positions every time the game is played. The coordinates of the food are verified to ensure they do not cross with the boundaries of the snake's body to avoid the possibility of the snake eating food on it. 

### 7. **Input Handling** 

For detecting player key presses the program loads the library ‘conio.h’ and its functions ‘_kbhit’ and ‘_getch’ which permit instantaneous input during the game. Furthermore, the user has access to the following functions: 

- The function ‘_kbhit’ allows for checking if a key has already been pressed. 

- The command ‘_getch’ allows a user to retrieve the pressed key so that the movement of the snake can be altered according to the users needs. 

### 8. **OS requirement**
This code is designed for **windows operating system**.

###  **Conclusion** 

In this case the structures of data are not complicated at all, but they are proficient means to achieving important stages of the game. It is also worth noting that the snake is constructed by means of a vector of pairs of coordinates which allow for the addition and removal of sections as well as in combination with the other vectors of food placement and the logic of random direction gives the game its versatility. 

The ease of understanding the data structures, and the basic control flow framework which include, but are not limited to the vector for the snake as well as the mouse make the game easy to play and fast acting.

Nonetheless, the addition of power-ups, levels or diverse food types can be included by introducing new data structures as well as modifying the existing ones.


