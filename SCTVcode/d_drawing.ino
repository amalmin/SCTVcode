// Set brightness between 0 and 100% with an exponential stretch - this works the best
// Values above 100 result in each stroke being drawn multiple times.  101 = 2 repeats, 102 = three, 103 = four, etc.
// Repeating strokes rapidly increase rendering time.
void setBrightness(int b) {
  if(b > 100) {
    Brightness = 4096;
    Strokes = b - 100;
  } else {
    Brightness = 4096 * BMap[b];
    Strokes = 1;
  }
//  Serial.printf("P: %d %d\n", b, Brightness);
}

// Standalone shape drawing for non-drawlist features

void drawALine(int xstart, int ystart, int xend, int yend) {
  Scale = 1;
  ChrXPos = 0;
  ChrYPos = 0;
  XStart = xstart;
  YStart = ystart;
  XEnd = xend;
  YEnd = yend;
  Shape = lin;
  DoSeg();
}

// FirstO   Start angle 0..7 is 0 deg .. 315 deg 0 = E, 90 = N, 180 = W, 270 = S
// LastO    End angle 1..14 is 45 deg .. 630 deg

void drawACircle(int xcenter, int ycenter, int diameter) {
  drawACircle(xcenter, ycenter, diameter, 6, 13);
}

// FirstO   Start angle 0..7 is 0 deg .. 315 deg 0 = E, 90 = N, 180 = W, 270 = S
// LastO    End angle 1..14 is 45 deg .. 630 deg
void drawACircle(int xcenter, int ycenter, int diameter, int fo, int lo) {
  Scale = 1;
  ChrXPos = 0;
  ChrYPos = 0;
  XCenter = xcenter;
  YCenter = ycenter;
  XSize = diameter;
  YSize = diameter;
  Shape = cir;
  FirstO = fo;
  LastO = lo;
  DoSeg();
}

// Draw a line from the center of the screen outwards.
// inside - how far out front the center to start the line
// outside - how far out from the center to end the line
// resolution - how many degrees should the screen have?  240 makes sense for clocks, 360 is common, and 1440 is nice and smooth...
// angle - what angle should the line be drawn at?  0 = up.
void drawRadialLine(int inside, int outside, int resolution, int angle) {
  int handAngle = (angle*nsteps/resolution) % nsteps;  // get angle in range of new sin/cos tab
  int ys = (float)costab[handAngle];      // swap X and Y, because 0 deg is at north CW like a clock, not east CCW like math
  int xs = (float)sintab[handAngle];

  XStart = (inside * xs / 500) >>8;
  YStart = (inside * ys / 500) >>8;
  XEnd   = (outside * xs / 500) >>8;
  YEnd   = (outside * ys / 500) >>8;
  Scale = 1;
  ChrXPos = ChrYPos = 0;
  Shape = lin;
  DoSeg();
}

// Draw a circle somewhere on the screen along an imaginary line from the center of the screen (does that make sense?)
// inside - how far out front the center of the screen to draw the center of the circle
// resolution - how many degrees should the screen have?  240 makes sense for clocks, 360 is common, and 1440 is nice and smooth...
// angle - what angle should the circle be drawn at? 0 = up.
// diameter - how big of a circle?
void drawRadialCircle(int inside, int resolution, int angle, int diameter) {
  int handAngle = (angle*nsteps/resolution) % nsteps;  // get angle in range of new sin/cos tab
  int ys = costab[handAngle];      // swap X and Y, because 0 deg is at north CW like a clock, not east CCW like math
  int xs = sintab[handAngle];

  drawACircle((inside * xs / 500) >>8, (inside * ys / 500) >>8, diameter);
//  if(diameter==30)
//    Serial.printf("i: %d r: %d a: %d d: %d -> handangle: %d sin: %d cos: %d xs: %f ys: %f -> %f (%d) %f (%d)\n", 
//                  inside, resolution, angle, diameter, handAngle, sintab[handAngle], costab[handAngle], xs, ys, (inside * xs), int(inside * xs)>>8, (inside * ys), int(inside * ys)>>8);
}

// ------------------- Draw list display code ------------------------------

// SetScale sets the character size parameters from Scale
// There are two char spacings - tight for big, looser for small scale
void SetScale() 
{
  ChrHt = Scale * OurChrHt;
  if (Scale < 40) 
  {
    Kern = Scale * OurLilKern;
    RowGap = Scale * OurLilGap;
  }
  else
  {
    Kern = Scale * OurBigKern;
    RowGap = Scale * OurBigGap;
  }
}

