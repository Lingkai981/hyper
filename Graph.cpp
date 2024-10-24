//
//  Graph.cpp
//  hypergraph_tri_count
//
//  Created by LingkaiMeng on 2024/3/21.
//

#include "Graph.hpp"
#include <cstdint>
#include <cstring>

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
    if(pairwise_adgvex == NULL) pairwise_adgvex = new vector<pairwise_edge>[n];
    if(pairwise_adgvex_start == NULL) pairwise_adgvex_start = new vector<uint32_t>[n];
    if(pairwise_adgvex2 == NULL) pairwise_adgvex2 = new vector<pairwise_edge>[n];
    if(pairwise_adgvex_start2 == NULL) pairwise_adgvex_start2 = new vector<uint32_t>[n];

    if(pairwise_adgvex_minHash == NULL) pairwise_adgvex_minHash = new vector<pairwise_edge>[n];
    if(pairwise_adgvex_start_minHash == NULL) pairwise_adgvex_start_minHash = new vector<uint32_t>[n];
    if(pairwise_adgvex_nei_num_minHash == NULL) pairwise_adgvex_nei_num_minHash = new vector<uint32_t>[n];
    hashMaps.resize(n);
    pairwise_adgvex_nei_num_i_minHash = new uint32_t[n];
    if(out_degree == NULL) out_degree = new uint32_t[n];

    common_vertices.resize(n);
    
    
    
    // if(pairwise_edge_adgvex == NULL) pairwise_edge_adgvex = new vector<pairwise_edge>[e];
    // if(pairwise_edge_adgvex_start == NULL) pairwise_edge_adgvex_start = new vector<uint32_t>[e];
    
    // // if(hyperedges_to_vectices == NULL) hyperedges_to_vectices = new pairwise_edge[m*200];
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
            vertices[hyperedges[hyperedges_i]].push_back(i);
            vertex_len[hyperedges[hyperedges_i]]++;
            hyperedges_i++;
        }
    }
    infile.close();
    
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
        pairwise_adgvex_start[i].resize(len+2);

        pairwise_adgvex2[i].reserve(len);
        pairwise_adgvex_start2[i].resize(len+2);

        pairwise_adgvex_minHash[i].resize(len);
        pairwise_adgvex_start_minHash[i].resize(len+2);
        pairwise_adgvex_nei_num_minHash[i].resize(len);
        hashMaps[i] = new HashMap(len);
        
    }
    memset(pairwise_adgvex_nei_num_i_minHash, 0, sizeof(uint32_t)*n);
    
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


void Graph::triangle_enum(){

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
    
    vector<uint64_t> type_num(5,0);
    uint64_t type_et = 0;
    uint32_t type = 0, tri_num = 0, common_num = 0;
    
    for(uint32_t i = 0; i<n;i++){
//        cout<<i<<endl;
//         cout<<out_edge_start[i+1] - out_edge_start[i] <<endl;
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

                    judge_tri_type(i, out_edges[j].pos, out_edges[j].vertex, out_edges[k].pos, i, visit_out_pos[out_edges[k].vertex], type, tri_num, common_num);
                    // judge_tri_type_minHash(i, out_edges_minHash[j].pos, out_edges_minHash[j].vertex, out_edges_minHash[k].pos, i, visit_out_pos[out_edges_minHash[k].vertex], type, tri_num, common_num);
                    
                    all_tri_num+=tri_num;
                    type_num[type]+=tri_num;
                    
                    if(type == 3) type_et+=tri_num/common_num;
                    else if(type == 4) type_et+=tri_num;
                }
            }
        }
    }
    
    delete[] visit_out;
    visit_out = NULL;
    delete[] visit_out_pos;
    visit_out_pos = NULL;
    
    for(int i = 0;i<5;i++){
        cout<<"type-"<<i<<": "<<type_num[i]<<endl;
    }

    // cout<<type_et<<endl;

    // type_et = 0;

    // for(uint32_t i = 0;i<n;i++){
    //     if(vertex_len[i] > 2) type_et+=vertex_len[i]*(vertex_len[i]-1)*(vertex_len[i]-2)/6;
    // }

    // cout<<type_et<<endl;
    // cout<<all_tri_num<<endl;

}

