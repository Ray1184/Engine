/*!
 * File Transform.h
 */


#pragma once

#include <pods/pods.h>
#include <glm/mat4x4.hpp>

namespace hpms
{

    struct Transform
    {
        glm::mat4 matrix;

        Transform(const glm::mat4& jointMatrix) : matrix(jointMatrix)
        {}

        Transform()
        {}

        PODS_SERIALIZABLE(
                1,
                PODS_OPT(matrix[0][0]),
                PODS_OPT(matrix[0][1]),
                PODS_OPT(matrix[0][2]),
                PODS_OPT(matrix[0][3]),
                PODS_OPT(matrix[1][0]),
                PODS_OPT(matrix[1][1]),
                PODS_OPT(matrix[1][2]),
                PODS_OPT(matrix[1][3]),
                PODS_OPT(matrix[2][0]),
                PODS_OPT(matrix[2][1]),
                PODS_OPT(matrix[2][2]),
                PODS_OPT(matrix[2][3]),
                PODS_OPT(matrix[3][0]),
                PODS_OPT(matrix[3][1]),
                PODS_OPT(matrix[3][2]),
                PODS_OPT(matrix[3][3])
        )


    };
}