#ifndef LAB_02_MATRIX_HPP
#define LAB_02_MATRIX_HPP

#include <array>

template<typename T, std::size_t N, std::size_t K, std::size_t M>
std::array<std::array<T, M>, N> matrix_mult(
        std::array<std::array<T, K>, N> m1,
        std::array<std::array<T, M>, K> m2,
        T zero_elem);

#include "matrix_impl.hpp"

#endif //LAB_02_MATRIX_HPP
