﻿#ifndef H_SLIDER_BOX_H
#define H_SLIDER_BOX_H

#include <abstract_sliding_box.h>

namespace om_animation {

class HSliderBox : public AbstractSlidingBox {
 public:
  enum SliderDirection { kFromLeftToRight, kFromRightToLeft };

 private:
};
}
#endif  // H_SLIDER_BOX_H