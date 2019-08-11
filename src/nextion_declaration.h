// Nextion components deklaration
// global
// page 1


char sRotationSpeed[2] = "";

NexText   title       = NexText(  0, 21, "title");
NexText   temp        = NexText(  0, 22, "temp");
NexText   humid       = NexText(  0, 23, "humid");

NexPage   p01         = NexPage(  0,  0, "p01");
NexText   p01title    = NexText(  0,  1, "p01title");
NexText   p01temp     = NexText(  0, 18, "p01temp");
NexText   p01humid    = NexText(  0, 19, "p01humid");
NexButton p01settings = NexButton(0,  9, "p01settings");
NexButton p01power    = NexButton(0, 20, "p01power");
NexButton p01t01      = NexButton(0,  2, "p01t01");
NexButton p01t02      = NexButton(0,  3, "p01t02");
NexButton p01t03      = NexButton(0,  4, "p01t03");
NexButton p01t04      = NexButton(0,  5, "p01t04");
NexButton p01t05      = NexButton(0,  6, "p01t05");
NexButton p01t06      = NexButton(0,  7, "p01t06");
NexButton p01t07      = NexButton(0,  8, "p01t07");
NexButton p01c01      = NexButton(0, 10, "p01c01");
NexButton p01c02      = NexButton(0, 11, "p01c02");
NexButton p01c03      = NexButton(0, 12, "p01c03");
NexButton p01c04      = NexButton(0, 13, "p01c04");
NexButton p01c05      = NexButton(0, 14, "p01c05");
NexButton p01c06      = NexButton(0, 15, "p01c06");
NexButton p01c07      = NexButton(0, 16, "p01c07");
NexButton p01c08      = NexButton(0, 17, "p01c08");
NexButton p01c09      = NexButton(0, 25, "p01c09");
// page 2
NexPage   p02         = NexPage(  1,  0, "p02");
NexText   p02title    = NexText(  1,  1, "p02title");
NexText   p02temp     = NexText(  1, 18, "p02temp");
NexText   p02humid    = NexText(  1, 19, "p02humid");
NexButton p02settings = NexButton(1,  9, "p02settings");
NexButton p02power    = NexButton(1, 20, "p02power");
NexButton p02t01      = NexButton(1,  2, "p02t01");
NexButton p02t02      = NexButton(1,  3, "p02t02");
NexButton p02t03      = NexButton(1,  4, "p02t03");
NexButton p02t04      = NexButton(1,  5, "p02t04");
NexButton p02t05      = NexButton(1,  6, "p02t05");
NexButton p02t06      = NexButton(1,  7, "p02t06");
NexButton p02t07      = NexButton(1,  8, "p02t07");
NexButton p02c01      = NexButton(1, 10, "p02c01");
NexButton p02c02      = NexButton(1, 11, "p02c02");
NexButton p02c03      = NexButton(1, 12, "p02c03");
NexButton p02c04      = NexButton(1, 13, "p02c04");
NexButton p02c05      = NexButton(1, 14, "p02c05");
NexButton p02c06      = NexButton(1, 15, "p02c06");
NexButton p02c07      = NexButton(1, 16, "p02c07");
NexButton p02c08      = NexButton(1, 17, "p02c08");
// page 3
NexPage   p03         = NexPage(  2,  0, "p03");
NexText   p03title    = NexText(  2,  1, "p03title");
NexText   p03temp     = NexText(  2, 18, "p03temp");
NexText   p03humid    = NexText(  2, 19, "p03humid");
NexButton p03settings = NexButton(2,  9, "p03settings");
NexButton p03power    = NexButton(2, 20, "p03power");
NexButton p03t01      = NexButton(2,  2, "p03t01");
NexButton p03t02      = NexButton(2,  3, "p03t02");
NexButton p03t03      = NexButton(2,  4, "p03t03");
NexButton p03t04      = NexButton(2,  5, "p03t04");
NexButton p03t05      = NexButton(2,  6, "p03t05");
NexButton p03t06      = NexButton(2,  7, "p03t06");
NexButton p03t07      = NexButton(2,  8, "p03t07");
NexButton p03c01      = NexButton(2, 10, "p03c01");
NexButton p03c02      = NexButton(2, 11, "p03c02");
NexButton p03c03      = NexButton(2, 12, "p03c03");
NexButton p03c04      = NexButton(2, 13, "p03c04");
NexButton p03c05      = NexButton(2, 14, "p03c05");
NexButton p03c06      = NexButton(2, 15, "p03c06");
NexButton p03c07      = NexButton(2, 16, "p03c07");
NexButton p03c08      = NexButton(2, 17, "p03c08");
// page 4
NexPage   p04         = NexPage(  3,  0, "p04");
NexText   p04title    = NexText(  3,  1, "p04title");
NexText   p04temp     = NexText(  3, 18, "p04temp");
NexText   p04humid    = NexText(  3, 19, "p04humid");
NexButton p04settings = NexButton(3,  9, "p04settings");
NexButton p04power    = NexButton(3, 20, "p04power");
NexButton p04t01      = NexButton(3,  2, "p04t01");
NexButton p04t02      = NexButton(3,  3, "p04t02");
NexButton p04t03      = NexButton(3,  4, "p04t03");
NexButton p04t04      = NexButton(3,  5, "p04t04");
NexButton p04t05      = NexButton(3,  6, "p04t05");
NexButton p04t06      = NexButton(3,  7, "p04t06");
NexButton p04t07      = NexButton(3,  8, "p04t07");
NexButton p04c01      = NexButton(3, 10, "p04c01");
NexButton p04c02      = NexButton(3, 11, "p04c02");
NexButton p04c03      = NexButton(3, 12, "p04c03");
NexButton p04c04      = NexButton(3, 13, "p04c04");
NexButton p04c05      = NexButton(3, 14, "p04c05");
NexButton p04c06      = NexButton(3, 15, "p04c06");
NexButton p04c07      = NexButton(3, 16, "p04c07");
NexButton p04c08      = NexButton(3, 17, "p04c08");
// page 5
NexPage   p05         = NexPage(  4,  0, "p05");
NexText   p05title    = NexText(  4,  1, "p05title");
NexText   p05temp     = NexText(  4, 18, "p05temp");
NexText   p05humid    = NexText(  4, 19, "p05humid");
NexButton p05settings = NexButton(4,  9, "p05settings");
NexButton p05power    = NexButton(4, 20, "p05power");
NexButton p05t01      = NexButton(4,  2, "p05t01");
NexButton p05t02      = NexButton(4,  3, "p05t02");
NexButton p05t03      = NexButton(4,  4, "p05t03");
NexButton p05t04      = NexButton(4,  5, "p05t04");
NexButton p05t05      = NexButton(4,  6, "p05t05");
NexButton p05t06      = NexButton(4,  7, "p05t06");
NexButton p05t07      = NexButton(4,  8, "p05t07");
NexButton p05c01      = NexButton(4, 10, "p05c01");
NexButton p05c02      = NexButton(4, 11, "p05c02");
NexButton p05c03      = NexButton(4, 12, "p05c03");
NexButton p05c04      = NexButton(4, 13, "p05c04");
NexButton p05c05      = NexButton(4, 14, "p05c05");
NexButton p05c06      = NexButton(4, 15, "p05c06");
NexButton p05c07      = NexButton(4, 16, "p05c07");
NexButton p05c08      = NexButton(4, 17, "p05c08");
NexButton p05c09      = NexButton(4, 21, "p05c09");
// page 6
NexPage   p06         = NexPage(  5,  0, "p06");
NexText   p06title    = NexText(  5,  1, "p06title");
NexText   p06temp     = NexText(  5, 18, "p06temp");
NexText   p06humid    = NexText(  5, 19, "p06humid");
NexButton p06settings = NexButton(5,  9, "p06settings");
NexButton p06power    = NexButton(5, 20, "p06power");
NexButton p06t01      = NexButton(5,  2, "p06t01");
NexButton p06t02      = NexButton(5,  3, "p06t02");
NexButton p06t03      = NexButton(5,  4, "p06t03");
NexButton p06t04      = NexButton(5,  5, "p06t04");
NexButton p06t05      = NexButton(5,  6, "p06t05");
NexButton p06t06      = NexButton(5,  7, "p06t06");
NexButton p06t07      = NexButton(5,  8, "p06t07");
NexButton p06c01      = NexButton(5, 10, "p06c01");
NexButton p06c02      = NexButton(5, 11, "p06c02");
NexButton p06c03      = NexButton(5, 12, "p06c03");
NexButton p06c04      = NexButton(5, 13, "p06c04");
NexButton p06c05      = NexButton(5, 14, "p06c05");
NexButton p06c06      = NexButton(5, 15, "p06c06");
NexButton p06c07      = NexButton(5, 16, "p06c07");
NexButton p06c08      = NexButton(5, 17, "p06c08");
// page 7
NexPage   p07         = NexPage(  6,  0, "p07");
NexText   p07title    = NexText(  6,  1, "p07title");
NexText   p07temp     = NexText(  6, 18, "p07temp");
NexText   p07humid    = NexText(  6, 19, "p07humid");
NexButton p07settings = NexButton(6,  9, "p07settings");
NexButton p07power    = NexButton(6, 20, "p07power");
NexButton p07t01      = NexButton(6,  2, "p07t01");
NexButton p07t02      = NexButton(6,  3, "p07t02");
NexButton p07t03      = NexButton(6,  4, "p07t03");
NexButton p07t04      = NexButton(6,  5, "p07t04");
NexButton p07t05      = NexButton(6,  6, "p07t05");
NexButton p07t06      = NexButton(6,  7, "p07t06");
NexButton p07t07      = NexButton(6,  8, "p07t07");
NexButton p07c01      = NexButton(6, 10, "p07c01");
NexButton p07c02      = NexButton(6, 14, "p07c02");
NexButton p07c03      = NexButton(6, 21, "p07c03");
NexButton p07c04      = NexButton(6, 25, "p07c04");
NexButton p07c05      = NexButton(6, 11, "p07c05");
NexButton p07c06      = NexButton(6, 15, "p07c06");
NexButton p07c07      = NexButton(6, 22, "p07c07");
NexButton p07c08      = NexButton(6, 26, "p07c08");
NexButton p07c09      = NexButton(6, 12, "p07c09");
NexButton p07c10      = NexButton(6, 16, "p07c10");
NexButton p07c11      = NexButton(6, 23, "p07c11");
NexButton p07c12      = NexButton(6, 27, "p07c12");
NexButton p07c13      = NexButton(6, 13, "p07c13");
NexButton p07c14      = NexButton(6, 17, "p07c14");
NexButton p07c15      = NexButton(6, 24, "p07c15");
NexButton p07c16      = NexButton(6, 28, "p07c16");
// page 8
NexPage   p08         = NexPage(  7,  0, "p08");
NexText   p08title    = NexText(  7,  1, "p08title");
NexText   p08temp     = NexText(  7, 18, "p08temp");
NexText   p08humid    = NexText(  7, 19, "p08humid");
NexButton p08settings = NexButton(7,  9, "p08settings");
NexButton p08power    = NexButton(7, 20, "p08power");
NexButton p08t01      = NexButton(7,  2, "p08t01");
NexButton p08t02      = NexButton(7,  3, "p08t02");
NexButton p08t03      = NexButton(7,  4, "p08t03");
NexButton p08t04      = NexButton(7,  5, "p08t04");
NexButton p08t05      = NexButton(7,  6, "p08t05");
NexButton p08t06      = NexButton(7,  7, "p08t06");
NexButton p08t07      = NexButton(7,  8, "p08t07");
NexButton p08c01      = NexButton(7, 10, "p08c01");
NexButton p08c02      = NexButton(7, 11, "p08c02");
NexButton p08c03      = NexButton(7, 12, "p08c03");
NexButton p08c04      = NexButton(7, 13, "p08c04");
NexButton p08c05      = NexButton(7, 14, "p08c05");
NexButton p08c06      = NexButton(7, 15, "p08c06");
NexButton p08c07      = NexButton(7, 16, "p08c07");
NexButton p08c08      = NexButton(7, 17, "p08c08");
NexText   p08temp02   = NexText(  7, 18, "p08temp02");
NexText   p08humid02  = NexText(  7, 19, "p08humid02");
NexText   p08speed01  = NexText(  7, 31, "p08speed01");

