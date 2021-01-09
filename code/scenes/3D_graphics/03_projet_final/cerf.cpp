#include "cerf.hpp"
#include "scene_finale.hpp"
#include "terrain.hpp"
#include <random>

#ifdef SCENE_PROJET_FINAL

using namespace vcl;



vcl::hierarchy_mesh_drawable data_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf){
    float a_corps = 0.6f;
    float a_tete = 0.18f;
    float a_nez = 0.15f;
    float a_leg = 0.25f;
    float r_bois = 0.01f;

    mesh_drawable corps = mesh_drawable( create_ellipsoide(0.28f,0.28f,a_corps,{0,0,0},100,100));
    mesh_drawable cou = mesh_drawable( create_ellipsoide(0.11f,0.11f,0.3f,{0,0,0},40,40));
    mesh_drawable tete = mesh_drawable( create_ovale(a_tete,a_tete-0.05f,{0,0,0},100,100));
    mesh_drawable museau = mesh_drawable( create_tube_conique(a_tete/2.0f,0.055f,{0,0,0},{0,-0.01f,a_tete},50));
    mesh_drawable nez = mesh_drawable( create_mid_ovale(a_nez,0.137f,{0,0,0},3.14f,3.14f,40,40));
    mesh_drawable truffe = mesh_drawable( create_mid_ovale(a_nez,0.137f,{0,0,0},3.14f/2.0f,3.14f,40,40));
    mesh_drawable oeil = mesh_drawable(mesh_primitive_sphere(0.017f, {0,0,0}, 20, 20));
    mesh_drawable up_leg_arr = mesh_drawable( create_ovale(a_leg,a_leg-0.03f,{0,0,0},40,40));
    mesh_drawable up_leg_av = mesh_drawable( create_ovale(a_leg,a_leg-0.02f,{0,0,0},40,40));
    mesh_drawable mid_leg = mesh_drawable( create_ovale(a_leg-0.05f,a_leg-0.06f,{0,0,0},40,40));
    mesh_drawable down_leg = mesh_drawable(mesh_primitive_cylinder(0.04f,{0,0,0},{0,0,0.3f}));
    mesh_drawable pied = mesh_drawable(mesh_primitive_cone(0.07f,{0,0,0.15f},{0,0,0},10));
    mesh ear_ext_cpu;
    ear_ext_cpu.position={{-0.04f,0,0},{0.04f,0,0},{0,0.2f,0}};
    ear_ext_cpu.connectivity={{0,1,2}};
    mesh_drawable ear_ext = mesh_drawable(ear_ext_cpu);
    mesh ear_int_cpu;
    ear_int_cpu.position={{-0.03f,0,0},{0.03f,0,0},{0,0.15f,0}};
    ear_int_cpu.connectivity={{0,1,2}};
    mesh_drawable ear_int = mesh_drawable(ear_int_cpu);
    mesh_drawable queue = mesh_drawable(create_ovale(0.1f,0.09f,{0,0,0},20,20));
    mesh_drawable bois1 = mesh_drawable(mesh_primitive_cylinder(r_bois,{0,0,0},{0,0.5f,0}));
    mesh_drawable bois2 = mesh_drawable(mesh_primitive_cylinder(r_bois,{0,0,0},{0,0.2f,0}));
    mesh_drawable bois3 = mesh_drawable(mesh_primitive_cylinder(r_bois,{0,0,0},{0,0.15f,0}));
    mesh_drawable bois4 = mesh_drawable(mesh_primitive_cylinder(r_bois,{0,0,0},{0,0.25f,0}));

    vec3 beige = {0.65f,0.4f,0.15f};
    vec3 marron = {0.35f,0.16f,0.0f};
    vec3 noir = {0,0,0};
    corps.uniform.color = beige;
    cou.uniform.color = beige;
    tete.uniform.color = beige;
    museau.uniform.color = beige;
    nez.uniform.color = beige;
    truffe.uniform.color = marron;
    oeil.uniform.color = noir;
    up_leg_arr.uniform.color = beige;
    up_leg_av.uniform.color = beige;
    mid_leg.uniform.color = beige;
    down_leg.uniform.color = beige;
    pied.uniform.color = marron;
    ear_ext.uniform.color = beige;
    ear_int.uniform.color = marron;
    queue.uniform.color = beige;
    bois1.uniform.color = marron;
    bois2.uniform.color = marron;
    bois3.uniform.color = marron;
    bois4.uniform.color = marron;

    float pi = 3.14f;
    float theta1 = -pi/2.5f;
    float theta2 = -theta1;
    float theta3 = pi;
    float theta4 = 0.0f;
    float theta5 = theta2;
    float theta6 = pi/4.0f;
    float theta7 = -theta6;
    float theta8 = pi/2.0f-theta5;
    float theta9 = pi-theta2;
    float theta10 = theta2-pi/2.0f;
    float theta11 = 0.0f;
    float theta12 = theta6;
    float theta13 = pi/1.5f;
    float theta14 = pi/8.0f;
    float theta15 = pi/6.0f;

    hierarchy_cerf.add(corps, "corps");
    hierarchy_cerf.add(cou, "cou", "corps", {{0,0.2f,0.57f}, Rx(theta1)} );
    hierarchy_cerf.add(tete, "tete", "cou", {{0,0,0.3f}, Rx(theta2)} );
    hierarchy_cerf.add(museau,"museau","tete",vec3(0,-0.04,0.02f));
    hierarchy_cerf.add(nez,"up_nez","tete",vec3(0,-0.05,0.13f));
    hierarchy_cerf.add(nez,"down_nez","tete",{{0,-0.05,0.13f},Rx(theta4)*Rz(theta3)});
    hierarchy_cerf.add(truffe,"up_truffe","tete",vec3(0,-0.05,0.131f));
    hierarchy_cerf.add(truffe,"down_truffe","tete",{{0,-0.05,0.131f},Rx(theta4)*Rz(theta3)});
    hierarchy_cerf.add(oeil,"oeil_droit","tete",vec3(-0.08f,0.01f,0.14f));
    hierarchy_cerf.add(oeil,"oeil_gauche","tete",vec3(0.08f,0.01f,0.14f));
    hierarchy_cerf.add(up_leg_arr,"up_leg_arr_droit","corps",{{-0.12f,-0.15f,-0.35f},Rx(theta5)});
    hierarchy_cerf.add(mid_leg,"mid_leg_arr_droit","up_leg_arr_droit",{{0,-0.1f,0.34f},Rx(theta6)});
    hierarchy_cerf.add(down_leg,"down_leg_arr_droit","mid_leg_arr_droit",{{0,0,0.15f},Rx(theta7)});
    hierarchy_cerf.add(pied,"pied_arr_droit","down_leg_arr_droit",{{0,0,0.25f},Rx(theta8)});
    hierarchy_cerf.add(up_leg_arr,"up_leg_arr_gauche","corps",{{0.12f,-0.15f,-0.35f},Rx(theta5)});
    hierarchy_cerf.add(mid_leg,"mid_leg_arr_gauche","up_leg_arr_gauche",{{0,-0.1f,0.34f},Rx(theta6)});
    hierarchy_cerf.add(down_leg,"down_leg_arr_gauche","mid_leg_arr_gauche",{{0,0,0.15f},Rx(theta7)});
    hierarchy_cerf.add(pied,"pied_arr_gauche","down_leg_arr_gauche",{{0,0,0.25f},Rx(theta8)});
    hierarchy_cerf.add(up_leg_av,"up_leg_av_droit","corps",{{-0.12f,-0.13f,0.32f},Rx(theta9)});
    hierarchy_cerf.add(mid_leg,"mid_leg_av_droit","up_leg_av_droit",{{0,0.0f,0.34f},Rx(theta10)});
    hierarchy_cerf.add(down_leg,"down_leg_av_droit","mid_leg_av_droit",{{0,0.0f,0.15f},Rx(theta11)});
    hierarchy_cerf.add(pied,"pied_av_droit","down_leg_av_droit",{{0,0,0.25f},Rx(theta11)});
    hierarchy_cerf.add(up_leg_av,"up_leg_av_gauche","corps",{{0.12f,-0.13f,0.32f},Rx(theta9)});
    hierarchy_cerf.add(mid_leg,"mid_leg_av_gauche","up_leg_av_gauche",{{0,0.0f,0.34f},Rx(theta10)});
    hierarchy_cerf.add(down_leg,"down_leg_av_gauche","mid_leg_av_gauche",{{0,0,0.15f},Rx(theta11)});
    hierarchy_cerf.add(pied,"pied_av_gauche","down_leg_av_gauche",{{0,0,0.25f},Rx(theta11)});
    hierarchy_cerf.add(ear_ext,"ear_ext_droit","tete",{{0.1f*sin(-theta12),0.1f*cos(theta12),0},Rz(theta12)});
    hierarchy_cerf.add(ear_ext,"ear_ext_gauche","tete",{{0.1f*sin(theta12),0.1f*cos(theta12),0},Rz(-theta12)});
    hierarchy_cerf.add(ear_int,"ear_int_droit","ear_ext_droit",vec3(0,0,0.001f));
    hierarchy_cerf.add(ear_int,"ear_int_gauche","ear_ext_gauche",vec3(0,0,0.001f));
    hierarchy_cerf.add(queue,"queue","corps",{{0,0,-0.6f},Rx(theta13)});
    hierarchy_cerf.add(bois1,"bois1_droit","tete",{{0.1f*sin(-theta14),0.1f*cos(theta14),0},Rz(theta14)});
    hierarchy_cerf.add(bois2,"bois2_droit","bois1_droit",{{0,0.05f,0},Rz(theta15)});
    hierarchy_cerf.add(bois3,"bois3_droit","bois1_droit",{{0,0.25f,0},Rz(theta15)});
    hierarchy_cerf.add(bois4,"bois4_droit","bois1_droit",{{0,0.3f,0},Rz(-theta15)});
    hierarchy_cerf.add(bois1,"bois1_gauche","tete",{{0.1f*sin(theta14),0.1f*cos(theta14),0},Rz(-theta14)});
    hierarchy_cerf.add(bois2,"bois2_gauche","bois1_gauche",{{0,0.05f,0},Rz(-theta15)});
    hierarchy_cerf.add(bois3,"bois3_gauche","bois1_gauche",{{0,0.25f,0},Rz(-theta15)});
    hierarchy_cerf.add(bois4,"bois4_gauche","bois1_gauche",{{0,0.3f,0},Rz(theta15)});

    return hierarchy_cerf;
}



