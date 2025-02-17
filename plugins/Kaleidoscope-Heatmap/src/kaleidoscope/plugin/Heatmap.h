/* -*- mode: c++ -*-
 * Kaleidoscope-Heatmap -- Heatmap LED effect for Kaleidoscope.
 * Copyright (C) 2016, 2017, 2018  Keyboard.io, Inc.
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

#include "kaleidoscope/KeyEvent.h"                       // for KeyEvent
#include "kaleidoscope/Runtime.h"                        // for Runtime, Run...
#include "kaleidoscope/device/device.h"                  // for cRGB, Device
#include "kaleidoscope/event_handler_result.h"           // for EventHandler...
#include "kaleidoscope/plugin.h"                         // for Plugin
#include "kaleidoscope/plugin/AccessTransientLEDMode.h"  // for AccessTransi...
#include "kaleidoscope/plugin/LEDMode.h"                 // for LEDMode
#include "kaleidoscope/plugin/LEDModeInterface.h"        // for LEDModeInter...

namespace kaleidoscope {
namespace plugin {
class Heatmap : public Plugin,
                public LEDModeInterface,
                public AccessTransientLEDMode {
 public:
  Heatmap(void) {}

  static uint16_t update_delay;
  static const cRGB *heat_colors;
  static uint8_t heat_colors_length;
  void resetMap(void);

  EventHandlerResult onKeyEvent(KeyEvent &event);
  EventHandlerResult beforeEachCycle();

  // This class' instance has dynamic lifetime
  //
  class TransientLEDMode : public LEDMode {
   public:
    // Please note that storing the parent ptr is only required
    // for those LED modes that require access to
    // members of their parent class. Most LED modes can do without.
    //
    explicit TransientLEDMode(const Heatmap *parent);

    void resetMap();
    EventHandlerResult onKeyEvent(KeyEvent &event);
    EventHandlerResult beforeEachCycle();

   protected:
    void update() final;

   private:
    uint16_t heatmap_[Runtime.device().numKeys()];
    uint16_t highest_;
    uint16_t last_heatmap_comp_time_;

    void shiftStats(void);
    cRGB computeColor(float v);

    friend class Heatmap;
  };
};

}  // namespace plugin
}  // namespace kaleidoscope

extern kaleidoscope::plugin::Heatmap HeatmapEffect;
