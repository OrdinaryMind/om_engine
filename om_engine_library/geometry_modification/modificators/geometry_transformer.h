﻿#ifndef GEOMETRY_TRANSFORMER_H
#define GEOMETRY_TRANSFORMER_H

#include <memory>

#include <geometry_modifier.h>
#include <om_utility.h>

class QRect;
class QWidget;

namespace geometry_modification {
using namespace om_utility;

class GeometryTransformer {
 public:
  GeometryTransformer(const ModificationFactor& modification_factor,
                      unsigned int side_to_modify = kRight,
                      TransformationType type = kShifting);

  GeometryTransformer(const ModificationFactor& modification_shift_factor,
                      const ModificationFactor& modification_stretch_factor,
                      Side shift_to = kRight, Side stretch_to = kRight);

 private:
  std::unique_ptr<GeometryModifier> composer_;
  std::unique_ptr<GeometryModifier> scaler_;
};
}

#endif  // GEOMETRY_TRANSFORMER_H