vec3marche marche_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf, float t_reel, vcl::buffer<vec3t> keyframes_cerf, bool cerf_doit_stopper){

    const float t0 = keyframes_cerf[0].t;
    const float t1 = keyframes_cerf[1].t;
    const float t2 = keyframes_cerf[2].t;
    const float t3 = keyframes_cerf[3].t;
    const vec3& p0 = keyframes_cerf[0].p;
    const vec3& p1 = keyframes_cerf[1].p;
    const vec3& p2 = keyframes_cerf[2].p;
    const vec3& p3 = keyframes_cerf[3].p;
    const float K = 0.5f;
    const float delta = 0.5f;
    const vec3 p = cardinal_spline_interpolation(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K);

    if (norm(p) > 2.2f){
        const vec3 dp = derive_p(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K,delta);
        const mat3 R_body = rotation_objet_anime(dp);
        float t = t_reel;

        float pi = 3.14f;
        float agl_u_l_arr_dt = pi/2.5f + 0.4f*sin(2.0f*3.14f*(t-0.4f));
        float agl_m_l_arr_dt = pi/4.0f + 0.15f*sin(2.0f*3.14f*(t-0.5f));
        float agl_d_l_arr_dt = -pi/4.0f + 0.1f*sin(2.0f*3.14f*(t-0.6f));
        float agl_p_arr_dt = pi/2.0f - agl_u_l_arr_dt - agl_m_l_arr_dt - agl_d_l_arr_dt;

        float agl_u_l_av_dt = pi-pi/2.5f + 0.4f*sin(2.0f*3.14f*(t-0.6f));
        float agl_m_l_av_dt = pi/2.5f-pi/2.0f + 0.15f*sin(2.0f*3.14f*(t-0.7f));
        float agl_d_l_av_dt = 0.1f*sin(2.0f*3.14f*(t-0.8f));
        float agl_p_av_dt = pi/2.0f - agl_u_l_av_dt - agl_m_l_av_dt - agl_d_l_av_dt;

        float agl_u_l_arr_gc = pi/2.5f - 0.4f*sin(2.0f*3.14f*(t-0.4f));
        float agl_m_l_arr_gc = pi/4.0f - 0.15f*sin(2.0f*3.14f*(t-0.5f));
        float agl_d_l_arr_gc = -pi/4.0f - 0.1f*sin(2.0f*3.14f*(t-0.6f));
        float agl_p_arr_gc = pi/2.0f - agl_u_l_arr_gc - agl_m_l_arr_gc - agl_d_l_arr_gc;

        float agl_u_l_av_gc = pi-pi/2.5f - 0.4f*sin(2.0f*3.14f*(t-0.6f));
        float agl_m_l_av_gc = pi/2.5f-pi/2.0f - 0.15f*sin(2.0f*3.14f*(t-0.7f));
        float agl_d_l_av_gc = -0.1f*sin(2.0f*3.14f*(t-0.8f));
        float agl_p_av_gc = pi/2.0f - agl_u_l_av_gc - agl_m_l_av_gc - agl_d_l_av_gc;

        float agl_cou = -pi/2.5f + 0.06f*sin(4.0f*3.14f*(t-0.4f));
        float agl_tete = -agl_cou;

        hierarchy_cerf["corps"].transform.scaling = 0.5f;
        hierarchy_cerf["corps"].transform.translation = {0,0.98f,0};
        hierarchy_cerf["corps"].transform.translation = p;
        hierarchy_cerf["corps"].transform.rotation = R_body;
        hierarchy_cerf["up_leg_arr_droit"].transform.rotation = Rx(agl_u_l_arr_dt);
        hierarchy_cerf["mid_leg_arr_droit"].transform.rotation = Rx(agl_m_l_arr_dt);
        hierarchy_cerf["down_leg_arr_droit"].transform.rotation = Rx(agl_d_l_arr_dt);
        hierarchy_cerf["pied_arr_droit"].transform.rotation = Rx(agl_p_arr_dt);

        hierarchy_cerf["up_leg_av_droit"].transform.rotation = Rx(agl_u_l_av_dt);
        hierarchy_cerf["mid_leg_av_droit"].transform.rotation = Rx(agl_m_l_av_dt);
        hierarchy_cerf["down_leg_av_droit"].transform.rotation = Rx(agl_d_l_av_dt);
        hierarchy_cerf["pied_av_droit"].transform.rotation = Rx(agl_p_av_dt);

        hierarchy_cerf["up_leg_arr_gauche"].transform.rotation = Rx(agl_u_l_arr_gc);
        hierarchy_cerf["mid_leg_arr_gauche"].transform.rotation = Rx(agl_m_l_arr_gc);
        hierarchy_cerf["down_leg_arr_gauche"].transform.rotation = Rx(agl_d_l_arr_gc);
        hierarchy_cerf["pied_arr_gauche"].transform.rotation = Rx(agl_p_arr_gc);

        hierarchy_cerf["up_leg_av_gauche"].transform.rotation = Rx(agl_u_l_av_gc);
        hierarchy_cerf["mid_leg_av_gauche"].transform.rotation = Rx(agl_m_l_av_gc);
        hierarchy_cerf["down_leg_av_gauche"].transform.rotation = Rx(agl_d_l_av_gc);
        hierarchy_cerf["pied_av_gauche"].transform.rotation = Rx(agl_p_av_gc);

        hierarchy_cerf["cou"].transform.rotation = Rx(agl_cou);
        hierarchy_cerf["tete"].transform.rotation = Rx(agl_tete);



        return {hierarchy_cerf, cerf_doit_stopper};
    }

    else{
        cerf_doit_stopper = true;
        return {hierarchy_cerf, cerf_doit_stopper};
    }
}



