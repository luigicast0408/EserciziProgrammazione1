cmake_minimum_required(VERSION 3.26)
project(C_code C)

set(CMAKE_C_STANDARD 11)

add_executable(C_code
        7_00_var.c
        7_01_char.c
        7_01_float_h.c
        7_01_int.c
        7_01_sizeof.c
        7_01_unary_op.c
        7_02_precision.c
        7_03_overflow.c
        7_04_casting.c
        7_04_constMath.c
        7_04_inf.c
        7_04_macro.c)

