
#include "terrain_seul.hpp"
#include "scenes/3D_graphics/03_projet_final/fonctions_auxiliaires.hpp"

#include <random>

#ifdef SCENE_TERRAIN_SEUL

// Add vcl namespace within the current one - Allows to use function from vcl library without explicitely preceeding their name with vcl::
using namespace vcl;

// Evaluate height of the terrain for any (u,v) \in [0,1]
float evaluate_terrain_z(float u, float v);
float evaluate_lac_z(float u, float v);
// Evaluate 3D position of the terrain for any (u,v) \in [0,1]
vec3 evaluate_terrain(float u, float v);
vec3 evaluate_lac(float u, float v);
// Generate terrain mesh
mesh create_terrain();
mesh create_lac();
mesh create_skybox();
//mesh create_cylinder(float radius, float height, vec3 p, unsigned int N,float r);
//mesh create_cone(float radius, float height, vec3 p, unsigned int N);
mesh create_tree_foliage(float radius, float height, float z_offset, vec3 p, unsigned int N, float r);

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
//bool est_trop_proche(std::vector<vcl::vec3> positions,vec3 p,float dmin);


/** This function is called before the beginning of the animation loop
    It is used to initialize all part-specific data */
void scene_model::setup_data(std::map<std::string,GLuint>& shaders, scene_structure& scene, gui_structure& )
{
    // Setup initial camera mode and position
    scene.camera.camera_type = camera_control_spherical_coordinates;
    scene.camera.scale = 10.0f;
    scene.camera.apply_rotation(0,0,0,1.2f);


    //décor
    terrain = create_terrain();
    terrain.uniform.color = {0.6f,0.85f,0.5f};
    terrain.uniform.shading.specular = 0.0f;
    lac = create_lac();
    skybox = create_skybox();

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

    positions_billboard=update_billboard_position_zone7(positions_billboard,40,0.01f);
    positions_billboard=update_billboard_position(positions_billboard,200,0.01f);
    positions_billboard=update_nenuphar_position(positions_billboard,15,0.02f);


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

    // Load a texture image on GPU and stores its ID
    texture_id = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/grass.png") );
    texture_id_eau = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/EauLacText.png") );
    texture_id_skybox=create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/skybox.png") );
    terrain.texture_id=texture_id;
    lac.texture_id=texture_id_eau;
    skybox.texture_id=texture_id_skybox;
    texture_id_billboard_grass = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/billboard_grass.png"), GL_REPEAT, GL_REPEAT );
    texture_id_billboard_flower = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/billboard_flower1.png"), GL_REPEAT, GL_REPEAT );
    texture_id_billboard_nenuphar = create_texture_gpu( image_load_png("scenes/3D_graphics/03_projet_final/assets/nenuphar.png"), GL_REPEAT, GL_REPEAT );


}




/** This function is called at each frame of the animation loop.
    It is used to compute time-varying argument and perform data data drawing */
void scene_model::frame_draw(std::map<std::string,GLuint>& shaders, scene_structure& scene, gui_structure& )
{
    set_gui();

    glEnable( GL_POLYGON_OFFSET_FILL ); // avoids z-fighting when displaying wireframe



    // Display terrain
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glPolygonOffset( 1.0, 1.0 );
    draw(terrain, scene.camera, shaders["mesh"]);
    glBindTexture(GL_TEXTURE_2D, texture_id_eau);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    draw(lac, scene.camera, shaders["mesh"]);


    if( gui_scene.wireframe ){ // wireframe if asked from the GUI
        glPolygonOffset( 1.0, 1.0 );
        //draw(terrain, scene.camera, shaders["wireframe"]);
    }
    if( gui_scene.wireframe ){ // wireframe if asked from the GUI
        glPolygonOffset( 1.0, 1.0 );
        draw(lac, scene.camera, shaders["wireframe"]);
    }
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

    //fleurs et touffes d'herbe

    // Enable use of alpha component as color blending for transparent elements
    //  new color = previous color + (1-alpha) current color
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // Disable depth buffer writing
    //  - Transparent elements cannot use depth buffer
    //  - They are supposed to be display from furest to nearest elements
    glDepthMask(false);
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

    glBindTexture(GL_TEXTURE_2D, texture_id_skybox);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    draw(skybox, scene.camera, shaders["mesh"]);







}


//********DEFINITION DES FONCTIONS AUXILIAIRES********



