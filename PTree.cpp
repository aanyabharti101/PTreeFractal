// Copyright 2026 Aanya Bharti
#include "PTree.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>

PTree::PTree(float baseLength, int depth, float angleDeg)
    : baseLength_(baseLength),
      maxDepth_(depth),
      angleDeg_(angleDeg) {}

void PTree::draw(sf::RenderTarget& target,
                 sf::RenderStates) const {
  sf::Vector2u winSize = target.getSize();

  sf::Vector2f bottomLeft(
      winSize.x / 2.0f - baseLength_ / 2.0f,
      winSize.y - 10.0f);

  drawTree(target, bottomLeft, baseLength_, 0.f, maxDepth_, 0);
}

void PTree::drawTree(sf::RenderTarget& target,
                     sf::Vector2f bottomLeft,
                     float size,
                     float rotation,
                     int depth,
                     int level) const {
  if (depth < 0) return;

  sf::RectangleShape square({size, size});
  square.setOrigin({0.f, size});
  square.setPosition(bottomLeft);
  square.setRotation(sf::degrees(rotation));

  float t = static_cast<float>(level) /
            static_cast<float>(std::max(1, maxDepth_));

  square.setFillColor(sf::Color(
      static_cast<std::uint8_t>(255 * t),
      static_cast<std::uint8_t>(200 * (1 - t)),
      static_cast<std::uint8_t>(150 + 100 * t)));

  target.draw(square);

  if (depth == 0) return;

  float theta = angleDeg_ * static_cast<float>(M_PI) / 180.f;

  float leftSize = size * std::cos(theta);
  float rightSize = size * std::sin(theta);

  sf::Transform transform;
  transform.translate(bottomLeft);
  transform.rotate(sf::degrees(rotation));

  sf::Vector2f topLeft =
      transform.transformPoint({0.f, -size});
  sf::Vector2f topRight =
      transform.transformPoint({size, -size});

  float leftRotation = rotation - angleDeg_;

  drawTree(target,
           topLeft,
           leftSize,
           leftRotation,
           depth - 1,
           level + 1);

  float rightRotation =
      rotation + (90.f - angleDeg_);

  float rightRad =
      rightRotation * static_cast<float>(M_PI) / 180.f;

  sf::Vector2f offset(
      rightSize * std::cos(rightRad),
      rightSize * std::sin(rightRad));

  drawTree(target,
           topRight - offset,
           rightSize,
           rightRotation,
           depth - 1,
           level + 1);
}
