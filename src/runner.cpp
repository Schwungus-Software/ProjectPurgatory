#include <exception>
#include <iostream>
#include <mutex>

#include "camera.hpp"
#include "runner.hpp"
#include "scene.hpp"
#include "title.hpp"
#include "utils.tpp"

Runner runner;

int Runner::run() {
    scene_stack.push(new Title);

    InitWindow(800, 600, "Project Purgatory");
    InitAudioDevice();

    const auto exit_code = mainloop();

    CloseAudioDevice();
    CloseWindow();

    return exit_code;
}

int Runner::mainloop() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        DEFER(EndDrawing);

        try {
            scene_stack.tick();
        } catch (GracefulExit) {
            return 0;
        } catch (std::exception ex) {
            std::cerr << "Encountered standard exception of type `" << typeid(ex).name() << "`\nCause: " << ex.what() << std::endl;
            return 1;
        }
    }

    return 0;
}
