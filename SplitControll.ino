#include <FastLED.h>
#define NUM_LEDS 516
#define COLOR_ORDER RGB
#define DATA_PIN 18
#define CLOCK_PIN 19

#define button1  27
#define button2  26
#define button3  25
#define button4  33


CRGB leds[NUM_LEDS];

unsigned long Starttimer1 ;
unsigned long Endtimer1 ;
unsigned long Present1 ;

unsigned long Starttimer2 ;
unsigned long Endtimer2 ;
unsigned long Present2 ;

int col1 = 85;
int col2 = 30;
int col3 = 0;
int col4 = 10;

int state = 1;
int mc = 0;
int me = 0;


void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  attachInterrupt(button1, but1, RISING);
  pinMode(button2, INPUT_PULLUP);
  attachInterrupt(button2, but2, RISING);
  pinMode(button3, INPUT_PULLUP);
  attachInterrupt(button3, but3, RISING);
  pinMode(button4, INPUT_PULLUP);
  attachInterrupt(button4, but4, RISING);
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RBG>(leds, NUM_LEDS);
}

void wich_map() {
  if ((mc == 1) && (me == 1) ) {
    all_black();
    zero();
    state = 0;
    maping1();
  }
  if ((mc == 2) && (me == 2) ) {
    all_black();
    zero();
    state = 0;
    maping2();
  }
  if ((mc == 3) && (me == 3) ) {
    all_black();
    zero();
    state = 0;
    maping3();
  }
  if ((mc == 4) && (me == 4) ) {
    all_black();
    zero();
    state = 5;
    maping4();
  }
}

void timer1() {
  Present1 = millis();
  Starttimer1 = millis();
  Endtimer1 = Starttimer1 + 1000;
  while (Endtimer1 > Present1) {
    Present1 = millis();
    wich_map();
  }
}

void timer2() {
  Present2 = millis();
  Starttimer2 = millis();
  Endtimer2 = Starttimer2 + 10000;
  while (Endtimer2 > Present2) {
    if (state == 5)
    {
      blink_3_5();
      state = 1;
    }
    Present2 = millis();
    wich_map();
  }
}

void but1() {
  mc = 1;
  me = 1;
}

void but2() {
  mc = 2;
  me = 2;
}

void but3() {
  mc = 3;
  me = 3;
}

void but4() {
  mc = 4;
  me = 4;
}


void zero() {
  mc = 0;
  me = 0;
}


void all_black()
{
  for (int i = 0; i < 517; i++)
  {
    leds[i] = CHSV( col1, 255, 0);
  }
  FastLED.show();
}

void all_white()
{
  for (int i = 0; i < 517; i++)
  {
    leds[i] = CHSV( col1, 0, 50);
  }
  FastLED.show();
}


void c_line(int a, int b, int j , int col) {
  int i = j;
  if (i > a - 1 && i < b + 1 )
  {
    leds[i ] = CHSV( col, 255, 150);
  }
  if (i == b)
  {
    FastLED.show();
  }

}

//line 1
void c_line_1(int a, int b, int j , int col) {
  int i = 15 + j;
  if (i > a - 1 && i < b + 1 )
  {
    leds[i ] = CHSV( col, 255, 150);
  }
  if (i == b)
  {
    FastLED.show();
  }

}

void line_1(int a, int b, int j , int col) {
  int i = 15 + j;
  if (i > a - 1 && i < b + 1)
  {
    leds[i] = CHSV( col, 255, 150);
    //if (i > a + 2) {
    //  leds[i - 3] = CHSV( col, 255, 100);
    //}
    FastLED.show();
  }
  //if (i == b )
  //{
  // for (int f = i - 4;  f < i + 1;  f++)
  // {
  //   leds[f] = CHSV( col, 255, 100);
  // }
  // FastLED.show();
  //}
}

//line2
void c_line_2_blink(int a, int b, int j , int col, int br) {
  int   i = 254 - j;
  if (i < a + 1 && i > b - 1)
  {
    leds[i ] = CHSV( col, 255, br);
  }
  if (i == b)
  {
    FastLED.show();
  }
}


