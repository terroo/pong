#include "pongball.hpp"

PongBall::PongBall(){

  window =  std::make_shared<sf::RenderWindow>(
    sf::VideoMode(1280, 720),
    "Pong (soccer remix)",
    sf::Style::Titlebar | sf::Style::Close
  );
  window->setPosition(sf::Vector2i(0, 0));

  points_time_a = points_time_b = {};
  speed = 1.9f;
  start = false;
  menu = true;

  time_a.setSize(sf::Vector2f( 50.f, 72.f ));
  time_b.setSize(sf::Vector2f( 50.f, 72.f ));
  time_a.setPosition( 0, 20.f );
  time_b.setPosition( 
    window->getSize().x - time_b.getSize().x , 
    20.f
  );

  tball.loadFromFile("./assets/img/ball64.png");
  tcampo.loadFromFile("./assets/img/campo.jpg");
  t_time_a.loadFromFile("./assets/img/player1.png");
  t_time_b.loadFromFile("./assets/img/player2.png");

  ball.setTexture( tball );
  campo.setTexture( tcampo );

  time_a.setTexture( &t_time_a );
  time_b.setTexture( &t_time_b );

  velocity = sf::Vector2f( speed, speed );

  font.loadFromFile("./assets/font/font.ttf");

  // TIME A(left)
  text_time_a.setFont( font );
  text_time_a.setString( std::to_string( points_time_a ) );
  text_time_a.setPosition( static_cast<float>(1280) / 2 - 50, 10);
  text_time_a.setCharacterSize( 50 );
  text_time_a.setOutlineThickness( 3 );

  // TIME B(Right)
  text_time_b.setFont( font );
  text_time_b.setString( std::to_string( points_time_b ) );
  text_time_b.setPosition( static_cast<float>(1280) / 2 + 10, 10);
  text_time_b.setCharacterSize( 50 );
  text_time_b.setOutlineThickness( 3 );

  // TIME B(Right)
  play.setFont( font );
  play.setString( "START THE GAME" );
  play.setPosition( static_cast<float>(1280) / 2 - 180, 300 );
  play.setCharacterSize( 50 );
  play.setOutlineThickness( 3 );
}
