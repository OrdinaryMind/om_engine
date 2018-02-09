﻿#include <h_sliding_widget_set.h>

#include <QRect>
#include <QWidget>

using namespace om_animaiton;

HSlidingWidgetSet::HSlidingWidgetSet(QWidget *parent, bool is_set_open,
                                     SlideDirection slide_direction)
    : AbstractSlidingWidgetSet(parent, is_set_open),
      slide_direction_(slide_direction) {}

HSlidingWidgetSet::~HSlidingWidgetSet() {}

void HSlidingWidgetSet::SetStartAnimationPosition() {
  DetermineStartXPosition();

  if (slide_direction_ == kFromLeftToRight) {
    for (auto &pair : *GetAnimationSet()) {
      pair.second->setStartValue(
          QRect(start_x_position_, pair.first->y(), 0, pair.first->height()));
    }
  }
}

void HSlidingWidgetSet::SetEndAnimationPosition() {}

void HSlidingWidgetSet::DetermineStartXPosition() {
  if (slide_direction_ == kFromLeftToRight) {
    unsigned int x_of_first_widget = GetAnimationSet()[0].first().first->x();
    start_x_position_ = x_of_first_widget;
  }
  if (slide_direction_ == kFromRightToLeft) {
    unsigned int x_of_last_widget = GetAnimationSet()->last().first->x();
    unsigned int width_of_last_widget =
        GetAnimationSet()->last().first->width();

    start_x_position_ = x_of_last_widget + width_of_last_widget;
  }
}