void Graph::triangle_enum2(){

    clock_t startTime,endTime;

    startTime = clock();//计时开始
    to_pairwise_minHash2();
    endTime = clock();//计时结束
    cout << "The to_pairwise_minHash time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    
    int *visit_out = new int[n];
    memset(visit_out, 0, sizeof(int)*n);
    int *visit_out_pos = new int[n];
    memset(visit_out_pos, 0, sizeof(int)*n);
    int *visit_out_nei_num = new int[n];
    memset(visit_out_nei_num, 0, sizeof(int)*n);
    
    uint64_t all_tri_num = 0;
    
    vector<uint64_t> type_num(5,0);
    uint64_t type_et = 0;
    uint32_t type = 0, tri_num = 0, common_num = 0;
    
    for(uint32_t i = 0; i<n;i++){
//        cout<<i<<endl;
//         cout<<out_edge_start[i+1] - out_edge_start[i] <<endl;
        for(uint32_t j = out_edge_start[i]; j<out_edge_start[i+1]; j++){

            if(out_edges[j].vertex == n) continue;
            
            visit_out[out_edges[j].vertex] = i+1;
            visit_out_pos[out_edges[j].vertex] = out_edges[j].pos;
            visit_out_nei_num[out_edges[j].vertex] = out_edges[j].neighbor_num;
        }


        for(uint32_t j = out_edge_start[i]; j < out_edge_start[i+1]; j++){
            if(out_edges[j].vertex == n) continue;
            for(uint32_t k = out_edge_start[out_edges[j].vertex]; k < out_edge_start[out_edges[j].vertex+1]; k++){
                if(out_edges[k].vertex == n) continue;
                if(visit_out[out_edges[k].vertex] == i+1){

                    judge_tri_type_minHash(i, out_edges[j].pos,out_edges[j].neighbor_num, out_edges[j].vertex, out_edges[k].pos, out_edges[k].neighbor_num, i, visit_out_pos[out_edges[k].vertex], visit_out_nei_num[out_edges[k].vertex], type, tri_num, common_num);
                    
                    all_tri_num+=tri_num;
                    type_num[type]+=tri_num;
                    
                    if(type == 3) type_et+=tri_num/common_num;
                    else if(type == 4) type_et+=tri_num;


                }
            }
        }
    }
    
    delete[] visit_out;
    visit_out = NULL;
    delete[] visit_out_pos;
    visit_out_pos = NULL;
    
    
    
    for(int i = 0;i<5;i++){
        cout<<"type-"<<i<<": "<<type_num[i]<<endl;
    }

    cout<<type_et<<endl;

    for(uint32_t i = 0;i<n;i++){
        if(vertex_len[i] > 2) type_et+=vertex_len[i]*(vertex_len[i]-1)*(vertex_len[i]-2)/6;
    }

    cout<<type_et<<endl;
    cout<<all_tri_num<<endl;

}
void Graph::triangle_enum3(){

    clock_t startTime,endTime;

    startTime = clock();//计时开始
    to_pairwise_minHash3();
    endTime = clock();//计时结束
    cout << "The to_pairwise_minHash time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    
    int *visit_out = new int[n];
    memset(visit_out, 0, sizeof(int)*n);
    int *visit_out_pos = new int[n];
    memset(visit_out_pos, 0, sizeof(int)*n);
    int *visit_out_nei_num = new int[n];
    memset(visit_out_nei_num, 0, sizeof(int)*n);
    
    uint64_t all_tri_num = 0, all_tri_num_ = 0;
    
    vector<uint64_t> type_num(5,0), type_num_(5,0);
    uint64_t type_et = 0, type_et_ = 0;
    uint32_t type = 0, tri_num = 0, common_num = 0;
    float common_ = 0;
    float del = 0;
    
    for(uint32_t i = 0; i<n;i++){
//        cout<<i<<endl;
//         cout<<out_edge_start[i+1] - out_edge_start[i] <<endl;
        for(uint32_t j = out_edge_start_minHash[i]; j<out_edge_start_minHash[i+1]; j++){

            if(out_edges_minHash[j].vertex == n) continue;
            
            visit_out[out_edges_minHash[j].vertex] = i+1;
            visit_out_pos[out_edges_minHash[j].vertex] = out_edges_minHash[j].pos;
            visit_out_nei_num[out_edges_minHash[j].vertex] = out_edges_minHash[j].neighbor_num;
        }


        for(uint32_t j = out_edge_start_minHash[i]; j < out_edge_start_minHash[i+1]; j++){
            if(out_edges_minHash[j].vertex == n){
                del++;
                continue;
            }
            for(uint32_t k = out_edge_start_minHash[out_edges_minHash[j].vertex]; k < out_edge_start_minHash[out_edges_minHash[j].vertex+1]; k++){
                if(out_edges_minHash[k].vertex == n){
                    del++;
                    continue;

                }
                if(visit_out[out_edges_minHash[k].vertex] == i+1){
                    common_++;

                    // multiple = min(min(out_degree[i]/(out_edge_start_minHash[i+1] - out_edge_start_minHash[i]), ))
                    // if(multiple>1)
                    // cout<<multiple<<endl;

                    // judge_tri_type(i, out_edges[j].pos, out_edges[j].vertex, out_edges[k].pos, i, visit_out_pos[out_edges[k].vertex], type, tri_num, common_num);
                    judge_tri_type_minHash(i, out_edges_minHash[j].pos,out_edges_minHash[j].neighbor_num, out_edges_minHash[j].vertex, out_edges_minHash[k].pos, out_edges_minHash[k].neighbor_num, i, visit_out_pos[out_edges_minHash[k].vertex], visit_out_nei_num[out_edges_minHash[k].vertex], type, tri_num, common_num);

                    
                    
                    all_tri_num_+=tri_num;
                    type_num_[type]+=tri_num;
                    
                    if(type == 3) type_et_+=tri_num/common_num;
                    else if(type == 4) type_et_+=tri_num;


                }
            }

            // int multiple = (int)((double)(out_degree[i] + out_degree[out_edges_minHash[j].vertex]- common_)/(double)(out_edge_start_minHash[i+1] - out_edge_start_minHash[i] + out_edge_start_minHash[out_edges_minHash[j].vertex+1] - out_edge_start_minHash[out_edges_minHash[j].vertex] - common_ ));

            float similarity = common_/(float)(out_edge_start_minHash[i+1] - out_edge_start_minHash[i] + out_edge_start_minHash[out_edges_minHash[j].vertex+1] - out_edge_start_minHash[out_edges_minHash[j].vertex] - del - common_);

            float multiple = ((float)(((float)(out_degree[i] + out_degree[out_edges_minHash[j].vertex]))*similarity)/(similarity+1))/common_;

            int multiple_ = max((int)multiple, 1);

            all_tri_num+=all_tri_num_*multiple_;
            all_tri_num_ = 0;
            for(int ii = 0;ii<5;ii++){
                type_num[ii]+=type_num_[ii]*multiple_;
                type_num_[ii] = 0;
            }
            type_et+=type_et_*multiple_;
            type_et_ = 0;
            common_ = 0;
            del = 0;

                    


        }
    }
    
    delete[] visit_out;
    visit_out = NULL;
    delete[] visit_out_pos;
    visit_out_pos = NULL;
    
    for(int i = 0;i<5;i++){
        cout<<type_num[i]<<endl;
    }

    cout<<type_et<<endl;

    for(uint32_t i = 0;i<n;i++){
        if(vertex_len[i] > 2) type_et+=vertex_len[i]*(vertex_len[i]-1)*(vertex_len[i]-2)/6;
    }

    cout<<type_et<<endl;
    cout<<all_tri_num<<endl;
}


void Graph::triangle_enum4(){

    clock_t startTime,endTime;

    startTime = clock();//计时开始
    to_pairwise_minHash4();
    endTime = clock();//计时结束
    cout << "The to_pairwise_minHash time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    
    int *visit_out = new int[n];
    memset(visit_out, 0, sizeof(int)*n);
    int *visit_out_pos = new int[n];
    memset(visit_out_pos, 0, sizeof(int)*n);
    
    uint64_t all_tri_num = 0, all_tri_num_ = 0;
    
    vector<uint64_t> type_num(5,0), type_num_(5,0);
    uint64_t type_et = 0, type_et_ = 0;
    uint32_t type = 0, tri_num = 0, common_num = 0;
    float common_ = 0;
    float del = 0;
    
    for(uint32_t i = 0; i<n;i++){
//        cout<<i<<endl;
//         cout<<out_edge_start[i+1] - out_edge_start[i] <<endl;
        for(uint32_t j = out_edge_start_minHash[i]; j<out_edge_start_minHash[i+1]; j++){

            if(out_edges_minHash[j].vertex == n) continue;
            
            visit_out[out_edges_minHash[j].vertex] = i+1;
            visit_out_pos[out_edges_minHash[j].vertex] = out_edges_minHash[j].pos;
            
        }


        for(uint32_t j = out_edge_start_minHash[i]; j < out_edge_start_minHash[i+1]; j++){
            if(out_edges_minHash[j].vertex == n){
                del++;
                continue;
            }
            for(uint32_t k = out_edge_start_minHash[out_edges_minHash[j].vertex]; k < out_edge_start_minHash[out_edges_minHash[j].vertex+1]; k++){
                if(out_edges_minHash[k].vertex == n){
                    del++;
                    continue;

                }
                if(visit_out[out_edges_minHash[k].vertex] == i+1){
                    common_++;

                    // multiple = min(min(out_degree[i]/(out_edge_start_minHash[i+1] - out_edge_start_minHash[i]), ))
                    // if(multiple>1)
                    // cout<<multiple<<endl;

                    judge_tri_type_minHash2(i, out_edges_minHash[j].pos, out_edges_minHash[j].vertex, out_edges_minHash[k].pos, i, visit_out_pos[out_edges_minHash[k].vertex], type, tri_num, common_num);
                    // judge_tri_type_minHash(i, out_edges_minHash[j].pos,out_edges_minHash[j].neighbor_num, out_edges_minHash[j].vertex, out_edges_minHash[k].pos, out_edges_minHash[k].neighbor_num, i, visit_out_pos[out_edges_minHash[k].vertex], visit_out_nei_num[out_edges_minHash[k].vertex], type, tri_num, common_num);

                    
                    
                    all_tri_num_+=tri_num;
                    type_num_[type]+=tri_num;
                    
                    if(type == 3) type_et_+=tri_num/common_num;
                    else if(type == 4) type_et_+=tri_num;


                }
            }

            float similarity = common_/(float)(out_edge_start_minHash[i+1] - out_edge_start_minHash[i] + out_edge_start_minHash[out_edges_minHash[j].vertex+1] - out_edge_start_minHash[out_edges_minHash[j].vertex] - del - common_);

            float multiple = ((float)(((float)(out_degree[i] + out_degree[out_edges_minHash[j].vertex]))*similarity)/(similarity+1))/common_;
            

            int multiple_ = max((int)multiple, 1);

            all_tri_num+=all_tri_num_*multiple_;
            all_tri_num_ = 0;
            for(int ii = 0;ii<5;ii++){
                type_num[ii]+=type_num_[ii]*multiple_;
                type_num_[ii] = 0;
            }
            type_et+=type_et_*multiple_;
            type_et_ = 0;
            common_ = 0;
            del = 0;

        }

        
    }
    
    delete[] visit_out;
    visit_out = NULL;
    delete[] visit_out_pos;
    visit_out_pos = NULL;
    
    for(int i = 0;i<5;i++){
        cout<<type_num[i]<<endl;
    }

    cout<<type_et<<endl;

    for(uint32_t i = 0;i<n;i++){
        if(vertex_len[i] > 2) type_et+=vertex_len[i]*(vertex_len[i]-1)*(vertex_len[i]-2)/6;
    }

    cout<<type_et<<endl;
    cout<<all_tri_num<<endl;
}

