#pragma once

#include "vcl/vcl.hpp"



struct vec3t{
    vcl::vec3 p; // position
    float t;     // time
};


vcl::mesh create_ovale(float a, float f, vcl::vec3 position, unsigned int N_theta, unsigned int N_phi);
vcl::mesh create_cone(float radius, float height, vcl::vec3 p, unsigned int N);
vcl::mesh create_mid_cone(float radius, float height, vcl::vec3 p, float theta_max ,unsigned int N);
//attention les disques sont toujours paralleles au plan xy
vcl::mesh create_tube_conique(float radius1, float radius2, vcl::vec3 p1, vcl::vec3 p2, unsigned int N);
vcl::mesh create_mid_ovale(float a, float f, vcl::vec3 position, float theta_max, float phi_max, unsigned int N_theta, unsigned int N_phi);
vcl::mesh create_ellipse(float a, float f, vcl::vec3 position, unsigned int N_theta);
//a = largeur selon x, b = largeur selon y, c = largeur selon z
vcl::mesh create_ellipsoide(float a, float b, float c, vcl::vec3 position, unsigned int N_theta, unsigned int N_phi);
vcl::mesh create_cylinder(float radius, float height, vcl::vec3 p, unsigned int N,float r);

vcl::vec3 cardinal_spline_interpolation(float t, float t0, float t1, float t2, float t3, const vcl::vec3& p0, const vcl::vec3& p1, const vcl::vec3& p2, const vcl::vec3& p3, float K);
vcl::vec3 derive_p (float t, float t0, float t1, float t2, float t3, const vcl::vec3& p0, const vcl::vec3& p1, const vcl::vec3& p2, const vcl::vec3& p3, float K, float delta_t);

vcl::mat3 Rx(float theta);
vcl::mat3 Ry(float theta);
vcl::mat3 Rz(float theta);
vcl::mat3 rotation_objet_anime(vcl::vec3 dp);

float update_t_min(float t, float t_precedent, float t_min, vcl::timer_interval timer);
vcl::vec3 rand_point(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax);
vcl::vec3 rand_nouveau_point(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax, float distance, vcl::vec3 p_precedent);
bool est_trop_proche(std::vector<vcl::vec3> positions,vcl::vec3 p, float dmin);
bool est_trop_proche_du_lac(vcl::vec3 p, float dmin);
bool est_trop_proche_arbres(std::vector <std::vector<vcl::vec3>> positions_arbres, vcl::vec3 p, float dmin);


