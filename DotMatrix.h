#ifndef DotMatix_h
#define DotMatrix_h

#include "Arduino.h"

class DotMatrix {
  public:
    // Brightness: [1, 40] with 1000/x system.
    int brightness = 20;
    int scrollSpeed = 0;
    void showText(String text, int displayMstext);
    void showText(String text, int displayMstext, int scrollSpeed);
    void showHackerText(String text, int displayMs);
    DotMatrix(int col1, int col2, int col3, int col4, int col5, int dataPin_, int clockPin_);

  private:
    int column[5];
    int dataPin;
    int clockPin;
    const static int maxStringSize = 8;
    char* displayText[maxStringSize];

    char oneChar[7] = {
      0b00100,
      0b01100,
      0b00100,
      0b00100,
      0b00100,
      0b00100,
      0b01110};
  
    char twoChar[7] = {
      0b01110,
      0b10001,
      0b00001,
      0b00110,
      0b01000,
      0b10000,
      0b11111};
  
    char threeChar[7] = {
      0b01110,
      0b10001,
      0b00001,
      0b00110,
      0b00001,
      0b10001,
      0b01110};
  
    char fourChar[7] = {
      0b00010,
      0b00110,
      0b01010,
      0b10010,
      0b11111,
      0b00010,
      0b00010};
  
    char fiveChar[7] = {
      0b11111,
      0b10000,
      0b11110,
      0b00001,
      0b00001,
      0b10001,
      0b01110};
  
    char sixChar[7] = {
      0b00110,
      0b01000,
      0b10000,
      0b11110,
      0b10001,
      0b10001,
      0b01110};
  
    char sevenChar[7] = {
      0b11111,
      0b00001,
      0b00010,
      0b00100,
      0b01000,
      0b01000,
      0b01000};
    char eightChar[7] = {
      0b01110,
      0b10001,
      0b10001,
      0b01110,
      0b10001,
      0b10001,
      0b01110};
  
    char nineChar[7] = {
      0b01110,
      0b10001,
      0b10001,
      0b01111,
      0b00001,
      0b00010,
      0b01100};
  
    char zeroChar[7] = {
      0b01110,
      0b10001,
      0b10011,
      0b10101,
      0b11001,
      0b10001,
      0b01110};
  
    char aChar[7] = {
      0b00000,
      0b00000,
      0b01110,
      0b10010,
      0b10010,
      0b10010,
      0b01101};
  
    char bChar[7] = {
      0b10000,
      0b10000,
      0b10110,
      0b11010,
      0b10001,
      0b10001,
      0b11110};
  
    char cChar[7] = {
      0b00000,
      0b00000,
      0b01110,
      0b10000,
      0b10000,
      0b10001,
      0b01110};
  
    char dChar[7] = {
      0b00001,
      0b00001,
      0b01101,
      0b10011,
      0b10001,
      0b10001,
      0b01111};
  
    char eChar[7] = {
      0b00000,
      0b00000,
      0b01110,
      0b10001,
      0b11110,
      0b10000,
      0b01110};
  
    char fChar[7] = {
      0b00100,
      0b01010,
      0b01000,
      0b11100,
      0b01000,
      0b01000,
      0b01000};
  
    char gChar[7] = {
      0b00000,
      0b00000,
      0b01111,
      0b10001,
      0b01111,
      0b00001,
      0b00110};
  
    char hChar[7] = {
      0b10000,
      0b10000,
      0b10110,
      0b11001,
      0b10001,
      0b10001,
      0b10001};
  
    char iChar[7] = {
      0b00100,
      0b00000,
      0b01100,
      0b00100,
      0b00100,
      0b00100,
      0b01110};
  
    char jChar[7] = {
      0b00010,
      0b00000,
      0b00110,
      0b00010,
      0b00010,
      0b10010,
      0b01100};
  
    char kChar[7] = {
      0b01000,
      0b01000,
      0b01001,
      0b01010,
      0b01100,
      0b01010,
      0b01001};
  
    char lChar[7] = {
      0b01100,
      0b00100,
      0b00100,
      0b00100,
      0b00100,
      0b00100,
      0b01110};
  
    char mChar[7] = {
      0b00000,
      0b00000,
      0b01010,
      0b10101,
      0b10101,
      0b10001,
      0b10001};
  
    char nChar[7] = {
      0b00000,
      0b00000,
      0b10110,
      0b11001,
      0b10001,
      0b10001,
      0b10001};
  
    char oChar[7] = {
      0b00000,
      0b00000,
      0b01110,
      0b10001,
      0b10001,
      0b10001,
      0b01110};
  
    char pChar[7] = {
      0b00000,
      0b00000,
      0b11110,
      0b10001,
      0b11001,
      0b10110,
      0b10000};
  
    char qChar[7] = {
      0b00000,
      0b00000,
      0b01110,
      0b10010,
      0b10110,
      0b01010,
      0b00011};
  
    char rChar[7] = {
      0b00000,
      0b00000,
      0b01011,
      0b01100,
      0b01000,
      0b01000,
      0b01000};
  
    char sChar[7] = {
      0b00000,
      0b00000,
      0b01110,
      0b10000,
      0b01110,
      0b00001,
      0b11110};
  
    char tChar[7] = {
      0b00000,
      0b01000,
      0b11100,
      0b01000,
      0b01000,
      0b01010,
      0b00100};
  
    char uChar[7] = {
      0b00000,
      0b00000,
      0b10001,
      0b10001,
      0b10001,
      0b10011,
      0b01101};
  
    char vChar[7] = {
      0b00000,
      0b00000,
      0b10001,
      0b10001,
      0b10001,
      0b01010,
      0b00100};
  
    char wChar[7] = {
      0b00000,
      0b00000,
      0b10001,
      0b10001,
      0b10101,
      0b10101,
      0b01010};
  
    char xChar[7] = {
      0b00000,
      0b00000,
      0b10001,
      0b01010,
      0b00100,
      0b01010,
      0b10001};
  
    char yChar[7] = {
      0b00000,
      0b00000,
      0b10001,
      0b01010,
      0b00100,
      0b00100,
      0b01000};
  
    char zChar[7] = {
      0b00000,
      0b00000,
      0b11111,
      0b00010,
      0b00100,
      0b01000,
      0b11111};
  
    char colonChar[7] = {
      0b00000,
      0b01100,
      0b01100,
      0b00000,
      0b01100,
      0b01100,
      0b00000};
  
    char spaceChar[7] = {
      0b00000,
      0b00000,
      0b00000,
      0b00000,
      0b00000,
      0b00000,
      0b00000};
  
    char smileyChar[7] = {
      0b00100,
      0b00010,
      0b01001,
      0b00001,
      0b01001,
      0b00010,
      0b00100};
    String allChars = "abcdefghijklmnopqrstuvwxyz";
  
  char* getBitmapFromChar(char c);
  
};

#endif
