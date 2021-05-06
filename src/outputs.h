/*
 * Functions and commands to use digital outputs
 */

//
// Output01
//
#ifdef OUTPUT01_PIN
  HomieNode output01Node("output01", "output01Node", "switch");

  // output01_on
  void publishOutput01on() {
    if (Homie.isConnected()) output01Node.setProperty("on").send(output01_on ? "true" : "false");
  }

  void updateOutput01on(String value, bool write = true) {
    #ifdef RELAIS_ALWAYS_ON
      output01_on = true;
      if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] NO UPDATE: output01_on: " << output01_on << endl;
    #else
      output01_on = (value == "true" || value == String(true));
      if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: output01_on: " << output01_on << endl;
    #endif
    // set output; consider output01_invert
    digitalWrite(OUTPUT01_PIN, (output01_on == !output01_invert) ? HIGH : LOW);
    publishOutput01on();
    if (write) writeEeepromOutput01on();
  }

  bool output01OnHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateOutput01on(value);
    return true;
  }

  // output01_invert
  void publishOutput01invert() {
    if (Homie.isConnected()) output01Node.setProperty("invert").send(output01_invert ? "true" : "false");
  }

  void updateOutput01invert(String value, bool write = true) {
    output01_invert = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: output01_invert: " << output01_invert << endl;
    publishOutput01invert();
    if (write) writeEeepromOutput01invert();
  }

  bool output01invertHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateOutput01invert(value);
    return true;
  }

  // Setup
  void HomieSetupOutput01() {
    pinMode(OUTPUT01_PIN, OUTPUT);
    digitalWrite(OUTPUT01_PIN, HIGH);
    output01Node.advertise("on").settable(output01OnHandler);
    output01Node.advertise("invert").settable(output01invertHandler);

    readEepromOutput01on();
    readEepromOutput01invert();
  }
#endif

//
// Output02
//
#ifdef OUTPUT02_PIN
  HomieNode output02Node("output02", "switch");

  // output02_on
  void publishOutput02on() {
    if (Homie.isConnected()) output02Node.setProperty("on").send(output02_on ? "true" : "false");
  }

  void updateOutput02on(String value, bool write = true) {
    output02_on = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: output02_on: " << output02_on << endl;
    // set output; consider output02_invert
    digitalWrite(OUTPUT02_PIN, (output02_on == !output02_invert) ? HIGH : LOW);
    publishOutput02on();
    if (write) writeEeepromOutput02on();
  }

  bool output02OnHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateOutput02on(value);
    return true;
  }

  // output02_invert
  void publishOutput02invert() {
    if (Homie.isConnected()) output02Node.setProperty("invert").send(output02_invert ? "true" : "false");
  }

  void updateOutput02invert(String value, bool write = true) {
    output02_invert = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: output02_invert: " << output02_invert << endl;
    publishOutput02invert();
    if (write) writeEeepromOutput02invert();
  }

  bool output02invertHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateOutput02invert(value);
    return true;
  }

  // Setup
  void HomieSetupOutput02() {
    pinMode(OUTPUT02_PIN, OUTPUT);
    digitalWrite(OUTPUT02_PIN, HIGH);
    output02Node.advertise("on").settable(output02OnHandler);
    output02Node.advertise("invert").settable(output02invertHandler);

    readEepromOutput02on();
    readEepromOutput02invert();
  }
#endif

//
// Output03
//
#ifdef OUTPUT03_PIN
  HomieNode output03Node("output03", "switch");

  // output03_on
  void publishOutput03on() {
    if (Homie.isConnected()) output03Node.setProperty("on").send(output03_on ? "true" : "false");
  }

  void updateOutput03on(String value, bool write = true) {
    output03_on = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: output03_on: " << output03_on << endl;
    // set output; consider output03_invert
    digitalWrite(OUTPUT03_PIN, (output03_on == !output03_invert) ? HIGH : LOW);
    publishOutput03on();
    if (write) writeEeepromOutput03on();
  }

  bool output03OnHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateOutput03on(value);
    return true;
  }

  // output03_invert
  void publishOutput03invert() {
    if (Homie.isConnected()) output03Node.setProperty("invert").send(output03_invert ? "true" : "false");
  }

  void updateOutput03invert(String value, bool write = true) {
    output03_invert = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: output03_invert: " << output03_invert << endl;
    publishOutput03invert();
    if (write) writeEeepromOutput03invert();
  }

  bool output03invertHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateOutput03invert(value);
    return true;
  }

  // Setup
  void HomieSetupOutput03() {
    pinMode(OUTPUT03_PIN, OUTPUT);
    digitalWrite(OUTPUT03_PIN, HIGH);
    output03Node.advertise("on").settable(output03OnHandler);
    output03Node.advertise("invert").settable(output03invertHandler);

    readEepromOutput03on();
    readEepromOutput03invert();
  }
#endif

//
// Output04
//
#ifdef OUTPUT04_PIN
  HomieNode output04Node("output04", "switch");

  // output04_on
  void publishOutput04on() {
    if (Homie.isConnected()) output04Node.setProperty("on").send(output04_on ? "true" : "false");
  }

  void updateOutput04on(String value, bool write = true) {
    output04_on = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: output04_on: " << output04_on << endl;
    // set output; consider output04_invert
    digitalWrite(OUTPUT04_PIN, (output04_on == !output04_invert) ? HIGH : LOW);
    publishOutput04on();
    if (write) writeEeepromOutput04on();
  }

  bool output04OnHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateOutput04on(value);
    return true;
  }

  // output04_invert
  void publishOutput04invert() {
    if (Homie.isConnected()) output04Node.setProperty("invert").send(output04_invert ? "true" : "false");
  }

  void updateOutput04invert(String value, bool write = true) {
    output04_invert = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: output04_invert: " << output04_invert << endl;
    publishOutput04invert();
    if (write) writeEeepromOutput04invert();
  }

  bool output04invertHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateOutput04invert(value);
    return true;
  }

  // Setup
  void HomieSetupOutput04() {
    pinMode(OUTPUT04_PIN, OUTPUT);
    digitalWrite(OUTPUT04_PIN, HIGH);
    output04Node.advertise("on").settable(output04OnHandler);
    output04Node.advertise("invert").settable(output04invertHandler);

    readEepromOutput04on();
    readEepromOutput04invert();
  }
#endif