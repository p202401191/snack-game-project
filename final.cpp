#include <bits/stdc++.h>
#include <conio.h>
using namespace std ;
int foodtype = 0 ;


string playerName;
int se ;
int highscore ;

class SnakeGame {
private:
    int gridWidth;
    int gridHeight;
    int frontX, frontY;
    int foodX, foodY;
    vector<pair<int, int>> snake ;
    int direction;
    bool gameRunning;
    int score;

public:
    SnakeGame() : gridWidth(se), gridHeight(se) 
    {
        initialize();
    }

    void initialize() {
        frontX = gridWidth / 2;
        frontY = gridHeight / 2;
        snake.clear();
        snake.push_back({frontX, frontY});
        snake.push_back({frontX-1,frontY}) ;
        snake.push_back({frontX-2,frontY}) ;
        direction = 1;  
        gameRunning = true;
        score = 0;
        foodPlace();
    }

    void draw() {
        system("cls") ;
        for (int i = 0; i < gridHeight; i++) 
        {
            for (int j = 0; j < gridWidth; j++) 
            {
                if(i == 0 || i == gridHeight - 1 || j == 0 || j == gridWidth - 1)
                {
                    cout << "#" ;  
                } 
                else if (i == frontY && j == frontX) 
                {
                    cout << "@" ; 
                } 
                else if (i == foodY && j == foodX) 
                {
                    if(foodtype==0)cout << "$" ;
                    else  cout<<"%" ; 
                } 
                else 
                {
                    bool isBody = false;
                    for (auto segment : snake) 
                    {
                        if (segment.first == j && segment.second == i) 
                        {
                            cout << "*";  
                            isBody = true;
                            break;
                        }
                    }
                    if (!isBody) cout << " ";
                }
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;
    }

    void input() 
    {
        if (_kbhit()) 
        {
            int key = _getch();

            if (key == 224) 
            {
                key = _getch();
                switch (key) {
                    case 72: if (direction != 2) direction = 0; break;  
                    case 77: if (direction != 3) direction = 1; break;
                    case 80: if (direction != 0) direction = 2; break;  
                    case 75: if (direction != 1) direction = 3; break;  
                }
            } else 
            {
                switch (key) 
                {
                    case 'w': if (direction != 2) direction = 0; break;  
                    case 'd': if (direction != 3) direction = 1; break;  
                    case 's': if (direction != 0) direction = 2; break;  
                    case 'a': if (direction != 1) direction = 3; break;  
                }
            }
        }
    }

    void update() 
    {
        switch (direction) 
        {
            case 0: frontY--; break;  
            case 1: frontX++; break;  
            case 2: frontY++; break;  
            case 3: frontX--; break;   
        }

        if (frontX <= 0 || frontX >= gridWidth - 1 || frontY <= 0 || frontY >= gridHeight - 1) 
        {
            gameRunning = false;
            return;
        }

        for (auto segment : snake) 
        {
            if (segment.first == frontX && segment.second == frontY) 
            {
                gameRunning = false;
                return;
            }
        }

        bool chefood = false ;
        if (frontX == foodX && frontY == foodY) 
        {
            if(foodtype==0) score += 1 ;
            else score += 5 ;
            snake.push_back({foodX, foodY});
            foodPlace();
            chefood = true ;
        }

        if(!chefood) 
        {
            snake.push_back({frontX,frontY}) ;
            snake.erase(snake.begin()) ;
        }
    }

    void foodPlace() {
        srand(time(0));
        while (true) {
            foodX = rand() % (gridWidth - 2) + 1;
            foodY = rand() % (gridHeight - 2) + 1;

            bool onSnake = false;
            for (auto segment : snake) {
                if (segment.first == foodX && segment.second == foodY) {
                    onSnake = true;
                    break;
                }
            }
            if (!onSnake) break;
        }
        foodtype = rand()%2 ;
    }

    void run() 
    {
        while (true) {
            gameRunning = true;
            cout << "Press 'h' for hard mode, 'm' for medium mode, 'e' for easy mode" << endl;
            char chh;
            cin >> chh;

            int an;
            if (chh == 'h') an = 50;  
            else if (chh == 'm') an = 100; 
            else an = 200; 

            initialize();
            while (gameRunning)
            {
                draw();
                input();
                update();
                _sleep(an);
            }
            if(score>highscore) highscore = score ;
            cout << "Game Over! " <<endl<< playerName << "'s score: " << score << endl ;
            cout<<"->  your highest score: "<<highscore<<endl ;
            cout << "-> Press 'i' to play again or any other key to exit." << endl;
            char ch;
            cin >> ch;

            if (ch != 'i') break;  
        }
    }
};

int main() {
    cout << "Enter Player name: " << endl;
        cin >> playerName;
        cout<<endl ;
        cout << "Hello " << playerName << endl;
        cout << endl;
        cout << endl;
        cout << "WELCOME TO SNAKE GAME" << endl;
        cout << endl;
        cout << "GAME RULES :" << endl;
        cout << endl;
        cout << "-> There will be one grid in which your snake will move." << endl;
        cout << "-> If your snake collides with the wall or its body part, the game will be over." << endl;
        cout << "-> Press 'w' or the up arrow for moving the snake upward." << endl;
        cout << "-> Press 'd' or the right arrow for moving the snake right." << endl;
        cout << "-> Press 's' or the down arrow for moving the snake downward." << endl;
        cout << "-> Press 'a' or the left arrow for moving the snake left." << endl;
        cout << endl;
        cout<<endl ;
        cout<<"select grid size as you want"<<endl ;
        cout<<"->  Press 1 for small grid"<<endl ;
        cout<<"->  Press 2 for medium grid"<<endl ;
        cout<<"->  Press 3 for big grid"<<endl ;
        int gg ;
        cin>>gg ;
        if(gg==1) se = 15 ;
        if(gg==2) se = 20 ;
        if(gg==3) se = 30 ;
        else se = 15 ;
    SnakeGame game;
    game.run();
    return 0;
}
