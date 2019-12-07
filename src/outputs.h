/*
 * Functions and commands to use digital outputs
 */

//
// Output01
//
#ifdef OUTPUT01_PIN
  HomieNode output01Node("output01", "switch");

  bool output01OnHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    bool on = (value == "true");
    // set output; consider output01_invert
    digitalWrite(OUTPUT01_PIN, (on == !output01_invert) ? HIGH : LOW);
    if ( !HOMIE_STANDALONE ) { output01Node.setProperty("on").send(value); };
    return true;
  }

  bool output01invertHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    output01_invert = (value == "true");
    if ( !HOMIE_STANDALONE ) { output01Node.setProperty("invert").send(value); };
    writeEeepromOutput01invert();
    return true;
  }

  void HomieSetupOutput01() {
    pinMode(OUTPUT01_PIN, OUTPUT);
    digitalWrite(OUTPUT01_PIN, HIGH);
    output01Node.advertise("on").settable(output01OnHandler);
    output01Node.advertise("invert").settable(output01invertHandler);

    readEepromOutput01invert();
  }
#endif