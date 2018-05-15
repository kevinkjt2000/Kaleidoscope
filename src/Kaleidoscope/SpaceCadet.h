/* -*- mode: c++ -*-
 * Kaleidoscope-SpaceCadet -- Space Cadet Shift Extended
 * Copyright (C) 2016, 2017, 2018  Gergely Nagy, Ben Gemperline
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-Ranges.h>

#ifndef SPACECADET_MAP_END
#define SPACECADET_MAP_END (kaleidoscope::SpaceCadet::KeyBinding) { Key_NoKey, Key_NoKey, 0 }
#endif

#define Key_SpaceCadetEnable (Key) { .raw = kaleidoscope::ranges::SC_FIRST }
#define Key_SpaceCadetDisable (Key) { .raw = kaleidoscope::ranges::SC_LAST }

namespace kaleidoscope {

class SpaceCadet : public kaleidoscope::Plugin {
 public:
  //Internal Class
  //Declarations for the modifier key mapping
  class KeyBinding {
   public:
    //Empty constructor; set the vars separately
    KeyBinding(void) {}
    //Constructor with input and output
    KeyBinding(Key input_, Key output_);
    //Constructor with all three set
    KeyBinding(Key input_, Key output_, uint16_t timeout_);
    //The key that is pressed
    Key input;
    //the key that is sent
    Key output;
    //The timeout (default to global timeout)
    uint16_t timeout = 0;
    //The flag (set to 0)
    bool flagged = false;
    //the start time for this key press
    uint32_t start_time = 0;
  };

  SpaceCadet(void);

  //Methods
  static void enable(void);
  static void disable(void);
  static bool active(void);

  //Publically accessible variables
  static uint16_t time_out;  //  The global timeout in milliseconds
  static SpaceCadet::KeyBinding * map;  // The map of key bindings

  EventHandlerResult onKeyswitchEvent(Key &mapped_key, byte row, byte col, uint8_t key_state);

#if KALEIDOSCOPE_ENABLE_V1_PLUGIN_API
 protected:
  void begin();
  static Key legacyEventHandler(Key mapped_key, byte row, byte col, uint8_t key_state);
#endif

 private:
  static bool disabled;
};
};

extern kaleidoscope::SpaceCadet SpaceCadet;