vec3arret arret_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf, float t_reel, bool cerf_doit_boire, std::vector <bool> cerf_doit_stopper_membres, vcl::timer_interval timer){
    float t = t_reel;
    float seuil = 0.05f;
    float pi = 3.14f;

    float agl_u_l_arr_dt = pi/2.5f + 0.4f*sin(2.0f*3.14f*(t-0.4f));
    float agl_m_l_arr_dt = pi/4.0f + 0.15f*sin(2.0f*3.14f*(t-0.5f));
    float agl_d_l_arr_dt = -pi/4.0f + 0.1f*sin(2.0f*3.14f*(t-0.6f));
    float agl_p_arr_dt = pi/2.0f - agl_u_l_arr_dt - agl_m_l_arr_dt - agl_d_l_arr_dt;
    float agl_u_l_av_dt = pi-pi/2.5f + 0.4f*sin(2.0f*3.14f*(t-0.6f));
    float agl_m_l_av_dt = pi/2.5f-pi/2.0f + 0.15f*sin(2.0f*3.14f*(t-0.7f));
    float agl_d_l_av_dt = 0.1f*sin(2.0f*3.14f*(t-0.8f));
    float agl_p_av_dt = pi/2.0f - agl_u_l_av_dt - agl_m_l_av_dt - agl_d_l_av_dt;
    float agl_u_l_arr_gc = pi/2.5f - 0.4f*sin(2.0f*3.14f*(t-0.4f));
    float agl_m_l_arr_gc = pi/4.0f - 0.15f*sin(2.0f*3.14f*(t-0.5f));
    float agl_d_l_arr_gc = -pi/4.0f - 0.1f*sin(2.0f*3.14f*(t-0.6f));
    float agl_p_arr_gc = pi/2.0f - agl_u_l_arr_gc - agl_m_l_arr_gc - agl_d_l_arr_gc;
    float agl_u_l_av_gc = pi-pi/2.5f - 0.4f*sin(2.0f*3.14f*(t-0.6f));
    float agl_m_l_av_gc = pi/2.5f-pi/2.0f - 0.15f*sin(2.0f*3.14f*(t-0.7f));
    float agl_d_l_av_gc = -0.1f*sin(2.0f*3.14f*(t-0.8f));
    float agl_p_av_gc = pi/2.0f - agl_u_l_av_gc - agl_m_l_av_gc - agl_d_l_av_gc;
    float agl_cou = -pi/2.5f + 0.06f*sin(4.0f*3.14f*(t-0.4f));
    float agl_tete = -agl_cou;

    std::vector <float> angles = {agl_u_l_arr_dt,
                                  agl_m_l_arr_dt,
                                  agl_d_l_arr_dt,
                                  agl_p_arr_dt,
                                  agl_u_l_av_dt,
                                  agl_m_l_av_dt,
                                  agl_d_l_av_dt,
                                  agl_p_av_dt,
                                  agl_u_l_arr_gc,
                                  agl_m_l_arr_gc,
                                  agl_d_l_arr_gc,
                                  agl_p_arr_gc,
                                  agl_u_l_av_gc,
                                  agl_m_l_av_gc,
                                  agl_d_l_av_gc,
                                  agl_p_av_gc,
                                  agl_cou,
                                  agl_tete
                                 };

    float ref_agl_u_l_arr = pi/2.5f;
    float ref_agl_m_l_arr = pi/4.0f;
    float ref_agl_d_l_arr = -pi/4.0f;
    float ref_agl_p_arr = pi/2.0f - pi/2.5f;
    float ref_agl_u_l_av = pi - pi/2.5f;
    float ref_agl_m_l_av = pi/2.5f - pi/2.0f;
    float ref_agl_d_l_av = 0.0f;
    float ref_agl_p_av = 0.0f;
    float ref_agl_cou = -pi/2.5f;
    float ref_agl_tete = pi/2.5f;

    std::vector <float> angles_ref = {ref_agl_u_l_arr,
                                      ref_agl_m_l_arr,
                                      ref_agl_d_l_arr,
                                      ref_agl_p_arr,
                                      ref_agl_u_l_av,
                                      ref_agl_m_l_av,
                                      ref_agl_d_l_av,
                                      ref_agl_p_av,
                                      ref_agl_cou,
                                      ref_agl_tete
                                     };

    bool no_stop1 = abs(agl_u_l_arr_dt - ref_agl_u_l_arr) > seuil;
    bool no_stop2 = abs(agl_m_l_arr_dt - ref_agl_m_l_arr) > seuil;
    bool no_stop3 = abs(agl_d_l_arr_dt - ref_agl_d_l_arr) > seuil;
    bool no_stop4 = abs(agl_p_arr_dt - ref_agl_p_arr) > seuil;
    bool no_stop5 = abs(agl_u_l_av_dt - ref_agl_u_l_av) > seuil;
    bool no_stop6 = abs(agl_m_l_av_dt - ref_agl_m_l_av) > seuil;
    bool no_stop7 = abs(agl_d_l_av_dt - ref_agl_d_l_av) > seuil;
    bool no_stop8 = abs(agl_p_av_dt - ref_agl_p_av) > seuil;
    bool no_stop9 = abs(agl_u_l_arr_gc - ref_agl_u_l_arr) > seuil;
    bool no_stop10 = abs(agl_m_l_arr_gc - ref_agl_m_l_arr) > seuil;
    bool no_stop11 = abs(agl_d_l_arr_gc - ref_agl_d_l_arr) > seuil;
    bool no_stop12 = abs(agl_p_arr_gc - ref_agl_p_arr) > seuil;
    bool no_stop13 = abs(agl_u_l_av_gc - ref_agl_u_l_av) > seuil;
    bool no_stop14 = abs(agl_m_l_av_gc - ref_agl_m_l_av) > seuil;
    bool no_stop15 = abs(agl_d_l_av_gc - ref_agl_d_l_av) > seuil;
    bool no_stop16 = abs(agl_p_av_gc - ref_agl_p_av) > seuil;
    bool no_stop17 = abs(agl_cou - ref_agl_cou) > seuil;
    bool no_stop18 = abs(agl_tete - ref_agl_tete) > seuil;

    std::vector <bool> comparaisons = {no_stop1,
                                       no_stop2,
                                       no_stop3,
                                       no_stop4,
                                       no_stop5,
                                       no_stop6,
                                       no_stop7,
                                       no_stop8,
                                       no_stop9,
                                       no_stop10,
                                       no_stop11,
                                       no_stop12,
                                       no_stop13,
                                       no_stop14,
                                       no_stop15,
                                       no_stop16,
                                       no_stop17,
                                       no_stop18
                                      };

    std::vector <std::string> noms_membres = {"up_leg_arr_droit",
                                              "mid_leg_arr_droit",
                                              "down_leg_arr_droit",
                                              "pied_arr_droit",
                                              "up_leg_av_droit",
                                              "mid_leg_av_droit",
                                              "down_leg_av_droit",
                                              "pied_av_droit",
                                              "up_leg_arr_gauche",
                                              "mid_leg_arr_gauche",
                                              "down_leg_arr_gauche",
                                              "pied_arr_gauche",
                                              "up_leg_av_gauche",
                                              "mid_leg_av_gauche",
                                              "down_leg_av_gauche",
                                              "pied_av_gauche",
                                              "cou",
                                              "tete"
                                             };

    bool cerf_doit_boire_courant = true;
    std::vector <bool> cerf_doit_stopper_membres_courant = {true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true,
                                                            true
                                                           };

    for (int i=0 ; i<18 ; i++){
        bool no_stop = comparaisons[i];
        float angle = angles[i];
        std::string membre = noms_membres[i];
        bool doit_stopper_membre = cerf_doit_stopper_membres[i];
        if (doit_stopper_membre == false){
            if (no_stop){
                hierarchy_cerf[membre].transform.rotation = Rx(angle);
                cerf_doit_boire_courant = false;
                cerf_doit_stopper_membres_courant[i]=false;
            }
        }
    }

    cerf_doit_boire = cerf_doit_boire_courant;
    cerf_doit_stopper_membres = cerf_doit_stopper_membres_courant;

    if (cerf_doit_boire){
        timer.t = 0.0f;
        timer.scale = 0.4f;
    }

    return {hierarchy_cerf,cerf_doit_boire,cerf_doit_stopper_membres,timer};
}



