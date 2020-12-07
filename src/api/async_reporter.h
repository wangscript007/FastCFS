/*
 * Copyright (c) 2020 YuQing <384681@qq.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _FCFS_API_ASYNC_REPORTER_H
#define _FCFS_API_ASYNC_REPORTER_H

#include "fastcommon/fc_queue.h"
#include "fcfs_api_types.h"

typedef struct {
    FCFSAPIContext *fcfs_api_ctx;
    struct fc_queue queue;
} AsyncReporterContext;

#ifdef __cplusplus
extern "C" {
#endif

    extern AsyncReporterContext g_async_reporter_ctx;

    int async_reporter_init(FCFSAPIContext *fcfs_api_ctx);

    void async_reporter_terminate();

#define async_reporter_push(task)  \
        fc_queue_push(&g_async_reporter_ctx.queue, task);

#ifdef __cplusplus
}
#endif

#endif
