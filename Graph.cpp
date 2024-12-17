#include "Graph.hpp"
#include <algorithm>

#include <bits/stdint-uintn.h>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <vector>


Graph::Graph(const char *_dir, uint32_t BUCKET_BITS) {
    dir = string(_dir);

    n = m = e = 0;
    max_e = 0;
    
    pairwise_edge_num = 0;
    
    hyperedge_len = NULL;
    vertex_len = NULL;
    
    hyperedges = NULL;
    hyperedges_start = NULL;
    
    vertices = NULL;
    
    pairwise_adgvex = NULL;
    pairwise_adgvex2 = NULL;
    pairwise_edge_adgvex = NULL;
    
    pairwise_adgvex_start = NULL;
    pairwise_adgvex_start2 = NULL;
    pairwise_edge_adgvex_start = NULL;

    pairwise_adgvex_minHash = NULL;
    pairwise_adgvex_start_minHash = NULL;
    
    out_edges = NULL;
    out_edge_start = NULL;
    out_edges_minHash = NULL;
    out_edge_start_minHash = NULL;
    out_degree = NULL;

    
    
    hyperedges_to_vectices = NULL;
    intersection_start = NULL;
    hyperedges_to_vectices_start = NULL;
    intersection_start_len = NULL;
    out_edge_edges = NULL;
    out_edge_edges_start = NULL;
    pairwise_adgvex_nei_num_minHash = NULL;
    Reservoir_size = pow(2, BUCKET_BITS);
    sample_pairwise_adgvex = NULL;
    sample_vertices = NULL;

    cout<<"Reservoir_size:"<<Reservoir_size<<endl;
}

Graph::~Graph() {
    
    if(out_edge_edges != NULL) {
        delete[] out_edge_edges;
        out_edge_edges = NULL;
    }
    
    if(out_edge_edges_start != NULL) {
        delete[] out_edge_edges_start;
        out_edge_edges_start = NULL;
    }
    
    if(hyperedges_to_vectices != NULL) {
        delete[] hyperedges_to_vectices;
        hyperedges_to_vectices = NULL;
    }
    
    if(intersection_start != NULL) {
        delete[] intersection_start;
        intersection_start = NULL;
    }
    
    if(intersection_start_len != NULL) {
        delete[] intersection_start_len;
        intersection_start_len = NULL;
    }
    
    if(hyperedges_to_vectices_start != NULL) {
        delete[] hyperedges_to_vectices_start;
        hyperedges_to_vectices_start = NULL;
    }
    
    if(out_edges != NULL) {
        delete[] out_edges;
        out_edges = NULL;
    }
    
    if(out_edge_start != NULL) {
        delete[] out_edge_start;
        out_edge_start = NULL;
    }

    if(out_edges_minHash != NULL) {
        delete[] out_edges_minHash;
        out_edges_minHash = NULL;
    }
    
    if(out_edge_start_minHash != NULL) {
        delete[] out_edge_start_minHash;
        out_edge_start_minHash = NULL;
    }

    if(out_degree != NULL) {
        delete[] out_degree;
        out_degree = NULL;
    }



    if(hyperedge_len != NULL) {
        delete[] hyperedge_len;
        hyperedge_len = NULL;
    }
    
    if(vertex_len != NULL) {
        delete[] vertex_len;
        vertex_len = NULL;
    }
    
    if(hyperedges != NULL) {
        delete[] hyperedges;
        hyperedges = NULL;
    }
    
    if(hyperedges_start != NULL) {
        delete[] hyperedges_start;
        hyperedges_start = NULL;
    }
    
    if(vertices != NULL) {
        delete[] vertices;
        vertices = NULL;
    }

    if(sample_vertices != NULL) {
        delete[] sample_vertices;
        sample_vertices = NULL;
    }
    
    if(pairwise_adgvex != NULL) {
        delete[] pairwise_adgvex;
        pairwise_adgvex = NULL;
    }
    if(pairwise_adgvex2 != NULL) {
        delete[] pairwise_adgvex2;
        pairwise_adgvex2 = NULL;
    }
    if(pairwise_adgvex_minHash != NULL) {
        delete[] pairwise_adgvex_minHash;
        pairwise_adgvex_minHash = NULL;
    }
    
    if(pairwise_edge_adgvex != NULL) {
        delete[] pairwise_edge_adgvex;
        pairwise_edge_adgvex = NULL;
    }
    
//    if(pairwise_adgvex2 != NULL) {
//        delete[] pairwise_adgvex2;
//        pairwise_adgvex2 = NULL;
//    }
    
    if(pairwise_adgvex_start != NULL) {
        delete[] pairwise_adgvex_start;
        pairwise_adgvex_start = NULL;
    }
    if(pairwise_adgvex_start2 != NULL) {
        delete[] pairwise_adgvex_start2;
        pairwise_adgvex_start2 = NULL;
    }

    if(pairwise_adgvex_start_minHash != NULL) {
        delete[] pairwise_adgvex_start_minHash;
        pairwise_adgvex_start_minHash = NULL;
    }
    
    if(pairwise_edge_adgvex_start != NULL) {
        delete[] pairwise_edge_adgvex_start;
        pairwise_edge_adgvex_start = NULL;
    }

    if(pairwise_adgvex_nei_num_minHash != NULL) {
        delete[] pairwise_adgvex_nei_num_minHash;
        pairwise_adgvex_nei_num_minHash = NULL;
    }

    

    if(pairwise_adgvex_nei_num_i_minHash != NULL) {
        delete[] pairwise_adgvex_nei_num_i_minHash;
        pairwise_adgvex_nei_num_i_minHash = NULL;
    }

    if(sample_pairwise_adgvex != NULL) {
        delete[] sample_pairwise_adgvex;
        sample_pairwise_adgvex = NULL;
    }
}

void Graph::read_graph() {

    ifstream infile;   //输入流
    infile.open(dir + "/degree.txt", ios::in);
    infile >> n >> e >> m;
    cout<<n<<" "<<e<<" "<<m<<endl;
    
    
    if(hyperedge_len == NULL) hyperedge_len = new uint32_t[e];
    if(vertex_len == NULL) vertex_len = new uint32_t[n];
    if(hyperedges == NULL) hyperedges = new uint32_t[m];
    if(hyperedges_start == NULL) hyperedges_start = new uint32_t[e+1];
    if(vertices == NULL) vertices = new vector<uint32_t>[n];
    if(sample_vertices == NULL) sample_vertices = new vector<uint32_t>[n];
    if(pairwise_adgvex == NULL) pairwise_adgvex = new vector<pairwise_edge>[n];
    if(pairwise_adgvex_start == NULL) pairwise_adgvex_start = new vector<uint32_t>[n];
    if(pairwise_adgvex2 == NULL) pairwise_adgvex2 = new vector<pairwise_edge>[n];
    if(pairwise_adgvex_start2 == NULL) pairwise_adgvex_start2 = new vector<uint32_t>[n];

    if(pairwise_adgvex_minHash == NULL) pairwise_adgvex_minHash = new vector<pairwise_edge>[n];
    if(pairwise_adgvex_start_minHash == NULL) pairwise_adgvex_start_minHash = new vector<uint32_t>[n];
    if(pairwise_adgvex_nei_num_minHash == NULL) pairwise_adgvex_nei_num_minHash = new vector<uint32_t>[n];
    if(sample_pairwise_adgvex == NULL) sample_pairwise_adgvex = new vector<pairwise_edge>[n];

    pairwise_adgvex_nei_num_i_minHash = new uint32_t[n];
    if(out_degree == NULL) out_degree = new uint32_t[n];

    common_vertices.resize(n);
    all_hyperedges.resize(e);
    sample_hyperedges.resize(e);
    sample_hyperedges_fixed.resize(e);
    // sample_common_vertices.resize(e);

    common_set.resize(n);
    common_set1_2.resize(n);
    
    
    
    if(pairwise_edge_adgvex == NULL) pairwise_edge_adgvex = new vector<pairwise_edge>[e];
    if(pairwise_edge_adgvex_start == NULL) pairwise_edge_adgvex_start = new vector<uint32_t>[e];
    
    // if(hyperedges_to_vectices == NULL) hyperedges_to_vectices = new pairwise_edge[m*200];
    // if(intersection_start == NULL) intersection_start = new uint32_t[m*200];
    // if(intersection_start_len == NULL) intersection_start_len = new uint32_t[m*200];
    // if(hyperedges_to_vectices_start == NULL) hyperedges_to_vectices_start = new uint32_t[e+1];

    // uint64_t hashMap_ = 2000000000;
    // hashMap = new HashMap(hashMap_);
    
    memset(vertex_len, 0, sizeof(uint32_t)*n);

    int di = 0;
    hyperedges_start[0] = 0;
    while (infile >> hyperedge_len[di]){
        hyperedges_start[di+1] = hyperedges_start[di] + hyperedge_len[di];
        if(max_e < hyperedge_len[di]) max_e = hyperedge_len[di];
        
        di++;
    }
    infile.close();

    cout<<"read degree over"<<endl;
    
    e = di;
    
    infile.open(dir + "/edges.txt", ios::in);
    
    uint32_t hyperedges_i = 0;
    for(uint32_t i = 0; i<e; i++){
        for(uint32_t j = 0; j < hyperedge_len[i]; j++){
            infile >> hyperedges[hyperedges_i];
            all_hyperedges[i].push_back(hyperedges[hyperedges_i]);
            vertices[hyperedges[hyperedges_i]].push_back(i);
            vertex_len[hyperedges[hyperedges_i]]++;
            hyperedges_i++;
        }
    }
    infile.close();

    for(int i = 0;i<e;i++){
        sort(hyperedges+hyperedges_start[i], hyperedges+hyperedges_start[i+1]);
        sort(all_hyperedges[i].begin(), all_hyperedges[i].end());
        // sample_common_vertices[i].reserve(max_e);
    }
    
    // double ttt = 0;
    // for(uint32_t i = 0;i<n;i++){
    //     if(vertex_len[i] == 1) ttt++;

    // }
    // cout<<"ttt:"<<ttt/(double)n<<endl;

    cout<<"read edges over"<<endl;
    
    for(uint32_t i = 0;i<n;i++){
        int len = 0;
        for(int j = 0; j <vertices[i].size();j++){
            len+=hyperedge_len[vertices[i][j]]-1;
        }
        pairwise_adgvex[i].reserve(len);
        sample_pairwise_adgvex[i].reserve(len);
        pairwise_adgvex_start[i].resize(len+2);

        pairwise_adgvex2[i].reserve(len);
        pairwise_adgvex_start2[i].resize(len+2);

        pairwise_adgvex_minHash[i].resize(len);
        pairwise_adgvex_start_minHash[i].resize(len+2);
        pairwise_adgvex_nei_num_minHash[i].resize(len);

        sample_vertices[i].reserve(vertices[i].size());
    
        
    }
    memset(pairwise_adgvex_nei_num_i_minHash, 0, sizeof(uint32_t)*n);
    RS_sample_edge.reserve(e);
    RS_sample_edge_num.reserve(e);
    sample_pairwise_adgvex_local = new HyperedgeData(n);
    sample_pairwise_adgvex_global = new HyperedgeData(n);
    
    // for(uint32_t i = 0;i<e;i++){
    //     uint32_t len = 0;
    //     for(uint32_t j = hyperedges_start[i]; j <hyperedges_start[i+1];j++){
    //         len+=vertices[hyperedges[j]].size() - 1;
    //     }
    //     pairwise_edge_adgvex[i].resize(len);
    //     pairwise_edge_adgvex_start[i].resize(len+2);
    // }

    cout<<"read graph over"<<endl;

}


vector<uint64_t> Graph::triangle_enum(){

    clock_t startTime,endTime;

    startTime = clock();//计时开始
    to_pairwise();
    endTime = clock();//计时结束
    cout << "The to_pairwise time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << endl;
    
    
    int *visit_out = new int[n];
    memset(visit_out, 0, sizeof(int)*n);
    int *visit_out_pos = new int[n];
    memset(visit_out_pos, 0, sizeof(int)*n);
    
    uint64_t all_tri_num = 0;
    
    vector<uint64_t> type_num(3,0);
    uint64_t type_et = 0;
    uint32_t type = 0, tri_num = 0, common_num = 0;

    uint32_t type1_num, type2_num;
    
    for(uint32_t i = 0; i<n;i++){
        for(uint32_t j = out_edge_start[i]; j<out_edge_start[i+1]; j++){

            if(out_edges[j].vertex == n) continue;
            
            visit_out[out_edges[j].vertex] = i+1;
            visit_out_pos[out_edges[j].vertex] = out_edges[j].pos;
        }


        for(uint32_t j = out_edge_start[i]; j < out_edge_start[i+1]; j++){
            if(out_edges[j].vertex == n) continue;
            for(uint32_t k = out_edge_start[out_edges[j].vertex]; k < out_edge_start[out_edges[j].vertex+1]; k++){
                if(out_edges[k].vertex == n) continue;
                if(visit_out[out_edges[k].vertex] == i+1){

                    judge_tri_type_2(i, out_edges[j].pos, out_edges[j].vertex, out_edges[k].pos, i, visit_out_pos[out_edges[k].vertex], type1_num, type2_num, common_num);
                    // all_tri_num+=tri_num;
                    // type_num[type]+=tri_num;
                    type_num[1]+=type1_num;
                    type_num[2]+=type2_num;
                }
            }
        }
    }
    
    delete[] visit_out;
    visit_out = NULL;
    delete[] visit_out_pos;
    visit_out_pos = NULL;

    type_num[0] = 0;

    for(uint32_t i = 0; i< e;i++) if(hyperedges_start[i+1] - hyperedges_start[i] > 2) type_num[0]+=((hyperedges_start[i+1] - hyperedges_start[i])*(hyperedges_start[i+1] - hyperedges_start[i]-1)*(hyperedges_start[i+1] - hyperedges_start[i]-2))/6;

    
    for(int i = 0;i<3;i++){
        cout<<"type-"<<i<<": "<<type_num[i]<<endl;
    }

    
    return type_num;

}