void Graph::hyperedge_triangle_enum(){
    // uint64_t et_num = 0;

    // for(uint32_t i = 0;i<n;i++){
    //     if(vertex_len[i]<3) continue;
    //     cout<<i<<endl;
    //     for(uint32_t j = 0;j<vertex_len[i];j++){
    //         for(uint32_t k = j+ 1;k<vertex_len[i];k++){
    //             for(uint32_t l = k+1;l < vertex_len[i];l++){
    //                 et_num++;
    //             }
    //         }
    //     }
    // }

    // cout<<"et_num:"<<et_num<<endl;
    

    // return;



    clock_t startTime,endTime;

    startTime = clock();//计时开始
    to_hyperedge_based_pairwise();
    endTime = clock();//计时结束
    cout << "The to_hyperedge_based_pairwise time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return;
    
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

void Graph::triangle_count(){
    to_hyperedge_based_pairwise2();
    
    int common_j_k;
    int common_j_l;
    int common_k_l;
    int common_j_k_l;

    uint64_t type3 = 0;
    uint64_t type2 = 0;
    uint64_t type1 = 0;
    uint64_t type0 = 0;
    
    uint64_t type3_ = 0;
    uint64_t type2_ = 0;

    for(uint32_t i = 0;i<e;i++){
        //        cout<<i<<endl;
        if(hyperedge_len[i] < 3) continue;
        for(uint32_t j = hyperedges_to_vectices_start[i]; j<hyperedges_to_vectices_start[i+1];j++){
            if(intersection_start_len[j] >= hyperedge_len[i]) continue;
            type2_ = 0;
            for(uint32_t k = j+1; k < hyperedges_to_vectices_start[i+1]; k++){
                if(intersection_start_len[k] >= hyperedge_len[i]) continue;
                common_j_k = two_interaction_num(hyperedges_to_vectices + intersection_start[j], intersection_start_len[j], hyperedges_to_vectices + intersection_start[k], intersection_start_len[k]);
                if(common_j_k > 0 && common_j_k < intersection_start_len[j] && common_j_k < intersection_start_len[k]){
                    type3_ = 0;
                    for(uint32_t l = k+1; l < hyperedges_to_vectices_start[i+1]; l++){
                        if(intersection_start_len[l] >= hyperedge_len[i]) continue;
                        common_j_l = two_interaction_num(hyperedges_to_vectices + intersection_start[j], intersection_start_len[j], hyperedges_to_vectices + intersection_start[l], intersection_start_len[l]);
                        common_k_l = two_interaction_num(hyperedges_to_vectices + intersection_start[k], intersection_start_len[k], hyperedges_to_vectices + intersection_start[l], intersection_start_len[l]);
                        if(common_j_l > 0 && common_k_l > 0 && common_j_l < intersection_start_len[j] && common_j_l < intersection_start_len[l] && common_k_l < intersection_start_len[l] && common_k_l < intersection_start_len[k]){
                            common_j_k_l = three_interaction_num(hyperedges_to_vectices + intersection_start[k], intersection_start_len[k], hyperedges_to_vectices + intersection_start[l], intersection_start_len[l], hyperedges_to_vectices + intersection_start[j], intersection_start_len[j]);
                            type3_+=(common_j_k - common_j_k_l)*(common_j_l - common_j_k_l)*(common_k_l - common_j_k_l);
                            
                            
                        }
                    }
                    type3+=type3_;
                }
                //                type2_ += (intersection_start_len[k] - common_j_k) * common_j_k * (intersection_start_len[j] - common_j_k) - type3_;
                
                
            }
            //            type1+=
            
        }
        
    }
        
    cout<<"type3:"<<type3<<endl;
//    }
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

void Graph::to_pairwise_minHash(){

    clock_t startTime,endTime;

    startTime = clock();//计时开始
    // to_pairwise();
    

    srand((unsigned)time(NULL));
    uint64_t vertices_pairwise_edge_num = 0;
    // uint32_t *
    int pos = -1;
    for(uint32_t i = 0;i<e;i++){
        // cout<<i<<endl;
        for(uint32_t j = hyperedges_start[i]; j < hyperedges_start[i+1]; j++){
            // if(vertex_len[hyperedges[j]] == 1) continue;
            for(uint32_t k = j + 1; k < hyperedges_start[i+1]; k++){
                // if(vertex_len[hwyperedges[k]] == 1) continue;
                pairwise_adgvex[hyperedges[j]].push_back({hyperedges[k], i});
                pairwise_adgvex[hyperedges[k]].push_back({hyperedges[j], i});

                pos = hashMaps[hyperedges[j]]->find(hyperedges[k]);

                if(pos == -1){
                    hashMaps[hyperedges[j]]->insert(hyperedges[k], pairwise_adgvex_nei_num_i_minHash[hyperedges[j]]);
                    pairwise_adgvex_nei_num_minHash[hyperedges[j]][pairwise_adgvex_nei_num_i_minHash[hyperedges[j]]] = 1;
                    pairwise_adgvex_nei_num_i_minHash[hyperedges[j]]++;
                }else {
                    pairwise_adgvex_nei_num_minHash[hyperedges[j]][pos]++;
                }

                pos = hashMaps[hyperedges[k]]->find(hyperedges[j]);

                if(pos == -1){
                    
                    hashMaps[hyperedges[k]]->insert(hyperedges[j], pairwise_adgvex_nei_num_i_minHash[hyperedges[k]]);
                    pairwise_adgvex_nei_num_minHash[hyperedges[k]][pairwise_adgvex_nei_num_i_minHash[hyperedges[k]]] = 1;
                    pairwise_adgvex_nei_num_i_minHash[hyperedges[k]]++;
                }else {
                    pairwise_adgvex_nei_num_minHash[hyperedges[k]][pos]++;
                }
            }
        }
        vertices_pairwise_edge_num+= (hyperedges_start[i+1] - hyperedges_start[i])*(hyperedges_start[i+1] - hyperedges_start[i] - 1);
    }

    endTime = clock();//计时结束
    cout << "The to_pairwise_minHash part 1 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    startTime = clock();//计时开始
    
    uint32_t out_edges_num = 0;
    uint32_t *nei_pos = new uint32_t[n];
    // vector<uint32_t> nei_pos(n,0);
    for(uint32_t i = 0; i< n; i++){
        // cout<<i<<endl;
        if(pairwise_adgvex[i].size()<1) continue;

        pairwise_adgvex_start_minHash[i][0] = 0;
        for(int j = 0; j < pairwise_adgvex_nei_num_i_minHash[i]; j++){
            if(pairwise_adgvex_nei_num_minHash[i][j] > bucket) pairwise_adgvex_start_minHash[i][j+1] = pairwise_adgvex_start_minHash[i][j] + bucket;
            else pairwise_adgvex_start_minHash[i][j+1] = pairwise_adgvex_start_minHash[i][j] + pairwise_adgvex_nei_num_minHash[i][j];
        }

        pairwise_adgvex_minHash[i].resize(pairwise_adgvex_start_minHash[i][pairwise_adgvex_nei_num_i_minHash[i]], {n, e});
        memset(nei_pos, 0, sizeof(uint32_t)*pairwise_adgvex_nei_num_i_minHash[i]);
        // nei_pos.resize(n,0);
        // vector<uint32_t> nei_pos(n,0);
        // fill(nei_pos.begin(), nei_pos.end(), 0);

        for(uint32_t j = 0; j < pairwise_adgvex[i].size();j++){
            int pos = hashMaps[i]->find(pairwise_adgvex[i][j].vertex);
            if(pairwise_adgvex_nei_num_minHash[i][pos] > bucket){
                uint32_t bucket_i = rand()%bucket;
                if(pairwise_adgvex[i][j].hyperedge < pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][pos] + bucket_i].hyperedge){
                    pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][pos] + bucket_i] = pairwise_adgvex[i][j];
                }

            }else {
                pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][pos] + nei_pos[pos]++] = pairwise_adgvex[i][j];
            }
        }


        std::sort(pairwise_adgvex_minHash[i].begin(), pairwise_adgvex_minHash[i].end(), [](const pairwise_edge& a, const pairwise_edge& b) {
            if(a.vertex == b.vertex) return a.hyperedge < b.hyperedge;
            return a.vertex < b.vertex;
        });

        // cout<<pairwise_adgvex_minHash[i].size()<<endl;
        pairwise_adgvex_start_minHash[i][0] = 0;
        uint32_t pairwise_adgvex_start_i = 1;
        uint32_t last_vertex = pairwise_adgvex_minHash[i][0].vertex+1;
        for(uint32_t j = 0; j < pairwise_adgvex_minHash[i].size();j++){
            if(pairwise_adgvex_minHash[i][j].vertex == n){
                pairwise_adgvex_minHash[i][j].vertex = pairwise_adgvex_minHash[i][j-1].vertex;
                continue;
            }
            if(pairwise_adgvex_minHash[i][j].vertex != last_vertex){
                pairwise_adgvex_start_minHash[i][pairwise_adgvex_start_i++] = j;
                pairwise_adgvex_start_minHash[i][0]++;
                last_vertex = pairwise_adgvex_minHash[i][j].vertex;
            }
        }
        out_edges_num+=pairwise_adgvex_start_minHash[i][0];
        pairwise_adgvex_start_minHash[i][pairwise_adgvex_start_i] = pairwise_adgvex_minHash[i].size();
        
        
    }
    
    if(out_edge_start == NULL) out_edge_start = new uint32_t[n+1];
    if(out_edges == NULL) out_edges = new out_edge_vertex_pos[out_edges_num];
    
    uint32_t out_edges_i = 0;
    out_edge_start[0] = 0;

    endTime = clock();//计时结束
    cout << "The to_pairwise_minHash part 2 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    startTime = clock();//计时开始
    
    for(uint32_t i = 0;i<n;i++){
        out_edge_start[i+1] = out_edge_start[i];
    
        
        for(uint32_t j = 0; j<pairwise_adgvex_start_minHash[i][0]; j++){

            if(pairwise_adgvex_start_minHash[i][0] > pairwise_adgvex_start_minHash[pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex][0] || (pairwise_adgvex_start_minHash[i][0] == pairwise_adgvex_start_minHash[pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex][0] && i > pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex)){
                
                out_edges[out_edges_i].vertex = pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex;
                
                out_edges[out_edges_i++].pos = j+1;
                out_edge_start[i+1]++;
                
            }
        }
    }
    

    endTime = clock();//计时结束
    cout << "The to_pairwise_minHash part 3 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    
    out_edge_start[n] = out_edges_i;
    cout<<"vertices_pairwise_edge_num:"<<vertices_pairwise_edge_num<<endl;
}

