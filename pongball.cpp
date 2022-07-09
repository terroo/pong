#include "pongball.hpp"


void PongBall::draw_game(){
  window->clear( sf::Color::Black );
  window->draw( campo );
  window->draw( time_a );
  window->draw( time_b );
  window->draw( ball );
  window->draw( text_time_a );
  window->draw( text_time_b );
  window->display();
}

void PongBall::events(){
  sf::Event event;
  while( window->pollEvent( event )){
    if( event.type == sf::Event::Closed){
      window->close();
    }
  }
}

void PongBall::run(){
  while( window->isOpen() ){
    events();

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Enter )){
      menu = false;
    }

    if( !menu ){
      logic();
      draw_game();
    }else{
      draw_menu();
    }

  }
}

void PongBall::draw_menu(){
  window->clear( sf::Color::Black );
  //window->draw( campo );
  window->draw( play );
  window->display();
}