// page 9
NexPage   p09            = NexPage(  8,  0, "p09");
NexText   p09title       = NexText(  8,  1, "p09title");
NexText   p09temp        = NexText(  8, 18, "p09temp");
NexText   p09humid       = NexText(  8, 19, "p09humid");
NexButton p09settings    = NexButton(8, 10, "p09settings");
NexButton p09power       = NexButton(8, 14, "p09power");
NexSlider p09sliderRed   = NexSlider(8, 16, "p09sliderRed");
NexSlider p09sliderGreen = NexSlider(8, 17, "p09sliderGreen");
NexSlider p09sliderBlue  = NexSlider(8, 28, "p09sliderBlue");
NexButton p09redM        = NexButton(8, 11, "p09redM");
NexButton p09redP        = NexButton(8, 21, "p09redP");
NexButton p09greenM      = NexButton(8, 23, "p09greenM");
NexButton p09greenP      = NexButton(8, 24, "p09greenP");
NexButton p09blueM       = NexButton(8, 26, "p09blueM");
NexButton p09blueP       = NexButton(8, 27, "p09blueP");
NexText   p09red         = NexText(  8, 15, "p09red");
NexText   p09green       = NexText(  8, 22, "p09green");
NexText   p09blue        = NexText(  8, 25, "p09blue");
NexButton p09save1       = NexButton(8, 29, "p09save1");
NexButton p09load1       = NexButton(8, 31, "p09load1");
NexButton p09save2       = NexButton(8, 30, "p09save2");
NexButton p09load2       = NexButton(8, 32, "p09load2");