void c_line_2(int a, int b, int j , int col) {
  int   i = 254 - j;
  if (i < a + 1 && i > b - 1)
  {
    leds[i ] = CHSV( col, 255, 150);
  }
  if (i == b)
  {
    FastLED.show();
  }
}

void line_2(int a, int b, int j , int col) {
  int i = 254 - j;
  if (i < a + 1 && i > b - 1)
  {
    leds[i] = CHSV( col, 255, 150);
    /* if (i < a - 2) {
       leds[i + 3] = CHSV( col, 255, 100);
      }*/
    FastLED.show();
  }
  /* if (i == b )
    {
     for (int f = i + 4; f > i - 1 ; f--)
     {
       leds[f] = CHSV( col, 255, 100);
     }
     FastLED.show();
    }*/
}

//line3

void c_line_3(int a, int b, int j , int col) {
  int i = 255 + j;
  if (i > a - 1 && i < b + 1 )
  {
    leds[i ] = CHSV( col, 255, 150);
  }
  if (i == b)
  {
    FastLED.show();
  }

}

void line_3(int a, int b, int j , int col) {
  int i = 255 + j;
  if (i > a - 1 && i < b + 1)
  {
    leds[i] = CHSV( col, 255, 150);
    /*  if (i > a + 2) {
        leds[i - 3] = CHSV( col, 255, 100);
      }*/
    FastLED.show();
  }
  /* if (i == b )
    {
     for (int f = i - 4; f < i + 1; f++)
     {
       leds[f] = CHSV( col, 255, 100);
     }
     FastLED.show();
    }*/

}

//line4

void c_line_4(int a, int b, int j , int col) {
  int i = 516 - j;
  if (i < a + 1 && i > b - 1)
  {
    leds[i ] = CHSV( col, 255, 150);
  }
  if (i == b)
  {
    FastLED.show();
  }

}



void line_4(int a, int b, int j , int col ) {
  int i = 516 - j;
  if (i < a + 1 && i > b - 1)
  {
    leds[i] = CHSV( col, 255, 150);
    /*if (i < a - 2) {
      leds[i + 3] = CHSV( col, 255, 100);
      }*/
    FastLED.show();
  }
  /* if (i == b )
    {
     for (int f = i + 4; f > i - 1 ; f--)
     {
       leds[f] = CHSV( col, 255, 100);
     }
     FastLED.show();
    }*/
}

