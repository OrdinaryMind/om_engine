﻿#ifndef OM_TIME_LABEL_H
#define OM_TIME_LABEL_H

#include <abstract_time_and_date.h>

namespace om_widgets {
class OmTimeLabel : public AbstractTimeAndDate {
 public:
  OmTimeLabel(QLabel* parent = nullptr);
  ~OmTimeLabel();

  void Update() override;

 private:
};
}
#endif  // OM_TIME_LABEL_H