include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/code
)

file(GLOB Sources code/*.c )

set_up_32bit_env()

add_executable(desura_bittest ${Sources})

install_internal_tool(desura_bittest)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Weffc++")
endif()
