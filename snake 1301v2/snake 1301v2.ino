/* -------------------------------------------------------------------------
   ChristmasIcons Library Examples
   ESP library for PxMatrix displays which contains a number of Christmas Icons.
   Created by Gavin Smalley, October 31st 2019.
   Released into the public domain.

   Please Note: This example will only run on a 64x64 display or larger as it displays
                four 32x32 icons at a time.
                The library itself works on any PxMatrix display which is at least
                32x32.
   ------------------------------------------------------------------------- */

/* Set Up the PxMatrix Display
   This is boilerplate code required for the PxMatrix display to run,
   it is not specific to this library or example.
   For more details see the PxMatrix library documentation and its own examples. */

// #define ALICEBLUE 0xF7DF
// #define ANTIQUEWHITE 0xFF5A
// #define AQUA 0x07FF
// #define AQUAMARINE 0x7FFA
// #define AZURE 0xF7FF
// #define BEIGE 0xF7BB
// #define BISQUE 0xFF38
// #define BLACK 0x0000
// #define BLANCHEDALMOND 0xFF59
// #define BLUE 0x001F
// #define BLUEVIOLET 0x895C
// #define BROWN 0xA145
// #define BURLYWOOD 0xDDD0
// #define CADETBLUE 0x5CF4
// #define CHARTREUSE 0x7FE0
// #define CHOCOLATE 0xD343
// #define CORAL 0xFBEA
// #define CORNFLOWERBLUE 0x64BD
// #define CORNSILK 0xFFDB
// #define CRIMSON 0xD8A7
// #define CYAN 0x07FF
// #define DARKBLUE 0x0011
// #define DARKCYAN 0x0451
// #define DARKGOLDENROD 0xBC21
// #define DARKGRAY 0xAD55
// #define DARKGREEN 0x0320
// #define DARKKHAKI 0xBDAD
// #define DARKMAGENTA 0x8811
// #define DARKOLIVEGREEN 0x5345
// #define DARKORANGE 0xFC60
// #define DARKORCHID 0x9999
// #define DARKRED 0x8800
// #define DARKSALMON 0xECAF
// #define DARKSEAGREEN 0x8DF1
// #define DARKSLATEBLUE 0x49F1
// #define DARKSLATEGRAY 0x2A69
// #define DARKTURQUOISE 0x067A
// #define DARKVIOLET 0x901A
// #define DEEPPINK 0xF8B2
// #define DEEPSKYBLUE 0x05FF
// #define DIMGRAY 0x6B4D
// #define DODGERBLUE 0x1C9F
// #define FIREBRICK 0xB104
// #define FLORALWHITE 0xFFDE
// #define FORESTGREEN 0x2444
// #define FUCHSIA 0xF81F
// #define GAINSBORO 0xDEFB
// #define GHOSTWHITE 0xFFDF
// #define GOLD 0xFEA0
// #define GOLDENROD 0xDD24
// #define GRAY 0x8410

// #define GREENYELLOW 0xAFE5
// #define HONEYDEW 0xF7FE
// #define HOTPINK 0xFB56
// #define INDIANRED 0xCAEB
// #define INDIGO 0x4810
// #define IVORY 0xFFFE
// #define KHAKI 0xF731
// #define LAVENDER 0xE73F
// #define LAVENDERBLUSH 0xFF9E
// #define LAWNGREEN 0x7FE0
// #define LEMONCHIFFON 0xFFD9
// #define LIGHTBLUE 0xAEDC
// #define LIGHTCORAL 0xF410
// #define LIGHTCYAN 0xE7FF
// #define LIGHTGOLDENRODYELLOW 0xFFDA
// #define LIGHTGREEN 0x9772
// #define LIGHTGREY 0xD69A
// #define LIGHTPINK 0xFDB8
// #define LIGHTSALMON 0xFD0F
// #define LIGHTSEAGREEN 0x2595
// #define LIGHTSKYBLUE 0x867F
// #define LIGHTSLATEGRAY 0x7453
// #define LIGHTSTEELBLUE 0xB63B
// #define LIGHTYELLOW 0xFFFC
// #define LIME 0x07E0
// #define LIMEGREEN 0x3666
// #define LINEN 0xFF9C
// #define MAGENTA 0xF81F
// #define MAROON 0x8000
// #define MEDIUMAQUAMARINE 0x6675
// #define MEDIUMBLUE 0x0019
// #define MEDIUMORCHID 0xBABA
// #define MEDIUMPURPLE 0x939B
// #define MEDIUMSEAGREEN 0x3D8E
// #define MEDIUMSLATEBLUE 0x7B5D
// #define MEDIUMSPRINGGREEN 0x07D3
// #define MEDIUMTURQUOISE 0x4E99
// #define MEDIUMVIOLETRED 0xC0B0
// #define MIDNIGHTBLUE 0x18CE
// #define MINTCREAM 0xF7FF
// #define MISTYROSE 0xFF3C
// #define MOCCASIN 0xFF36
// #define NAVAJOWHITE 0xFEF5
// #define NAVY 0x0010
// #define OLDLACE 0xFFBC
// #define OLIVE 0x8400
// #define OLIVEDRAB 0x6C64
// #define ORANGE 0xFD20
// #define ORANGERED 0xFA20
// #define ORCHID 0xDB9A
// #define PALEGOLDENROD 0xEF55
// #define PALEGREEN 0x9FD3
// #define PALETURQUOISE 0xAF7D
// #define PALEVIOLETRED 0xDB92
// #define PAPAYAWHIP 0xFF7A
// #define PEACHPUFF 0xFED7
// #define PERU 0xCC27
// #define PINK 0xFE19
// #define PLUM 0xDD1B
// #define POWDERBLUE 0xB71C
// #define PURPLE 0x8010
// #define RED 0xF800
// #define ROSYBROWN 0xBC71
// #define ROYALBLUE 0x435C
// #define SADDLEBROWN 0x8A22
// #define SALMON 0xFC0E
// #define SANDYBROWN 0xF52C
// #define SEAGREEN 0x2C4A
// #define SEASHELL 0xFFBD
// #define SIENNA 0xA285
// #define SILVER 0xC618
// #define SKYBLUE 0x867D
// #define SLATEBLUE 0x6AD9
// #define SLATEGRAY 0x7412
// #define SNOW 0xFFDF
// #define SPRINGGREEN 0x07EF
// #define STEELBLUE 0x4416
// #define TAN 0xD5B1
// #define TEAL 0x0410
// #define THISTLE 0xDDFB
// #define TOMATO 0xFB08
// #define TURQUOISE 0x471A

