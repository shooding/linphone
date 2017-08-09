############################################################################
# CMakeLists.txt
# Copyright (C) 2017  Belledonne Communications, Grenoble France
#
############################################################################
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#
############################################################################

set(LINPHONE_CXX_OBJECTS_PRIVATE_HEADER_FILES
	call/call.h
	chat/chat-room.h
	conference/conference.h
	conference/conference-listener.h
	conference/conference-p.h
	conference/local-conference.h
	conference/params/call-session-params.h
	conference/params/call-session-params-p.h
	conference/params/media-session-params.h
	conference/params/media-session-params-p.h
	conference/participant.h
	conference/remote-conference.h
	conference/session/call-session.h
	conference/session/call-session-p.h
	conference/session/media-session.h
	cpim/cpim.h
	cpim/header/cpim-core-headers.h
	cpim/header/cpim-generic-header.h
	cpim/header/cpim-header-p.h
	cpim/header/cpim-header.h
	cpim/message/cpim-message.h
	cpim/parser/cpim-grammar.h
	cpim/parser/cpim-parser.h
	logger/logger.h
	object/clonable-object.h
	object/clonable-object-p.h
	object/object-p.h
	object/object.h
	object/singleton.h
	utils/content-type.h
	utils/general.h
	utils/utils.h
)

set(LINPHONE_CXX_OBJECTS_SOURCE_FILES
	call/call.cpp
	chat/chat-room.cpp
	conference/conference.cpp
	conference/local-conference.cpp
	conference/params/call-session-params.cpp
	conference/params/media-session-params.cpp
	conference/participant.cpp
	conference/remote-conference.cpp
	conference/session/call-session.cpp
	conference/session/media-session.cpp
	cpim/header/cpim-core-headers.cpp
	cpim/header/cpim-generic-header.cpp
	cpim/header/cpim-header.cpp
	cpim/message/cpim-message.cpp
	cpim/parser/cpim-grammar.cpp
	cpim/parser/cpim-parser.cpp
	logger/logger.cpp
	object/clonable-object.cpp
	object/object.cpp
	utils/content-type.cpp
	utils/utils.cpp
)

set(LINPHONE_CXX_OBJECTS_DEFINITIONS "-DLIBLINPHONE_EXPORTS")
set(LINPHONE_CXX_OBJECTS_INCLUDE_DIRS ${BELR_INCLUDE_DIRS})

set(LINPHONE_PRIVATE_HEADER_FILES)
foreach(header ${LINPHONE_CXX_OBJECTS_PRIVATE_HEADER_FILES})
	list(APPEND LINPHONE_PRIVATE_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/${header}")
endforeach()
set(LINPHONE_PRIVATE_HEADER_FILES ${LINPHONE_PRIVATE_HEADER_FILES} PARENT_SCOPE)

bc_apply_compile_flags(LINPHONE_CXX_OBJECTS_SOURCE_FILES STRICT_OPTIONS_CPP STRICT_OPTIONS_CXX)

if(ENABLE_STATIC)
	add_library(linphone-cxx-objects-static OBJECT ${LINPHONE_CXX_OBJECTS_PRIVATE_HEADER_FILES} ${LINPHONE_CXX_OBJECTS_SOURCE_FILES})
	target_compile_definitions(linphone-cxx-objects-static PRIVATE ${LINPHONE_CXX_OBJECTS_DEFINITIONS})
	target_include_directories(linphone-cxx-objects-static PRIVATE ${LINPHONE_CXX_OBJECTS_INCLUDE_DIRS} ${LINPHONE_INCLUDE_DIRS})
endif()

if(ENABLE_SHARED)
	add_library(linphone-cxx-objects OBJECT ${LINPHONE_CXX_OBJECTS_PRIVATE_HEADER_FILES} ${LINPHONE_CXX_OBJECTS_SOURCE_FILES})
	target_compile_definitions(linphone-cxx-objects PRIVATE ${LINPHONE_CXX_OBJECTS_DEFINITIONS})
	target_include_directories(linphone-cxx-objects PRIVATE ${LINPHONE_CXX_OBJECTS_INCLUDE_DIRS} ${LINPHONE_INCLUDE_DIRS})
	target_compile_options(linphone-cxx-objects PRIVATE "-fPIC")
endif()
