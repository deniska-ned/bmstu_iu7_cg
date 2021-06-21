#ifndef LAB_02_PICTURE_HPP
#define LAB_02_PICTURE_HPP

#include "house.hpp"

void pic_init();
void pic_destroy();
void pic_move(double dx, double dy);
void pic_scale(struct point center, double kx, double ky);
void pic_rotate(struct point center, double angle);
struct house pic_get();

bool pic_goto_next();
bool pic_goto_prev();

#endif //LAB_02_PICTURE_HPP
