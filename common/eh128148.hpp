//Лаврентьева А.А. СКБ-161, задача №3.
#include <cstddef>
#ifndef EH128148_HPP
#define EH128148_HPP
namespace N {

using S_t = struct S*;
using const_S_t =const S_t;

// Задание начального состояния: массив с указанным
// числом измерений заданных размеров, заполненный указанным значением.
    S_t init(const std::size_t* array, bool symbol,std::size_t dim);

// Получение числа измерений.
    std::size_t dimension(const_S_t acme);

// Получение размеров массива.
    const std::size_t* array_size(const_S_t acme);

// Запись элемента массива по данным координатам.
    void rec_symbol(S_t acme, bool symbol,const std::size_t* dim);

// Чтение элемента массива по данным координатам.
    bool read_symbol(const_S_t acme,const std::size_t* dim);

// Сравнение двух массивов на идентичность.
    bool compare(const_S_t acme1,const S* acme2);

// Освобождение динамической памяти.
    void destroy(S_t acme);




}
#endif // EH128148_HPP
