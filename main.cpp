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
#include <fstream>

#include <sys/resource.h>

long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str = "/home/data/mlk/data/hyperdata/";
    
    if (argc > 1) str = str + string(argv[1]);
    else str = str + "NDC";

    uint32_t Reservoir_size = 12;
    if(argc > 2) Reservoir_size = stoi(argv[2]);

    
    Graph *g = new Graph(str.data(), Reservoir_size);
    
    clock_t startTime,endTime;
    startTime = clock();

    long start_memory, end_memory;

    vector<double> time1, time2, type2_error1, type2_error2, type3_error1, type3_error2;
    vector<uint64_t> sample_size1, sample_size2, sample_edge1, sample_edge2;
    std::string filename = string("results2_2024_12_15/") + string(argv[1]) +string(argv[2]) + "_result.txt"; // 要写入的文件名
    cout<<filename<<endl;
    std::ofstream outfile(filename); 
    
    g->read_graph();
    
    endTime = clock();
    cout << "The read_graph time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    
    startTime = clock();
    vector<uint64_t> accurate_value = g->triangle_enum();
    endTime = clock();
    // cout << "The triangle_enum time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    // cout<<endl;
    
    // start_memory = getMemoryUsage();
    // startTime = clock();
    // vector<uint64_t> stream_value_local = g->tc_tri_stream_local_time();
    // endTime = clock();
    // end_memory = getMemoryUsage();
    // cout<<"type-1 error: "<<((double)stream_value_local[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    // cout<<"type-2 error: "<<((double)stream_value_local[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    // cout<<"type-3 error: "<<((double)stream_value_local[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    // cout << "The tc_tri_stream_local_time time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    // cout << "The tc_tri_stream_local_time memory is: " <<(double)(end_memory - start_memory)  << endl;
    // cout<<endl;

    // start_memory = getMemoryUsage();
    // startTime = clock();
    // vector<uint64_t> stream_value_local2 = g->tc_tri_stream_local_space();
    // endTime = clock();
    // end_memory = getMemoryUsage();
    

    // cout<<"type-1 error: "<<((double)stream_value_local2[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    // cout<<"type-2 error: "<<((double)stream_value_local2[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    // cout<<"type-3 error: "<<((double)stream_value_local2[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    // cout << "The tc_tri_stream_local_space time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    // cout << "The tc_tri_stream_local_space memory is: " <<(double)(end_memory - start_memory)  << endl;
    // cout<<endl;

    // start_memory = getMemoryUsage();
    // startTime = clock();
    // vector<uint64_t> stream_value_local22 = g->tc_tri_stream_local_space2();
    // endTime = clock();
    // end_memory = getMemoryUsage();
    

    // cout<<"type-1 error: "<<((double)stream_value_local22[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    // cout<<"type-2 error: "<<((double)stream_value_local22[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    // cout<<"type-3 error: "<<((double)stream_value_local22[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    // cout << "The tc_tri_stream_local_space2 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    // cout << "The tc_tri_stream_local_space2 memory is: " <<(double)(end_memory - start_memory)  << endl;
    // cout<<endl;

    // start_memory = getMemoryUsage();
    // startTime = clock();
    // vector<uint64_t> stream_value_global = g->tc_tri_stream_global_time();
    // endTime = clock();
    // end_memory = getMemoryUsage();
    
    // cout<<"type-1 error: "<<((double)stream_value_global[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    // cout<<"type-2 error: "<<((double)stream_value_global[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    // cout<<"type-3 error: "<<((double)stream_value_global[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    // cout << "The tc_tri_stream_global_time time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    // cout << "The tc_tri_stream_global_time memory is: " <<(double)(end_memory - start_memory)  << endl;
    // cout<<endl;

    // g->init();

    // start_memory = getMemoryUsage();
    // startTime = clock();
    // vector<uint64_t> stream_value_global2 = g->tc_tri_stream_global_space();
    // endTime = clock();
    // end_memory = getMemoryUsage();
    
    // cout<<"type-1 error: "<<((double)stream_value_global2[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    // cout<<"type-2 error: "<<((double)stream_value_global2[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    // cout<<"type-3 error: "<<((double)stream_value_global2[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    // cout << "The tc_tri_stream_global_space time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    // cout << "The tc_tri_stream_global_space memory is: " <<(double)(end_memory - start_memory)  << endl;
    // cout<<endl;
    
    for (int i = 0;i<50;i++){
    g->init();

    start_memory = getMemoryUsage();
    startTime = clock();
    vector<uint64_t> stream_value_local2_fixed = g->tc_tri_stream_local_space_fixed();
    endTime = clock();
    end_memory = getMemoryUsage();
    
    // cout<<"type-1 error: "<<((double)stream_value_local2_fixed[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    // cout<<"type-2 error: "<<((double)stream_value_local2_fixed[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    // cout<<"type-3 error: "<<((double)stream_value_local2_fixed[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    // cout << "The tc_tri_stream_local_space_fixed time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    // cout << "The tc_tri_stream_local_space_fixed memory is: " <<(double)(end_memory - start_memory)  << endl;
    // cout<<endl;

    time1.push_back((double)(endTime - startTime) / CLOCKS_PER_SEC);
    type2_error1.push_back(((double)stream_value_local2_fixed[1] - (double)accurate_value[1])/(double)accurate_value[1]);
    type3_error1.push_back(((double)stream_value_local2_fixed[2] - (double)accurate_value[2])/(double)accurate_value[2]);
    sample_size1.push_back(stream_value_local2_fixed[3]);
    sample_edge1.push_back(stream_value_local2_fixed[4]);

    // g->init();

    // start_memory = getMemoryUsage();
    // startTime = clock();
    // vector<uint64_t> stream_value_local2_fixed2 = g->tc_tri_stream_local_space_fixed2();
    // endTime = clock();
    // end_memory = getMemoryUsage();
    
    // cout<<"type-1 error: "<<((double)stream_value_local2_fixed2[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    // cout<<"type-2 error: "<<((double)stream_value_local2_fixed2[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    // cout<<"type-3 error: "<<((double)stream_value_local2_fixed2[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    // cout << "The tc_tri_stream_local_space_fixed2 time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    // cout << "The tc_tri_stream_local_space_fixed2 memory is: " <<(double)(end_memory - start_memory)  << endl;
    cout<<endl;

    g->init();

    start_memory = getMemoryUsage();
    startTime = clock();
    vector<uint64_t> tc_tri_stream_local2_fixed_muti_Reservoir = g->tc_tri_stream_local_space_fixed_muti_Reservoir();
    endTime = clock();
    end_memory = getMemoryUsage();

    time2.push_back((double)(endTime - startTime) / CLOCKS_PER_SEC);
    type2_error2.push_back(((double)tc_tri_stream_local2_fixed_muti_Reservoir[1] - (double)accurate_value[1])/(double)accurate_value[1]);
    type3_error2.push_back(((double)tc_tri_stream_local2_fixed_muti_Reservoir[2] - (double)accurate_value[2])/(double)accurate_value[2]);
    sample_size2.push_back(tc_tri_stream_local2_fixed_muti_Reservoir[3]);
    sample_edge2.push_back(tc_tri_stream_local2_fixed_muti_Reservoir[4]);

    cout<<i<<"   "<<time1[i]<<","<<time2[i]<<","<<type2_error1[i]<<","<<type2_error2[i]<<","<<type3_error1[i]<<","<<type3_error2[i]<<","<<sample_size1[i]<<","<<sample_size2[i]<<","<<sample_edge1[i]<<","<<sample_edge2[i]<<endl;
    
    }
    
    // cout<<"type-1 error: "<<((double)tc_tri_stream_local2_fixed_muti_Reservoir[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    // cout<<"type-2 error: "<<((double)tc_tri_stream_local2_fixed_muti_Reservoir[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    // cout<<"type-3 error: "<<((double)tc_tri_stream_local2_fixed_muti_Reservoir[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    // cout << "The tc_tri_stream_local_space_fixed_muti_Reservoir time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    // cout << "The tc_tri_stream_local_space_fixed_muti_Reservoir memory is: " <<(double)(end_memory - start_memory)  << endl;
    // cout<<endl;



    for(int i = 0;i<type2_error2.size();i++){
        outfile<<time1[i]<<","<<time2[i]<<","<<type2_error1[i]<<","<<type2_error2[i]<<","<<type3_error1[i]<<","<<type3_error2[i]<<","<<sample_size1[i]<<","<<sample_size2[i]<<","<<sample_edge1[i]<<","<<sample_edge2[i]<<endl;
    }
    outfile.close();

    
    return 0;
}
