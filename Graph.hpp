#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <bits/stdint-uintn.h>
#include <fstream>
#include <iostream>

#include <unordered_set>

#include <vector>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include "HashMap.hpp"
#include <cmath>

#include <time.h>
#include <unordered_set>
#include <set>
#include <tuple>
#include <random>
#include <sys/resource.h>
#include <cstdint>
#include "HyperedgeData.cpp"

using namespace std;

struct pairwise_edge {
    uint32_t vertex;
    uint32_t hyperedge;
    bool operator==(const pairwise_edge& other) const {
        return (vertex == other.vertex && hyperedge == other.hyperedge);
    }
};

struct out_edge_vertex_pos {
    uint32_t vertex;
    uint32_t pos;
    uint32_t neighbor_num;
};

struct Triplet {
    int x, y, z;

    Triplet(int a, int b, int c) {
        if (a > b) std::swap(a, b);
        if (a > c) std::swap(a, c);
        if (b > c) std::swap(b, c);

        x = a;
        y = b;
        z = c;
    }

    bool operator==(const Triplet& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

struct TripletHash {
    std::size_t operator()(const Triplet& t) const {
        std::size_t h1 = std::hash<int>{}(t.x);
        std::size_t h2 = std::hash<int>{}(t.y);
        std::size_t h3 = std::hash<int>{}(t.z);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};


class Graph {
private:
    string dir; //input graph directory
    uint32_t n, e, m; //number of nodes and edges of the graph

    uint32_t Reservoir_size;
    
    uint32_t max_e;

    uint32_t bucket = 64;
    uint32_t bucket_tri = 32;

    uint32_t bucket_mask = bucket - 1;

    uint32_t log_num_samples = static_cast<uint32_t>(std::ceil(std::log2(bucket)));
    
    
    uint32_t *hyperedge_len;
    uint32_t *vertex_len;
    
    uint32_t *hyperedges;
    uint32_t *hyperedges_start;
    
    uint64_t pairwise_edge_num;
    
    pairwise_edge *hyperedges_to_vectices;
    uint32_t *intersection_start;
    uint32_t *intersection_start_len;
    uint32_t *hyperedges_to_vectices_start;
    
    out_edge_vertex_pos *out_edges;
    uint32_t *out_edge_start;

    out_edge_vertex_pos *out_edges_minHash;
    uint32_t *out_edge_start_minHash;
    
    out_edge_vertex_pos *out_edge_edges;
    uint32_t *out_edge_edges_start;
    
    vector<uint32_t> *vertices;
    
    vector<pairwise_edge> *pairwise_adgvex;
    vector<uint32_t> *pairwise_adgvex_start;

    vector<pairwise_edge> *pairwise_adgvex2;
    vector<uint32_t> *pairwise_adgvex_start2;

    vector<pairwise_edge> *pairwise_adgvex_minHash;
    vector<uint32_t> *pairwise_adgvex_start_minHash;
    vector<uint32_t> *pairwise_adgvex_nei_num_minHash;
    uint32_t *pairwise_adgvex_nei_num_i_minHash;
    
    vector<pairwise_edge> *pairwise_edge_adgvex;
    vector<uint32_t> *pairwise_edge_adgvex_start;


    uint32_t *out_degree;

    vector<uint32_t> common_vertices;

    std::unordered_set<Triplet, TripletHash> triplets;
    std::set<std::tuple<uint32_t, uint32_t, uint32_t>> uniqueTriplets;

    vector<uint32_t> he_inner2_diff_num;

    vector<pairwise_edge> *sample_pairwise_adgvex;
    vector<uint32_t> RS_sample_edge;
    vector<uint32_t> RS_sample_edge_num;
    HyperedgeData *sample_pairwise_adgvex_local;
    HyperedgeData *sample_pairwise_adgvex_global;

    vector<vector<uint32_t>> all_hyperedges;
    vector<vector<uint32_t>> sample_hyperedges;
    vector<vector<uint32_t>> sample_hyperedges_fixed;
    vector<uint32_t> *sample_vertices;
    vector<vector<uint32_t>> sample_common_vertices;
    vector<uint32_t> common_set;
    vector<uint32_t> common_set1_2;

public:
    Graph(const char *_dir, uint32_t BUCKET_BITS);
    ~Graph() ;

    void read_graph();
    
    vector<uint64_t> triangle_enum();

    void hyperedge_triangle_enum();
    
    void to_pairwise(); //精确
    
    void to_hyperedge_based_pairwise();
    
    void judge_tri_type(uint32_t u, uint32_t u_pos, uint32_t v, uint32_t v_pos,uint32_t w, uint32_t w_pos, uint32_t &type, uint32_t &tri_num, uint32_t &common_num);

    void judge_tri_type_2(uint32_t u, uint32_t u_pos, uint32_t v, uint32_t v_pos,uint32_t w, uint32_t w_pos, uint32_t &type1_num, uint32_t &type2_num, uint32_t &common_num);

    void tc_inner_tri();

    int two_interaction_num2(uint32_t *a, uint32_t la, uint32_t *b, uint32_t lb);
    int two_interaction_num(pairwise_edge *a, uint32_t la, pairwise_edge *b, uint32_t lb);
    int three_interaction_num(pairwise_edge *a, uint32_t la, pairwise_edge *b, uint32_t lb, pairwise_edge *c, uint32_t lc);

    vector<uint64_t> tc_tri_stream_local_time();
    bool binary_search(uint32_t* arr, uint32_t begin, uint32_t end, uint32_t target);
    void intersect_three_sets(const std::set<uint32_t>& set1, const std::set<uint32_t>& set2, const std::set<uint32_t>& set3, double &tri_num_type1_, double &tri_num_type2_, double &tri_num_type3_, int common_num, double update_factor);

    vector<uint64_t> tc_tri_stream_global_time();
    void intersect_three_sets2(const std::set<uint32_t>& set1, const std::set<uint32_t>& set2, const std::set<uint32_t>& set3, double &tri_num_type2_, double &tri_num_type3_, double update_factor);

    vector<uint64_t> tc_tri_stream_global_space();

    vector<uint64_t> tc_tri_stream_local_space();
    void intersect_three_sets3(vector<uint32_t> &set1, vector<uint32_t> &set2, vector<uint32_t> &set3, double &tri_num_type3_, double update_factor);
    void intersect_two_sets3(vector<uint32_t> &set1, vector<uint32_t> &set2, double &tri_num_type2_, double update_factor);

    vector<uint64_t> tc_tri_stream_local_space2();

    vector<uint64_t> tc_tri_stream_local_space_fixed();
    void init();
    int intersect_three_sets_fixed(vector<uint32_t> &set1, vector<uint32_t> &set2, vector<uint32_t> &set3, double &tri_num_type3_, double update_factor1,  double update_factor2);
    void intersect_two_sets_fixed(vector<uint32_t> &set1, vector<uint32_t> &set2, double &tri_num_type2_, double update_factor, int &common_num);

    int intersect_three_sets_fixed2(vector<uint32_t> &common_set1, vector<uint32_t> &common_set2, vector<uint32_t> &set3, vector<uint32_t> &set4, double &tri_num_type3_, double update_factor);
    void intersect_two_sets_fixed2(vector<uint32_t> &set1, vector<uint32_t> &set2, double &tri_num_type2_, double update_factor, int &common_num, vector<uint32_t> &sample_common_vertices_single);

    vector<uint64_t> tc_tri_stream_local_space_fixed2();
    

    vector<uint64_t> tc_tri_stream_local_space_fixed_muti_Reservoir();






    
};

#endif
