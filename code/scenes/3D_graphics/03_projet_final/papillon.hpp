#pragma once

#include "main/scene_base/base.hpp"
#include "fonctions_auxiliaires.hpp"

#ifdef SCENE_PROJET_FINAL

vcl::hierarchy_mesh_drawable data_corps_papillon(vcl::hierarchy_mesh_drawable hierarchy_corps_papillon);
vcl::hierarchy_mesh_drawable draw_corps_papillon(vcl::hierarchy_mesh_drawable hierarchy_corps_papillon, float t_reel, vcl::buffer<vec3t> keyframes_papillon);
vcl::hierarchy_mesh_drawable data_ailes_papillon(vcl::hierarchy_mesh_drawable hierarchy_ailes_papillon);
vcl::hierarchy_mesh_drawable draw_ailes_papillon(vcl::hierarchy_mesh_drawable hierarchy_ailes_papillon, float t_reel, vcl::buffer<vec3t> keyframes_papillon);
std::vector <vcl::buffer<vec3t>> update_keyframes_papillon(std::vector<vcl::buffer<vec3t>> keyframes_papillons, float t_min, float t_max);
std::vector <vcl::buffer<vec3t>> init_keyframes_papillon (unsigned int N);
std::vector <int> init_couleur_papillon(unsigned int N);


#endif
