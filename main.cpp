//
//  main.cpp
//  hypergraph_tri_count
//
//  Created by LingkaiMeng on 2024/3/20.
//

#include <cstdint>
#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str = "/home/data/mlk/data/hyperdata/";
    
    if (argc > 1) str = str + string(argv[1]);
    else str = str + "NDC";

    uint32_t Reservoir_size = 10;
    if(argc > 2) Reservoir_size = stoi(argv[2]);

    
    Graph *g = new Graph(str.data(), Reservoir_size);
    
    clock_t startTime,endTime;
    startTime = clock();
    
    g->read_graph();
    
    endTime = clock();
    cout << "The read_graph time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    
    startTime = clock();
    vector<uint64_t> accurate_value = g->triangle_enum();
    endTime = clock();
    cout << "The triangle_enum time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    
    startTime = clock();
    vector<uint64_t> stream_value_local = g->tc_tri_stream_local();
    endTime = clock();
    cout<<"type-1 error: "<<((double)stream_value_local[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    cout<<"type-2 error: "<<((double)stream_value_local[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    cout<<"type-3 error: "<<((double)stream_value_local[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    cout << "The stream_value_local time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;

    startTime = clock();
    vector<uint64_t> stream_value_local2 = g->tc_tri_stream_local2();
    endTime = clock();
    

    cout<<"type-1 error: "<<((double)stream_value_local2[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    cout<<"type-2 error: "<<((double)stream_value_local2[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    cout<<"type-3 error: "<<((double)stream_value_local2[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    cout << "The stream_value_local2 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;

    g->init();

    startTime = clock();
    vector<uint64_t> stream_value_local2_fixed = g->tc_tri_stream_local2_fixed();
    endTime = clock();
    
    cout<<"type-1 error: "<<((double)stream_value_local2_fixed[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    cout<<"type-2 error: "<<((double)stream_value_local2_fixed[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    cout<<"type-3 error: "<<((double)stream_value_local2_fixed[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    cout << "The stream_value_local2_fixed time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;

    g->init();

    startTime = clock();
    vector<uint64_t> stream_value_local2_fixed2 = g->tc_tri_stream_local2_fixed2();
    endTime = clock();
    
    cout<<"type-1 error: "<<((double)stream_value_local2_fixed2[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    cout<<"type-2 error: "<<((double)stream_value_local2_fixed2[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    cout<<"type-3 error: "<<((double)stream_value_local2_fixed2[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    cout << "The stream_value_local2_fixed2 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;

    g->init();

    startTime = clock();
    vector<uint64_t> tc_tri_stream_local2_fixed_muti_Reservoir = g->tc_tri_stream_local2_fixed_muti_Reservoir();
    endTime = clock();
    
    cout<<"type-1 error: "<<((double)tc_tri_stream_local2_fixed_muti_Reservoir[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    cout<<"type-2 error: "<<((double)tc_tri_stream_local2_fixed_muti_Reservoir[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    cout<<"type-3 error: "<<((double)tc_tri_stream_local2_fixed_muti_Reservoir[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    cout << "The tc_tri_stream_local2_fixed_muti_Reservoir time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;


    startTime = clock();
    vector<uint64_t> stream_value_global = g->tc_tri_stream_global();
    endTime = clock();
    
    cout<<"type-1 error: "<<((double)stream_value_global[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    cout<<"type-2 error: "<<((double)stream_value_global[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    cout<<"type-3 error: "<<((double)stream_value_global[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    cout << "The stream_value_global time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;


    

    
//    startTime = clock();
//    g->triangle_count();
//    endTime = clock();
//    cout << "The triangle_count time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    
    return 0;
}
