# Engine project
cmake_minimum_required(VERSION 3.15)
project(HPMSEngine)

set(CMAKE_SHARED_LIBRARY_PREFIX)
set(CMAKE_STATIC_LIBRARY_PREFIX)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "Debug Postfix for lib, samples and tools")
else()
  set(CMAKE_DEBUG_POSTFIX "" CACHE STRING "Debug Postfix for lib, samples and tools")
endif()

include_directories(include)

# Third party
include(Shared.cmake)

install_from_repo(https://github.com/glfw/glfw.git GLFW master TRUE /include/)

install_from_repo(https://github.com/g-truc/glm.git GLM master TRUE /)

install_from_repo(https://github.com/mtrempoltsev/pods.git PODS master FALSE /include/)

set(PHYSFS_BUILD_SHARED OFF CACHE BOOL "Disable physfs shared library" FORCE INCLUDE_DIR)
set(PHYSFS_ARCHIVE_7Z OFF CACHE BOOL "Disable physfs 7Z" FORCE)
set(PHYSFS_ARCHIVE_GRP OFF CACHE BOOL "Disable physfs GRP" FORCE)
set(PHYSFS_ARCHIVE_WAD OFF CACHE BOOL "Disable physfs WAD" FORCE)
set(PHYSFS_ARCHIVE_HOG OFF CACHE BOOL "Disable physfs HOG" FORCE)
set(PHYSFS_ARCHIVE_MVL OFF CACHE BOOL "Disable physfs MVL" FORCE)
set(PHYSFS_ARCHIVE_QPAK OFF CACHE BOOL "Disable physfs QPAK" FORCE)
set(PHYSFS_ARCHIVE_SLB OFF CACHE BOOL "Disable physfs SLB" FORCE)
set(PHYSFS_ARCHIVE_ISO9660 OFF CACHE BOOL "Disable physfs ISO9660" FORCE)
set(PHYSFS_ARCHIVE_VDF OFF CACHE BOOL "Disable physfs VDF" FORCE)
set(PHYSFS_BUILD_TEST OFF CACHE BOOL "Disable physfs VDF" FORCE)

install_from_repo(https://github.com/criptych/physfs.git PHYSFS master TRUE /src/)

set(SOURCES
        src/thirdparty/glad/glad.c
        src/common/FileSystem.cpp
        src/common/Utils.cpp
        src/core/FrustumCullingCalculator.cpp
        src/core/gl/GLFrameBuffer.cpp
        src/core/gl/GLRenderer.cpp
        src/core/gl/GLShader.cpp
        src/core/gl/GLWindow.cpp
        src/core/items/SceneNode.cpp
        src/core/PipelineUtils.cpp
        src/core/ResourceItemsCache.cpp
        src/core/Scene.cpp
        src/core/techniques/R25DPipeline.cpp
        src/core/CGAPIManager.cpp)

add_definitions(-DSTB_IMAGE_IMPLEMENTATION -DSTB_IMAGE_STATIC -DGLM_ENABLE_EXPERIMENTAL)


add_library(HPMSEngine SHARED ${SOURCES})

target_link_libraries(HPMSEngine glfw physfs-static)