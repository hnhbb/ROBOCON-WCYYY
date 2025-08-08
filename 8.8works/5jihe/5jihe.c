#include "5jihe.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 向量加法
vector3f vector_add(vector3f v1, vector3f v2) {
    vector3f result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

// 向量减法
vector3f vector_subtract(vector3f v1, vector3f v2) {
    vector3f result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

// 向量点乘
float vector_dot(vector3f v1, vector3f v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// 向量单位化
vector3f vector_normalize(vector3f v) {
    float magnitude = vector_magnitude(v);
    vector3f result;
    result.x = v.x / magnitude;
    result.y = v.y / magnitude;
    result.z = v.z / magnitude;
    return result;
}

// 计算向量的模长
float vector_magnitude(vector3f v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// 向量与标量的乘法
vector3f vector_scale(vector3f v, float scalar) {
    vector3f result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;
    return result;
}

// 计算点到直线的距离
float point_to_line_distance(vector3f point, vector3f line_start, vector3f line_end) {
    vector3f line_dir = vector_subtract(line_end, line_start);
    vector3f point_dir = vector_subtract(point, line_start);
    float t = vector_dot(point_dir, line_dir) / vector_dot(line_dir, line_dir);
    vector3f projection = vector_add(line_start, vector_scale(line_dir, t));
    vector3f distance_vector = vector_subtract(point, projection);
    return vector_magnitude(distance_vector);
}

// 计算点到平面的距离
float point_to_plane_distance(vector3f point, vector3f plane_point, vector3f plane_normal) {
    vector3f point_dir = vector_subtract(point, plane_point);
    float distance = vector_dot(point_dir, plane_normal) / vector_magnitude(plane_normal);
    return fabs(distance);
}

int main() {
    // 直接在程序中定义点 A, B, C, E, F
    vector3f A = {1.0, 0.0, 1.0};
    vector3f B = {1.0, 1.0, 1.0};
    vector3f C = {0.0, 1.0, 1.0};
    vector3f E = {1.0, 0.5, 0.0}; 
    vector3f F = {1.0, 0.5, 1.0}; 

    // 求点 B 到直线 AC 的距离
    float distance_B_to_AC = point_to_line_distance(B, A, C);
    printf("点 B 到直线 AC 的距离: %f\n", distance_B_to_AC);

    // 求点 F 到平面 AEC 的距离
    // AEC平面的法向量
    vector3f plane_normal = vector_normalize(vector_add(vector_subtract(E, A), vector_subtract(C, A)));
    float distance_F_to_AEC = point_to_plane_distance(F, A, plane_normal);
    printf("点 F 到平面 AEC 的距离: %f\n", distance_F_to_AEC);

    return 0;
}
