INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SCOPY scopy)

FIND_PATH(
    SCOPY_INCLUDE_DIRS
    NAMES scopy/api.h
    HINTS $ENV{SCOPY_DIR}/include
        ${PC_SCOPY_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SCOPY_LIBRARIES
    NAMES gnuradio-scopy
    HINTS $ENV{SCOPY_DIR}/lib
        ${PC_SCOPY_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SCOPY DEFAULT_MSG SCOPY_LIBRARIES SCOPY_INCLUDE_DIRS)
MARK_AS_ADVANCED(SCOPY_LIBRARIES SCOPY_INCLUDE_DIRS)

