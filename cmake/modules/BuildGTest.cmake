if(NOT WITH_GMOCK)
	if(MSVC11)
	  set(ADD_CXX_FLAGS "/D_VARIADIC_MAX=10")
	endif()

	ExternalProject_Add(
	  gtest
	  URL "${GTEST_URL}"
	  URL_MD5 ${GTEST_MD5}
	  CMAKE_ARGS -DBUILD_SHARED_LIBS=ON -DCMAKE_CXX_FLAGS=${ADD_CXX_FLAGS} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -Dgtest_force_shared_crt:BOOL=ON
	  BUILD_IN_SOURCE 1
	  INSTALL_COMMAND ""
	)

	ExternalProject_Get_Property(
	  gtest
	  source_dir
	)

	set(GTEST_INCLUDE_DIRS "${source_dir}/include")
	
	if(WIN32)
	  set(GTEST_LIBRARIES "${source_dir}/${CMAKE_BUILD_TYPE}/gtest.lib")
	  set(GTEST_INSTALL_LIBS "${source_dir}/${CMAKE_BUILD_TYPE}/gtest.dll")
	else()
	  set(GTEST_LIBRARIES "${source_dir}/libgtest.so")
	  set(GTEST_INSTALL_LIBS "${source_dir}/libgtest.so")
	endif()

	set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

	install_external_library(gtest ${GTEST_INSTALL_LIBS})
endif()
