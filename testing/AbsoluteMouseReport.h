/* -*- mode: c++ -*-
 * Copyright (C) 2020  Eric Paniagua (epaniagua@google.com)
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

#include <cstdint>
#include <vector>

#include "DeviceAPIs/AbsoluteMouseAPI.h"
#include "HID-Settings.h"

namespace kaleidoscope {
namespace testing {

class AbsoluteMouseReport {
 public:
  typedef HID_MouseAbsoluteReport_Data_t ReportData;

  static constexpr uint8_t kHidReportType = HID_REPORTID_MOUSE_ABSOLUTE;

  AbsoluteMouseReport(const void *data);

  uint32_t Timestamp() const;
  std::vector<uint8_t> Buttons() const;
  uint16_t XAxis() const;
  uint16_t YAxis() const;
  int8_t Wheel() const;

 private:
  uint32_t timestamp_;
  ReportData report_data_;
};

}  // namespace testing
}  // namespace kaleidoscope
