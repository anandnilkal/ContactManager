include_directories("${PROJECT_SOURCE_DIR}/Interface/include")
add_library(interface SHARED ${PROJECT_SOURCE_DIR}/Interface/src/ContactData.cpp)
install(TARGETS interface DESTINATION ${PROJECT_SOURCE_DIR}/lib)
