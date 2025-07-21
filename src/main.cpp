#include "main.h"
#include "rendering.h"
#include "resource_manager.h"

Global_Variables globals;

static void init_shaders() {
    globals.shader_color = find_or_load_shader("color");
}

static void respond_to_input() {
    for (auto event : globals.events_this_frame) {
        switch (event.type) {
            case EVENT_TYPE_QUIT: {
                globals.should_quit_game = true;
            } break;
        }
    }

    for (auto record : globals.window_resizes) {
        if (record.window != globals.window) continue;

        globals.window_width  = record.width;
        globals.window_height = record.height;
    }
    globals.window_resizes.count = 0;
}

int main(int argc, char *argv[]) {
    os_init();

    globals.window_width  = 1600;
    globals.window_height = 900;
    globals.window = os_create_window(globals.window_width, globals.window_height, "Platformer!");
    if (!globals.window) return 1;
    if (!init_rendering(globals.window, globals.should_vsync)) return 1;
    init_resource_manager(); // !!! Need to init resource manager before shaders and textures !!!
    init_shaders();
    
    while (!globals.should_quit_game) {
        os_update_window_events();
        respond_to_input();

        set_shader(NULL);
        
        set_viewport(0, 0, globals.window_width, globals.window_height);
        clear_framebuffer(0.2f, 0.5f, 0.8f, 1.0f);

        set_shader(globals.shader_color);
        rendering_2d(globals.window_width, globals.window_height);
        
        immediate_begin();
        immediate_quad(50, 50, 64, 64, v4(1, 0.5f, 0.2f, 1));
        immediate_flush();
        
        swap_buffers();

        do_hotloading();
    }
    
    return 0;
}
