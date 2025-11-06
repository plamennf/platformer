#pragma once

struct World;

struct Camera {
    Vector2 position;
    Vector2 target;
    u64 following_id;
    Vector2 dead_zone_size;
    float smooth_factor;

    bool intro_active = false;
    float intro_timer = 0.0f;
    float intro_duration = 2.0f;

    Vector2 intro_start_pos;
    Vector2 intro_end_pos;
    float intro_start_zoom = 1.0f;
    float intro_end_zoom   = 1.0f;
    float zoom = 1.0f;
};

void update_camera(Camera *camera, World *world, float dt);
Matrix4 get_world_to_view_matrix(Camera *camera, World *world);
