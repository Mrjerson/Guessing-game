#ifndef NBAHEADER1_H_INCLUDED
#define NBAHEADER1_H_INCLUDED


//add on functions for screen console management
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*================================================*/

//#include <stdlib.h>
void clrscr()
    {
        system("cls");
    }

/*================================================*/

//#include<time.h>
void delay(unsigned int mseconds)
    {
        clock_t goal = mseconds + clock();
        while (goal > clock());
    }
    
/*================================================*/

//#include <windows.h>
void gotoxy(int x, int y) //function definition
     {
            COORD xyPos = {0, 0};   //initialization cursor position
            xyPos.X = x;   xyPos.Y =  y;  //assign coordinates

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xyPos);
    }

/*================================================*/


void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}


/*================================================*/
//#include <stdio.h>
void wait()
    {
		char msg[35] = " Loading...please wait for a while";
        for(int i = 0; i < 20; i++)
        {
            gotoxy(40,11);  printf("%c", 196);  delay(150);
            gotoxy(40,11);  printf("%c", 92); delay(150);
            gotoxy(40,11);  printf("%c", 179); delay(150);
            gotoxy(40,11);  printf("%c", 47);  delay(150);

	   		gotoxy(24,13);
            printf("%s", msg);
        }
        
        clrscr();
    }
/*================================================*/


#endif // NBAHEADER1_H_INCLUDED