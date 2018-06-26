#include "DotMatrix.h"

void DotMatrix::showText(String text, int displayMs) {
  showText(text, displayMs, 0);
}

void DotMatrix::showText(String text, int displayMs, int scrollMs) {
  // Parse the bitmaps for the given string.
  for (int i = 0; i < text.length(); i++) {
    displayText[i] = getBitmapFromChar(text[i]);
  }

  int textLength = text.length();
  int scrollTime = millis();
  int scrollOffset = 0;
  
  int startTime = millis();
  while(millis() - startTime < displayMs) {
	// Increment scroll offset at the desired rate.
    if (scrollMs > 0 && millis() - scrollTime > scrollMs) {
      scrollOffset = (scrollOffset + 1) % textLength;
      scrollTime = millis();
    }

    // Loop for all columns.
    for (int colNum = 0; colNum < 5; colNum++) {
      // Loop for a single column.
      for (int j = 0; j < textLength; j++) {
        int charToRead = (j + scrollOffset) % textLength;
        // Loop for loading bits of one column of a single character.
        for (int k = 0; k < 7; k++) {
          // Shift the data in to the display.
          boolean bitToFeed = displayText[charToRead][k] & (1 << colNum);
          digitalWrite(dataPin, bitToFeed);
          digitalWrite(clockPin, HIGH);
          digitalWrite(clockPin, LOW);
        }
      }

      // This is how brightness is controlled. The longer the column is held high,
      // the longer the leds will shine for.
      digitalWrite(column[colNum], HIGH);
      delayMicroseconds(brightness*brightness);
      digitalWrite(column[colNum], LOW);
    }
  }
}

void DotMatrix::showHackerText(String text, int displayMs) {
  // Decode the text.
  int textLength = text.length();
  int charsPerIncrement = 5;
  int decodePerCharTime = 150;
  int scrabbleInstantTime = decodePerCharTime / charsPerIncrement;
  // Outer loop for each frame change
  for (int i = 0; i < textLength * charsPerIncrement; i++) {
    char decoderText[textLength];
    // Adds legitimate text to screen
    for (int j = 0; j < i / charsPerIncrement; j++) {
      decoderText[j] = text[j];
    }
    // Adds scrambled letters to screen
    for (int k = i / charsPerIncrement; k < textLength; k++) {
      decoderText[k] = allChars[random(26)];
    }
    showText(decoderText, scrabbleInstantTime);
  }

  // Once text is visually decoded, just show normal text.
  showText(text, displayMs);
}

DotMatrix::DotMatrix(
    int col1, int col2, int col3, int col4, int col5, int dataPin_, int clockPin_) {
  column[0] = col1;
  column[1] = col2;
  column[2] = col3;
  column[3] = col4;
  column[4] = col5;
  dataPin = dataPin_;
  clockPin = clockPin_;
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, HIGH);
  for (int i = 0; i < 5; i++) {
    pinMode(column[i], OUTPUT);
    digitalWrite(column[i], LOW);
  }
}

char* DotMatrix::getBitmapFromChar(char c) {
    switch(c) {
      case '0': return zeroChar;
      case '1': return oneChar;
      case '2': return twoChar;
      case '3': return threeChar;
      case '4': return fourChar;
      case '5': return fiveChar;
      case '6': return sixChar;
      case '7': return sevenChar;
      case '8': return eightChar;
      case '9': return nineChar;
      case 'a': return aChar;
      case 'b': return bChar;
      case 'c': return cChar;
      case 'd': return dChar;
      case 'e': return eChar;
      case 'f': return fChar;
      case 'g': return gChar;
      case 'h': return hChar;
      case 'i': return iChar;
      case 'j': return jChar;
      case 'k': return kChar;
      case 'l': return lChar;
      case 'm': return mChar;
      case 'n': return nChar;
      case 'o': return oChar;
      case 'p': return pChar;
      case 'q': return qChar;
      case 'r': return rChar;
      case 's': return sChar;
      case 't': return tChar;
      case 'u': return uChar;
      case 'v': return vChar;
      case 'w': return wChar;
      case 'x': return xChar;
      case 'y': return yChar;
      case 'z': return zChar;
      case ':': return colonChar;
      case ' ': return spaceChar;
      //case '': return smileyChar;
	  // Feel free to add more chars. Just remember it takes up precious memory ;)
      default: return 0;
    }
}
