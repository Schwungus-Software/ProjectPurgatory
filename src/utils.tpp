#pragma once

#include <algorithm>

template <typename T>
bool contains(const std::vector<T>& v, const T& x) {
    return std::find(v.begin(), v.end(), x) != v.end();
}

template <typename T>
void erase_all_from(std::vector<T>& dest, const std::vector<T>& src) {
    std::erase_if(dest, [&src](const T& x) { return contains(src, x); });
}

struct Defer {
    using Fn = std::function<void()>;

  private:
    Fn functor;

  public:
    Defer() = delete;
    Defer(Fn functor) : functor(functor) {}

    ~Defer() {
        functor();
    }
};

#define DEFER(fn) Defer run_##fn##_deferred([]() { fn(); })
