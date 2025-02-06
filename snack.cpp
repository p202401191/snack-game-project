#include <iostream>
#include <conio.h> // For _kbhit() and _getch()

int main() {
    char ch;

    std::cout << "Press arrow keys (or ESC to exit):\n";

    while (true) {
        if (_kbhit()) { // Check if a key has been pressed
            ch = _getch(); // Get the character code

            if (ch == 224) { // Special key (arrow keys are extended codes)
                ch = _getch(); // Get the actual arrow key code
                switch (ch) {
                    case 72: // Up arrow
                        std::cout << "Up arrow pressed\n";
                        break;
                    case 80: // Down arrow
                        std::cout << "Down arrow pressed\n";
                        break;
                    case 75: // Left arrow
                        std::cout << "Left arrow pressed\n";
                        break;
                    case 77: // Right arrow
                        std::cout << "Right arrow pressed\n";
                        break;
                }
            } else if (ch == 27) { // Escape key
                std::cout << "Exiting...\n";
                break;
            }
        }
    }

return 0;
}
