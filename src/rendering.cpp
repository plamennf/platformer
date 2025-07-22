#include "main.h"
#include "rendering.h"

void rendering_2d(int width, int height) {
    Matrix4 m = matrix4_identity();
    rendering_2d(width, height, m);
}

void rendering_2d(int width, int height, Matrix4 world_to_view_matrix) {
    float w = (float)width;
    if (w < 1.0f) w = 1.0f;
    float h = (float)height;
    if (h < 1.0f) h = 1.0f;

    Matrix4 m = make_orthographic(0.0f, w, 0.0f, h, -1.0f, 1.0f);

    globals.view_to_proj_matrix    = m;
    globals.world_to_view_matrix   = world_to_view_matrix;
    globals.object_to_world_matrix = matrix4_identity();

    refresh_transform();    
}
