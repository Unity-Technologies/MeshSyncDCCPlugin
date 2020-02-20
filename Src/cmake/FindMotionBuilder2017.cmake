# * MOTIONBUILDER2017_INCLUDE_DIR
# * MOTIONBUILDER2017_LIBRARIES

set(CMAKE_PREFIX_PATH
    "/usr/autodesk/MotionBuilder2017/OpenRealitySDK"
    "/opt/autodesk/MotionBuilder2017/OpenRealitySDK"
)

find_path(MOTIONBUILDER2017_INCLUDE_DIR fbsdk/fbsdk.h)
mark_as_advanced(MOTIONBUILDER2017_INCLUDE_DIR)
foreach(MOBU_LIB fbsdk)
    find_file(MOTIONBUILDER2017_${MOBU_LIB}_LIBRARY lib${MOBU_LIB}${CMAKE_SHARED_LIBRARY_SUFFIX} PATH_SUFFIXES lib/linux_64)
    mark_as_advanced(MOTIONBUILDER2017_${MOBU_LIB}_LIBRARY)
    if(MOTIONBUILDER2017_${MOBU_LIB}_LIBRARY)
        list(APPEND MOTIONBUILDER2017_LIBRARIES ${MOTIONBUILDER2017_${MOBU_LIB}_LIBRARY})
    endif()
endforeach()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args("MotionBuilder2017"
    DEFAULT_MSG
    MOTIONBUILDER2017_INCLUDE_DIR
    MOTIONBUILDER2017_LIBRARIES
)
