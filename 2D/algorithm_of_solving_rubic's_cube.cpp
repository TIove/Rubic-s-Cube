#include "algorithm_of_solving_rubic's_cube.h"

void Solution_of_Rubics_cube::reverse_forward_0_1_box(Cube &cube, char color_1, char color_2) {
    if (cube.get_forward_matrix()[0][1] == color_1 && cube.get_up_matrix()[2][1] == color_2) {
        cube.enter_commands_for_cube({'f', 'U', 'r', 'u'});
    }
}

void Solution_of_Rubics_cube::find_side_box(Cube &cube, char color_1, char color_2) {
    if (cube.get_forward_matrix()[0][1] == color_1 && cube.get_up_matrix()[2][1] == color_2) {
        cube.enter_commands_for_cube({'f', 'U', 'r', 'u'});
        return;
    }

    if ((cube.get_left_matrix()[0][1] == color_1 && cube.get_up_matrix()[1][0] == color_2) ||
        (cube.get_left_matrix()[0][1] == color_2 && cube.get_up_matrix()[1][0] == color_1)) {

        cube.enter_commands_for_cube({'L', 'L', 'd', 'l', 'l', 'F', 'F'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }

    if ((cube.get_back_matrix()[0][1] == color_1 && cube.get_up_matrix()[0][1] == color_2) ||
        (cube.get_back_matrix()[0][1] == color_2 && cube.get_up_matrix()[0][1] == color_1)) {
        cube.enter_commands_for_cube({'U', 'L', 'L', 'd', 'l', 'l', 'u', 'F', 'F'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }
    if ((cube.get_right_matrix()[0][1] == color_1 && cube.get_up_matrix()[1][2] == color_2) ||
        (cube.get_right_matrix()[0][1] == color_2 && cube.get_up_matrix()[1][2] == color_1)) {
        cube.enter_commands_for_cube({'U', 'U', 'L', 'L', 'd', 'l', 'l', 'u', 'u', 'F', 'F'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }

    if ((cube.get_forward_matrix()[1][0] == color_1 && cube.get_left_matrix()[1][2] == color_2) ||
        (cube.get_forward_matrix()[1][0] == color_2 && cube.get_left_matrix()[1][2] == color_1)) {
        cube.enter_commands_for_cube({'f'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }
    if ((cube.get_left_matrix()[1][0] == color_1 && cube.get_back_matrix()[1][2] == color_2) ||
        (cube.get_left_matrix()[1][0] == color_2 && cube.get_back_matrix()[1][2] == color_1)) {
        cube.enter_commands_for_cube({'L', 'd', 'l', 'f', 'f'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }

    if ((cube.get_right_matrix()[1][2] == color_1 && cube.get_back_matrix()[1][0] == color_2) ||
        (cube.get_right_matrix()[1][2] == color_2 && cube.get_back_matrix()[1][0] == color_1)) {
        cube.enter_commands_for_cube({'r', 'D', 'R', 'f', 'f'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }
    if ((cube.get_right_matrix()[1][2] == color_1 && cube.get_back_matrix()[1][0] == color_2) ||
        (cube.get_right_matrix()[1][2] == color_2 && cube.get_back_matrix()[1][0] == color_1)) {
        cube.enter_commands_for_cube({'r', 'D', 'R', 'f', 'f'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }
    if ((cube.get_forward_matrix()[1][2] == color_1 && cube.get_right_matrix()[1][0] == color_2) ||
        (cube.get_forward_matrix()[1][2] == color_2 && cube.get_right_matrix()[1][0] == color_1)) {
        cube.enter_commands_for_cube({'F'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }

    if ((cube.get_down_matrix()[0][1] == color_1 && cube.get_forward_matrix()[2][1] == color_2) ||
        (cube.get_down_matrix()[0][1] == color_2 && cube.get_forward_matrix()[2][1] == color_1)) {
        cube.enter_commands_for_cube({'f', 'f'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }
    if ((cube.get_down_matrix()[1][0] == color_1 && cube.get_left_matrix()[2][1] == color_2) ||
        (cube.get_down_matrix()[1][0] == color_2 && cube.get_left_matrix()[2][1] == color_1)) {
        cube.enter_commands_for_cube({'d', 'f', 'f'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }
    if ((cube.get_down_matrix()[2][1] == color_1 && cube.get_back_matrix()[2][1] == color_2) ||
        (cube.get_down_matrix()[2][1] == color_2 && cube.get_back_matrix()[2][1] == color_1)) {
        cube.enter_commands_for_cube({'d', 'd', 'f', 'f'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }
    if ((cube.get_down_matrix()[1][2] == color_1 && cube.get_right_matrix()[2][1] == color_2) ||
        (cube.get_down_matrix()[1][2] == color_2 && cube.get_right_matrix()[2][1] == color_1)) {
        cube.enter_commands_for_cube({'D', 'f', 'f'});
        reverse_forward_0_1_box(cube, color_1, color_2);
        return;
    }
}

void Solution_of_Rubics_cube::solve_corner(Cube &cube, char color_1, char color_2, char color_3) {
    for (int i = 0; i < 3; ++i) {
        char a = cube.get_forward_matrix()[2][2];
        char b = cube.get_right_matrix()[2][0];
        char c = cube.get_down_matrix()[0][2];
        if ((a == color_1 && b == color_2 && c == color_3) || (a == color_1 && b == color_3 && c == color_2) ||
            (a == color_2 && b == color_1 && c == color_3) || (a == color_2 && b == color_3 && c == color_1) ||
            (a == color_3 && b == color_1 && c == color_2) || (a == color_3 && b == color_2 && c == color_1)) {
            break;
        }
        cube.rotate_side_down_to_left();
    }
    for (int j = 0; j < 5; ++j) {
        if (!(cube.get_forward_matrix()[0][2] == color_3 && cube.get_right_matrix()[0][0] == color_2
              && cube.get_up_matrix()[2][2] == color_1)) {
            cube.enter_commands_for_cube({'R', 'D', 'r', 'd'});
        }
    }
    cube.change_point_of_view_right();
}

void Solution_of_Rubics_cube::solve_white_line(Cube &cube) {
    if (cube.get_up_matrix()[0][1] == 'W' && cube.get_up_matrix()[2][1] == 'W') {
        cube.rotate_side_up_to_left();
        cube.enter_commands_for_cube({'f', 'r', 'u', 'R', 'U', 'F'});
    }
    if (cube.get_up_matrix()[1][0] == 'W' && cube.get_up_matrix()[1][2] == 'W') {
        cube.enter_commands_for_cube({'f', 'r', 'u', 'R', 'U', 'F'});
    }
}

void Solution_of_Rubics_cube::solve_white_corner(Cube &cube) {
    if (cube.get_up_matrix()[0][1] == 'W') {
        if (cube.get_up_matrix()[1][0] == 'W') {
            cube.enter_commands_for_cube({'f', 'r', 'u', 'R', 'U', 'F'});

        } else if (cube.get_up_matrix()[1][2] == 'W') {
            cube.rotate_side_up_to_left();
            cube.enter_commands_for_cube({'f', 'r', 'u', 'R', 'U', 'F'});

        }
    } else if (cube.get_up_matrix()[2][1] == 'W') {
        if (cube.get_up_matrix()[1][0] == 'W') {
            cube.rotate_side_up_to_left();
            cube.enter_commands_for_cube({'f', 'r', 'u', 'R', 'U', 'F'});

        } else if (cube.get_up_matrix()[1][2] == 'W') {
            cube.rotate_side_up_to_right();
            cube.rotate_side_up_to_right();
            cube.enter_commands_for_cube({'f', 'r', 'u', 'R', 'U', 'F'});

        }
    }
}

void Solution_of_Rubics_cube::find_accord_up_and_side(Cube &cube) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!(cube.get_forward_matrix()[0][1] == cube.get_forward_matrix()[1][1] &&
                  (cube.get_left_matrix()[0][1] == cube.get_left_matrix()[1][1] ||
                   cube.get_right_matrix()[0][1] == cube.get_right_matrix()[1][1]))) {
                cube.rotate_side_up_to_right();
            } else {
                break;
            }
        }
        if (cube.get_forward_matrix()[0][1] == cube.get_forward_matrix()[1][1] &&
            cube.get_left_matrix()[0][1] == cube.get_left_matrix()[1][1]) {
            cube.change_point_of_view_left();
            cube.change_point_of_view_left();
            cube.enter_commands_for_cube({'r', 'u', 'R', 'u', 'r', 'u', 'u', 'R', 'u'});
            return;
        } else if (cube.get_forward_matrix()[0][1] == cube.get_forward_matrix()[1][1] &&
                   cube.get_right_matrix()[0][1] == cube.get_right_matrix()[1][1]) {
            cube.change_point_of_view_left();
            cube.enter_commands_for_cube({'r', 'u', 'R', 'u', 'r', 'u', 'u', 'R', 'u'});
            return;
        } else {
            cube.change_point_of_view_left();
        }
    }
}

bool Solution_of_Rubics_cube::is_correct_place_to_corner(Cube &cube, char color_1, char color_2, char color_3) {
    char a = cube.get_forward_matrix()[0][2];
    char b = cube.get_right_matrix()[0][0];
    char c = cube.get_up_matrix()[2][2];
    return
            (a == color_3 && b == color_1 && c == color_2) ||
            (a == color_3 && b == color_2 && c == color_1) ||
            (a == color_1 && b == color_3 && c == color_2) ||
            (a == color_1 && b == color_2 && c == color_3) ||
            (a == color_2 && b == color_1 && c == color_3) ||
            (a == color_2 && b == color_3 && c == color_1);
}

void Solution_of_Rubics_cube::step_1(Cube &cube) {
    if (cube.get_up_matrix()[1][1] != 'Y') {
        if (cube.get_up_matrix()[1][1] == 'R' || cube.get_up_matrix()[1][1] == 'O' ||
            cube.get_up_matrix()[1][1] == 'G' || cube.get_up_matrix()[1][1] == 'B') {
            if (cube.get_right_matrix()[1][1] == 'Y') {
                cube.change_point_of_view_right();
            } else if (cube.get_left_matrix()[1][1] == 'Y') {
                cube.change_point_of_view_left();
            }
            if (cube.get_forward_matrix()[1][1] == 'Y') {
                cube.change_point_of_view_down();
            } else if (cube.get_back_matrix()[1][1] == 'Y') {
                cube.change_point_of_view_up();
            }
        } else if (cube.get_down_matrix()[1][1] == 'Y') {
            cube.change_point_of_view_up();
            cube.change_point_of_view_up();
        }
    }
    while (cube.get_forward_matrix()[1][1] != 'B') {
        cube.change_point_of_view_right();
    }
    if (cube.get_forward_matrix()[0][1] == 'Y' && cube.get_up_matrix()[2][1] == 'B') {
        cube.enter_commands_for_cube({'f', 'U', 'r', 'u'});
    }
    find_side_box(cube, 'Y', 'B');
    cube.change_point_of_view_right();
    find_side_box(cube, 'Y', 'R');
    cube.change_point_of_view_right();
    find_side_box(cube, 'Y', 'G');
    cube.change_point_of_view_right();
    find_side_box(cube, 'Y', 'O');
    cube.change_point_of_view_right();
}

void Solution_of_Rubics_cube::step_2(Cube &cube) {
    for (int i = 0; i < 4; ++i) {
        char a = cube.get_up_matrix()[2][2];
        char b = cube.get_right_matrix()[0][0];
        char c = cube.get_forward_matrix()[0][2];
        if (a == 'Y' || b == 'Y' || c == 'Y') {
            while (cube.get_forward_matrix()[2][2] == 'Y' || cube.get_right_matrix()[2][0] == 'Y'
                   || cube.get_down_matrix()[0][2] == 'Y') {
                cube.rotate_side_down_to_left();
            }
            cube.enter_commands_for_cube({'R', 'D', 'r', 'd'});
        }
        cube.change_point_of_view_right();
    }
    solve_corner(cube, 'Y', 'R', 'B');
    solve_corner(cube, 'Y', 'G', 'R');
    solve_corner(cube, 'Y', 'O', 'G');
    solve_corner(cube, 'Y', 'B', 'O');
}

void Solution_of_Rubics_cube::step_3(Cube &cube) {
    cube.change_point_of_view_up();
    cube.change_point_of_view_up();

    for (int i = 0; i < 4; ++i) {
        char f_12 = cube.get_forward_matrix()[1][2];
        char f_11 = cube.get_forward_matrix()[1][1];
        char r_10 = cube.get_right_matrix()[1][0];
        char r_11 = cube.get_right_matrix()[1][1];
        if (!((cube.get_forward_matrix()[1][2] == 'W' ||
               cube.get_right_matrix()[1][0] == 'W') &&
              (cube.get_right_matrix()[1][2] == 'W' ||
               cube.get_back_matrix()[1][0] == 'W') &&
              (cube.get_left_matrix()[1][2] == 'W' ||
               cube.get_forward_matrix()[1][0] == 'W') &&
              (cube.get_left_matrix()[1][0] == 'W' ||
               cube.get_back_matrix()[1][2] == 'W'))) {
            if ((f_12 != 'W' && r_10 != 'W') || (f_12 != f_11 || r_10 != r_11)) { //
                for (int j = 0; j < 4; ++j) {
                    if (cube.get_forward_matrix()[0][1] != 'W' && cube.get_up_matrix()[2][1] != 'W') {
                        cube.rotate_side_up_to_right();
                    } else {
                        break;
                    }
                }
                cube.enter_commands_for_cube({'u', 'r', 'U', 'R', 'U', 'F', 'u', 'f'});
            }
        }
        cube.change_point_of_view_right();
    }

    for (int k = 0; k < 8; ++k) {
        for (int i = 0; i < 4; ++i) {
            if (cube.get_forward_matrix()[0][1] != cube.get_forward_matrix()[1][1] ||
                (cube.get_up_matrix()[2][1] != cube.get_left_matrix()[1][1] &&
                 cube.get_right_matrix()[1][1] != cube.get_up_matrix()[2][1])) {
                cube.rotate_side_up_to_right();
            } else {
                break;
            }
        }
        if (cube.get_forward_matrix()[0][1] == cube.get_forward_matrix()[1][1]) {
            if (cube.get_up_matrix()[2][1] == cube.get_left_matrix()[1][1] &&
                (cube.get_left_matrix()[1][2] != cube.get_left_matrix()[1][1] ||
                 cube.get_forward_matrix()[1][0] != cube.get_forward_matrix()[1][1])) {
                cube.enter_commands_for_cube({'U', 'L', 'u', 'l', 'u', 'f', 'U', 'F'});

            } else if (cube.get_right_matrix()[1][1] == cube.get_up_matrix()[2][1] &&
                       (cube.get_right_matrix()[1][0] != cube.get_right_matrix()[1][1] ||
                        cube.get_forward_matrix()[1][2] != cube.get_forward_matrix()[1][1])) {
                cube.enter_commands_for_cube({'u', 'r', 'U', 'R', 'U', 'F', 'u', 'f'});
            }
        }
        cube.change_point_of_view_right();
    }
}

void Solution_of_Rubics_cube::step_4(Cube &cube) {
    if (cube.get_up_matrix()[0][1] == 'W' && cube.get_up_matrix()[2][1] == 'W' &&
        cube.get_up_matrix()[1][0] == 'W' && cube.get_up_matrix()[1][2] == 'W') {
        return;
    }
    int sum = 0;
    if (cube.get_up_matrix()[0][1] == 'W')
        sum++;
    if (cube.get_up_matrix()[1][0] == 'W')
        sum++;
    if (cube.get_up_matrix()[1][2] == 'W')
        sum++;
    if (cube.get_up_matrix()[2][1] == 'W')
        sum++;
    if (sum < 2) {
        cube.enter_commands_for_cube({'f', 'r', 'u', 'R', 'U', 'F'});
        solve_white_corner(cube);
        solve_white_line(cube);
    } else if (sum == 2) {
        solve_white_corner(cube);
        solve_white_line(cube);
    }

    if (!(cube.get_up_matrix()[0][1] == 'W' && cube.get_up_matrix()[1][0] == 'W' &&
          cube.get_up_matrix()[1][2] == 'W' && cube.get_up_matrix()[2][1] == 'W')) {
        cube.enter_commands_for_cube({'f', 'r', 'u', 'R', 'U', 'F'});
        solve_white_corner(cube);
        solve_white_line(cube);
    }
}

void Solution_of_Rubics_cube::step_5(Cube &cube) {
    for (int i = 0; i < 4; ++i) {
        if (cube.get_forward_matrix()[0][1] == cube.get_forward_matrix()[1][1] &&
            cube.get_right_matrix()[0][1] == cube.get_right_matrix()[1][1] &&
            cube.get_left_matrix()[0][1] == cube.get_left_matrix()[1][1] &&
            cube.get_back_matrix()[0][1] == cube.get_back_matrix()[1][1]) {
            return;
        }
        cube.rotate_side_up_to_right();
    }
    find_accord_up_and_side(cube);
    if (cube.get_forward_matrix()[0][1] == cube.get_forward_matrix()[1][1] &&
        cube.get_right_matrix()[0][1] == cube.get_right_matrix()[1][1] &&
        cube.get_left_matrix()[0][1] == cube.get_left_matrix()[1][1] &&
        cube.get_back_matrix()[0][1] == cube.get_back_matrix()[1][1]) {
        return;
    } else {
        cube.enter_commands_for_cube({'r', 'u', 'R', 'u', 'r', 'u', 'u', 'R'});
        find_accord_up_and_side(cube);
        if (!(cube.get_forward_matrix()[0][1] == cube.get_forward_matrix()[1][1] &&
              cube.get_right_matrix()[0][1] == cube.get_right_matrix()[1][1] &&
              cube.get_left_matrix()[0][1] == cube.get_left_matrix()[1][1] &&
              cube.get_back_matrix()[0][1] == cube.get_back_matrix()[1][1])) {
            throw Cube_exception("Cube cannot be solved");
        }
    }
}

void Solution_of_Rubics_cube::step_6(Cube &cube) {
    bool is_correct_corner = false;

    for (int j = 0; j < 4 && !is_correct_corner; ++j) {
        if (is_correct_place_to_corner(cube, cube.get_right_matrix()[1][1],
                                       cube.get_up_matrix()[1][1],
                                       cube.get_forward_matrix()[1][1])) {
            is_correct_corner = true;
            break;
        } else {
            cube.change_point_of_view_right();
        }
    }

    if (!is_correct_corner) {
        cube.enter_commands_for_cube({'u', 'r', 'U', 'L', 'u', 'R', 'U', 'l'});
        for (int j = 0; j < 4; ++j) {
            if (is_correct_place_to_corner(cube, cube.get_right_matrix()[1][1],
                                           cube.get_up_matrix()[1][1],
                                           cube.get_forward_matrix()[1][1])) {
                is_correct_corner = true;
                break;
            } else {
                cube.change_point_of_view_right();
            }
        }
        cube.enter_commands_for_cube({'u', 'r', 'U', 'L', 'u', 'R', 'U', 'l'});
        for (int i = 0; i < 4; ++i) {
            if (!is_correct_place_to_corner(cube, cube.get_right_matrix()[1][1],
                                            cube.get_up_matrix()[1][1],
                                            cube.get_forward_matrix()[1][1])) {
                is_correct_corner = false;
            }
            cube.change_point_of_view_right();
        }
        if (!is_correct_corner) {
            cube.enter_commands_for_cube({'u', 'r', 'U', 'L', 'u', 'R', 'U', 'l'});
        }
    } else {
        cube.enter_commands_for_cube({'u', 'r', 'U', 'L', 'u', 'R', 'U', 'l'});
        for (int i = 0; i < 4; ++i) {
            if (!is_correct_place_to_corner(cube, cube.get_right_matrix()[1][1],
                                            cube.get_up_matrix()[1][1],
                                            cube.get_forward_matrix()[1][1])) {
                is_correct_corner = false;
            }
            cube.change_point_of_view_right();
        }
        if (!is_correct_corner) {
            cube.enter_commands_for_cube({'u', 'r', 'U', 'L', 'u', 'R', 'U', 'l'});
        }
    }
}

void Solution_of_Rubics_cube::step_7(Cube &cube) {
    for (int k = 0; k < 4; ++k) {
        char a = cube.get_forward_matrix()[0][2];
        char b = cube.get_right_matrix()[0][0];
        char c = cube.get_up_matrix()[2][2];
        if (a == cube.get_forward_matrix()[1][1] && b == cube.get_right_matrix()[1][1] &&
            c == cube.get_up_matrix()[1][1]) {
            cube.change_point_of_view_right();
        } else {
            break;
        }
        if (k == 3) {
            return;
        }
    }

    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 5; ++i) {
            if (cube.get_forward_matrix()[0][2] == cube.get_forward_matrix()[0][1] &&
                cube.get_right_matrix()[0][0] == cube.get_right_matrix()[0][1] &&
                cube.get_up_matrix()[2][2] == cube.get_up_matrix()[1][1]) {
                cube.rotate_side_up_to_right();
                break;
            }
            cube.enter_commands_for_cube({'R', 'D', 'r', 'd'});
            if (cube.get_forward_matrix()[0][2] == cube.get_forward_matrix()[0][1] &&
                cube.get_right_matrix()[0][0] == cube.get_right_matrix()[0][1] &&
                cube.get_up_matrix()[2][2] == cube.get_up_matrix()[1][1]) {
                cube.rotate_side_up_to_right();
                break;
            }
        }
    }
    if (!cube.check_status()) {
        throw Cube_exception("Cube wasn't solved");
    }
}



