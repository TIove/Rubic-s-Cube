#pragma once

#include <vector>
#include <fstream>
#include <deque>
#include "Exceptions.h"


class Cube {
private:
    std::deque<char> correct_combination_;
    std::vector<std::vector<char>> up_;
    std::vector<std::vector<char>> down_;
    std::vector<std::vector<char>> right_;
    std::vector<std::vector<char>> left_;
    std::vector<std::vector<char>> back_;
    std::vector<std::vector<char>> forward_;
    static void resize(std::vector<std::vector<char>>& vec);
    static void rotate_matrix_left(std::vector<std::vector<char>>& vec);
    static void rotate_matrix_right(std::vector<std::vector<char>>& vec);
    void roll_lineN_left(int N);
    void roll_lineN_right(int N);
    void roll_rowN_up(int N);
    void roll_rowN_down(int N);
public:
    void enter_commands_for_cube(const std::vector<char>& option);
    void random_tangling(int N);

    Cube() = default;

    Cube(Cube const &cube) {
        this->up_ = cube.up_;
        this->down_ = cube.down_;
        this->left_ = cube.left_;
        this->right_ = cube.right_;
        this->forward_ = cube.forward_;
        this->back_ = cube.back_;
    }

    bool check_status();
    bool can_be_solved();

    void input(const std::string& f_in);
    void output(const std::string& f_out);

    void rotate_side_up_to_left();
    void rotate_side_up_to_right();

    void rotate_side_down_to_left();
    void rotate_side_down_to_right();

    void rotate_side_left_to_left();
    void rotate_side_left_to_right();

    void rotate_side_forward_to_left();
    void rotate_side_forward_to_right();

    void rotate_side_right_to_left();
    void rotate_side_right_to_right();

    void change_point_of_view_left();
    void change_point_of_view_right();

    void change_point_of_view_up();
    void change_point_of_view_down();

    std::vector<std::vector<char>> get_up_matrix() {
        return this->up_;
    }
    std::vector<std::vector<char>> get_down_matrix() {
        return this->down_;
    }
    std::vector<std::vector<char>> get_right_matrix() {
        return this->right_;
    }
    std::vector<std::vector<char>> get_left_matrix() {
        return this->left_;
    }
    std::vector<std::vector<char>> get_back_matrix() {
        return this->back_;
    }
    std::vector<std::vector<char>> get_forward_matrix() {
        return this->forward_;
    }
    
    void get_right_answer();
    std::vector <char> get_right_answer_3D ();
};
