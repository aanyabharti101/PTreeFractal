// Copyright 2026 Aanya Bharti

#include <iostream>
#include <string>

#include "PTree.hpp"



int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: ./PTree L N [angle]\n";
    return 1;
  }

  float L = std::stof(argv[1]);
  int N = std::stoi(argv[2]);

  float angle = 45.0f;
  if (argc >= 4)
    angle = std::stof(argv[3]);

  unsigned int width =
      static_cast<unsigned int>(6 * L);
  unsigned int height =
      static_cast<unsigned int>(4 * L);

  sf::RenderWindow window(
      sf::VideoMode({width, height}),
      "Pythagoras Tree");

  PTree tree(L, N, angle);

  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();

      if (event->is<sf::Event::KeyPressed>()) {
        auto key =
            event->getIf<sf::Event::KeyPressed>()->code;

        if (key == sf::Keyboard::Key::Right) {
          N++;
          tree = PTree(L, N, angle);
        }

        if (key == sf::Keyboard::Key::Left && N > 0) {
          N--;
          tree = PTree(L, N, angle);
        }

        if (key == sf::Keyboard::Key::Up) {
          angle += 2.f;
          tree = PTree(L, N, angle);
        }

        if (key == sf::Keyboard::Key::Down) {
          angle -= 2.f;
          tree = PTree(L, N, angle);
        }
      }
    }

    window.clear(sf::Color::Black);
    window.draw(tree);
    window.display();
  }

  return 0;
}