void Graph::to_pairwise_minHash2(){
        uint64_t vertices_pairwise_edge_num = 0;
    for(uint32_t i = 0;i<e;i++){
        // cout<<i<<endl;
        for(uint32_t j = hyperedges_start[i]; j < hyperedges_start[i+1]; j++){
            // if(vertex_len[hyperedges[j]] == 1) continue;
            for(uint32_t k = j + 1; k < hyperedges_start[i+1]; k++){
                // if(vertex_len[hyperedges[k]] == 1) continue;
                pairwise_adgvex2[hyperedges[j]].push_back({hyperedges[k], i});
                pairwise_adgvex2[hyperedges[k]].push_back({hyperedges[j], i});
                
                
            }
        }
        vertices_pairwise_edge_num+= (hyperedges_start[i+1] - hyperedges_start[i])*(hyperedges_start[i+1] - hyperedges_start[i] - 1);
    }
    
    uint32_t out_edges_num = 0;
    
    for(uint32_t i = 0; i< n; i++){
        // cout<<i<<endl;
        if(pairwise_adgvex2[i].size()<1) continue;
        std::sort(pairwise_adgvex2[i].begin(), pairwise_adgvex2[i].end(), [](const pairwise_edge& a, const pairwise_edge& b) {
            if(a.vertex == b.vertex) return a.hyperedge < b.hyperedge;
            return a.vertex < b.vertex;
        });
        

        pairwise_adgvex_start2[i][0] = 0;
        uint32_t pairwise_adgvex_start_i = 1;
        uint32_t last_vertex = pairwise_adgvex2[i][0].vertex+1;
        for(uint32_t j = 0; j < pairwise_adgvex2[i].size();j++){
            if(pairwise_adgvex2[i][j].vertex != last_vertex){
                pairwise_adgvex_start2[i][pairwise_adgvex_start_i++] = j;
                pairwise_adgvex_start2[i][0]++;
                last_vertex = pairwise_adgvex2[i][j].vertex;
            }
        }
        out_edges_num+=pairwise_adgvex_start2[i][0];
        pairwise_adgvex_start2[i][pairwise_adgvex_start_i] = pairwise_adgvex2[i].size();

        uint32_t pairwise_adgvex_min_i = 0;
        pairwise_adgvex_start_minHash[i][0] = pairwise_adgvex_start2[i][0];
        pairwise_adgvex_start_minHash[i][1] = 0;
        for(uint32_t j = 0; j<pairwise_adgvex_start2[i][0]; j++){
            if(pairwise_adgvex_start2[i][j+2] - pairwise_adgvex_start2[i][j+1] <= bucket){
                pairwise_adgvex_start_minHash[i][j+2] = pairwise_adgvex_start_minHash[i][j+1] + pairwise_adgvex_start2[i][j+2] - pairwise_adgvex_start2[i][j+1];
                for(uint32_t k = pairwise_adgvex_start2[i][j+1]; k < pairwise_adgvex_start2[i][j+2]; k++){
                    pairwise_adgvex_minHash[i][pairwise_adgvex_min_i++] = pairwise_adgvex2[i][k];
                }

            }else{
                pairwise_adgvex_start_minHash[i][j+2] = pairwise_adgvex_start_minHash[i][j+1] + bucket;

                vector<bool> bucket_bool(bucket, false);

                for(uint32_t k = pairwise_adgvex_start2[i][j+1]; k < pairwise_adgvex_start2[i][j+2]; k++){
                    int bucket_i = pairwise_adgvex2[i][k].hyperedge & bucket_mask;
                    // int bucket_i = rand()%bucket;

                    if(bucket_bool[bucket_i]){
                        if((pairwise_adgvex_minHash[i][pairwise_adgvex_min_i + bucket_i].hyperedge >> log_num_samples) > (pairwise_adgvex2[i][k].hyperedge >> log_num_samples)) pairwise_adgvex_minHash[i][pairwise_adgvex_min_i + bucket_i] = pairwise_adgvex2[i][k];
                    }else{
                        pairwise_adgvex_minHash[i][pairwise_adgvex_min_i + bucket_i] = pairwise_adgvex2[i][k];
                    }

                }
                

                std::sort(pairwise_adgvex_minHash[i].begin() + pairwise_adgvex_min_i, pairwise_adgvex_minHash[i].begin()+pairwise_adgvex_min_i + bucket, [](const pairwise_edge& a, const pairwise_edge& b) {
                    if(a.vertex == b.vertex) return a.hyperedge < b.hyperedge;
                    return a.vertex < b.vertex;
                });

                pairwise_adgvex_minHash[i][pairwise_adgvex_min_i].vertex = pairwise_adgvex2[i][pairwise_adgvex_start2[i][j+1]].vertex;

                pairwise_adgvex_min_i+=bucket;

                
            }
        }
        
        
    }
    
    if(out_edge_start == NULL) out_edge_start = new uint32_t[n+1];
    if(out_edges == NULL) out_edges = new out_edge_vertex_pos[out_edges_num];
    
    uint32_t out_edges_i = 0;
    out_edge_start[0] = 0;
    
    for(uint32_t i = 0;i<n;i++){
        out_edge_start[i+1] = out_edge_start[i];

        
        for(uint32_t j = 0; j<pairwise_adgvex_start_minHash[i][0]; j++){
            

            if(pairwise_adgvex_start_minHash[i][0] > pairwise_adgvex_start_minHash[pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex][0] || (pairwise_adgvex_start_minHash[i][0] == pairwise_adgvex_start_minHash[pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex][0] && i > pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex)){
                
                out_edges[out_edges_i].vertex = pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex;
                
                out_edges[out_edges_i].pos = j+1;
                out_edges[out_edges_i++].neighbor_num = pairwise_adgvex_start2[i][j+2] - pairwise_adgvex_start2[i][j+1];

                out_edge_start[i+1]++;
                
            }
        }
    }
    
    
    
    out_edge_start[n] = out_edges_i;
    cout<<"vertices_pairwise_edge_num:"<<vertices_pairwise_edge_num<<endl;
}

