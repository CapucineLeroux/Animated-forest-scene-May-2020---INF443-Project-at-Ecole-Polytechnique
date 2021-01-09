#pragma once

#include "main/scene_base/base.hpp"
#include "fonctions_auxiliaires.hpp"

#ifdef SCENE_PROJET_FINAL

float evaluate_terrain_z(float u, float v);
float evaluate_lac_z(float u, float v);
vcl::vec3 evaluate_terrain(float u, float v);
vcl::vec3 evaluate_lac(float u, float v);
vcl::mesh create_terrain();
vcl::mesh create_lac();
vcl::mesh create_skybox();
vcl::mesh create_tree_foliage(float radius, float height, float z_offset, vcl::vec3 p, unsigned int N, float r);

//ajoute N positions pour un objet dont on veut qu'il soit à la distance dmin des autres objets déjà présents
std::vector<vcl::vec3> update_trees_position1(std::vector<vcl::vec3> positions1, unsigned int N, float dmin);
std::vector<vcl::vec3> update_trees_position2(std::vector<vcl::vec3> positions2, unsigned int N, float dmin);
std::vector<vcl::vec3> update_trees_position3(std::vector<vcl::vec3> positions3, unsigned int N, float dmin);
std::vector<vcl::vec3> update_trees_position4(std::vector<vcl::vec3> positions4, unsigned int N, float dmin);
std::vector<vcl::vec3> update_trees_position5(std::vector<vcl::vec3> positions5, unsigned int N, float dmin);
std::vector<vcl::vec3> update_trees_position6(std::vector<vcl::vec3> positions6, unsigned int N, float dmin);
std::vector<vcl::vec3> update_trees_position7(std::vector<vcl::vec3> positions7, unsigned int N, float dmin);
std::vector<vcl::vec3> update_trees_position8(std::vector<vcl::vec3> positions8, unsigned int N, float dmin);
std::vector<vcl::vec3> update_billboard_position_zone7(std::vector<vcl::vec3> positions, unsigned int N, float dmin);
std::vector<vcl::vec3> update_billboard_position(std::vector<vcl::vec3> positions, unsigned int N, float dmin);
std::vector<vcl::vec3> update_nenuphar_position(std::vector<vcl::vec3> positions, unsigned int N, float dmin);


#endif
