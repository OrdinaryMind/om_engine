﻿#ifndef H_ANIMATION_VALUE_SETTER_H
#define H_ANIMATION_VALUE_SETTER_H

#include <animation_value_setter.h>

namespace om_animation {

struct HAnimationValueSetter : public AnimationValueSetter {
  enum SlideDirection { kFromLeftToRight, kFromRightToLeft };

  HAnimationValueSetter(AnimationSet *animation_set = nullptr,
                        unsigned int slide_direction = kFromLeftToRight);
  ~HAnimationValueSetter();

  void SetStartValue() override;
  void SetEndValue() override;
};
}

#endif  // H_ANIMATION_VALUE_SETTER_H