void maping1() {

  for (int i = 0; i < 15; i++) {
    c_line(0 , 14 , i, col1);
  }

  //first part///////////
  for (int i = 0; i < 30; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    line_1(15 , 38 , i , col1);
    c_line_1(39, 49 , i, col1);

    //line 2///////////
    line_2(254 , 238 , i, col1);
    c_line_2(237, 227 , i, col1);
    line_2(226 , 221 , i, col1);

    //line 3///////////
    line_3(255 , 262 , i, col1);
    line_3(274 , 280 , i, col1);
    c_line_3(281 , 291 , i, col1);

    //line 4///////////
    line_4(516 , 500 , i, col1);
    c_line_4(499 , 489 , i, col1);
    line_4(488 , 474 , i, col1);
    wich_map();
  }

  //second part///////////
  for (int i = 30; i < 60; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    c_line_1(39, 49 , i, col1);
    line_1(50 , 55 , i, col1);
    line_1(67 , 107 , i, col1);

    //line 2///////////
    line_2(226 , 221 , i, col1);
    line_2(209 , 203 , i, col1);
    c_line_2(202, 192 , i, col1);

    //line 3///////////
    c_line_3(281 , 291 , i, col1);
    line_3(292 , 297 , i, col1);
    line_3(309 , 319 , i, col1);

    //line 4///////////
    line_4(488 , 474 , i, col1);
    line_4(462 , 431 , i, col1);
    wich_map();
  }

  //third part///////////
  for (int i = 60; i < 90; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1
    line_1(67 , 107 , i, col1);

    //line 2///////////
    c_line_2(202, 192 , i, col1);
    line_2(191, 185 , i, col1);
    line_2(173, 166 , i, col1);
    c_line_2(165, 155 , i, col1);

    //line 3///////////
    line_3(309 , 319 , i , col1);
    c_line_3(320 , 330 , i, col1);
    line_3(331 , 342 , i, col1);
    c_line_3(343 , 353 , i, col1);

    //line 4///////////
    line_4(462 , 431 , i, col1);
    c_line_4(430 , 420 , i, col1);
    wich_map();
  }

  //forth part///////////
  for (int i = 90; i < 120; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    line_1(67 , 107 , i, col1);
    c_line_1(108, 122 , i, col1);

    //line 2///////////
    c_line_2(165, 155 , i, col1);
    line_2(154, 138 , i, col1);
    c_line_2(137, 123 , i, col1);

    //line 3///////////
    c_line_3(343 , 353 , i, col1);
    line_3(354 , 360 , i, col1);
    line_3(372 , 380 , i, col1);

    //line 4///////////
    c_line_4(430 , 420 , i, col1);
    line_4(419 , 411 , i, col1);
    c_line_4(410 , 396 , i, col1);
    wich_map();
  }

  //fith part///////////
  for (int i = 120; i < 141; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    // line 2 ///////////
    c_line_2(137, 123 , i, col1);

    //line 3///////////
    line_3(372 , 380 , i, col1);
    c_line_3(381 , 395 , i, col1);

    //line 4///////////
    c_line_4(410 , 396 , i, col1);
    wich_map();
  }
  me = 9;
  timer2();
  all_white();
}

void maping2() {

  for (int i = 0; i < 15; i++) {
    c_line(0 , 14 , i, col2);
  }

  //first part///////////
  for (int i = 0; i < 30; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    line_1(15 , 38 , i, col2);

    //line 2///////////
    line_2(254 , 238 , i, col2);
    line_2(226 , 221 , i, col2);

    //line 3///////////
    line_3(255 , 262 , i, col2);
    line_3(274 , 280 , i, col2);

    //line 4///////////
    line_4(516 , 500 , i, col2);
    line_4(488 , 474 , i, col2);
    wich_map();
  }

  //second part///////////
  for (int i = 30; i < 60; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    line_1(50 , 55 , i, col2);
    c_line_1(56, 66 , i, col2);
    line_1(67 , 107 , i, col2);

    //line 2///////////
    line_2(226 , 221 , i, col2);
    c_line_2(220, 210 , i, col2);
    line_2(209 , 203 , i, col2);

    //line 3///////////
    line_3(292 , 297 , i, col2);
    c_line_3(298 , 308 , i, col2);
    line_3(309 , 319 , i, col2);

    //line 4///////////
    line_4(488 , 474 , i, col2);
    c_line_4(473 , 463 , i, col2);
    line_4(462 , 431 , i, col2);
    wich_map();
  }

  //third part///////////
  for (int i = 60; i < 90; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1
    line_1(67 , 107 , i, col2);

    //line 2///////////
    line_2(191, 185 , i, col2);
    line_2(173, 166 , i, col2);

    //line 3///////////
    line_3(309 , 319 , i, col2);
    line_3(331 , 342 , i, col2);

    //line 4///////////
    line_4(462 , 431 , i, col2);
    wich_map();
  }

  //forth part///////////
  for (int i = 90; i < 120; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    line_1(67 , 107 , i, col2);
    c_line_1(108, 122 , i, col2);

    //line 2///////////
    line_2(154, 138 , i, col2);
    c_line_2(137, 123 , i, col2);

    //line 3///////////
    line_3(354 , 360 , i, col2);
    line_3(372 , 380 , i, col2);

    //line 4///////////
    line_4(419 , 411 , i, col2);
    c_line_4(410 , 396 , i, col2);
    wich_map();
  }

  //fith part///////////
  for (int i = 120; i < 141; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    // line 2 ///////////
    c_line_2(137, 123 , i, col2);

    //line 3///////////
    line_3(372 , 380 , i, col2);
    c_line_3(381 , 395 , i, col2);

    //line 4///////////
    c_line_4(410 , 396 , i, col2);
    wich_map();
  }
  me = 9;
  timer2();
  all_white();
}

