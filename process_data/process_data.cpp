#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <string>

void processHypergraph(const std::string &inputFile, const std::string &degreeFile, const std::string &edgesFile) {
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open input file: " << inputFile << std::endl;
        return;
    }

    int max_v;

    std::ofstream degreeOut(degreeFile);
    std::ofstream edgesOut(edgesFile);

    if (!degreeOut.is_open() || !edgesOut.is_open()) {
        std::cerr << "Failed to open output files." << std::endl;
        return;
    }

    std::unordered_set<int> uniqueVertices;
    std::vector<std::vector<int> > hyperedges;
    size_t totalPoints = 0;

    std::string line;
    while (std::getline(inFile, line)) {

        std::vector<int> hyperedge;
        std::stringstream ss(line);
        std::string item;

        while (std::getline(ss, item, ',')) {
            //  std::cout<<item<< std::endl;
            
            int vertex = std::stoi(item);
            hyperedge.push_back(vertex);
            // uniqueVertices.insert(vertex);
            if(max_v<vertex){
                max_v = vertex;
                std::cout<<max_v<< std::endl;

            } 
        }

        totalPoints += hyperedge.size();
        hyperedges.push_back(hyperedge);
    }

    // Write degree.txt
    degreeOut << max_v+1 << " " 
              << hyperedges.size() << " " 
              << totalPoints << "\n";
    for (const auto &hyperedge : hyperedges) {
        degreeOut << hyperedge.size() << "\n";
    }

    // Write edges.txt
    for (const auto &hyperedge : hyperedges) {
        for (size_t i = 0; i < hyperedge.size(); ++i) {
            edgesOut << hyperedge[i];
            if (i < hyperedge.size() - 1) {
                edgesOut << " ";
            }
        }
        edgesOut << "\n";
    }

    inFile.close();
    degreeOut.close();
    edgesOut.close();
}

void processHypergraph2(const std::string &aFile,const std::string &bFile, const std::string &degreeFile, const std::string &edgesFile) {
    std::cout << "Processing complete. Results saved to degree.txt and edges.txt." << std::endl;
    // 打开 a.txt 文件（记录边包含的节点数量）
    std::ifstream aInFile(aFile);
    if (!aInFile.is_open()) {
        std::cerr << "Failed to open a.txt file: " << aFile << std::endl;
        return;
    }
int max_v = 0;
std::vector<std::vector<int> > hyperedges;
    // 打开 b.txt 文件（记录节点数据）
    std::ifstream bInFile(bFile);
    if (!bInFile.is_open()) {
        std::cerr << "Failed to open b.txt file: " << bFile << std::endl;
        return;
    }

    std::vector<int> edgeSizes;
    int nodeCount;
    size_t totalPoints = 0;
    
    // 读取 a.txt 文件中的边的节点数量
    while (aInFile >> nodeCount) {
        edgeSizes.push_back(nodeCount);
        totalPoints+=nodeCount;

    }

    std::vector<int> nodes;
    int node;
    hyperedges.resize(edgeSizes.size());
    
    // 读取 b.txt 文件中的节点数据
    for(int i = 0;i<edgeSizes.size();i++){
        for(int j = 0;j<edgeSizes[i];j++){
            if(bInFile >> node){
            if(max_v < node) max_v = node;
            hyperedges[i].push_back(node);
            }
        }
    }

        std::ofstream degreeOut(degreeFile);
    std::ofstream edgesOut(edgesFile);

        // Write degree.txt
    degreeOut << max_v+1 << " " 
              << hyperedges.size() << " " 
              << totalPoints << "\n";
    for (const auto &hyperedge : hyperedges) {
        degreeOut << hyperedge.size() << "\n";
    }

    // Write edges.txt
    for (const auto &hyperedge : hyperedges) {
        for (size_t i = 0; i < hyperedge.size(); ++i) {
            edgesOut << hyperedge[i];
            if (i < hyperedge.size() - 1) {
                edgesOut << " ";
            }
        }
        edgesOut << "\n";
    }



    aInFile.close();
    bInFile.close();
}

int main() {
    // 输入文件路径
    std::string inputFile1 = "/Users/milk/test_data/hypergraph/hyperdata/congress-bills-full/congress-bills-full-nverts.txt";
    std::string inputFile2 = "/Users/milk/test_data/hypergraph/hyperdata/congress-bills-full/congress-bills-full-simplices.txt";
    // 输出文件路径
    std::string degreeFile = "/Users/milk/test_data/hypergraph/hyperdata/congress-bills-full/degree.txt";
    std::string edgesFile = "/Users/milk/test_data/hypergraph/hyperdata/congress-bills-full/edges.txt";

    processHypergraph2(inputFile1,inputFile2, degreeFile, edgesFile);

    std::cout << "Processing complete. Results saved to degree.txt and edges.txt." << std::endl;

    return 0;
}