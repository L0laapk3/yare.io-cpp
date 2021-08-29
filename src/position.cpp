
#include "position.h"

#include <math.h>



Position operator+(const Position& u, const Position& v) {
	return { u.x + v.x, u.y + v.y };
}
Position operator-(const Position& u, const Position& v) {
	return { u.x - v.x, u.y - v.y };
}
Position operator*(const Position& u, const float a) {
	return { u.x * a, u.y * a };
}
Position operator*(const float a, const Position& u) {
	return u * a;
}
Position operator/(const Position& u, const float a) {
	return { u.x / a, u.y / a };
}
float dot(const Position& u, const Position& v) {
	return u.x * v.x + u.y * v.y;
}
float norm(const Position& u) {
	return sqrtf(dot(u, u));
}
Position normalize(const Position& u) {
	return u / norm(u);
}
float dist(const Position& u, const Position& v) {
	return norm(u - v);
}
Position inDirection(const Position& u, const Position& v, const float d) {
	return u + normalize(v - u) * d;
}
float atan2(const Position& u) {
	return atan2f(u.y, u.x);
}
Position fromAngle(const float angle) {
	return { cosf(angle), sinf(angle) };
}
Position rot90(const Position& u) {
	return { -u.y, u.x };
}
Position rot90(const Position& u, const Position& dir) {
	auto v = rot90(u);
	return dot(v, { -u.y, u.x }) >= 0 ? v : v * -1;
}