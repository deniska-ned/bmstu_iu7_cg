#include "picture.hpp"

#include <array>
#include <cassert>
#include <cmath>

#include "point_transformations.hpp"

#define MAX_HOUSES_COUNT                10

static std::array<struct house, MAX_HOUSES_COUNT> houses;
static std::size_t houses_cur_i;
static std::size_t houses_len;

void pic_push(struct house house)
{
    if (houses_cur_i == MAX_HOUSES_COUNT - 1)
    {
        for (std::size_t i = 0; i < MAX_HOUSES_COUNT - 1; ++i)
        {
            houses[i] = houses[i + 1];
        }

        houses[MAX_HOUSES_COUNT - 1] = house;

        assert(houses_len == MAX_HOUSES_COUNT);
        assert(houses_cur_i == MAX_HOUSES_COUNT - 1);

        return;
    }

    ++houses_cur_i;
    houses_len = houses_cur_i + 1;
    houses[houses_cur_i] = house;
}

bool pic_goto_next()
{
    if (houses_cur_i == houses_len - 1)
    {
        return false;
    }

    ++houses_cur_i;

    return true;
}

bool pic_goto_prev()
{
    if (0 == houses_cur_i)
    {
        return false;
    }

    --houses_cur_i;

    return true;
}

struct house pic_get_curr()
{
    return houses[houses_cur_i];
}


void pic_init()
{
    struct house house{};

    house.roof.nodes[0] = {6, 4};
    house.roof.nodes[1] = {7, 1};
    house.roof.nodes[2] = {-7, 1};
    house.roof.nodes[3] = {-6, 4};

    house.walls.nodes[0] = {6, 1};
    house.walls.nodes[1] = {6, -4};
    house.walls.nodes[2] = {-6, -4};
    house.walls.nodes[3] = {-6, 1};

    house.door.nodes[0] = {-1, 0};
    house.door.nodes[1] = {-1, -4};
    house.door.nodes[2] = {-4, -4};
    house.door.nodes[3] = {-4, 0};

    house.handle.nodes[0] = {-1.3, -1.3};
    house.handle.nodes[1] = {-1.3, -2.6};
    house.handle.nodes[2] = {-1.6, -2.6};
    house.handle.nodes[3] = {-1.6, -1.3};

    const struct point center = {3, -2};
    const double radius = 1.0;
    for (unsigned i = 0; i < RING_POINTS_COUNT; ++i)
    {
        double angle = ((double) i) / RING_POINTS_COUNT * 2 * M_PI;
        double x = radius * cos(angle) + center.x;
        double y = radius * sin(angle) + center.y;
        house.window.nodes[i] = {x, y};
    }
    house.grating_hor.nodes[0] = {center.x - radius, center.y};
    house.grating_hor.nodes[1] = {center.x + radius, center.y};

    house.grating_ver.nodes[0] = {center.x, center.y - radius};
    house.grating_ver.nodes[1] = {center.x, center.y + radius};

    house.ground.nodes[0] = {8, -4};
    house.ground.nodes[1] = {-8, -4};

    houses_cur_i = 0;
    houses_len = 1;
    houses[houses_cur_i] = house;
}

void pic_destroy() {}

#define FOR_EACH_HOUSE_POINT(func_name, ...) \
do { \
for (auto & node : house.roof.nodes)        { func_name(node, __VA_ARGS__); } \
for (auto & node : house.walls.nodes)       { func_name(node, __VA_ARGS__); } \
for (auto & node : house.door.nodes)        { func_name(node, __VA_ARGS__); } \
for (auto & node : house.handle.nodes)      { func_name(node, __VA_ARGS__); } \
for (auto & node : house.window.nodes)      { func_name(node, __VA_ARGS__); } \
for (auto & node : house.ground.nodes)      { func_name(node, __VA_ARGS__); } \
for (auto & node : house.grating_hor.nodes) { func_name(node, __VA_ARGS__); } \
for (auto & node : house.grating_ver.nodes) { func_name(node, __VA_ARGS__); } \
} while (false)

void pic_move(double dx, double dy)
{
    struct house house = houses[houses_cur_i];
    FOR_EACH_HOUSE_POINT(point_move, dx, dy);
    pic_push(house);
}

void pic_scale(struct point center, double kx, double ky)
{
    struct house house = houses[houses_cur_i];
    FOR_EACH_HOUSE_POINT(point_scale, center, kx, ky);
    pic_push(house);
}

void pic_rotate(struct point center, double angle)
{
    struct house house = houses[houses_cur_i];
    FOR_EACH_HOUSE_POINT(point_rotate, center, angle);
    pic_push(house);
}

struct house pic_get()
{
    return houses[houses_cur_i];
}