INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_AUTOJAM autojam)

FIND_PATH(
    AUTOJAM_INCLUDE_DIRS
    NAMES autojam/api.h
    HINTS $ENV{AUTOJAM_DIR}/include
        ${PC_AUTOJAM_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    AUTOJAM_LIBRARIES
    NAMES gnuradio-autojam
    HINTS $ENV{AUTOJAM_DIR}/lib
        ${PC_AUTOJAM_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(AUTOJAM DEFAULT_MSG AUTOJAM_LIBRARIES AUTOJAM_INCLUDE_DIRS)
MARK_AS_ADVANCED(AUTOJAM_LIBRARIES AUTOJAM_INCLUDE_DIRS)

