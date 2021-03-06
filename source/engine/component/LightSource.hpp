#ifndef COMPONENT_LIGHTSOURCE_HPP
#define COMPONENT_LIGHTSOURCE_HPP

#include "Component.hpp"

namespace glPortal {

class LightSource : public Component {
public:
  Vector3f color;
  float distance;
  float energy;
  float specular;

  LightSource(Entity &ent) :
    Component(ent), color(1, 1, 1), distance(1), energy(10) {}
};

} /* namespace glPortal */

#endif /* COMPONENT_LIGHTSOURCE_HPP */