void maping3() {

  for (int i = 0; i < 15; i++) {
    c_line(0 , 14 , i, col3);
  }

  //first part///////////
  for (int i = 0; i < 30; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    line_1(15 , 38 , i, col3);
    c_line_1(39, 49 , i, col3);

    //line 2///////////
    line_2(254 , 238 , i, col3);
    c_line_2(237, 227 , i, col3);
    line_2(226 , 221 , i, col3);

    //line 3///////////
    line_3(255 , 262 , i, col3);
    line_3(274 , 280 , i, col3);
    c_line_3(281 , 291 , i, col3);

    //line 4///////////
    line_4(516 , 500 , i, col3);
    line_4(488 , 474 , i, col3);
    wich_map();
  }
  //second part///////////
  for (int i = 30; i < 60; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    c_line_1(39, 49 , i, col3);
    line_1(50 , 55 , i, col3);
    line_1(67 , 107 , i, col3);

    //line 2///////////
    line_2(226 , 221 , i, col3);
    line_2(209 , 203 , i, col3);
    c_line_2(202, 192 , i, col3);

    //line 3///////////
    c_line_3(281 , 291 , i, col3);
    line_3(292 , 297 , i, col3);
    line_3(309 , 319 , i, col3);

    //line 4///////////
    line_4(488 , 474 , i, col3);
    line_4(462 , 431 , i, col3);
    wich_map();
  }
  //third part///////////
  for (int i = 60; i < 90; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1
    line_1(67 , 107 , i, col3);

    //line 2///////////
    c_line_2(202, 192 , i, col3);
    line_2(191, 185 , i, col3);
    line_2(173, 166 , i, col3);
    c_line_2(165, 155 , i, col3);

    //line 3///////////
    line_3(309 , 319 , i, col3);
    c_line_3(320 , 330 , i, col3);
    line_3(331 , 342 , i, col3);
    c_line_3(343 , 353 , i, col3);

    //line 4///////////
    line_4(462 , 431 , i, col3);
    wich_map();
  }
  //forth part///////////
  for (int i = 90; i < 120; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    line_1(67 , 107 , i, col3);
    c_line_1(108, 122 , i, col3);

    //line 2///////////
    c_line_2(165, 155 , i, col3);
    line_2(154, 138 , i, col3);
    c_line_2(137, 123 , i, col3);

    //line 3///////////
    c_line_3(343 , 353 , i, col3);
    line_3(354 , 360 , i, col3);
    line_3(372 , 380 , i, col3);

    //line 4///////////
    line_4(419 , 411 , i, col3);
    c_line_4(410 , 396 , i, col3);
    wich_map();
  }

  //fith part///////////
  for (int i = 120; i < 141; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    // line 2 ///////////
    c_line_2(137, 123 , i, col3);

    //line 3///////////
    line_3(372 , 380 , i, col3);
    c_line_3(381 , 395 , i, col3);

    //line 4///////////
    c_line_4(410 , 396 , i, col3);
    wich_map();
  }
  me = 9;
  timer2();
  all_white();
}

