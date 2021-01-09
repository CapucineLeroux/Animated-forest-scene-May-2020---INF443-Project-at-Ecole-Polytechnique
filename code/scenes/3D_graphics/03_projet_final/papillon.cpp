#include "papillon.hpp"
#include "scene_finale.hpp"
#include <random>

#ifdef SCENE_PROJET_FINAL

using namespace vcl;




vcl::hierarchy_mesh_drawable data_corps_papillon(vcl::hierarchy_mesh_drawable hierarchy_corps_papillon){
    float a_corps = 0.05f;

    mesh_drawable corps = mesh_drawable( create_ovale(a_corps,a_corps-0.0005f,{0,0,0},50,50));
    mesh_drawable antenne = mesh_drawable(mesh_primitive_cylinder(0.001f,{0,0,0},{0,0,a_corps}));

    vec3 noir = {0,0,0};

    corps.uniform.color = noir;
    antenne.uniform.color = noir;

    float pi = 3.14f;
    float theta1 = pi/6.0f;

    hierarchy_corps_papillon.add(corps,"corps");
    hierarchy_corps_papillon.add(antenne,"antenne_dt","corps",{{0,0,a_corps},Ry(theta1)});
    hierarchy_corps_papillon.add(antenne,"antenne_gc","corps",{{0,0,a_corps},Ry(-theta1)});

    return hierarchy_corps_papillon;
}



vcl::hierarchy_mesh_drawable draw_corps_papillon(vcl::hierarchy_mesh_drawable hierarchy_corps_papillon, float t_reel, vcl::buffer<vec3t> keyframes_papillon){
    const float t0 = keyframes_papillon[0].t;
    const float t1 = keyframes_papillon[1].t;
    const float t2 = keyframes_papillon[2].t;
    const float t3 = keyframes_papillon[3].t;
    const vec3& p0 = keyframes_papillon[0].p;
    const vec3& p1 = keyframes_papillon[1].p;
    const vec3& p2 = keyframes_papillon[2].p;
    const vec3& p3 = keyframes_papillon[3].p;
    const float K = 0.5f;
    const float delta = 0.5f;
    const vec3 p = cardinal_spline_interpolation(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K);
    const vec3 dp = derive_p(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K,delta);
    const mat3 R_body = rotation_objet_anime(dp);

    hierarchy_corps_papillon["corps"].transform.scaling = 0.7f;
    hierarchy_corps_papillon["corps"].transform.rotation = R_body;
    hierarchy_corps_papillon["corps"].transform.translation = p;

    return hierarchy_corps_papillon;
}



vcl::hierarchy_mesh_drawable data_ailes_papillon(vcl::hierarchy_mesh_drawable hierarchy_ailes_papillon){
    float a_corps = 0.05f;
    float k = 2.0f;

    mesh_drawable corps = mesh_drawable( create_ovale(a_corps,a_corps-0.0005f,{0,0,0},50,50));
    mesh aile_cpu;
    aile_cpu.position = {{0,0,0},{0.07f,0,0},{0.07f,0,0.07f*k},{0,0,0.07f*k}};
    aile_cpu.connectivity = {{0,1,2},{0,2,3}};
    aile_cpu.texture_uv = {{0,1}, {1,1}, {1,0}, {0,0}};
    mesh_drawable aile = aile_cpu;

    vec3 noir = {0,0,0};

    corps.uniform.color = noir;
    aile.uniform.shading = {1,0,0};

    float pi = 3.14f;

    hierarchy_ailes_papillon.add(corps,"corps");
    hierarchy_ailes_papillon.add(aile,"aile_gc","corps",vec3(0,0,-0.09f));
    hierarchy_ailes_papillon.add(aile,"aile_dt","corps",{{0,0,-0.09f},Rz(pi)});

    return hierarchy_ailes_papillon;
}



