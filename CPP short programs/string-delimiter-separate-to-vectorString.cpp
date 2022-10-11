#include <sstream>
#include <vector>
#include <iostream>

int main() {
    std::string input= "FUT,OPT,MLEG";
    std::stringstream ss(input);
    std::vector<std::string> output;
    int i;
    while (ss.good()) {
        std::string substr;
        getline(ss, substr, ','); //get first string delimited by comma
        output.push_back(substr);
    }    
    for (size_t i = 0; i < output.size(); i++)
    {
        std::cout << output[i]<<" ";
    }
}

//Output: FUT OPT MLEG
