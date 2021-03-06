# CUSTOM output executable and lib files
DEFAULT_TARGET :=		debug
TARGET_EXEC :=			knapsack
TARGET_LIB :=
HEADER_EXT :=			.hpp
SOURCE_EXT :=			.cpp

# CUSTOM paths
INC_DIRS :=
INC_EXT_DIRS :=
FORMAT_INC_DIRS :=
SRC_DIRS :=
TEST_SRC_DIRS :=
FORMAT_SRC_DIRS :=		src
MAIN_SRC :=			src/main.cpp
LIB_DIRS :=
ROOT_BUILD_DIR :=		build

# CUSTOM libs for different targets
RELEASE_LIBS :=
STATIC_LIBS :=			$(RELEASE_LIBS)
LIBRARY_LIBS :=			$(RELEASE_LIBS)
DEBUG_LIBS :=			$(RELEASE_LIBS)
PROFILE_LIBS :=			$(RELEASE_LIBS)
TEST_LIBS :=			$(RELEASE_LIBS)

# finally, include the generic makefile
include ext/Makefile.inc
