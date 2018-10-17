// Nextion components inizialization
// global
void NextionSetup()
{
    nexInit();
    // page 1
    p01.attachPop(p01PopCallback);
    title.attachPop(titlePopCallback);
    temp.attachPop(titlePopCallback);
    humid.attachPop(titlePopCallback);
    p01title.attachPop(p01titlePopCallback);
    p01temp.attachPop(p01tempPopCallback);
    p01humid.attachPop(p01humidPopCallback);
    p01settings.attachPop(p01settingsPopCallback);
    p01power.attachPop(p01powerPopCallback);
    p01t01.attachPop(p01t01PopCallback);
    p01t02.attachPop(p01t02PopCallback);
    p01t03.attachPop(p01t03PopCallback);
    p01t04.attachPop(p01t04PopCallback);
    p01t05.attachPop(p01t05PopCallback);
    p01t06.attachPop(p01t06PopCallback);
    p01t07.attachPop(p01t07PopCallback);
    p01c01.attachPop(p01c01PopCallback);
    p01c02.attachPop(p01c02PopCallback);
    p01c03.attachPop(p01c03PopCallback);
    p01c04.attachPop(p01c04PopCallback);
    p01c05.attachPop(p01c05PopCallback);
    p01c06.attachPop(p01c06PopCallback);
    p01c07.attachPop(p01c07PopCallback);
    p01c08.attachPop(p01c08PopCallback);
    p01c09.attachPop(p01c09PopCallback);
    // page 2
    p02.attachPop(p02PopCallback);
    p02title.attachPop(p02titlePopCallback);
    p02temp.attachPop(p02tempPopCallback);
    p02humid.attachPop(p02humidPopCallback);
    p02settings.attachPop(p02settingsPopCallback);
    p02power.attachPop(p02powerPopCallback);
    p02t01.attachPop(p02t01PopCallback);
    p02t02.attachPop(p02t02PopCallback);
    p02t03.attachPop(p02t03PopCallback);
    p02t04.attachPop(p02t04PopCallback);
    p02t05.attachPop(p02t05PopCallback);
    p02t06.attachPop(p02t06PopCallback);
    p02t07.attachPop(p02t07PopCallback);
    p02c01.attachPop(p02c01PopCallback);
    p02c02.attachPop(p02c02PopCallback);
    p02c03.attachPop(p02c03PopCallback);
    p02c04.attachPop(p02c04PopCallback);
    p02c05.attachPop(p02c05PopCallback);
    p02c06.attachPop(p02c06PopCallback);
    p02c07.attachPop(p02c07PopCallback);
    p02c08.attachPop(p02c08PopCallback);
    // page 3
    p03.attachPop(p03PopCallback);
    p03title.attachPop(p03titlePopCallback);
    p03temp.attachPop(p03tempPopCallback);
    p03humid.attachPop(p03humidPopCallback);
    p03settings.attachPop(p03settingsPopCallback);
    p03power.attachPop(p03powerPopCallback);
    p03t01.attachPop(p03t01PopCallback);
    p03t02.attachPop(p03t02PopCallback);
    p03t03.attachPop(p03t03PopCallback);
    p03t04.attachPop(p03t04PopCallback);
    p03t05.attachPop(p03t05PopCallback);
    p03t06.attachPop(p03t06PopCallback);
    p03t07.attachPop(p03t07PopCallback);
    p03c01.attachPop(p03c01PopCallback);
    p03c02.attachPop(p03c02PopCallback);
    p03c03.attachPop(p03c03PopCallback);
    p03c04.attachPop(p03c04PopCallback);
    p03c05.attachPop(p03c05PopCallback);
    p03c06.attachPop(p03c06PopCallback);
    p03c07.attachPop(p03c07PopCallback);
    p03c08.attachPop(p03c08PopCallback);
    // page 4
    p04.attachPop(p04PopCallback);
    p04title.attachPop(p04titlePopCallback);
    p04temp.attachPop(p04tempPopCallback);
    p04humid.attachPop(p04humidPopCallback);
    p04settings.attachPop(p04settingsPopCallback);
    p04power.attachPop(p04powerPopCallback);
    p04t01.attachPop(p04t01PopCallback);
    p04t02.attachPop(p04t02PopCallback);
    p04t03.attachPop(p04t03PopCallback);
    p04t04.attachPop(p04t04PopCallback);
    p04t05.attachPop(p04t05PopCallback);
    p04t06.attachPop(p04t06PopCallback);
    p04t07.attachPop(p04t07PopCallback);
    p04c01.attachPop(p04c01PopCallback);
    p04c02.attachPop(p04c02PopCallback);
    p04c03.attachPop(p04c03PopCallback);
    p04c04.attachPop(p04c04PopCallback);
    p04c05.attachPop(p04c05PopCallback);
    p04c06.attachPop(p04c06PopCallback);
    p04c07.attachPop(p04c07PopCallback);
    p04c08.attachPop(p04c08PopCallback);
    // page 5
    p05.attachPop(p05PopCallback);
    p05title.attachPop(p05titlePopCallback);
    p05temp.attachPop(p05tempPopCallback);
    p05humid.attachPop(p05humidPopCallback);
    p05settings.attachPop(p05settingsPopCallback);
    p05power.attachPop(p05powerPopCallback);
    p05t01.attachPop(p05t01PopCallback);
    p05t02.attachPop(p05t02PopCallback);
    p05t03.attachPop(p05t03PopCallback);
    p05t04.attachPop(p05t04PopCallback);
    p05t05.attachPop(p05t05PopCallback);
    p05t06.attachPop(p05t06PopCallback);
    p05t07.attachPop(p05t07PopCallback);
    p05c01.attachPop(p05c01PopCallback);
    p05c02.attachPop(p05c02PopCallback);
    p05c03.attachPop(p05c03PopCallback);
    p05c04.attachPop(p05c04PopCallback);
    p05c05.attachPop(p05c05PopCallback);
    p05c06.attachPop(p05c06PopCallback);
    p05c07.attachPop(p05c07PopCallback);
    p05c08.attachPop(p05c08PopCallback);
    p05c09.attachPop(p05c09PopCallback);
    // page 6
    p06.attachPop(p06PopCallback);
    p06title.attachPop(p06titlePopCallback);
    p06temp.attachPop(p06tempPopCallback);
    p06humid.attachPop(p06humidPopCallback);
    p06settings.attachPop(p06settingsPopCallback);
    p06power.attachPop(p06powerPopCallback);
    p06t01.attachPop(p06t01PopCallback);
    p06t02.attachPop(p06t02PopCallback);
    p06t03.attachPop(p06t03PopCallback);
    p06t04.attachPop(p06t04PopCallback);
    p06t05.attachPop(p06t05PopCallback);
    p06t06.attachPop(p06t06PopCallback);
    p06t07.attachPop(p06t07PopCallback);
    p06c01.attachPop(p06c01PopCallback);
    p06c02.attachPop(p06c02PopCallback);
    p06c03.attachPop(p06c03PopCallback);
    p06c04.attachPop(p06c04PopCallback);
    p06c05.attachPop(p06c05PopCallback);
    p06c06.attachPop(p06c06PopCallback);
    p06c07.attachPop(p06c07PopCallback);
    p06c08.attachPop(p06c08PopCallback);
    // page 7
    p07.attachPop(p07PopCallback);
    p07title.attachPop(p07titlePopCallback);
    p07temp.attachPop(p07tempPopCallback);
    p07humid.attachPop(p07humidPopCallback);
    p07settings.attachPop(p07settingsPopCallback);
    p07power.attachPop(p07powerPopCallback);
    p07t01.attachPop(p07t01PopCallback);
    p07t02.attachPop(p07t02PopCallback);
    p07t03.attachPop(p07t03PopCallback);
    p07t04.attachPop(p07t04PopCallback);
    p07t05.attachPop(p07t05PopCallback);
    p07t06.attachPop(p07t06PopCallback);
    p07t07.attachPop(p07t07PopCallback);
    p07c01.attachPop(p07c01PopCallback);
    p07c02.attachPop(p07c02PopCallback);
    p07c03.attachPop(p07c03PopCallback);
    p07c04.attachPop(p07c04PopCallback);
    p07c05.attachPop(p07c05PopCallback);
    p07c06.attachPop(p07c06PopCallback);
    p07c07.attachPop(p07c07PopCallback);
    p07c08.attachPop(p07c08PopCallback);
    // page 8
    p08.attachPop(p08PopCallback);
    p08title.attachPop(p08titlePopCallback);
    p08temp.attachPop(p08tempPopCallback);
    p08humid.attachPop(p08humidPopCallback);
    p08settings.attachPop(p08settingsPopCallback);
    p08power.attachPop(p08powerPopCallback);
    p08t01.attachPop(p08t01PopCallback);
    p08t02.attachPop(p08t02PopCallback);
    p08t03.attachPop(p08t03PopCallback);
    p08t04.attachPop(p08t04PopCallback);
    p08t05.attachPop(p08t05PopCallback);
    p08t06.attachPop(p08t06PopCallback);
    p08t07.attachPop(p08t07PopCallback);
    p08c01.attachPop(p08c01PopCallback);
    p08c02.attachPop(p08c02PopCallback);
    p08c03.attachPop(p08c03PopCallback);
    p08c04.attachPop(p08c04PopCallback);
    p08c05.attachPop(p08c05PopCallback);
    p08c06.attachPop(p08c06PopCallback);
    p08c07.attachPop(p08c07PopCallback);
    p08c08.attachPop(p08c08PopCallback);
    p08temp02.attachPop(p08tempPopCallback);
    p08humid02.attachPop(p08humidPopCallback);
    p08speed01.attachPop(p08speed01PopCallback);
    // page 9
    p09.attachPop(p09PopCallback);
    p09title.attachPop(p09titlePopCallback);
    p09temp.attachPop(p09tempPopCallback);
    p09humid.attachPop(p09humidPopCallback);
    p09settings.attachPop(p09settingsPopCallback);
    p09power.attachPop(p09powerPopCallback);
    p09sliderRed.attachPop(p09sliderRedPopCallback);
    p09sliderRed.attachPush(p09sliderRedPushCallback);
    p09sliderGreen.attachPop(p09sliderGreenPopCallback);
    p09sliderGreen.attachPush(p09sliderGreenPushCallback);
    p09sliderBlue.attachPop(p09sliderBluePopCallback);
    p09sliderBlue.attachPush(p09sliderBluePushCallback);
    //
    dbSerialPrintln("setup done");
}