// #define WHEAT 0xF6F6
// #define WHITE 0xFFFF
// #define WHITESMOKE 0xF7BE

// #define YELLOWGREEN 0x9E66

#define SWITCH 35
#define VRY 32
#define VRX 33
#define YELLOW 0xFFE0
#define VIOLET 0xEC1D
#define GREEN 0x0400
#define DARKVIOLET 0x901A
int sw;
int sy;
int sx;

#define double_buffer
#include <PxMatrix.h>

#define DISPLAY_DRAW_TIME 10

#ifdef ESP32

#define P_LAT 22
#define P_A 19
#define P_B 23
#define P_C 18
#define P_D 5
#define P_E 15
#define P_OE 2
hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

#endif

#ifdef ESP8266

#include <Ticker.h>
Ticker display_ticker;
#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_D 12
#define P_E 0
#define P_OE 2

#endif

// Pins for LED MATRIX

//PxMATRIX display(64,32,P_LAT, P_OE,P_A,P_B,P_C,P_D);
PxMATRIX display(32, 32, P_LAT, P_OE, P_A, P_B, P_C, P_D);

#ifdef ESP8266
// ISR for display refresh
void display_updater() {
  display.display(DISPLAY_DRAW_TIME);
}
#endif

#ifdef ESP32
void IRAM_ATTR display_updater() {
  display.display(DISPLAY_DRAW_TIME);
}
#endif

/* Begin the Christmas Icons Code */

#include <ChristmasIcons.h>

/* The constructor takes a pointer to the PxMatrix display object. */

ChristmasIcons ChristmasIcons(&display);

/* Set up an array of icons and some control variables so that the code
   can iterate through them later.
   It would be unusual to do this this way in a practical project,
   more likely would be to reference the Icon name (list below) directly in
   the ChristmasIcons.drawIcon() call, eg
     ChristmasIcons.drawIcon(5, 5, bells);
   This section is, therefore, quite specific to this example. */

const uint16_t *icons[44] = {
  bells,
  bigbell,
  bluelight,
  candycane,
  hat,
  clearlight,
  goldball,
  goldcandle,
  goldstar,
  greenball,
  greencandle,
  greencandle_2,
  greenlight,
  holly_1,
  holly_2,
  present_1,
  present_2,
  present_3,
  present_4,
  present_5,
  purpleball,
  reindeer,
  reindeers,
  redball,
  redcandle,
  redcandle_2,
  redlight,
  santa,
  silverball,
  silvercandle,
  silverstar,
  sled,
  snowglobe_penguin,
  snowglobe_tree,
  snowman,
  stocking,
  tree_1,
  tree_2,
  whitecandle,
  woodenball,
  wreath_1,
  wreath_2,
  wreath_3,
  yellowlight
};
int icon_count = 44;
int current_icon = 0;

/* Now run setup() */

#define SNAKE_COLOR 45
#define FRUIT_COLOR 50000
#define T_COLONNE 32
#define T_LIGNE 32


