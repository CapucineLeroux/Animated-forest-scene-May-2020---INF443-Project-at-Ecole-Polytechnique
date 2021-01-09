#include "lapin.hpp"
#include "scene_finale.hpp"
#include "terrain.hpp"
#include <random>

#ifdef SCENE_PROJET_FINAL
using namespace vcl;


vcl::hierarchy_mesh_drawable data_lapin(vcl::hierarchy_mesh_drawable hierarchy_lapin){
    mesh_drawable corps = mesh_drawable(create_ellipsoide(0.08f,0.09f,0.17f,{0,0,0},100,100));
    mesh_drawable cou = mesh_drawable(create_ellipsoide(0.02f,0.1f,0.04f,{0,0,0},100,100));
    mesh_drawable tete = mesh_drawable(create_ellipsoide(0.04f,0.05f,0.08f,{0,0,0},100,100));
    mesh_drawable oreille = mesh_drawable(create_ellipse(0.075f,0.07f,{0,0,0},100));
    mesh_drawable oeil = mesh_drawable(mesh_primitive_sphere(0.01f,{0,0,0},50,50));
    mesh_drawable moustache = mesh_drawable(mesh_primitive_cylinder(0.0005f,{0,0,0},{0,0,0.04f},50,50));
    mesh nez_cpu;
    nez_cpu.position = {{-0.005f,0,0},{0.005f,0,0},{0,0.01f,0}};
    nez_cpu.connectivity = {{0,1,2}};
    mesh_drawable nez = mesh_drawable(nez_cpu);
    mesh_drawable queue = mesh_drawable(create_ellipsoide(0.03f,0.05f,0.03f,{0,0,0},100,100));
    mesh_drawable leg_up_arr = mesh_drawable(create_ellipsoide(0.04f,0.08f,0.06f,{0,0,0},100,100));
    mesh_drawable leg_mid_arr = mesh_drawable(create_ellipsoide(0.03f,0.06f,0.03f,{0,0,0},100,100));
    mesh_drawable leg_down_arr = mesh_drawable(mesh_primitive_cylinder(0.02f,{0,0,0},{0,-0.08f,0},100,100));
    mesh_drawable pate = mesh_drawable(create_ellipsoide(0.025f,0.04f,0.02f,{0,0,0},100,100));
    mesh_drawable leg_up_av = mesh_drawable(create_ellipsoide(0.02f,0.08f,0.03f,{0,0,0},100,100));
    mesh_drawable leg_down_av = mesh_drawable(mesh_primitive_cylinder(0.015f,{0,0,0},{0,-0.08f,0},100,100));

    vec3 gris = {0.5,0.43,0.35};
    vec3 gris_clair = {0.73,0.68,0.6};
    vec3 noir = {0,0,0};
    vec3 rose = {1.0f,0.75f,0.82f};
    corps.uniform.color = gris;
    cou.uniform.color = gris;
    tete.uniform.color = gris;
    oreille.uniform.color = gris;
    oeil.uniform.color = noir;
    moustache.uniform.color = gris_clair;
    nez.uniform.color = rose;
    queue.uniform.color = gris_clair;
    leg_up_arr.uniform.color = gris;
    leg_mid_arr.uniform.color = gris;
    leg_down_arr.uniform.color = gris;
    pate.uniform.color = gris;
    leg_up_av.uniform.color = gris;
    leg_down_av.uniform.color = gris;

    float pi = 3.14f;
    float theta1 = pi/10.0f;
    float theta2 = -theta1;
    float theta3 = -pi/2.0f-pi/6.0f;
    float theta4 = -pi/3.0f;
    float theta5 = pi/2.0f;
    float theta6 = pi/8.0f;
    float theta7 = -pi/4.0f;
    float theta8 = pi/2.0f;
    float theta9 = -pi/2.0f;
    float theta10 = -pi/2.0f - theta7 -theta8 - theta9;
    float theta11 = pi/8.0f;
    float theta12 = -2.0f*theta11;
    float theta13 = -pi/2.0f - theta11 -theta12;

    hierarchy_lapin.add(corps,"corps");
    hierarchy_lapin.add(cou,"cou","corps",{{0,0.04f,0.12f},Rx(theta1)});
    hierarchy_lapin.add(tete,"tete","cou",{{0,0.08f,0.04f},Rx(theta2)});
    hierarchy_lapin.add(oreille,"oreille_dt","tete",{{-0.035f,0.08f,-0.05f},Ry(theta4)*Rx(theta3)});
    hierarchy_lapin.add(oreille,"oreille_gc","tete",{{0.035f,0.08f,-0.05f},Ry(-theta4)*Rx(theta3)});
    hierarchy_lapin.add(oeil,"oeil_dt","tete",vec3(-0.034f,0.02f,0.01f));
    hierarchy_lapin.add(oeil,"oeil_gc","tete",vec3(0.034f,0.02f,0.01f));
    hierarchy_lapin.add(moustache,"moustache_mid_dt","tete",{{-0.02f,-0.01f,0.06f},Ry(theta5)});
    hierarchy_lapin.add(moustache,"moustache_up_dt","tete",{{-0.02f,-0.005f,0.06f},Rz(-theta6)*Ry(theta5)});
    hierarchy_lapin.add(moustache,"moustache_down_dt","tete",{{-0.02f,-0.015f,0.06f},Rz(theta6)*Ry(theta5)});
    hierarchy_lapin.add(moustache,"moustache_mid_gc","tete",{{0.02f,-0.01f,0.06f},Ry(-theta5)});
    hierarchy_lapin.add(moustache,"moustache_up_gc","tete",{{0.02f,-0.005f,0.06f},Rz(theta6)*Ry(-theta5)});
    hierarchy_lapin.add(moustache,"moustache_down_gc","tete",{{0.02f,-0.015f,0.06f},Rz(-theta6)*Ry(-theta5)});
    hierarchy_lapin.add(nez,"nez","tete",vec3(0,0,0.0801f));
    hierarchy_lapin.add(queue,"queue","corps",vec3(0,0,-0.16f));
    hierarchy_lapin.add(leg_up_arr,"leg_up_arr_dt","corps",{{-0.03f,-0.02f,-0.07f},Rx(theta7)});
    hierarchy_lapin.add(leg_mid_arr,"leg_mid_arr_dt","leg_up_arr_dt",{{0.0f,-0.06f,-0.05f},Rx(theta8)});
    hierarchy_lapin.add(leg_down_arr,"leg_down_arr_dt","leg_mid_arr_dt",{{0.0f,-0.04f,0.0f},Rx(theta9)});
    hierarchy_lapin.add(pate,"pate_arr_dt","leg_down_arr_dt",{{0.0f,-0.095f,0.01f},Rx(theta10)});
    hierarchy_lapin.add(leg_up_arr,"leg_up_arr_gc","corps",{{0.03f,-0.02f,-0.07f},Rx(theta7)});
    hierarchy_lapin.add(leg_mid_arr,"leg_mid_arr_gc","leg_up_arr_gc",{{0.0f,-0.06f,-0.05f},Rx(theta8)});
    hierarchy_lapin.add(leg_down_arr,"leg_down_arr_gc","leg_mid_arr_gc",{{0.0f,-0.04f,0.0f},Rx(theta9)});
    hierarchy_lapin.add(pate,"pate_arr_gc","leg_down_arr_gc",{{0.0f,-0.095f,0.01f},Rx(theta10)});
    hierarchy_lapin.add(leg_up_av,"leg_up_av_dt","corps",{{-0.02f,-0.04f,0.09f},Rx(theta11)});
    hierarchy_lapin.add(leg_down_av,"leg_down_av_dt","leg_up_av_dt",{{0.0f,-0.06f,0.0f},Rx(theta12)});
    hierarchy_lapin.add(pate,"pate_av_dt","leg_down_av_dt",{{0.0f,-0.105f,0.02f},Rx(theta13)});
    hierarchy_lapin.add(leg_up_av,"leg_up_av_gc","corps",{{0.02f,-0.04f,0.09f},Rx(theta11)});
    hierarchy_lapin.add(leg_down_av,"leg_down_av_gc","leg_up_av_gc",{{0.0f,-0.06f,0.0f},Rx(theta12)});
    hierarchy_lapin.add(pate,"pate_av_gc","leg_down_av_gc",{{0.0f,-0.105f,0.02f},Rx(theta13)});

    return hierarchy_lapin;
}



