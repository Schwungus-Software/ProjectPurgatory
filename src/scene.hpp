#pragma once

#include <memory>
#include <vector>

#include "camera.hpp"

class Scene {
  public:
    virtual void update() = 0;
    virtual void draw() const = 0;
};

extern struct SceneStack {
  private:
    std::vector<std::unique_ptr<Scene>> stack, temporary_storage;

  public:
    SceneStack() = default;

    void push(Scene*);
    void pop();

    Scene* top();

    void tick();
} scene_stack;
