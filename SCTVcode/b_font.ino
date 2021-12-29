// -------------------- 12x20 proportional font ------------------

// Table is in ASCII character order. 
// An index table Font points to entries in this list
// to allow variable segment count.

// The lower left corner is the origin (0,0).
// The center of the typical character is at (6,10).
// The upper right corner of the typical character is (12,20).
// Descending lower case characters exist.

// Each segment uses seven signed int parameters:

// cir      Draw a circle, ellipse or arc
// XCenter  X Offset from LL corner to center of circle
// YCenter  Y Offset from LL corner to center of circle
// XSize    Width of circle in diameter units
// YSize    Height of circle in diameter units
// FirstO   Start angle 0..7 is 0 deg .. 315 deg 0 = E, 90 = N, 180 = W, 270 = S
// LastO    End angle 1..14 is 45 deg .. 630 deg
// The character ends with a 0x80 which tells DoChar to stop, plus the char width.

// lin      Draw a straight line
// XStart   X start of line
// YStart   Y start of line
// XEnd     X end of line
// YEnd     Y end of line
// FirstO   ignored
// LastO    ignored
// The character ends with a 0x80 which tells DoChar to stop, plus the char width.

const int OurBigKern = 2;  // this font's kern size for 40-up scales
const int OurLilKern = 3;  // this font's kern size for 30-down scales
const int OurBigGap = 4;   // this font's inter-row gap for 40-up scales
const int OurLilGap = 10;  // this font's inter-row gap for 30-down scales
const int OurChrHt = 20;   // this font's character height

// circle:              cir,XC,YC,XS,YS,FO,LO{,width|0x80}
// line:                lin,XS,YS,XE,YE,FO,LO{,width|0x80}
const int Space[]   = {0x86};      // space does nothing but move over
const int Exclam[]  = { lin, 1, 6, 1,20, 6,13, 
                        cir, 1, 1, 2, 2, 6,13, 0x82};
const int DQuot[]   = { lin, 0,12, 0,20, 6,13, 
                        lin, 6,12, 6,20, 6,13, 0x86};
const int Sharp[]   = { lin, 2, 4, 4,20, 6,13, 
                        lin, 7, 4, 9,20, 6,13, 
                        lin, 0, 9,10, 9, 6,13, 
                        lin, 1,15,11,15, 6,13, 0x8c};
const int Dollar[]  = { cir, 5, 6,10, 8, 4, 9,
                        cir, 5,14,10, 8, 0, 5, 
                        lin, 5, 2, 5,22, 6,13, 0x8a};
const int Percent[] = { cir, 3,17, 6, 6, 6,13, 
                        cir, 9, 3, 6, 6, 6,13, 
                        lin, 3, 0,15,20, 6,13, 0x8c};
const int Amper[]   = { cir, 4,15, 8,10, 6,12,
                        cir, 4, 5, 8,10, 2, 5, 
                        cir, 4, 8,16,16, 6, 7, 
                        lin, 1,12,11, 0, 6,13, 0x8c};
const int Apost[]   = { cir, 3,19, 2, 2, 6,13, 
                        cir, 0,19, 8,12, 6, 7, 0x84};
const int LParen[]  = { cir, 4,10, 8,20, 2, 5, 0x84};
const int RParen[]  = { cir, 0,10, 8,20, 6, 9, 0x84};
const int Aster[]   = { lin, 0,10,12,10, 6,13, 
                        lin, 2, 4,10,16, 6,13, 
                        lin, 2,16,10, 4, 6,13, 0x8c};
const int Plus[]    = { lin, 0,10,12,10, 6,13, 
                        lin, 6, 4, 6,16, 6,13, 0x8c};
const int Comma[]   = { cir, 3, 1, 2, 2, 6,13, 
                        cir, 0, 1, 8,12, 6, 7, 0x84};
const int Minus[]   = { lin, 0,10,12,10, 6,13, 0x8c};
const int Period[]  = { cir, 1, 1, 2, 2, 6,13, 0x82};
const int Slash[]   = { lin, 0, 0,12,20, 6,13, 0x8c};
const int Zero[]    = { cir, 6,10,12,20, 6,13, 0x8c};
const int One[]     = { lin, 7, 0, 7,20, 6,13, 
                        lin, 3,16, 7,20, 6,13, 0x8c};
const int Two[]     = { cir, 6,14,12,12, 6,11,
                        cir, 6, 0,12,16, 2, 3, 
                        lin, 0, 0,12, 0, 6,13, 0x8c};
const int Three[]   = { cir, 6, 6,12,12, 5, 9,
                        lin, 1,20,11,20, 6,13, 
                        lin, 6,12,11,20, 6,13, 0x8c};
const int Four[]    = { lin, 8, 0, 8,20, 6,13, 
                        lin, 0, 6,12, 6, 6,13, 
                        lin, 0, 6, 8,20, 6,13, 0x8c};
const int Five[]    = { cir, 6, 6,12,12, 5,10,
                        lin, 2,10, 4,20, 6,13, 
                        lin, 4,20,12,20, 6,13, 0x8c};
const int Six[]     = { cir, 6, 6,12,12, 6,13, 
                        lin, 2,10, 8,20, 6,13, 0x8c};
const int Seven[]   = { lin, 0, 0,12,20, 6,13, 
                        lin, 0,20,12,20, 6,13, 0x8c};
const int Eight[]   = { cir, 6, 6,12,12, 6,13, 
                        cir, 6,16, 8, 8, 6,13, 0x8c};
const int Nine[]    = { cir, 6,14,12,12, 6,13, 
                        lin, 4, 0,10,10, 6,13, 0x8c};
const int Colon[]   = { cir, 2, 6, 4, 4, 6,13, 
                        cir, 2,14, 4, 4, 6,13, 0x84};
const int SemiCol[] = { cir, 3,14, 2, 2, 6,13, 
                        cir, 3, 6, 2, 2, 6,13, 
                        cir, 0, 6, 8,12, 6, 7, 0x84};
const int LThan[]   = { lin, 0,10,12,18, 6,13, 
                        lin, 0,10,12, 2, 6,13, 0x8c};
const int Equal[]   = { lin, 0,13,12,13, 6,13, 
                        lin, 0, 7,12, 7, 6,13, 0x8c};
const int GThan[]   = { lin, 0,18,12,10, 6,13, 
                        lin, 0, 2,12,10, 6,13, 0x8c};
const int Quest[]   = { cir, 5,14,10,10, 6,11,
                        cir, 5, 7, 4, 4, 2, 7,
                        cir, 5, 1, 2, 2, 6,13, 0x8a};
const int AtSign[]  = { cir, 3,10, 6,10, 6,13, 
                        cir, 3,10,14,20, 0, 6,
                        cir, 8,10, 4, 4, 4, 7, 0x8c};
const int BigA[]    = { lin, 0, 0, 6,20, 6,13, 
                        lin, 6,20,12, 0, 6,13, 
                        lin, 3, 8, 9, 8, 6,13, 0x8c};
const int BigB[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0, 0, 8, 0, 6,13, 
                        lin, 0,10, 8,10, 6,13, 
                        lin, 0,20, 8,20, 6,13, 
                        cir, 8, 5,10,10, 6, 9, 
                        cir, 8,15,10,10, 6, 9, 0x8c};
const int BigC[]    = { cir, 7,10,14,20, 1, 6, 0x8c};
const int BigD[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0, 0, 4, 0, 6,13, 
                        lin, 0,20, 4,20, 6,13, 
                        cir, 4,10,16,20, 6, 9, 0x8c};
const int BigE[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0, 0,12, 0, 6,13, 
                        lin, 0,10, 8,10, 6,13, 
                        lin, 0,20,12,20, 6,13, 0x8c};
const int BigF[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0,10, 8,10, 6,13, 
                        lin, 0,20,12,20, 6,13, 0x8c};
const int BigG[]    = { cir, 7,10,14,20, 1, 6,
                        lin,11, 2,11, 8, 6,13, 
                        lin, 7, 8,11, 8, 6,13, 0x8c};
const int BigH[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin,12, 0,12,20, 6,13, 
                        lin, 0,10,12,10, 6,13, 0x8c};
const int BigI[]    = { lin, 2, 0, 2,20, 6,13, 
                        lin, 1, 0, 5, 0, 6,13, 
                        lin, 1,20, 5,20, 6,13, 0x84};
const int BigJ[]    = { lin,12, 6,12,20, 6,13, 
                        cir, 6, 6,12,12, 4, 7, 0x8c};
const int BigK[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0,10,12, 0, 6,13, 
                        lin, 0,10,12,20, 6,13, 0x8c};
const int BigL[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0, 0,12, 0, 6,13, 0x8c};
const int BigM[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin,12, 0,12,20, 6,13, 
                        lin, 0,20, 6,10, 6,13, 
                        lin, 6,10,12,20, 6,13, 0x8c};
const int BigN[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin,12, 0,12,20, 6,13, 
                        lin, 0,20,12, 0, 6,13, 0x8c};
const int BigO[]    = { cir, 6,10,12,20, 6,13, 0x8c};
const int BigP[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0,10, 8,10, 6,13, 
                        lin, 0,20, 8,20, 6,13, 
                        cir, 8,15,10,10, 6, 9, 0x8c};
const int BigQ[]    = { cir, 6,10,12,20, 6,13, 
                        lin, 8, 6,12, 0, 6,13, 0x8c};
const int BigR[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0,10, 8,10, 6,13, 
                        lin, 0,20, 8,20, 6,13, 
                        cir, 8,15,10,10, 6, 9, 
                        lin, 6,10,12, 0, 6,13, 0x8c};
const int BigS[]    = { cir, 6, 5,12,10, 4, 9,
                        cir, 6,15,12,10, 0, 5, 0x8c};
const int BigT[]    = { lin, 6, 0, 6,20, 6,13, 
                        lin, 0,20,12,20, 6,13, 0x8c};
const int BigU[]    = { lin, 0, 6, 0,20, 6,13, 
                        lin,12, 6,12,20, 6,13, 
                        cir, 6, 6,12,12, 4, 7, 0x8c};