// Evaluate height of the terrain for any (u,v) \in [0,1]
float evaluate_terrain_z(float u, float v)
{
    const float r2 =(u-0.5f)*(u-0.5f)+(v-0.5f)*(v-0.5f);
    const float r = std::sqrt(r2);
    if (r2<0.1f*0.1f){
        return -0.2f;
    }
    else if(r2<0.0144f) {
        return std::exp(4*(r-0.1))-0.7;
    }
    else {
        const float bar = std::exp(4*0.02)-0.7;
        const std::vector < std:: vector <float> > pi = {{0.2f,0.3f},{0.5f,0.0f},{0.2f,0.7f},{0.9f,0.9f}};
        const std::vector<float> hi = {1,0.7,0.7,0.8};
        const std::vector<float> sigmai = {0.5f,0.15f,0.2f,0.2f};
        float somme= 0.0f;
        const int n = hi.size();

        for (int i=0;i<n;i++){
            float sigma = sigmai[i];
            float h = hi[i];
            vec2 p = {pi[i][0],pi[i][1]};
            float d = norm(vec2(u,v)-p)/sigma;
            float z = h*std::exp(-d*d);
            somme=somme+z;
        };
        return bar + ((r-0.12f)/0.3f)*(somme-bar);
    }

}
float evaluate_lac_z(float u, float v)
{
    const float r2 =(u-0.5f)*(u-0.5f)+(v-0.5f)*(v-0.5f);
    const float r= std::sqrt(r2);
    if (r2<0.4f*0.4f){
        return 0.2f;
    }
    else if(r2<0.5f*0.5f){
        return std::exp(-(r-0.4f))-1.1f;
    }
    else {
        return -0.5f;
    }
}

// Evaluate 3D position of the terrain for any (u,v) \in [0,1]
vec3 evaluate_terrain(float u, float v)
{
    const float x = 20*(u-0.5f);
    const float y = 20*(v-0.5f);
    const float z = evaluate_terrain_z(u,v);

    return {x,y,z};
}
vec3 evaluate_lac(float u, float v)
{
    const float x = 5*(u-0.5f);
    const float y = 5*(v-0.5f);
    const float z = evaluate_lac_z(u,v);

    return {x,y,z};
}

// Generate terrain mesh
mesh create_terrain()
{
    // Number of samples of the terrain is N x N
    const size_t N = 500;
    const float height = 0.3f;
    const float scaling = 3.0f;
    const int octave = 9;
    const float persistency = 0.5f;

    mesh terrain; // temporary terrain storage (CPU only)
    terrain.position.resize(N*N);
    terrain.color.resize(N*N);
    terrain.texture_uv.resize(N*N);

    // Fill terrain geometry
    for(size_t ku=0; ku<N; ++ku)
    {
        for(size_t kv=0; kv<N; ++kv)
        {
            // Compute local parametric coordinates (u,v) \in [0,1]
            const float u = ku/(N-1.0f);
            const float v = kv/(N-1.0f);
            const float r2 =(u-0.5f)*(u-0.5f)+(v-0.5f)*(v-0.5f);
            const float r = std::sqrt(r2);

            if (r2<0.1f*0.1f){
                terrain.position[kv+N*ku] = evaluate_terrain(u,v);
                terrain.color[kv+N*ku] = {0.1f,0.5f,1.0f,1.0f};

            }
            else if (r<0.12){
                // Evaluate Perlin noise
                const float noise = perlin(scaling*u, scaling*v, octave, persistency);
                // 3D vertex coordinates
                vec3 pos=evaluate_terrain(u,v);
                const float x = pos[0];
                const float y = pos[1];
                float z = pos[2];
                z=z+height*(noise-1.0f);
                const float c = 0.3f+0.7f*noise;
                // Compute coordinates
                terrain.position[kv+N*ku] = {x,y,z};
                const float cbis = c*((r-0.1)/0.02);
                terrain.color[kv+N*ku]  = {cbis,cbis,cbis,1.0f};
                terrain.texture_uv[kv+N*ku]={u*8,v*8};
            }
            else {
                // Evaluate Perlin noise
                const float noise = perlin(scaling*u, scaling*v, octave, persistency);
                // 3D vertex coordinates
                vec3 pos=evaluate_terrain(u,v);
                const float x = pos[0];
                const float y = pos[1];
                float z = pos[2];
                z=z+height*(noise-1.0f);
                const float c = 0.3f+0.7f*noise;
                // Compute coordinates
                terrain.position[kv+N*ku] = {x,y,z};
                terrain.color[kv+N*ku]  = {c,c,c,1.0f};
                terrain.texture_uv[kv+N*ku]={u*8,v*8};
            }


        }
    }


    // Generate triangle organization
    //  Parametric surface with uniform grid sampling: generate 2 triangles for each grid cell
    const unsigned int Ns = N;
    for(unsigned int ku=0; ku<Ns-1; ++ku)
    {
        for(unsigned int kv=0; kv<Ns-1; ++kv)
        {
            const unsigned int idx = kv + N*ku; // current vertex offset

            const uint3 triangle_1 = {idx, idx+1+Ns, idx+1};
            const uint3 triangle_2 = {idx, idx+Ns, idx+1+Ns};

            terrain.connectivity.push_back(triangle_1);
            terrain.connectivity.push_back(triangle_2);
        }
    }

    return terrain;
}

