#pragma once

#include <iostream>

class Cube_exception : public std::exception {
private:
    char* m_error;
public:
    explicit Cube_exception(char* error)
            : m_error(error) {}
    [[nodiscard]] const char* what() const noexcept override { return m_error; }
};