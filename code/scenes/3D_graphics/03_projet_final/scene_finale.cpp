
#include "scene_finale.hpp"
#include <random>
#include "cerf.hpp"
#include "papillon.hpp"
#include "lapin.hpp"
#include "terrain.hpp"


#ifdef SCENE_PROJET_FINAL
using namespace vcl;


//********************************SETUP DATA********************************



void scene_model::setup_data(std::map<std::string,GLuint>& shaders, scene_structure& scene, gui_structure& )
{
    //**************CAMERA**************

    scene.camera.camera_type = camera_control_spherical_coordinates;
    scene.camera.scale = 10.0f;
    scene.camera.apply_rotation(0,0,0,1.2f);

    //**************DECOR**************

        //terrain

    terrain = create_terrain();
    terrain.uniform.color = {0.6f,0.85f,0.5f};
    terrain.uniform.shading.specular = 0.0f;
    lac = create_lac();
    skybox = create_skybox();

        //arbres

            //zone1
    for (unsigned int i=0; i<100; i++){
        const float r=rand_interval(0.8f,1.4f);
        const float rtronc = rand_interval(0.5f,1.5f);
        const float rfeuillage = rand_interval(0.5f,1.5f);
        mesh tronc_cpu = create_cylinder(0.1f,0.5f,{0,0,0},50,r);
        tronc=mesh_drawable(tronc_cpu);
        tronc.uniform.color = {0.5f*rtronc,0.3f*rtronc,0.05f*rtronc};
        troncs1.push_back(tronc);
        mesh feuillage_cpu = create_tree_foliage(0.24f,0.36f,0.10f,{0,0,0.36f},50,r);
        feuillage=mesh_drawable(feuillage_cpu);
        feuillage.uniform.color={0.0f,1.0f*rfeuillage,0.0f};
        feuillages1.push_back(feuillage);
    }
    positions1=update_trees_position1(positions1,100,0.15f);
    positions_arbres.push_back(positions1);

            //zone2
    for (unsigned int i=0; i<25; i++){
        const float r=rand_interval(0.8f,1.4f);
        const float rtronc = rand_interval(0.5f,1.5f);
        const float rfeuillage = rand_interval(0.5f,1.5f);
        mesh tronc_cpu = create_cylinder(0.1f,0.7f,{0,0,0},50,r);
        tronc=mesh_drawable(tronc_cpu);
        tronc.uniform.color = {0.5f*rtronc,0.3f*rtronc,0.05f*rtronc};
        troncs2.push_back(tronc);
        mesh feuillage_cpu = create_tree_foliage(0.24f,0.45f,0.2f,{0,0,0.45f},50,r);
        feuillage=mesh_drawable(feuillage_cpu);
        feuillage.uniform.color={0.0f,1.0f*rfeuillage,0.0f};
        feuillages2.push_back(feuillage);
    }
    positions2=update_trees_position2(positions2,25,0.50f);
    positions_arbres.push_back(positions2);

            //zone3
    for (unsigned int i=0; i<25; i++){
        const float r=rand_interval(0.8f,1.4f);
        const float rtronc = rand_interval(0.5f,1.5f);
        const float rfeuillage = rand_interval(0.5f,1.5f);
        mesh tronc_cpu = create_cylinder(0.1f,0.7f,{0,0,0},50,r);
        tronc=mesh_drawable(tronc_cpu);
        tronc.uniform.color = {0.5f*rtronc,0.3f*rtronc,0.05f*rtronc};
        troncs3.push_back(tronc);
        mesh feuillage_cpu = create_tree_foliage(0.24f,0.45f,0.2f,{0,0,0.45f},50,r);
        feuillage=mesh_drawable(feuillage_cpu);
        feuillage.uniform.color={0.0f,1.0f*rfeuillage,0.0f};
        feuillages3.push_back(feuillage);
    }
    positions3=update_trees_position3(positions3,25,1.0f);
    positions_arbres.push_back(positions3);

            //zone4
    for (unsigned int i=0; i<50; i++){
        const float r=rand_interval(0.8f,1.4f);
        const float rtronc = rand_interval(0.5f,1.5f);
        const float rfeuillage = rand_interval(0.5f,1.5f);
        mesh tronc_cpu = create_cylinder(0.1f,0.7f,{0,0,0},50,r);
        tronc=mesh_drawable(tronc_cpu);
        tronc.uniform.color = {0.5f*rtronc,0.3f*rtronc,0.05f*rtronc};
        troncs4.push_back(tronc);
        mesh feuillage_cpu = create_tree_foliage(0.24f,0.45f,0.2f,{0,0,0.45f},50,r);
        feuillage=mesh_drawable(feuillage_cpu);
        feuillage.uniform.color={0.0f,1.0f*rfeuillage,0.0f};
        feuillages4.push_back(feuillage);
    }
    positions4=update_trees_position4(positions4,50,0.40f);
    positions_arbres.push_back(positions4);

            //zone5
    for (unsigned int i=0; i<20; i++){
        const float r=rand_interval(0.8f,1.4f);
        const float rtronc = rand_interval(0.5f,1.5f);
        const float rfeuillage = rand_interval(0.5f,1.5f);
        mesh tronc_cpu = create_cylinder(0.1f,0.7f,{0,0,0},50,r);
        tronc=mesh_drawable(tronc_cpu);
        tronc.uniform.color = {0.5f*rtronc,0.3f*rtronc,0.05f*rtronc};
        troncs5.push_back(tronc);
        mesh feuillage_cpu = create_tree_foliage(0.24f,0.45f,0.2f,{0,0,0.45f},50,r);
        feuillage=mesh_drawable(feuillage_cpu);
        feuillage.uniform.color={0.0f,1.0f*rfeuillage,0.0f};
        feuillages5.push_back(feuillage);
    }
    positions5=update_trees_position5(positions5,20,1.0f);
    positions_arbres.push_back(positions5);

            //zone6
    for (unsigned int i=0; i<25; i++){
        const float r=rand_interval(0.8f,1.4f);
        const float rtronc = rand_interval(0.5f,1.5f);
        const float rfeuillage = rand_interval(0.5f,1.5f);
        mesh tronc_cpu = create_cylinder(0.1f,0.7f,{0,0,0},50,r);
        tronc=mesh_drawable(tronc_cpu);
        tronc.uniform.color = {0.5f*rtronc,0.3f*rtronc,0.05f*rtronc};
        troncs6.push_back(tronc);
        mesh feuillage_cpu = create_tree_foliage(0.24f,0.45f,0.2f,{0,0,0.45f},50,r);
        feuillage=mesh_drawable(feuillage_cpu);
        feuillage.uniform.color={0.0f,1.0f*rfeuillage,0.0f};
        feuillages6.push_back(feuillage);
    }
    positions6=update_trees_position6(positions6,25,0.50f);
    positions_arbres.push_back(positions6);

            //zone7
    for (unsigned int i=0; i<100; i++){
        const float r=rand_interval(0.8f,1.4f);
        const float rtronc = rand_interval(0.5f,1.5f);
        const float rfeuillage = rand_interval(0.5f,1.5f);
        mesh tronc_cpu = create_cylinder(0.1f,0.7f,{0,0,0},50,r);
        tronc=mesh_drawable(tronc_cpu);
        tronc.uniform.color = {0.5f*rtronc,0.3f*rtronc,0.05f*rtronc};
        troncs7.push_back(tronc);
        mesh feuillage_cpu = create_tree_foliage(0.24f,0.45f,0.2f,{0,0,0.45f},50,r);
        feuillage=mesh_drawable(feuillage_cpu);
        feuillage.uniform.color={0.0f,1.0f*rfeuillage,0.0f};
        feuillages7.push_back(feuillage);
    }
    positions7=update_trees_position7(positions7,100,0.15f);
    positions_arbres.push_back(positions7);

            //zone8
    for (unsigned int i=0; i<25; i++){
        const float r=rand_interval(0.8f,1.4f);
        const float rtronc = rand_interval(0.5f,1.5f);
        const float rfeuillage = rand_interval(0.5f,1.5f);
        mesh tronc_cpu = create_cylinder(0.1f,0.7f,{0,0,0},50,r);
        tronc=mesh_drawable(tronc_cpu);
        tronc.uniform.color = {0.5f*rtronc,0.3f*rtronc,0.05f*rtronc};
        troncs8.push_back(tronc);
        mesh feuillage_cpu = create_tree_foliage(0.24f,0.45f,0.2f,{0,0,0.45f},50,r);
        feuillage=mesh_drawable(feuillage_cpu);
        feuillage.uniform.color={0.0f,1.0f*rfeuillage,0.0f};
        feuillages8.push_back(feuillage);
    }
    positions8=update_trees_position8(positions8,25,0.50f);
    positions_arbres.push_back(positions8);

        //billboards

    positions_billboard=update_billboard_position_zone7(positions_billboard,40,0.01f);
    positions_billboard=update_billboard_position(positions_billboard,200,0.01f);
    positions_billboard=update_nenuphar_position(positions_billboard,30,0.04f);

            //Gestion surface billboard
    mesh surface_billboard_cpu;
    surface_billboard_cpu.position = {{-0.2f,0,0}, { 0.2f,0,0}, { 0.2f, 0.4f,0}, {-0.2f, 0.4f,0}};
    surface_billboard_cpu.texture_uv = {{0,1}, {1,1}, {1,0}, {0,0}};
    surface_billboard_cpu.connectivity = {{0,1,2}, {0,2,3}};
    surface_billboard = surface_billboard_cpu;
    surface_billboard.uniform.shading = {1,0,0};
            //Gestion surface nenuphar
    mesh surface_nenuphar_cpu;
    surface_nenuphar_cpu.position = {{-0.2f,0,0}, { 0.2f,0,0}, { 0.2f, 0.4f,0}, {-0.2f, 0.4f,0}};
    surface_nenuphar_cpu.texture_uv = {{0,1}, {1,1}, {1,0}, {0,0}};
    surface_nenuphar_cpu.connectivity = {{0,1,2}, {0,2,3}};
    surface_nenuphar=surface_nenuphar_cpu;
    surface_nenuphar.uniform.shading = {1,0,0};
            //Textures
    texture_id = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/grass.png") );
    texture_id_eau = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/EauLacText.png") );
    texture_id_skybox=create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/skybox.png") );
    terrain.texture_id=texture_id;
    lac.texture_id=texture_id_eau;
    skybox.texture_id=texture_id_skybox;
    texture_id_billboard_grass = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/billboard_grass.png"), GL_REPEAT, GL_REPEAT );
    texture_id_billboard_flower = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/billboard_flower1.png"), GL_REPEAT, GL_REPEAT );
    texture_id_billboard_nenuphar = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/nenuphar.png"), GL_REPEAT, GL_REPEAT );


    //**************CERF**************

    timer_cerf.scale = 0.55f;
    t_min_cerf = 0.0f;
    t_max_cerf = 1.0f;

    hierarchy_cerf = data_cerf(hierarchy_cerf);
    hierarchy_cerf.set_shader_for_all_elements(shaders["mesh"]);
    hierarchy_cerf_visual_debug.init(shaders["segment_im"], shaders["mesh"]);
    keyframes_cerf = init_keyframes_cerf(keyframes_cerf, positions_arbres);
    position_cerf = keyframes_cerf[1].p;
    float t0 = keyframes_cerf[0].t;
    float t1 = keyframes_cerf[1].t;
    float t2 = keyframes_cerf[2].t;
    float t3 = keyframes_cerf[3].t;
    vec3 p0 = keyframes_cerf[0].p;
    vec3 p1 = keyframes_cerf[1].p;
    vec3 p2 = keyframes_cerf[2].p;
    vec3 p3 = keyframes_cerf[3].p;
    float K = 0.5f;
    float delta = 0.5f;
    orientation_cerf = derive_p(timer_cerf.t,t0,t1,t2,t3,p0,p1,p2,p3,K,delta);
    cerf_doit_stopper = false;
    cerf_doit_boire = false;
    cerf_doit_stopper_membres = {false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false,
                                 false
                                };
    cerf_doit_stopper_boire = false;
    cerf_doit_relever = false;


    //**************PAPILLON**************

    timer_papillon.scale = 0.45f;
    t_min_papillon = 0.0f;
    t_max_papillon = 1.0f;

    hierarchy_corps_papillon = data_corps_papillon(hierarchy_corps_papillon);
    hierarchy_corps_papillon.set_shader_for_all_elements(shaders["mesh"]);
    hierarchy_corps_papillon_visual_debug.init(shaders["segment_im"], shaders["mesh"]);

    hierarchy_ailes_papillon = data_ailes_papillon(hierarchy_ailes_papillon);
    texture_id_papillon_1 = create_texture_gpu(image_load_png("scenes/3D_graphics/03_projet_final/assets/papillon1.png"), GL_REPEAT, GL_REPEAT);
    texture_id_papillon_2 = create_texture_gpu(image_load_png("scenes/3D_graphics/03_projet_final/assets/papillon2.png"), GL_REPEAT, GL_REPEAT);
    texture_id_papillon_3 = create_texture_gpu(image_load_png("scenes/3D_graphics/03_projet_final/assets/papillon3.png"), GL_REPEAT, GL_REPEAT);
    texture_id_papillon_4 = create_texture_gpu(image_load_png("scenes/3D_graphics/03_projet_final/assets/papillon4.png"), GL_REPEAT, GL_REPEAT);
    hierarchy_ailes_papillon.set_shader_for_all_elements(shaders["mesh"]);
    hierarchy_ailes_papillon_visual_debug.init(shaders["segment_im"], shaders["mesh"]);
    keyframes_papillons = init_keyframes_papillon(30);
    couleur_papillons = init_couleur_papillon(30);

    //**************LAPIN**************

    timer_lapin.scale = 0.55f;
    t_min_lapin = 0.0f;
    t_max_lapin = 1.0f;

    hierarchy_lapin = data_lapin(hierarchy_lapin);
    hierarchy_lapin.set_shader_for_all_elements(shaders["mesh"]);
    hierarchy_lapin_visual_debug.init(shaders["segment_im"], shaders["mesh"]);
    keyframes_lapins = init_keyframes_lapin(10,positions_arbres);



}