mesh create_lac(){
    // Number of samples of the lake is N x N
    const size_t N = 1000;
    const float height = 0.05f;
    const float scaling = 2.0f;
    const int octave = 9;
    const float persistency = 0.5f;

    mesh lac; // temporary terrain storage (CPU only)
    lac.position.resize(N*N);
    lac.color.resize(N*N);
    lac.texture_uv.resize(N*N);

    // Fill terrain geometry
    for(size_t ku=0; ku<N; ++ku)
    {
        for(size_t kv=0; kv<N; ++kv)
        {
            // Compute local parametric coordinates (u,v) \in [0,1]
            const float u = ku/(N-1.0f);
            const float v = kv/(N-1.0f);
            // Evaluate Perlin noise
            const float noise = perlin(scaling*u, scaling*v, octave, persistency);
            const float c = 0.3f+0.7f*noise;


                vec3 pos=evaluate_lac(u,v);
                lac.position[kv+N*ku] = {pos[0], pos[1], pos[2]+0.008f*std::cos(pos[0]*9)+0.012f*std::cos(pos[1]*11)+height*(noise-1.0f)};
                lac.color[kv+N*ku] = {0.075f+c,0.15f+c,0.75f+c,1.0f};
                lac.texture_uv[kv+N*ku]={u,v};


         }
    }
    // Generate triangle organization
    //  Parametric surface with uniform grid sampling: generate 2 triangles for each grid cell
    const unsigned int Ns = N;
    for(unsigned int ku=0; ku<Ns-1; ++ku)
    {
        for(unsigned int kv=0; kv<Ns-1; ++kv)
        {
            const unsigned int idx = kv + N*ku; // current vertex offset

            const uint3 triangle_1 = {idx, idx+1+Ns, idx+1};
            const uint3 triangle_2 = {idx, idx+Ns, idx+1+Ns};

            lac.connectivity.push_back(triangle_1);
            lac.connectivity.push_back(triangle_2);
        }
    }

    return lac;

}

mesh create_skybox(){
    mesh skybox;
    skybox.position={{-40,40,-40},{-40,40,40},{-40,-40,40},{-40,40,40},{40,40,40},{40,-40,40},{40,40,40},{-40,40,40},{-40,40,-40},{40,40,-40},{40,-40,-40},{40,40,-40},{-40,40,-40},{-40,-40,-40}};
    skybox.texture_uv={{0,0.35}, {0,0.64}, {0.26,0.64}, {0.27,1},{0.5,1},{0.5,0.64},{0.75,0.64},{1,0.64},{1,0.35},{0.75,0.35},{0.5,0.35},{0.5,0},{0.27,0},{0.27,0.35}};
    skybox.connectivity={{0,1,2},{0,2,13},{2,3,4},{2,4,5},{13,5,10},{13,2,5},{12,13,10},{12,10,11},{10,5,6},{10,6,9},{9,6,7},{9,7,8}};
    return skybox;
}

/**mesh create_cylinder(float radius, float height, vec3 p, unsigned int N,float r){

    const float radiusr= r*radius;
    const float heightr = r*height;
    const float theta = 2*3.14f/N;
    mesh cylinder;
    const float x = p[0];
    const float y = p[1];
    const float z = p[2];

    for (unsigned int n=0; n<N; n++){
       float xn = radiusr*std::cos(n*theta);
       float yn = radiusr*std::sin(n*theta);
       cylinder.position.push_back({x+xn,y+yn,z});
       cylinder.position.push_back({x+xn,y+yn,z+heightr});
    }
    for (unsigned int i=0; i<2*N-2; i++){
        if (i%2==0){
            cylinder.connectivity.push_back({i,i+2,i+1});
         }
        else{
            cylinder.connectivity.push_back({i,i+1,i+2});
        }
    }

    cylinder.connectivity.push_back({2*N-2,0,2*N-1});
    cylinder.connectivity.push_back({2*N-1,0,1});

    return cylinder;
}*/