// DoSeg displays one segment.
// It returns after drawing the segment.
// Entered with the display blanked.
// Exits with the display blanked.

// Uses some math to draw each dot exactly once, with the number of dots calculated 
// to produce a good even display brightness. The dots are close enough together that they 
// are smeared together into a line or arc. 
// 
// Scaling:
// The DACs are 12 bits, giving a field of 4096 square. We use 2500 for the active field, 
// centered at (0,0). 
// with the rest being extra room for the x and y position controls to work.  
//
void DoSeg() 
{
  int len, xmotion, ymotion, motion, xstart, ystart;
 // if (doingHand) Serial.printf("shape %d  ", Shape);
  if (Shape == cir) {
    // draw a circle
    int xcen = XCenter * Scale + ChrXPos + XSaver + xPos + midDAC;  // X center position
    int ycen = YCenter * Scale + ChrYPos + YSaver + yPos + midDAC;  // Y center position
    int xrad = (XSize * Scale) / 2;         // X size: radius is diameter/2 
    int yrad = (YSize * Scale) / 2;         // Y size
    int firstAngle = FirstO     * (nsteps >> 3);
    int lastAngle = (LastO + 1) * (nsteps >> 3);
    int bigness = (xrad > yrad ? xrad : yrad );
    int stride = (circleSpeed<<8) / bigness;   // stride is scaled by 256 to allow finer resolution of step size
    xstart = ((costab[firstAngle] * xrad)>>16) + xcen;
    ystart = ((sintab[firstAngle] * yrad)>>16) + ycen;
    xmotion = abs(thisX - xstart);
    ymotion = abs(thisY - ystart);
    motion = (xmotion > ymotion ? xmotion : ymotion);   // how far to move from previous segment

    for(int b = Strokes; b > 0; b--) {
      // go to the start point with beam off
      analogWriteDAC0(xstart);
      analogWriteDAC1(ystart);
  
      // wait for the beam to reach the start point
      delayMicroseconds(motion/motionDelay + settlingDelay);
      analogWrite(BlankPin, Brightness);
      delayMicroseconds(glowDelay);        // wait for glow to start
  
      // draw the circle with the beam on, stride is 24.8 bits to allow fine rate control
      if(FastDraw) {
        for (i=(firstAngle<<8); i<(lastAngle<<8); i+=stride) {
          thisX = ((costab[(i>>8) % nsteps] * xrad) >> 16) + xcen;
          thisY = ((sintab[(i>>8) % nsteps] * yrad) >> 16) + ycen;
          analogWriteDAC0(thisX);
          analogWriteDAC1(thisY);
        }
      } else {
        for (i=(firstAngle<<8); i<(lastAngle<<8); i+=stride) {
          thisX = ((costab[(i>>8) % nsteps] * xrad) >> 16) + xcen;
          thisY = ((sintab[(i>>8) % nsteps] * yrad) >> 16) + ycen;
          analogWrite(XDACPin, thisX);
          analogWrite(YDACPin, thisY);
        }
      }

      //delayMicroseconds(glowDelay);        // wait for glow to start
      analogWrite(BlankPin, 0);              // Turn off the beam.
//  analogWrite(BlankPin, 4096);           // Leave the beam on to observe the 'rapids' movements between lit segments.
    }
  } 
  else if (Shape == lin) {
    // draw a line 
    xstart = XStart * Scale + ChrXPos + XSaver + xPos + midDAC;  // X start position
    ystart = YStart * Scale + ChrYPos + YSaver + yPos + midDAC;  // Y start position
    int xlen = ((XEnd - XStart) * Scale);         // X size
    int ylen = ((YEnd - YStart) * Scale);         // Y size

    if (xlen == 0)
      len = abs(ylen);   //save ourselves a square root and two muls when not needed
    else if (ylen == 0)
      len = abs(xlen);
    else
      len = (int)sqrt(xlen * xlen + ylen * ylen);

    if (len <= 0) len = lineStride;
    int xinc = ((xlen<<8)/len);
    int yinc = ((ylen<<8)/len);
    xmotion = abs(thisX - xstart);
    ymotion = abs(thisY - ystart);
    motion = (xmotion > ymotion ? xmotion : ymotion);   // how far to move from previous segment
 //   if (doingHand) Serial.printf("motion %4d   len %4d\n", motion, len);

    for(int b = Strokes; b > 0; b--) {
      analogWriteDAC0(xstart);
      analogWriteDAC1(ystart);
    
    delayMicroseconds(motion/motionDelay + settlingDelay);
    analogWrite(BlankPin, Brightness);
    delayMicroseconds(glowDelay);        // wait for glow to start
    
 //   if (doingHand) Serial.printf("len %4d   stride %4d\n", len, lineStride);
    if(FastDraw) {
      for (i=0; i<(len); i += lineStride) {
        thisX = ((i*xinc)>>(8)) + xstart;
        thisY = ((i*yinc)>>(8)) + ystart;
          analogWriteDAC0(thisX);
          analogWriteDAC1(thisY);
      }
    } else {
      for (i=0; i<(len); i += lineStride) {
        thisX = ((i*xinc)>>(8)) + xstart;
        thisY = ((i*yinc)>>(8)) + ystart;
        analogWrite(XDACPin, thisX);
        analogWrite(YDACPin, thisY);
      }
    }

  //delayMicroseconds(glowDelay);        // wait for glow to start
  analogWrite(BlankPin, 0);              // Turn off the beam.
//  analogWrite(BlankPin, 4096);           // Leave the beam on to observe the 'rapids' movements between lit segments.
    }
  }
}