void Graph::to_pairwise_minHash3(){
        uint64_t vertices_pairwise_edge_num = 0;
    for(uint32_t i = 0;i<e;i++){
        // cout<<i<<endl;
        for(uint32_t j = hyperedges_start[i]; j < hyperedges_start[i+1]; j++){
            if(vertex_len[hyperedges[j]] == 1) continue;
            for(uint32_t k = j + 1; k < hyperedges_start[i+1]; k++){
                if(vertex_len[hyperedges[k]] == 1) continue;
                pairwise_adgvex2[hyperedges[j]].push_back({hyperedges[k], i});
                pairwise_adgvex2[hyperedges[k]].push_back({hyperedges[j], i});
                
                
            }
        }
        vertices_pairwise_edge_num+= (hyperedges_start[i+1] - hyperedges_start[i])*(hyperedges_start[i+1] - hyperedges_start[i] - 1);
    }
    
    uint32_t out_edges_num = 0;
    
    for(uint32_t i = 0; i< n; i++){
        // cout<<i<<endl;
        if(pairwise_adgvex2[i].size()<1) continue;
        std::sort(pairwise_adgvex2[i].begin(), pairwise_adgvex2[i].end(), [](const pairwise_edge& a, const pairwise_edge& b) {
            if(a.vertex == b.vertex) return a.hyperedge < b.hyperedge;
            return a.vertex < b.vertex;
        });
        

        pairwise_adgvex_start2[i][0] = 0;
        uint32_t pairwise_adgvex_start_i = 1;
        uint32_t last_vertex = pairwise_adgvex2[i][0].vertex+1;
        for(uint32_t j = 0; j < pairwise_adgvex2[i].size();j++){
            if(pairwise_adgvex2[i][j].vertex != last_vertex){
                pairwise_adgvex_start2[i][pairwise_adgvex_start_i++] = j;
                pairwise_adgvex_start2[i][0]++;
                last_vertex = pairwise_adgvex2[i][j].vertex;
            }
        }
        out_edges_num+=pairwise_adgvex_start2[i][0];
        pairwise_adgvex_start2[i][pairwise_adgvex_start_i] = pairwise_adgvex2[i].size();

        uint32_t pairwise_adgvex_min_i = 0;
        pairwise_adgvex_start_minHash[i][0] = pairwise_adgvex_start2[i][0];
        pairwise_adgvex_start_minHash[i][1] = 0;
        for(uint32_t j = 0; j<pairwise_adgvex_start2[i][0]; j++){
            if(pairwise_adgvex_start2[i][j+2] - pairwise_adgvex_start2[i][j+1] <= bucket){
                pairwise_adgvex_start_minHash[i][j+2] = pairwise_adgvex_start_minHash[i][j+1] + pairwise_adgvex_start2[i][j+2] - pairwise_adgvex_start2[i][j+1];
                for(uint32_t k = pairwise_adgvex_start2[i][j+1]; k < pairwise_adgvex_start2[i][j+2]; k++){
                    pairwise_adgvex_minHash[i][pairwise_adgvex_min_i++] = pairwise_adgvex2[i][k];
                }

            }else{
                pairwise_adgvex_start_minHash[i][j+2] = pairwise_adgvex_start_minHash[i][j+1] + bucket;

                vector<bool> bucket_bool(bucket, false);

                for(uint32_t k = pairwise_adgvex_start2[i][j+1]; k < pairwise_adgvex_start2[i][j+2]; k++){
                    int bucket_i = pairwise_adgvex2[i][k].hyperedge & bucket_mask;

                    if(bucket_bool[bucket_i]){
                        if((pairwise_adgvex_minHash[i][pairwise_adgvex_min_i + bucket_i].hyperedge >> log_num_samples) > (pairwise_adgvex2[i][k].hyperedge >> log_num_samples)) pairwise_adgvex_minHash[i][pairwise_adgvex_min_i + bucket_i] = pairwise_adgvex2[i][k];
                    }else{
                        pairwise_adgvex_minHash[i][pairwise_adgvex_min_i + bucket_i] = pairwise_adgvex2[i][k];
                    }

                }
                

                std::sort(pairwise_adgvex_minHash[i].begin() + pairwise_adgvex_min_i, pairwise_adgvex_minHash[i].begin()+pairwise_adgvex_min_i + bucket, [](const pairwise_edge& a, const pairwise_edge& b) {
                    if(a.vertex == b.vertex) return a.hyperedge < b.hyperedge;
                    return a.vertex < b.vertex;
                });

                pairwise_adgvex_minHash[i][pairwise_adgvex_min_i].vertex = pairwise_adgvex2[i][pairwise_adgvex_start2[i][j+1]].vertex;

                pairwise_adgvex_min_i+=bucket;

                
            }
        }
        
        
    }
    
    if(out_edge_start == NULL) out_edge_start = new uint32_t[n+1];
    if(out_edges == NULL) out_edges = new out_edge_vertex_pos[out_edges_num];

    if(out_edge_start_minHash == NULL) out_edge_start_minHash = new uint32_t[n+1];
    if(out_edges_minHash == NULL) out_edges_minHash = new out_edge_vertex_pos[out_edges_num];
    
    uint32_t out_edges_i = 0;
    out_edge_start[0] = 0;
    
    for(uint32_t i = 0;i<n;i++){
        out_edge_start[i+1] = out_edge_start[i];

        for(uint32_t j = 0; j<pairwise_adgvex_start_minHash[i][0]; j++){
            

            if(pairwise_adgvex_start_minHash[i][0] > pairwise_adgvex_start_minHash[pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex][0] || (pairwise_adgvex_start_minHash[i][0] == pairwise_adgvex_start_minHash[pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex][0] && i > pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex)){
                
                out_edges[out_edges_i].vertex = pairwise_adgvex_minHash[i][pairwise_adgvex_start_minHash[i][j+1]].vertex;
                
                out_edges[out_edges_i].pos = j+1;
                out_edges[out_edges_i++].neighbor_num = pairwise_adgvex_start2[i][j+2] - pairwise_adgvex_start2[i][j+1];
                out_edge_start[i+1]++;
                
            }
        }

        out_degree[i] = out_edge_start[i+1] - out_edge_start[i];

    }
    out_edges_i = 0;
    out_edge_start_minHash[0] = 0;
    for(uint32_t i = 0;i<n;i++){
        if(out_edge_start[i+1] - out_edge_start[i] <= bucket){
            out_edge_start_minHash[i+1] = out_edge_start_minHash[i] + out_edge_start[i+1] - out_edge_start[i];
            for(uint32_t j = out_edge_start[i]; j< out_edge_start[i+1]; j++){
                out_edges_minHash[out_edges_i++] = out_edges[j];
            }
        }
        else {
            vector<bool> bucket_bool(bucket, false);
            out_edge_start_minHash[i+1] = out_edge_start_minHash[i] + bucket;
            for(uint32_t j = out_edge_start[i]; j< out_edge_start[i+1]; j++){
                // int bucket_i = out_edges[j].vertex & bucket_mask;
                int bucket_i = rand()%bucket;
                if(bucket_bool[bucket_i]){
                    if((out_edges_minHash[out_edges_i + bucket_i].vertex >> log_num_samples) > (out_edges[j].vertex >> log_num_samples)) out_edges_minHash[out_edges_i + bucket_i] = out_edges[j];
                }else{
                    out_edges_minHash[out_edges_i + bucket_i] = out_edges[j];
                    bucket_bool[bucket_i] = true;
                }
            }

            for(int j = 0; j<bucket;j++){
                if(bucket_bool[j] == false){
                    out_edges_minHash[out_edges_i + j].vertex = n;
                }
            }
            out_edges_i+=bucket;
        
        }

    }
    
    
    
    out_edge_start[n] = out_edges_i;
    cout<<"vertices_pairwise_edge_num:"<<vertices_pairwise_edge_num<<endl;
}

