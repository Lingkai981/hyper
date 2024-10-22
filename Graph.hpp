//
//  Graph.hpp
//  hypergraph_tri_count
//
//  Created by LingkaiMeng on 2024/3/21.
//

#ifndef _GRAPH_H_
#define _GRAPH_H_

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

using namespace std;

struct pairwise_edge {
    uint32_t vertex;
    uint32_t hyperedge;
};

struct out_edge_vertex_pos {
    uint32_t vertex;
    uint32_t pos;
    uint32_t neighbor_num;
};

class Graph {
private:
    string dir; //input graph directory
    uint32_t n, e, m; //number of nodes and edges of the graph
    
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

    vector<HashMap*> hashMaps;

    uint32_t *out_degree;

    vector<uint32_t> common_vertices;

    
    
//    unordered_map<uint32_t, vector<uint32_t> > *pairwise_adgvex2;
    
    

public:
    Graph(const char *_dir) ;
    ~Graph() ;

    void read_graph();
    
    void triangle_enum();

    void triangle_enum2();
    void triangle_enum3();
    void triangle_enum4();
    
    void hyperedge_triangle_enum();
    
    void triangle_count();
    
    void to_pairwise(); //精确

    void to_pairwise_minHash();

    void to_pairwise_minHash2(); //精确找三角形，近似判断类型

    void to_pairwise_minHash3();//近似找三角形，近似判断类型

    void to_pairwise_minHash4();//近似找三角形，精确判断类型
    
    void to_hyperedge_based_pairwise();
    
    void to_hyperedge_based_pairwise2();
    
    void judge_tri_type(uint32_t u, uint32_t u_pos, uint32_t v, uint32_t v_pos,uint32_t w, uint32_t w_pos, uint32_t &type, uint32_t &tri_num, uint32_t &common_num);
    int judge_tri_type_minHash(uint32_t u, uint32_t u_pos, uint32_t u_nei_num, uint32_t v, uint32_t v_pos, uint32_t v_nei_num,uint32_t w, uint32_t w_pos, uint32_t w_nei_num, uint32_t &type, uint32_t &tri_num, uint32_t &common_num);
    void judge_tri_type_minHash2(uint32_t u, uint32_t u_pos, uint32_t v, uint32_t v_pos,uint32_t w, uint32_t w_pos, uint32_t &type, uint32_t &tri_num, uint32_t &common_num);
    
    int two_interaction_num2(uint32_t *a, uint32_t la, uint32_t *b, uint32_t lb);
    int two_interaction_num(pairwise_edge *a, uint32_t la, pairwise_edge *b, uint32_t lb);
    int three_interaction_num(pairwise_edge *a, uint32_t la, pairwise_edge *b, uint32_t lb, pairwise_edge *c, uint32_t lc);

    
};

#endif
