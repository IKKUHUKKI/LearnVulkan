# CMakeList.txt : CMake project for LearnVulkan, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Define the project
project ("LearnVulkan")

# GLFW Build Configuration
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/glfw")

# Add the project executable
add_executable(LearnVulkan)

# Set the CXX_STANDARD
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LearnVulkan PROPERTY CXX_STANDARD 20)
endif()

# This is useful to get an RESOURCES_PATH in your IDE during development but you should comment this if you compile a release version and uncomment the next line
target_compile_definitions("LearnVulkan" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/") 

# Uncomment this line to setup the ASSETS_PATH macro to the final assets directory when you share the game
#target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources/") 
#add_definitions(-DRESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")


# Add sources to the project
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE MY_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
target_sources("LearnVulkan" 
	PRIVATE ${MY_SOURCES} 
	PRIVATE ${MY_HEADERS}
)

# Add include directories to the project
target_include_directories("LearnVulkan" PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}/include/"
	"${CMAKE_CURRENT_SOURCE_DIR}/deps/vulkan/include/"
)


# Add link libraries to the project
target_link_libraries("LearnVulkan" 
	glfw
	"${CMAKE_CURRENT_SOURCE_DIR}/deps/vulkan/lib/vulkan-1.lib"
)