const int BigV[]    = { lin, 0,20, 6, 0, 6,13, 
                        lin, 6, 0,12,20, 6,13, 0x8c};
const int BigW[]    = { lin, 0, 0, 0,20, 6,13, 
                        lin,12, 0,12,20, 6,13, 
                        lin, 0, 0, 6,10, 6,13, 
                        lin, 6,10,12, 0, 6,13, 0x8c};
const int BigX[]    = { lin, 0,20,12, 0, 6,13, 
                        lin, 0, 0,12,20, 6,13, 0x8c};
const int BigY[]    = { lin, 6, 0, 6,10, 6,13, 
                        lin, 0,20, 6,10, 6,13, 
                        lin, 6,10,12,20, 6,13, 0x8c};
const int BigZ[]    = { lin, 0, 0,12,20, 6,13, 
                        lin, 0, 0,12, 0, 6,13, 
                        lin, 0,20,12,20, 6,13, 0x8c};
const int LftSqBr[] = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0, 0, 4, 0, 6,13, 
                        lin, 0,20, 4,20, 6,13, 0x84};
const int BackSl[]  = { lin, 0,20,12, 0, 6,13, 0x8c};
const int RtSqBr[]  = { lin, 4, 0, 4,20, 6,13, 
                        lin, 0, 0, 4, 0, 6,13, 
                        lin, 0,20, 4,20, 6,13, 0x84};
const int Carat[]   = { lin, 0,10, 6,16, 6,13, 
                        lin, 6,16,12,10, 6,13, 0x8c};
const int UnderSc[] = { lin, 0, 0,12, 0, 6,13, 0x8c};
const int BackQu[]  = { lin, 0,20, 4,12, 6,13, 0x84};
const int SmallA[]  = { cir, 5, 6,10,12, 6,13, 
                        lin,10, 0,10,12, 6,13, 0x8a};
const int SmallB[]  = { cir, 5, 6,10,12, 6,13, 
                        lin, 0, 0, 0,20, 6,13, 0x8a};
const int SmallC[]  = { cir, 5, 6,10,12, 1, 6, 0x88};
const int SmallD[]  = { cir, 5, 6,10,12, 6,13, 
                        lin,10, 0,10,20, 6,13, 0x8a};
const int SmallE[]  = { cir, 5, 6,10,12, 0, 6,
                        lin, 0, 6,10, 6, 6,13, 0x8a};
const int SmallF[]  = { cir, 7,16, 6, 8, 0, 3, 
                        lin, 0,10, 8,10, 6,13, 
                        lin, 4, 0, 4,16, 6,13, 0x8a};
const int SmallG[]  = { cir, 5, 6,10,12, 6,13, 
                        lin,10, 0,10,12, 6,13, 
                        cir, 5, 0,10,12, 5, 7, 0x8a};
const int SmallH[]  = { cir, 4, 8, 8, 8, 0, 3, 
                        lin, 0, 0, 0,20, 6,13, 
                        lin, 8, 0, 8, 8, 6,13, 0x88};
const int SmallI[]  = { cir, 1,16, 2, 2, 6,13, 
                        lin, 1, 0, 1,12, 6,13, 0x82};
const int SmallJ[]  = { cir, 6,16, 2, 2, 6,13, 
                        lin, 6, 0, 6,12, 6,13, 
                        cir, 3, 0, 6, 8, 5, 7, 0x88};
const int SmallK[]  = { lin, 0, 0, 0,20, 6,13, 
                        lin, 0, 4, 8,12, 6,13, 
                        lin, 1, 6, 7, 0, 6,13, 0x88};
const int SmallL[]  = { lin, 1, 0, 1,20, 6,13, 0x82};
const int SmallM[]  = { lin, 0, 0, 0,12, 6,13, 
                        cir, 4, 8, 8, 8, 0, 3, 
                        lin, 8, 0, 8, 8, 6,13, 
                        cir,12, 8, 8, 8, 0, 3, 
                        lin,16, 0,16, 8, 6,13, 0x90};
const int SmallN[]  = { lin, 0, 0, 0,12, 6,13, 
                        cir, 4, 8, 8, 8, 0, 3, 
                        lin, 8, 0, 8, 8, 6,13, 0x88};
const int SmallO[]  = { cir, 5, 6,10,12, 6,13, 0x8a};
const int SmallP[]  = { cir, 5, 6,10,12, 6,13, 
                        lin, 0,-4, 0,12, 6,13, 0x8a};
const int SmallQ[]  = { cir, 5, 6,10,12, 6,13, 
                        lin,10,-4,10,12, 6,13, 0x8a};
const int SmallR[]  = { lin, 0, 0, 0,12, 6,13, 
                        cir, 5, 6,10,12, 1, 3, 0x88};
const int SmallS[]  = { cir, 4, 9, 8, 6, 0, 5, 
                        cir, 4, 3, 8, 6, 4, 9, 0x88};
const int SmallT[]  = { // cir, 8, 4, 8, 8, 4, 5, 
                        lin, 0,12, 8,12, 6,13, 
                        lin, 4, 0, 4,16, 6,13, 0x88};
const int SmallU[]  = { lin, 8, 0, 8,12, 6,13, 
                        cir, 4, 4, 8, 8, 4, 7, 
                        lin, 0, 4, 0,12, 6,13, 0x88};
const int SmallV[]  = { lin, 0,12, 4, 0, 6,13, 
                        lin, 4, 0, 8,12, 6,13, 0x88};
const int SmallW[]  = { lin, 0,12, 4, 0, 6,13, 
                        lin, 4, 0, 8,12, 6,13, 
                        lin, 8,12,12, 0, 6,13, 
                        lin,12, 0,16,12, 6,13, 0x90};
const int SmallX[]  = { lin, 0,12, 8, 0, 6,13, 
                        lin, 0, 0, 8,12, 6,13, 0x88};
const int SmallY[]  = { lin, 0,12, 4, 0, 6,13, 
                        lin, 4, 0, 8,12, 6,13, 
                        cir, 1, 0, 6, 8, 6, 7, 0x88};
const int SmallZ[]  = { lin, 0, 0, 8, 0, 6,13, 
                        lin, 0,12, 8,12, 6,13, 
                        lin, 0, 0, 8,12, 6,13, 0x88};
const int LfBrace[] = { cir, 8, 6, 8,12, 4, 5, 
                        cir, 0, 6, 8, 8, 0, 1, 
                        cir, 0,14, 8, 8, 6, 7, 
                        cir, 8,14, 8,12, 2, 3, 0x88};
const int VertBar[] = { lin, 1, 1, 1,21, 6,13, 0x82};
const int RtBrace[] = { cir, 0, 6, 8,12, 6, 7, 
                        cir, 8, 6, 8, 8, 2, 3, 
                        cir, 8,14, 8, 8, 4, 5, 
                        cir, 0,14, 8,12, 0, 1, 0x88};
const int Tilde[]   = { cir, 3,12, 6, 4, 0, 3, 
                        cir, 9,12, 6, 4, 4, 7, 0x8c};
const int Rubout[]  = { lin, 0,10, 6,20, 6,13, 
                        lin, 0, 0,12,20, 6,13, 
                        lin, 6, 0,12,10, 6,13, 0x8c};

// All the characters, arranged in ASCII order because ASCII rules
const int * const Font1[] =
{Space, Exclam,DQuot, Sharp,  Dollar, Percent,Amper, Apost,
 LParen,RParen,Aster, Plus,   Comma,  Minus,  Period,Slash,
 Zero,  One,   Two,   Three,  Four,   Five,   Six,   Seven,
 Eight, Nine,  Colon, SemiCol,LThan,  Equal,  GThan, Quest,
 AtSign,BigA,  BigB,  BigC,   BigD,   BigE,   BigF,  BigG,
 BigH,  BigI,  BigJ,  BigK,   BigL,   BigM,   BigN,  BigO,
 BigP,  BigQ,  BigR,  BigS,   BigT,   BigU,   BigV,  BigW,
 BigX,  BigY,  BigZ,  LftSqBr,BackSl, RtSqBr, Carat, UnderSc,
 BackQu,SmallA,SmallB,SmallC, SmallD, SmallE, SmallF,SmallG,
 SmallH,SmallI,SmallJ,SmallK, SmallL, SmallM, SmallN,SmallO,
 SmallP,SmallQ,SmallR,SmallS, SmallT, SmallU, SmallV,SmallW,
 SmallX,SmallY,SmallZ,LfBrace,VertBar,RtBrace,Tilde, Rubout};

