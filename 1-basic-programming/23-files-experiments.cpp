#include <fstream>

struct Product {
    char name[15];
    float price;
};

int main() {
    Product products[2];


    std::ofstream outputFile("text.dat", std::ios::out | std::ios::binary);



    if(outputFile.is_open()) {
        char symbol = 'E';
        outputFile.write(&symbol, sizeof(symbol));

        outputFile.close();
    }

    return 0;
}
