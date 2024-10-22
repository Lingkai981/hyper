//
//  main.cpp
//  hypergraph_tri_count
//
//  Created by LingkaiMeng on 2024/3/20.
//

#include <iostream>
#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str = "/Users/milk/test_data/hypergraph/NDC";
    Graph *g = new Graph(str.data());
    
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    
    g->read_graph();
    
    endTime = clock();//计时结束
    cout << "The read_graph time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//计时开始
    g->triangle_enum4();
    endTime = clock();//计时结束
    cout << "The triangle_enum time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
//    startTime = clock();//计时开始
//    g->hyperedge_triangle_enum();
//    endTime = clock();//计时结束
//    cout << "The hyperedge_triangle_enum time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
//    
    
//    startTime = clock();//计时开始
//    g->triangle_count();
//    endTime = clock();//计时结束
//    cout << "The triangle_count time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    return 0;
}