// font from asteroids
const int asteroidsSpace[]   = {0x86};      // space does nothing but move over
const int asteroidsRubout[]  = { lin, 0,10, 6,20, 6,13, lin, 0, 0,12,20, 6,13, lin, 6, 0,12,10, 6,13, 0x8c};
const int asteroidsAmper[] = {lin,13,0,7,20,0,0,lin,7,20,13,13,0,0,lin,13,13,0,7,0,0,lin,0,7,7,0,0,0,lin,7,0,13,7,0,0,0x8f};
const int asteroidsApost[] = {lin,3,10,10,17,0,0,0x8f};
const int asteroidsAster[] = {lin,0,0,7,20,0,0,lin,7,20,13,0,0,0,lin,13,0,0,13,0,0,lin,0,13,13,13,0,0,lin,13,13,0,0,0,0,0x8f};
const int asteroidsAtSign[] = {lin,13,7,7,0,0,0,lin,7,0,0,7,0,0,lin,0,7,0,13,0,0,lin,0,13,7,20,0,0,lin,7,20,13,13,0,0,lin,13,13,7,7,0,0,lin,7,7,5,10,0,0,0x8f};
const int asteroidsBackQu[] = {lin,3,17,10,10,0,0,0x8f};
const int asteroidsBackSl[] = {lin,0,20,13,0,0,0,0x8f};
const int asteroidsBigA[] = {lin,0,0,0,13,0,0,lin,0,13,7,20,0,0,lin,7,20,13,13,0,0,lin,13,13,13,0,0,0,lin,0,7,13,7,0,0,0x8f};
const int asteroidsBigB[] = {lin,0,0,0,20,0,0,lin,0,20,7,20,0,0,lin,7,20,13,17,0,0,lin,13,17,7,10,0,0,lin,7,10,13,3,0,0,lin,13,3,7,0,0,0,lin,7,0,0,0,0,0,0x8f};
const int asteroidsBigC[] = {lin,13,0,0,0,0,0,lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,0x8f};
const int asteroidsBigD[] = {lin,0,0,0,20,0,0,lin,0,20,7,20,0,0,lin,7,20,13,13,0,0,lin,13,13,13,7,0,0,lin,13,7,7,0,0,0,lin,7,0,0,0,0,0,0x8f};
const int asteroidsBigE[] = {lin,13,0,0,0,0,0,lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,0,10,10,10,0,0,0x8f};
const int asteroidsBigF[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,0,10,10,10,0,0,0x8f};
const int asteroidsBigG[] = {lin,10,10,13,7,0,0,lin,13,7,13,0,0,0,lin,13,0,0,0,0,0,lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,0x8f};
const int asteroidsBigH[] = {lin,0,0,0,20,0,0,lin,0,10,13,10,0,0,lin,13,20,13,0,0,0,0x8f};
const int asteroidsBigI[] = {lin,0,0,13,0,0,0,lin,7,0,7,20,0,0,lin,0,20,13,20,0,0,0x8f};
const int asteroidsBigJ[] = {lin,0,7,7,0,0,0,lin,7,0,13,0,0,0,lin,13,0,13,20,0,0,0x8f};
const int asteroidsBigK[] = {lin,0,0,0,20,0,0,lin,13,20,0,10,0,0,lin,0,10,10,0,0,0,0x8f};
const int asteroidsBigL[] = {lin,13,0,0,0,0,0,lin,0,0,0,20,0,0,0x8f};
const int asteroidsBigM[] = {lin,0,0,0,20,0,0,lin,0,20,7,13,0,0,lin,7,13,13,20,0,0,lin,13,20,13,0,0,0,0x8f};
const int asteroidsBigN[] = {lin,0,0,0,20,0,0,lin,0,20,13,0,0,0,lin,13,0,13,20,0,0,0x8f};
const int asteroidsBigO[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,13,20,13,0,0,0,lin,13,0,0,0,0,0,0x8f};
const int asteroidsBigP[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,13,20,13,10,0,0,lin,13,10,0,8,0,0,0x8f};
const int asteroidsBigQ[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,13,20,13,7,0,0,lin,13,7,0,0,0,0,lin,7,7,13,0,0,0,0x8f};
const int asteroidsBigR[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,13,20,13,10,0,0,lin,13,10,0,8,0,0,lin,7,8,13,0,0,0,0x8f};
const int asteroidsBigS[] = {lin,0,3,3,0,0,0,lin,3,0,13,0,0,0,lin,13,0,13,8,0,0,lin,13,8,0,12,0,0,lin,0,12,0,20,0,0,lin,0,20,10,20,0,0,lin,10,20,13,17,0,0,0x8f};
const int asteroidsBigT[] = {lin,0,20,13,20,0,0,lin,7,20,7,0,0,0,0x8f};
const int asteroidsBigU[] = {lin,0,20,0,3,0,0,lin,0,3,7,0,0,0,lin,7,0,13,3,0,0,lin,13,3,13,20,0,0,0x8f};
const int asteroidsBigV[] = {lin,0,20,7,0,0,0,lin,7,0,13,20,0,0,0x8f};
const int asteroidsBigW[] = {lin,0,20,3,0,0,0,lin,3,0,7,7,0,0,lin,7,7,10,0,0,0,lin,10,0,13,20,0,0,0x8f};
const int asteroidsBigX[] = {lin,0,0,13,20,0,0,lin,0,20,13,0,0,0,0x8f};
const int asteroidsBigY[] = {lin,0,20,7,10,0,0,lin,7,10,13,20,0,0,lin,7,10,7,0,0,0,0x8f};
const int asteroidsBigZ[] = {lin,0,20,13,20,0,0,lin,13,20,0,0,0,0,lin,0,0,13,0,0,0,lin,3,10,10,10,0,0,0x8f};
const int asteroidsCarat[] = {lin,3,10,7,20,0,0,lin,7,20,10,10,0,0,0x8f};
const int asteroidsColon[] = {lin,7,15,7,12,0,0,lin,7,8,7,5,0,0,0x8f};
const int asteroidsComma[] = {lin,3,0,7,3,0,0,0x8f};
const int asteroidsDQuot[] = {lin,3,17,3,10,0,0,lin,10,17,10,10,0,0,0x8f};
const int asteroidsDollar[] = {lin,10,3,3,10,0,0,lin,3,10,10,17,0,0,lin,7,20,7,0,0,0,0x8f};
const int asteroidsEight[] = {lin,0,0,13,0,0,0,lin,13,0,13,20,0,0,lin,13,20,0,20,0,0,lin,0,20,0,0,0,0,lin,0,10,13,10,0,0,0x8f};
const int asteroidsEqual[] = {lin,2,7,12,7,0,0,lin,2,13,12,13,0,0,0x8f};
const int asteroidsExclam[] = {lin,7,0,5,3,0,0,lin,5,3,8,3,0,0,lin,8,3,7,0,0,0,lin,7,7,7,20,0,0,0x8f};
const int asteroidsFive[] = {lin,0,0,13,0,0,0,lin,13,0,13,10,0,0,lin,13,10,0,12,0,0,lin,0,12,0,20,0,0,lin,0,20,13,20,0,0,0x8f};
const int asteroidsFour[] = {lin,0,20,0,10,0,0,lin,0,10,13,10,0,0,lin,13,20,13,0,0,0,0x8f};
const int asteroidsGThan[] = {lin,3,0,10,10,0,0,lin,10,10,3,20,0,0,0x8f};
const int asteroidsLParen[] = {lin,10,0,3,7,0,0,lin,3,7,3,13,0,0,lin,3,13,10,20,0,0,0x8f};
const int asteroidsLThan[] = {lin,10,0,3,10,0,0,lin,3,10,10,20,0,0,0x8f};
const int asteroidsLfBrace[] = {lin,10,0,7,3,0,0,lin,7,3,7,17,0,0,lin,7,17,10,20,0,0,lin,3,10,7,10,0,0,0x8f};
const int asteroidsLftSqBr[] = {lin,10,0,3,0,0,0,lin,3,0,3,20,0,0,lin,3,20,10,20,0,0,0x8f};
const int asteroidsMinus[] = {lin,3,10,10,10,0,0,0x8f};
const int asteroidsNine[] = {lin,13,0,13,20,0,0,lin,13,20,0,20,0,0,lin,0,20,0,12,0,0,lin,0,12,13,8,0,0,0x8f};
const int asteroidsOne[] = {lin,7,0,7,20,0,0,lin,7,20,5,17,0,0,0x8f};
const int asteroidsPercent[] = {lin,0,0,13,20,0,0,lin,3,17,3,13,0,0,lin,10,7,10,3,0,0,0x8f};
const int asteroidsPeriod[] = {lin,5,0,7,0,0,0,0x8f};
const int asteroidsPlus[] = {lin,2,10,12,10,0,0,lin,7,15,7,5,0,0,0x8f};
const int asteroidsQuest[] = {lin,0,13,7,20,0,0,lin,7,20,13,13,0,0,lin,13,13,7,7,0,0,lin,7,2,7,0,0,0,0x8f};
const int asteroidsRParen[] = {lin,3,0,10,7,0,0,lin,10,7,10,13,0,0,lin,10,13,3,20,0,0,0x8f};
const int asteroidsRtBrace[] = {lin,7,0,10,3,0,0,lin,10,3,10,17,0,0,lin,10,17,7,20,0,0,lin,10,10,13,10,0,0,0x8f};
const int asteroidsRtSqBr[] = {lin,3,0,10,0,0,0,lin,10,0,10,20,0,0,lin,10,20,3,20,0,0,0x8f};
const int asteroidsSemiCol[] = {lin,7,15,7,12,0,0,lin,7,8,2,3,0,0,0x8f};
const int asteroidsSeven[] = {lin,0,20,13,20,0,0,lin,13,20,13,10,0,0,lin,13,10,7,0,0,0,0x8f};
const int asteroidsSharp[] = {lin,0,7,13,7,0,0,lin,13,7,10,3,0,0,lin,10,3,10,17,0,0,lin,10,17,13,13,0,0,lin,13,13,0,13,0,0,lin,0,13,3,17,0,0,lin,3,17,3,3,0,0,0x8f};
const int asteroidsSix[] = {lin,0,20,0,0,0,0,lin,0,0,13,0,0,0,lin,13,0,13,8,0,0,lin,13,8,0,12,0,0,0x8f};
const int asteroidsSlash[] = {lin,0,0,13,20,0,0,0x8f};
const int asteroidsSmallA[] = {lin,0,0,0,13,0,0,lin,0,13,7,20,0,0,lin,7,20,13,13,0,0,lin,13,13,13,0,0,0,lin,0,7,13,7,0,0,0x8f};
const int asteroidsSmallB[] = {lin,0,0,0,20,0,0,lin,0,20,7,20,0,0,lin,7,20,13,17,0,0,lin,13,17,7,10,0,0,lin,7,10,13,3,0,0,lin,13,3,7,0,0,0,lin,7,0,0,0,0,0,0x8f};
const int asteroidsSmallC[] = {lin,13,0,0,0,0,0,lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,0x8f};
const int asteroidsSmallD[] = {lin,0,0,0,20,0,0,lin,0,20,7,20,0,0,lin,7,20,13,13,0,0,lin,13,13,13,7,0,0,lin,13,7,7,0,0,0,lin,7,0,0,0,0,0,0x8f};
const int asteroidsSmallE[] = {lin,13,0,0,0,0,0,lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,0,10,10,10,0,0,0x8f};
const int asteroidsSmallF[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,0,10,10,10,0,0,0x8f};
const int asteroidsSmallG[] = {lin,10,10,13,7,0,0,lin,13,7,13,0,0,0,lin,13,0,0,0,0,0,lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,0x8f};
const int asteroidsSmallH[] = {lin,0,0,0,20,0,0,lin,0,10,13,10,0,0,lin,13,20,13,0,0,0,0x8f};
const int asteroidsSmallI[] = {lin,0,0,13,0,0,0,lin,7,0,7,20,0,0,lin,0,20,13,20,0,0,0x8f};
const int asteroidsSmallJ[] = {lin,0,7,7,0,0,0,lin,7,0,13,0,0,0,lin,13,0,13,20,0,0,0x8f};
const int asteroidsSmallK[] = {lin,0,0,0,20,0,0,lin,13,20,0,10,0,0,lin,0,10,10,0,0,0,0x8f};
const int asteroidsSmallL[] = {lin,13,0,0,0,0,0,lin,0,0,0,20,0,0,0x8f};
const int asteroidsSmallM[] = {lin,0,0,0,20,0,0,lin,0,20,7,13,0,0,lin,7,13,13,20,0,0,lin,13,20,13,0,0,0,0x8f};
const int asteroidsSmallN[] = {lin,0,0,0,20,0,0,lin,0,20,13,0,0,0,lin,13,0,13,20,0,0,0x8f};
const int asteroidsSmallO[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,13,20,13,0,0,0,lin,13,0,0,0,0,0,0x8f};
const int asteroidsSmallP[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,13,20,13,10,0,0,lin,13,10,0,8,0,0,0x8f};
const int asteroidsSmallQ[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,13,20,13,7,0,0,lin,13,7,0,0,0,0,lin,7,7,13,0,0,0,0x8f};
const int asteroidsSmallR[] = {lin,0,0,0,20,0,0,lin,0,20,13,20,0,0,lin,13,20,13,10,0,0,lin,13,10,0,8,0,0,lin,7,8,13,0,0,0,0x8f};
const int asteroidsSmallS[] = {lin,0,3,3,0,0,0,lin,3,0,13,0,0,0,lin,13,0,13,8,0,0,lin,13,8,0,12,0,0,lin,0,12,0,20,0,0,lin,0,20,10,20,0,0,lin,10,20,13,17,0,0,0x8f};
const int asteroidsSmallT[] = {lin,0,20,13,20,0,0,lin,7,20,7,0,0,0,0x8f};
const int asteroidsSmallU[] = {lin,0,20,0,3,0,0,lin,0,3,7,0,0,0,lin,7,0,13,3,0,0,lin,13,3,13,20,0,0,0x8f};
const int asteroidsSmallV[] = {lin,0,20,7,0,0,0,lin,7,0,13,20,0,0,0x8f};
const int asteroidsSmallW[] = {lin,0,20,3,0,0,0,lin,3,0,7,7,0,0,lin,7,7,10,0,0,0,lin,10,0,13,20,0,0,0x8f};
const int asteroidsSmallX[] = {lin,0,0,13,20,0,0,lin,0,20,13,0,0,0,0x8f};
const int asteroidsSmallY[] = {lin,0,20,7,10,0,0,lin,7,10,13,20,0,0,lin,7,10,7,0,0,0,0x8f};
const int asteroidsSmallZ[] = {lin,0,20,13,20,0,0,lin,13,20,0,0,0,0,lin,0,0,13,0,0,0,lin,3,10,10,10,0,0,0x8f};
const int asteroidsThree[] = {lin,0,20,13,20,0,0,lin,13,20,13,0,0,0,lin,13,0,0,0,0,0,lin,0,10,13,10,0,0,0x8f};
const int asteroidsTilde[] = {lin,0,7,3,13,0,0,lin,3,13,10,7,0,0,lin,10,7,13,13,0,0,0x8f};
const int asteroidsTwo[] = {lin,0,20,13,20,0,0,lin,13,20,13,12,0,0,lin,13,12,0,8,0,0,lin,0,8,0,0,0,0,lin,0,0,13,0,0,0,0x8f};
const int asteroidsUnderSc[] = {lin,0,0,13,0,0,0,0x8f};
const int asteroidsVertBar[] = {lin,7,0,7,8,0,0,lin,7,10,7,20,0,0,0x8f};
const int asteroidsZero[] = {lin,0,0,13,0,0,0,lin,13,0,13,20,0,0,lin,13,20,0,20,0,0,lin,0,20,0,0,0,0,lin,0,0,13,20,0,0,0x8f};

