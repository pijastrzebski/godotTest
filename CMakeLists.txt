﻿cmake_minimum_required (VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set project name
project ("godotTestLib")

# Add other projects
add_subdirectory(godot-cpp)

# Add src files
set(SRC_FILES 
  # templates
  src/godotcustomsprite.cpp
  src/godotregistertypes.cpp
  src/godotcustomanimatedsprite.cpp
  src/godotcustomcharacterbody.cpp
  src/godotcustomcontrol.cpp
  src/godotcustomtext.cpp
  src/godotcustombutton.cpp
  # core game components
  src/main.cpp
  src/menu.cpp
  src/title.cpp
  src/startbutton.cpp
  src/optionsbutton.cpp
  src/game.cpp
  src/options.cpp
  src/exitbutton.cpp
  # the bunker game
  src/bunker.cpp
  src/machinegun.cpp
  src/bullet.cpp
  src/enemybuilder.cpp
  src/enemy.cpp
  src/player.cpp
  src/hud.cpp
)

# Add header files
set(HEADER_FILES
  # templates
  src/godotcustomsprite.hpp
  src/godotregistertypes.hpp
  src/godotcustomanimatedsprite.hpp
  src/godotcustomcharacterbody.hpp
  src/godotcustomcontrol.hpp
  src/godotcustomtext.hpp
  src/godotcustombutton.hpp
  # core game components
  src/main.hpp
  src/menu.hpp
  src/title.hpp
  src/startbutton.hpp
  src/optionsbutton.hpp
  src/game.hpp
  src/options.hpp
  src/exitbutton.hpp
  # the bunker game
  src/bunker.hpp
  src/machinegun.hpp
  src/bullet.hpp
  src/enemybuilder.hpp
  src/enemy.hpp
  src/player.hpp
  src/hud.hpp
)


# Add executable target
add_library (godotTestLib STATIC ${SRC_FILES} ${HEADER_FILES})

# Build the godot-cpp extension dll
add_custom_command(
    TARGET godotTestLib
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running SCons script..."
    COMMAND cmd /c "${CMAKE_SOURCE_DIR}/run_scons"
    COMMENT "Running SCons after building godotTestLib"
)

# Set target properties
set_target_properties(godotTestLib PROPERTIES 
  VERSION 1.0
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
)

# Link libraries
target_link_libraries(godotTestLib godot-cpp)

# Add precompiled header
target_precompile_headers(godotTestLib PRIVATE src/pch.hpp)