vec3boire boire_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf, float t, bool cerf_doit_stopper_boire, vcl::vec3 position_cerf, vcl::vec3 orientation_cerf, vcl::timer_interval timer){
    float seuil = 0.05f;
    float pi = 3.14f;
    float t_final = 1.0f;

    //descendre le cou

    float agl_cou_final = pi/4.0f;
    float k = (pi/2.5f + agl_cou_final)/t_final;
    float K = k*(pi/7.0f)*(pi/2.5f);
    float alpha = pi/2.5f - k*t;
    float theta = pi/7.0f - K*t;

    float agl_cou = -alpha;
    float agl_tete = pi/2.5f -0.5f*k*t;
    vec3 pos_cou = {0,0.28f*sin(theta)+0.08f*sin(alpha),0.6f*cos(theta)+0.08f*cos(alpha)};


    //incliner et descendre le buste

    float agl_corps_final = 0.4f;
    float k1 = agl_corps_final/t_final;
    float s = hierarchy_cerf["corps"].transform.scaling;

    float agl_corps = k1*t;
    float agl_up_leg_arr = pi/2.5f - agl_corps;
    float agl_up_leg_av = pi-pi/2.5f - agl_corps;
    float diff_descendre = s*0.3f*sin(agl_corps);
    vec3 pos_corps = {position_cerf[0],position_cerf[1],position_cerf[2]-diff_descendre};


    //plier les jambes de devant

    float agl_up_leg_av_final = 3.0f*pi/4.0f;
    float agl_mid_leg_av_final = -pi/2.0f;
    float agl_down_leg_av_final = pi/1.5f;
    float k2 = (agl_up_leg_av_final - (pi-pi/2.5f))/t_final;
    float k3 = (agl_mid_leg_av_final - (pi/2.5f-pi/2.0f))/t_final;
    float k4 = (agl_down_leg_av_final - (0.0f))/t_final;
    float y_leg = 0.2f*t;
    float z_leg = 0.1f*t;

    agl_up_leg_av = pi-pi/2.5f - agl_corps + k2*t;
    float agl_mid_leg_av = pi/2.5f-pi/2.0f + k3*t;
    float agl_down_leg_av = 0.0f + k4*t;
    float agl_pied_av = pi/2.0f - agl_corps - agl_up_leg_av - agl_mid_leg_av - agl_down_leg_av;

    cerf_doit_stopper_boire = abs(t - t_final) <= seuil;

    if (cerf_doit_stopper_boire == false){

        hierarchy_cerf["cou"].transform.rotation = Rx(agl_cou);
        hierarchy_cerf["tete"].transform.rotation = Rx(agl_tete);
        hierarchy_cerf["cou"].transform.translation = pos_cou;
        hierarchy_cerf["corps"].transform.rotation = rotation_from_axis_angle_mat3({cos(pi/4.0f),sin(pi/4.0f),0},agl_corps)*rotation_objet_anime(orientation_cerf);
        hierarchy_cerf["corps"].transform.translation = pos_corps;
        hierarchy_cerf["up_leg_arr_droit"].transform.rotation = Rx(agl_up_leg_arr);
        hierarchy_cerf["up_leg_arr_gauche"].transform.rotation = Rx(agl_up_leg_arr);
        hierarchy_cerf["up_leg_av_droit"].transform.rotation = Rx(agl_up_leg_av);
        hierarchy_cerf["up_leg_av_gauche"].transform.rotation = Rx(agl_up_leg_av);
        hierarchy_cerf["mid_leg_av_droit"].transform.rotation = Rx(agl_mid_leg_av);
        hierarchy_cerf["mid_leg_av_gauche"].transform.rotation = Rx(agl_mid_leg_av);
        hierarchy_cerf["mid_leg_av_droit"].transform.translation = {0,0+y_leg,0.34f-z_leg};
        hierarchy_cerf["mid_leg_av_gauche"].transform.translation = {0,0+y_leg,0.34f-z_leg};
        hierarchy_cerf["down_leg_av_droit"].transform.rotation = Rx(agl_down_leg_av);
        hierarchy_cerf["down_leg_av_gauche"].transform.rotation = Rx(agl_down_leg_av);
        hierarchy_cerf["pied_av_droit"].transform.rotation = Rx(agl_pied_av);
        hierarchy_cerf["pied_av_gauche"].transform.rotation = Rx(agl_pied_av);

    }

    else{
        cerf_doit_stopper_boire = true;
        position_cerf = pos_corps;
        timer.t = 0.0f;
    }

    return {hierarchy_cerf,cerf_doit_stopper_boire,position_cerf,timer};

}



