// Copyright 2026 Aanya Bharti
#pragma once

#include <SFML/Graphics.hpp>

class PTree : public sf::Drawable {
 public:
  PTree(float baseLength, int depth, float angleDeg = 45.0f);

 private:
  void draw(sf::RenderTarget& target,
            sf::RenderStates states) const override;

  void drawTree(sf::RenderTarget& target,
                sf::Vector2f bottomLeft,
                float size,
                float rotation,
                int depth,
                int level) const;

  float baseLength_;
  int maxDepth_;
  float angleDeg_;
};
