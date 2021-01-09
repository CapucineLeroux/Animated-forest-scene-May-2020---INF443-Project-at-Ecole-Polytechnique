#pragma once

#include "main/scene_base/base.hpp"
#include "fonctions_auxiliaires.hpp"

#ifdef SCENE_PROJET_FINAL



struct gui_scene_structure
{
    bool wireframe   = false;
    bool surface     = true;
    bool skeleton    = false;
    bool display_keyframe = false;
    bool display_polygon  = false;
};



struct scene_model : scene_base
{

    void setup_data(std::map<std::string,GLuint>& shaders, scene_structure& scene, gui_structure& gui);
    void frame_draw(std::map<std::string,GLuint>& shaders, scene_structure& scene, gui_structure& gui);

    void set_gui();
    gui_scene_structure gui_scene;


//********************************CERF********************************

    vcl::hierarchy_mesh_drawable hierarchy_cerf;
    vcl::hierarchy_mesh_drawable_display_skeleton hierarchy_cerf_visual_debug;
    vcl::vec3 position_cerf;
    vcl::vec3 orientation_cerf;
    bool cerf_doit_stopper;
    std::vector <bool> cerf_doit_stopper_membres;
    bool cerf_doit_boire;
    bool cerf_doit_stopper_boire;
    bool cerf_doit_stopper_bloquer;
    bool cerf_doit_relever;
    vcl::timer_interval timer_cerf;
    float t_precedent_cerf;
    float t_reel_cerf;
    float t_min_cerf;
    float t_max_cerf;
    vcl::buffer<vec3t> keyframes_cerf;

//********************************PAPILLON********************************

    vcl::hierarchy_mesh_drawable hierarchy_corps_papillon;
    vcl::hierarchy_mesh_drawable hierarchy_ailes_papillon;
    vcl::hierarchy_mesh_drawable_display_skeleton hierarchy_corps_papillon_visual_debug;
    vcl::hierarchy_mesh_drawable_display_skeleton hierarchy_ailes_papillon_visual_debug;
    GLuint texture_id_papillon_1;
    GLuint texture_id_papillon_2;
    GLuint texture_id_papillon_3;
    GLuint texture_id_papillon_4;
    vcl::timer_interval timer_papillon;
    float t_precedent_papillon;
    float t_reel_papillon;
    float t_min_papillon;
    float t_max_papillon;
    std::vector <vcl::buffer<vec3t>> keyframes_papillons;
    std::vector <int> couleur_papillons;

//********************************LAPIN********************************

    vcl::hierarchy_mesh_drawable hierarchy_lapin;
    vcl::hierarchy_mesh_drawable_display_skeleton hierarchy_lapin_visual_debug;
    vcl::timer_interval timer_lapin;
    float t_precedent_lapin;
    float t_reel_lapin;
    float t_min_lapin;
    float t_max_lapin;
    std::vector <vcl::buffer<vec3t>> keyframes_lapins;



//********************************DECOR********************************

    vcl::mesh_drawable terrain;
    vcl::mesh_drawable lac;

    vcl::mesh_drawable tronc;
    vcl::mesh_drawable feuillage;
    std::vector<vcl::vec3> positions1;
    std::vector<vcl::vec3> positions2;
    std::vector<vcl::vec3> positions3;
    std::vector<vcl::vec3> positions4;
    std::vector<vcl::vec3> positions5;
    std::vector<vcl::vec3> positions6;
    std::vector<vcl::vec3> positions7;
    std::vector<vcl::vec3> positions8;
    std::vector <std::vector<vcl::vec3>> positions_arbres;
    std::vector<vcl::mesh_drawable> troncs1;
    std::vector<vcl::mesh_drawable> troncs2;
    std::vector<vcl::mesh_drawable> troncs3;
    std::vector<vcl::mesh_drawable> troncs4;
    std::vector<vcl::mesh_drawable> troncs5;
    std::vector<vcl::mesh_drawable> troncs6;
    std::vector<vcl::mesh_drawable> troncs7;
    std::vector<vcl::mesh_drawable> troncs8;
    std::vector<vcl::mesh_drawable> feuillages1;
    std::vector<vcl::mesh_drawable> feuillages2;
    std::vector<vcl::mesh_drawable> feuillages3;
    std::vector<vcl::mesh_drawable> feuillages4;
    std::vector<vcl::mesh_drawable> feuillages5;
    std::vector<vcl::mesh_drawable> feuillages6;
    std::vector<vcl::mesh_drawable> feuillages7;
    std::vector<vcl::mesh_drawable> feuillages8;

    std::vector<vcl::vec3> positions_billboard;  
    GLuint texture_id;
    GLuint texture_id_eau;
    GLuint texture_id_skybox;
    GLuint texture_id_billboard_grass;
    GLuint texture_id_billboard_flower;
    GLuint texture_id_billboard_nenuphar;
    vcl::mesh_drawable surface_billboard;
    vcl::mesh_drawable surface_nenuphar;
    vcl::mesh_drawable skybox;

};



#endif