const int * const asteroidsFont[] =
{Space, asteroidsExclam, asteroidsDQuot, asteroidsSharp, asteroidsDollar, asteroidsPercent, asteroidsAmper, asteroidsApost, asteroidsLParen,
 asteroidsRParen, asteroidsAster, asteroidsPlus, asteroidsComma, asteroidsMinus, asteroidsPeriod, asteroidsSlash, asteroidsZero,
 asteroidsOne, asteroidsTwo, asteroidsThree, asteroidsFour, asteroidsFive, asteroidsSix, asteroidsSeven, asteroidsEight,
 asteroidsNine, asteroidsColon, asteroidsSemiCol, asteroidsLThan, asteroidsEqual, asteroidsGThan, asteroidsQuest, asteroidsAtSign,
 asteroidsBigA, asteroidsBigB, asteroidsBigC, asteroidsBigD, asteroidsBigE, asteroidsBigF, asteroidsBigG, asteroidsBigH, 
 asteroidsBigI, asteroidsBigJ, asteroidsBigK, asteroidsBigL, asteroidsBigM, asteroidsBigN, asteroidsBigO, asteroidsBigP,
 asteroidsBigQ, asteroidsBigR, asteroidsBigS, asteroidsBigT, asteroidsBigU, asteroidsBigV, asteroidsBigW, asteroidsBigX,
 asteroidsBigY, asteroidsBigZ, asteroidsLftSqBr, asteroidsBackSl, asteroidsRtSqBr, asteroidsCarat, asteroidsUnderSc, asteroidsBackQu,
 asteroidsSmallA, asteroidsSmallB, asteroidsSmallC, asteroidsSmallD, asteroidsSmallE, asteroidsSmallF, asteroidsSmallG, asteroidsSmallH,
 asteroidsSmallI, asteroidsSmallJ, asteroidsSmallK, asteroidsSmallL, asteroidsSmallM, asteroidsSmallN, asteroidsSmallO, asteroidsSmallP,
 asteroidsSmallQ, asteroidsSmallR, asteroidsSmallS, asteroidsSmallT, asteroidsSmallU, asteroidsSmallV, asteroidsSmallW, asteroidsSmallX,
 asteroidsSmallY, asteroidsSmallZ, asteroidsLfBrace, asteroidsVertBar, asteroidsRtBrace, asteroidsTilde, asteroidsRubout};