void Graph::to_pairwise_minHash4(){
        uint64_t vertices_pairwise_edge_num = 0;
    for(uint32_t i = 0;i<e;i++){
        // cout<<i<<endl;
        for(uint32_t j = hyperedges_start[i]; j < hyperedges_start[i+1]; j++){
            if(vertex_len[hyperedges[j]] == 1) continue;
            for(uint32_t k = j + 1; k < hyperedges_start[i+1]; k++){
                if(vertex_len[hyperedges[k]] == 1) continue;
                pairwise_adgvex2[hyperedges[j]].push_back({hyperedges[k], i});
                pairwise_adgvex2[hyperedges[k]].push_back({hyperedges[j], i});
                
                
            }
        }
        vertices_pairwise_edge_num+= (hyperedges_start[i+1] - hyperedges_start[i])*(hyperedges_start[i+1] - hyperedges_start[i] - 1);
    }
    
    uint32_t out_edges_num = 0;
    
    for(uint32_t i = 0; i< n; i++){
        // cout<<i<<endl;
        if(pairwise_adgvex2[i].size()<1) continue;
        std::sort(pairwise_adgvex2[i].begin(), pairwise_adgvex2[i].end(), [](const pairwise_edge& a, const pairwise_edge& b) {
            if(a.vertex == b.vertex) return a.hyperedge < b.hyperedge;
            return a.vertex < b.vertex;
        });
        

        pairwise_adgvex_start2[i][0] = 0;
        uint32_t pairwise_adgvex_start_i = 1;
        uint32_t last_vertex = pairwise_adgvex2[i][0].vertex+1;
        for(uint32_t j = 0; j < pairwise_adgvex2[i].size();j++){
            if(pairwise_adgvex2[i][j].vertex != last_vertex){
                pairwise_adgvex_start2[i][pairwise_adgvex_start_i++] = j;
                pairwise_adgvex_start2[i][0]++;
                last_vertex = pairwise_adgvex2[i][j].vertex;
            }
        }
        out_edges_num+=pairwise_adgvex_start2[i][0];
        pairwise_adgvex_start2[i][pairwise_adgvex_start_i] = pairwise_adgvex2[i].size();
    }
    
    if(out_edge_start == NULL) out_edge_start = new uint32_t[n+1];
    if(out_edges == NULL) out_edges = new out_edge_vertex_pos[out_edges_num];

    if(out_edge_start_minHash == NULL) out_edge_start_minHash = new uint32_t[n+1];
    if(out_edges_minHash == NULL) out_edges_minHash = new out_edge_vertex_pos[out_edges_num];
    
    uint32_t out_edges_i = 0;
    out_edge_start[0] = 0;
    
    for(uint32_t i = 0;i<n;i++){
        out_edge_start[i+1] = out_edge_start[i];

        for(uint32_t j = 0; j<pairwise_adgvex_start2[i][0]; j++){
            

            if(pairwise_adgvex_start2[i][0] > pairwise_adgvex_start2[pairwise_adgvex2[i][pairwise_adgvex_start2[i][j+1]].vertex][0] || (pairwise_adgvex_start2[i][0] == pairwise_adgvex_start2[pairwise_adgvex2[i][pairwise_adgvex_start2[i][j+1]].vertex][0] && i > pairwise_adgvex2[i][pairwise_adgvex_start2[i][j+1]].vertex)){
                
                out_edges[out_edges_i].vertex = pairwise_adgvex2[i][pairwise_adgvex_start2[i][j+1]].vertex;
                out_edges[out_edges_i++].pos = j+1;
                out_edge_start[i+1]++;
                
            }
        }

        out_degree[i] = out_edge_start[i+1] - out_edge_start[i];

    }
    out_edges_i = 0;
    out_edge_start_minHash[0] = 0;
    for(uint32_t i = 0;i<n;i++){
        if(out_edge_start[i+1] - out_edge_start[i] <= bucket){
            out_edge_start_minHash[i+1] = out_edge_start_minHash[i] + out_edge_start[i+1] - out_edge_start[i];
            for(uint32_t j = out_edge_start[i]; j< out_edge_start[i+1]; j++){
                out_edges_minHash[out_edges_i++] = out_edges[j];
            }
        }
        else {
            vector<bool> bucket_bool(bucket, false);
            out_edge_start_minHash[i+1] = out_edge_start_minHash[i] + bucket;
            for(uint32_t j = out_edge_start[i]; j< out_edge_start[i+1]; j++){
                int bucket_i = out_edges[j].vertex & bucket_mask;
                // int bucket_i = rand()%bucket;
                if(bucket_bool[bucket_i]){
                    if((out_edges_minHash[out_edges_i + bucket_i].vertex >> log_num_samples) > (out_edges[j].vertex >> log_num_samples)) out_edges_minHash[out_edges_i + bucket_i] = out_edges[j];
                }else{
                    out_edges_minHash[out_edges_i + bucket_i] = out_edges[j];
                    bucket_bool[bucket_i] = true;
                }
            }

            for(int j = 0; j<bucket;j++){
                if(bucket_bool[j] == false){
                    out_edges_minHash[out_edges_i + j].vertex = n;
                }
            }
            out_edges_i+=bucket;
        
        }

    }
    
    
    
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

void Graph::to_hyperedge_based_pairwise2(){
    uint32_t last = 0;
    uint32_t hyperedges_to_vectices_i = 0;
    uint32_t intersection_start_i = 0;
    uint32_t hyperedges_to_vectices_start_i = 0;
    for(uint32_t i = 0; i<e;i++){
//        cout<<i<<endl;
//        for(uint32_t j = i+1; j<e;j++){
//            tett+= two_interaction_num2(hyperedges + hyperedges_start[i], hyperedges_start[i+1] - hyperedges_start[i], hyperedges + hyperedges_start[j], hyperedges_start[j+1] - hyperedges_start[j]);
//        }
        
        for(uint32_t j = hyperedges_start[i]; j< hyperedges_start[i+1]; j++){
            
            for(uint32_t k = 0; k<vertices[hyperedges[j]].size();k++){
                if(vertices[hyperedges[j]][k] == i) continue;
//                if(i < vertices[hyperedges[j]][k]){
//
//
                    hyperedges_to_vectices[hyperedges_to_vectices_i].hyperedge = vertices[hyperedges[j]][k];
                    hyperedges_to_vectices[hyperedges_to_vectices_i++].vertex = hyperedges[j];
//                }
            }
        }
        sort(hyperedges_to_vectices + last, hyperedges_to_vectices + hyperedges_to_vectices_i, compare_by_hyperedge);
        hyperedges_to_vectices_start[hyperedges_to_vectices_start_i++] = intersection_start_i;
        int len = 1;
        for(uint32_t j = last+1; j<hyperedges_to_vectices_i;j++){
            if(hyperedges_to_vectices[j].hyperedge != hyperedges_to_vectices[j-1].hyperedge){
                if(len>1){
                    intersection_start[intersection_start_i] = j - len;
                    intersection_start_len[intersection_start_i++] = len;
                    len = 1;
                }
            }else len++;
        }
        
        if(len>1){
            intersection_start[intersection_start_i] = hyperedges_to_vectices_i - len;
            intersection_start_len[intersection_start_i++] = len;
            len = 1;
        }
        
        last = hyperedges_to_vectices_i;
        
    }
    
    intersection_start[intersection_start_i++] = hyperedges_to_vectices_i;
    hyperedges_to_vectices_start[hyperedges_to_vectices_start_i++] = intersection_start_i;
    
    cout<<hyperedges_to_vectices_i<<" "<<intersection_start_i<<" "<<hyperedges_to_vectices_start_i<<endl;
    
//    for(int i = 0;i<10;i++){
//        for(int j = hyperedges_to_vectices_start[i]; j<hyperedges_to_vectices_start[i+1];j++){
//            for(int k = intersection_start[j];k<intersection_start[j]+intersection_start_len[j];k++)
//                cout<<hyperedges_to_vectices[k].hyperedge<<" "<<hyperedges_to_vectices[k].vertex<<"||";
//            cout<<endl;
//        }
//        cout<<endl;
//    }
    
    
}

void Graph::to_hyperedge_based_pairwise(){

    uint32_t *pairwise_edge_adgvex_i = new uint32_t[e];
    memset(pairwise_edge_adgvex_i, 0, sizeof(uint32_t)*e);

    uint64_t all_num = 0;

    for(uint32_t i = 0;i<e;i++){
        for(uint32_t j = hyperedges_start[i];j<hyperedges_start[i+1];j++){
            for(uint32_t j2 = 0;j2<vertex_len[hyperedges[j]];j2++){
            if(i<vertices[hyperedges[j]][j2] && pairwise_edge_adgvex_i[vertices[hyperedges[j]][j2]] != e+1){
                pairwise_edge_adgvex_i[vertices[hyperedges[j]][j2]] = e+1;

                for(uint32_t k1 = hyperedges_start[i], k2 = hyperedges_start[vertices[hyperedges[j]][j2]];k1<hyperedges_start[i+1] && k2 < hyperedges_start[vertices[hyperedges[j]][j2]+1];){
                    if(hyperedges[k1] == hyperedges[k2]){
                        k1++;
                        k2++;
                        all_num++;
                        // pairwise_edge_adgvex[i][pairwise_edge_adgvex_i[i]++] = pairwise_edge{hyperedges[k1], i};
                        // pairwise_edge_adgvex[vertices[hyperedges[j]][j2]][pairwise_edge_adgvex_i[vertices[hyperedges[j]][j2]]++] = pairwise_edge{hyperedges[k2], vertices[hyperedges[j]][j2]};

                    }
                    else if (hyperedges[k1] < hyperedges[k2]) {
                        k1++;
                    }
                    else{
                        k2++;
                    }
                }
            }
            }
        
        }

    }

    cout<<"all_num:"<<all_num<<endl;

    
    // for(uint32_t i = 0; i <n;i++){
    //     // cout<<vertex_len[i]<<endl;
    //     for(uint32_t j = 0; j < vertex_len[i]; j++){
    //         for(uint32_t k = j + 1; k<vertex_len[i];k++){
                // pairwise_edge_adgvex[vertices[i][j]][pairwise_edge_adgvex_i[vertices[i][j]]++] = pairwise_edge{i, vertices[i][k]};
                // pairwise_edge_adgvex[vertices[i][k]][pairwise_edge_adgvex_i[vertices[i][k]]++] = pairwise_edge{i, vertices[i][j]};
    //         }
    //     }
    // }
    
    // for(uint32_t i = 0; i<e;i++){
    //     pairwise_edge_adgvex_start[i][0] = 0;
        
    //     if(pairwise_edge_adgvex_i[i] < 1) continue;
    //     sort(pairwise_edge_adgvex[i].begin(), pairwise_edge_adgvex[i].begin() + pairwise_edge_adgvex_i[i], [](const pairwise_edge& a, const pairwise_edge& b) {
    //         if(a.hyperedge == b.hyperedge) return a.vertex < b.vertex;
    //         return a.hyperedge < b.hyperedge;
    //     });
        
        
    //     uint32_t pairwise_adgvex_start_i = 1;
    //     uint32_t last_hyperedge = pairwise_edge_adgvex[i][0].hyperedge+1;
    //     for(uint32_t j = 0; j < pairwise_edge_adgvex_i[i];j++){
    //         if(pairwise_edge_adgvex[i][j].hyperedge != last_hyperedge){
    //             pairwise_edge_adgvex_start[i][pairwise_adgvex_start_i++] = j;
    //             pairwise_edge_adgvex_start[i][0]++;
    //             last_hyperedge = pairwise_edge_adgvex[i][j].hyperedge;
    //         }
    //     }
    //     pairwise_edge_num += pairwise_edge_adgvex_start[i][0];
    //     // cout<<pairwise_edge_adgvex_start[i][0]<<endl;
    //     pairwise_edge_adgvex_start[i][pairwise_adgvex_start_i] = pairwise_edge_adgvex_i[i];
    
    // }
    
    cout<<"pairwise_edge_num:"<<pairwise_edge_num<<endl;
    cout<<"arg_edge_nei:"<<pairwise_edge_num/e<<endl;
    
}

int judge_tri_type_i = 0;

void Graph::judge_tri_type(uint32_t u, uint32_t u_pos, uint32_t v, uint32_t v_pos,uint32_t w, uint32_t w_pos, uint32_t &type, uint32_t &tri_num, uint32_t &common_num){

    common_num = 0;
    type = 0;
    tri_num = 1;
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
        type++;
        tri_num = tri_num*(pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos] - common_num);
    }
    if((pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num) > 0){
        type++;
        tri_num = tri_num*(pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num);
    }
    if((pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num) > 0){
        type++;
        tri_num = tri_num*(pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num);
    }
    
    if(common_num == 0) type++;
    else tri_num = tri_num*common_num;

    // if(common_num>1000) cout<<common_num<<" "<<pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos] - common_num<<" "<<pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num<<" "<<pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num<<endl;
}


