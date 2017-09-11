#include "eh128148.hpp"
#include <iostream>
#include <cstring>
namespace N {

struct S {
    bool* p;
    std::size_t* array;
    std::size_t dim;
};

namespace {

inline std::size_t get_index(const_S_t acme, const std::size_t *coord) {
    std::size_t step = 1;
    std::size_t d = 0;
    for(std::size_t i = 0; i < acme->dim; ++i) {
        d += coord[i] * step;
        step *= acme->array[i];
    }
    return d;
}
}

S_t init(const std::size_t *array, bool symbol, std::size_t dim) {
    S_t acme = new S;
    acme->array = new std::size_t[dim];
    acme->dim = dim;
    std::size_t k = 1;
    for(std::size_t i = 0; i < dim; ++i) {
        k *= array[i];
        acme->array[i] = array[i];
    }
    acme->p = new bool[k];
    memset(acme->p, symbol, k);
    return acme;
}

std::size_t dimension(const_S_t acme) {
    return acme->dim;
}

const std::size_t* array_size(const_S_t acme) {
    return acme->array;
}

void rec_symbol(S_t acme, bool symbol, const std::size_t *coord) {
    acme->p[get_index(acme, coord)] = symbol;
}

bool read_symbol(const_S_t acme, const std::size_t *coord) {
    return acme->p[get_index(acme, coord)];
}

bool compare(const_S_t acme1, const_S_t acme2) {
    std::size_t k = 1;
    if(acme1->dim != acme2->dim)
        return false;
    for(std::size_t i = 0; i < acme1->dim; ++i) {
        if(acme1->array[i] != acme2->array[i])
            return false;
        k *= acme1->array[i];
    }
    return memcmp(acme1->p, acme2->p, k*sizeof(bool)) == 0;
}

void destroy(S_t acme) {
    delete[] acme->p;
    delete[] acme->array;
    delete acme;
}

}