void maping4() {

  for (int i = 0; i < 15; i++) {
    c_line(0 , 14 , i, col4);
  }

  //first part///////////
  for (int i = 0; i < 30; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    line_1(15 , 38 , i, col4);
    c_line_1(39, 49 , i, col4);

    //line 2///////////
    line_2(254 , 238 , i, col4);
    line_2(226 , 221 , i, col4);

    //line 3///////////
    line_3(255 , 262 , i, col4);
    c_line_3(263 , 273 , i, col4);
    line_3(274 , 280 , i, col4);

    //line 4///////////
    line_4(516 , 500 , i, col4);
    c_line_4(499 , 489 , i, col4);
    line_4(488 , 474 , i, col4);
    wich_map();
  }
  //second part///////////
  for (int i = 30; i < 60; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    c_line_1(39, 49 , i, col4);
    line_1(50 , 55 , i, col4);
    line_1(67 , 107 , i, col4);

    //line 2///////////
    line_2(226 , 221 , i, col4);
    line_2(209 , 203 , i, col4);
    c_line_2(202, 192 , i, col4);

    //line 3///////////
    line_3(292 , 297 , i, col4);
    line_3(309 , 319 , i, col4);

    //line 4///////////
    line_4(488 , 474 , i, col4);
    line_4(462 , 431 , i, col4);
    wich_map();
  }
  //third part///////////
  for (int i = 60; i < 90; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1
    line_1(67 , 107 , i, col4);

    //line 2///////////
    c_line_2(202, 192 , i, col4);
    line_2(191, 185 , i, col4);
    c_line_2(184, 174 , i, col4);
    line_2(173, 166 , i, col4);
    c_line_2(165, 155 , i, col4);

    //line 3///////////
    line_3(309 , 319 , i, col4);
    line_3(331 , 342 , i, col4);

    //line 4///////////
    line_4(462 , 431 , i, col4);
    c_line_4(430 , 420 , i, col4);
    wich_map();
  }
  //forth part///////////
  for (int i = 90; i < 120; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    //line 1///////////
    line_1(67 , 107 , i, col4);
    c_line_1(108, 122 , i, col4);

    //line 2///////////
    c_line_2(165, 155 , i, col4);
    line_2(154, 138 , i, col4);
    c_line_2(137, 123 , i, col4);

    //line 3///////////
    line_3(354 , 360 , i, col4);
    c_line_3(361 , 371 , i, col4);
    line_3(372 , 380 , i, col4);

    //line 4///////////
    c_line_4(430 , 420 , i, col4);
    line_4(419 , 411 , i, col4);
    c_line_4(410 , 396 , i, col4);
    wich_map();
  }

  //fith part///////////
  for (int i = 120; i < 141; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    // line 2 ///////////
    c_line_2(137, 123 , i, col4);

    //line 3///////////
    line_3(372 , 380 , i, col4);
    c_line_3(381 , 395 , i, col4);

    //line 4///////////
    c_line_4(410 , 396 , i, col4);
    wich_map();
  }
  timer2();
  me = 9;
  all_white();
}

void blink_3_5() {
  for (int i = 50; i < 65; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    c_line_2_blink(202 , 192 , i, col4, 0);
  }
  timer1();

  for (int i = 50; i < 65; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    c_line_2_blink(202 , 192 , i, col4, 150);
  }
  for (int i = 65; i < 84; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    c_line_2_blink(184 , 174 , i, col4, 0);
  }

  timer1();

  for (int i = 65; i < 84; i++) {
    if (me != mc) {
      break;
    }
    c_line_2_blink(184 , 174 , i, col4, 150);
  }
  for (int i = 50; i < 65; i++) {
    c_line_2_blink(202 , 192 , i, col4, 0);
  }

  timer1();
  for (int i = 50; i < 65; i++) {
    if (me != mc) {
      all_white();
      break;
    }
    c_line_2_blink(202 , 192 , i, col4, 150);
  }
  for (int i = 65; i < 84; i++) {
    if (me != mc) {
      break;
    }
    c_line_2_blink(184 , 174 , i, col4, 0);
  }

  timer1();

  for (int i = 65; i < 84; i++) {
    if (me != mc) {
      break;
    }
    c_line_2_blink(184 , 174 , i, col4, 150);
  }
  for (int i = 50; i < 65; i++) {
    if (me != mc) {
      break;
    }
    c_line_2_blink(202 , 192 , i, col4, 0);
  }
  timer1();
  for (int i = 50; i < 65; i++) {
    if (me != mc) {
      break;
    }
    c_line_2_blink(202 , 192 , i, col4, 150);
  }
}

void loop() {
  if (state == 1) {
    all_white();
    state = 0;
  }
  wich_map();
}
