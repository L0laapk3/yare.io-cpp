#pragma once

struct Position {
	float x, y;
};


Position operator+(const Position& u, const Position& v);
Position operator-(const Position& u, const Position& v);
Position operator*(const Position& u, const float a);
Position operator*(const float a, const Position& u);
Position operator/(const Position& u, const float a);
float dot(const Position& u, const Position& v);
float norm(const Position& u);
Position normalize(const Position& u);
float dist(const Position& u, const Position& v);
Position inDirection(const Position& u, const Position& v, const float d);
float atan2(const Position& u);
Position fromAngle(const float angle);
Position rot90(const Position& u);
Position rot90(const Position& u, const Position& dir);
