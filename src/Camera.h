#pragma once 
#include "Vector2D.h"

// Note: Camera does not have 'width' or 'height' (which are determined by Game screen)
// We setup one of 'target' (preferred) or 'position'
class Camera {
public:
  // to make Camera a Singleton
  static Camera* Instance() {
    if (s_pCamera == nullptr) 
      s_pCamera = new Camera();
    return s_pCamera;
  }


  void update(Vector2D velocity);
  void setTarget(Vector2D* target) { m_pTarget = target; }
  void setPosition(const Vector2D& position) { m_position = position; }
  const Vector2D getPosition() const;

private:
  Camera();
  ~Camera() {}

  Vector2D* m_pTarget; // Camera's target (top left of Player)
  Vector2D m_position; // Camera's position in full Tilemap
  static Camera* s_pCamera;
};