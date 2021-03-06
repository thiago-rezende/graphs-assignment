/**
 * @file pch.hpp
 * @brief Pre-Compiled Header
 *
 * This file is auto included in all cpp files by cmake
 *
 */

#pragma once

/* StdLib Stuff */
#include <map>
#include <set>
#include <array>
#include <unordered_map>
#include <unordered_set>

#include <iostream>
#include <algorithm>

/* Application Config */
#include "config.h"

/* Platform Detection */
#include "core/platform_detection.h"

/* Horus Logger */
#include "core/logger.h"

/* Horus Assertions */
#include "debug/assert.h"

/* Horus Instrumentation */
#include "debug/instrumentor.h"
