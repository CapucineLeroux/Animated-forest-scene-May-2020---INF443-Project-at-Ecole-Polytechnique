#pragma once

#include "main/scene_base/base.hpp"
#include "fonctions_auxiliaires.hpp"


#ifdef SCENE_PROJET_FINAL

//********************************DECLARATION DES STRUCTURES********************************

struct vec3marche{
    vcl::hierarchy_mesh_drawable hierarchy; // hierarchy
    bool doit_stopper; //indique si l'action est terminee
};



struct vec3arret{
    vcl::hierarchy_mesh_drawable hierarchy; // hierarchy
    bool doit_boire; //indique si l'action est terminee
    std::vector <bool> doit_stopper_membres; //indique pour chaque membre si l'action est terminee
    vcl::timer_interval timer;
};



struct vec3boire{
    vcl::hierarchy_mesh_drawable hierarchy; // hierarchy
    bool doit_stopper_boire; //indique si l'action est terminee
    vcl::vec3 position;
    vcl::timer_interval timer;
};



struct vec3bloquer{
    bool doit_stopper_bloquer;
    vcl::timer_interval timer;
};



//********************************DECLARATION DES FONCTIONS********************************


vcl::hierarchy_mesh_drawable data_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf);
vec3marche marche_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf, float t_reel, vcl::buffer<vec3t> keyframes_cerf, bool cerf_doit_stopper);
vec3arret arret_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf, float t_reel, bool cerf_doit_boire, std::vector <bool> cerf_doit_stopper_membres, vcl::timer_interval timer);
vec3boire boire_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf, float t, bool cerf_doit_stopper_boire, vcl::vec3 position_cerf, vcl::vec3 orientation_cerf, vcl::timer_interval timer);
vec3bloquer bloquer_cerf(bool cerf_doit_stopper_bloquer,vcl::timer_interval timer);
vec3boire relever_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf, float t, bool cerf_doit_relever, vcl::vec3 position_cerf, vcl::vec3 orientation_cerf, vcl::timer_interval timer);
vcl::buffer<vec3t> init_keyframes_cerf(vcl::buffer<vec3t> keyframes_cerf, std::vector<std::vector<vcl::vec3>> positions_arbres);
vcl::buffer<vec3t> update_keyframes_cerf(vcl::buffer<vec3t> keyframes_cerf, float t_min, float t_max, bool cerf_doit_stopper, std::vector<std::vector<vcl::vec3>> positions_arbres);
vcl::vec3 update_position_cerf(vcl::vec3 position_cerf, vcl::buffer<vec3t> keyframes_cerf, float t_reel, bool cerf_doit_stopper);
vcl::vec3 update_orientation_cerf(vcl::vec3 orientation_cerf, vcl::buffer<vec3t> keyframes_cerf, float t_reel, bool cerf_doit_stopper);

#endif