// -------------------- Draw list centering code ---------------------

// GetWid calculates the pixel width of the text string pointed to by StrPtr
// for centering purposes. It scans the character segments for
// the last int which contains the width, adds them and their kerns.
// The result is returned in StrWid.
//
// If the line is terminated with an NL, it sets NewL in MenuFlg and
// subtracts one kern from the total width.
void GetWid() 
{
  ChrCnt = 0;
  StrWid = 0;
  // look up width of each printable char, sum into StrWid, leave StrPtr at \n or null
  while ((TheChr = *StrPtr++) >= 0x20)
  {
    TheSeg = Fonts[Font][(TheChr % 0x7f)- 32]; // read font table - tricky
    while (*TheSeg < 0x80) // skip over all real segments, stopping at end flag
      TheSeg += 7;
    StrWid += *TheSeg % 128;   // mask off end flag to reveal width
    ChrCnt++;
  }
  // calculate string width depending on newline
  StrWid *= Scale;   // big chars use more space
  if (TheChr == '\n')
  {
    NewL = true;
    StrWid += Kern * (ChrCnt - 1);  // newline - use n-1 kern spaces
  }
  else
  {
    NewL = false;
    StrWid += Kern * ChrCnt;        // no newline, retain kern after last char
  }
}
 
// Center centers a draw list, calculating X and Y string positions and storing them 
// in the copy of the drawlist.

// This is tricky, as a line of text is composed of multiple strings. Only the 
// last string in each line has a newline char. 

// We need the total line width for all strings in a line so that we may
// calculate the start X position for each string. So we need this info
// on the first string, but it's only available after the last string.
// So we need to store it in LinWid and do another scan on each line in X pass.

//  The first X pass does the following:

// For each string, call GetWid and store StrWid in XPos.
// Store term char (0 or NL) in YPos. Store line width in LinWids array.

// The Y scan of the strings calculates XPos from LinWid and StrWid,
// for each string in the line. The YPos flag helps know when to NL.

// CentXLp sets the X positions and calculates the total height.
// CentYLp sets the Y positions using the height.

// It returns without doing anything if there is a string that has a non-zero position. 
// This is true in a drawlist such as pong or face clock. 

