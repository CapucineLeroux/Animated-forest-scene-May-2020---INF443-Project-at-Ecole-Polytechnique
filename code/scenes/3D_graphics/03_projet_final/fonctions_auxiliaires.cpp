
#include "fonctions_auxiliaires.hpp"
#include <random>

using namespace vcl;


vcl::mesh create_ovale(float a, float f, vcl::vec3 position, unsigned int N_theta, unsigned int N_phi){
    mesh ovale;
    const float e = f/a;
    const float p = a*(1 - e*e);
    const float theta=3.14f/(N_theta-1);
    const float phi=2.0f*3.14f/N_phi;
    const float x0 = position[0];
    const float y0 = position[1];
    const float z0 = position[2];

    for (unsigned int i = 0 ; i < N_theta ; i++){
        float theta_i = i*theta;
        float r_i = p/(1.0f + e*cos(theta_i));
        for (unsigned int j = 0 ; j < N_phi ; j++){
            float phi_j = j*phi;
            float x_ij = r_i*sin(theta_i)*cos(phi_j);
            float y_ij = r_i*sin(theta_i)*sin(phi_j);
            float z_ij = r_i*cos(theta_i);
            ovale.position.push_back({x0+x_ij,y0+y_ij,z0+z_ij+f});
        }
    }

    for (unsigned int i = 0 ; i < N_theta-1; i++){
        for (unsigned int j = 0 ; j < N_phi-1 ; j++){
            unsigned int idx1 = i*N_phi + j;
            unsigned int idx2 = i*N_phi + j+1;
            unsigned int idx3 = (i+1)*N_phi + j;
            unsigned int idx4 = (i+1)*N_phi + j+1;
            ovale.connectivity.push_back({idx1,idx3,idx4});
            ovale.connectivity.push_back({idx1,idx4,idx2});
        }
        unsigned int idx1 = i*N_phi + N_phi-1;
        unsigned int idx2 = i*N_phi + 0;
        unsigned int idx3 = (i+1)*N_phi + N_phi-1;
        unsigned int idx4 = (i+1)*N_phi + 0;
        ovale.connectivity.push_back({idx1,idx3,idx4});
        ovale.connectivity.push_back({idx1,idx4,idx2});
    }

    return ovale;
}



vcl::mesh create_cone(float radius, float height, vcl::vec3 p, unsigned int N){
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
}



vcl::mesh create_mid_cone(float radius, float height, vcl::vec3 p, float theta_max ,unsigned int N){
    const float theta = theta_max/N;
    mesh cone;
    const float x = p[0];
    const float y = p[1];
    const float z = p[2];

    for (unsigned int n=0; n<N+1; n++){
        float xn = radius*std::cos(n*theta);
        float yn = radius*std::sin(n*theta);
        cone.position.push_back({x+xn,y+yn,z});
    }

    cone.position.push_back({x,y,z});
    cone.position.push_back({x,y,z+height});

    for (unsigned int i=0; i<N; i++){
        cone.connectivity.push_back({i,i+1,N+1});
        cone.connectivity.push_back({i,i+1,N+2});
    }
    cone.connectivity.push_back({N,0,N+1});
    cone.connectivity.push_back({N,0,N+2});

    return cone;
}



vcl::mesh create_tube_conique(float radius1, float radius2, vcl::vec3 p1, vcl::vec3 p2, unsigned int N){
    const float theta = 2*3.14f/N;
    mesh cone;
    const float x1 = p1[0];
    const float y1 = p1[1];
    const float z1 = p1[2];
    const float x2 = p2[0];
    const float y2 = p2[1];
    const float z2 = p2[2];

    for (unsigned int n=0; n<N; n++){
        float xn1 = radius1*std::cos(n*theta);
        float yn1 = radius1*std::sin(n*theta);
        float xn2 = radius2*std::cos(n*theta);
        float yn2 = radius2*std::sin(n*theta);
        cone.position.push_back({x1+xn1,y1+yn1,z1});
        cone.position.push_back({x2+xn2,y2+yn2,z2});
    }

    cone.position.push_back({x1,y1,z1});
    cone.position.push_back({x2,y2,z2});

    for (unsigned int i=0; i<N-1; i++){
        cone.connectivity.push_back({2*i,2*i+2,2*N});
        cone.connectivity.push_back({2*i+1,2*i+3,2*N+1});
    }
    cone.connectivity.push_back({2*N-2,0,2*N});
    cone.connectivity.push_back({2*N-1,1,2*N+1});

    for (unsigned int i=0; i<N-1; i++){
        cone.connectivity.push_back({2*i,2*i+2,2*i+3});
        cone.connectivity.push_back({2*i,2*i+3,2*i+1});
    }
    cone.connectivity.push_back({2*N-2,0,1});
    cone.connectivity.push_back({2*N-2,1,2*N-1});

    return cone;
}



