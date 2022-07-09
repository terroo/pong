#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class PongBall {

  // SFML
  std::shared_ptr<sf::RenderWindow> window;
  sf::RectangleShape time_a, time_b;
  sf::Texture t_time_a, t_time_b, tcampo, tball;
  sf::Sprite campo, ball;
  sf::Vector2f velocity;
  sf::Font font;
  sf::Text text_time_a, text_time_b, play;

  int points_time_a, points_time_b;
  float speed;
  bool start, menu;

  protected:
    void events();
    void draw_game();
    void draw_menu();
    void logic();

  public:
    PongBall();
    void run();
};
