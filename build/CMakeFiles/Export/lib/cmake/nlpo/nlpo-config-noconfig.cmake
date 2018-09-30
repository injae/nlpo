#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nlpo::nlpo" for configuration ""
set_property(TARGET nlpo::nlpo APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(nlpo::nlpo PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libnlpo.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS nlpo::nlpo )
list(APPEND _IMPORT_CHECK_FILES_FOR_nlpo::nlpo "${_IMPORT_PREFIX}/lib/libnlpo.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
