/* -*- mode: c++ -*-
 * Kaleidoscope-FingerPainter -- On-the-fly keyboard painting.
 * Copyright (C) 2017-2021  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>  // for uint16_t

#include "kaleidoscope/KeyAddr.h"               // for KeyAddr
#include "kaleidoscope/KeyEvent.h"              // for KeyEvent
#include "kaleidoscope/event_handler_result.h"  // for EventHandlerResult
#include "kaleidoscope/plugin/LEDMode.h"        // for LEDMode

namespace kaleidoscope {
namespace plugin {

// This class is implemented as a persistent LED mode
// as there is no benefit of transforming it into a dynamic
// LED mode in terms of PROGMEM or RAM.
//
class FingerPainter : public LEDMode {
 public:
  FingerPainter(void) {}

  static void toggle(void);

  EventHandlerResult onKeyEvent(KeyEvent &event);
  EventHandlerResult onFocusEvent(const char *command);
  EventHandlerResult onSetup();
  EventHandlerResult onNameQuery();

 protected:
  void update(void) final;
  void refreshAt(KeyAddr key_addr) final;

 private:
  static uint16_t color_base_;
  static bool edit_mode_;
};

}  // namespace plugin
}  // namespace kaleidoscope

extern kaleidoscope::plugin::FingerPainter FingerPainter;
