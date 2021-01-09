#include "terrain.hpp"
#include "scene_finale.hpp"
#include <random>

#ifdef SCENE_PROJET_FINAL
using namespace vcl;

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



vcl::vec3 evaluate_terrain(float u, float v)
{
    const float x = 20*(u-0.5f);
    const float y = 20*(v-0.5f);
    const float z = evaluate_terrain_z(u,v);

    return {x,y,z};
}



vcl::vec3 evaluate_lac(float u, float v)
{
    const float x = 5*(u-0.5f);
    const float y = 5*(v-0.5f);
    const float z = evaluate_lac_z(u,v);

    return {x,y,z};
}



vcl::mesh create_terrain()
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



vcl::mesh create_lac(){
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



vcl::mesh create_skybox(){
    mesh skybox;
    skybox.position={{-40,40,-40},{-40,40,40},{-40,-40,40},{-40,40,40},{40,40,40},{40,-40,40},{40,40,40},{-40,40,40},{-40,40,-40},{40,40,-40},{40,-40,-40},{40,40,-40},{-40,40,-40},{-40,-40,-40}};
    skybox.texture_uv={{0,0.35}, {0,0.64}, {0.26,0.64}, {0.27,1},{0.5,1},{0.5,0.64},{0.75,0.64},{1,0.64},{1,0.35},{0.75,0.35},{0.5,0.35},{0.5,0},{0.27,0},{0.27,0.35}};
    skybox.connectivity={{0,1,2},{0,2,13},{2,3,4},{2,4,5},{13,5,10},{13,2,5},{12,13,10},{12,10,11},{10,5,6},{10,6,9},{9,6,7},{9,7,8}};
    return skybox;
}



vcl::mesh create_tree_foliage(float radius, float height, float z_offset, vcl::vec3 p, unsigned int N, float r){
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

#endif
