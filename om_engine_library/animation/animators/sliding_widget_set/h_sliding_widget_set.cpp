﻿#include <h_sliding_widget_set.h>

#include <QRect>
#include <QVariant>
#include <QWidget>

#include <h_animation_value_setter.h>

using namespace om_animation;

HSlidingWidgetSet::HSlidingWidgetSet(QWidget *parent,
                                     SlideDirection slide_direction,
                                     unsigned int distance_between_widgets_px,
                                     bool is_set_open)
    : AbstractSlidingWidgetSet(parent, is_set_open),
      value_setter_(new HAnimationValueSetter(GetDirectAnimationSet(),
                                              slide_direction,
                                              distance_between_widgets_px))

{}

HSlidingWidgetSet::~HSlidingWidgetSet() {}

void HSlidingWidgetSet::SetDirectAnimation() {
  value_setter_->SetDirectStartValue();
  value_setter_->SetDirectEndValue();
}
