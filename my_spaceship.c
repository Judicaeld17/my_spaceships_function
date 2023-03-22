#include<stdlib.h>
#include<string.h>

int my_strcmp(char* str1, char* str2){
    if(strlen(str1)==strlen(str2)){
      while(*str1!='\0'){
          if(*str1==*str2){
              str1++;
              str2++;
          }
          else{
              return 0;
          }
      }
      return 1;
    }
    else{
        return 0;
    }
}
char* set_direction(char* dir){
    int len =strlen(dir);
    char* Direction =(char*)malloc((len+1)*sizeof(char));
    char* temp =Direction;
    while(*dir!='\0'){
        *temp=*dir;
        temp++;
        dir++;
    }
    *temp='\0';
    return Direction;
}
char* my_spaceship(char* travel_path){
    char* temp = travel_path;
    char* Direction = set_direction("up");
    char* up=(char*)malloc((strlen("up")+1)*sizeof(char));
    strcpy(up,"up");

    char* down=(char*)malloc((strlen("down")+1)*sizeof(char));
    strcpy(down,"down");

    char* right=(char*)malloc((strlen("right")+1)*sizeof(char));
    strcpy(right,"right");

    char* left=(char*)malloc((strlen("left")+1)*sizeof(char));
    strcpy(left,"left");
    int x=0;
    int y=0;

    char* format_result(int x,int y,char* direction){
        int r_val_size = snprintf(NULL,0,"{x: %d, y: %d, direction: '%s'}",x,y,direction);
        char* r_val=(char*)malloc(r_val_size*sizeof(char));
        snprintf(r_val,100,"{x: %d, y: %d, direction: '%s'}",x,y,direction);
        return r_val;   
    }

    while(*temp!='\0'){
        if(*temp=='R'){
            if(my_strcmp(Direction,up )){
              Direction=set_direction(right);
            }
            else if(my_strcmp(Direction,right)){
                Direction=set_direction(down);
            }
            else if(my_strcmp(Direction,down)){
                Direction=set_direction(left);
            }
            else{
                Direction=set_direction(up);
            }   
        }
        else if(*temp=='L'){
            if(my_strcmp(Direction,up )){
              Direction=set_direction(left);
            }
            else if(my_strcmp(Direction,right)){
                Direction=set_direction(up);
            }
            else if(my_strcmp(Direction,down)){
                Direction=set_direction(right);
            }
            else{
                Direction=set_direction(down);
            }   
        }
        else{
            if(my_strcmp(Direction,up )){
              y--;
            }
            else if(my_strcmp(Direction,right)){
              x++;
            }
            else if(my_strcmp(Direction,down)){
             y++;
            }
            else{
             x--;
            }   
        }
        temp++;
    }
 return format_result(x,y,set_direction(Direction));   
}

// Description
// You have been recently been hired by SpacePro, a new rocket manufacturer, and have been tasked with designing a simulator for their spaceships. This simulator creates a virtual “space” and keeps track of the basic movements and direction of a given ship. Your job is to keep track of where the ship is and it’s orientation relative to its starting point.

// Instructions
// Your ship simulator must take in a string of letters that represent a planned flight path for a given rocket ship.

// In a ship’s flight path there are only 3 valid options for movement; R for turning right, L for turning left and A for advancing.

// If, for example, you receive “RRALAA” as your flight path, you should interpret it as the following:
// Turn right, turn right, advance, turn left, advance, advance
// Once given this initial flight path, your program must return the x,y coordinates of a ship’s final destination as well as it’s orientation relative to the starting point.

// Orientation is represented as left, right, up or down.

// Space is infinite, so the x,y coordinates you return could be placed on a seemingly infinite grid and can be negative or positive values.

// So let's say an upward-facing rocket ship leaves its starting point of 0,0 and is given the flight path of “RRALAA”, its final location will be 2,-1 and it will be facing right.

// Your Job
// You must create a function that takes in a flight path of a rocket ship as a string of letters and returns the following format:
// "{x: X, y: Y, direction: 'DIRECTION'}"
// X,Y represent the ending coordinates of your ship and direction represents its final direction.

// Notes
// Function my_spaceship returns a STRING.

// Tip
// (In C)
// In C, you can use snprintf.