void Graph::hyperedge_triangle_enum(){

    clock_t startTime,endTime;

    startTime = clock();//计时开始
    to_hyperedge_based_pairwise();
    endTime = clock();//计时结束
    cout << "The to_hyperedge_based_pairwise time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    // return;
    
    startTime = clock();//计时开始
    out_edge_edges = new out_edge_vertex_pos[pairwise_edge_num];
    out_edge_edges_start = new uint32_t[e+1];
    
    uint64_t out_edge_edges_i = 0;
    out_edge_edges_start[0] = 0;
    for(uint32_t i = 0; i < e; i++){
        // cout<<i<<endl;
        out_edge_edges_start[i+1] = out_edge_edges_start[i];
        for(uint32_t j = 0; j < pairwise_edge_adgvex_start[i][0]; j++){
            if(pairwise_edge_adgvex_start[i][0] > pairwise_edge_adgvex_start[pairwise_edge_adgvex[i][pairwise_edge_adgvex_start[i][j+1]].hyperedge][0] || (pairwise_edge_adgvex_start[i][0] == pairwise_edge_adgvex_start[pairwise_edge_adgvex[i][pairwise_edge_adgvex_start[i][j+1]].hyperedge][0] && i > pairwise_edge_adgvex[i][pairwise_edge_adgvex_start[i][j+1]].hyperedge)){
                out_edge_edges[out_edge_edges_i++].vertex = pairwise_edge_adgvex[i][pairwise_edge_adgvex_start[i][j+1]].hyperedge;
//                out_edge_edges[out_edge_edges_i++].pos = j + 1;
                out_edge_edges_start[i+1]++;
                
            }
        }
    }

    endTime = clock();//计时结束
    cout << "The out_edge_edges time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    startTime = clock();//计时开始
    
    int *visit_out = new int[e];
    memset(visit_out, 0, sizeof(int)*e);
    // int *visit_out_pos = new int[n];
    // memset(visit_out_pos, 0, sizeof(int)*n);
    
    uint64_t hyperedge_triangle_num = 0;
    
    for(uint32_t i = 0;i<e;i++){
    //    cout<<i<<endl;
        for(uint32_t j = out_edge_edges_start[i]; j < out_edge_edges_start[i+1]; j++){
            visit_out[out_edge_edges[j].vertex] = i+1;
            // visit_out_pos[out_edge_edges[j].vertex] = out_edge_edges[j].pos;
            
        }
        for(uint32_t j = out_edge_edges_start[i]; j < out_edge_edges_start[i+1]; j++){
            for(uint32_t k = out_edge_edges_start[out_edge_edges[j].vertex]; k < out_edge_edges_start[out_edge_edges[j].vertex+1];k++){
                if(visit_out[out_edge_edges[k].vertex] == i+1){
                    hyperedge_triangle_num++;
                }
            }
        }
    }
    
    delete[] visit_out;
    visit_out = NULL;
    // delete[] visit_out_pos;
    // visit_out_pos = NULL;

    endTime = clock();//计时结束
    cout << "The hyperedge_triangle time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    cout<<"hyperedge_triangle_num:"<<hyperedge_triangle_num<<endl;
    
}


void Graph::to_pairwise(){
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    uint64_t vertices_pairwise_edge_num = 0;
    for(uint32_t i = 0;i<e;i++){
        // cout<<i<<endl;
        for(uint32_t j = hyperedges_start[i]; j < hyperedges_start[i+1]; j++){
            // if(vertex_len[hyperedges[j]] == 1) continue;
            for(uint32_t k = j + 1; k < hyperedges_start[i+1]; k++){
                // if(vertex_len[hwyperedges[k]] == 1) continue;
                pairwise_adgvex[hyperedges[j]].push_back({hyperedges[k], i});
                pairwise_adgvex[hyperedges[k]].push_back({hyperedges[j], i});
            }
        }
        vertices_pairwise_edge_num+= (hyperedges_start[i+1] - hyperedges_start[i])*(hyperedges_start[i+1] - hyperedges_start[i] - 1);
    }

    endTime = clock();//计时结束
    cout << "The to_pairwise_minHash part 1 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    startTime = clock();//计时开始
    
    uint32_t out_edges_num = 0;
    
    for(uint32_t i = 0; i< n; i++){
        // cout<<i<<endl;
        if(pairwise_adgvex[i].size()<1) continue;
        std::sort(pairwise_adgvex[i].begin(), pairwise_adgvex[i].end(), [](const pairwise_edge& a, const pairwise_edge& b) {
            if(a.vertex == b.vertex) return a.hyperedge < b.hyperedge;
            return a.vertex < b.vertex;
        });
        pairwise_adgvex_start[i][0] = 0;
        uint32_t pairwise_adgvex_start_i = 1;
        uint32_t last_vertex = pairwise_adgvex[i][0].vertex+1;
        for(uint32_t j = 0; j < pairwise_adgvex[i].size();j++){
            if(pairwise_adgvex[i][j].vertex != last_vertex){
                pairwise_adgvex_start[i][pairwise_adgvex_start_i++] = j;
                pairwise_adgvex_start[i][0]++;
                last_vertex = pairwise_adgvex[i][j].vertex;
            }
        }
        out_edges_num+=pairwise_adgvex_start[i][0];
        pairwise_adgvex_start[i][pairwise_adgvex_start_i] = pairwise_adgvex[i].size();
        
        
    }
    
    if(out_edge_start == NULL) out_edge_start = new uint32_t[n+1];
    if(out_edges == NULL) out_edges = new out_edge_vertex_pos[out_edges_num];

    endTime = clock();//计时结束
    cout << "The to_pairwise_minHash part 2 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    startTime = clock();//计时开始
    
    uint32_t out_edges_i = 0;
    out_edge_start[0] = 0;
    
    for(uint32_t i = 0;i<n;i++){
        out_edge_start[i+1] = out_edge_start[i];
        
        
        for(uint32_t j = 0; j<pairwise_adgvex_start[i][0]; j++){
            

            if(pairwise_adgvex_start[i][0] > pairwise_adgvex_start[pairwise_adgvex[i][pairwise_adgvex_start[i][j+1]].vertex][0] || (pairwise_adgvex_start[i][0] == pairwise_adgvex_start[pairwise_adgvex[i][pairwise_adgvex_start[i][j+1]].vertex][0] && i > pairwise_adgvex[i][pairwise_adgvex_start[i][j+1]].vertex)){
                
                out_edges[out_edges_i].vertex = pairwise_adgvex[i][pairwise_adgvex_start[i][j+1]].vertex;
                
                out_edges[out_edges_i++].pos = j+1;
                out_edge_start[i+1]++;
                
            }
        }
    }
    
    endTime = clock();//计时结束
    cout << "The to_pairwise_minHash part 3 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    startTime = clock();//计时开始
    
    out_edge_start[n] = out_edges_i;
    cout<<"vertices_pairwise_edge_num:"<<vertices_pairwise_edge_num<<endl;
}


bool compare_by_hyperedge(const pairwise_edge& a, const pairwise_edge& b) {
    if(a.hyperedge == b.hyperedge) return a.vertex < b.vertex;
    return a.hyperedge < b.hyperedge;
}

bool compare_by_hyperedge2(const pairwise_edge& a, const pairwise_edge& b) {
    if(a.vertex == b.vertex) return a.hyperedge < b.hyperedge;
    return a.vertex < b.vertex;
}

void Graph::to_hyperedge_based_pairwise(){

    uint32_t last = 0;
    uint32_t hyperedges_to_vectices_i = 0;
    uint32_t intersection_start_i = 0;
    uint32_t hyperedges_to_vectices_start_i = 0;
    uint64_t vertices_pairwise_edge_num = 0;
    for(uint32_t i = 0; i<n;i++){
        for(uint32_t j = 0;j<vertices[i].size();j++){
            for(uint32_t k = j+1;k<vertices[i].size();k++){
                pairwise_edge_adgvex[vertices[i][j]].push_back({i,vertices[i][k]});
                pairwise_edge_adgvex[vertices[i][k]].push_back({i,vertices[i][j]});
            }
        }
        vertices_pairwise_edge_num+=vertices[i].size()*(vertices[i].size()-1);

    }

    for(uint32_t i = 0;i<e;i++){

    }

    
    cout<<vertices_pairwise_edge_num<<endl;
    
}

int judge_tri_type_i = 0;

void Graph::judge_tri_type(uint32_t u, uint32_t u_pos, uint32_t v, uint32_t v_pos,uint32_t w, uint32_t w_pos, uint32_t &type, uint32_t &tri_num, uint32_t &common_num){

    common_num = 0;
    type = 0;
    tri_num = 1;
    int tri_num1 = 0, tri_num2 = 0, tri_num3 = 0;
    uint32_t u_i, v_i, w_i;
    for(u_i = pairwise_adgvex_start[u][u_pos], v_i = pairwise_adgvex_start[v][v_pos], w_i = pairwise_adgvex_start[w][w_pos]; u_i < pairwise_adgvex_start[u][u_pos+1] && v_i < pairwise_adgvex_start[v][v_pos+1] && w_i < pairwise_adgvex_start[w][w_pos+1];){
        
        if(pairwise_adgvex[u][u_i].hyperedge == pairwise_adgvex[v][v_i].hyperedge && pairwise_adgvex[u][u_i].hyperedge == pairwise_adgvex[w][w_i].hyperedge){
            u_i++;
            v_i++;
            w_i++;
            common_num++;
        }
        else if (pairwise_adgvex[u][u_i].hyperedge < pairwise_adgvex[v][v_i].hyperedge && pairwise_adgvex[u][u_i].hyperedge < pairwise_adgvex[w][w_i].hyperedge){
            u_i++;
        }else if (pairwise_adgvex[u][u_i].hyperedge > pairwise_adgvex[v][v_i].hyperedge && pairwise_adgvex[v][v_i].hyperedge < pairwise_adgvex[w][w_i].hyperedge){
            v_i++;
        }else{
            w_i++;
        }
        
    }

    tri_num = common_num;

    // cout<<max(pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos], max(pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos], pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos]))<<endl;

    // cout<<max(u_i - pairwise_adgvex_start[u][u_pos], max(v_i - pairwise_adgvex_start[v][v_pos], w_i - pairwise_adgvex[w][w_i].hyperedge))<<endl;
    
    if((pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos] - common_num) > 0){
        type=1;
        tri_num1 = (pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos] - common_num);
    }
    if((pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num) > 0){
        type=1;
        tri_num2 = (pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num);
    }
    if((pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num) > 0){
        type=1;
        tri_num3 = (pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num);
    }
    
    if(common_num == 0){
        type = 2;
        tri_num = tri_num1*tri_num2*tri_num3;
    } 
    else if(type == 1){
        tri_num = (tri_num1+tri_num2+tri_num3)*common_num;
    }
    // if(common_num>1000) cout<<common_num<<" "<<pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos] - common_num<<" "<<pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num<<" "<<pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num<<endl;
}

void Graph::judge_tri_type_2(uint32_t u, uint32_t u_pos, uint32_t v, uint32_t v_pos,uint32_t w, uint32_t w_pos, uint32_t &type1_num, uint32_t &type2_num, uint32_t &common_num){

    common_num = 0;
    int tri_num1 = 0, tri_num2 = 0, tri_num3 = 0;
    uint32_t u_i, v_i, w_i;
    for(u_i = pairwise_adgvex_start[u][u_pos], v_i = pairwise_adgvex_start[v][v_pos], w_i = pairwise_adgvex_start[w][w_pos]; u_i < pairwise_adgvex_start[u][u_pos+1] && v_i < pairwise_adgvex_start[v][v_pos+1] && w_i < pairwise_adgvex_start[w][w_pos+1];){
        
        if(pairwise_adgvex[u][u_i].hyperedge == pairwise_adgvex[v][v_i].hyperedge && pairwise_adgvex[u][u_i].hyperedge == pairwise_adgvex[w][w_i].hyperedge){
            u_i++;
            v_i++;
            w_i++;
            common_num++;
        }
        else if (pairwise_adgvex[u][u_i].hyperedge < pairwise_adgvex[v][v_i].hyperedge && pairwise_adgvex[u][u_i].hyperedge < pairwise_adgvex[w][w_i].hyperedge){
            u_i++;
        }else if (pairwise_adgvex[u][u_i].hyperedge > pairwise_adgvex[v][v_i].hyperedge && pairwise_adgvex[v][v_i].hyperedge < pairwise_adgvex[w][w_i].hyperedge){
            v_i++;
        }else{
            w_i++;
        }
        
    }

    // cout<<max(pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos], max(pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos], pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos]))<<endl;

    // cout<<max(u_i - pairwise_adgvex_start[u][u_pos], max(v_i - pairwise_adgvex_start[v][v_pos], w_i - pairwise_adgvex[w][w_i].hyperedge))<<endl;
    
    if((pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos] - common_num) > 0){
        
        tri_num1 = (pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos] - common_num);
    }
    if((pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num) > 0){
        
        tri_num2 = (pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num);
    }
    if((pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num) > 0){
        
        tri_num3 = (pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num);
    }
    

    type2_num = tri_num1*tri_num2*tri_num3;

    type1_num = (tri_num1+tri_num2+tri_num3)*common_num;

    // if(common_num>1000) cout<<common_num<<" "<<pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos] - common_num<<" "<<pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num<<" "<<pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num<<endl;
}





int Graph::two_interaction_num(pairwise_edge *a, uint32_t la, pairwise_edge *b, uint32_t lb){
    int num = 0;
    
    for(uint32_t a_i = 0, b_i = 0; a_i < la && b_i < lb;){
        if(a[a_i].vertex == b[b_i].vertex){
            num++;
            a_i++;
            b_i++;
        }else if (a[a_i].vertex < b[b_i].vertex){
            a_i++;
        }else{
            b_i++;
        }
    }
    
    return num;
}

int Graph::two_interaction_num2(uint32_t *a, uint32_t la, uint32_t *b, uint32_t lb){
    int num = 0;
    
    for(uint32_t a_i = 0, b_i = 0; a_i < la && b_i < lb;){
        if(a[a_i] == b[b_i]){
            num++;
            a_i++;
            b_i++;
        }else if (a[a_i] < b[b_i]){
            a_i++;
        }else{
            b_i++;
        }
    }
    
    return num;
}

int Graph::three_interaction_num(pairwise_edge *a, uint32_t la, pairwise_edge *b, uint32_t lb, pairwise_edge *c, uint32_t lc){
    int num = 0;
    
    for(uint32_t a_i = 0, b_i = 0, c_i = 0; a_i < la && b_i < lb && c_i < lc;){
        if(a[a_i].vertex == b[b_i].vertex && a[a_i].vertex == c[c_i].vertex){
            num++;
            a_i++;
            b_i++;
            c_i++;
        }else{
            uint32_t max_v = max(a[a_i].vertex, max(b[b_i].vertex, c[c_i].vertex));
            if(a[a_i].vertex < max_v) a_i++;
            if(b[b_i].vertex < max_v) b_i++;
            if(c[c_i].vertex < max_v) c_i++;
        }
    }
    
    return num;
}


