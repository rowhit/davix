/*
 * This File is part of Davix, The IO library for HTTP based protocols
 * Copyright (C) 2013  Adrien Devresse <adrien.devresse@cern.ch>, CERN
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
*/
#ifndef DAVIX_TYPES_HPP
#define DAVIX_TYPES_HPP


#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <typeinfo>
#include <algorithm>
#include <functional>

#include <stdint.h>
#include <sys/types.h>

#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

#include "davix_config.hpp"
#include "davix_nocopy.hpp"

#ifndef __DAVIX_INSIDE__
#error "Only davix.hpp should be included."
#endif




// type decl
#ifndef DAVIX_EXPORT
#define DAVIX_EXPORT __attribute__((visibility("default")))
#endif

struct Davix_context;
struct Davix_error;

// alias
typedef struct Davix_context* davix_sess_t;
typedef struct Davix_error* davix_error_t;
typedef struct davix_file_desc_s* davix_file_desc_t;
typedef struct davix_auth_st* davix_auth_t;
typedef struct davix_request_params* davix_params_t;

namespace Davix{
    // Davix namespace declaration
    typedef std::vector< std::pair <std::string, std::string> > HeaderVec;

} // Davix


typedef uint64_t dav_off_t;
typedef uint64_t dav_size_t;
typedef int64_t dav_ssize_t;

// block size
#define DAVIX_BLOCK_SIZE 4096
#define DAVIX_MAX_BLOCK_SIZE 16777216



#endif // DAVIX_TYPES_HPP
