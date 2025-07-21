#pragma once

#include "general.h"
#include "geometry.h"
#include "array.h"
#include "hash_table.h"

#include "os_specific.h"

struct Shader;

struct Global_Variables {
    Array <Event> events_this_frame;
    Array <Window_Resize_Record> window_resizes;
    bool should_quit_game = false;
    bool should_vsync = true;
    
    Window_Type window = NULL;
    int window_width = 0;
    int window_height = 0;

    Shader *shader_color = NULL;

    Matrix4 object_to_proj_matrix;
    Matrix4 view_to_proj_matrix;
    Matrix4 world_to_view_matrix;
    Matrix4 object_to_world_matrix;
};

extern Global_Variables globals;
