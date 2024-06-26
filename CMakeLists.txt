cmake_minimum_required(VERSION 3.12)
project(game VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(SOURCES source/main.cpp source/location.cpp source/object.cpp source/item.cpp source/character.cpp source/inventory.cpp source/party.cpp source/fight.cpp source/equipment.cpp 
source/shop.cpp source/merchant.cpp source/quest_giver.cpp source/screen.cpp source/tavern.cpp)
include_directories("include/")
add_executable(game ${SOURCES})
