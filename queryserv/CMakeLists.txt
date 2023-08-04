CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

SET(qserv_sources
	database.cpp
	dbupdate.cpp
	main.cpp
	queryservconfig.cpp
	worldserver.cpp
)

SET(qserv_headers
	queryservconfig.h
	worldserver.h
)

ADD_EXECUTABLE(queryserv ${qserv_sources} ${qserv_headers})

INSTALL(TARGETS queryserv RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

ADD_DEFINITIONS(-DQSERV)

TARGET_LINK_LIBRARIES(queryserv ${SERVER_LIBS})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

SET(TEST_ID queryserv_tests)
FILE(GLOB_RECURSE TEST_FILES "*_test.cpp" )
ADD_EXECUTABLE(${TEST_ID} ${TEST_FILES})
TARGET_LINK_LIBRARIES(${TEST_ID} gtest gtest_main)
SET_TARGET_PROPERTIES(${TEST_ID} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/tests)
GTEST_DISCOVER_TESTS(${TEST_ID})