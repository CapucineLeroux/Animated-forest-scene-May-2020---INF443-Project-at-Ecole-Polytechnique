#pragma once

#include "main/scene_base/base.hpp"

#ifdef SCENE_TERRAIN_SEUL

struct gui_scene_structure
{
    bool wireframe;
};

struct scene_model : scene_base
{

    /** A part must define two functions that are called from the main function:
     * setup_data: called once to setup data before starting the animation loop
     * frame_draw: called at every displayed frame within the animation loop
     *
     * These two functions receive the following parameters
     * - shaders: A set of shaders.
     * - scene: Contains general common object to define the 3D scene. Contains in particular the camera.
     * - data: The part-specific data structure defined previously
     * - gui: The GUI structure allowing to create/display buttons to interact with the scene.
    */

    void setup_data(std::map<std::string,GLuint>& shaders, scene_structure& scene, gui_structure& gui);
    void frame_draw(std::map<std::string,GLuint>& shaders, scene_structure& scene, gui_structure& gui);
    void set_gui();


    // visual representation of a surface
    //  Surface is a class attribute to be initialized in setup_data and used in frame_draw
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
    std::vector<vcl::vec3> positions_billboard;
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
    gui_scene_structure gui_scene;
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