void Graph::tc_inner_tri(){
    uint64_t inner_tri1 = 0;
    uint64_t inner_tri2 = 0;
    vector<pairwise_edge> hyperedges_neighbors;
    hyperedges_neighbors.reserve(n);
    vector<uint32_t> vertices_same;
    vector<uint32_t> vertices_diff;
    uint64_t all_data=0;
    uint32_t he_start = 0, he_end = 0;
    for(uint32_t i = 0;i<e;i++){
        if(hyperedges_start[i+1]-hyperedges_start[i] < 3) continue;
        hyperedges_neighbors.clear();
        triplets.clear();
        // uniqueTriplets.clear();
        he_start = 0;
        he_end = 0;
        for(uint32_t j = hyperedges_start[i]; j< hyperedges_start[i+1]; j++){
            for(uint32_t k = 0; k<vertices[hyperedges[j]].size();k++){
                if(vertices[hyperedges[j]][k] == i) continue;
                hyperedges_neighbors.push_back(pairwise_edge{hyperedges[j], vertices[hyperedges[j]][k]});
            }

        }
        sort(hyperedges_neighbors.begin(), hyperedges_neighbors.end(), compare_by_hyperedge);

        // for(int iii = 0;iii<hyperedges_neighbors.size();iii++){
        //     cout<<hyperedges_neighbors[iii].hyperedge<<" "<<hyperedges_neighbors[iii].vertex<<endl;
        // }
        // cout<<endl;

        while (he_start<hyperedges_neighbors.size()) {
            he_end = he_start;
            vertices_same.clear();
            vertices_diff.clear();
            while(he_end < hyperedges_neighbors.size() && hyperedges_neighbors[he_end].hyperedge == hyperedges_neighbors[he_start].hyperedge){
                vertices_same.push_back(hyperedges_neighbors[he_end].vertex);
                he_end++;
            }

            uint32_t he1 = i;
            uint32_t he2 = hyperedges_neighbors[he_start].hyperedge;

            if(he_end - he_start > 1){
                uint32_t j = hyperedges_start[i], he_same_i = 0;
                for(; j< hyperedges_start[i+1] && he_same_i<vertices_same.size();){
                    if(hyperedges[j] == vertices_same[he_same_i]){
                        j++;
                        he_same_i++;
                    }else {
                        vertices_diff.push_back(hyperedges[j]);
                        j++;
                    }
                }
                while (j< hyperedges_start[i+1]) {
                    vertices_diff.push_back(hyperedges[j]);
                    j++;
                
                }
                if(vertices_diff.size()>0){
                    inner_tri2 += vertices_same.size()*(vertices_same.size()-1)/2*vertices_diff.size();
                    for(uint32_t he_i = 0; he_i<vertices_same.size()-1;he_i++){
                        for(uint32_t he_j = he_i+1;he_j < vertices_same.size();he_j++){
                            for(uint32_t he_k = 0;he_k < vertices_diff.size();he_k++){
                                if (triplets.find(Triplet(vertices_same[he_i], vertices_same[he_j], vertices_diff[he_k])) == triplets.end()) {
                                    triplets.emplace(vertices_same[he_i], vertices_same[he_j], vertices_diff[he_k]);
                                }
                            }
                        }
                    }

                }

            }

            // cout<<hyperedges_start[i+1] - hyperedges_start[i]<<" "<<vertices_same.size()<<" "<<vertices_diff.size()<<endl;
            he_start = he_end;

        }

        all_data += hyperedges_neighbors.size();
        uint64_t all_vertices = hyperedges_start[i+1] - hyperedges_start[i];

        inner_tri1 += all_vertices*(all_vertices-1)*(all_vertices-2)/6 - triplets.size();

    }


    cout<<"type-0:"<<inner_tri1<<endl;
    cout<<"type-1:"<<inner_tri2<<endl;
    cout<<all_data<<endl;


}

vector<uint64_t> Graph::tc_tri_stream_local_time(){
    double tri_num_type1 = 0;
    double tri_num_type1_2 = 0;
    double tri_num_type2 = 0;
    double tri_num_type3 = 0;
    uint32_t currentEdges = 0;

    srand(static_cast<unsigned int>(time(0)));
    std::random_device rd;
    std::mt19937 gen(rd());

    int RS_sample_edge_l_i = 0;

    std::uniform_real_distribution<> dis(0.0, 1.0);
    double tri_num_type1_, tri_num_type2_, tri_num_type3_;

    int judge_type1 = 0;

    std::cout<<"Reservoir_size:"<<Reservoir_size<<std::endl;

    for(uint32_t i = 0;i<e;i++){
        currentEdges++;
        // cout<<tri_num_type1<<" "<<tri_num_type2<<" "<<tri_num_type3<<endl;
        double update_factor = 1;

        if(hyperedges_start[i+1] - hyperedges_start[i] > 2) tri_num_type1_2+=((hyperedges_start[i+1] - hyperedges_start[i])*(hyperedges_start[i+1] - hyperedges_start[i]-1)*(hyperedges_start[i+1] - hyperedges_start[i]-2))/6;


        if(currentEdges > Reservoir_size) update_factor = ((double)Reservoir_size/(double)currentEdges);
        

        for(uint32_t j = hyperedges_start[i]; j< hyperedges_start[i+1]; j++){
            for(uint32_t k = j+1; k<hyperedges_start[i+1];k++){
                judge_type1 = 0;
                auto judge = sample_pairwise_adgvex_local->data[hyperedges[j]].find(hyperedges[k]);
                auto it1 = sample_pairwise_adgvex_local->data[hyperedges[j]].begin();
                auto it2 = sample_pairwise_adgvex_local->data[hyperedges[k]].begin();
                while (it1 != sample_pairwise_adgvex_local->data[hyperedges[j]].end() && it2 != sample_pairwise_adgvex_local->data[hyperedges[k]].end()) {
                    if (it1->first == it2->first) {
                        if(judge != sample_pairwise_adgvex_local->data[hyperedges[j]].end()){
                            if(binary_search(hyperedges, hyperedges_start[i], hyperedges_start[i+1], it1->first)){
                                if(it1->first > hyperedges[j] && it1->first > hyperedges[k]){
                                    judge_type1++;

                                    intersect_three_sets(judge->second, it1->second, it2->second, tri_num_type1_, tri_num_type2_, tri_num_type3_, 1, update_factor);
                                    tri_num_type1+=tri_num_type1_;
                                    tri_num_type2+=tri_num_type2_;
                                    tri_num_type3+=tri_num_type3_;
                                }
                            } 
                            else {
                                intersect_three_sets(judge->second, it1->second, it2->second, tri_num_type1_, tri_num_type2_, tri_num_type3_, 0, update_factor);
                                tri_num_type1+=tri_num_type1_;
                                tri_num_type2+=tri_num_type2_;
                                tri_num_type3+=tri_num_type3_;
                                
                            }


                        }else{
                            if(binary_search(hyperedges, hyperedges_start[i], hyperedges_start[i+1], it1->first)){
                                if(it1->first > hyperedges[j] && it1->first > hyperedges[k]){
                                    tri_num_type2+=(double)(it1->second.size()+it2->second.size())/update_factor;
                                    judge_type1++;

                                } 
                            } 
                            else tri_num_type3+=(double)(it1->second.size()*it2->second.size())/update_factor/update_factor;
                        }
                        ++it1;
                        ++it2;
                    } else if (it1->first < it2->first) {
                        if(it1->first > hyperedges[j] && it1->first > hyperedges[k])
                            if(binary_search(hyperedges, hyperedges_start[i], hyperedges_start[i+1], it1->first)){
                                judge_type1++;
                                tri_num_type2+=(double)it1->second.size()/update_factor;
                                if(judge != sample_pairwise_adgvex_local->data[hyperedges[j]].end()){
                                    tri_num_type2+=(double)judge->second.size()/update_factor;
                                }
                                
                            } 
                                
                        ++it1; 
                    } else {
                        if(it2->first > hyperedges[j] && it2->first > hyperedges[k])
                            if(binary_search(hyperedges, hyperedges_start[i], hyperedges_start[i+1], it2->first)){
                                judge_type1++;
                                tri_num_type2+=(double)it2->second.size()/update_factor;
                                if(judge != sample_pairwise_adgvex_local->data[hyperedges[j]].end()){
                                    tri_num_type2+=(double)judge->second.size()/update_factor;
                                }
                            }
                                
                        ++it2;
                    }
                }

                while (it1 != sample_pairwise_adgvex_local->data[hyperedges[j]].end()){
                    if(it1->first > hyperedges[j] && it1->first > hyperedges[k])
                        if(binary_search(hyperedges, hyperedges_start[i], hyperedges_start[i+1], it1->first)){
                            judge_type1++;
                            tri_num_type2+=(double)it1->second.size()/(update_factor);
                            if(judge != sample_pairwise_adgvex_local->data[hyperedges[j]].end()){
                                tri_num_type2+=(double)judge->second.size()/(update_factor);
                            }
                        } 
                                
                    ++it1;
                }

                while(it2 != sample_pairwise_adgvex_local->data[hyperedges[k]].end()){
                    if(it2->first > hyperedges[j] && it2->first > hyperedges[k])
                        if(binary_search(hyperedges, hyperedges_start[i], hyperedges_start[i+1], it2->first)){
                            judge_type1++;
                            tri_num_type2+=(double)it2->second.size()/update_factor;
                            if(judge != sample_pairwise_adgvex_local->data[hyperedges[j]].end()){
                                tri_num_type2+=(double)judge->second.size()/update_factor;
                            }
                        }
                                
                    ++it2;

                }

                // cout<<judge_type1<<endl;
                // if((double)hyperedges_start[i+1]-(double)k-1.0-(double)judge_type1<0){
                    // cout<<i<<" "<<hyperedges_start[i+1]<<" "<< k-1<< " "<<judge_type1<<endl;
                // }

                
                if(judge != sample_pairwise_adgvex_local->data[hyperedges[j]].end()){
                    tri_num_type2+=(((double)hyperedges_start[i+1]-(double)k-1.0-(double)judge_type1)*judge->second.size())/(update_factor);
                }else{
                    tri_num_type1+=((double)hyperedges_start[i+1]-(double)k-1.0-(double)judge_type1);
                }

                // cout<<"11111:"<<tri_num_type1<<" "<<tri_num_type2<<" "<<tri_num_type3<<endl;
                
            }
        }

        if(currentEdges <= Reservoir_size){
            RS_sample_edge.push_back(i);
            for(uint32_t j = hyperedges_start[i]; j< hyperedges_start[i+1]; j++){
                for(uint32_t k = j+1; k<hyperedges_start[i+1];k++){
                    // sample_pairwise_adgvex[hyperedges[j]].push_back({hyperedges[k], i});
                    // sample_pairwise_adgvex[hyperedges[k]].push_back({hyperedges[j], i});
                    sample_pairwise_adgvex_local->insert(hyperedges[j], hyperedges[k], i);
                    sample_pairwise_adgvex_local->insert(hyperedges[k], hyperedges[j], i);

                }
            }
        }else if(dis(gen) < (double)Reservoir_size/(double)currentEdges){
            uint32_t del_pos = rand() % Reservoir_size;
            uint32_t del_edge = RS_sample_edge[del_pos];
            RS_sample_edge[del_pos] = i;

            for(uint32_t j = hyperedges_start[del_edge]; j< hyperedges_start[del_edge+1]; j++){
                for(uint32_t k = j+1; k<hyperedges_start[del_edge+1];k++){
                    // auto& del_adj_j = sample_pairwise_adgvex[hyperedges[j]];
                    // pairwise_edge temp_j = {hyperedges[k], del_edge};
                    // std::swap(del_adj_j.back(), *std::find(del_adj_j.begin(), del_adj_j.end(), temp_j));
                    // del_adj_j.pop_back();
                    

                    // auto& del_adj_k = sample_pairwise_adgvex[hyperedges[k]];
                    // pairwise_edge temp_k = {hyperedges[j], del_edge};
                    // std::swap(del_adj_k.back(), *std::find(del_adj_k.begin(), del_adj_k.end(), temp_k));
                    // del_adj_k.pop_back();

                    sample_pairwise_adgvex_local->erase(hyperedges[j], hyperedges[k], del_edge);
                    sample_pairwise_adgvex_local->erase(hyperedges[k], hyperedges[j], del_edge);
                }
            }

            for(uint32_t j = hyperedges_start[i]; j< hyperedges_start[i+1]; j++){
                for(uint32_t k = j+1; k<hyperedges_start[i+1];k++){
                    sample_pairwise_adgvex_local->insert(hyperedges[j], hyperedges[k], i);
                    sample_pairwise_adgvex_local->insert(hyperedges[k], hyperedges[j], i);
                }
            }

        }
        
    }

    // cout<<tri_num_type1<<" "<<tri_num_type2<<" "<<tri_num_type3<<endl;

    cout<<"type-1: "<<(int64_t)tri_num_type1_2<<endl;
    cout<<"type-2: "<<(int64_t)tri_num_type2<<endl;
    cout<<"type-3: "<<(int64_t)tri_num_type3<<endl;

    vector<uint64_t> type_num(3);
    type_num[0] = (int64_t)tri_num_type1_2;
    type_num[1] = (int64_t)tri_num_type2;
    type_num[2] = (int64_t)tri_num_type3;

    return type_num;


}

bool Graph::binary_search(uint32_t* arr, uint32_t begin, uint32_t end, uint32_t target) {
    int left = begin;
    int right = end - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (arr[mid] == target) {
            return true;  
        } else if (arr[mid] < target) {
            left = mid + 1;  
        } else {
            right = mid - 1;
        }
    }
    return false;  // 未找到目标值
}

