#ifndef LAB_02_HOUSE_HPP
#define LAB_02_HOUSE_HPP

#define RING_POINTS_COUNT               100
#define TETRAGON_NODES_COUNT            4
#define LINE_NODES_COUNT                2


struct point
{
    double x;
    double y;
};

struct tetragon
{
    struct point nodes[TETRAGON_NODES_COUNT];
};

struct line
{
    struct point nodes[LINE_NODES_COUNT];
};

struct ring
{
    struct point nodes[RING_POINTS_COUNT];
};

struct house
{
    struct tetragon roof;
    struct tetragon walls;
    struct tetragon door;
    struct tetragon handle;
    struct ring window;
    struct line grating_hor;
    struct line grating_ver;
    struct line ground;
};

#endif //LAB_02_HOUSE_HPP
