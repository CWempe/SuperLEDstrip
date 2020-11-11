/* FastLED_RGBW
 * 
 * Hack to enable SK6812 RGBW strips to work with FastLED.
 *
 * Original code by Jim Bumgardner (http://krazydad.com).
 * Modified by David Madison (http://partsnotincluded.com).
 * Extended by Christoph Wempe
 * 
*/

#ifndef FastLED_RGBW_h
#define FastLED_RGBW_h


/// scale four one byte values by a fith one, which is treated as
///         the numerator of a fraction whose demominator is 256
///         In other words, it computes r,g,b,w * (scale / 256)
///
///         THIS FUNCTION ALWAYS MODIFIES ITS ARGUMENTS IN PLACE

LIB8STATIC void nscale8x4( uint8_t& r, uint8_t& g, uint8_t& b, uint8_t& w, fract8 scale)
{
#if SCALE8_C == 1
#if (FASTLED_SCALE8_FIXED == 1)
  uint16_t scale_fixed = scale + 1;
  r = (((uint16_t)r) * scale_fixed) >> 8;
  g = (((uint16_t)g) * scale_fixed) >> 8;
  b = (((uint16_t)b) * scale_fixed) >> 8;
  w = (((uint16_t)w) * scale_fixed) >> 8;
#else
  r = ((int)r * (int)(scale) ) >> 8;
  g = ((int)g * (int)(scale) ) >> 8;
  b = ((int)b * (int)(scale) ) >> 8;
  w = ((int)w * (int)(scale) ) >> 8;
#endif
#elif SCALE8_AVRASM == 1
  r = scale8_LEAVING_R1_DIRTY(r, scale);
  g = scale8_LEAVING_R1_DIRTY(g, scale);
  b = scale8_LEAVING_R1_DIRTY(b, scale);
  w = scale8_LEAVING_R1_DIRTY(w, scale);
  cleanup_R1();
#else
#error "No implementation for nscale8x3 available."
#endif
}


struct CRGBW  {
	union {
		struct {
			union {
				uint8_t g;
				uint8_t green;
			};
			union {
				uint8_t r;
				uint8_t red;
			};
			union {
				uint8_t b;
				uint8_t blue;
			};
			union {
				uint8_t w;
				uint8_t white;
			};
		};
		uint8_t raw[4];
	};

	CRGBW(){}

	CRGBW(uint8_t rd, uint8_t grn, uint8_t blu, uint8_t wht){
		r = rd;
		g = grn;
		b = blu;
		w = wht;
	}

	inline void operator = (const CRGB c) __attribute__((always_inline)){ 
		this->r = c.r;
		this->g = c.g;
		this->b = c.b;
		this->white = 0;
	}

  /// add one RGBW to another, saturating at 0xFF for each channel
  inline CRGBW& operator+= (const CRGB& rhs )
  {
    r = qadd8( r, rhs.r);
    g = qadd8( g, rhs.g);
    b = qadd8( b, rhs.b);
    w = 0;
    return *this;
  }

  /// scale down a RGBW to N 256ths of it's current brightness, using
  /// 'plain math' dimming rules, which means that if the low light levels
  /// may dim all the way to 100% black.
  inline CRGBW& nscale8 (uint8_t scaledown )
  {
    nscale8x4( r, g, b, w, scaledown);
    return *this;
  }

  /// scale down a RGBW to N 256ths of it's current brightness, using
  /// 'plain math' dimming rules, which means that if the low light levels
  /// may dim all the way to 100% black.
  inline CRGBW& nscale8 (const CRGBW & scaledown )
  {
    r = ::scale8(r, scaledown.r);
    g = ::scale8(g, scaledown.g);
    b = ::scale8(b, scaledown.b);
    w = 0;
    return *this;
  }
};


inline uint16_t getRGBWsize(uint16_t nleds){
	uint16_t nbytes = nleds * 4;
	if(nbytes % 3 > 0) return nbytes / 3 + 1;
	else return nbytes / 3;
}

void fill_solid( struct CRGBW * leds, int numToFill, CRGB color)
{
  for( int i = 0; i < numToFill; i++) {
    leds[i] = color;
  }
}

void nscale8( CRGBW* leds, uint16_t num_leds, uint8_t scale)
{
  for( uint16_t i = 0; i < num_leds; i++) {
      leds[i].nscale8( scale);
  }
}

void fadeToBlackBy( CRGBW* leds, uint16_t num_leds, uint8_t fadeBy)
{
    nscale8( leds, num_leds, 255 - fadeBy);
}

void fill_rainbow( struct CRGBW * pFirstLED, int numToFill,
                  uint8_t initialhue,
                  uint8_t deltahue )
{
    CHSV hsv;
    hsv.hue = initialhue;
    hsv.val = 255;
    hsv.sat = 240;
    for( int i = 0; i < numToFill; i++) {
        pFirstLED[i] = hsv;
        hsv.hue += deltahue;
    }
}

#endif