vec3bloquer bloquer_cerf(bool cerf_doit_stopper_bloquer,vcl::timer_interval timer){
    float seuil = 0.05f;
    float t_final = 1.0f;
    float t = timer.t;
    cerf_doit_stopper_bloquer = abs(t - t_final) <= seuil;

    if (cerf_doit_stopper_bloquer ==true){
        timer.t = 1.0f - t;
    }

    return {cerf_doit_stopper_bloquer,timer};
}



vec3boire relever_cerf(vcl::hierarchy_mesh_drawable hierarchy_cerf, float t, bool cerf_doit_relever, vcl::vec3 position_cerf, vcl::vec3 orientation_cerf, vcl::timer_interval timer){
    if (cerf_doit_relever == false){
        float seuil = 0.05f;
        float pi = 3.14f;
        float t_final = 1.0f;

        //descendre le cou

        float agl_cou_final = pi/4.0f;
        float k = (pi/2.5f + agl_cou_final)/t_final;
        float K = k*(pi/7.0f)*(pi/2.5f);
        float alpha = pi/2.5f - k*(1.0f-t);
        float theta = pi/7.0f - K*(1.0f-t);

        float agl_cou = -alpha;
        float agl_tete = pi/2.5f -0.5f*k*(1.0f-t);
        vec3 pos_cou = {0,0.28f*sin(theta)+0.08f*sin(alpha),0.6f*cos(theta)+0.08f*cos(alpha)};


        //incliner et descendre le buste

        float agl_corps_final = 0.4f;
        float k1 = agl_corps_final/t_final;
        float s = hierarchy_cerf["corps"].transform.scaling;

        float agl_corps = k1*(1.0f-t);
        float agl_up_leg_arr = pi/2.5f - agl_corps;
        float agl_up_leg_av = pi-pi/2.5f - agl_corps;
        float diff_descendre = s*0.6f*sin(agl_corps);
        vec3 pos_corps = {position_cerf[0],position_cerf[1],1.19f*(position_cerf[2]-diff_descendre)};


        //plier les jambes de devant

        float agl_up_leg_av_final = 3.0f*pi/4.0f;
        float agl_mid_leg_av_final = -pi/2.0f;
        float agl_down_leg_av_final = pi/1.5f;
        float k2 = (agl_up_leg_av_final - (pi-pi/2.5f))/t_final;
        float k3 = (agl_mid_leg_av_final - (pi/2.5f-pi/2.0f))/t_final;
        float k4 = (agl_down_leg_av_final - (0.0f))/t_final;
        float y_leg = 0.2f*(1.0f-t);
        float z_leg = 0.1f*(1.0f-t);

        agl_up_leg_av = pi-pi/2.5f - agl_corps + k2*(1.0f-t);
        float agl_mid_leg_av = pi/2.5f-pi/2.0f + k3*(1.0f-t);
        float agl_down_leg_av = 0.0f + k4*(1.0f-t);
        float agl_pied_av = pi/2.0f - agl_corps - agl_up_leg_av - agl_mid_leg_av - agl_down_leg_av;

        cerf_doit_relever = abs(t - t_final) <= seuil;

        if (cerf_doit_relever == false){

            hierarchy_cerf["cou"].transform.rotation = Rx(agl_cou);
            hierarchy_cerf["tete"].transform.rotation = Rx(agl_tete);
            hierarchy_cerf["cou"].transform.translation = pos_cou;
            hierarchy_cerf["corps"].transform.rotation = rotation_from_axis_angle_mat3({cos(pi/4.0f),sin(pi/4.0f),0},agl_corps)*rotation_objet_anime(orientation_cerf);
            hierarchy_cerf["corps"].transform.translation = pos_corps;
            hierarchy_cerf["up_leg_arr_droit"].transform.rotation = Rx(agl_up_leg_arr);
            hierarchy_cerf["up_leg_arr_gauche"].transform.rotation = Rx(agl_up_leg_arr);
            hierarchy_cerf["up_leg_av_droit"].transform.rotation = Rx(agl_up_leg_av);
            hierarchy_cerf["up_leg_av_gauche"].transform.rotation = Rx(agl_up_leg_av);
            hierarchy_cerf["mid_leg_av_droit"].transform.rotation = Rx(agl_mid_leg_av);
            hierarchy_cerf["mid_leg_av_gauche"].transform.rotation = Rx(agl_mid_leg_av);
            hierarchy_cerf["mid_leg_av_droit"].transform.translation = {0,0+y_leg,0.34f-z_leg};
            hierarchy_cerf["mid_leg_av_gauche"].transform.translation = {0,0+y_leg,0.34f-z_leg};
            hierarchy_cerf["down_leg_av_droit"].transform.rotation = Rx(agl_down_leg_av);
            hierarchy_cerf["down_leg_av_gauche"].transform.rotation = Rx(agl_down_leg_av);
            hierarchy_cerf["pied_av_droit"].transform.rotation = Rx(agl_pied_av);
            hierarchy_cerf["pied_av_gauche"].transform.rotation = Rx(agl_pied_av);

        }

        else{
            cerf_doit_relever = true;
            position_cerf = pos_corps;
            timer.t = 0.0f;
        }

        return {hierarchy_cerf,cerf_doit_relever,position_cerf,timer};
    }

    else {
        return {hierarchy_cerf,cerf_doit_relever,position_cerf,timer};
    }
}