vcl::mesh create_mid_ovale(float a, float f, vcl::vec3 position, float theta_max, float phi_max, unsigned int N_theta, unsigned int N_phi){
    mesh ovale;
    //excentricite de l'ellipse
    const float e = f/a;
    const float p = a*(1 - e*e);
    //teta decrit un ovale
    const float theta=theta_max/(N_theta-1);
    //phi decrit un cercle
    const float phi=phi_max/N_phi;
    const float x0 = position[0];
    const float y0 = position[1];
    const float z0 = position[2];

    for (unsigned int i = 0 ; i < N_theta ; i++){
        float theta_i = i*theta;
        float r_i = p/(1.0f + e*cos(theta_i));
        for (unsigned int j = 0 ; j < N_phi+1 ; j++){
            float phi_j = j*phi;
            float x_ij = r_i*sin(theta_i)*cos(phi_j);
            float y_ij = r_i*sin(theta_i)*sin(phi_j);
            float z_ij = r_i*cos(theta_i);
            ovale.position.push_back({x0+x_ij,y0+y_ij,z0+z_ij+f});
        }
    }
    for (unsigned int i = 0 ; i < N_theta-1; i++){
        for (unsigned int j = 0 ; j < N_phi ; j++){
            unsigned int idx1 = i*N_phi + j;
            unsigned int idx2 = i*N_phi + j+1;
            unsigned int idx3 = (i+1)*N_phi + j;
            unsigned int idx4 = (i+1)*N_phi + j+1;
            ovale.connectivity.push_back({idx1,idx3,idx4});
            ovale.connectivity.push_back({idx1,idx4,idx2});
        }
        unsigned int idx1 = i*(N_phi+1) + N_phi;
        unsigned int idx2 = i*(N_phi+1) + 0;
        unsigned int idx3 = (i+1)*(N_phi+1) + N_phi;
        unsigned int idx4 = (i+1)*(N_phi+1) + 0;
        ovale.connectivity.push_back({idx1,idx3,idx4});
        ovale.connectivity.push_back({idx1,idx4,idx2});
    }

    return ovale;
}



vcl::mesh create_ellipse(float a, float f, vcl::vec3 position, unsigned int N_theta){
    mesh ellipse;
    const float e = f/a;
    const float p = a*(1 - e*e);
    const float theta=2*3.14f/(N_theta-1);
    const float x0 = position[0];
    const float y0 = position[1];
    const float z0 = position[2];

    for (unsigned int i = 0 ; i < N_theta ; i++){
        float theta_i = i*theta;
        float r_i = p/(1.0f + e*cos(theta_i));
        float x_ij = r_i*sin(theta_i);
        float y_ij = 0.0f;
        float z_ij = r_i*cos(theta_i);
        ellipse.position.push_back({x0+x_ij,y0+y_ij,z0+z_ij+f});
    }

    ellipse.position.push_back(position);

    for (unsigned int i = 0 ; i < N_theta-1; i++){
            ellipse.connectivity.push_back({i,i+1,N_theta});
    }
    ellipse.connectivity.push_back({N_theta-1,0,N_theta});

    return ellipse;
}



vcl::mesh create_ellipsoide(float a, float b, float c, vcl::vec3 position, unsigned int N_theta, unsigned int N_phi){
    mesh ovale;
    const float theta=3.14f/(N_theta-1);
    const float phi=2.0f*3.14f/N_phi;
    const float x0 = position[0];
    const float y0 = position[1];
    const float z0 = position[2];

    for (unsigned int i = 0 ; i < N_theta ; i++){
        float theta_i = i*theta;
        for (unsigned int j = 0 ; j < N_phi ; j++){
            float phi_j = j*phi;
            float x_ij = a*sin(theta_i)*cos(phi_j);
            float y_ij = b*sin(theta_i)*sin(phi_j);
            float z_ij = c*cos(theta_i);
            ovale.position.push_back({x0+x_ij,y0+y_ij,z0+z_ij});
        }
    }

    for (unsigned int i = 0 ; i < N_theta-1; i++){
        for (unsigned int j = 0 ; j < N_phi-1 ; j++){
            unsigned int idx1 = i*N_phi + j;
            unsigned int idx2 = i*N_phi + j+1;
            unsigned int idx3 = (i+1)*N_phi + j;
            unsigned int idx4 = (i+1)*N_phi + j+1;
            ovale.connectivity.push_back({idx1,idx3,idx4});
            ovale.connectivity.push_back({idx1,idx4,idx2});
        }
        unsigned int idx1 = i*N_phi + N_phi-1;
        unsigned int idx2 = i*N_phi + 0;
        unsigned int idx3 = (i+1)*N_phi + N_phi-1;
        unsigned int idx4 = (i+1)*N_phi + 0;
        ovale.connectivity.push_back({idx1,idx3,idx4});
        ovale.connectivity.push_back({idx1,idx4,idx2});
    }

    return ovale;
}



