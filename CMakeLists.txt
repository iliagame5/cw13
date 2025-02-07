cmake_minimum_required(VERSION 3.10)

project(cw13)

set(CMAKE_C_STANDARD 99)

add_executable(cw13 10.5.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -march=native")

find_package(Gnuplot)
find_package(TEX REQUIRED)

add_custom_command(TARGET cw13 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Generating plot using Gnuplot"
    COMMAND gnuplot plot.gpi
    COMMAND ${CMAKE_COMMAND} -E echo "Generating PDF using pdflatex"
    COMMAND pdflatex art.tex
)
