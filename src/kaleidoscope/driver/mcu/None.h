/* -*- mode: c++ -*-
 * driver::MCU::None -- Dummy MCU driver for Kaleidoscope
 * Copyright (C) 2019, 2020  Keyboard.io, Inc
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

#include "kaleidoscope/driver/mcu/Base.h"  // for Base, BaseProps (ptr only)

namespace kaleidoscope {
namespace driver {
namespace mcu {

/*
 * The purpose of this class is to serve as a default inside the base
 * `kaleidoscope::device::Base` class, with a name more descriptive than
 * `mcu::Base`. In practice, one shouldn't use it, and should override the
 * MCU in the device description.
 */
class None : public kaleidoscope::driver::mcu::Base<BaseProps> {};

}  // namespace mcu
}  // namespace driver
}  // namespace kaleidoscope