vcl::buffer<vec3t> init_keyframes_cerf(vcl::buffer<vec3t> keyframes_cerf, std::vector<std::vector<vcl::vec3>> positions_arbres){
    float hauteur_min = 0.45f; //0.98*0.5 où 0.5 est le scaling
    float distance_arbres = 0.64f;
    float marge = 0.05f;
    float pi = 3.14f;

    float x0 = -5.0f;
    float y0 = 5.0f;
    float u0 = x0/20.0f+0.5f;
    float v0 = y0/20.0f+0.5f;
    float z0 = hauteur_min + evaluate_terrain_z(u0,v0);
    float k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
    float xk0 = k*cos(pi/4.0f) + x0;
    float yk0 = k*sin(pi/4.0f) + y0;
    vec3 pk0 = {xk0,yk0,z0};
    while(est_trop_proche_arbres(positions_arbres,pk0,distance_arbres)){
        k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
        xk0 = k*cos(pi/4.0f) + x0;
        yk0 = k*sin(pi/4.0f) + y0;
        pk0 = {xk0,yk0,z0};
    }

    float x1 = -4.4f;
    float y1 = 4.4f;
    float u1 = x1/20.0f+0.5f;
    float v1 = y1/20.0f+0.5f;
    float z1 = hauteur_min + evaluate_terrain_z(u1,v1);
    k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
    float xk1 = k*cos(pi/4.0f) + x1;
    float yk1 = k*sin(pi/4.0f) + y1;
    vec3 pk1 = {xk1,yk1,z1};
    while(est_trop_proche_arbres(positions_arbres,pk1,distance_arbres)){
        k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
        xk1 = k*cos(pi/4.0f) + x1;
        yk1 = k*sin(pi/4.0f) + y1;
        pk1 = {xk1,yk1,z1};
    }

    float x2 = -3.8f;
    float y2 = 3.8f;
    float u2 = x2/20.0f+0.5f;
    float v2 = y2/20.0f+0.5f;
    float z2 = hauteur_min + evaluate_terrain_z(u2,v2);
    k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
    float xk2 = k*cos(pi/4.0f) + x2;
    float yk2 = k*sin(pi/4.0f) + y2;
    vec3 pk2 = {xk2,yk2,z2};
    while(est_trop_proche_arbres(positions_arbres,pk2,distance_arbres)){
        k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
        xk2 = k*cos(pi/4.0f) + x2;
        yk2 = k*sin(pi/4.0f) + y2;
        pk2 = {xk2,yk2,z2};
    }

    float x3 = -3.2f;
    float y3 = 3.2f;
    float u3 = x3/20.0f+0.5f;
    float v3 = y3/20.0f+0.5f;
    float z3 = hauteur_min + evaluate_terrain_z(u3,v3);
    k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
    float xk3 = k*cos(pi/4.0f) + x3;
    float yk3 = k*sin(pi/4.0f) + y3;
    vec3 pk3 = {xk3,yk3,z3};
    while(est_trop_proche_arbres(positions_arbres,pk3,distance_arbres)){
        k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
        xk3 = k*cos(pi/4.0f) + x3;
        yk3 = k*sin(pi/4.0f) + y3;
        pk3 = {xk3,yk3,z3};
    }

    keyframes_cerf = { { pk0 , -1.0f },
                           { pk1 , 0.0f  },
                           { pk2 , 1.0f  },
                           { pk3 , 2.0f  },
                           };
    return keyframes_cerf;
}