// center a draw list, filling in xpos and ypos fields for each element
void Center(struct item *list) 
{
  int LinWid = 0;     // scaled width of line in pixels
  int LinWids[10];    // array of line widths per line
  int *wp;       // points to array above
  item *p = list;

  NewL = true;    // flag if a newline seen yet on this line

  DispHt = 0;
  wp = LinWids;   // array of widths of every line
  // CXLoop scans all lines of text, calcs height and widths
  while (p->type != listend) 
  {
    if (p->xpos != 0)
    {
      return;  // there is a string that has a position, so don't do any centering of this list
    }
    Scale = p->scale;
    StrPtr = p->string;   // read string pointer
    SetScale();           // set Kern, Scale
    GetWid();
    p->xpos = StrWid;  // save string width in x pos space
    p->ypos = TheChr;  // save termination char in Y pos space
    LinWid += StrWid;
    if (NewL) {    // process another row because newline spotted
      *wp++ = LinWid;
      DispHt += (RowGap + ChrHt);   // accumulate height of row for Y centering
      LinWid = 0;
    }
    p++;    // look at next list element
  }
  // calculate the Y start point from total size and row heights
  ChrYPos = ((DispHt - RowGap)/2);
  
  // this last loop fills in xpos and ypos in each string, based on entire drawlist
  NewL = true;
  wp = LinWids;
  p = list;
  while (p->type != listend) 
  {
    Scale = p->scale;
    StrPtr = p->string;   // read string pointer
    StrWid = p->xpos;  // fetch string width we stashed in x pos space
    TheChr = p->ypos;  // fetch termination char we stashed in Y pos space
    if (NewL) {    // process another row because newline spotted
      ChrXPos = 0-*wp++/2;   // left end = middle - length/2
      SetScale();
      ChrYPos -= ChrHt;
    }
    NewL = false;
    if (TheChr == '\n') 
      NewL = true;
    p->xpos = ChrXPos;   // write the real position into list
    ChrXPos += StrWid;
    p->ypos = ChrYPos;
    if (NewL)
      ChrYPos -= RowGap;   // remove one inter-row gap since n-1 gaps in n lines
    p++;    // look at next list element
  }
}

// copy a draw list to TheList, since TheList is modified by Center(). 
void copyList(struct item *list) 
{
  item *p = list;
  item *q = TheList; 
  p = list;
  while (p->type != listend) 
  {
    q->type   = p->type;
    q->scale  = p->scale;
    q->func   = p->func;
    q->font   = p->font;
    q->brightness   = p->brightness;
    q->shadow   = p->shadow;
    q->shadow_spacing   = p->shadow_spacing;
    q->string = p->string; 
    q->xpos   = p->xpos;  
    q->ypos   = p->ypos; 
    p++;    // look at next list element
    q++; 
  }
  q->type   = p->type;  // copy the last listend to terminate the list
}

// Get the segment into RAM from TheSeg pointer
int GetSeg() {
  int theChar;
  // read a segment's descriptor from char font array
  theChar   = *TheSeg++;
  if (theChar < 128) {                // if < 128 it's shape, else it's char width
    Shape   = theChar;
    XCenter = XStart = *TheSeg++;
    YCenter = YStart = *TheSeg++;
    XSize   = XEnd = *TheSeg++;
    YSize   = YEnd = *TheSeg++;
    FirstO  = *TheSeg++;              // these are not used for lines, only for arcs
    LastO   = *TheSeg++;
    return 1;  // not end of character
  }
  else {
    ChrWid = (theChar % 128) * Scale;  // bit 7 is end flag - mask it off
    return 0;  // end of character
  }
}

// DispStr displays the zero-terminated text string pointed to by StrPtr
void DispStr() 
{
  int notLast;

  TheChr = (*StrPtr++);
  while ((TheChr >= 32)) // printable
  {
    // look up character in ROM font table. This is tricky. 
    TheSeg = Fonts[Font][(TheChr & 0x7f) - 32];
    notLast = GetSeg();
    while (notLast) 
    {
      DoSeg();           // display segments until last one found
      notLast = GetSeg();
    }
    ChrXPos = ChrXPos + ChrWid + Kern;   // move over by width of char
    TheChr = (*StrPtr++);
  }
    DoEnc();          // polled mode I/O, so we need to do it many times
}


