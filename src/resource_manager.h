#pragma once

struct Shader;

void init_resource_manager();
void do_hotloading();

Shader *find_or_load_shader(char *name);