void Graph::intersect_three_sets(const std::set<uint32_t>& set1, const std::set<uint32_t>& set2, const std::set<uint32_t>& set3, double &tri_num_type1_, double &tri_num_type2_, double &tri_num_type3_, int common_num, double update_factor){
    auto it1 = set1.begin();
    auto it2 = set2.begin();
    auto it3 = set3.begin();

    double common_num_ = 0;
    double tri_num1 = 0, tri_num2 = 0, tri_num3 = 0;


    while (it1 != set1.end() && it2 != set2.end() && it3 != set3.end()) {
        if (*it1 == *it2 && *it2 == *it3) {
            ++it1;
            ++it2;
            ++it3;
            common_num_++;
        } else if (*it1 < *it2 && *it1 < *it3) {
            ++it1;  
        } else if (*it2 < *it3 && *it2 < *it1) {
            ++it2;
        } else {
            ++it3;
        }
    }
    tri_num1 = (double)set1.size() - common_num_;
    tri_num2 = (double)set2.size() - common_num_;
    tri_num3 = (double)set3.size() - common_num_;

    if(common_num == 0){
        if(common_num_ ==0 && tri_num1 > 0 && tri_num2 > 0 && tri_num3 > 0){
            // tri_num_type1_ = 0;
            tri_num_type2_ = 0;
            tri_num_type3_ = tri_num2*tri_num3/update_factor/update_factor;
        }else if(tri_num1 == 0 && tri_num2 == 0 && tri_num3 == 0){
            // tri_num_type1_ = -common_num_/update_factor;
            tri_num_type2_ = common_num_/update_factor;
            tri_num_type3_ = 0;
        }else{
            // tri_num_type1_ = 0;
            tri_num_type2_ = common_num_/update_factor;
            // tri_num_type3_ = 0;
            tri_num_type3_ = tri_num2*tri_num3/update_factor/update_factor;
        }

    }else if (common_num == 1) {
        if(common_num_ ==0 && tri_num1 > 0 && tri_num2 > 0 && tri_num3 > 0){
            tri_num_type1_ = 0;
            tri_num_type2_ = (tri_num1+tri_num2+tri_num3)/update_factor;
            // tri_num_type3_ = -(tri_num1*tri_num2*tri_num3)/update_factor/update_factor/update_factor;
            tri_num_type3_ = 0;
        }else if(tri_num1 == 0 && tri_num2 == 0 && tri_num3 == 0){
            tri_num_type1_ = 1.0;
            tri_num_type2_ = 0;
            tri_num_type3_ = 0;
        }else{
            tri_num_type1_ = 0;
            tri_num_type2_ = (tri_num1+tri_num2+tri_num3)/update_factor;
            tri_num_type3_ = 0;
        }
    
    }


}

vector<uint64_t> Graph::tc_tri_stream_global_time(){
    double tri_num_type1 = 0;
    double tri_num_type2 = 0;
    double tri_num_type3 = 0;
    uint32_t currentEdges = 0;

    srand(static_cast<unsigned int>(time(0)));
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> dis(0.0, 1.0);
    double tri_num_type1_, tri_num_type2_, tri_num_type3_;

    int judge_type1 = 0;

    std::cout<<"Reservoir_size:"<<Reservoir_size<<std::endl;

    for(uint32_t i = 0;i<e;i++){
        currentEdges++;
        if(currentEdges <= Reservoir_size){
            RS_sample_edge.push_back(i);
            RS_sample_edge_num.push_back(hyperedges_start[i+1] - hyperedges_start[i]);
            for(uint32_t j = hyperedges_start[i]; j< hyperedges_start[i+1]; j++){
                for(uint32_t k = j+1; k<hyperedges_start[i+1];k++){
                    sample_pairwise_adgvex_global->insert(hyperedges[j], hyperedges[k], i);
                    sample_pairwise_adgvex_global->insert(hyperedges[k], hyperedges[j], i);

                }
            }
        }else if(dis(gen) < (double)Reservoir_size/(double)currentEdges){
            uint32_t del_pos = rand() % Reservoir_size;
            uint32_t del_edge = RS_sample_edge[del_pos];
            RS_sample_edge[del_pos] = i;
            RS_sample_edge_num[del_pos] = hyperedges_start[i+1] - hyperedges_start[i];

            for(uint32_t j = hyperedges_start[del_edge]; j< hyperedges_start[del_edge+1]; j++){
                for(uint32_t k = j+1; k<hyperedges_start[del_edge+1];k++){
                    sample_pairwise_adgvex_global->erase(hyperedges[j], hyperedges[k], del_edge);
                    sample_pairwise_adgvex_global->erase(hyperedges[k], hyperedges[j], del_edge);
                }
            }

            for(uint32_t j = hyperedges_start[i]; j< hyperedges_start[i+1]; j++){
                for(uint32_t k = j+1; k<hyperedges_start[i+1];k++){
                    sample_pairwise_adgvex_global->insert(hyperedges[j], hyperedges[k], i);
                    sample_pairwise_adgvex_global->insert(hyperedges[k], hyperedges[j], i);
                }
            }

        }
        
    }

    double update_factor = 1;
    if(currentEdges > Reservoir_size) update_factor = ((double)Reservoir_size/(double)currentEdges);
        

    for(uint32_t i = 0; i < min(Reservoir_size, currentEdges); i++) if(RS_sample_edge_num[i] > 2) tri_num_type1+=(double)(RS_sample_edge_num[i])*(double)(RS_sample_edge_num[i]-1)*(double)(RS_sample_edge_num[i]-2)/6.0/update_factor;

    for (uint32_t i = 0;i<n;i++){
        if(sample_pairwise_adgvex_global->data[i].size()>1){
            for (const auto& pair : sample_pairwise_adgvex_global->data[i]) {
                if(pair.first > i){
                    for(auto v1 = sample_pairwise_adgvex_global->data[i].begin(), v2 = sample_pairwise_adgvex_global->data[pair.first].begin(); v1 != sample_pairwise_adgvex_global->data[i].end() && v2 != sample_pairwise_adgvex_global->data[pair.first].end();){
                        if(v1->first == v2->first){
                            if(v1->first > i && v1->first > pair.first){
                                intersect_three_sets2(v1->second, v2->second, pair.second, tri_num_type2_, tri_num_type3_,  update_factor);
                                tri_num_type2+=tri_num_type2_;
                                tri_num_type3+=tri_num_type3_;
                            }
                            ++v1;
                            ++v2;

                        }else if (v1->first < v2->first) {
                            ++v1;
                        }else {
                            ++v2;
                        }
                    }

                }
            }
        }

    }
    cout<<"type-1: "<<(int64_t)tri_num_type1<<endl;
    cout<<"type-2: "<<(int64_t)tri_num_type2/2<<endl;
    cout<<"type-3: "<<(int64_t)tri_num_type3/2<<endl;

    vector<uint64_t> type_num(3);
    type_num[0] = (int64_t)tri_num_type1;
    type_num[1] = (int64_t)tri_num_type2/2;
    type_num[2] = (int64_t)tri_num_type3/2;

    return type_num;
}

void Graph::intersect_three_sets2(const std::set<uint32_t>& set1, const std::set<uint32_t>& set2, const std::set<uint32_t>& set3, double &tri_num_type2_, double &tri_num_type3_, double update_factor){
    auto it1 = set1.begin();
    auto it2 = set2.begin();
    auto it3 = set3.begin();

    double common_num_ = 0;
    double tri_num1 = 0, tri_num2 = 0, tri_num3 = 0;


    while (it1 != set1.end() && it2 != set2.end() && it3 != set3.end()) {
        if (*it1 == *it2 && *it2 == *it3) {
            ++it1;
            ++it2;
            ++it3;
            common_num_++;
        } else if (*it1 < *it2 && *it1 < *it3) {
            ++it1;  
        } else if (*it2 < *it3 && *it2 < *it1) {
            ++it2;
        } else {
            ++it3;
        }
    }
    tri_num1 = (double)set1.size() - common_num_;
    tri_num2 = (double)set2.size() - common_num_;
    tri_num3 = (double)set3.size() - common_num_;

    tri_num_type2_ = (tri_num1+tri_num2+tri_num3)*common_num_/update_factor/update_factor;
    tri_num_type3_ = (tri_num1*tri_num2*tri_num3)/update_factor/update_factor/update_factor;
}

// vector<uint64_t> Graph::tc_tri_stream_local_space(){
//     double tri_num_type1 = 0;
//     double tri_num_type2 = 0;
//     double tri_num_type3 = 0;
//     uint32_t currentEdges = 0;

//     srand(static_cast<unsigned int>(time(0)));
//     std::random_device rd;
//     std::mt19937 gen(rd());

//     int RS_sample_edge_l_i = 0;

//     std::uniform_real_distribution<> dis(0.0, 1.0);
//     double tri_num_type1_, tri_num_type2_, tri_num_type3_;

//     int judge_type1 = 0;
//     double update_factor = 1;

//     std::cout<<"Reservoir_size:"<<Reservoir_size<<std::endl;
//     vector<uint32_t> edge_nei(e);
//     uint32_t edge_nei_i = 0;
//     vector<int> edge_nei_exist(e,-1);
    

//     for(int i = 0;i<e;i++){

//         // cout<<i<<endl;
        
//         currentEdges++;
//         if(all_hyperedges[i].size() > 2) tri_num_type1 += (all_hyperedges[i].size()*(all_hyperedges[i].size()-1)*(all_hyperedges[i].size()-2))/6;

//         update_factor = 1.0;
//         if(currentEdges > Reservoir_size) update_factor = ((double)Reservoir_size/(double)(currentEdges));

//         uint32_t max_edge = min(currentEdges-1,Reservoir_size);

//         edge_nei_i = 0;

//         for(uint32_t v = 0;v<all_hyperedges[i].size();v++){
//             for(uint32_t v2 = 0; v2 < sample_vertices[all_hyperedges[i][v]].size(); v2++){ 
//                 if(edge_nei_exist[sample_vertices[all_hyperedges[i][v]][v2]] < i){
//                     edge_nei[edge_nei_i++] = sample_vertices[all_hyperedges[i][v]][v2];
//                     edge_nei_exist[sample_vertices[all_hyperedges[i][v]][v2]] = i;
//                 } 
//             }
            
//         }

//         // for(uint32_t j = 0;j<edge_nei_i;j++) cout<<edge_nei[j]<<" ";
//         // cout<<endl;

//         for(uint32_t j = 0;j<edge_nei_i;j++){
//             intersect_two_sets3(all_hyperedges[i], sample_hyperedges[edge_nei[j]], tri_num_type2_, update_factor);
//             tri_num_type2+=tri_num_type2_;

//             for(uint32_t k = j+1;k<edge_nei_i;k++){
//                 intersect_three_sets3(all_hyperedges[i], sample_hyperedges[edge_nei[j]], sample_hyperedges[edge_nei[k]], tri_num_type3_, update_factor);
//                 tri_num_type3+=tri_num_type3_;
//             }
//         }
//         if (currentEdges <= Reservoir_size) {
//             sample_hyperedges[currentEdges - 1] = all_hyperedges[i];
//             for (uint32_t v = 0; v < all_hyperedges[i].size(); v++)
//                 sample_vertices[all_hyperedges[i][v]].push_back(currentEdges - 1);
//         } else if (dis(gen) < (double)Reservoir_size / (double)currentEdges) {
//             uint32_t del_edge = rand() % Reservoir_size;
    
//             for (uint32_t v = 0; v < sample_hyperedges[del_edge].size(); v++) {
//                 uint32_t vertex = sample_hyperedges[del_edge][v];
//                 auto& vertex_edges = sample_vertices[vertex];
//                 auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
//                 if (it != vertex_edges.end()) {
//                     std::swap(*it, vertex_edges.back());
//                     vertex_edges.pop_back();
//                 }
//                 // else cout<<"error"<<endl;
//             }
//             sample_hyperedges[del_edge] = all_hyperedges[i];
//             for (uint32_t v = 0; v < all_hyperedges[i].size(); v++)
//                 sample_vertices[all_hyperedges[i][v]].push_back(del_edge);
//         }
//     }


//     cout<<"type-1: "<<(int64_t)tri_num_type1<<endl;
//     cout<<"type-2: "<<(int64_t)tri_num_type2<<endl;
//     cout<<"type-3: "<<(int64_t)tri_num_type3<<endl;

//     vector<uint64_t> type_num(3);
//     type_num[0] = (int64_t)tri_num_type1;
//     type_num[1] = (int64_t)tri_num_type2;
//     type_num[2] = (int64_t)tri_num_type3;

//     return type_num;
// }

vector<uint64_t> Graph::tc_tri_stream_local_space() {
    double tri_num_type1 = 0;
    double tri_num_type2 = 0;
    double tri_num_type3 = 0;
    uint32_t currentEdges = 0;

    srand(static_cast<unsigned int>(time(0)));
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> dis(0.0, 1.0);
    double tri_num_type2_, tri_num_type3_;

    double update_factor = 1;

    std::cout << "Reservoir_size:" << Reservoir_size << std::endl;

    vector<uint32_t> edge_nei;
    edge_nei.reserve(e);
    std::unordered_set<uint32_t> edge_nei_exist;

#pragma omp simd
    for (int i = 0; i < e; i++) {
        currentEdges++;
        uint32_t edge_size = all_hyperedges[i].size();
        if (edge_size > 2)
            tri_num_type1 += (edge_size * (edge_size - 1) * (edge_size - 2)) / 6;

        update_factor = (currentEdges > Reservoir_size) ? ((double)Reservoir_size / (double)(currentEdges)) : 1.0;

        edge_nei.clear();
        edge_nei_exist.clear();

        #pragma omp simd
        for (size_t j = 0; j < all_hyperedges[i].size(); j++) {
            uint32_t v = all_hyperedges[i][j];
            const auto& vertex_edges = sample_vertices[v];

            #pragma omp simd
            for (size_t k = 0; k < vertex_edges.size(); k++) {
                uint32_t edge_id = vertex_edges[k];
                if (edge_nei_exist.insert(edge_id).second) {
                    edge_nei.push_back(edge_id);
                }
            }
        }

        #pragma omp simd
        for (size_t idx = 0; idx < edge_nei.size(); idx++) {
            uint32_t j = edge_nei[idx];
            intersect_two_sets3(all_hyperedges[i], sample_hyperedges[j], tri_num_type2_, update_factor);
            tri_num_type2 += tri_num_type2_;
            #pragma omp simd
            for (size_t kdx = idx + 1; kdx < edge_nei.size(); kdx++) {
                uint32_t k = edge_nei[kdx];
                intersect_three_sets3(all_hyperedges[i], sample_hyperedges[j], sample_hyperedges[k], tri_num_type3_, update_factor);
                tri_num_type3 += tri_num_type3_;
            }
        }

        // 更新采样的超边集合
        if (currentEdges <= Reservoir_size) {
            sample_hyperedges[currentEdges - 1] = all_hyperedges[i];
            #pragma omp simd
            for (size_t j = 0; j < all_hyperedges[i].size(); j++) {
                uint32_t v = all_hyperedges[i][j];
                sample_vertices[v].push_back(currentEdges - 1);
            }
        } else if (dis(gen) < (double)Reservoir_size / (double)currentEdges) {
            uint32_t del_edge = rand() % Reservoir_size;
            #pragma omp simd
            for (size_t j = 0; j < sample_hyperedges[del_edge].size(); j++) {
                uint32_t vertex = sample_hyperedges[del_edge][j];
                auto& vertex_edges = sample_vertices[vertex];
                auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
                if (it != vertex_edges.end()) {
                    vertex_edges.erase(it);
                }
            }

            sample_hyperedges[del_edge] = all_hyperedges[i];
            #pragma omp simd
            for (size_t k = 0; k < all_hyperedges[i].size(); k++) {
                uint32_t v = all_hyperedges[i][k];
                sample_vertices[v].push_back(del_edge);
            }
        }
    }

    std::cout << "type-1: " << (int64_t)tri_num_type1 << std::endl;
    std::cout << "type-2: " << (int64_t)tri_num_type2 << std::endl;
    std::cout << "type-3: " << (int64_t)tri_num_type3 << std::endl;

    vector<uint64_t> type_num(3);
    type_num[0] = (int64_t)tri_num_type1;
    type_num[1] = (int64_t)tri_num_type2;
    type_num[2] = (int64_t)tri_num_type3;

    return type_num;
}

