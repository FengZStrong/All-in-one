#include <iostream>
#include <vector>

int main(int argc, char **argv) {
    const int limit = 10000;
    std::vector<int> vec(limit, 1);
    
    for (int i = 2; i < limit; ++i) {
        if (vec[i]) {
            for(int j = i; j * i < limit; ++j) {
                vec[j * i] = 0;
            }    
        }
    }
    for (int i = 2; i < limit; ++i) {
        if (vec[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}