vcl::mesh create_cylinder(float radius, float height, vcl::vec3 p, unsigned int N,float r){

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
}



vcl::vec3 cardinal_spline_interpolation(float t, float t0, float t1, float t2, float t3, const vcl::vec3& p0, const vcl::vec3& p1, const vcl::vec3& p2, const vcl::vec3& p3, float K){
    float s = (t-t1)/(t2-t1);
    vec3 d1 = 2*K*(p2-p0)/(t2-t0);
    vec3 d2 = 2*K*(p3-p1)/(t3-t1);
    vec3 p = (2*pow(s,3)-3*pow(s,2)+1)*p1 + (pow(s,3)-2*pow(s,2)+s)*d1 + (-2*pow(s,3)+3*pow(s,2))*p2 + (pow(s,3)-pow(s,2))*d2;
    return p;
}



vcl::vec3 derive_p (float t, float t0, float t1, float t2, float t3, const vcl::vec3& p0, const vcl::vec3& p1, const vcl::vec3& p2, const vcl::vec3& p3, float K, float delta_t){
    vec3 p_plus = cardinal_spline_interpolation(t+delta_t/2.0f, t0, t1, t2, t3, p0, p1, p2, p3, K);
    vec3 p_moins = cardinal_spline_interpolation(t-delta_t/2.0f, t0, t1, t2, t3, p0, p1, p2, p3, K);
    vec3 dp = (p_plus-p_moins)/delta_t;
    return dp;
}



vcl::mat3 Rx(float theta){
    return {1,0,0, 0,cos(theta),-sin(theta), 0,sin(theta),cos(theta)};
}



vcl::mat3 Ry(float theta){
    return {cos(theta),0,-sin(theta), 0,1,0, sin(theta),0,cos(theta)};
}



vcl::mat3 Rz(float theta){
    return {cos(theta),-sin(theta),0, sin(theta),cos(theta),0, 0,0,1};
}



vcl::mat3 rotation_objet_anime(vcl::vec3 dp){
    float x=dp[0];
    float y=dp[1];
    float z=dp[2];
    float seuil = 0.001f;
    float pi = 3.14f;

    if (abs(x) < seuil){
        if (abs(y) < seuil){
            return {1,0,0, 0,1,0, 0,0,1};
        }
    }

    float r = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    float phi=acos(z/r);
    float theta;
    if (y >= 0.0f){
        theta = acos(x/sqrt(pow(x,2)+pow(y,2)));
    }
    else{
        theta = 2.0f*pi - acos(x/sqrt(pow(x,2)+pow(y,2)));
    }

    mat3 R1 = Rz(theta + pi/2.0f);
    mat3 R2 = rotation_from_axis_angle_mat3({-y,x,0},phi);

    return R2*R1;
}



float update_t_min(float t, float t_precedent, float t_min, vcl::timer_interval timer){
    float pas_de_temps = timer.t_max;
    float seuil1 = 0.05f;
    float seuil2 = pas_de_temps - 0.05f;
    if ( (t_precedent > seuil2) && (t < seuil1) ){
        t_min = t_min + pas_de_temps;
    }

    return t_min;
}



vcl::vec3 rand_point(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax){
    float x = rand_interval(xmin,xmax);
    float y = rand_interval(ymin,ymax);
    float z = rand_interval(zmin,zmax);
    return {x,y,z};
}



vcl::vec3 rand_nouveau_point(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax, float distance, vcl::vec3 p_precedent){
    float x = rand_interval(xmin,xmax);
    float y = rand_interval(ymin,ymax);
    float z = rand_interval(zmin,zmax);
    vec3 p = {x,y,z};
    float n = norm (p - p_precedent);

    while (n > distance){
        x = rand_interval(xmin,xmax);
        y = rand_interval(ymin,ymax);
        z = rand_interval(zmin,zmax);
        p = {x,y,z};
        n = norm (p - p_precedent);
    }

    return p;
}



bool est_trop_proche(std::vector<vcl::vec3> positions,vcl::vec3 p, float dmin){
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
}



bool est_trop_proche_du_lac(vcl::vec3 p, float dmin){
    return (norm(p) < (2.0f+dmin));
}



bool est_trop_proche_arbres(std::vector <std::vector<vcl::vec3>> positions_arbres, vcl::vec3 p, float dmin){
    bool trop_proche = false;
    float x = p[0];
    float y = p[1];
    float z = p[2];
    for (auto positions_i : positions_arbres){
        for (auto pbis : positions_i){
            float xbis = pbis[0];
            float ybis = pbis[1];
            float zbis = pbis[2];
            float d = norm(vec3(x,y,z)-vec3(xbis,ybis,zbis));
            if (d<dmin){
                trop_proche = true;
            }
        }
    }

    return trop_proche;
}
