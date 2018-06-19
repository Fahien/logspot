function(make_test TEST_NAME)
	# Sources
	set(TEST_SOURCES ${LST_TEST_DIR}/${TEST_NAME}.cpp)
	source_group(${TEST_NAME} FILES ${TEST_SOURCES})
	
	# Executable
	add_executable(${TEST_NAME} ${TEST_SOURCES})
	target_include_directories(${TEST_NAME} PUBLIC ${LST_INCLUDE_DIRS})
	set_target_properties(${TEST_NAME} PROPERTIES LINKER_LANGUAGE CXX)
	target_link_libraries(${TEST_NAME} ${LST_LIBRARIES})
	add_test(${TEST_NAME} ${EXECUTABLE_OUTPUT_PATH}/${TEST_NAME})
endfunction(make_test)

make_test(lst-test)
