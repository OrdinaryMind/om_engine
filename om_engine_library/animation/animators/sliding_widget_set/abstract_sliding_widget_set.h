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
  AbstractSlidingWidgetSet(QWidget* parent = nullptr, bool is_set_open = false);
  ~AbstractSlidingWidgetSet();

  bool Add(QWidget* widget);

  bool IsSetOpen() const;

 protected:
  virtual void SetStartAnimationPosition() = 0;
  virtual void SetEndAnimationPosition() = 0;

 private:
  void CloseAsNeeded(QWidget* widget);

  QParallelAnimationGroup* animation_group_ = nullptr;

  QVector<QPair<QWidget*, QPropertyAnimation*>> animation_set_;

  bool is_set_open_;
};
}

#endif  // ABSTRACT_SLIDING_WIDGET_SET_H