vcl::buffer<vec3t> update_keyframes_cerf(vcl::buffer<vec3t> keyframes_cerf, float t_min, float t_max, bool cerf_doit_stopper, std::vector<std::vector<vcl::vec3>> positions_arbres){

    float t1 = keyframes_cerf[1].t;
    float t2 = keyframes_cerf[2].t;

    if ( (t1 == t_min) && (t2 == t_max) ){
        return keyframes_cerf;
    }
    else{
        const float t0 = keyframes_cerf[1].t;
        t1 = keyframes_cerf[2].t;
        t2 = keyframes_cerf[3].t;
        const float t3 = t2 + 1.0f;

        vec3 p0 = keyframes_cerf[0].p;
        vec3 p1 = keyframes_cerf[1].p;
        vec3 p2 = keyframes_cerf[2].p;
        vec3 p3 = keyframes_cerf[3].p;
        vec3 pk3 = p3;

        if (cerf_doit_stopper == false){
            float hauteur_min = 0.45f; //0.98*0.5 où 0.5 est le scaling
            float distance = 0.6f;
            float distance_arbres = 0.64f;
            float marge = 0.05f;
            float pi = 3.14f;

            p0 = p1;
            p1 = p2;
            p2 = p3;
            float x2 = p2[0];
            float y2 = p2[1];
            float x3 = x2 + distance;
            float y3 = y2 - distance;
            float distance_au_lac = sqrt(x3*x3+y3*y3);
            float z3;

            if (distance_au_lac <= 2.8f){
                z3 = 1.5f*hauteur_min;
            }
            else{
                float u3 = x3/20.0f+0.5f;
                float v3 = y3/20.0f+0.5f;
                z3 = hauteur_min + evaluate_terrain_z(u3,v3);
            }

            float k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
            float xk3 = k*cos(pi/4.0f) + x3;
            float yk3 = k*sin(pi/4.0f) + y3;
            pk3 = {xk3,yk3,z3};
            while(est_trop_proche_arbres(positions_arbres,pk3,distance_arbres)){
                k = rand_interval(-(distance_arbres+marge),distance_arbres+marge);
                xk3 = k*cos(pi/4.0f) + x3;
                yk3 = k*sin(pi/4.0f) + y3;
                pk3 = {xk3,yk3,z3};
            }

        }

        keyframes_cerf = { { p0 , t0 },
                         { p1 , t1 },
                         { p2 , t2 },
                         { pk3 , t3 },
                         };

        return keyframes_cerf;
    }
}



