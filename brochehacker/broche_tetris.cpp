#include "brochehacker.h"

const byte HEIGHT = 12;
static byte board[HEIGHT] = {0,0,0,0,0,0,0,0,0,0,0,0};
static byte sprite[HEIGHT] = {0,0,0,0,0,0,0,0,0,0,0,0};

const byte MIDDLE = 2;
const byte cycleForgiveness = 10;
byte cycleFall = 50;
boolean initTetris = true;

byte cycle;
byte block;
byte orientation;
char x = MIDDLE; // char for signedness
char y = 5;

// outputs both board and sprite muxed into screen
void blitScreen() {
  for(byte i = 3; i < 11; i++)
    screen[i-3] = board[i] | sprite[i];
}

// makes sprite be a single block at x and y
void blitSprite() {
  memset(sprite,0,HEIGHT);
  byte offset = block*8 + orientation*2;
  char _y = y-1;
  sprite[++_y] = (blocks[offset]        & 0b11110000);
  sprite[++_y] = (blocks[offset]<<4     & 0b11110000);
  sprite[++_y] = (blocks[offset + 1]    & 0b11110000);
  sprite[++_y] = (blocks[offset + 1]<<4 & 0b11110000);
  for(byte i = 0; i < 4; i++) {
    _y = y+i;
    if(x < 0) sprite[_y]<<=-x;
    else sprite[_y]>>=x;
  }
  
  blitScreen();
}

// --- collision routines

//checks if piece can go left (false if collides)
boolean checkLeft() {
  if(x <= minX[block*4+orientation]) return false;
  if(checkSidewaysCollision(-1)) return false;
  return true;
}

//checks if piece can go right (false if collides)
boolean checkRight() {
  if(x >= maxX[block*4+orientation]) return false;
  if(checkSidewaysCollision(1)) return false;
  return true;
}

// checks for board collision (true if collides)
boolean checkSidewaysCollision() { // default to no offset
  return checkSidewaysCollision(0);
}
boolean checkSidewaysCollision(char offset) {
  char _y;
  for(byte i = 0; i < 4; i++) {
    _y = i+y;
    if(offset < 0) {
      if(sprite[_y]<<-offset & board[_y]) return true;
    } else {
      if(sprite[_y]>>offset & board[_y]) return true;
    }
  }
  return false;
}

// checks collision if block goes one down (true if collides)
boolean checkBottomCollision() {
  //if(sprite[10] & 0b11111111) return true;
  char _y;
  for(byte i = 0; i < 4; i++) {
    _y = i+y;
    if(_y > 0 && sprite[_y] & board[_y+1]) return true;
  }
  return false;
}

// check if block can rotate (false if collides)
boolean checkRotation() {
  byte oldOrientation = orientation;
  char oldX = x;
  orientation++;
  if(orientation >= 4) orientation = 0;
  byte offset = block*4+orientation;
  if(x < minX[offset]) x = minX[offset];
  else if(x > maxX[offset]) x = maxX[offset];
  blitSprite();
  boolean result = checkSidewaysCollision();
  // TODO: check if out of bounds (how??)
  orientation = oldOrientation;
  x = oldX;
  blitSprite();
  return !result;
}

// ---

// clear a line
void clearLine(byte row) {
  for(byte i = row; i > 0; i--)
    board[i] = board[i-1];
  board[0] = 0;
}

// clear the board
void clearBoard() {
  memset(sprite,0,HEIGHT);
  memset(board,0,HEIGHT);
  board[HEIGHT-1] = 0b11111111;
}

// commit block to board and spawn a new block
void newBlock() {
  for(byte i = 0; i < HEIGHT; i++)
    board[i] |= sprite[i];

  for(byte i = 0; i < HEIGHT-1; i++) {
    if(board[i] == 0b11111111)
    clearLine(i);
  }

  block = random(7);
  orientation = 0;
  x = MIDDLE;
  y = 0;
  blitSprite();
  if(checkSidewaysCollision()) {
    // game over
    initTetris = true;
    state = ST_GLIDER;
  }
}

// loop function for tetris
void runTetris() {
  // init variables - new game
  if(initTetris) {
    randomSeed(millis());
    byte randomTrash;
    randomTrash = random(7);
    randomTrash = random(7);
    randomTrash = random(7);
    randomTrash = random(7);
    initTetris = false;
    cycle = 0;
    clearBoard();
    newBlock();
  }
  
  byte btn = buttonState();
  if(btn & BUTTON_1) { // move left
    if(checkLeft()) {
      x--;
      blitSprite();
      // if it's about to hit, increase drop time a little
      if(cycle >= cycleForgiveness && checkBottomCollision()) cycle-=cycleForgiveness;
    }
  } else if(btn & BUTTON_2) { // move right
    if(checkRight()) {
      x++;
      blitSprite();
      if(cycle >= cycleForgiveness && checkBottomCollision()) cycle-=cycleForgiveness;
    }
  } else if(btn & BUTTON_4) { // rotate
    if(checkRotation()) {
      orientation++;
      if(orientation >= 4) orientation = 0;
      byte offset = block*4+orientation;
      if(x < minX[offset]) x = minX[offset];
      else if(x > maxX[offset]) x = maxX[offset];
      blitSprite();
      if(cycle >= cycleForgiveness && checkBottomCollision()) cycle-=cycleForgiveness;
    }
  }

  cycle++;
  if(cycle >= cycleFall) {
    cycle = 0;
    if(checkBottomCollision()) {
      newBlock();
    } else {
      y++;
      blitSprite();
    }
  }
}

