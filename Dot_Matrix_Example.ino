#include "DotMatrix.h"

DotMatrix display(6, 5, 4, 3, 2, 7, 8);

void setup(){
  display.showHackerText("test", 3000);
  //display.showText("scroooll", 5000, 500); 
}

void loop(){
  display.showText("0123", 1000);
  display.showText("4567", 1000);
  display.showText("89ab", 1000);
  display.showText("cdef", 1000);
  display.showText("ghij", 1000);
  display.showText("klmn", 1000);
  display.showText("opqr", 1000);
  display.showText("stuv", 1000);
  display.showText("wxyz", 1000);
  
}

