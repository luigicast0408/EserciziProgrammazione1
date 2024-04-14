cmake_minimum_required(VERSION 3.26)
project(operatoriLogici C)

set(CMAKE_C_STANDARD 11)

add_executable(maxfra3numeri main.c
        ../while/main.c
        ../for/main.c
        "../../Esercizi slide/E10.2/main.c"
        "../../Esercizi slide/H9.5/main.c"
        "../../Esercizi slide/H10.8/main.c")
