﻿#include <om_date_label.h>

#include <om_utility.h>

using namespace om_widgets;
using namespace om_utility;

OmDateLabel::OmDateLabel(QWidget* parent) : AbstractTimeAndDate(parent) {
  Update();
  InitializeTimer(this);
}

OmDateLabel::~OmDateLabel() {}

void OmDateLabel::Update() { om_utility::TimeDateChanger::ChangeDate(this); }