const int pico8Space[]   = {0x86};      // space does nothing but move over
const int pico8Rubout[]  = { lin, 0,10, 6,20, 6,13, lin, 0, 0,12,20, 6,13, lin, 6, 0,12,10, 6,13, 0x8c};
const int pico8Exclam[] = {lin,8,8,4,8,0,0,lin,8,20,8,8,0,0,lin,4,20,8,20,0,0,lin,4,8,4,20,0,0,lin,8,0,4,0,0,0,lin,8,4,8,0,0,0,lin,4,4,8,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8DQuot[] = {lin,4,12,0,12,0,0,lin,4,20,4,12,0,0,lin,0,20,4,20,0,0,lin,0,12,0,20,0,0,lin,12,12,8,12,0,0,lin,12,20,12,12,0,0,lin,8,20,12,20,0,0,lin,8,12,8,20,0,0,0x8c};
const int pico8Sharp[] = {lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,8,4,4,4,0,0,lin,8,0,8,4,0,0,lin,12,0,8,0,0,0,lin,12,20,12,0,0,0,lin,8,20,12,20,0,0,lin,8,16,8,20,0,0,lin,4,16,8,16,0,0,lin,4,20,4,16,0,0,lin,0,20,4,20,0,0,lin,0,0,0,20,0,0,lin,4,8,8,8,0,0,lin,4,12,4,8,0,0,lin,8,12,4,12,0,0,lin,8,8,8,12,0,0,0x8c};
const int pico8Dollar[] = {lin,8,0,4,0,0,0,lin,8,4,8,0,0,0,lin,12,4,8,4,0,0,lin,12,12,12,4,0,0,lin,8,12,12,12,0,0,lin,8,16,8,12,0,0,lin,12,16,8,16,0,0,lin,12,20,12,16,0,0,lin,0,20,12,20,0,0,lin,0,12,0,20,0,0,lin,4,12,0,12,0,0,lin,4,8,4,12,0,0,lin,0,8,4,8,0,0,lin,0,4,0,8,0,0,lin,4,4,0,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8Percent[] = {lin,4,16,0,16,0,0,lin,4,20,4,16,0,0,lin,0,20,4,20,0,0,lin,0,16,0,20,0,0,lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,0,8,4,8,0,0,lin,0,0,0,8,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,8,4,12,0,0,lin,12,12,8,12,0,0,lin,12,20,12,12,0,0,lin,8,20,12,20,0,0,lin,8,12,8,20,0,0,lin,12,0,8,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,0,8,4,0,0,0x8c};
const int pico8Amper[] = {lin,12,0,0,0,0,0,lin,12,12,12,0,0,0,lin,8,12,12,12,0,0,lin,8,20,8,12,0,0,lin,0,20,8,20,0,0,lin,0,0,0,20,0,0,lin,4,4,8,4,0,0,lin,4,8,4,4,0,0,lin,8,8,4,8,0,0,lin,8,4,8,8,0,0,0x8c};
const int pico8Apost[] = {lin,4,12,0,12,0,0,lin,4,16,4,12,0,0,lin,0,16,4,16,0,0,lin,0,12,0,16,0,0,lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,4,20,8,20,0,0,lin,4,16,4,20,0,0,0x8c};
const int pico8LParen[] = {lin,4,4,0,4,0,0,lin,4,16,4,4,0,0,lin,0,16,4,16,0,0,lin,0,4,0,16,0,0,lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,4,20,8,20,0,0,lin,4,16,4,20,0,0,lin,8,0,4,0,0,0,lin,8,4,8,0,0,0,lin,4,4,8,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8RParen[] = {lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,4,20,8,20,0,0,lin,4,16,4,20,0,0,lin,8,0,4,0,0,0,lin,8,4,8,0,0,0,lin,4,4,8,4,0,0,lin,4,0,4,4,0,0,lin,12,4,8,4,0,0,lin,12,16,12,4,0,0,lin,8,16,12,16,0,0,lin,8,4,8,16,0,0,0x8c};
const int pico8Aster[] = {lin,4,16,0,16,0,0,lin,4,20,4,16,0,0,lin,0,20,4,20,0,0,lin,0,16,0,20,0,0,lin,8,4,4,4,0,0,lin,8,8,8,4,0,0,lin,12,8,8,8,0,0,lin,12,12,12,8,0,0,lin,8,12,12,12,0,0,lin,8,16,8,12,0,0,lin,4,16,8,16,0,0,lin,4,12,4,16,0,0,lin,0,12,4,12,0,0,lin,0,8,0,12,0,0,lin,4,8,0,8,0,0,lin,4,4,4,8,0,0,lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,lin,12,16,8,16,0,0,lin,12,20,12,16,0,0,lin,8,20,12,20,0,0,lin,8,16,8,20,0,0,lin,12,0,8,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,0,8,4,0,0,0x8c};
const int pico8Plus[] = {lin,8,4,4,4,0,0,lin,8,8,8,4,0,0,lin,12,8,8,8,0,0,lin,12,12,12,8,0,0,lin,8,12,12,12,0,0,lin,8,16,8,12,0,0,lin,4,16,8,16,0,0,lin,4,12,4,16,0,0,lin,0,12,4,12,0,0,lin,0,8,0,12,0,0,lin,4,8,0,8,0,0,lin,4,4,4,8,0,0,0x8c};
const int pico8Comma[] = {lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,lin,8,4,4,4,0,0,lin,8,8,8,4,0,0,lin,4,8,8,8,0,0,lin,4,4,4,8,0,0,0x8c};
const int pico8Minus[] = {lin,12,8,0,8,0,0,lin,12,12,12,8,0,0,lin,0,12,12,12,0,0,lin,0,8,0,12,0,0,0x8c};
const int pico8Period[] = {lin,8,0,4,0,0,0,lin,8,4,8,0,0,0,lin,4,4,8,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8Slash[] = {lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,lin,8,4,4,4,0,0,lin,8,16,8,4,0,0,lin,4,16,8,16,0,0,lin,4,4,4,16,0,0,lin,12,16,8,16,0,0,lin,12,20,12,16,0,0,lin,8,20,12,20,0,0,lin,8,16,8,20,0,0,0x8c};
const int pico8Zero[] = {lin,12,0,0,0,0,0,lin,12,20,12,0,0,0,lin,0,20,12,20,0,0,lin,0,0,0,20,0,0,lin,4,4,8,4,0,0,lin,4,16,4,4,0,0,lin,8,16,4,16,0,0,lin,8,4,8,16,0,0,0x8c};
const int pico8One[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,20,8,4,0,0,lin,0,20,8,20,0,0,lin,0,16,0,20,0,0,lin,4,16,0,16,0,0,lin,4,4,4,16,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8Two[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,8,4,4,0,0,lin,12,8,4,8,0,0,lin,12,20,12,8,0,0,lin,0,20,12,20,0,0,lin,0,16,0,20,0,0,lin,8,16,0,16,0,0,lin,8,12,8,16,0,0,lin,0,12,8,12,0,0,lin,0,0,0,12,0,0,0x8c};
const int pico8Three[] = {lin,12,0,0,0,0,0,lin,12,20,12,0,0,0,lin,0,20,12,20,0,0,lin,0,16,0,20,0,0,lin,8,16,0,16,0,0,lin,8,12,8,16,0,0,lin,4,12,8,12,0,0,lin,4,8,4,12,0,0,lin,8,8,4,8,0,0,lin,8,4,8,8,0,0,lin,0,4,8,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8Four[] = {lin,12,0,8,0,0,0,lin,12,20,12,0,0,0,lin,8,20,12,20,0,0,lin,8,12,8,20,0,0,lin,4,12,8,12,0,0,lin,4,20,4,12,0,0,lin,0,20,4,20,0,0,lin,0,8,0,20,0,0,lin,8,8,0,8,0,0,lin,8,0,8,8,0,0,0x8c};
const int pico8Five[] = {lin,12,0,0,0,0,0,lin,12,12,12,0,0,0,lin,4,12,12,12,0,0,lin,4,16,4,12,0,0,lin,12,16,4,16,0,0,lin,12,20,12,16,0,0,lin,0,20,12,20,0,0,lin,0,8,0,20,0,0,lin,8,8,0,8,0,0,lin,8,4,8,8,0,0,lin,0,4,8,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8Six[] = {lin,12,0,0,0,0,0,lin,12,12,12,0,0,0,lin,4,12,12,12,0,0,lin,4,20,4,12,0,0,lin,0,20,4,20,0,0,lin,0,0,0,20,0,0,lin,4,4,8,4,0,0,lin,4,8,4,4,0,0,lin,8,8,4,8,0,0,lin,8,4,8,8,0,0,0x8c};
const int pico8Seven[] = {lin,12,0,8,0,0,0,lin,12,20,12,0,0,0,lin,0,20,12,20,0,0,lin,0,16,0,20,0,0,lin,8,16,0,16,0,0,lin,8,0,8,16,0,0,0x8c};
const int pico8Eight[] = {lin,12,0,0,0,0,0,lin,12,20,12,0,0,0,lin,0,20,12,20,0,0,lin,0,0,0,20,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,8,16,4,16,0,0,lin,8,12,8,16,0,0,lin,4,4,8,4,0,0,lin,4,8,4,4,0,0,lin,8,8,4,8,0,0,lin,8,4,8,8,0,0,0x8c};
const int pico8Nine[] = {lin,12,0,8,0,0,0,lin,12,20,12,0,0,0,lin,0,20,12,20,0,0,lin,0,8,0,20,0,0,lin,8,8,0,8,0,0,lin,8,0,8,8,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,8,16,4,16,0,0,lin,8,12,8,16,0,0,0x8c};
const int pico8Colon[] = {lin,8,12,4,12,0,0,lin,8,16,8,12,0,0,lin,4,16,8,16,0,0,lin,4,12,4,16,0,0,lin,8,4,4,4,0,0,lin,8,8,8,4,0,0,lin,4,8,8,8,0,0,lin,4,4,4,8,0,0,0x8c};
const int pico8SemiCol[] = {lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,lin,8,12,4,12,0,0,lin,8,16,8,12,0,0,lin,4,16,8,16,0,0,lin,4,12,4,16,0,0,lin,8,4,4,4,0,0,lin,8,8,8,4,0,0,lin,4,8,8,8,0,0,lin,4,4,4,8,0,0,0x8c};
const int pico8LThan[] = {lin,4,8,0,8,0,0,lin,4,12,4,8,0,0,lin,0,12,4,12,0,0,lin,0,8,0,12,0,0,lin,8,12,4,12,0,0,lin,8,16,8,12,0,0,lin,4,16,8,16,0,0,lin,4,12,4,16,0,0,lin,8,4,4,4,0,0,lin,8,8,8,4,0,0,lin,4,8,8,8,0,0,lin,4,4,4,8,0,0,lin,12,16,8,16,0,0,lin,12,20,12,16,0,0,lin,8,20,12,20,0,0,lin,8,16,8,20,0,0,lin,12,0,8,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,0,8,4,0,0,0x8c};
const int pico8Equal[] = {lin,12,12,0,12,0,0,lin,12,16,12,12,0,0,lin,0,16,12,16,0,0,lin,0,12,0,16,0,0,lin,12,4,0,4,0,0,lin,12,8,12,4,0,0,lin,0,8,12,8,0,0,lin,0,4,0,8,0,0,0x8c};
const int pico8GThan[] = {lin,4,16,0,16,0,0,lin,4,20,4,16,0,0,lin,0,20,4,20,0,0,lin,0,16,0,20,0,0,lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,lin,8,12,4,12,0,0,lin,8,16,8,12,0,0,lin,4,16,8,16,0,0,lin,4,12,4,16,0,0,lin,8,4,4,4,0,0,lin,8,8,8,4,0,0,lin,4,8,8,8,0,0,lin,4,4,4,8,0,0,lin,12,8,8,8,0,0,lin,12,12,12,8,0,0,lin,8,12,12,12,0,0,lin,8,8,8,12,0,0,0x8c};
const int pico8Quest[] = {lin,12,8,4,8,0,0,lin,12,20,12,8,0,0,lin,0,20,12,20,0,0,lin,0,16,0,20,0,0,lin,8,16,0,16,0,0,lin,8,12,8,16,0,0,lin,4,12,8,12,0,0,lin,4,8,4,12,0,0,lin,8,0,4,0,0,0,lin,8,4,8,0,0,0,lin,4,4,8,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8AtSign[] = {lin,4,4,0,4,0,0,lin,4,16,4,4,0,0,lin,0,16,4,16,0,0,lin,0,4,0,16,0,0,lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,4,20,8,20,0,0,lin,4,16,4,20,0,0,lin,12,0,4,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,0,4,4,0,0,lin,12,8,8,8,0,0,lin,12,16,12,8,0,0,lin,8,16,12,16,0,0,lin,8,8,8,16,0,0,0x8c};
const int pico8BigA[] = {lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,8,8,4,8,0,0,lin,8,0,8,8,0,0,lin,12,0,8,0,0,0,lin,12,20,12,0,0,0,lin,0,20,12,20,0,0,lin,0,0,0,20,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,8,16,4,16,0,0,lin,8,12,8,16,0,0,0x8c};
const int pico8BigB[] = {lin,12,0,0,0,0,0,lin,12,8,12,0,0,0,lin,8,8,12,8,0,0,lin,8,4,8,8,0,0,lin,4,4,8,4,0,0,lin,4,8,4,4,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,8,16,4,16,0,0,lin,8,12,8,16,0,0,lin,12,12,8,12,0,0,lin,12,20,12,12,0,0,lin,0,20,12,20,0,0,lin,0,0,0,20,0,0,0x8c};
const int pico8BigC[] = {lin,4,4,0,4,0,0,lin,4,16,4,4,0,0,lin,0,16,4,16,0,0,lin,0,4,0,16,0,0,lin,12,16,4,16,0,0,lin,12,20,12,16,0,0,lin,4,20,12,20,0,0,lin,4,16,4,20,0,0,lin,12,0,4,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8BigD[] = {lin,12,0,0,0,0,0,lin,12,16,12,0,0,0,lin,8,16,12,16,0,0,lin,8,4,8,16,0,0,lin,4,4,8,4,0,0,lin,4,16,4,4,0,0,lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,0,20,8,20,0,0,lin,0,0,0,20,0,0,0x8c};
const int pico8BigE[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,8,4,4,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,12,16,4,16,0,0,lin,12,20,12,16,0,0,lin,0,20,12,20,0,0,lin,0,0,0,20,0,0,0x8c};
const int pico8BigF[] = {lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,12,16,4,16,0,0,lin,12,20,12,16,0,0,lin,0,20,12,20,0,0,lin,0,0,0,20,0,0,0x8c};
const int pico8BigG[] = {lin,12,0,0,0,0,0,lin,12,8,12,0,0,0,lin,8,8,12,8,0,0,lin,8,4,8,8,0,0,lin,4,4,8,4,0,0,lin,4,16,4,4,0,0,lin,0,16,4,16,0,0,lin,0,0,0,16,0,0,lin,12,16,4,16,0,0,lin,12,20,12,16,0,0,lin,4,20,12,20,0,0,lin,4,16,4,20,0,0,0x8c};
const int pico8BigH[] = {lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,8,8,4,8,0,0,lin,8,0,8,8,0,0,lin,12,0,8,0,0,0,lin,12,20,12,0,0,0,lin,8,20,12,20,0,0,lin,8,12,8,20,0,0,lin,4,12,8,12,0,0,lin,4,20,4,12,0,0,lin,0,20,4,20,0,0,lin,0,0,0,20,0,0,0x8c};
const int pico8BigI[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,16,8,4,0,0,lin,12,16,8,16,0,0,lin,12,20,12,16,0,0,lin,0,20,12,20,0,0,lin,0,16,0,20,0,0,lin,4,16,0,16,0,0,lin,4,4,4,16,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8BigJ[] = {lin,8,0,0,0,0,0,lin,8,16,8,0,0,0,lin,12,16,8,16,0,0,lin,12,20,12,16,0,0,lin,0,20,12,20,0,0,lin,0,16,0,20,0,0,lin,4,16,0,16,0,0,lin,4,4,4,16,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8BigK[] = {lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,20,4,12,0,0,lin,0,20,4,20,0,0,lin,0,0,0,20,0,0,lin,12,12,8,12,0,0,lin,12,20,12,12,0,0,lin,8,20,12,20,0,0,lin,8,12,8,20,0,0,lin,12,0,8,0,0,0,lin,12,8,12,0,0,0,lin,8,8,12,8,0,0,lin,8,0,8,8,0,0,0x8c};
const int pico8BigL[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,20,4,4,0,0,lin,0,20,4,20,0,0,lin,0,0,0,20,0,0,0x8c};
const int pico8BigM[] = {lin,4,0,0,0,0,0,lin,4,12,4,0,0,0,lin,8,12,4,12,0,0,lin,8,0,8,12,0,0,lin,12,0,8,0,0,0,lin,12,20,12,0,0,0,lin,0,20,12,20,0,0,lin,0,0,0,20,0,0,0x8c};
const int pico8BigN[] = {lin,4,0,0,0,0,0,lin,4,16,4,0,0,0,lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,0,20,8,20,0,0,lin,0,0,0,20,0,0,lin,12,0,8,0,0,0,lin,12,16,12,0,0,0,lin,8,16,12,16,0,0,lin,8,0,8,16,0,0,0x8c};
const int pico8BigO[] = {lin,8,0,0,0,0,0,lin,8,4,8,0,0,0,lin,4,4,8,4,0,0,lin,4,16,4,4,0,0,lin,0,16,4,16,0,0,lin,0,0,0,16,0,0,lin,12,4,8,4,0,0,lin,12,20,12,4,0,0,lin,4,20,12,20,0,0,lin,4,16,4,20,0,0,lin,8,16,4,16,0,0,lin,8,4,8,16,0,0,0x8c};
const int pico8BigP[] = {lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,12,8,4,8,0,0,lin,12,20,12,8,0,0,lin,0,20,12,20,0,0,lin,0,0,0,20,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,8,16,4,16,0,0,lin,8,12,8,16,0,0,0x8c};
const int pico8BigQ[] = {lin,12,0,4,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,8,8,4,0,0,lin,4,8,8,8,0,0,lin,4,16,4,8,0,0,lin,0,16,4,16,0,0,lin,0,4,0,16,0,0,lin,4,4,0,4,0,0,lin,4,0,4,4,0,0,lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,4,20,8,20,0,0,lin,4,16,4,20,0,0,lin,12,8,8,8,0,0,lin,12,16,12,8,0,0,lin,8,16,12,16,0,0,lin,8,8,8,16,0,0,0x8c};
const int pico8BigR[] = {lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,8,16,4,16,0,0,lin,8,12,8,16,0,0,lin,12,12,8,12,0,0,lin,12,20,12,12,0,0,lin,0,20,12,20,0,0,lin,0,0,0,20,0,0,lin,12,0,8,0,0,0,lin,12,8,12,0,0,0,lin,8,8,12,8,0,0,lin,8,0,8,8,0,0,0x8c};
const int pico8BigS[] = {lin,12,4,8,4,0,0,lin,12,12,12,4,0,0,lin,4,12,12,12,0,0,lin,4,16,4,12,0,0,lin,0,16,4,16,0,0,lin,0,8,0,16,0,0,lin,8,8,0,8,0,0,lin,8,4,8,8,0,0,lin,8,0,0,0,0,0,lin,8,4,8,0,0,0,lin,0,4,8,4,0,0,lin,0,0,0,4,0,0,lin,12,16,4,16,0,0,lin,12,20,12,16,0,0,lin,4,20,12,20,0,0,lin,4,16,4,20,0,0,0x8c};
const int pico8BigT[] = {lin,8,0,4,0,0,0,lin,8,16,8,0,0,0,lin,12,16,8,16,0,0,lin,12,20,12,16,0,0,lin,0,20,12,20,0,0,lin,0,16,0,20,0,0,lin,4,16,0,16,0,0,lin,4,0,4,16,0,0,0x8c};
const int pico8BigU[] = {lin,4,4,0,4,0,0,lin,4,20,4,4,0,0,lin,0,20,4,20,0,0,lin,0,4,0,20,0,0,lin,12,0,4,0,0,0,lin,12,20,12,0,0,0,lin,8,20,12,20,0,0,lin,8,4,8,20,0,0,lin,4,4,8,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8BigV[] = {lin,8,0,4,0,0,0,lin,8,4,8,0,0,0,lin,12,4,8,4,0,0,lin,12,20,12,4,0,0,lin,8,20,12,20,0,0,lin,8,8,8,20,0,0,lin,4,8,8,8,0,0,lin,4,20,4,8,0,0,lin,0,20,4,20,0,0,lin,0,4,0,20,0,0,lin,4,4,0,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8BigW[] = {lin,12,0,0,0,0,0,lin,12,20,12,0,0,0,lin,8,20,12,20,0,0,lin,8,8,8,20,0,0,lin,4,8,8,8,0,0,lin,4,20,4,8,0,0,lin,0,20,4,20,0,0,lin,0,0,0,20,0,0,0x8c};
const int pico8BigX[] = {lin,4,12,0,12,0,0,lin,4,20,4,12,0,0,lin,0,20,4,20,0,0,lin,0,12,0,20,0,0,lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,0,8,4,8,0,0,lin,0,0,0,8,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,8,4,12,0,0,lin,12,12,8,12,0,0,lin,12,20,12,12,0,0,lin,8,20,12,20,0,0,lin,8,12,8,20,0,0,lin,12,0,8,0,0,0,lin,12,8,12,0,0,0,lin,8,8,12,8,0,0,lin,8,0,8,8,0,0,0x8c};
const int pico8BigY[] = {lin,12,0,0,0,0,0,lin,12,20,12,0,0,0,lin,8,20,12,20,0,0,lin,8,12,8,20,0,0,lin,4,12,8,12,0,0,lin,4,20,4,12,0,0,lin,0,20,4,20,0,0,lin,0,8,0,20,0,0,lin,8,8,0,8,0,0,lin,8,4,8,8,0,0,lin,0,4,8,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8BigZ[] = {lin,12,12,8,12,0,0,lin,12,20,12,12,0,0,lin,0,20,12,20,0,0,lin,0,16,0,20,0,0,lin,8,16,0,16,0,0,lin,8,12,8,16,0,0,lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,8,4,4,0,0,lin,0,8,4,8,0,0,lin,0,0,0,8,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,8,4,12,0,0,0x8c};
const int pico8LftSqBr[] = {lin,8,0,0,0,0,0,lin,8,4,8,0,0,0,lin,4,4,8,4,0,0,lin,4,16,4,4,0,0,lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,0,20,8,20,0,0,lin,0,0,0,20,0,0,0x8c};
const int pico8BackSl[] = {lin,4,16,0,16,0,0,lin,4,20,4,16,0,0,lin,0,20,4,20,0,0,lin,0,16,0,20,0,0,lin,8,4,4,4,0,0,lin,8,16,8,4,0,0,lin,4,16,8,16,0,0,lin,4,4,4,16,0,0,lin,12,0,8,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,0,8,4,0,0,0x8c};
const int pico8RtSqBr[] = {lin,12,0,4,0,0,0,lin,12,20,12,0,0,0,lin,4,20,12,20,0,0,lin,4,16,4,20,0,0,lin,8,16,4,16,0,0,lin,8,4,8,16,0,0,lin,4,4,8,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8Carat[] = {lin,4,12,0,12,0,0,lin,4,16,4,12,0,0,lin,0,16,4,16,0,0,lin,0,12,0,16,0,0,lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,4,20,8,20,0,0,lin,4,16,4,20,0,0,lin,12,12,8,12,0,0,lin,12,16,12,12,0,0,lin,8,16,12,16,0,0,lin,8,12,8,16,0,0,0x8c};
const int pico8UnderSc[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,0,4,12,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8BackQu[] = {lin,8,16,4,16,0,0,lin,8,20,8,16,0,0,lin,4,20,8,20,0,0,lin,4,16,4,20,0,0,lin,12,12,8,12,0,0,lin,12,16,12,12,0,0,lin,8,16,12,16,0,0,lin,8,12,8,16,0,0,0x8c};
const int pico8SmallA[] = {lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,8,4,4,4,0,0,lin,8,0,8,4,0,0,lin,12,0,8,0,0,0,lin,12,16,12,0,0,0,lin,0,16,12,16,0,0,lin,0,0,0,16,0,0,lin,4,8,8,8,0,0,lin,4,12,4,8,0,0,lin,8,12,4,12,0,0,lin,8,8,8,12,0,0,0x8c};
const int pico8SmallB[] = {lin,12,0,0,0,0,0,lin,12,8,12,0,0,0,lin,8,8,12,8,0,0,lin,8,4,8,8,0,0,lin,4,4,8,4,0,0,lin,4,8,4,4,0,0,lin,8,8,4,8,0,0,lin,8,16,8,8,0,0,lin,0,16,8,16,0,0,lin,0,0,0,16,0,0,0x8c};
const int pico8SmallC[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,12,4,4,0,0,lin,12,12,4,12,0,0,lin,12,16,12,12,0,0,lin,0,16,12,16,0,0,lin,0,0,0,16,0,0,0x8c};
const int pico8SmallD[] = {lin,8,0,0,0,0,0,lin,8,4,8,0,0,0,lin,4,4,8,4,0,0,lin,4,12,4,4,0,0,lin,8,12,4,12,0,0,lin,8,16,8,12,0,0,lin,0,16,8,16,0,0,lin,0,0,0,16,0,0,lin,12,4,8,4,0,0,lin,12,12,12,4,0,0,lin,8,12,12,12,0,0,lin,8,4,8,12,0,0,0x8c};
const int pico8SmallE[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,8,4,4,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,12,12,8,12,0,0,lin,12,16,12,12,0,0,lin,0,16,12,16,0,0,lin,0,0,0,16,0,0,0x8c};
const int pico8SmallF[] = {lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,12,12,8,12,0,0,lin,12,16,12,12,0,0,lin,0,16,12,16,0,0,lin,0,0,0,16,0,0,0x8c};
const int pico8SmallG[] = {lin,12,0,0,0,0,0,lin,12,8,12,0,0,0,lin,8,8,12,8,0,0,lin,8,4,8,8,0,0,lin,4,4,8,4,0,0,lin,4,12,4,4,0,0,lin,12,12,4,12,0,0,lin,12,16,12,12,0,0,lin,0,16,12,16,0,0,lin,0,0,0,16,0,0,0x8c};
const int pico8SmallH[] = {lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,8,4,4,4,0,0,lin,8,0,8,4,0,0,lin,12,0,8,0,0,0,lin,12,16,12,0,0,0,lin,8,16,12,16,0,0,lin,8,8,8,16,0,0,lin,4,8,8,8,0,0,lin,4,16,4,8,0,0,lin,0,16,4,16,0,0,lin,0,0,0,16,0,0,0x8c};
const int pico8SmallI[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,12,8,4,0,0,lin,12,12,8,12,0,0,lin,12,16,12,12,0,0,lin,0,16,12,16,0,0,lin,0,12,0,16,0,0,lin,4,12,0,12,0,0,lin,4,4,4,12,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8SmallJ[] = {lin,8,0,0,0,0,0,lin,8,12,8,0,0,0,lin,12,12,8,12,0,0,lin,12,16,12,12,0,0,lin,0,16,12,16,0,0,lin,0,12,0,16,0,0,lin,4,12,0,12,0,0,lin,4,4,4,12,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8SmallK[] = {lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,0,16,4,16,0,0,lin,0,0,0,16,0,0,lin,12,12,8,12,0,0,lin,12,16,12,12,0,0,lin,8,16,12,16,0,0,lin,8,12,8,16,0,0,lin,12,0,8,0,0,0,lin,12,8,12,0,0,0,lin,8,8,12,8,0,0,lin,8,0,8,8,0,0,0x8c};
const int pico8SmallL[] = {lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,16,4,4,0,0,lin,0,16,4,16,0,0,lin,0,0,0,16,0,0,0x8c};
const int pico8SmallM[] = {lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,8,8,4,8,0,0,lin,8,0,8,8,0,0,lin,12,0,8,0,0,0,lin,12,16,12,0,0,0,lin,0,16,12,16,0,0,lin,0,0,0,16,0,0,0x8c};
const int pico8SmallN[] = {lin,4,0,0,0,0,0,lin,4,12,4,0,0,0,lin,8,12,4,12,0,0,lin,8,16,8,12,0,0,lin,0,16,8,16,0,0,lin,0,0,0,16,0,0,lin,12,0,8,0,0,0,lin,12,12,12,0,0,0,lin,8,12,12,12,0,0,lin,8,0,8,12,0,0,0x8c};
const int pico8SmallO[] = {lin,8,0,0,0,0,0,lin,8,4,8,0,0,0,lin,4,4,8,4,0,0,lin,4,12,4,4,0,0,lin,0,12,4,12,0,0,lin,0,0,0,12,0,0,lin,12,4,8,4,0,0,lin,12,16,12,4,0,0,lin,4,16,12,16,0,0,lin,4,12,4,16,0,0,lin,8,12,4,12,0,0,lin,8,4,8,12,0,0,0x8c};
const int pico8SmallP[] = {lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,12,4,4,4,0,0,lin,12,16,12,4,0,0,lin,0,16,12,16,0,0,lin,0,0,0,16,0,0,lin,4,8,8,8,0,0,lin,4,12,4,8,0,0,lin,8,12,4,12,0,0,lin,8,8,8,12,0,0,0x8c};
const int pico8SmallQ[] = {lin,12,0,4,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,8,8,4,0,0,lin,4,8,8,8,0,0,lin,4,12,4,8,0,0,lin,0,12,4,12,0,0,lin,0,4,0,12,0,0,lin,4,4,0,4,0,0,lin,4,0,4,4,0,0,lin,8,12,4,12,0,0,lin,8,16,8,12,0,0,lin,4,16,8,16,0,0,lin,4,12,4,16,0,0,lin,12,8,8,8,0,0,lin,12,12,12,8,0,0,lin,8,12,12,12,0,0,lin,8,8,8,12,0,0,0x8c};
const int pico8SmallR[] = {lin,4,0,0,0,0,0,lin,4,4,4,0,0,0,lin,8,4,4,4,0,0,lin,8,8,8,4,0,0,lin,4,8,8,8,0,0,lin,4,12,4,8,0,0,lin,8,12,4,12,0,0,lin,8,8,8,12,0,0,lin,12,8,8,8,0,0,lin,12,16,12,8,0,0,lin,0,16,12,16,0,0,lin,0,0,0,16,0,0,lin,12,0,8,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,0,8,4,0,0,0x8c};
const int pico8SmallS[] = {lin,4,8,0,8,0,0,lin,4,12,4,8,0,0,lin,0,12,4,12,0,0,lin,0,8,0,12,0,0,lin,8,0,0,0,0,0,lin,8,4,8,0,0,0,lin,0,4,8,4,0,0,lin,0,0,0,4,0,0,lin,12,12,4,12,0,0,lin,12,16,12,12,0,0,lin,4,16,12,16,0,0,lin,4,12,4,16,0,0,lin,12,4,8,4,0,0,lin,12,8,12,4,0,0,lin,8,8,12,8,0,0,lin,8,4,8,8,0,0,0x8c};
const int pico8SmallT[] = {lin,8,0,4,0,0,0,lin,8,12,8,0,0,0,lin,12,12,8,12,0,0,lin,12,16,12,12,0,0,lin,0,16,12,16,0,0,lin,0,12,0,16,0,0,lin,4,12,0,12,0,0,lin,4,0,4,12,0,0,0x8c};
const int pico8SmallU[] = {lin,4,4,0,4,0,0,lin,4,16,4,4,0,0,lin,0,16,4,16,0,0,lin,0,4,0,16,0,0,lin,12,0,4,0,0,0,lin,12,16,12,0,0,0,lin,8,16,12,16,0,0,lin,8,4,8,16,0,0,lin,4,4,8,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8SmallV[] = {lin,8,0,4,0,0,0,lin,8,4,8,0,0,0,lin,12,4,8,4,0,0,lin,12,16,12,4,0,0,lin,8,16,12,16,0,0,lin,8,8,8,16,0,0,lin,4,8,8,8,0,0,lin,4,16,4,8,0,0,lin,0,16,4,16,0,0,lin,0,4,0,16,0,0,lin,4,4,0,4,0,0,lin,4,0,4,4,0,0,0x8c};
const int pico8SmallW[] = {lin,12,0,0,0,0,0,lin,12,16,12,0,0,0,lin,8,16,12,16,0,0,lin,8,8,8,16,0,0,lin,4,8,8,8,0,0,lin,4,16,4,8,0,0,lin,0,16,4,16,0,0,lin,0,0,0,16,0,0,0x8c};
const int pico8SmallX[] = {lin,4,12,0,12,0,0,lin,4,16,4,12,0,0,lin,0,16,4,16,0,0,lin,0,12,0,16,0,0,lin,4,0,0,0,0,0,lin,4,8,4,0,0,0,lin,0,8,4,8,0,0,lin,0,0,0,8,0,0,lin,8,8,4,8,0,0,lin,8,12,8,8,0,0,lin,4,12,8,12,0,0,lin,4,8,4,12,0,0,lin,12,12,8,12,0,0,lin,12,16,12,12,0,0,lin,8,16,12,16,0,0,lin,8,12,8,16,0,0,lin,12,0,8,0,0,0,lin,12,8,12,0,0,0,lin,8,8,12,8,0,0,lin,8,0,8,8,0,0,0x8c};
const int pico8SmallY[] = {lin,12,0,0,0,0,0,lin,12,16,12,0,0,0,lin,8,16,12,16,0,0,lin,8,12,8,16,0,0,lin,4,12,8,12,0,0,lin,4,16,4,12,0,0,lin,0,16,4,16,0,0,lin,0,8,0,16,0,0,lin,8,8,0,8,0,0,lin,8,4,8,8,0,0,lin,0,4,8,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8SmallZ[] = {lin,12,8,8,8,0,0,lin,12,16,12,8,0,0,lin,0,16,12,16,0,0,lin,0,12,0,16,0,0,lin,8,12,0,12,0,0,lin,8,8,8,12,0,0,lin,12,0,0,0,0,0,lin,12,4,12,0,0,0,lin,4,4,12,4,0,0,lin,4,8,4,4,0,0,lin,0,8,4,8,0,0,lin,0,0,0,8,0,0,0x8c};
const int pico8LfBrace[] = {lin,12,0,4,0,0,0,lin,12,4,12,0,0,0,lin,8,4,12,4,0,0,lin,8,16,8,4,0,0,lin,12,16,8,16,0,0,lin,12,20,12,16,0,0,lin,4,20,12,20,0,0,lin,4,12,4,20,0,0,lin,0,12,4,12,0,0,lin,0,8,0,12,0,0,lin,4,8,0,8,0,0,lin,4,0,4,8,0,0,0x8c};
const int pico8VertBar[] = {lin,8,0,4,0,0,0,lin,8,20,8,0,0,0,lin,4,20,8,20,0,0,lin,4,0,4,20,0,0,0x8c};
const int pico8RtBrace[] = {lin,8,0,0,0,0,0,lin,8,8,8,0,0,0,lin,12,8,8,8,0,0,lin,12,12,12,8,0,0,lin,8,12,12,12,0,0,lin,8,20,8,12,0,0,lin,0,20,8,20,0,0,lin,0,16,0,20,0,0,lin,4,16,0,16,0,0,lin,4,4,4,16,0,0,lin,0,4,4,4,0,0,lin,0,0,0,4,0,0,0x8c};
const int pico8Tilde[] = {lin,4,4,0,4,0,0,lin,4,8,4,4,0,0,lin,12,8,4,8,0,0,lin,12,16,12,8,0,0,lin,8,16,12,16,0,0,lin,8,12,8,16,0,0,lin,0,12,8,12,0,0,lin,0,4,0,12,0,0,0x8c};

const int * const pico8Font[] =
{Space, pico8Exclam, pico8DQuot, pico8Sharp, pico8Dollar, pico8Percent, pico8Amper, pico8Apost, pico8LParen,
 pico8RParen, pico8Aster, pico8Plus, pico8Comma, pico8Minus, pico8Period, pico8Slash, pico8Zero,
 pico8One, pico8Two, pico8Three, pico8Four, pico8Five, pico8Six, pico8Seven, pico8Eight,
 pico8Nine, pico8Colon, pico8SemiCol, pico8LThan, pico8Equal, pico8GThan, pico8Quest, pico8AtSign,
 pico8BigA, pico8BigB, pico8BigC, pico8BigD, pico8BigE, pico8BigF, pico8BigG, pico8BigH, 
 pico8BigI, pico8BigJ, pico8BigK, pico8BigL, pico8BigM, pico8BigN, pico8BigO, pico8BigP,
 pico8BigQ, pico8BigR, pico8BigS, pico8BigT, pico8BigU, pico8BigV, pico8BigW, pico8BigX,
 pico8BigY, pico8BigZ, pico8LftSqBr, pico8BackSl, pico8RtSqBr, pico8Carat, pico8UnderSc, pico8BackQu,
 pico8SmallA, pico8SmallB, pico8SmallC, pico8SmallD, pico8SmallE, pico8SmallF, pico8SmallG, pico8SmallH,
 pico8SmallI, pico8SmallJ, pico8SmallK, pico8SmallL, pico8SmallM, pico8SmallN, pico8SmallO, pico8SmallP,
 pico8SmallQ, pico8SmallR, pico8SmallS, pico8SmallT, pico8SmallU, pico8SmallV, pico8SmallW, pico8SmallX,
 pico8SmallY, pico8SmallZ, pico8LfBrace, pico8VertBar, pico8RtBrace, pico8Tilde, pico8Rubout};

/*
  AAA
F     B
F     B
  GGG
E     C
E     C
  DDD
 */

#define LEDSEGA lin,10,18, 2,18, 6,13,  lin,11,19,10,18, 6,13,  lin,10,20,11,19, 6,13,  lin, 2,20,10,20, 6,13,  lin, 1,19, 2,20, 6,13,  lin, 2,18, 1,19, 6,13,
#define LEDSEGB lin,10,11,10,18, 6,13,  lin,11,10,10,11, 6,13,  lin,12,11,11,10, 6,13,  lin,12,18,12,11, 6,13,  lin,11,19,12,18, 6,13,  lin,10,18,11,19, 6,13,
#define LEDSEGC lin,10, 2,10, 9, 6,13,  lin,11, 1,10, 2, 6,13,  lin,12, 2,11, 1, 6,13,  lin,12, 9,12, 2, 6,13,  lin,11,10,12, 9, 6,13,  lin,10, 9,11,10, 6,13,
#define LEDSEGD lin,10, 0, 2, 0, 6,13,  lin,11, 1,10, 0, 6,13,  lin,10, 2,11, 1, 6,13,  lin, 2, 2,10, 2, 6,13,  lin, 1, 1, 2, 2, 6,13,  lin, 2, 0, 1, 1, 6,13,
#define LEDSEGE lin, 0, 2, 0, 9, 6,13,  lin, 1, 1, 0, 2, 6,13,  lin, 2, 2, 1, 1, 6,13,  lin, 2, 9, 2, 2, 6,13,  lin, 1,10, 2, 9, 6,13,  lin, 0, 9, 1,10, 6,13,
#define LEDSEGF lin, 0,11, 0,18, 6,13,  lin, 1,10, 0,11, 6,13,  lin, 2,11, 1,10, 6,13,  lin, 2,18, 2,11, 6,13,  lin, 1,19, 2,18, 6,13,  lin, 0,18, 1,19, 6,13,
#define LEDSEGG lin,10, 9, 2, 9, 6,13,  lin,11,10,10, 9, 6,13,  lin,10,11,11,10, 6,13,  lin, 2,11,10,11, 6,13,  lin, 1,10, 2,11, 6,13,  lin, 2, 9, 1,10, 6,13,

const int LEDZero[] = {
  LEDSEGA
  LEDSEGB
  LEDSEGC
  LEDSEGD
  LEDSEGE
  LEDSEGF
  0x8c};

const int LEDOne[] = {
  LEDSEGB
  LEDSEGC
  0x8c};

const int LEDTwo[] = {
  LEDSEGA
  LEDSEGB
  LEDSEGD
  LEDSEGE
  LEDSEGG
  0x8c};

const int LEDThree[] = {
  LEDSEGA
  LEDSEGB
  LEDSEGC
  LEDSEGD
  LEDSEGG
  0x8c};

const int LEDFour[] = {
  LEDSEGB
  LEDSEGC
  LEDSEGF
  LEDSEGG
  0x8c};

const int LEDFive[] = {
  LEDSEGA
  LEDSEGC
  LEDSEGD
  LEDSEGF
  LEDSEGG
  0x8c};

const int LEDSix[] = {
  LEDSEGA
  LEDSEGC
  LEDSEGD
  LEDSEGE
  LEDSEGF
  LEDSEGG
  0x8c};

const int LEDSeven[] = {
  LEDSEGA
  LEDSEGB
  LEDSEGC
  0x8c};

const int LEDEight[] = {
  LEDSEGA
  LEDSEGB
  LEDSEGC
  LEDSEGD
  LEDSEGE
  LEDSEGF
  LEDSEGG
  0x8c};

const int LEDNine[] = {
  LEDSEGA
  LEDSEGB
  LEDSEGC
  LEDSEGD
  LEDSEGF
  LEDSEGG
  0x8c};

// All the characters, arranged in ASCII order because ASCII rules
const int * const LEDFont[] =
{Space, Exclam,DQuot, Sharp,  Dollar, Percent,Amper, Apost,
 LParen,RParen,Aster, Plus,   Comma,  Minus,  Period,Slash,
 LEDZero, LEDOne, LEDTwo, LEDThree, LEDFour, LEDFive, LEDSix, LEDSeven,
 LEDEight, LEDNine,  Colon, SemiCol,LThan,  Equal,  GThan, Quest,
 AtSign,BigA,  BigB,  BigC,   BigD,   BigE,   BigF,  BigG,
 BigH,  BigI,  BigJ,  BigK,   BigL,   BigM,   BigN,  BigO,
 BigP,  BigQ,  BigR,  BigS,   BigT,   BigU,   BigV,  BigW,
 BigX,  BigY,  BigZ,  LftSqBr,BackSl, RtSqBr, Carat, UnderSc,
 BackQu,SmallA,SmallB,SmallC, SmallD, SmallE, SmallF,SmallG,
 SmallH,SmallI,SmallJ,SmallK, SmallL, SmallM, SmallN,SmallO,
 SmallP,SmallQ,SmallR,SmallS, SmallT, SmallU, SmallV,SmallW,
 SmallX,SmallY,SmallZ,LfBrace,VertBar,RtBrace,Tilde, Rubout};

const int * const * Fonts[] = {Font1, asteroidsFont, LEDFont, pico8Font};
