﻿#include <test_colorizer.h>

void TestColorizer::ColorizeButtons(QPushButton* button,
                                    const QRect& current_geometry) {
  button->setStyleSheet(
      "QPushButton{"
      "background-color: rgba(0, 0, 0, 50%);"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}"
      "QPushButton:hover:pressed { "
      "border: 2px solid red;"
      "color: red; }");
  button->setWindowOpacity(0.5);
  button->setGeometry(current_geometry);
}

void TestColorizer::ColorizeFrame(QFrame* frame,
                                  const QRect& current_geometry) {
  frame->setStyleSheet(
      "QFrame{"
      "background: rgba(0, 0, 0, 50%);"
      "color: #00FFFF;"
      "border: 2px solid #00FFFF;"
      "border-radius: 5px;"
      "}");
  frame->setWindowOpacity(0.5);
  frame->setGeometry(current_geometry);
}

void TestColorizer::ColorizeLabel(QLabel* label, const QRect& geometry) {
  label->setStyleSheet(
      "QLabel{"
      "background-color: rgba(0, 0, 0, 50%);"
      "border: 2px solid #00FFFF;"
      "color: #00FFFF;"
      "}");
  label->setGeometry(geometry);
  label->setAlignment(Qt::AlignCenter);
  label->setWordWrap(true);
}
