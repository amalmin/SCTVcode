
face * registerCalibrateCircle() {
  face* f = (face*) malloc(sizeof(face));

  f->text = 0;
  f->title = 0;
  f->init = 0;
  f->uninit = 0;
  f->draw = doCalibrateCircle;
  f->uses_knobs = 0;

  return f;
}

void doCalibrateCircle() {
  for (int i = 100; i < 3000; i += 200) {
    drawACircle(0, 0, i);
  }
}
face * registerCalibrateSquare() {
  face* f = (face*) malloc(sizeof(face));

  f->text = 0;
  f->title = 0;
  f->init = 0;
  f->uninit = 0;
  f->draw = doCalibrateSquare;
  f->uses_knobs = 0;

  return f;
}

void doCalibrateSquare() {
// xs ys xe ye 
  drawALine(-1250, 1250, 1250, 1250);
  drawALine(-1250, 0, 1250, 0);
  drawALine(-1250, -1250, 1250, -1250);

  drawALine(-1250, -1250, -1250, 1250);
  drawALine(0, -1250, 0, 1250);
  drawALine(1250, -1250, 1250, 1250);

  drawALine(-1250, -1250, 1250, 1250);
  drawALine(1250, -1250, -1250, 1250);
}

char numbers[] = "0123456789\n";
char letters[] = "aAbBcCdDeEfFgGhHiI\n";
char LETTERS[] = "ABCDEFGHIJFG\n";

char chars1[] = 
"!\"`$%&'()*+,-./\n";
char chars2[] = 
"0123456789:;<=>?@\n";
char chars3[] = 
"ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
char chars4[] = 
"abcdefghijklmnopqrstuvwxyz\n";
char chars5[] =
"[\\]^_`{|}~\n";


struct item calibrateFontList[] = {
  {text,10,0,0,0,0,0,chars1,  0,0},
  {text,10,0,0,0,0,0,chars2,  0,0},
  {text,10,0,0,0,0,0,chars3,  0,0},
  {text,10,0,0,0,0,0,chars4,  0,0},
  {text,10,0,0,0,0,0,chars5,  0,0},
  {listend,0,0,0,0,0,0,BlankLn,0,0}
};

face * registerCalibrateFont() {
  face* f = (face*) malloc(sizeof(face));

  f->text = calibrateFontList;
  f->title = 0;
  f->init = 0;
  f->uninit = 0;
  f->draw = doCalibrateFont;
  f->uses_knobs = 0;

  return f;
}

void doCalibrateFont() {
  static int f = 0;
  static int count = 1;

  if(count++%100 == 0) {
    f = (f+1) % 5;

    calibrateFontList[0].font = f;
    calibrateFontList[1].font = f;
    calibrateFontList[2].font = f;
    calibrateFontList[3].font = f;
    calibrateFontList[4].font = f;
  }
}


struct item calibrateBrightnessList[] = {
  {text,3,0,0,0,0,0,(char *)"10%",  -1100, 300},
  {text,3,0,0,0,0,0,(char *)"20%",  -900 , 300},
  {text,3,0,0,0,0,0,(char *)"30%",  -700 , 300},
  {text,3,0,0,0,0,0,(char *)"40%",  -500 , 300},
  {text,3,0,0,0,0,0,(char *)"50%",  -300 , 300},
  {text,3,0,0,0,0,0,(char *)"60%",  -100 , 300},
  {text,3,0,0,0,0,0,(char *)"70%",  100  , 300},
  {text,3,0,0,0,0,0,(char *)"80%",  300  , 300},
  {text,3,0,0,0,0,0,(char *)"90%",  500  , 300},
  {text,3,0,0,0,0,0,(char *)"100%",  700 , 300},

  {text,3,0,0,0,0,0,(char *)"101 %",  900 , -25},
  {text,3,0,0,0,0,0,(char *)"102 %",  900 ,-225},
  {text,3,0,0,0,0,0,(char *)"103 %",  900 ,-425},
  {text,3,0,0,0,0,0,(char *)"104 %",  900 ,-625},
  {listend,0,0,0,0,0,0,BlankLn,0,0}
};


face * registerCalibrateBrightness() {
  face* f = (face*) malloc(sizeof(face));

  f->text = calibrateBrightnessList;
  f->title = 0;
  f->init = 0;
  f->uninit = 0;
  f->draw = doCalibrateBrightness;
  f->uses_knobs = 0;

  return f;
}

void doCalibrateBrightness() {
  int x = -1000;
  int y = 200;
  int b = 10;

  for(int i=0; i< 10; i++) {
    setBrightness(b);
    b+=10;
    drawACircle(x, y, 100);
    drawACircle(x, y, 80);
    drawACircle(x, y, 60);
    drawACircle(x, y, 40);
    drawACircle(x, y, 20);
    x+=200;
  }

  x-=200;
  y-=200;

  for(int i=101; i<= 104; i++) {
    setBrightness(i);

    drawACircle(x, y, 100);
    drawACircle(x, y, 80);
    drawACircle(x, y, 60);
    drawACircle(x, y, 40);
    drawACircle(x, y, 20);
    y-=200;
  }

  setBrightness(BRIGHTNESS_DEFAULT);
  
}
