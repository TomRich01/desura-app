include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/code
)

if(DEBUG)
	file(GLOB Sources code/*.cpp)

	add_library(stackwalker SHARED ${Sources})
	install_library(stackwalker)


	SetSharedRuntime(stackwalker)

	target_link_libraries(stackwalker
		DbgHelp
	)
endif()

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Weffc++")
endif()
