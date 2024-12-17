#include <iostream>
#include <map>
#include <set>
#include <vector>

class HyperedgeData {
public:

    HyperedgeData(uint32_t num){
        data.resize(num);

    }
    void insert(uint32_t vertex, uint32_t key, uint32_t value) {
        data[vertex][key].insert(value);  // 若 key 不存在，会自动创建
    }

    // 删除操作：从键 key 下的 value 数组中删除值 value
    void erase(uint32_t vertex, uint32_t key, uint32_t value) {
        auto it = data[vertex].find(key);
        if (it != data[vertex].end()) {
            // 删除指定的 value
            it->second.erase(value);

            // 如果 key 的 value 数组为空，删除该 key
            if (it->second.empty()) {
                data[vertex].erase(it);
            }
        }
    }

    bool exists(uint32_t vertex, uint32_t key) const {
        return data[vertex].find(key) != data[vertex].end();
    }

    // 打印整个数据结构的内容
    void print() const {
        for(int i = 0;i<data.size();i++){
            std::cout<<"Vertex:"<<i<<std::endl;
            for (const auto& [key, values] : data[i]) {
                std::cout << "Key: " << key << " -> Values: ";
                for (const auto& val : values) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;
            }
        }
    }
    
    std::vector<std::map<uint32_t, std::set<uint32_t>>> data;  
};