#pragma once

#include <variant>

#include "raylib.h"

struct CameraMode2D {
    Vector2 offset{0.0, 0.0}, target{0.0, 0.0};
    float rotation = 0.0, zoom = 1.0;

    CameraMode2D() = default;

    operator Camera2D() const;
};

struct CameraMode3D {
    // TODO: Stub atm.

    CameraMode3D() = default;

    operator Camera3D() const;
};

extern struct UltraCamera {
    std::variant<CameraMode2D, CameraMode3D> mode = CameraMode2D();
    bool frame_started = false;

    void start_view(const CameraMode2D&);
    void start_view(const CameraMode3D&);
    void end_view();

    CameraMode2D& expect_2d();
    CameraMode3D& expect_3d();
} camera;