int Graph::judge_tri_type_minHash(uint32_t u, uint32_t u_pos, uint32_t u_nei_num, uint32_t v, uint32_t v_pos, uint32_t v_nei_num,uint32_t w, uint32_t w_pos, uint32_t w_nei_num, uint32_t &type, uint32_t &tri_num, uint32_t &common_num){

    // return;
    
    common_num = 0;
    type = 0;
    tri_num = 1;
    uint32_t u_i, v_i, w_i;
    for(u_i = pairwise_adgvex_start_minHash[u][u_pos], v_i = pairwise_adgvex_start_minHash[v][v_pos], w_i = pairwise_adgvex_start_minHash[w][w_pos]; u_i < pairwise_adgvex_start_minHash[u][u_pos+1] && v_i < pairwise_adgvex_start_minHash[v][v_pos+1] && w_i < pairwise_adgvex_start_minHash[w][w_pos+1];){
        if(pairwise_adgvex_minHash[u][u_i].hyperedge == e || pairwise_adgvex_minHash[v][v_i].hyperedge == e || pairwise_adgvex_minHash[w][w_i].hyperedge == e) break;
        if(pairwise_adgvex_minHash[u][u_i].hyperedge == pairwise_adgvex_minHash[v][v_i].hyperedge && pairwise_adgvex_minHash[u][u_i].hyperedge == pairwise_adgvex_minHash[w][w_i].hyperedge){
            u_i++;
            v_i++;
            w_i++;
            common_num++;
        }
        else if (pairwise_adgvex_minHash[u][u_i].hyperedge < pairwise_adgvex_minHash[v][v_i].hyperedge && pairwise_adgvex_minHash[u][u_i].hyperedge < pairwise_adgvex_minHash[w][w_i].hyperedge){
            u_i++;
        }else if (pairwise_adgvex_minHash[u][u_i].hyperedge > pairwise_adgvex_minHash[v][v_i].hyperedge && pairwise_adgvex_minHash[v][v_i].hyperedge < pairwise_adgvex_minHash[w][w_i].hyperedge){
            v_i++;
        }else{
            w_i++;
        }
        
    }
    int origin_common = common_num;

    // double sim = common_num/()

    common_num = (int)(2*(double)common_num * (double)(u_nei_num + v_nei_num + w_nei_num)/(double)(pairwise_adgvex_start_minHash[u][u_pos+1] - pairwise_adgvex_start_minHash[u][u_pos] + pairwise_adgvex_start_minHash[v][v_pos+1] - pairwise_adgvex_start_minHash[v][v_pos] + pairwise_adgvex_start_minHash[w][w_pos+1] - pairwise_adgvex_start_minHash[w][w_pos]));


    common_num = min(min(common_num, u_nei_num), min(v_nei_num, w_nei_num));

    // common_num = (int)((double)common_num * (double)min(min(u_nei_num, v_nei_num), w_nei_num)/(double)min(min(pairwise_adgvex_start_minHash[u][u_pos+1] - pairwise_adgvex_start_minHash[u][u_pos], pairwise_adgvex_start_minHash[v][v_pos+1] - pairwise_adgvex_start_minHash[v][v_pos]), pairwise_adgvex_start_minHash[w][w_pos+1] - pairwise_adgvex_start_minHash[w][w_pos]));

    // cout<<max(pairwise_adgvex_start_minHash[u][u_pos+1] - pairwise_adgvex_start_minHash[u][u_pos], max(pairwise_adgvex_start_minHash[v][v_pos+1] - pairwise_adgvex_start_minHash[v][v_pos], pairwise_adgvex_start_minHash[w][w_pos+1] - pairwise_adgvex_start_minHash[w][w_pos]))<<endl;

    // cout<<max(u_i - pairwise_adgvex_start_minHash[u][u_pos], max(v_i - pairwise_adgvex_start_minHash[v][v_pos], w_i - pairwise_adgvex[w][w_i].hyperedge))<<endl;
    
    if((u_nei_num - common_num) > 0){
        type++;
        tri_num = tri_num*(u_nei_num - common_num);
    }
    if((v_nei_num - common_num) > 0){
        type++;
        tri_num = tri_num*(v_nei_num - common_num);
    }
    if((w_nei_num - common_num) > 0){
        type++;
        tri_num = tri_num*(w_nei_num - common_num);
    }
    
    if(common_num == 0) type++;
    else tri_num = tri_num*common_num;

    return origin_common;

    // if(common_num>1000) cout<<common_num<<" "<<pairwise_adgvex_start[u][u_pos+1] - pairwise_adgvex_start[u][u_pos] - common_num<<" "<<pairwise_adgvex_start[v][v_pos+1] - pairwise_adgvex_start[v][v_pos] - common_num<<" "<<pairwise_adgvex_start[w][w_pos+1] - pairwise_adgvex_start[w][w_pos] - common_num<<endl;
}