vector<uint64_t> Graph::tc_tri_stream_local_space2() {
    double tri_num_type1 = 0;
    double tri_num_type2 = 0;
    double tri_num_type3 = 0;
    uint32_t currentEdges = 0;

    srand(static_cast<unsigned int>(time(0)));
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> dis(0.0, 1.0);
    double tri_num_type2_, tri_num_type3_;

    double update_factor = 1;

    std::cout << "Reservoir_size:" << Reservoir_size << std::endl;

    vector<uint32_t> edge_nei;
    edge_nei.reserve(e);
    std::unordered_set<uint32_t> edge_nei_exist;


    for (int i = 0; i < e; i++) {
        currentEdges++;
        uint32_t edge_size = all_hyperedges[i].size();
        if (edge_size > 2)
            tri_num_type1 += (edge_size * (edge_size - 1) * (edge_size - 2)) / 6;

        

        // 更新采样的超边集合
        if (currentEdges <= Reservoir_size) {
            sample_hyperedges[currentEdges - 1] = all_hyperedges[i];
            #pragma omp simd
            for (size_t j = 0; j < all_hyperedges[i].size(); j++) {
                uint32_t v = all_hyperedges[i][j];
                sample_vertices[v].push_back(currentEdges - 1);
            }
        } else if (dis(gen) < (double)Reservoir_size / (double)currentEdges) {
            uint32_t del_edge = rand() % Reservoir_size;
            
            #pragma omp simd
            for (size_t j = 0; j < sample_hyperedges[del_edge].size(); j++) {
                uint32_t vertex = sample_hyperedges[del_edge][j];
                auto& vertex_edges = sample_vertices[vertex];
                auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
                if (it != vertex_edges.end()) {
                    vertex_edges.erase(it);
                }
            }

            update_factor = (currentEdges > Reservoir_size) ? ((double)Reservoir_size / (double)(currentEdges)) : 1.0;

            edge_nei.clear();
            edge_nei_exist.clear();

            #pragma omp simd
            for (size_t j = 0; j < all_hyperedges[i].size(); j++) {
                uint32_t v = all_hyperedges[i][j];
                const auto& vertex_edges = sample_vertices[v];

                #pragma omp simd
                for (size_t k = 0; k < vertex_edges.size(); k++) {
                    uint32_t edge_id = vertex_edges[k];
                    if (edge_nei_exist.insert(edge_id).second) {
                        edge_nei.push_back(edge_id);
                    }
                }
            }

            #pragma omp simd
            for (size_t idx = 0; idx < edge_nei.size(); idx++) {
                uint32_t j = edge_nei[idx];
                intersect_two_sets3(all_hyperedges[i], sample_hyperedges[j], tri_num_type2_, update_factor);
                tri_num_type2 += tri_num_type2_/update_factor;
            
                for (size_t kdx = idx + 1; kdx < edge_nei.size(); kdx++) {
                    uint32_t k = edge_nei[kdx];
                    intersect_three_sets3(all_hyperedges[i], sample_hyperedges[j], sample_hyperedges[k], tri_num_type3_, update_factor);
                    tri_num_type3 += tri_num_type3_/update_factor;
                }
            }




            sample_hyperedges[del_edge] = all_hyperedges[i];
            #pragma omp simd
            for (size_t k = 0; k < all_hyperedges[i].size(); k++) {
                uint32_t v = all_hyperedges[i][k];
                sample_vertices[v].push_back(del_edge);
            }
        }
    }

    std::cout << "type-1: " << (int64_t)tri_num_type1 << std::endl;
    std::cout << "type-2: " << (int64_t)tri_num_type2 << std::endl;
    std::cout << "type-3: " << (int64_t)tri_num_type3 << std::endl;

    vector<uint64_t> type_num(3);
    type_num[0] = (int64_t)tri_num_type1;
    type_num[1] = (int64_t)tri_num_type2;
    type_num[2] = (int64_t)tri_num_type3;

    return type_num;
}

void Graph::intersect_three_sets3(
    std::vector<uint32_t> &set1, 
    std::vector<uint32_t> &set2, 
    std::vector<uint32_t> &set3, 
    double &tri_num_type3_, 
    double update_factor
) {
    double common_num_ = 0;
    double common_num_1 = 0, common_num_2 = 0, common_num_3 = 0;

    // 计算三个集合的交集数量
    for(uint32_t i = 0, j = 0, k = 0; i < set1.size() && j < set2.size() && k < set3.size();) {
        if (set1[i] == set2[j] && set2[j] == set3[k]) {
            ++i;
            ++j;
            ++k;
            common_num_++;
        } else {
            uint32_t min_val = std::min({set1[i], set2[j], set3[k]});
            if (set1[i] == min_val) ++i;
            if (set2[j] == min_val) ++j;
            if (set3[k] == min_val) ++k;
        }
    }

    // 计算 set1 和 set2 的交集数量
    for(uint32_t i = 0, j = 0; i < set1.size() && j < set2.size();) {
        if(set1[i] == set2[j]) {
            common_num_1++;
            i++;
            j++;
        } else {
            uint32_t min_val = std::min(set1[i], set2[j]);
            if (set1[i] == min_val) i++;
            else j++;
        }
    }

    // 计算 set1 和 set3 的交集数量
    for(uint32_t i = 0, j = 0; j < set1.size() && i < set3.size();) {
        if(set1[i] == set3[j]) {
            common_num_2++;
            i++;
            j++;
        } else {
            uint32_t min_val = std::min(set1[i], set3[j]);
            if (set1[i] == min_val) i++;
            else j++;
        }
    }

    // 计算 set2 和 set3 的交集数量
    for(uint32_t i = 0, j = 0; i < set2.size() && j < set3.size();) {
        if(set2[j] == set3[i]) {
            common_num_3++;
            i++;
            j++;
        } else {
            uint32_t min_val = std::min(set2[j], set3[i]);
            if (set2[j] == min_val) j++;
            else i++;
        }
    }

    // cout<<common_num_1<<" "<<common_num_2<<" "<<common_num_3<<" "<<common_num_<<endl;

    // 确保 update_factor 不为零
    if (update_factor != 0) {
        tri_num_type3_ = ((common_num_1 - common_num_) * (common_num_2 - common_num_) * (common_num_3 - common_num_)) / (update_factor * update_factor);
    } else {
        // 处理除以零的情况
        tri_num_type3_ = 0;
    }
}

void Graph::intersect_two_sets3(vector<uint32_t> &set1, vector<uint32_t> &set2, double &tri_num_type2_, double update_factor){
    double common_num_ = 0;
    for(uint32_t i = 0, j = 0; i < set1.size() && j < set2.size();) {
        if(set1[i] == set2[j]) {
            common_num_++;
            i++;
            j++;
        } else {
            uint32_t min_val = std::min(set1[i], set2[j]);
            if (set1[i] == min_val) i++;
            else j++;
        }
    }

    tri_num_type2_=(set1.size() - common_num_ + set2.size() - common_num_)*common_num_*(common_num_-1)/2/update_factor;

}

int Graph::intersect_three_sets_fixed(
    std::vector<uint32_t> &set1, 
    std::vector<uint32_t> &set2, 
    std::vector<uint32_t> &set3, 
    double &tri_num_type3_, 
    double update_factor1,
    double update_factor2
) {
    double common_num_ = 0;
    double common_num_1 = 0, common_num_2 = 0, common_num_3 = 0;

        // 计算 set2 和 set3 的交集数量
    for(uint32_t i = 0, j = 0; i < set2.size() && j < set3.size();) {
        if(set2[i] == set3[j]) {
            common_num_3++;
            i++;
            j++;
        } else if(set2[i] < set3[j]){
            i++;
            
        }else j++;
    }

    if(common_num_3 == 0 || set2.size() == common_num_3 || set3.size() == common_num_3){
        tri_num_type3_ = 0;
        return 1;
    }

    // 计算 set1 和 set3 的交集数量
    for(uint32_t i = 0, j = 0; i < set1.size() && j < set3.size();) {
        if(set1[i] == set3[j]) {
            common_num_2++;
            i++;
            j++;
        } else if(set1[i] < set3[j]) {
            i++;
            
        } else j++;
    }

    if(common_num_2 == 0 || set1.size() == common_num_2 || set3.size() == common_num_2){
        tri_num_type3_ = 0;
        return 2;
    }

        // 计算 set1 和 set2 的交集数量
    for(uint32_t i = 0, j = 0; i < set1.size() && j < set2.size();) {
        if(set1[i] == set2[j]) {
            common_num_1++;
            i++;
            j++;
        } else {
            uint32_t min_val = std::min(set1[i], set2[j]);
            if (set1[i] == min_val) i++;
            else j++;
        }
    }

    if(common_num_1 == 0 || set1.size() == common_num_1 || set2.size() == common_num_1){
        tri_num_type3_ = 0;
        return 3;
    }

    // 计算三个集合的交集数量
    for(uint32_t i = 0, j = 0, k = 0; i < set1.size() && j < set2.size() && k < set3.size();) {
        if (set1[i] == set2[j] && set2[j] == set3[k]) {
            ++i;
            ++j;
            ++k;
            common_num_++;
        } else {
            uint32_t min_val = std::min({set1[i], set2[j], set3[k]});
            if (set1[i] == min_val) ++i;
            if (set2[j] == min_val) ++j;
            if (set3[k] == min_val) ++k;
        }
    }
    // cout<<common_num_1<<" "<<common_num_2<<" "<<common_num_3<<" "<<common_num_<<endl;

    tri_num_type3_ = ((common_num_1 - common_num_) * (common_num_2 - common_num_) * (common_num_3 - common_num_)) / (update_factor1 * update_factor2);
    return 4;

}

void Graph::intersect_two_sets_fixed(vector<uint32_t> &set1, vector<uint32_t> &set2, double &tri_num_type2_, double update_factor, int &common_num){
    common_num = 0;
    for(uint32_t i = 0, j = 0; i < set1.size() && j < set2.size();) {
        if(set1[i] == set2[j]) {
            common_num++;
            i++;
            j++;
        } 
        else if(set1[i] < set2[j]) i++;
        else j++;
    }

    tri_num_type2_=(set1.size() - common_num + set2.size() - common_num)*common_num*(common_num-1)/2/update_factor;

}

int Graph::intersect_three_sets_fixed2(vector<uint32_t> &common_set1, vector<uint32_t> &common_set2, vector<uint32_t> &set3, vector<uint32_t> &set4, double &tri_num_type3_, double update_factor){
    double common_num_ = 0;
    uint32_t common_set3_i = 0;
    uint32_t common_set1_2_i = 0;

    // for(uint32_t i = 0, j = 0; i < common_set1.size() && j < common_set2.size();) {
    //     if(set3[i] == set4[j]) {
    //         common_set1_2[common_set1_2_i++] = common_set1[i];
    //         i++;
    //         j++;
            
    //     } else if(common_set1[i] < common_set2[j]){
    //         i++;
            
    //     }else j++;
    // }

    // if(common_set1.size() == common_set1_2_i || common_set2.size() == common_set1_2_i){
    //     tri_num_type3_ = 0;
    //     return 1;
    // }


    for(uint32_t i = 0, j = 0; i < set3.size() && j < set4.size();) {
        if(set3[i] == set4[j]) {
            common_set[common_set3_i++] = set3[i];
            i++;
            j++;
            
        } else if(set3[i] < set4[j]){
            i++;
            
        }else j++;
    }

    if(common_set3_i == 0 || set3.size() == common_set3_i || set4.size() == common_set3_i){
        tri_num_type3_ = 0;
        return 1;
    }


    for(uint32_t i = 0, j = 0, k = 0; i < common_set1.size() && j < common_set2.size() && k < common_set3_i;) {
        if (common_set1[i] == common_set2[j] && common_set2[j] == common_set[k]) {
            ++i;
            ++j;
            ++k;
            common_num_++;
        } else {
            uint32_t min_val = std::min({common_set1[i], common_set2[j], common_set[k]});
            if (common_set1[i] == min_val) ++i;
            if (common_set2[j] == min_val) ++j;
            if (common_set[k] == min_val) ++k;
        }
    }


    tri_num_type3_ = ((common_set1.size() - common_num_) * (common_set2.size() - common_num_) * (common_set3_i - common_num_)) / (update_factor);

    return 2;
    
}

void Graph::intersect_two_sets_fixed2(vector<uint32_t> &set1, vector<uint32_t> &set2, double &tri_num_type2_, double update_factor, int &common_num, vector<uint32_t> &sample_common_vertices_single){
    common_num = 0;

    for(uint32_t i = 0, j = 0; i < set1.size() && j < set2.size();) {
        if(set1[i] == set2[j]) {
            sample_common_vertices_single.push_back(set1[i]);
            common_num++;
            i++;
            j++;
        } 
        else if(set1[i] < set2[j]) i++;
        else j++;
    }

    tri_num_type2_=(set1.size() - common_num + set2.size() - common_num)*common_num*(common_num-1)/2/update_factor;
}