vcl::hierarchy_mesh_drawable draw_lapin(vcl::hierarchy_mesh_drawable hierarchy_lapin, float t_reel, vcl::buffer<vec3t> keyframes_lapin){
    const float t0 = keyframes_lapin[0].t;
    const float t1 = keyframes_lapin[1].t;
    const float t2 = keyframes_lapin[2].t;
    const float t3 = keyframes_lapin[3].t;
    const vec3& p0 = keyframes_lapin[0].p;
    const vec3& p1 = keyframes_lapin[1].p;
    const vec3& p2 = keyframes_lapin[2].p;
    const vec3& p3 = keyframes_lapin[3].p;
    const float K = 0.5f;
    const float delta = 0.5f;
    const vec3 p = cardinal_spline_interpolation(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K);
    const vec3 dp = derive_p(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K,delta);
    const mat3 R_body = rotation_objet_anime(dp);
    float t = t_reel;

    hierarchy_lapin["corps"].transform.scaling = 0.5f;

    hierarchy_lapin["corps"].transform.rotation = R_body;
    hierarchy_lapin["corps"].transform.translation = p;

    float pi = 3.14f;
    float theta1 = sin(6.0f*3.14f*(t-0.4f));
    float theta2 = pi/3.0f - sin(6.0f*3.14f*(t-0.4f));
    float theta3 = -pi/2.0f + sin(6.0f*3.14f*(t-0.4f));
    float theta4 = -pi/2.0f - theta1 -theta2 - theta3;
    float theta5 = -sin(6.0f*3.14f*(t-0.35f));
    float theta6 = -pi/4.0f + sin(6.0f*3.14f*(t-0.35f));
    float theta7 = -pi/2.0f -theta5 - theta6;
    float theta8 = pi/9.0f + 0.2f*sin(6.0f*3.14f*(t-0.35f));

    hierarchy_lapin["leg_up_arr_dt"].transform.rotation = Rx(theta1);
    hierarchy_lapin["leg_mid_arr_dt"].transform.rotation = Rx(theta2);
    hierarchy_lapin["leg_down_arr_dt"].transform.rotation = Rx(theta3);
    hierarchy_lapin["pate_arr_dt"].transform.rotation = Rx(theta4);
    hierarchy_lapin["leg_up_arr_gc"].transform.rotation = Rx(theta1);
    hierarchy_lapin["leg_mid_arr_gc"].transform.rotation = Rx(theta2);
    hierarchy_lapin["leg_down_arr_gc"].transform.rotation = Rx(theta3);
    hierarchy_lapin["pate_arr_gc"].transform.rotation = Rx(theta4);
    hierarchy_lapin["leg_up_av_dt"].transform.rotation = Rx(theta5);
    hierarchy_lapin["leg_down_av_dt"].transform.rotation = Rx(theta6);
    hierarchy_lapin["pate_av_dt"].transform.rotation = Rx(theta7);
    hierarchy_lapin["leg_up_av_gc"].transform.rotation = Rx(theta5);
    hierarchy_lapin["leg_down_av_gc"].transform.rotation = Rx(theta6);
    hierarchy_lapin["pate_av_gc"].transform.rotation = Rx(theta7);
    hierarchy_lapin["cou"].transform.rotation = Rx(theta8);
    hierarchy_lapin["tete"].transform.rotation = Rx(-theta8);

    return hierarchy_lapin;
}



