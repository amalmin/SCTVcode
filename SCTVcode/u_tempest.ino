int level_x[16][16] = {
  { -112, -103, -79, -42, 0, 42, 79, 103, 112, 103, 79, 42, 0, -42, -79, -103},
  { -112, -112, -112, -56, 0, 56, 112, 112, 112, 112, 112, 56, 0, -56, -112, -112},
  { -112, -112, -56, -56, 0, 56, 56, 112, 112, 112, 56, 56, 0, -56, -56, -112},
  { -108, -85, -49, -16, 16, 49, 85, 108, 108, 85, 49, 16, -16, -49, -85, -108},
  { -112, -64, -32, -20, 20, 32, 64, 112, 112, 64, 32, 20, -20, -32, -64, -112},
  { -89, -66, -44, -23, 0, 23, 46, 68, 89, 112, 75, 38, 0, -38, -74, -112},
  { -106, -96, -28, 0, 28, 96, 106, 48, 106, 96, 28, 0, -28, -96, -106, -48},
  {112, 98, 84, 70, 56, 42, 28, 16, -16, -30, -44, -58, -72, -86, -100, -112},
  {112, 98, 83, 68, 53, 38, 23, 8, -7, -22, -37, -52, -67, -82, -97, -112},
  {112, 112, 112, 112, 106, 87, 58, 23, -23, -58, -87, -106, -112, -112, -112, -112},
  {112, 92, 80, 74, 66, 55, 38, 11, -20, -36, -44, -58, -90, -98, -106, -112},
  {0, 16, 56, 96, 112, 96, 56, 16, 0, -16, -56, -96, -112, -96, -56, -16},
  { -90, -36, -7, 0, 7, 36, 90, 112, 112, 96, 56, 0, -56, -96, -112, -112},
  {112, 112, 80, 80, 48, 48, 16, 16, -16, -16, -48, -48, -80, -80, -112, -112},
  { -48, 0, 48, 57, 104, 80, 104, 57, 48, 0, -48, -57, -104, -84, -104, -57},
  {112, 98, 95, 88, 68, 43, 26, 13, -13, -26, -43, -68, -88, -95, -98, -112}
};

int level_y[16][16] = {
  {0, -42, -79, -103, -112, -103, -79, -42, 0, 42, 79, 103, 112, 103, 79, 42},
  {0, -56, -112, -112, -112, -112, -112, -56, 0, 56, 112, 112, 112, 112, 112, 56},
  {0, -56, -56, -112, -112, -112, -56, -56, 0, 56, 56, 112, 112, 112, 56, 56},
  { -20, -48, -56, -39, -39, -56, -48, -20, 20, 48, 56, 39, 39, 56, 48, 20},
  { -22, -35, -69, -112, -112, -69, -35, -22, 22, 35, 69, 112, 112, 69, 35, 22},
  {67, 22, -23, -68, -112, -68, -23, 22, 67, 112, 112, 112, 112, 112, 112, 112},
  { -32, -96, -106, -48, -106, -96, -32, 0, 32, 96, 106, 48, 106, 96, 32, 0},
  { -112, -80, -48, -16, 16, 48, 80, 112, 112, 80, 48, 16, -16, -48, -80, -112},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { -111, -74, -37, 1, 37, 72, 97, 111, 111, 97, 72, 37, 1, -37, -74, -111},
  { -78, -52, -24, 8, 40, 67, 94, 78, 82, 57, 25, -3, 0, -30, -62, -94},
  {1, 42, 57, 42, 1, -40, -57, -40, 1, 42, 57, 42, 1, -40, -57, -40},
  { -104, -108, -59, -4, -59, -108, -104, -54, 2, 53, 92, 108, 92, 53, 2, -54},
  { -64, -32, -32, 0, 0, 32, 32, 64, 64, 32, 32, 0, 0, -32, -32, -64},
  { -105, -83, -105, -60, -49, -3, 43, 54, 105, 77, 105, 54, 43, -3, -49, -60},
  { -41, -21, 4, 27, 41, 41, 29, 7, 7, 29, 41, 41, 27, 4, -21, -41}
};

