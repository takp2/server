CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

SET(eqlogin_sources
	client.cpp
	client_manager.cpp
	config.cpp
	database.cpp
	eq_crypto.cpp
	main.cpp
	server_manager.cpp
	world_server.cpp
)

SET(eqlogin_headers
	client.h
	client_manager.h
	config.h
	database.h
	eq_crypto.h
	login_server.h
	login_structures.h
	options.h
	server_manager.h
	world_server.h
)

ADD_EXECUTABLE(loginserver ${eqlogin_sources} ${eqlogin_headers})

INSTALL(TARGETS loginserver RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

TARGET_LINK_LIBRARIES(loginserver ${SERVER_LIBS})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

SET(TEST_ID loginserver_tests)
FILE(GLOB_RECURSE TEST_FILES "*_test.cpp" )
ADD_EXECUTABLE(${TEST_ID} ${TEST_FILES})
TARGET_LINK_LIBRARIES(${TEST_ID} gtest gtest_main)
SET_TARGET_PROPERTIES(${TEST_ID} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/tests)
GTEST_DISCOVER_TESTS(${TEST_ID})