vcl::vec3 update_position_cerf(vcl::vec3 position_cerf, vcl::buffer<vec3t> keyframes_cerf, float t_reel, bool cerf_doit_stopper){

    vec3 p = position_cerf;

    if (cerf_doit_stopper == false){
        const float t0 = keyframes_cerf[0].t;
        const float t1 = keyframes_cerf[1].t;
        const float t2 = keyframes_cerf[2].t;
        const float t3 = keyframes_cerf[3].t;
        const vec3& p0 = keyframes_cerf[0].p;
        const vec3& p1 = keyframes_cerf[1].p;
        const vec3& p2 = keyframes_cerf[2].p;
        const vec3& p3 = keyframes_cerf[3].p;
        const float K = 0.5f;
        p = cardinal_spline_interpolation(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K);
    }

    return p;
}



vcl::vec3 update_orientation_cerf(vcl::vec3 orientation_cerf, vcl::buffer<vec3t> keyframes_cerf, float t_reel, bool cerf_doit_stopper){
    vec3 dp = orientation_cerf;

    if (cerf_doit_stopper == false){
        const float t0 = keyframes_cerf[0].t;
        const float t1 = keyframes_cerf[1].t;
        const float t2 = keyframes_cerf[2].t;
        const float t3 = keyframes_cerf[3].t;
        const vec3& p0 = keyframes_cerf[0].p;
        const vec3& p1 = keyframes_cerf[1].p;
        const vec3& p2 = keyframes_cerf[2].p;
        const vec3& p3 = keyframes_cerf[3].p;
        const float K = 0.5f;
        const float delta = 0.5f;

        dp = derive_p(t_reel,t0,t1,t2,t3,p0,p1,p2,p3,K,delta);
    }

    return dp;
}




#endif