// Display a draw list once
void DoAList(struct item *list) 
{
  item *p = list;
  int TheItem = 0;         // menu item currently being processed
  char *DupPtr;        // duplicate StrPtr for bright work
  int DupXPos;        // copy for highlighted strings
  int DupYPos;        // copy for highlighted strings

  InField = false;
  while (p->type != listend) 
  {
    Scale = p->scale;
    Font = p->font;

    if(p->brightness)
      setBrightness(p->brightness);

    StrPtr = p->string;   // read string pointer
    ChrXPos = p->xpos;  // read position of string (not used by most!)
    ChrYPos = p->ypos;

    // seg tells it to draw a circle or a line. This code does a circle. Need to do a line also. 
    if (p->type == seg) {
      XCenter = YCenter = 0;  // position done by ChrX,YPos
      XSize = StrPtr[0];   // read out segment parameters from 'string' array
      YSize = StrPtr[1];
      XStart = -XSize/2;
      YStart = -YSize/2;
      XEnd = XSize/2;
      YEnd = YSize/2;
      Shape = StrPtr[2];
      FirstO = StrPtr[3];
      LastO = StrPtr[4];
      DoSeg();
    }
    else
    {
      if (p->type != text) 
      { // it's a menu item, so save its code pointer and count up items
        TheItem++;
      }

      DupPtr = StrPtr;   // save pointer and position for displaying twice to highlight
      DupXPos = ChrXPos;
      DupYPos = ChrYPos;
      SetScale();

      DispStr();

      if(p->shadow) {
        for(int n=1; n < p->shadow + 1; n++) {
          StrPtr = DupPtr;
          ChrXPos = DupXPos + p->shadow_spacing*n;
          ChrYPos = DupYPos - p->shadow_spacing*n;

          DispStr();
        }
      }

      if ((p->type != text) && (TheItem == HotItem)) 
      {  // hot, either highlight or blink item
        MenuCod = p->func;
        if (p->type == field) 
        {
          InField = true;
          if (!InParam || Blink) 
          {  // if it's a parameter, blink it
            StrPtr = DupPtr;
            ChrXPos = DupXPos;
            DispStr();
          }
        }  // not field 1
        else // highlighted, so draw it twice more to make it stand out
        {
          InParam = false;   // hot item that's not a field: highlighted, not blinking
          StrPtr = DupPtr;
          ChrXPos = DupXPos;
          DispStr();
          InParam = false;   // hot item that's not a field: highlighted, not blinking
          StrPtr = DupPtr;
          ChrXPos = DupXPos;
          DispStr();
        }
      }
    }
    p++;
  }
  NItems = TheItem;   // will this work to set number of items? 
}

// Once an hour, advance the screensaver to the next position
// in the list. This subtly moves the display but spreads out
// any phosphor burn over a 4 by 8 pixel area.
//

// Screensaver moves the display impercetibly in a triangle raster scan 
// every hour, to spread out the screen burn.
const int nSavers = 31;
int lastHour = 0;

void updateScreenSaver() {
  if (Hrs != lastHour) {  // on the hour
    ScrX++;
    if (ScrX >= nSavers) ScrX = 0;
    XSaver = 4*abs(ScrX - nSavers/2);
    YSaver = 15*abs(ScrX%8 - (nSavers%8)/2);
  }
  lastHour = Hrs;
}

// --------------------
// A couple functions used to try to make the brightness scale more linear.

float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float fscale( float originalMin, float originalMax, float newBegin, float newEnd, float inputValue, float curve){
  float OriginalRange = 0;
  float NewRange = 0;
  float zeroRefCurVal = 0;
  float normalizedCurVal = 0;
  float rangedValue = 0;
  boolean invFlag = 0;


  // condition curve parameter
  // limit range

  if (curve > 10) curve = 10;
  if (curve < -10) curve = -10;

  curve = (curve * -.1) ; // - invert and scale - this seems more intuitive - postive numbers give more weight to high end on output
  curve = pow(10, curve); // convert linear scale into lograthimic exponent for other pow function

  // Check for out of range inputValues
  if (inputValue < originalMin) {
    inputValue = originalMin;
  }
  if (inputValue > originalMax) {
    inputValue = originalMax;
  }

  // Zero Refference the values
  OriginalRange = originalMax - originalMin;

  if (newEnd > newBegin){
    NewRange = newEnd - newBegin;
  }
  else
  {
    NewRange = newBegin - newEnd;
    invFlag = 1;
  }

  zeroRefCurVal = inputValue - originalMin;
  normalizedCurVal  =  zeroRefCurVal / OriginalRange;   // normalize to 0 - 1 float

  // Check for originalMin > originalMax  - the math for all other cases i.e. negative numbers seems to work out fine
  if (originalMin > originalMax ) {
    return 0;
  }

  if (invFlag == 0){
    rangedValue =  (pow(normalizedCurVal, curve) * NewRange) + newBegin;

  }
  else     // invert the ranges
  {  
    rangedValue =  newBegin - (pow(normalizedCurVal, curve) * NewRange);
  }

  return rangedValue;
}
