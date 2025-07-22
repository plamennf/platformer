#pragma once

struct World;

struct Camera {
    Vector2 position;
    Vector2 target;
    u64 following_id;
    Vector2 dead_zone_size;
    float smooth_factor;
};

void update_camera(Camera *camera, World *world, float dt);
Matrix4 get_world_to_view_matrix(Camera *camera, World *world);
