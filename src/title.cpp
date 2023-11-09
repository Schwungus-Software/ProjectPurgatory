#include "raylib.h"

#include "title.hpp"

Title::Title() {
    stage.anim = Anim::SCHWUNGUS_FADE_IN;
    stage.duration = stage_duration();
    stage.progress = 0.0;
}

void Title::update() {
    stage.progress += GetFrameTime();

    if (stage.progress > stage.duration) {
        stage.anim = static_cast<Anim>(stage.anim + 1);
        stage.duration = stage_duration();
        stage.progress = 0.0;
    }

    if (stage.anim == Anim::QUIT) {
        scene_stack.pop();
    }
}

void Title::draw() const {
    camera.start_view(CameraMode2D());
    ClearBackground(RAYWHITE);

    switch (stage.anim) {
        case Anim::SCHWUNGUS_FADE_IN:
            DrawText("FADING IN THE SCHWUNG", 0, 300, 40, BLACK);
            break;
        case Anim::SCHWUNGUS_FADE_OUT:
            DrawText("FADING OUT THE SCHWUNG", 0, 300, 40, BLACK);
            break;
        case Anim::SCHWUNGUS_ANIM:
            DrawText("SCHWUNG!!!!!!!", 0, 300, 40, BLACK);
            break;
        default:
            // Ignored.
            break;
    }

    camera.end_view();
}

float Title::stage_duration() const {
    switch (stage.anim) {
        case Anim::SCHWUNGUS_FADE_IN:
            return 2.0;
        case Anim::SCHWUNGUS_FADE_OUT:
            return 1.5;
        case Anim::SCHWUNGUS_ANIM:
            return 5.0;
        default:
            return 0.0;
    }
}