int level_angle[16][16] = {
    {0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, 0x01, 0x02, 0x03, 0x04},
    {0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04},
    {0x04, 0x08, 0x04, 0x08, 0x08, 0x0c, 0x08, 0x0c, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x04, 0x00, 0x04},
    {0x06, 0x07, 0x09, 0x08, 0x07, 0x09, 0x0a, 0x0c, 0x0e, 0x0f, 0x01, 0x00, 0x0f, 0x01, 0x02, 0x04},
    {0x07, 0x06, 0x05, 0x08, 0x0b, 0x0a, 0x09, 0x0c, 0x0f, 0x0e, 0x0d, 0x00, 0x03, 0x02, 0x01, 0x04},
    {0x05, 0x05, 0x05, 0x05, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05},
    {0x04, 0x08, 0x0b, 0x05, 0x08, 0x0c, 0x0e, 0x09, 0x0c, 0x00, 0x03, 0x0d, 0x00, 0x04, 0x07, 0x02},
    {0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x0c, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x00, 0x01, 0x01, 0x02, 0x03, 0x04, 0x04, 0x04, 0x00},
    {0x0e, 0x0d, 0x0c, 0x0d, 0x0d, 0x0d, 0x01, 0x0f, 0x02, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x00},
    {0x0b, 0x09, 0x07, 0x05, 0x03, 0x01, 0x0f, 0x0d, 0x0d, 0x0f, 0x01, 0x03, 0x05, 0x07, 0x09, 0x0b},
    {0x08, 0x0b, 0x0c, 0x04, 0x05, 0x08, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x01, 0x02, 0x03, 0x04, 0x05},
    {0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00},
    {0x0a, 0x06, 0x0c, 0x08, 0x0e, 0x0a, 0x00, 0x0c, 0x02, 0x0e, 0x04, 0x00, 0x06, 0x02, 0x08, 0x04},
    {0x0e, 0x0c, 0x0d, 0x0e, 0x00, 0x02, 0x02, 0x00, 0x0e, 0x0e, 0x00, 0x02, 0x03, 0x04, 0x02, 0x00}
};

byte lev_scale[16] = {
  0x18, 0x1c, 0x18, 0x0f, 0x18, 0x18, 0x18, 0x18, 0x0a, 0x18, 0x10, 0x0f, 0x18, 0x0c, 0x14, 0x0a
};

byte lev_y3d[16] = {
  0x50, 0x50, 0x50, 0x68, 0x50, 0x50, 0x68, 0xb0, 0xa0, 0x50, 0x90, 0x80, 0x20, 0xb0, 0x60, 0xa0
};

byte lev_y2d_h[16] = {
  0x40, 0x20, 0x40, 0x80, 0x40, 0x40, 0x70, 0x60, 0x00, 0x20, 0x40, 0x00, 0xa0, 0x40, 0x40, 0x00
};

byte lev_y2d_l[16] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0x00, 0x00, 0xfe, 0x01, 0xff, 0x01
};

byte lev_open[16] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1 };

int tempest_level = 0;

face * registerTempest() {
  face* f = (face*) malloc(sizeof(face));

  f->text = 0;
  f->title = 0;
  f->init = 0;
  f->uninit = 0;
  f->draw = doTempest;
  f->uses_knobs = 0;

  return f;
}

void doTempest() {
  int scale = 10;
  int y_offset_scale = 2;
//  int y_camera_offset = lev_y3d[tempest_level];
  
  static int count = 1;

  //  int y3d = lev_y3d[tempest_level];
  short y2d = lev_y2d_l[tempest_level] << 8;
  y2d = y2d | lev_y2d_h[tempest_level];

//  Serial.printf("y2d: %d\n", y2d);
//  Serial.println("");

  for (int i = 1; i < 16; i++) {
    int x1 = level_x[tempest_level][i - 1];
    int y1 = -level_y[tempest_level][i - 1];

    int x2 = level_x[tempest_level][i];
    int y2 = -level_y[tempest_level][i];

    /*
        Serial.printf("scale: %-3d level: %-2d x1a: %-5d y1a: %-5d x1: %-5d y1: %-5d\n",
                      lev_scale[level],
                      tempest_level,
                      lev_x[tempest_level][i - 1],
                      lev_y[tempest_level][i - 1],
                      x1, y1);
    */

    drawALine(x1, y1 + y2d * y_offset_scale, x2, y2 + y2d * y_offset_scale);

    drawALine(x1 * scale, y1 * scale, x2 * scale, y2 * scale);

    drawALine(x1, y1 + y2d * y_offset_scale, x1 * scale, y1 * scale);

//void drawRadialLine(int inside, int outside, int resolution, int angle) {
//    drawRadialLine(0, 1000, 16, level_angle[tempest_level][i-1]);
//    Serial.printf("%3d ", level_angle[tempest_level][i-1]);
  }

  if (!lev_open[tempest_level]) {
    drawALine(level_x[tempest_level][0], -level_y[tempest_level][0] + y2d * y_offset_scale, level_x[tempest_level][15], -level_y[tempest_level][15] + y2d * y_offset_scale);
    drawALine(level_x[tempest_level][0] * scale, -level_y[tempest_level][0] * scale, level_x[tempest_level][15] * scale, -level_y[tempest_level][15] * scale);
  }

  drawALine(level_x[tempest_level][15], -level_y[tempest_level][15] + y2d * y_offset_scale, level_x[tempest_level][15] * scale, -level_y[tempest_level][15] * scale);

  if(count++%100 == 0) {
    tempest_level = (tempest_level+1) % 16;
  }
}
