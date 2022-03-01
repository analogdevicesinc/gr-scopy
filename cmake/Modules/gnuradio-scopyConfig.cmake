find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_SCOPY gnuradio-scopy)

FIND_PATH(
    GR_SCOPY_INCLUDE_DIRS
    NAMES gnuradio/scopy/api.h
    HINTS $ENV{SCOPY_DIR}/include
        ${PC_SCOPY_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_SCOPY_LIBRARIES
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

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-scopyTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_SCOPY DEFAULT_MSG GR_SCOPY_LIBRARIES GR_SCOPY_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_SCOPY_LIBRARIES GR_SCOPY_INCLUDE_DIRS)
