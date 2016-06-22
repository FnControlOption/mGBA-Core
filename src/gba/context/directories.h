/* Copyright (c) 2013-2015 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef DIRECTORIES_H
#define DIRECTORIES_H

#include "util/common.h"

#if !defined(MINIMAL_CORE) || MINIMAL_CORE < 2
struct VDir;

struct GBADirectorySet {
	struct VDir* base;
	struct VDir* archive;
	struct VDir* save;
	struct VDir* patch;
	struct VDir* state;
	struct VDir* screenshot;
};

void GBADirectorySetInit(struct GBADirectorySet* dirs);
void GBADirectorySetDeinit(struct GBADirectorySet* dirs);

void GBADirectorySetAttachBase(struct GBADirectorySet* dirs, struct VDir* base);
void GBADirectorySetDetachBase(struct GBADirectorySet* dirs);

struct VFile* GBADirectorySetOpenPath(struct GBADirectorySet* dirs, const char* path, bool (*filter)(struct VFile*));

struct GBAOptions;
void GBADirectorySetMapOptions(struct GBADirectorySet* dirs, const struct GBAOptions* opts);
#endif

#endif