//********************************DRAW DATA********************************


void scene_model::frame_draw(std::map<std::string,GLuint>& shaders, scene_structure& scene, gui_structure& )
{


    //**************TIMERS**************

    t_precedent_cerf = timer_cerf.t;
    timer_cerf.update();
    const float t_cerf = timer_cerf.t;
    t_min_cerf = update_t_min(t_cerf,t_precedent_cerf,t_min_cerf, timer_cerf);
    t_max_cerf = t_min_cerf + 1.0f;
    t_reel_cerf = (1.0f-t_cerf)*t_min_cerf + t_cerf*t_max_cerf;

    t_precedent_papillon = timer_papillon.t;
    timer_papillon.update();
    const float t_papillon = timer_papillon.t;
    t_min_papillon = update_t_min(t_papillon,t_precedent_papillon,t_min_papillon, timer_papillon);
    t_max_papillon = t_min_papillon + 1.0f;
    t_reel_papillon = (1.0f-t_papillon)*t_min_papillon + t_papillon*t_max_papillon;

    t_precedent_lapin = timer_lapin.t;
    timer_lapin.update();
    const float t_lapin = timer_lapin.t;
    t_min_lapin = update_t_min(t_lapin,t_precedent_lapin,t_min_lapin, timer_lapin);
    t_max_lapin = t_min_lapin + 1.0f;
    t_reel_lapin = (1.0f-t_lapin)*t_min_lapin + t_lapin*t_max_lapin;

    set_gui();


    //**************MOUVEMENTS CERF**************

    keyframes_cerf = update_keyframes_cerf(keyframes_cerf, t_min_cerf, t_max_cerf, cerf_doit_stopper, positions_arbres);
    position_cerf = update_position_cerf(position_cerf, keyframes_cerf, t_reel_cerf, cerf_doit_stopper);
    orientation_cerf = update_orientation_cerf(orientation_cerf, keyframes_cerf, t_reel_cerf, cerf_doit_stopper);
    if (cerf_doit_stopper == false){
        vec3marche m_cerf = marche_cerf(hierarchy_cerf, t_reel_cerf, keyframes_cerf, cerf_doit_stopper);
        hierarchy_cerf = m_cerf.hierarchy;
        cerf_doit_stopper = m_cerf.doit_stopper;
    }
    else {
        if (cerf_doit_boire == false){
            vec3arret a_cerf = arret_cerf(hierarchy_cerf, t_reel_cerf, cerf_doit_boire, cerf_doit_stopper_membres, timer_cerf);
            hierarchy_cerf = a_cerf.hierarchy;
            cerf_doit_boire = a_cerf.doit_boire;
            cerf_doit_stopper_membres = a_cerf.doit_stopper_membres;
            timer_cerf = a_cerf.timer;
        }
        else {
            if (cerf_doit_stopper_boire == false) {
                vec3boire b_cerf = boire_cerf(hierarchy_cerf, t_cerf, cerf_doit_stopper_boire, position_cerf, orientation_cerf, timer_cerf);
                hierarchy_cerf = b_cerf.hierarchy;
                cerf_doit_stopper_boire = b_cerf.doit_stopper_boire;
                position_cerf = b_cerf.position;
                timer_cerf = b_cerf.timer;
            }
            else {
                if (cerf_doit_stopper_bloquer == false) {
                    vec3bloquer bl_cerf = bloquer_cerf(cerf_doit_stopper_bloquer, timer_cerf);
                    cerf_doit_stopper_bloquer = bl_cerf.doit_stopper_bloquer;
                    timer_cerf = bl_cerf.timer;
                }
                else{
                    vec3boire b_cerf = relever_cerf(hierarchy_cerf, t_cerf, cerf_doit_relever, position_cerf, orientation_cerf, timer_cerf);
                    hierarchy_cerf = b_cerf.hierarchy;
                    cerf_doit_relever = b_cerf.doit_stopper_boire;
                    position_cerf = b_cerf.position;
                    timer_cerf = b_cerf.timer;
                }
            }
        }
    }
    hierarchy_cerf.update_local_to_global_coordinates();
    if(gui_scene.surface)
        draw(hierarchy_cerf, scene.camera);
    if(gui_scene.wireframe)
        draw(hierarchy_cerf, scene.camera, shaders["wireframe"]);
    if(gui_scene.skeleton)
        hierarchy_cerf_visual_debug.draw(hierarchy_cerf, scene.camera);



    //**************MOUVEMENTS CORPS PAPILLONS**************

    keyframes_papillons = update_keyframes_papillon(keyframes_papillons, t_min_papillon, t_max_papillon);
    for (auto keyframes_papillon : keyframes_papillons){
        hierarchy_corps_papillon = draw_corps_papillon(hierarchy_corps_papillon, t_reel_papillon, keyframes_papillon);
        hierarchy_corps_papillon.update_local_to_global_coordinates();
        if(gui_scene.surface)
            draw(hierarchy_corps_papillon, scene.camera);
        if(gui_scene.wireframe)
            draw(hierarchy_corps_papillon, scene.camera, shaders["wireframe"]);
        if(gui_scene.skeleton)
            hierarchy_corps_papillon_visual_debug.draw(hierarchy_corps_papillon, scene.camera);
    }



    //**************MOUVEMENTS LAPINS**************

    keyframes_lapins = update_keyframes_lapin(keyframes_lapins, t_min_lapin, t_max_lapin, positions_arbres);

    for (auto keyframes_lapin : keyframes_lapins){
        hierarchy_lapin = draw_lapin(hierarchy_lapin, t_reel_lapin, keyframes_lapin);
        hierarchy_lapin.update_local_to_global_coordinates();
        if(gui_scene.surface)
            draw(hierarchy_lapin, scene.camera);
        if(gui_scene.wireframe)
            draw(hierarchy_lapin, scene.camera, shaders["wireframe"]);
        if(gui_scene.skeleton)
            hierarchy_lapin_visual_debug.draw(hierarchy_lapin, scene.camera);
    }



    //**************DECOR**************

    glEnable( GL_POLYGON_OFFSET_FILL );

        //terrain

    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glPolygonOffset( 1.0, 1.0 );
    draw(terrain, scene.camera, shaders["mesh"]);
    glBindTexture(GL_TEXTURE_2D, texture_id_eau);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    draw(lac, scene.camera, shaders["mesh"]);
    if( gui_scene.wireframe ){
        glPolygonOffset( 1.0, 1.0 );
        draw(terrain, scene.camera, shaders["wireframe"]);
    }
    if( gui_scene.wireframe ){
        glPolygonOffset( 1.0, 1.0 );
        draw(lac, scene.camera, shaders["wireframe"]);
    }
    glBindTexture(GL_TEXTURE_2D, scene.texture_white);

        //arbres

    for (unsigned int i=0; i<100; i++) {
        vec3 p={positions1[i][0],positions1[i][1],positions1[i][2]-0.1f};
        troncs1[i].uniform.transform.translation = p;
        draw(troncs1[i],scene.camera, shaders["mesh"]);
        //draw(tronc,scene.camera, shaders["wireframe"]);
        feuillages1[i].uniform.transform.translation = p;
        draw(feuillages1[i],scene.camera,shaders["mesh"]);
        //draw(feuillage,scene.camera, shaders["wireframe"]);
    }
    for (unsigned int i=0; i<25; i++) {
        vec3 p={positions2[i][0],positions2[i][1],positions2[i][2]-0.1f};
        troncs2[i].uniform.transform.translation = p;
        draw(troncs2[i],scene.camera, shaders["mesh"]);
        //draw(tronc,scene.camera, shaders["wireframe"]);
        feuillages2[i].uniform.transform.translation = p;
        draw(feuillages2[i],scene.camera,shaders["mesh"]);
        //draw(feuillage,scene.camera, shaders["wireframe"]);
    }
    for (unsigned int i=0; i<25; i++) {
        vec3 p={positions3[i][0],positions3[i][1],positions3[i][2]-0.1f};
        troncs3[i].uniform.transform.translation = p;
        draw(troncs3[i],scene.camera, shaders["mesh"]);
        //draw(tronc,scene.camera, shaders["wireframe"]);
        feuillages3[i].uniform.transform.translation = p;
        draw(feuillages3[i],scene.camera,shaders["mesh"]);
        //draw(feuillage,scene.camera, shaders["wireframe"]);
    }
    for (unsigned int i=0; i<50; i++) {
        vec3 p={positions4[i][0],positions4[i][1],positions4[i][2]-0.1f};
        troncs4[i].uniform.transform.translation = p;
        draw(troncs4[i],scene.camera, shaders["mesh"]);
        //draw(tronc,scene.camera, shaders["wireframe"]);
        feuillages4[i].uniform.transform.translation = p;
        draw(feuillages4[i],scene.camera,shaders["mesh"]);
        //draw(feuillage,scene.camera, shaders["wireframe"]);
    }
    for (unsigned int i=0; i<20; i++) {
        vec3 p={positions5[i][0],positions5[i][1],positions5[i][2]-0.1f};
        troncs5[i].uniform.transform.translation = p;
        draw(troncs5[i],scene.camera, shaders["mesh"]);
        //draw(tronc,scene.camera, shaders["wireframe"]);
        feuillages5[i].uniform.transform.translation = p;
        draw(feuillages5[i],scene.camera,shaders["mesh"]);
        //draw(feuillage,scene.camera, shaders["wireframe"]);
    }
    for (unsigned int i=0; i<25; i++) {
        vec3 p={positions6[i][0],positions6[i][1],positions6[i][2]-0.1f};
        troncs6[i].uniform.transform.translation = p;
        draw(troncs6[i],scene.camera, shaders["mesh"]);
        //draw(tronc,scene.camera, shaders["wireframe"]);
        feuillages6[i].uniform.transform.translation = p;
        draw(feuillages6[i],scene.camera,shaders["mesh"]);
        //draw(feuillage,scene.camera, shaders["wireframe"]);
    }
    for (unsigned int i=0; i<100; i++) {
        vec3 p={positions7[i][0],positions7[i][1],positions7[i][2]-0.1f};
        troncs7[i].uniform.transform.translation = p;
        draw(troncs7[i],scene.camera, shaders["mesh"]);
        //draw(tronc,scene.camera, shaders["wireframe"]);
        feuillages7[i].uniform.transform.translation = p;
        draw(feuillages7[i],scene.camera,shaders["mesh"]);
        //draw(feuillage,scene.camera, shaders["wireframe"]);
    }
    for (unsigned int i=0; i<25; i++) {
        vec3 p={positions8[i][0],positions8[i][1],positions8[i][2]-0.1f};
        troncs8[i].uniform.transform.translation = p;
        draw(troncs8[i],scene.camera, shaders["mesh"]);
        //draw(tronc,scene.camera, shaders["wireframe"]);
        feuillages8[i].uniform.transform.translation = p;
        draw(feuillages8[i],scene.camera,shaders["mesh"]);
        //draw(feuillage,scene.camera, shaders["wireframe"]);
    }



    //**************MOUVEMENTS AILES PAPILLONS**************

    unsigned int i = 0;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(false);

    for (auto keyframes_papillon : keyframes_papillons){
        if (couleur_papillons[i]==1){
        glBindTexture(GL_TEXTURE_2D, texture_id_papillon_1);
        }
        if (couleur_papillons[i]==2){
        glBindTexture(GL_TEXTURE_2D, texture_id_papillon_2);
        }
        if (couleur_papillons[i]==3){
        glBindTexture(GL_TEXTURE_2D, texture_id_papillon_3);
        }
        if (couleur_papillons[i]==4){
        glBindTexture(GL_TEXTURE_2D, texture_id_papillon_4);
        }
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        hierarchy_ailes_papillon = draw_ailes_papillon(hierarchy_ailes_papillon, t_reel_papillon, keyframes_papillon);
        hierarchy_ailes_papillon.update_local_to_global_coordinates();
        if(gui_scene.surface)
            draw(hierarchy_ailes_papillon, scene.camera);
        if(gui_scene.wireframe)
            draw(hierarchy_ailes_papillon, scene.camera, shaders["wireframe"]);
        if(gui_scene.skeleton)
            hierarchy_ailes_papillon_visual_debug.draw(hierarchy_ailes_papillon, scene.camera);
        i = i+1;
    }
    glBindTexture(GL_TEXTURE_2D, scene.texture_white);


    //**************BILLBOARDS**************

        //herbes et fleurs
    glBindTexture(GL_TEXTURE_2D, texture_id_billboard_grass);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // avoids sampling artifacts
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // avoids sampling artifacts
    // Display a billboard always facing the camera direction
    surface_billboard.uniform.transform.rotation = scene.camera.orientation;

    for (unsigned int i=0; i<20; i++) {
        vec3 p=positions_billboard[i];
        surface_billboard.uniform.transform.translation = p;
        draw(surface_billboard, scene.camera, shaders["mesh"]);
        if(gui_scene.wireframe)
            draw(surface_billboard, scene.camera, shaders["wireframe"]);
    }
    glBindTexture(GL_TEXTURE_2D, scene.texture_white);
    glBindTexture(GL_TEXTURE_2D, texture_id_billboard_flower);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // avoids sampling artifacts
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // avoids sampling artifacts
    // Display a billboard always facing the camera direction
    surface_billboard.uniform.transform.rotation = scene.camera.orientation;

    for (unsigned int i=20; i<40; i++) {
        vec3 p=positions_billboard[i];
        surface_billboard.uniform.transform.translation = p;
        draw(surface_billboard, scene.camera, shaders["mesh"]);
        if(gui_scene.wireframe)
            draw(surface_billboard, scene.camera, shaders["wireframe"]);
    }
    glBindTexture(GL_TEXTURE_2D, scene.texture_white);
    glBindTexture(GL_TEXTURE_2D, texture_id_billboard_grass);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // avoids sampling artifacts
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // avoids sampling artifacts

    for (unsigned int i=40; i<140; i++) {
        vec3 p=positions_billboard[i];
        surface_billboard.uniform.transform.translation = p;
        draw(surface_billboard, scene.camera, shaders["mesh"]);
        if(gui_scene.wireframe)
            draw(surface_billboard, scene.camera, shaders["wireframe"]);
    }
    glBindTexture(GL_TEXTURE_2D, scene.texture_white);

    glBindTexture(GL_TEXTURE_2D, texture_id_billboard_flower);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // avoids sampling artifacts
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // avoids sampling artifacts
    // Display a billboard always facing the camera direction
    surface_billboard.uniform.transform.rotation = scene.camera.orientation;

    for (unsigned int i=140; i<240; i++) {
        vec3 p=positions_billboard[i];
        surface_billboard.uniform.transform.translation = p;
        draw(surface_billboard, scene.camera, shaders["mesh"]);
        if(gui_scene.wireframe)
            draw(surface_billboard, scene.camera, shaders["wireframe"]);
    }
    glBindTexture(GL_TEXTURE_2D, scene.texture_white);
    glDepthMask(false);
    glBindTexture(GL_TEXTURE_2D, texture_id_billboard_nenuphar);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // avoids sampling artifacts
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // avoids sampling artifacts
    // Display a billboard always facing the camera direction


    for (unsigned int i=240; i<270; i++) {
        vec3 p=positions_billboard[i];
        surface_nenuphar.uniform.transform.translation = p;
        draw(surface_nenuphar, scene.camera, shaders["mesh"]);
        if(gui_scene.wireframe)
            draw(surface_nenuphar, scene.camera, shaders["wireframe"]);
    }
    glBindTexture(GL_TEXTURE_2D, scene.texture_white);
    glDepthMask(true);

        //skybox
    glBindTexture(GL_TEXTURE_2D, texture_id_skybox);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    draw(skybox, scene.camera, shaders["mesh"]);
    glBindTexture(GL_TEXTURE_2D, scene.texture_white);
}





//********************************FONCTION SET GUI********************************


void scene_model::set_gui()
{
    ImGui::Text("Display: "); ImGui::SameLine();
    ImGui::Checkbox("Wireframe", &gui_scene.wireframe); ImGui::SameLine();
    ImGui::Checkbox("Surface", &gui_scene.surface);     ImGui::SameLine();
    ImGui::Checkbox("Skeleton", &gui_scene.skeleton);   ImGui::SameLine();

    ImGui::Spacing();
    ImGui::SliderFloat("Time_cerf", &timer_cerf.t, timer_cerf.t_min, timer_cerf.t_max);
    ImGui::SliderFloat("Time_cerf scale", &timer_cerf.scale, 0.0f, 3.0f);
    ImGui::SliderFloat("Time_papillon", &timer_papillon.t, timer_papillon.t_min, timer_papillon.t_max);
    ImGui::SliderFloat("Time_papillon scale", &timer_papillon.scale, 0.0f, 3.0f);
    ImGui::SliderFloat("Time_lapin", &timer_lapin.t, timer_lapin.t_min, timer_lapin.t_max);
    ImGui::SliderFloat("Time_lapin scale", &timer_lapin.scale, 0.0f, 3.0f);
}





#endif


