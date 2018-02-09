﻿#ifndef ABSTRACT_SLIDING_WIDGET_SET_H
#define ABSTRACT_SLIDING_WIDGET_SET_H

#include <QObject>
#include <QPair>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QVector>

class QWidget;

namespace om_animaiton {

class AbstractSlidingWidgetSet : public QObject {
  Q_OBJECT
 public:
  enum SetCondition { kOpen, kClosed };

  AbstractSlidingWidgetSet(QWidget* parent = nullptr);
  ~AbstractSlidingWidgetSet();

 protected:
  virtual void SetStartAnimationPosition() = 0;
  virtual void SetEndAnimationPosition() = 0;

 private:
  QParallelAnimationGroup* animation_group_ = nullptr;

  QVector<QPair<QWidget*, QPropertyAnimation*>> animation_set_;
};
}

#endif  // ABSTRACT_SLIDING_WIDGET_SET_H
