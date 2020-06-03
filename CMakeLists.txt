cmake_minimum_required(VERSION 3.3)
project(Mancala CXX)
include(.cs211/cmake/CMakeLists.txt)

# TODO: PUT ADDITIONAL MODEL .cxx FILES IN THIS LIST:
set(MODEL_SRC
        src/model.cxx
        src/board.cxx)

# TODO: PUT ADDITIONAL NON-MODEL (UI) .cxx FILES IN THIS LIST:
add_program(Mancala
        src/Mancala.cxx
        src/view.cxx
        src/controller.cxx
        ${MODEL_SRC})
target_link_libraries(Mancala ge211)

add_test_program(model_test
        test/model_test.cxx
        ${MODEL_SRC})
target_link_libraries(model_test ge211)

# vim: ft=cmake
