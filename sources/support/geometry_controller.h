﻿#ifndef GEOMETRY_CONTROLLER_H
#define GEOMETRY_CONTROLLER_H

#include <geometry_composer.h>
#include <geometry_scaler.h>

namespace demo_code {
using namespace om_composing;
using namespace om_utility;

class GeometryController {
 public:
  static void ShiftGeometry(const QRect& initial_widget_geometry, QWidget* widget);
  static void StretchGeometry(const QRect& initial_widget_geometry, QWidget* widget);
  static void ScaleGeometry(const QRect& initial_widget_geometry, QWidget* widget);

  static void SetDeltaSize(const DeltaSize& delta_size);

 private:
  static GeometryComposer shifter_;
  static GeometryComposer stretcher_;
  static GeometryScaler scaler_;
};
}

#endif  // GEOMETRY_CONTROLLER_H