std::vector <vcl::buffer<vec3t>> update_keyframes_lapin(std::vector<vcl::buffer<vec3t>> keyframes_lapins, float t_min, float t_max, std::vector<std::vector<vcl::vec3>> positions_arbres){
    float t1 = keyframes_lapins[0][1].t;
    float t2 = keyframes_lapins[0][2].t;

    if ( (t1 == t_min) && (t2 == t_max) ){
        return keyframes_lapins;
    }
    else{
        float pas_de_temps = 1.0f;
        const float t0 = keyframes_lapins[0][1].t;
        t1 = keyframes_lapins[0][2].t;
        t2 = keyframes_lapins[0][3].t;
        const float t3 = t2 + pas_de_temps;

        float xmin = 3.0f;
        float xmax = 8.0f;
        float ymin = -8.0f;
        float ymax = -3.0f;
        float zmin = 0.05f; //0.16*0.5 ou 0.5 est le scale
        float zmax = 0.05f;
        float distance_pas = 1.0f;
        float distance_lapins = 0.3f;
        float distance_lac = 0.05f;
        float distance_arbres = 0.3f;

        unsigned int N = keyframes_lapins.size();
        std::vector <vec3> positions3;

        for (unsigned int i=0 ; i<N ; i++){
            const vec3& p0 = keyframes_lapins[i][1].p;
            const vec3& p1 = keyframes_lapins[i][2].p;
            const vec3& p2 = keyframes_lapins[i][3].p;
            //problème ici
            vec3 p3 = rand_nouveau_point(xmin,xmax,ymin,ymax,zmin,zmax,distance_pas,p2);

            while (est_trop_proche(positions3,p3,distance_lapins) || est_trop_proche_du_lac(p3,distance_lac) || est_trop_proche_arbres(positions_arbres,p3,distance_arbres)){
                p3 = rand_nouveau_point(xmin,xmax,ymin,ymax,zmin,zmax,distance_pas,p2);
            }
            float x3 = p3[0];
            float y3 = p3[1];
            float z3 = p3[2];
            float u3 = x3/20.0f+0.5f;
            float v3 = y3/20.0f+0.5f;
            z3 = z3 + evaluate_terrain_z(u3,v3);
            p3 = {x3,y3,z3};

            positions3.push_back(p3);
            keyframes_lapins[i] = { { p0 , t0 },
                            { p1 , t1 },
                            { p2 , t2 },
                            { p3 , t3 },
                             };
        }

        return keyframes_lapins;
    }
}



