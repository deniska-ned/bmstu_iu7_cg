template<typename T, std::size_t N, std::size_t K, std::size_t M>
std::array<std::array<T, M>, N> matrix_mult(
        std::array<std::array<T, K>, N> m1,
        std::array<std::array<T, M>, K> m2,
        T zero_elem)
{
    std::array<std::array<T, M>, N> composition;

    for (auto & array: composition)
    {
        for (auto & elem: array)
        {
            elem = zero_elem;
        }
    }

    for (std::size_t row_i = 0; row_i < N; ++row_i)
    {
        for (std::size_t col_i = 0; col_i < M; ++col_i)
        {
            for (std::size_t i = 0; i < K; ++i)
            {
                composition[row_i][col_i] += m1[row_i][i] * m2[i][col_i];
            }
        }
    }

    return composition;
}