#include <stdexcept>

#include "raylib.h"

#include "camera.hpp"

UltraCamera camera;

void UltraCamera::start_view(const CameraMode2D& cam2d) {
    if (frame_started) {
        throw std::invalid_argument("Frame already started");
    }

    mode = cam2d;
    frame_started = true;

    BeginMode2D(cam2d);
}

void UltraCamera::start_view(const CameraMode3D& cam3d) {
    if (frame_started) {
        throw std::invalid_argument("Frame already started");
    }

    mode = cam3d;
    frame_started = true;

    BeginMode3D(cam3d);
}

void UltraCamera::end_view() {
    if (!frame_started) {
        throw std::invalid_argument("Frame not started yet");
    }

    if (mode.index() == 0) {
        EndMode2D();
    } else {
        EndMode3D();
    }

    frame_started = false;
}

CameraMode2D::operator Camera2D() const {
    return {offset, target, rotation, zoom};
}

CameraMode3D::operator Camera3D() const {
    throw "Unimplemented";
}
