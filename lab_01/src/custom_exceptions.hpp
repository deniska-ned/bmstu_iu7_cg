#ifndef LAB_01_CUSTOM_EXCEPTIONS_HPP
#define LAB_01_CUSTOM_EXCEPTIONS_HPP

#include <stdexcept>

class qtablewidget_error: public std::runtime_error
{
public:
    int row_i;
    int col_i;

    qtablewidget_error(const int row_i, const int col_i)
        : runtime_error("Incorrect table data"), row_i(row_i), col_i(col_i) {}

protected:
    qtablewidget_error(const char *msg, const int row_i, const int col_i)
            : runtime_error(msg), row_i(row_i), col_i(col_i) {}
};

class qtablewidget_item_empty_error: public qtablewidget_error
{
public:
    qtablewidget_item_empty_error(int row_i, int col_i)
            : qtablewidget_error("Empty table item", row_i, col_i) {}
};

class qtablewidget_invalid_argument_error: public qtablewidget_error
{
public:
    qtablewidget_invalid_argument_error(int row_i, int col_i)
            : qtablewidget_error("Not a number", row_i, col_i) {}
};

class parallel_lines_intersection_error: public std::logic_error
{
public:
    parallel_lines_intersection_error()
            : std::logic_error("Parallel lines dont intersect") {}
};

class no_suitable_triangle_error: public std::runtime_error
{
public:
    no_suitable_triangle_error()
            : std::runtime_error("No suitable triangle found "
                                 "for given rectangle") {}
};

class incorrect_rect_error: public std::invalid_argument
{
public:
    incorrect_rect_error()
            : std::invalid_argument("Incorrect rectangle") {}
};

#endif //LAB_01_CUSTOM_EXCEPTIONS_HPP