void Graph::judge_tri_type_minHash2(uint32_t u, uint32_t u_pos, uint32_t v, uint32_t v_pos,uint32_t w, uint32_t w_pos, uint32_t &type, uint32_t &tri_num, uint32_t &common_num){

    common_num = 0;
    type = 0;
    tri_num = 1;
    uint32_t u_i, v_i, w_i;
    for(u_i = pairwise_adgvex_start2[u][u_pos], v_i = pairwise_adgvex_start2[v][v_pos], w_i = pairwise_adgvex_start2[w][w_pos]; u_i < pairwise_adgvex_start2[u][u_pos+1] && v_i < pairwise_adgvex_start2[v][v_pos+1] && w_i < pairwise_adgvex_start2[w][w_pos+1];){
        if(pairwise_adgvex2[u][u_i].hyperedge == e || pairwise_adgvex2[v][v_i].hyperedge == e || pairwise_adgvex2[w][w_i].hyperedge == e) break;
        if(pairwise_adgvex2[u][u_i].hyperedge == pairwise_adgvex2[v][v_i].hyperedge && pairwise_adgvex2[u][u_i].hyperedge == pairwise_adgvex2[w][w_i].hyperedge){
            u_i++;
            v_i++;
            w_i++;
            common_num++;
        }
        else if (pairwise_adgvex2[u][u_i].hyperedge < pairwise_adgvex2[v][v_i].hyperedge && pairwise_adgvex2[u][u_i].hyperedge < pairwise_adgvex2[w][w_i].hyperedge){
            u_i++;
        }else if (pairwise_adgvex2[u][u_i].hyperedge > pairwise_adgvex2[v][v_i].hyperedge && pairwise_adgvex2[v][v_i].hyperedge < pairwise_adgvex2[w][w_i].hyperedge){
            v_i++;
        }else{
            w_i++;
        }
        
    }

    if((pairwise_adgvex_start2[u][u_pos+1] - pairwise_adgvex_start2[u][u_pos] - common_num) > 0){
        type++;
        tri_num = tri_num*(pairwise_adgvex_start2[u][u_pos+1] - pairwise_adgvex_start2[u][u_pos] - common_num);
    }
    if((pairwise_adgvex_start2[v][v_pos+1] - pairwise_adgvex_start2[v][v_pos] - common_num) > 0){
        type++;
        tri_num = tri_num*(pairwise_adgvex_start2[v][v_pos+1] - pairwise_adgvex_start2[v][v_pos] - common_num);
    }
    if((pairwise_adgvex_start2[w][w_pos+1] - pairwise_adgvex_start2[w][w_pos] - common_num) > 0){
        type++;
        tri_num = tri_num*(pairwise_adgvex_start2[w][w_pos+1] - pairwise_adgvex_start2[w][w_pos] - common_num);
    }
    
    if(common_num == 0) type++;
    else tri_num = tri_num*common_num;

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


