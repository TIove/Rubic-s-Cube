#include <iostream>
#include "cube.h"
#include "algorithm_of_solving_rubic's_cube.h"

void Cube::input(const std::string& f_in) {
    this->correct_combination_.clear();
    resize(up_);
    resize(down_);
    resize(right_);
    resize(left_);
    resize(back_);
    resize(forward_);
    std::ifstream in(f_in);
    for (int i = 0; i < 9 * 6; i++) {
        char buf;
        int pos;
        in >> buf;
        in >> pos;
        int it_i = (pos - 1) / 3;
        int it_j = pos - it_i * 3 - 1;
        switch (buf) {
            case 'U':
                in >> up_[it_i][it_j];
                break;
            case 'D':
                in >> down_[it_i][it_j];
                break;
            case 'R':
                in >> right_[it_i][it_j];
                break;
            case 'L':
                in >> left_[it_i][it_j];
                break;
            case 'B':
                in >> back_[it_i][it_j];
                break;
            case 'F':
                in >> forward_[it_i][it_j];
                break;
            default:
                throw Cube_exception("Invalid character in input file");
        }
    }
}

void Cube::output(const std::string &f_out) {
    std::ofstream out(f_out);
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            out << "  ";
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << up_[k][j] << ' ';
        }
        out << '\n';
    }

    for (int l = 0; l < 3; ++l) {
        for (int j = 0; j < 3; ++j) {
            out << left_[l][j] << ' ';
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << forward_[l][j] << ' ';
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << right_[l][j] << ' ';
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << back_[l][j] << ' ';
        }
        out << '\n';
    }

    for (int m = 0; m < 3; ++m) {
        for (int i = 0; i < 3; ++i) {
            out << "  ";
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << down_[m][j] << ' ';
        }
        out << '\n';
    }
}

void Cube::resize(std::vector<std::vector<char>>& vec) {
    vec.resize(3);
    for (int j = 0; j < 3; ++j) {
        vec[j].resize(3, ' ');
    }
}

void Cube::rotate_matrix_right(std::vector<std::vector<char>> &vec) {
    std::vector<std::vector<char>> buf(3, std::vector<char>(3));
    buf = vec;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            vec[i][j] = buf[2 - j][i];
        }
    }
}

void Cube::rotate_matrix_left(std::vector<std::vector<char>> &vec) {
    rotate_matrix_right(vec);
    rotate_matrix_right(vec);
    rotate_matrix_right(vec);
}

void Cube::roll_lineN_left(const int N) {
    std::vector<char> vec(3);
    for (int i = 0; i < 3; ++i) {
        vec[i] = left_[N][i];
    }

    for (int i = 0; i < 3; ++i) {
        left_[N][i] = forward_[N][i];
    }

    for (int i = 0; i < 3; ++i) {
        forward_[N][i] = right_[N][i];
    }

    for (int i = 0; i < 3; ++i) {
        right_[N][i] = back_[N][i];
    }
    for (int i = 0; i < 3; ++i) {
        back_[N][i] = vec[i];
    }
}

void Cube::roll_lineN_right(int N) {
    roll_lineN_left(N);
    roll_lineN_left(N);
    roll_lineN_left(N);
}

void Cube::rotate_side_up_to_left() {
    roll_lineN_left(0);
    rotate_matrix_right(up_);
}

void Cube::rotate_side_up_to_right() {
    roll_lineN_right(0);
    rotate_matrix_left(up_);
}

void Cube::rotate_side_down_to_left() {
    roll_lineN_right(2);
    rotate_matrix_right(down_);
}

void Cube::rotate_side_down_to_right() {
    roll_lineN_left(2);
    rotate_matrix_left(down_);
}

void Cube::roll_rowN_down(int N) {
    std::vector<char> vec(3);
    for (int i = 0; i < 3; ++i) {
        vec[i] = down_[i][N];
    }
    for (int i = 0; i < 3; ++i) {
        down_[i][N] = forward_[i][N];
    }
    for (int i = 0; i < 3; ++i) {
        forward_[i][N] = up_[i][N];
    }
    for (int j = 0; j < 3; ++j) {
        up_[j][N] = back_[2 - j][2 - N];
    }
    for (int i = 0; i < 3; ++i) {
        back_[i][2 - N] = vec[2 - i];
    }
}

void Cube::roll_rowN_up(int N) {
    roll_rowN_down(N);
    roll_rowN_down(N);
    roll_rowN_down(N);
}

void Cube::rotate_side_left_to_left() {
    roll_rowN_up(0);
    rotate_matrix_left(left_);
}

void Cube::rotate_side_left_to_right() {
    rotate_side_left_to_left();
    rotate_side_left_to_left();
    rotate_side_left_to_left();
}

void Cube::rotate_side_forward_to_left() {
    rotate_matrix_left(forward_);
    std::vector<char> vec(3);
    for (int i = 0; i < 3; ++i) {
        vec[i] = up_[2][i];
    }
    for (int j = 0; j < 3; ++j) {
        up_[2][j] = right_[j][0];
    }
    for (int k = 0; k < 3; ++k) {
        right_[k][0] = down_[0][2 - k];
    }
    for (int l = 0; l < 3; ++l) {
        down_[0][l] = left_[l][2];
    }
    for (int m = 0; m < 3; ++m) {
        left_[m][2] = vec[2 - m];
    }
}

void Cube::rotate_side_forward_to_right() {
    rotate_side_forward_to_left();
    rotate_side_forward_to_left();
    rotate_side_forward_to_left();
}

