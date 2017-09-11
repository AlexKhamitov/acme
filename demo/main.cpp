#include <iostream>
#include <cassert>
#include <random>
#include "../common/eh128148.hpp"

int rand(int min, int max) {
    static std::mt19937 prng(std::random_device{}());
    return std::uniform_int_distribution <> (min, max)(prng);
}

bool is_included(std::size_t x1, std::size_t y1,std::size_t z1,
                 std::size_t x2, std::size_t y2, std::size_t z2, std::size_t d) {
    return 4*((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2)) <= d*d;
}

int main()
{
    std::size_t a, b, c, n, d;
    std::cout << "Enter cheese's parametrs: width, height, depth; bomb's numbers and diameter" << '\n';
    if(!(std::cin >> a >> b >> c >> n >> d)) {
        std::cerr << "Incorrect data";
        return 1;
    }
    std::size_t* size = new std::size_t[3];
    size[0] = a;
    size[1] = b;
    size[2] = c;
    N::S_t acme = N::init(size, true, 3);

    std::size_t x_bomb,y_bomb,z_bomb;
    std::size_t coord[3] = {};

    for(std::size_t q = 0; q < n; ++q) {
        x_bomb = rand(0, N::array_size(acme)[0]-1);
        y_bomb = rand(0, N::array_size(acme)[1]-1);
        z_bomb = rand(0, N::array_size(acme)[2]-1);
        //TODO: delete it
        std::cout << x_bomb << ' ' << y_bomb << ' ' << z_bomb << '\n';
        for(std::size_t i = 0; i < N::array_size(acme)[0]; ++i) {
            for(std::size_t j = 0; j < N::array_size(acme)[1]; ++j) {
                for(std::size_t k = 0; k < N::array_size(acme)[2]; ++k) {
                    if(is_included(x_bomb, y_bomb, z_bomb, i, j, k, d)) {
                        coord[0] = i;
                        coord[1] = j;
                        coord[2] = k;
                        N::rec_symbol(acme, false, coord);
                    }

                }
            }
        }
    }
    std::cout << "Result: \n";


    for(std::size_t k = 0; k < N::array_size(acme)[2]; ++k) {
        coord[2] = k;
        std::cout << '\n';
        for(std::size_t i = 0; i < N::array_size(acme)[0]; ++i) {
            coord[0] = i;
            for(std::size_t j = 0; j < N::array_size(acme)[1]; ++j) {
                coord[1] = j;
                std::cout << (N::read_symbol(acme,coord) ? '#': ' ');
            }
            std::cout << '\n';
        }
        std::cout << "-----";
    }
    std::cout << '\n';

}
