#include <glPortal/Game.hpp>
#include <glPortal/GameState.hpp>

#include <iostream>

using namespace radix;

namespace glPortal {

Game::Game() {
  windowTitle = "GlPortal";
  defaultMap = "/maps/n1.xml";
}

void Game::initHook() {
  world.stateFunctionStack.push(&GameState::handleRunning);
  world.stateFunctionStack.push(&GameState::handleSplash);
  gameController = std::make_unique<GameController>(this);
  World& worldReference = static_cast<glPortal::World&>(world);
  radix::Renderer& rendererReference = *renderer.get();
  gameRenderer =
    std::make_unique<GameRenderer>(worldReference, rendererReference, camera.get(), &dtime);
  uiRenderer =
    std::make_unique<UiRenderer>(worldReference, rendererReference);

  renderer->addRenderer(*gameRenderer);
  renderer->addRenderer(*uiRenderer);
}

void Game::processInput() {
  gameController->processInput();
}

void Game::update() {
  BaseGame::update();
  dtime = (currentTime-lastRender)/1000.;
}

} /* namespace glPortal */
