/*
 * Functions and commands to use digital outputs
 */

//
// Output01
//
#ifdef OUTPUT01_PIN
  HomieNode output01Node("output01", "switch");

  // output01_on
  void publishOutput01on() {
    if ( !HOMIE_STANDALONE ) output01Node.setProperty("on").send(output01_on ? "true" : "false");
  }

  void updateOutput01on(String value, bool write = true) {
    output01_on = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: output01_on: " << output01_on << endl;
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
    if ( !HOMIE_STANDALONE ) output01Node.setProperty("invert").send(output01_invert ? "true" : "false");
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
    if ( !HOMIE_STANDALONE ) output02Node.setProperty("on").send(output02_on ? "true" : "false");
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
    if ( !HOMIE_STANDALONE ) output02Node.setProperty("invert").send(output02_invert ? "true" : "false");
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