vector<uint64_t> Graph::tc_tri_stream_local_space_fixed(){
    double tri_num_type1 = 0;
    double tri_num_type2 = 0;
    double tri_num_type3 = 0;
    uint32_t currentEdges = 0;
    uint32_t currentVertices = 0;
    uint32_t sampleVertices = 0;
    uint32_t Reservoir_size_ = Reservoir_size;

    double Reservoir_size_now = 0;

    srand(static_cast<unsigned int>(time(0)));
    std::random_device rd;
    std::mt19937 gen(rd());

    int RS_sample_edge_l_i = 0;

    std::uniform_real_distribution<> dis(0.0, 1.0);
    double tri_num_type1_, tri_num_type2_, tri_num_type3_;

    int judge_type1 = 0;
    double update_factor = 1;

    std::cout<<"Reservoir_size:"<<Reservoir_size<<std::endl;
    vector<uint32_t> edge_nei(min(Reservoir_size_/2, e));
    uint32_t edge_nei_i = 0;
    vector<int> edge_nei_dup(e,-1);
    vector<pairwise_edge> sample_all_vertices;
    sample_all_vertices.reserve(Reservoir_size_);
    bool r_full = false;

    std::unordered_set<uint32_t> edge_nei_exist;
    int common_num;

    // int time_2 = 0, time_3 = 0, time_3_0 = 0;
    // vector<int> time_3_type(5,0);
    // int time_3_type_;
    
    for(int i = 0;i<e;i++){
        if(all_hyperedges[i].size() < 2) continue;

        // if(i%1000 == 0) 
        // cout<<i<<endl;
        currentEdges++;
        currentVertices+=all_hyperedges[i].size();

        if(all_hyperedges[i].size() > 2) tri_num_type1 += (all_hyperedges[i].size()*(all_hyperedges[i].size()-1)*(all_hyperedges[i].size()-2))/6;


        update_factor = 1.0;
        if(r_full) update_factor = ((double)Reservoir_size_now/(double)(currentEdges));

        edge_nei_i = 0;
        edge_nei_exist.clear();

        if(all_hyperedges[i].size() >= 2){

            #pragma omp simd
            for (size_t j = 0; j < all_hyperedges[i].size(); j++) {
                uint32_t v = all_hyperedges[i][j];
                const auto& vertex_edges = sample_vertices[v];

                #pragma omp simd
                for (size_t k = 0; k < vertex_edges.size(); k++) {
                    
                
                    uint32_t edge_id = vertex_edges[k];
                    // if(sample_hyperedges_fixed[edge_id].size() < 2) continue;
                    // if(sample_hyperedges_fixed[edge_id].size() < 2) continue;
                    if (edge_nei_exist.insert(edge_id).second) {
                        edge_nei[edge_nei_i++] = edge_id;
                    }
                }
            }
            sample_common_vertices.clear();

            sample_common_vertices.resize(edge_nei_i);

            // if(i%1000 == 0) 
            // cout<<edge_nei_i<<endl;
#pragma omp simd
            for(uint32_t j = 0;j<edge_nei_i;j++){
                // time_2++;
                // if(sample_hyperedges_fixed[edge_nei[j]].size() < 2) continue;
                intersect_two_sets_fixed2(all_hyperedges[i], sample_hyperedges_fixed[edge_nei[j]], tri_num_type2_, update_factor, common_num, sample_common_vertices[j]);
                tri_num_type2+=tri_num_type2_;

            }
            int time_3 = 0;
#pragma omp simd
            for(uint32_t j = 0;j<edge_nei_i;j++){

                // if(sample_hyperedges_fixed[edge_nei[j]].size() < 2) continue;

                if(all_hyperedges[i].size() - sample_common_vertices[j].size() == 0 || sample_hyperedges_fixed[edge_nei[j]].size() - sample_common_vertices[j].size() == 0) continue;
#pragma omp simd
                for(uint32_t k = j+1;k<edge_nei_i;k++){

                    // if(sample_hyperedges_fixed[edge_nei[k]].size() < 2) continue;
                    if(all_hyperedges[i].size() - sample_common_vertices[k].size() == 0 || sample_hyperedges_fixed[edge_nei[k]].size() - sample_common_vertices[k].size() == 0) continue;
                    time_3++;
                    intersect_three_sets_fixed2(sample_common_vertices[j], sample_common_vertices[k], sample_hyperedges_fixed[edge_nei[j]], sample_hyperedges_fixed[edge_nei[k]], tri_num_type3_, update_factor*update_factor);
                    tri_num_type3+=tri_num_type3_;
                    // if(tri_num_type3_ == 0) time_3_0++;
                    // time_3_type[time_3_type_]++;
                }
            }
            // cout<<time_3<<endl<<endl;
        }
        if (currentVertices <= Reservoir_size_) {

            Reservoir_size_now++;
            sampleVertices+=all_hyperedges[i].size();
            
            sample_hyperedges_fixed[(uint32_t)Reservoir_size_now - 1] = all_hyperedges[i];
            for (uint32_t v = 0; v < all_hyperedges[i].size(); v++){
                sample_vertices[all_hyperedges[i][v]].push_back((uint32_t)Reservoir_size_now - 1);
            }
            
                
        } else if (dis(gen) < (double)Reservoir_size_now / (double)currentEdges) {

            if(r_full == 0) {
                r_full = 1;
                cout<<"r_full:"<<Reservoir_size_now<<endl;
            }

            // cout<<1<<endl;
            double del_num = 1.0;

        

            double new_edge_sample_rate = (double)Reservoir_size_now / (double)currentEdges;
            double origin_sample = (double)Reservoir_size_now;

            

            uint32_t del_edge = rand() % (uint32_t)Reservoir_size_now;
            sampleVertices-=sample_hyperedges_fixed[del_edge].size();
    
            for (uint32_t v = 0; v < sample_hyperedges_fixed[del_edge].size(); v++) {
                uint32_t vertex = sample_hyperedges_fixed[del_edge][v];
                auto& vertex_edges = sample_vertices[vertex];
                auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
                if (it != vertex_edges.end()) {
                    std::swap(*it, vertex_edges.back());
                    vertex_edges.pop_back();
                }
                else cout<<"error1"<<endl;
            }

            // edge_nei_dup[del_edge] = i;

            // cout<<2<<endl;
            if(del_edge != (uint32_t)Reservoir_size_now-1){
                // sample_rates[del_edge] = sample_rates[(uint32_t)Reservoir_size_now-1];
                sample_hyperedges_fixed[del_edge] = sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1];
                for (uint32_t v = 0; v < sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1].size(); v++) {
                    uint32_t vertex = sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1][v];
                    auto& vertex_edges = sample_vertices[vertex];
                    auto it = std::find(vertex_edges.begin(), vertex_edges.end(), (uint32_t)Reservoir_size_now-1);
                    if (it != vertex_edges.end()) {
                        std::swap(*it, vertex_edges.back());
                        vertex_edges.pop_back();
                    }
                    else cout<<"error2"<<endl;
                    sample_vertices[vertex].push_back(del_edge);

                }

            }
            Reservoir_size_now--;

            sample_hyperedges_fixed[(uint32_t)Reservoir_size_now] = all_hyperedges[i];
            for (uint32_t v = 0; v < all_hyperedges[i].size(); v++)
                sample_vertices[all_hyperedges[i][v]].push_back((uint32_t)Reservoir_size_now);
            Reservoir_size_now++;
            sampleVertices+=all_hyperedges[i].size();

            // sample_rates[(uint32_t)Reservoir_size_now-1] = new_edge_sample_rate;

            while (sampleVertices > Reservoir_size_) {
                // while (edge_nei_dup[del_edge] == i) {
                del_edge = rand() % (uint32_t)Reservoir_size_now;
                    // cout<<del_edge<<" "<<Reservoir_size_now<<endl;
                // }
                edge_nei_dup[del_edge] = i;
                
                sampleVertices-=sample_hyperedges_fixed[del_edge].size();
                del_num++;

                for (uint32_t v = 0; v < sample_hyperedges_fixed[del_edge].size(); v++) {
                    uint32_t vertex = sample_hyperedges_fixed[del_edge][v];
                    auto& vertex_edges = sample_vertices[vertex];
                    auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
                    if (it != vertex_edges.end()) {
                        std::swap(*it, vertex_edges.back());
                        vertex_edges.pop_back();
                    }
                    else cout<<"error3"<<endl;
                }
                if(del_edge != (uint32_t)Reservoir_size_now-1){
                    // sample_rates[del_edge] = sample_rates[(uint32_t)Reservoir_size_now-1];
                    sample_hyperedges_fixed[del_edge] = sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1];
                    for (uint32_t v = 0; v < sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1].size(); v++) {
                        uint32_t vertex = sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1][v];
                        auto& vertex_edges = sample_vertices[vertex];
                        auto it = std::find(vertex_edges.begin(), vertex_edges.end(), (uint32_t)Reservoir_size_now-1);
                        if (it != vertex_edges.end()) {
                            std::swap(*it, vertex_edges.back());
                            vertex_edges.pop_back();
                        }
                        else cout<<"error4"<<endl;
                        sample_vertices[vertex].push_back(del_edge);
                    }
                }

                Reservoir_size_now--;

                // cout<<3<<endl;
            
            }
            
        }
    }


    cout<<"type-1: "<<(int64_t)tri_num_type1<<endl;
    cout<<"type-2: "<<(int64_t)tri_num_type2<<endl;
    cout<<"type-3: "<<(int64_t)tri_num_type3<<endl;

    cout<<"Reservoir_size_now:"<<Reservoir_size_now<<" "<<sampleVertices<<endl;

    vector<uint64_t> type_num(5);
    type_num[0] = (int64_t)tri_num_type1;
    type_num[1] = (int64_t)tri_num_type2;
    type_num[2] = (int64_t)tri_num_type3;
    type_num[3] = (int64_t)Reservoir_size_now;
    type_num[4] = (int64_t)sampleVertices;

    // cout<<time_2<<" "<<time_3<<" "<<time_3_0<<endl;
    // cout<<time_3_type[1]<<" "<<time_3_type[2]<<endl;

    return type_num;
}




