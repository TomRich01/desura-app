include_directories(
    ${CEF_INCLUDE_DIRS}
)

file (GLOB Sources gcJSBase.cpp)
file (GLOB Common Common.cpp)

set(COMMON_SOURCE ${Common} PARENT_SCOPE)

add_library(gcJSBase STATIC ${Sources})
target_link_libraries(gcJSBase
  util
)
if(WIN32)
  SetSharedRuntime(gcJSBase)
endif()

SET_PROPERTY(TARGET gcJSBase                PROPERTY FOLDER "Common")

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Weffc++")
endif()
