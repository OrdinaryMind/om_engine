﻿#include <h_animation_value_setter.h>

#include <QRect>

using namespace om_animation;

HAnimationValueSetter::HAnimationValueSetter(
    AnimationValueSetter::AnimationSet *animation_set,
    unsigned int slide_direction)
    : AnimationValueSetter(animation_set, slide_direction) {}

HAnimationValueSetter::~HAnimationValueSetter() {}

void HAnimationValueSetter::DetermineStartXPosition() {
  if (slide_direction_ == kFromLeftToRight) {
    unsigned int x_of_first_widget = animation_set_->first().first->x();
    start_x_pos_ = x_of_first_widget;
  }
  // if (slide_direction_ == kFromRightToLeft) {}
}

void HAnimationValueSetter::SetStartValue() {
  if (!animation_set_->isEmpty()) {
    DetermineStartXPosition();

    if (slide_direction_ == kFromLeftToRight) {
      for (auto &pair : *animation_set_) {
        pair.second->setStartValue(
            QRect(start_x_pos_, pair.first->y(), 0, pair.first->height()));
      }
    }
  }
}

void HAnimationValueSetter::SetEndValue() {
  if (!animation_set_->isEmpty()) {
    if (slide_direction_ == kFromLeftToRight) {
      unsigned int count = 0;

      for (auto &pair : *animation_set_) {
        if (count == 0) {
          pair.second->setEndValue(QRect(start_x_pos_, pair.first->y(),
                                         pair.first->width(),
                                         pair.first->height()));
        } else {
          unsigned int x_position = start_x_pos_;
          for (auto it = animation_set_->begin();
               it < animation_set_->begin() + count; ++it) {
            x_position += it->first->width() + 5;  // <-- MARGIN
          }
          pair.second->setEndValue(QRect(x_position, pair.first->y(),
                                         pair.first->width(),
                                         pair.first->height()));
          x_position = start_x_pos_;
        }

        ++count;
      }
    }
  }
}