/**mesh create_cone(float radius, float height, vec3 p, unsigned int N){
    const float theta = 2*3.14f/N;
    mesh cone;
    const float x = p[0];
    const float y = p[1];
    const float z = p[2];

    for (unsigned int n=0; n<N; n++){
        float xn = radius*std::cos(n*theta);
        float yn = radius*std::sin(n*theta);
        cone.position.push_back({x+xn,y+yn,z});
    }

    cone.position.push_back({x,y,z});
    cone.position.push_back({x,y,z+height});

    for (unsigned int i=0; i<N-1; i++){
        cone.connectivity.push_back({i,i+1,N});
        cone.connectivity.push_back({i,i+1,N+1});
    }
    cone.connectivity.push_back({N-1,0,N});
    cone.connectivity.push_back({N-1,0,N+1});

    return cone;
}*/



mesh create_tree_foliage(float radius, float height, float z_offset, vec3 p, unsigned int N, float r){
    mesh m = create_cone(radius*r, height*r, p, N);
    p={p[0],p[1],p[2]+z_offset};
    m.push_back( create_cone(radius*r, height*r, p, N) );
    p={p[0],p[1],p[2]+z_offset};
    m.push_back( create_cone(radius*r, height*r, p, N) );
    return m;
}

std::vector<vcl::vec3> update_trees_position1(std::vector<vcl::vec3> positions1, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.0f,0.4f);
        float v = rand_interval(0.0f,0.4f);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions1,p,dmin);

        while (trop_proche == true){
            u = rand_interval(0.0f,0.4f);
            v = rand_interval(0.0f,0.4f);
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions1,p,dmin);
        }
        positions1.push_back(p);
    }

    return positions1;
}
std::vector<vcl::vec3> update_trees_position2(std::vector<vcl::vec3> positions2, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.0f,0.4f);
        float v = rand_interval(0.4f,0.6f);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions2,p,dmin);

        while (trop_proche == true){
            u = rand_interval(0.0f,0.4f);
            v = rand_interval(0.4f,0.6f);
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions2,p,dmin);
        }
        positions2.push_back(p);
    }

    return positions2;
}
std::vector<vcl::vec3> update_trees_position3(std::vector<vcl::vec3> positions3, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.0f,0.4f);
        float v = rand_interval(0.6f,1.0f);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions3,p,dmin);

        while (trop_proche == true){
            u = rand_interval(0.0f,0.4f);
            v = rand_interval(0.6f,1.0f);
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions3,p,dmin);
        }
        positions3.push_back(p);
    }

    return positions3;
}
std::vector<vcl::vec3> update_trees_position4(std::vector<vcl::vec3> positions4, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.4f,0.6f);
        float v = rand_interval(0.6f,1.0f);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions4,p,dmin);

        while (trop_proche == true){
            u = rand_interval(0.4f,0.6f);
            v = rand_interval(0.6f,1.0f);
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions4,p,dmin);
        }
        positions4.push_back(p);
    }

    return positions4;
}
std::vector<vcl::vec3> update_trees_position5(std::vector<vcl::vec3> positions5, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.6f,1.0f);
        float v = rand_interval(0.6f,1.0f);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions5,p,dmin);

        while (trop_proche == true){
            u = rand_interval(0.6f,1.0f);
            v = rand_interval(0.6f,1.0f);
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions5,p,dmin);
        }
        positions5.push_back(p);
    }

    return positions5;
}
std::vector<vcl::vec3> update_trees_position6(std::vector<vcl::vec3> positions6, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.6f,1.0f);
        float v = rand_interval(0.4f,0.6f);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions6,p,dmin);

        while (trop_proche == true){
            u = rand_interval(0.6f,1.0f);
            v = rand_interval(0.4f,0.6f);
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions6,p,dmin);
        }
        positions6.push_back(p);
    }

    return positions6;
}
std::vector<vcl::vec3> update_trees_position7(std::vector<vcl::vec3> positions7, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.6f,1.0f);
        float v = rand_interval(0.0f,0.4f);
        float r2 = (u-0.8)*(u-0.8)+(v-0.2)*(v-0.2);
        float r = std::sqrt(r2);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions7,p,dmin);
        bool dans_clairiere = r<0.08;


        while (trop_proche == true || dans_clairiere==true){
            u = rand_interval(0.6f,1.0f);
            v = rand_interval(0.0f,0.4f);
            r2 = (u-0.8)*(u-0.8)+(v-0.2)*(v-0.2);
            r = std::sqrt(r2);
            dans_clairiere = r<0.08;
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions7,p,dmin);

        }
        positions7.push_back(p);
    }

    return positions7;
}
std::vector<vcl::vec3> update_trees_position8(std::vector<vcl::vec3> positions8, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.4f,0.6f);
        float v = rand_interval(0.0f,0.4f);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions8,p,dmin);

        while (trop_proche == true){
            u = rand_interval(0.4f,0.6f);
            v = rand_interval(0.0f,0.4f);
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions8,p,dmin);
        }
        positions8.push_back(p);
    }

    return positions8;
}