std::vector <vcl::buffer<vec3t>> init_keyframes_lapin (unsigned int N, std::vector<std::vector<vcl::vec3>> positions_arbres){
    std::vector <vec3> positions0;
    std::vector <vec3> positions1;
    std::vector <vec3> positions2;
    std::vector <vec3> positions3;
    std::vector <vcl::buffer<vec3t>> keyframes_lapins;
    float xmin = 4.0f;
    float xmax = 9.0f;
    float ymin = -9.0f;
    float ymax = -4.0f;
    float zmin = 0.05f;
    float zmax = 0.05f;
    float distance_pas = 1.0f;
    float distance_lapins = 0.3f;
    float distance_lac = 0.05f;
    float distance_arbres = 0.3f;

    for (unsigned int i=0 ; i<N ; i++){
        vec3 p0 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        while (est_trop_proche(positions0,p0,distance_lapins) || est_trop_proche_du_lac(p0,distance_lac) || est_trop_proche_arbres(positions_arbres,p0,distance_arbres)){
            p0 = rand_point(xmin,xmax,ymin,ymax,zmin,zmax);
        }

        float x0 = p0[0];
        float y0 = p0[1];
        float z0 = p0[2];
        float u0 = x0/20.0f+0.5f;
        float v0 = y0/20.0f+0.5f;
        z0 = z0 + evaluate_terrain_z(u0,v0);
        p0 = {x0,y0,z0};

        vec3 p1 = rand_nouveau_point(xmin,xmax,ymin,ymax,zmin,zmax,distance_pas,p0);
        while (est_trop_proche(positions1,p1,distance_lapins) || est_trop_proche_du_lac(p1,distance_lac) || est_trop_proche_arbres(positions_arbres,p1,distance_arbres)){
            p1 = rand_nouveau_point(xmin,xmax,ymin,ymax,zmin,zmax,distance_pas,p0);
        }
        float x1 = p1[0];
        float y1 = p1[1];
        float z1 = p1[2];
        float u1 = x1/20.0f+0.5f;
        float v1 = y1/20.0f+0.5f;
        z1 = z1 + evaluate_terrain_z(u1,v1);
        p1 = {x1,y1,z1};

        vec3 p2 = rand_nouveau_point(xmin,xmax,ymin,ymax,zmin,zmax,distance_pas,p1);
        while (est_trop_proche(positions2,p2,distance_lapins) || est_trop_proche_du_lac(p2,distance_lac) || est_trop_proche_arbres(positions_arbres,p2,distance_arbres)){
            p2 = rand_nouveau_point(xmin,xmax,ymin,ymax,zmin,zmax,distance_pas,p1);
        }
        float x2 = p2[0];
        float y2 = p2[1];
        float z2 = p2[2];
        float u2 = x2/20.0f+0.5f;
        float v2 = y2/20.0f+0.5f;
        z2 = z2 + evaluate_terrain_z(u2,v2);
        p2 = {x2,y2,z2};

        vec3 p3 = rand_nouveau_point(xmin,xmax,ymin,ymax,zmin,zmax,distance_pas,p2);
        while (est_trop_proche(positions3,p3,distance_lapins) || est_trop_proche_du_lac(p3,distance_lac) || est_trop_proche_arbres(positions_arbres,p3,distance_arbres)){
            p3 = rand_nouveau_point(xmin,xmax,ymin,ymax,zmin,zmax,distance_pas,p2);
        }
        float x3 = p3[0];
        float y3 = p3[1];
        float z3 = p3[2];
        float u3 = x3/20.0f+0.5f;
        float v3 = y3/20.0f+0.5f;
        z3 = z3 + evaluate_terrain_z(u3,v3);
        p3 = {x3,y3,z3};

        float pas_de_temps = 1.0f;
        float t0 = -pas_de_temps;
        float t1 = t0 + pas_de_temps;
        float t2 = t1 + pas_de_temps;
        float t3 = t2 + pas_de_temps;

        vcl::buffer<vec3t> keyframes_lapin = { { p0 , t0 },
                                                  { p1 , t1  },
                                                  { p2 , t2  },
                                                  { p3 , t3  },
                                                  };
        keyframes_lapins.push_back(keyframes_lapin);
    }
    return keyframes_lapins;
}




#endif
