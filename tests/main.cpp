#include <iostream>
#include "../common/eh128148.hpp"
#include <cassert>

int main()
{
    {
        std::size_t h[3] = {1,2,3};
        N::S_t Cheese = N::init(h, true, 3);
        assert(N::dimension(Cheese) == 3);
        for(std::size_t i = 0; i < N::dimension(Cheese); ++i)
            assert(N::array_size(Cheese)[i] == h[i]);
        N::destroy(Cheese);
        /**
        std::size_t p[3];
        for(std::size_t i = 0; i < N::array_size(&Cheese)[i]; ++i)
            for(std::size_t j = 0; j < N::array_size(&Cheese)[j]; ++j)
                for(std::size_t k = 0; k < N::array_size(&Cheese)[k]; ++k) {
                    p[i] = i; p[j] = j; p[k] = k;
                    assert(N::read_symbol(&Cheese, p));
                }
        **/
    }

    {
        std::size_t h[2] = {1,2};
        N::S_t Cheese = N::init(h, true, 2);
        assert(N::dimension(Cheese) == 2);
        for(std::size_t i = 0; i < N::dimension(Cheese); ++i)
            assert(N::array_size(Cheese)[i] == h[i]);
        N::destroy(Cheese);
    }

    {
        std::size_t h[1] = {5};
        N::S_t Cheese = N::init(h, true, 1);
        assert(N::dimension(Cheese) == 1);
        for(std::size_t i = 0; i < N::dimension(Cheese); ++i)
            assert(N::array_size(Cheese)[i] == h[i]);
        N::destroy(Cheese);
    }

    {   /**
        std::size_t h[3] = {1,2,3};
        std::size_t m[3] = {0,1,1};
        N::S Cheese;
        N::init(&Cheese,h, true, 3);
        assert(N::read_symbol(&Cheese,m));
        **/
        std::size_t h[3] = {3,2,1};
        N::S_t Cheese = N::init(h, true, 3);
        std::size_t p[3];
        for(std::size_t i = 0; i < 1; ++i) {
            p[2] = i;
            for(std::size_t j = 0; j < 2; ++j) {
                p[1] = j;
                for(std::size_t k = 0; k < 3; ++k) {
                    p[0] = k;
                    N::rec_symbol(Cheese, false,p);
                }
            }
        }
        for(std::size_t i = 0; i < 1; ++i) {
            p[2] = i;
            for(std::size_t j = 0; j < 2; ++j) {
                p[1] = i;
                for(std::size_t k = 0; k < 3; ++k) {
                    p[0] = k;
                    assert(!N::read_symbol(Cheese, p));
                }
            }
        }
        N::destroy(Cheese);
    }

}
