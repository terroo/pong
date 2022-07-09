#include "pongball.hpp"

void PongBall::logic(){
  
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::S)){
    if( time_a.getPosition().y < window->getSize().y - time_a.getSize().y ){
      time_a.move( 0, speed );
    }
  }

  if( sf::Keyboard::isKeyPressed( sf::Keyboard::W)){
    if( time_a.getPosition().y > 0 ){
      time_a.move( 0, -speed );
    }
  }

  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down)){
    if( time_b.getPosition().y < window->getSize().y - time_b.getSize().y ){
      time_b.move( 0, speed );
    }
  }

  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up)){
    if( time_b.getPosition().y > 0 ){
      time_b.move( 0, -speed );
    }
  }

  // Uncomment to play with computer (Artificial Intelligence*)
  //if( ball.getPosition().x > (float)1280 / 2 ){
  //  time_b.setPosition(
  //    time_b.getPosition().x,
  //    ball.getPosition().y
  //  );
  //}

  if( (ball.getPosition().y > window->getSize().y && velocity.y > 0) ||
      ( ball.getPosition().y < 0 && velocity.y < 0 ) ){
      velocity.y = -velocity.y;
  }

  if( time_a.getGlobalBounds().intersects( ball.getGlobalBounds() ) && velocity.x < 0){
    velocity.x = -velocity.x;
  }

  if( time_b.getGlobalBounds().intersects( ball.getGlobalBounds() ) && velocity.x > 0){
    velocity.x = -velocity.x;
  }

  ball.setPosition( ball.getPosition() + velocity );


  // I changed, that is, it is different from the video
  if( ball.getPosition().x < 0 && !start ){
    text_time_b.setString( std::to_string( ++points_time_b ) );
    start = true;
  }

  if( ball.getPosition().x > 1280 && !start ){
    text_time_a.setString( std::to_string( ++points_time_a ) );
    start = true;
  }

  // I changed, that is, it is different from the video
  if( start ){
    ball.setPosition(
      static_cast<float>(window->getSize().x) / 2 - ball.getGlobalBounds().width / 2,
      static_cast<float>( window->getSize().y ) / 2 - ball.getGlobalBounds().height / 2
    );
    start = false;
  }

}