void Cube::rotate_side_right_to_left() {
    rotate_matrix_left(right_);
    roll_rowN_down(2);
}

void Cube::rotate_side_right_to_right() {
    rotate_side_right_to_left();
    rotate_side_right_to_left();
    rotate_side_right_to_left();
}

void Cube::change_point_of_view_right() {
    this->correct_combination_.push_back('C');
    std::vector<std::vector<char>> vec(3, std::vector<char>(3));
    vec = left_;
    left_ = forward_;
    forward_ = right_;
    right_ = back_;
    back_ = vec;
    rotate_matrix_right(up_);
    rotate_matrix_left(down_);
}

void Cube::change_point_of_view_left() {
    this->correct_combination_.push_back('c');
    change_point_of_view_right();
    change_point_of_view_right();
    change_point_of_view_right();
}

void Cube::change_point_of_view_up() {
    std::vector<std::vector<char>> vec(3, std::vector<char>(3));
    rotate_matrix_right(down_);
    rotate_matrix_right(down_);
    vec = down_;
    down_ = forward_;
    forward_ = up_;
    rotate_matrix_right(back_);
    rotate_matrix_right(back_);
    up_ = back_;
    back_ = vec;
    rotate_matrix_right(left_);
    rotate_matrix_left(right_);
}

void Cube::change_point_of_view_down() {
    change_point_of_view_up();
    change_point_of_view_up();
    change_point_of_view_up();
}

void Cube::random_tangling(int N) {
    for (int i = 0; i < N; ++i) {
        int buf = 1 + random() % 13;
        switch (buf) {
            case 1:
                this->rotate_side_up_to_right();
                break;
            case 2:
                this->rotate_side_up_to_left();
                break;
            case 3:
                this->rotate_side_down_to_right();
                break;
            case 4:
                this->rotate_side_down_to_left();
                break;
            case 5:
                this->rotate_side_left_to_right();
                break;
            case 6:
                this->rotate_side_left_to_left();
                break;
            case 7:
                this->rotate_side_forward_to_right();
                break;
            case 8:
                this->rotate_side_forward_to_left();
                break;
            case 9:
                this->rotate_side_right_to_right();
                break;
            case 10:
                this->rotate_side_right_to_left();
                break;
            case 11:
                this->change_point_of_view_right();
                break;
            case 12:
                this->change_point_of_view_left();
                break;
            case 13:
                this->change_point_of_view_down();
                break;
            case 14:
                this->change_point_of_view_up();
                break;
            default:
                break;
        }
    }
}

void Cube::enter_commands_for_cube(const std::vector<char> &option) {
    for (char i : option) {
        this->correct_combination_.push_back(i);
        switch (i) {
            case 'l':
                this->rotate_side_left_to_right();
                break;
            case 'L':
                this->rotate_side_left_to_left();
                break;
            case 'r':
                this->rotate_side_right_to_right();
                break;
            case 'R':
                this->rotate_side_right_to_left();
                break;
            case 'u':
                this->rotate_side_up_to_left();
                break;
            case 'U':
                this->rotate_side_up_to_right();
                break;
            case 'd':
                this->rotate_side_down_to_left();
                break;
            case 'D':
                this->rotate_side_down_to_right();
                break;
            case 'f':
                this->rotate_side_forward_to_right();
                break;
            case 'F':
                this->rotate_side_forward_to_left();
                break;
            default:
                throw Cube_exception("Invalid operand");
        }
    }
}

void Cube::get_right_answer() {
    for (int i = 0; i < this->correct_combination_.size(); ++i) {
        std::cout << this->correct_combination_[i] << ' ';
    }
}

bool Cube::check_status() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (up_[i][j] != up_[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (down_[i][j] != down_[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (left_[i][j] != left_[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (forward_[i][j] != forward_[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (right_[i][j] != right_[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (back_[i][j] != back_[0][0])
                return false;
        }
    }

    return true;
}

bool Cube::can_be_solved() {
    Cube cube(*this);
    try {
        Solution_of_Rubics_cube::solve(cube);
    }catch(Cube_exception& exception) {
        return false;
    }
    return true;
}

std::vector<char> Cube::get_right_answer_3D() {
    std::vector<char> ans;
    for (int i = 0; i < this->correct_combination_.size(); ++i) {
        switch (this->correct_combination_[i]) {
            case 'l':
                ans.push_back('4');
                break;
            case 'L':
                ans.push_back('4');
                ans.push_back('4');
                ans.push_back('4');
                break;
            case 'r':
                ans.push_back('5');
                ans.push_back('5');
                ans.push_back('5');
                break;
            case 'R':
                ans.push_back('5');
                break;
            case 'u':
                ans.push_back('3');
                ans.push_back('3');
                ans.push_back('3');
                break;
            case 'U':
                ans.push_back('3');
                break;
            case 'd':
                ans.push_back('2');
                break;
            case 'D':
                ans.push_back('2');
                ans.push_back('2');
                ans.push_back('2');
                break;
            case 'f':
                ans.push_back('1');
                ans.push_back('1');
                ans.push_back('1');
                break;
            case 'F':
                ans.push_back('1');
                break;
            case 'c':
                ans.push_back('6');
                ans.push_back('6');
                ans.push_back('6');
                ans.push_back('2');
                ans.push_back('3');
                break;
            case 'C':
                ans.push_back('6');
                ans.push_back('2');
                ans.push_back('2');
                ans.push_back('2');
                ans.push_back('3');
                ans.push_back('3');
                ans.push_back('3');
                break;
        }


    }

    return ans;
}



