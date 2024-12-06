# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(gamepong)

# Указываем путь к компиляторам
set(CMAKE_CXX_COMPILER "D:/msys64/mingw64/bin/g++.exe")
set(CMAKE_C_COMPILER "D:/msys64/mingw64/bin/gcc.exe")

# Устанавливаем флаги компилятора
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -g")

# Указываем путь для поиска библиотеки SFML
set(SFML_DIR "D:/msys64/mingw64/share/SFML/cmake")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Источники проекта
file(GLOB SOURCES "src/*.cpp")

# Добавляем исполнимый файл
add_executable(${PROJECT_NAME} ${SOURCES})

# Линкуем с SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Указываем дополнительные пути для заголовочных файлов (если нужно)
include_directories(D:/msys64/mingw64/include)

# Указываем дополнительные пути для библиотек (если нужно)
link_directories(D:/msys64/mingw64/lib)
