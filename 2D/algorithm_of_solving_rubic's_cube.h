#pragma once
#include "cube.h"
#include <vector>

class Solution_of_Rubics_cube {
private:
    static void reverse_forward_0_1_box(Cube& cube, char color_1, char color_2);

    static void find_side_box(Cube& cube, char color_1, char color_2);

    static void solve_corner(Cube& cube, char color_1, char color_2, char color_3);

    static void solve_white_line(Cube& cube);

    static void solve_white_corner(Cube& cube);

    static void find_accord_up_and_side(Cube& cube);

    static bool is_correct_place_to_corner(Cube& cube, char color_1, char color_2, char color_3);

    static void step_1(Cube& cube);

    static void step_2(Cube& cube);

    static void step_3(Cube& cube);

    static void step_4(Cube& cube);

    static void step_5(Cube& cube);

    static void step_6(Cube& cube);

    static void step_7(Cube& cube);
public:
    static void solve(Cube& cube) {
        step_1(cube);
        step_2(cube);
        step_3(cube);
        step_4(cube);
        step_5(cube);
        step_6(cube);
        step_7(cube);
    }
};
