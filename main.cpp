#include "pongball.hpp"

int main(){
  auto pong = std::make_shared<PongBall>();
  pong->run();
  return 0;
}