int pos_x_head = 16;
int pos_y_head = 16;
int dtime = 200;
int direction = -1;  // gauche 0, haut 1, droite 2, bas 3
int pos_food_x;
int pos_food_y;
int snakeSize = 3;
bool directChanged = false;
bool eating = false;

int plateau[T_LIGNE][T_COLONNE];
void pixelShow(int x, int y, int newColor) {
  display.clearDisplay();
  display.drawPixel(x, y, newColor);
  display.showBuffer();
}

bool checkGameOver() {
  bool gameOver = false;

  for (int ligne = 0; ligne < T_LIGNE; ligne++) {
    for (int colonne = 0; colonne < T_COLONNE; colonne++) {
      if (plateau[ligne][colonne] > snakeSize)
        gameOver = true;
    }
  }
  return (gameOver);
}

void resetGame() {
  pos_x_head = 16;
  pos_y_head = 16;
  dtime = 100;
  direction = -1;  // gauche 0, haut 1, droite 2, bas 3
  snakeSize = 3;
  directChanged = false;
  eating = false;
  initPlateau();
}

void spawnFood()  //OK
{
  pos_food_x = random(0, 32);
  pos_food_y = random(0, 32);
  if (plateau[pos_food_y][pos_food_x] > 0)
    spawnFood();
}

void foodEaten()  //OK
{
  if (pos_x_head == pos_food_x && pos_y_head == pos_food_y) {
    if (dtime > 50)
      dtime -= 5;

    plateau[pos_food_y][pos_food_x] = snakeSize;
    snakeSize++;
    spawnFood();
    plateau[pos_food_y][pos_food_x] = -1;
    eating = true;
  }
}


void initPlateau()  //OK
{
  for (int ligne = 0; ligne < T_LIGNE; ligne++) {
    for (int colonne = 0; colonne < T_COLONNE; colonne++) {
      plateau[ligne][colonne] = 0;
    }
  }
  plateau[pos_y_head][pos_x_head] = snakeSize;
  spawnFood();
  plateau[pos_food_y][pos_food_x] = -1;
}

void affichPlateau() 
{
  display.clearDisplay();
  for (int ligne = 0; ligne < T_LIGNE; ligne++) {
    for (int colonne = 0; colonne < T_COLONNE; colonne++) {
      if (plateau[ligne][colonne] > 0) {
        if (plateau[ligne][colonne] % 2 == 0)
          display.drawPixel(colonne, ligne, DARKVIOLET);
        else
          display.drawPixel(colonne, ligne, YELLOW);
      }

      else if (plateau[ligne][colonne] == -1)
        display.drawPixel(colonne, ligne, GREEN);
    }
  }
  display.showBuffer();
}

void nextTurn() 
{
  for (int ligne = 0; ligne < T_LIGNE; ligne++) {
    for (int colonne = 0; colonne < T_COLONNE; colonne++) {
      if (plateau[ligne][colonne] > 0)
        plateau[ligne][colonne]--;
    }
  }
}


void changeSnakePlace() {
  switch (direction) {
    case 0:
      if (pos_x_head == 0)
        pos_x_head = 31;
      else

        pos_x_head--;
      break;
    case 1:
      if (pos_y_head == 0)
        pos_y_head = 31;
      else
        pos_y_head--;
      break;
    case 2:
      if (pos_x_head == 31)
        pos_x_head = 0;
      else
        pos_x_head++;
      break;
    case 3:
      if (pos_y_head == 31)
        pos_y_head = 0;
      else
        pos_y_head++;
      break;
    default:
      break;
  }
  plateau[pos_y_head][pos_x_head] += snakeSize;
}
void selectDirection() {
  int sx = analogRead(VRY);
  int sy = analogRead(VRX);

  if (sx < 1700 && sy > 900 && sy < 3150 && direction != 2) {
    directChanged = true;
    direction = 0;
  } else if (sx > 2000 && sy > 900 && sy < 3150 && direction != 0) {
    directChanged = true;
    direction = 2;
  } else if (sy < 1700 && sx > 900 && sx < 3150 && direction != 1) {
    directChanged = true;
    direction = 3;
  } else if (sy > 2000 && sx > 900 && sx < 3150 && direction != 3) {
    directChanged = true;
    direction = 1;
  }
}


void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(27));
  display.begin(16);
  display.setFastUpdate(true);
  display.clearDisplay();
  initPlateau();

#ifdef ESP32
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &display_updater, true);
  timerAlarmWrite(timer, 2000, true);
  timerAlarmEnable(timer);
#endif
}

void loop() {

  Serial.println(dtime);
  if (millis() % dtime < 1) 
  {
    Serial.println(direction);
    foodEaten();
    nextTurn();
    changeSnakePlace();
    if (checkGameOver())
      resetGame();
    affichPlateau();
    directChanged = false;
  } else 
  {
    if (directChanged == false)
      selectDirection();
  }
  delay(1);
}
