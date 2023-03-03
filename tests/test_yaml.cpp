#include <yaml-cpp/yaml.h>
#include <assert.h>
#include <iostream>

int main() {
    YAML::Node node = YAML::Load("[1, 2, 3]");
    for(std::size_t i = 0; i < node.size(); ++i) {
        std::cout << node[i].as<int>() << "\n";
    }
}