vector<uint64_t> Graph::tc_tri_stream_local_space_fixed2(){
    double tri_num_type1 = 0;
    double tri_num_type2 = 0;
    double tri_num_type3 = 0;
    uint32_t currentEdges = 0;
    uint32_t currentVertices = 0;
    uint32_t sampleVertices = 0;
    uint32_t Reservoir_size_ = Reservoir_size;

    double Reservoir_size_now = 0;

    srand(static_cast<unsigned int>(time(0)));
    std::random_device rd;
    std::mt19937 gen(rd());

    int RS_sample_edge_l_i = 0;

    std::uniform_real_distribution<> dis(0.0, 1.0);
    double tri_num_type1_, tri_num_type2_, tri_num_type3_;

    int judge_type1 = 0;
    double update_factor = 1;

    std::cout<<"Reservoir_size:"<<Reservoir_size<<std::endl;
    vector<uint32_t> edge_nei(e);
    uint32_t edge_nei_i = 0;
    vector<int> edge_nei_exist(e,-1);
    vector<int> edge_nei_dup(e,-1);
    vector<pairwise_edge> sample_all_vertices;
    sample_all_vertices.reserve(Reservoir_size_);
    vector<double> sample_rates(e, 1.0);
    bool r_full = false;
    int adjust = 0;

    vector<int> sample_rates_molerator(e, 1.0);
    vector<int> sample_rates_denominator(e, 1.0);
    string test;
    double judge;
    int common_num;
    

    for(int i = 0;i<e;i++){

        // cout<<currentVertices<<" "<<Reservoir_size_now<<" "<<all_hyperedges[i].size()<<endl;
        currentEdges++;
        currentVertices+=all_hyperedges[i].size();
        if(all_hyperedges[i].size() > 2) tri_num_type1 += (all_hyperedges[i].size()*(all_hyperedges[i].size()-1)*(all_hyperedges[i].size()-2))/6;

        update_factor = 1.0;
        if(r_full) update_factor = ((double)Reservoir_size_now/(double)(currentEdges));
        adjust = 0;
        if(r_full) adjust = 1;

        edge_nei_i = 0;

        for(uint32_t v = 0;v<all_hyperedges[i].size();v++){
            for(uint32_t v2 = 0; v2 < sample_vertices[all_hyperedges[i][v]].size(); v2++){ 
                if(edge_nei_exist[sample_vertices[all_hyperedges[i][v]][v2]] < i){
                    edge_nei[edge_nei_i++] = sample_vertices[all_hyperedges[i][v]][v2];
                    edge_nei_exist[sample_vertices[all_hyperedges[i][v]][v2]] = i;
                } 
            }
            
        }

        // for(uint32_t j = 0;j<edge_nei_i;j++) cout<<edge_nei[j]<<" ";
        // cout<<endl;

        for(uint32_t j = 0;j<edge_nei_i;j++){
            intersect_two_sets_fixed(all_hyperedges[i], sample_hyperedges_fixed[edge_nei[j]], tri_num_type2_, (double)sample_rates[edge_nei[j]],common_num);
            // intersect_two_sets_fixed(all_hyperedges[i], sample_hyperedges_fixed[edge_nei[j]], tri_num_type2_, update_factor);
            
            tri_num_type2+=tri_num_type2_;
            // cout<<currentEdges<<" "<<Reservoir_size_now<<" "<<sample_rates[edge_nei[j]]<<" "<<update_factor<<endl;

            for(uint32_t k = j+1;k<edge_nei_i;k++){
                intersect_three_sets_fixed(all_hyperedges[i], sample_hyperedges_fixed[edge_nei[j]], sample_hyperedges_fixed[edge_nei[k]], tri_num_type3_, (double)sample_rates[edge_nei[j]], (double)sample_rates[edge_nei[k]]);
                // intersect_three_sets_fixed(all_hyperedges[i], sample_hyperedges_fixed[edge_nei[j]], sample_hyperedges_fixed[edge_nei[k]], tri_num_type3_, update_factor, update_factor);
                tri_num_type3+=tri_num_type3_;
            }
        }
        if(sampleVertices+all_hyperedges[i].size() <= Reservoir_size_) judge = (double)(Reservoir_size_now + 1) / (double)currentEdges;
        else judge = (double)Reservoir_size_now / (double)currentEdges;
        
        
        if (currentVertices <= Reservoir_size_) {

            Reservoir_size_now++;
            sampleVertices+=all_hyperedges[i].size();
            
            sample_hyperedges_fixed[(uint32_t)Reservoir_size_now - 1] = all_hyperedges[i];
            for (uint32_t v = 0; v < all_hyperedges[i].size(); v++){
                sample_vertices[all_hyperedges[i][v]].push_back((uint32_t)Reservoir_size_now - 1);
            }

            sample_rates[(uint32_t)Reservoir_size_now - 1] = 1.0;
            sample_rates_molerator[(uint32_t)Reservoir_size_now - 1] = 1;
            sample_rates_denominator[(uint32_t)Reservoir_size_now - 1] = 1;

                
        } else if (dis(gen) < judge) {
            // string ddd;
            // cout<<Reservoir_size_now<<" "<<currentEdges<<endl;
            // for(uint32_t rate_i = 0; rate_i < (uint32_t)Reservoir_size_now; rate_i++){
            //             cout<<sample_rates_molerator[rate_i]<<" "<<sample_rates_denominator[rate_i]<<"|";
            //         }
            //         cout<<endl;

            
            // cin>>ddd;

            if(!r_full) r_full = true;

            // cout<<1<<endl;
            int del_num = 0;
            uint32_t del_edge;

        


            double new_edge_sample_rate = judge;
            // double origin_sample = (double)Reservoir_size_now;
/*
            

            uint32_t del_edge = rand() % (uint32_t)Reservoir_size_now;
            sampleVertices-=sample_hyperedges_fixed[del_edge].size();
    
            for (uint32_t v = 0; v < sample_hyperedges_fixed[del_edge].size(); v++) {
                uint32_t vertex = sample_hyperedges_fixed[del_edge][v];
                auto& vertex_edges = sample_vertices[vertex];
                auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
                if (it != vertex_edges.end()) {
                    std::swap(*it, vertex_edges.back());
                    vertex_edges.pop_back();
                }
                else cout<<"error1"<<endl;
            }

            // edge_nei_dup[del_edge] = i;

            // cout<<2<<endl;
            if(del_edge != (uint32_t)Reservoir_size_now-1){
                // sample_rates[del_edge] = sample_rates[(uint32_t)Reservoir_size_now-1];
                sample_hyperedges_fixed[del_edge] = sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1];
                for (uint32_t v = 0; v < sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1].size(); v++) {
                    uint32_t vertex = sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1][v];
                    auto& vertex_edges = sample_vertices[vertex];
                    auto it = std::find(vertex_edges.begin(), vertex_edges.end(), (uint32_t)Reservoir_size_now-1);
                    if (it != vertex_edges.end()) {
                        std::swap(*it, vertex_edges.back());
                        vertex_edges.pop_back();
                    }
                    else cout<<"error2"<<endl;
                    sample_vertices[vertex].push_back(del_edge);

                }

            }
            Reservoir_size_now--;
*/
            sample_hyperedges_fixed[(uint32_t)Reservoir_size_now] = all_hyperedges[i];
            for (uint32_t v = 0; v < all_hyperedges[i].size(); v++)
                sample_vertices[all_hyperedges[i][v]].push_back((uint32_t)Reservoir_size_now);
            Reservoir_size_now++;
            sampleVertices+=all_hyperedges[i].size();

            sample_rates[(uint32_t)Reservoir_size_now-1] = new_edge_sample_rate;
            sample_rates_molerator[(uint32_t)Reservoir_size_now-1] = (int)Reservoir_size_now-1;
            sample_rates_denominator[(uint32_t)Reservoir_size_now-1] = currentEdges;

            while (sampleVertices > Reservoir_size_) {
                
                if(del_num<1){
                    del_edge = rand() % ((uint32_t)Reservoir_size_now-1);
                    
                    for(uint32_t rate_i = 0; rate_i < (uint32_t)Reservoir_size_now-1; rate_i++){
                        sample_rates[rate_i] = sample_rates[rate_i]*((double)(currentEdges-1)/(double)currentEdges);
                        sample_rates_molerator[rate_i] = sample_rates_molerator[rate_i]*(currentEdges-1)/sample_rates_denominator[rate_i];
                        // if(sample_rates_molerator[rate_i]!=(int)Reservoir_size_now-1)
                        //     cout<<"rrrrrtttttgg                gdgdgdggdgd"<<" "<<rate_i<<" "<<(currentEdges-1)<<" "<<sample_rates_denominator[rate_i]<<endl;
                        sample_rates_denominator[rate_i] = currentEdges;
                        
                    }
                }else{
                    del_edge = rand() % ((uint32_t)Reservoir_size_now);
                    for(uint32_t rate_i = 0; rate_i < (uint32_t)Reservoir_size_now; rate_i++){
                        sample_rates[rate_i] = sample_rates[rate_i]*((Reservoir_size_now-1)/Reservoir_size_now);
                    }
                }

                
                sampleVertices-=sample_hyperedges_fixed[del_edge].size();
                del_num++;

                for (uint32_t v = 0; v < sample_hyperedges_fixed[del_edge].size(); v++) {
                    uint32_t vertex = sample_hyperedges_fixed[del_edge][v];
                    auto& vertex_edges = sample_vertices[vertex];
                    auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
                    if (it != vertex_edges.end()) {
                        std::swap(*it, vertex_edges.back());
                        vertex_edges.pop_back();
                    }
                    else cout<<"error3"<<endl;
                }

                if(del_edge != (uint32_t)Reservoir_size_now-1){
                    sample_rates[del_edge] = sample_rates[(uint32_t)Reservoir_size_now-1];
                    sample_rates_molerator[del_edge] = sample_rates_molerator[(uint32_t)Reservoir_size_now-1];
                    sample_rates_denominator[del_edge] = sample_rates_denominator[(uint32_t)Reservoir_size_now-1];
                    sample_hyperedges_fixed[del_edge] = sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1];
                    for (uint32_t v = 0; v < sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1].size(); v++) {
                        uint32_t vertex = sample_hyperedges_fixed[(uint32_t)Reservoir_size_now-1][v];
                        auto& vertex_edges = sample_vertices[vertex];
                        auto it = std::find(vertex_edges.begin(), vertex_edges.end(), (uint32_t)Reservoir_size_now-1);
                        if (it != vertex_edges.end()) {
                            std::swap(*it, vertex_edges.back());
                            vertex_edges.pop_back();
                        }
                        else cout<<"error4"<<endl;
                        sample_vertices[vertex].push_back(del_edge);
                    }
                }

                // cout<<"del_edge:"<<del_edge<<endl;

                Reservoir_size_now--;

                // for(uint32_t rate_i = 0; rate_i < (uint32_t)Reservoir_size_now; rate_i++){
                //     cout<<sample_rates_molerator[rate_i]<<" "<<sample_rates_denominator[rate_i]<<endl;
                // }

                // cout<<3<<endl;
            
            }
            if(del_num == 0){
                // sample_rates[(uint32_t)Reservoir_size_now-1] = sample_rates[(uint32_t)Reservoir_size_now-1]*Reservoir_size_now/(Reservoir_size_now-1);
                for(uint32_t rate_i = 0; rate_i < (uint32_t)Reservoir_size_now-1; rate_i++){
                    sample_rates[rate_i] = sample_rates[rate_i]*((double)(Reservoir_size_now)/((double)Reservoir_size_now-1));
                    sample_rates_molerator[rate_i] = sample_rates_molerator[rate_i]*(currentEdges-1)/sample_rates_denominator[rate_i];
                    sample_rates_denominator[rate_i] = currentEdges;
                }
            }

            

            // cout<<4<<endl;



            // cout<<5<<endl;
        }
        else{
            for(uint32_t rate_i = 0; rate_i < (uint32_t)Reservoir_size_now-1; rate_i++){
                sample_rates[rate_i] = sample_rates[rate_i]*((double)(currentEdges-1)/(double)currentEdges);
                sample_rates_molerator[rate_i] = sample_rates_molerator[rate_i]*(currentEdges-1)/sample_rates_denominator[rate_i];
                sample_rates_denominator[rate_i] = currentEdges;
            }
        }
    }


    cout<<"type-1: "<<(int64_t)tri_num_type1<<endl;
    cout<<"type-2: "<<(int64_t)tri_num_type2<<endl;
    cout<<"type-3: "<<(int64_t)tri_num_type3<<endl;

    cout<<"Reservoir_size_now:"<<Reservoir_size_now<<" "<<sampleVertices<<endl;

    vector<uint64_t> type_num(3);
    type_num[0] = (int64_t)tri_num_type1;
    type_num[1] = (int64_t)tri_num_type2;
    type_num[2] = (int64_t)tri_num_type3;

    return type_num;
}



void Graph::init(){
    for(int i = 0;i<n;i++) sample_vertices[i].clear();
    sample_hyperedges_fixed.clear();
    sample_hyperedges_fixed.resize(e);
}

