/*

This runs in a windows console, doesn't work on other operating systems (it uses conio.h, an old dos library)


Code for a moving player on the screen

Use 'W', 'A', 'S', 'D'   to move the player

Compiled with MinGW-w64 for windows

*/

#include <stdio.h>
#include <conio.h>
#include <unistd.h>

int main() {

    int px = 10; //player X position
    int py = 10; //player Y position

    while(1) {

        //user input
        if(kbhit()) { //function from 'conio.h'
            char input = getch(); //function from 'conio.h'
            switch(input) {
                case 'd':
                    px++;
                    break;
                case 'a':
                    px--;                 //detects which key is pressed
                    break;
                case 's':
                    py++;
                    break;
                case 'w':
                    py--;
                    break;
            }
        }

        //drawing code

        system("cls"); //clears the screen

        for(int y = 0; y < 21; y++) {
            for(int x = 0; x < 21; x++) {          //the screen size is 20 characters, so we say 21

                int draw = 0; //draw buffer           0 = false, 1 = true
                
                if(x == px && y == py) {    
                    draw = 1;
                    printf("P"); //draw the player
                }

                if(!draw) {
                    printf(" "); //print empty space if nothing is being drawn
                }

            }
            printf("\n"); //endline character for each row
        }

        //end of game loop
        usleep(100000); //sleeps for 100,000 microseconds,   function from 'unistd.h'

    }

}