std::vector<vcl::vec3> update_billboard_position_zone7(std::vector<vcl::vec3> positions, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.7f,0.9f);
        float v = rand_interval(0.1f,0.3f);
        float r2 = (u-0.8)*(u-0.8)+(v-0.2)*(v-0.2);
        float r = std::sqrt(r2);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions,p,dmin);
        bool dans_clairiere = r<0.08;


        while (trop_proche == true || dans_clairiere==false){
            u = rand_interval(0.7f,0.9f);
            v = rand_interval(0.1f,0.3f);
            r2 = (u-0.8)*(u-0.8)+(v-0.2)*(v-0.2);
            r = std::sqrt(r2);
            dans_clairiere = r<0.08;
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions,p,dmin);

        }
        positions.push_back(p);
    }

    return positions;
}
std::vector<vcl::vec3> update_billboard_position(std::vector<vcl::vec3> positions, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0,1);
        float v = rand_interval(0,1);
        float r2 = (u-0.5)*(u-0.5)+(v-0.5)*(v-0.5);
        vec3 p = evaluate_terrain(u,v);
        bool trop_proche = est_trop_proche(positions,p,dmin);
        bool est_dans_lac = r2<0.01;


        while (trop_proche || est_dans_lac){
            u = rand_interval(0,1);
            v = rand_interval(0,1);
            r2 = (u-0.5)*(u-0.5)+(v-0.5)*(v-0.5);
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions,p,dmin);
            est_dans_lac = r2<0.01;

        }
        positions.push_back(p);
    }

    return positions;
}
std::vector<vcl::vec3> update_nenuphar_position(std::vector<vcl::vec3> positions, unsigned int N, float dmin){
    for (unsigned int i=0; i<N ; i++){
        float u = rand_interval(0.4,0.6);
        float v = rand_interval(0.4,0.6);
        float r2 = (u-0.5)*(u-0.5)+(v-0.5)*(v-0.5);
        vec3 p = evaluate_terrain(u,v);
        vec3 d =evaluate_lac(u,v);
        bool trop_proche = est_trop_proche(positions,p,dmin);
        bool est_dans_lac = r2<0.006;


        while (trop_proche || est_dans_lac==false){
            u = rand_interval(0,1);
            v = rand_interval(0,1);
            r2 = (u-0.5)*(u-0.5)+(v-0.5)*(v-0.5);
            p = evaluate_terrain(u,v);
            trop_proche = est_trop_proche(positions,p,dmin);
            est_dans_lac = r2<0.006;

        }
        positions.push_back({p[0],p[1],d[2]+0.04f});
    }

    return positions;
}

/**bool est_trop_proche(std::vector<vcl::vec3> positions,vec3 p, float dmin){
    bool trop_proche = false;
    float x = p[0];
    float y = p[1];
    for (auto pbis : positions){
        float xbis = pbis[0];
        float ybis = pbis[1];
        float d = norm(vec2(x,y)-vec2(xbis,ybis));
        if (d<dmin){
            trop_proche = true;
        }
    }

    return trop_proche;
}*/

/**bool est_trop_proche(std::vector<vcl::vec3> positions,vcl::vec3 p, float dmin){
    bool trop_proche = false;
    float x = p[0];
    float y = p[1];
    float z = p[2];
    for (auto pbis : positions){
        float xbis = pbis[0];
        float ybis = pbis[1];
        float zbis = pbis[2];
        float d = norm(vec3(x,y,z)-vec3(xbis,ybis,zbis));
        if (d<dmin){
            trop_proche = true;
        }
    }

    return trop_proche;
}*/


void scene_model::set_gui()
{
    ImGui::Checkbox("Wireframe", &gui_scene.wireframe);
}


#endif