vector<uint64_t> Graph::tc_tri_stream_local_space_fixed_muti_Reservoir(){
    double tri_num_type1 = 0;
    double tri_num_type2 = 0;
    double tri_num_type3 = 0;
    // uint32_t currentEdges = 0;
    // uint32_t currentVertices = 0;
    // uint32_t sampleVertices = 0;
    uint32_t Reservoir_size_2 = Reservoir_size;

    // double Reservoir_size_now = 0;

    srand(static_cast<unsigned int>(time(0)));
    std::random_device rd;
    std::mt19937 gen(rd());

    // uint32_t currentVertices = 0;

    int RS_sample_edge_l_i = 0;

    std::uniform_real_distribution<> dis(0.0, 1.0);
    std::uniform_int_distribution<> dis_int(0, Reservoir_size_2);
    double tri_num_type1_, tri_num_type2_, tri_num_type3_;

    // int judge_type1 = 0;
    // double update_factor = 1;

    // std::cout<<"Reservoir_size:"<<Reservoir_size<<std::endl;
    vector<uint32_t> edge_nei(e);
    uint32_t edge_nei_i = 0;
    vector<int> edge_nei_exist(e,-1);
    vector<int> edge_nei_dup(e,-1);
    vector<pairwise_edge> sample_all_vertices;
    sample_all_vertices.reserve(Reservoir_size_2);
    vector<double> sample_rates(e, 1.0);
    // bool r_full = false;
    int max_Reservoir_size = 10;

    vector<uint32_t> reservoir_ownership(e);
    uint32_t Reservoir_num = 1;
    vector<uint32_t> Reservoir_size_muti(max_Reservoir_size);
    Reservoir_size_muti[0] = Reservoir_size_2;
    vector<double> Reservoir_size_now_muti(max_Reservoir_size+1);
    vector<int> r_full_muti(max_Reservoir_size, 0);
    vector<uint32_t> sample_hyperedges_fixed_muti_start(max_Reservoir_size+1);
    sample_hyperedges_fixed_muti_start[0] = 0;
    vector<double> update_factor_muti(max_Reservoir_size);
    uint32_t sampleVertices_all = 0;
    vector<uint32_t> sampleVertices_muti(max_Reservoir_size);
    vector<uint32_t> currentVertices_muti(max_Reservoir_size);
    sampleVertices_muti[0] = 0;
    currentVertices_muti[0] = 0;
    vector<uint32_t> currentEdges_muti(max_Reservoir_size,0);
    uint32_t Reservoir_size_muti_old = 0;
    uint32_t accumulated_weight = 0;
    uint32_t current_Reservoir_id;
    int common_num;

    double update_factor = 1;

    double muti_rate = 0.95;

    // if(Reservoir_size_2 == 1024) muti_rate = 0.85;

    cout<<"muti_rate:"<<(1-(double)(1.6*max_Reservoir_size*m/e)/(double)Reservoir_size_2)<<" add rate:"<<1.4*m/e<<endl;
    

    for(int i = 0;i<e;i++){
        if(all_hyperedges[i].size() < 2) continue;
        // cout<< i<<endl;
        if((double)sampleVertices_all/(double)Reservoir_size_2 < muti_rate && r_full_muti[Reservoir_num-1] == 1 && Reservoir_num < max_Reservoir_size){
            // cout<<sampleVertices_all<<" "<<Reservoir_size_2<<endl;
            Reservoir_num++;
            sampleVertices_muti[Reservoir_num-1] = 0;
            currentEdges_muti[Reservoir_num - 1] = 0;
            currentVertices_muti[Reservoir_num - 1] = 0;

            // cout<<"Reservoir_size_now:"<<Reservoir_size_now_muti[Reservoir_num - 2]<<" "<<sampleVertices_all<<endl;

            Reservoir_size_muti_old = 0;
            
            for(int Reservoir_i = 0; Reservoir_i<Reservoir_num-1; Reservoir_i++){
                Reservoir_size_muti[Reservoir_i] = sampleVertices_muti[Reservoir_i]+10;
                Reservoir_size_muti_old+=Reservoir_size_muti[Reservoir_i];
            } 
            Reservoir_size_muti[Reservoir_num-1] = Reservoir_size_2 - Reservoir_size_muti_old;
            Reservoir_size_now_muti[Reservoir_num - 1] = 0;
            sample_hyperedges_fixed_muti_start[Reservoir_num - 1] = sample_hyperedges_fixed_muti_start[Reservoir_num - 2] + Reservoir_size_now_muti[Reservoir_num - 2];
            // cout<<Reservoir_size_muti[Reservoir_num-1]<<" "<<Reservoir_size_muti_old<<" "<<Reservoir_size_2<<endl;
        }

        // if(currentVertices_muti[Reservoir_num-1] + all_hyperedges[i].size() <= Reservoir_size_muti[Reservoir_num-1]) current_Reservoir_id = Reservoir_num-1;
        if(currentEdges_muti[Reservoir_num - 1] == 0 || (Reservoir_num > 1 && ((double)Reservoir_size_now_muti[Reservoir_num-1]/(double)(currentEdges_muti[Reservoir_num-1]) > (double)Reservoir_size_now_muti[Reservoir_num-2]/(double)(currentEdges_muti[Reservoir_num-2])))) current_Reservoir_id = Reservoir_num-1;
        else{

            int rand_val = dis_int(gen);
            accumulated_weight = 0;
            for (size_t Reservoir_i = 0; Reservoir_i < 10; ++Reservoir_i) {
                accumulated_weight += Reservoir_size_muti[Reservoir_i];
                if (rand_val <= accumulated_weight) {
                    current_Reservoir_id = Reservoir_i;
                    break;
                }
            }
        }

        uint32_t& currentEdges = currentEdges_muti[current_Reservoir_id];
        uint32_t& Reservoir_size_ = Reservoir_size_muti[current_Reservoir_id];
        double& Reservoir_size_now = Reservoir_size_now_muti[current_Reservoir_id];
        uint32_t& sampleVertices = sampleVertices_muti[current_Reservoir_id];
        uint32_t& currentVertices = currentVertices_muti[current_Reservoir_id];
        int& r_full = r_full_muti[current_Reservoir_id];

        currentEdges++;
        currentVertices+=all_hyperedges[i].size();
        if(all_hyperedges[i].size() > 2) tri_num_type1 += (all_hyperedges[i].size()*(all_hyperedges[i].size()-1)*(all_hyperedges[i].size()-2))/6;
        for (uint32_t update_factor_i = 0; update_factor_i < Reservoir_num; update_factor_i++){
            update_factor_muti[update_factor_i] = 1.0;
            if(r_full_muti[update_factor_i] == 1) update_factor_muti[update_factor_i] = ((double)Reservoir_size_now_muti[update_factor_i]/(double)(currentEdges_muti[update_factor_i]));
        }

        edge_nei_i = 0;

        for(uint32_t v = 0;v<all_hyperedges[i].size();v++){
            for(uint32_t v2 = 0; v2 < sample_vertices[all_hyperedges[i][v]].size(); v2++){ 
                if(edge_nei_exist[sample_vertices[all_hyperedges[i][v]][v2]] < i){
                    edge_nei[edge_nei_i++] = sample_vertices[all_hyperedges[i][v]][v2];
                    edge_nei_exist[sample_vertices[all_hyperedges[i][v]][v2]] = i;
                } 
            }
            
        }

        // for(uint32_t j = 0;j<edge_nei_i;j++){
        //     intersect_two_sets_fixed(all_hyperedges[i], sample_hyperedges_fixed[edge_nei[j]], tri_num_type2_, update_factor_muti[reservoir_ownership[edge_nei[j]]],common_num);
        //     tri_num_type2+=tri_num_type2_;
        //     if(all_hyperedges[i].size() - common_num == 0 || sample_hyperedges_fixed[edge_nei[j]].size() - common_num == 0){
                
        //         continue;

        //     }
        //     for(uint32_t k = j+1;k<edge_nei_i;k++){
        //         intersect_three_sets_fixed(all_hyperedges[i], sample_hyperedges_fixed[edge_nei[j]], sample_hyperedges_fixed[edge_nei[k]], tri_num_type3_, update_factor_muti[reservoir_ownership[edge_nei[j]]], update_factor_muti[reservoir_ownership[edge_nei[k]]]);
        //         tri_num_type3+=tri_num_type3_;
        //     }
        // }

        sample_common_vertices.clear();

        sample_common_vertices.resize(edge_nei_i);

        for(uint32_t j = 0;j<edge_nei_i;j++){
            // time_2++;
            intersect_two_sets_fixed2(all_hyperedges[i], sample_hyperedges_fixed[edge_nei[j]], tri_num_type2_, update_factor_muti[reservoir_ownership[edge_nei[j]]], common_num, sample_common_vertices[j]);
            tri_num_type2+=tri_num_type2_;

        }

        for(uint32_t j = 0;j<edge_nei_i;j++){

            if(all_hyperedges[i].size() - sample_common_vertices[j].size() == 0 || sample_hyperedges_fixed[edge_nei[j]].size() - sample_common_vertices[j].size() == 0) continue;

            for(uint32_t k = j+1;k<edge_nei_i;k++){
                if(all_hyperedges[i].size() - sample_common_vertices[k].size() == 0 || sample_hyperedges_fixed[edge_nei[k]].size() - sample_common_vertices[k].size() == 0) continue;
                // time_3++;
                if(reservoir_ownership[edge_nei[j]] == reservoir_ownership[edge_nei[k]]){
                    update_factor = 1.0;
                    if(r_full_muti[reservoir_ownership[edge_nei[k]]] == 1) update_factor = ((double)Reservoir_size_now_muti[reservoir_ownership[edge_nei[k]]]*((double)Reservoir_size_now_muti[reservoir_ownership[edge_nei[k]]]-1)/(double)(currentEdges_muti[reservoir_ownership[edge_nei[k]]])/((double)(currentEdges_muti[reservoir_ownership[edge_nei[k]]])-1));
                }else {
                    update_factor = update_factor_muti[reservoir_ownership[edge_nei[k]]]*update_factor_muti[reservoir_ownership[edge_nei[j]]];
                }
                intersect_three_sets_fixed2(sample_common_vertices[j], sample_common_vertices[k], sample_hyperedges_fixed[edge_nei[j]], sample_hyperedges_fixed[edge_nei[k]], tri_num_type3_, update_factor);
                tri_num_type3+=tri_num_type3_;
                // if(tri_num_type3_ == 0) time_3_0++;
                // time_3_type[time_3_type_]++;
            }
        }

        if (currentVertices <= Reservoir_size_) {

            Reservoir_size_now++;
            sampleVertices+=all_hyperedges[i].size();
            sampleVertices_all+=all_hyperedges[i].size();
            
            sample_hyperedges_fixed[sample_hyperedges_fixed_muti_start[current_Reservoir_id] + (uint32_t)Reservoir_size_now - 1] = all_hyperedges[i];
            for (uint32_t v = 0; v < all_hyperedges[i].size(); v++){
                sample_vertices[all_hyperedges[i][v]].push_back(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + (uint32_t)Reservoir_size_now - 1);
            }

            reservoir_ownership[sample_hyperedges_fixed_muti_start[current_Reservoir_id] + (uint32_t)Reservoir_size_now - 1] = current_Reservoir_id;

        } else if (dis(gen) < (double)Reservoir_size_now / (double)currentEdges) {

            if(r_full == 0) {
                r_full = 1;
                cout<<"r_full:"<<Reservoir_size_now<<endl;
            }

            double del_num = 1.0;

            uint32_t del_edge = sample_hyperedges_fixed_muti_start[current_Reservoir_id] + rand() % (uint32_t)Reservoir_size_now;
            sampleVertices-=sample_hyperedges_fixed[del_edge].size();
            sampleVertices_all-=sample_hyperedges_fixed[del_edge].size();
    
            for (uint32_t v = 0; v < sample_hyperedges_fixed[del_edge].size(); v++) {
                uint32_t vertex = sample_hyperedges_fixed[del_edge][v];
                auto& vertex_edges = sample_vertices[vertex];
                auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
                if (it != vertex_edges.end()) {
                    std::swap(*it, vertex_edges.back());
                    vertex_edges.pop_back();
                }
                else cout<<"error1"<<endl;
            }

            if(del_edge != (uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)){
                
                reservoir_ownership[del_edge] = reservoir_ownership[(uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)];
                sample_hyperedges_fixed[del_edge] = sample_hyperedges_fixed[(uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)];
                for (uint32_t v = 0; v < sample_hyperedges_fixed[(uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)].size(); v++) {
                    uint32_t vertex = sample_hyperedges_fixed[(uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)][v];
                    auto& vertex_edges = sample_vertices[vertex];
                    auto it = std::find(vertex_edges.begin(), vertex_edges.end(), (uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1));
                    if (it != vertex_edges.end()) {
                        std::swap(*it, vertex_edges.back());
                        vertex_edges.pop_back();
                    }
                    else cout<<"error2"<<endl;
                    sample_vertices[vertex].push_back(del_edge);

                }

            }
            Reservoir_size_now--;

            sample_hyperedges_fixed[sample_hyperedges_fixed_muti_start[current_Reservoir_id] + (uint32_t)Reservoir_size_now] = all_hyperedges[i];
            for (uint32_t v = 0; v < all_hyperedges[i].size(); v++)
                sample_vertices[all_hyperedges[i][v]].push_back(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + (uint32_t)Reservoir_size_now);
            Reservoir_size_now++;
            sampleVertices+=all_hyperedges[i].size();
            sampleVertices_all+=all_hyperedges[i].size();
            reservoir_ownership[sample_hyperedges_fixed_muti_start[current_Reservoir_id] + (uint32_t)Reservoir_size_now - 1] = current_Reservoir_id;

            while (sampleVertices > Reservoir_size_) {
                
                uint32_t del_edge = sample_hyperedges_fixed_muti_start[current_Reservoir_id] + rand() % (uint32_t)Reservoir_size_now;

                
                sampleVertices-=sample_hyperedges_fixed[del_edge].size();
                sampleVertices_all-=sample_hyperedges_fixed[del_edge].size();
                del_num++;

                for (uint32_t v = 0; v < sample_hyperedges_fixed[del_edge].size(); v++) {
                    uint32_t vertex = sample_hyperedges_fixed[del_edge][v];
                    auto& vertex_edges = sample_vertices[vertex];
                    auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
                    if (it != vertex_edges.end()) {
                        std::swap(*it, vertex_edges.back());
                        vertex_edges.pop_back();
                    }
                    else cout<<"error3"<<endl;
                }
                if(del_edge != (uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)){
                    
                    reservoir_ownership[del_edge] = reservoir_ownership[(uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)];
                    sample_hyperedges_fixed[del_edge] = sample_hyperedges_fixed[(uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)];
                    for (uint32_t v = 0; v < sample_hyperedges_fixed[(uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)].size(); v++) {
                        uint32_t vertex = sample_hyperedges_fixed[(uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1)][v];
                        auto& vertex_edges = sample_vertices[vertex];
                        auto it = std::find(vertex_edges.begin(), vertex_edges.end(), (uint32_t)(sample_hyperedges_fixed_muti_start[current_Reservoir_id] + Reservoir_size_now-1));
                        if (it != vertex_edges.end()) {
                            std::swap(*it, vertex_edges.back());
                            vertex_edges.pop_back();
                        }
                        else cout<<"error4"<<endl;
                        sample_vertices[vertex].push_back(del_edge);
                    }
                }

                Reservoir_size_now--;
            
            }
        }
    }

    cout<<"type-1: "<<(int64_t)tri_num_type1<<endl;
    cout<<"type-2: "<<(int64_t)tri_num_type2<<endl;
    cout<<"type-3: "<<(int64_t)tri_num_type3<<endl;

    uint32_t all_Reservoir_size_now = 0;
    for(int Reservoir_i = 0; Reservoir_i<Reservoir_num; Reservoir_i++){
        all_Reservoir_size_now+=(uint32_t)Reservoir_size_now_muti[Reservoir_i];
        cout<<"Reservoir_size_now-"<<Reservoir_i<<":"<<Reservoir_size_now_muti[Reservoir_i]<<endl;
    } 

    cout<<"Reservoir_size_now:"<<all_Reservoir_size_now<<" "<<sampleVertices_all<<endl;

    vector<uint64_t> type_num(5);
    type_num[0] = (int64_t)tri_num_type1;
    type_num[1] = (int64_t)tri_num_type2;
    type_num[2] = (int64_t)tri_num_type3;
    type_num[3] = (int64_t)all_Reservoir_size_now;
    type_num[4] = (int64_t)sampleVertices_all;

    return type_num;
}

vector<uint64_t> Graph::tc_tri_stream_global_space(){
    double tri_num_type1 = 0;
    double tri_num_type2 = 0;
    double tri_num_type3 = 0;
    uint32_t currentEdges = 0;

    srand(static_cast<unsigned int>(time(0)));
    std::random_device rd;
    std::mt19937 gen(rd());

    int RS_sample_edge_l_i = 0;

    std::uniform_real_distribution<> dis(0.0, 1.0);
    double tri_num_type1_, tri_num_type2_, tri_num_type3_;

    int judge_type1 = 0;
    double update_factor = 1;

    std::cout<<"Reservoir_size:"<<Reservoir_size<<std::endl;
    vector<uint32_t> edge_nei(e);
    uint32_t edge_nei_i = 0;
    vector<int> edge_nei_exist(e,-1);
    

    for(int i = 0;i<e;i++){

        
        currentEdges++;
        
        if (currentEdges <= Reservoir_size) {
            sample_hyperedges[currentEdges - 1] = all_hyperedges[i];
            for (uint32_t v = 0; v < all_hyperedges[i].size(); v++)
                sample_vertices[all_hyperedges[i][v]].push_back(currentEdges - 1);
        } 
        else if (dis(gen) < (double)Reservoir_size / (double)currentEdges) {
            uint32_t del_edge = rand() % Reservoir_size;
    
            for (uint32_t v = 0; v < sample_hyperedges[del_edge].size(); v++) {
                uint32_t vertex = sample_hyperedges[del_edge][v];
                auto& vertex_edges = sample_vertices[vertex];
                auto it = std::find(vertex_edges.begin(), vertex_edges.end(), del_edge);
                if (it != vertex_edges.end()) {
                    std::swap(*it, vertex_edges.back());
                    vertex_edges.pop_back();
                }
            }
            sample_hyperedges[del_edge] = all_hyperedges[i];
            for (uint32_t v = 0; v < all_hyperedges[i].size(); v++)
                sample_vertices[all_hyperedges[i][v]].push_back(del_edge);
        }
    }

    update_factor = ((double)Reservoir_size/(double)(currentEdges));

    for(int i = 0; i < Reservoir_size; i++){
        if(sample_hyperedges[i].size() > 2) tri_num_type1 += (sample_hyperedges[i].size()*(sample_hyperedges[i].size()-1)*(sample_hyperedges[i].size()-2))/6/update_factor;

        edge_nei_i = 0;

        for(uint32_t v = 0;v<sample_hyperedges[i].size();v++){
            for(uint32_t v2 = 0; v2 < sample_vertices[sample_hyperedges[i][v]].size(); v2++){ 
                if(edge_nei_exist[sample_vertices[sample_hyperedges[i][v]][v2]] < i){
                    edge_nei[edge_nei_i++] = sample_vertices[sample_hyperedges[i][v]][v2];
                    edge_nei_exist[sample_vertices[sample_hyperedges[i][v]][v2]] = i;
                } 
            }
            
        }


        for(uint32_t j = 0;j<edge_nei_i;j++){

            if(edge_nei[j] > i){
                intersect_two_sets3(sample_hyperedges[i], sample_hyperedges[edge_nei[j]], tri_num_type2_, update_factor);
                tri_num_type2+=tri_num_type2_/update_factor;

                for(uint32_t k = j+1;k<edge_nei_i;k++){
                    if(edge_nei[k] > i){
                        intersect_three_sets3(sample_hyperedges[i], sample_hyperedges[edge_nei[j]], sample_hyperedges[edge_nei[k]], tri_num_type3_, update_factor);
                        tri_num_type3+=tri_num_type3_/update_factor;
                    }
                }

            }
            
        }
    }


    cout<<"type-1: "<<(int64_t)tri_num_type1<<endl;
    cout<<"type-2: "<<(int64_t)tri_num_type2<<endl;
    cout<<"type-3: "<<(int64_t)tri_num_type3<<endl;

    vector<uint64_t> type_num(3);
    type_num[0] = (int64_t)tri_num_type1;
    type_num[1] = (int64_t)tri_num_type2;
    type_num[2] = (int64_t)tri_num_type3;

    return type_num;
}
