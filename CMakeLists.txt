cmake_minimum_required(VERSION 3.24)
project(Proyecto1_BattleSpace)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto1_BattleSpace main.cpp Menu.cpp Menu.h Facil.cpp Facil.h Medio.cpp Medio.h Player.h Dificil.h Dificil.cpp Player.cpp Bullet.cpp Bullet.h Enemy.cpp Enemy.h EnemyR.h EnemyR.cpp Estrategias.h Estrategias.cpp Collector.h Collector.cpp)

find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)
target_link_libraries(Proyecto1_BattleSpace sfml-graphics sfml-window)

include_directories(/usr/include/libserial/)
target_link_libraries(Proyecto1_BattleSpace serial)