vcl::hierarchy_mesh_drawable draw_ailes_papillon(vcl::hierarchy_mesh_drawable hierarchy_ailes_papillon, float t_reel, vcl::buffer<vec3t> keyframes_papillon){
    const float t0 = keyframes_papillon[0].t;
    const float t1 = keyframes_papillon[1].t;
    const float t2 = keyframes_papillon[2].t;
    const float t3 = keyframes_papillon[3].t;
    const vec3& p0 = keyframes_papillon[0].p;
    const vec3& p1 = keyframes_papillon[1].p;
    const vec3& p2 = keyframes_papillon[2].p;
    const vec3& p3 = keyframes_papillon[3].p;
    const float K = 0.5f;
    const float delta = 0.5f;
    const vec3 p = cardinal_spline_interpolation(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K);
    const vec3 dp = derive_p(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K,delta);
    const mat3 R_body = rotation_objet_anime(dp);
    float t = t_reel;

    float pi = 3.14f;
    float theta1 = 0.9f*sin(40.0f*3.14f*(t-0.4f));

    hierarchy_ailes_papillon["corps"].transform.scaling = 0.7f;
    hierarchy_ailes_papillon["corps"].transform.rotation = R_body;
    hierarchy_ailes_papillon["corps"].transform.translation = p;
    hierarchy_ailes_papillon["aile_gc"].transform.rotation = Rz(theta1);
    hierarchy_ailes_papillon["aile_dt"].transform.rotation = Rz(pi-theta1);

    return hierarchy_ailes_papillon;
}



std::vector <vcl::buffer<vec3t>> update_keyframes_papillon(std::vector<vcl::buffer<vec3t>> keyframes_papillons, float t_min, float t_max){
    float t1 = keyframes_papillons[0][1].t;
    float t2 = keyframes_papillons[0][2].t;

    if ( (t1 == t_min) && (t2 == t_max) ){
        return keyframes_papillons;
    }
    else{
        const float t0 = keyframes_papillons[0][1].t;
        t1 = keyframes_papillons[0][2].t;
        t2 = keyframes_papillons[0][3].t;
        const float t3 = t2 + 1.0f;

        float xmin = -2.0f;
        float xmax = 2.0f;
        float ymin = -2.0f;
        float ymax = 2.0f;
        float zmin = 0.5f;
        float zmax = 2.5f;

        unsigned int N = keyframes_papillons.size();
        std::vector <vec3> positions3;

        for (unsigned int i=0 ; i<N ; i++){
            const vec3& p0 = keyframes_papillons[i][1].p;
            const vec3& p1 = keyframes_papillons[i][2].p;
            const vec3& p2 = keyframes_papillons[i][3].p;
            vec3 p3 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);

            while (est_trop_proche(positions3,p3,0.3f)){
                p3 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
            }

            positions3.push_back(p3);
            keyframes_papillons[i] = { { p0 , t0 },
                            { p1 , t1 },
                            { p2 , t2 },
                            { p3 , t3 },
                             };
        }

        return keyframes_papillons;
    }
}



std::vector <vcl::buffer<vec3t>> init_keyframes_papillon (unsigned int N){
    std::vector <vec3> positions0;
    std::vector <vec3> positions1;
    std::vector <vec3> positions2;
    std::vector <vec3> positions3;
    std::vector <vcl::buffer<vec3t>> keyframes_papillons;
    float xmin = -2.0f;
    float xmax = 2.0f;
    float ymin = -2.0f;
    float ymax = 2.0f;
    float zmin = 0.5f;
    float zmax = 2.5f;

    for (unsigned int i=0 ; i<N ; i++){
        vec3 p0 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        while (est_trop_proche(positions0,p0,0.3f)){
            p0 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        }
        vec3 p1 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        while (est_trop_proche(positions1,p1,0.3f)){
            p1 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        }
        vec3 p2 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        while (est_trop_proche(positions2,p2,0.3f)){
            p2 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        }
        vec3 p3 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        while (est_trop_proche(positions3,p3,0.3f)){
            p3 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        }
        vcl::buffer<vec3t> keyframes_papillon = { { p0 , -1.0f },
                                                  { p1 , 0.0f  },
                                                  { p2 , 1.0f  },
                                                  { p3 , 2.0f  },
                                                  };
        keyframes_papillons.push_back(keyframes_papillon);
    }
    return keyframes_papillons;
}



std::vector <int> init_couleur_papillon(unsigned int N){
    std::vector <int> couleur_papillons;
    for (unsigned int i=0 ; i<N ; i++){
        float indice = rand_interval(0.0f,4.0f);
        if (0.0f<=indice && indice<1.0f){
            couleur_papillons.push_back(1);
        }
        if (1.0f<=indice && indice<2.0f){
            couleur_papillons.push_back(2);
        }
        if (2.0f<=indice && indice<3.0f){
            couleur_papillons.push_back(3);
        }
        if (3.0f<=indice && indice<=4.0f){
            couleur_papillons.push_back(4);
        }
    }
    return couleur_papillons;
}


#endif
