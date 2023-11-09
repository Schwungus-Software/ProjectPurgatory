#include "scene.hpp"

class Title : public Scene {
  public:
    enum Anim {
        SCHWUNGUS_FADE_IN,
        SCHWUNGUS_ANIM,
        SCHWUNGUS_FADE_OUT,
        QUIT,
    };

    struct {
        Anim anim;
        float duration, progress;
    } stage;

    Title();

    void update() override;
    void draw() const override;

    float stage_duration() const;
};
