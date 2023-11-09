#include <algorithm>

#include "runner.hpp"
#include "scene.hpp"
#include "utils.tpp"

SceneStack scene_stack;

void SceneStack::push(Scene* scene) {
    stack.push_back(std::unique_ptr<Scene>(scene));
}

void SceneStack::pop() {
    auto top = std::move(stack.back());
    temporary_storage.push_back(std::move(top));
    stack.pop_back();
}

Scene* SceneStack::top() {
    if (stack.empty()) {
        throw "Scene stack empty";
    } else {
        return stack.back().get();
    }
}

void SceneStack::tick() {
    if (stack.empty()) {
        throw GracefulExit();
    }

    const auto scene = top();
    scene->update();
    scene->draw();

    erase_all_from(stack, temporary_storage);
    temporary_storage.clear();
}
