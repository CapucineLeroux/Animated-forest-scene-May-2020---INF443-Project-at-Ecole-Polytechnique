#pragma once

#include "main/scene_base/base.hpp"
#include "fonctions_auxiliaires.hpp"

#ifdef SCENE_PROJET_FINAL

vcl::hierarchy_mesh_drawable data_lapin(vcl::hierarchy_mesh_drawable hierarchy_lapin);
vcl::hierarchy_mesh_drawable draw_lapin(vcl::hierarchy_mesh_drawable hierarchy_lapin, float t_reel, vcl::buffer<vec3t> keyframes_lapin);
std::vector <vcl::buffer<vec3t>> update_keyframes_lapin(std::vector<vcl::buffer<vec3t>> keyframes_lapins, float t_min, float t_max, std::vector<std::vector<vcl::vec3>> positions_arbres);
std::vector <vcl::buffer<vec3t>> init_keyframes_lapin (unsigned int N, std::vector<std::vector<vcl::vec3>> positions_arbres);

#endif
