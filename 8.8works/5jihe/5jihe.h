#ifndef VECTOR3F_H
#define VECTOR3F_H

// 定义三维向量结构体
typedef struct {
    float x;
    float y;
    float z;
} vector3f;

// 向量加法
vector3f vector_add(vector3f v1, vector3f v2);

// 向量减法
vector3f vector_subtract(vector3f v1, vector3f v2);

// 向量点乘
float vector_dot(vector3f v1, vector3f v2);

// 向量单位化
vector3f vector_normalize(vector3f v);

// 计算向量的模长
float vector_magnitude(vector3f v);

// 向量与标量的乘法
vector3f vector_scale(vector3f v, float scalar);

// 计算点到直线的距离
float point_to_line_distance(vector3f point, vector3f line_start, vector3f line_end);

// 计算点到平面的距离
float point_to_plane_distance(vector3f point, vector3f plane_point, vector3f plane_normal);

#endif
