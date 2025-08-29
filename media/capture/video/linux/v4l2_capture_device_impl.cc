// Copyright 2018 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/capture/video/linux/v4l2_capture_device_impl.h"

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/poll.h>
#include <unistd.h>

#if BUILDFLAG(USE_LIBV4L2)
// Auto-generated for dlopen libv4l2 libraries
#include "media/gpu/v4l2/v4l2_stubs.h"
#include "third_party/v4l-utils/lib/include/libv4l2.h"

using media_gpu_v4l2::kModuleV4l2;
using media_gpu_v4l2::InitializeStubs;
using media_gpu_v4l2::StubPathMap;

inline static constexpr char kLibV4l2Path[] =
#if defined(__aarch64__)
      "/usr/lib64/libv4l2.so";
#else
      "/usr/lib/libv4l2.so";
#endif
#endif

namespace media {

V4L2CaptureDeviceImpl::~V4L2CaptureDeviceImpl() = default;

V4L2CaptureDeviceImpl::V4L2CaptureDeviceImpl() {
#if BUILDFLAG(USE_LIBV4L2)
  use_libv4l2_ = false;
#endif
}

int V4L2CaptureDeviceImpl::open(const char* device_name, int flags) {
  int fd = ::open64(device_name, flags);
  if (fd < 0)
    return fd;

#if BUILDFLAG(USE_LIBV4L2)
  StubPathMap paths;
  paths[kModuleV4l2].push_back(kLibV4l2Path);

  static bool libv4l2_initialized = InitializeStubs(paths);
  if (libv4l2_initialized && v4l2_fd_open(fd, V4L2_DISABLE_CONVERSION) != -1)
      use_libv4l2_ = true;
#endif
  return fd;
}

int V4L2CaptureDeviceImpl::close(int fd) {
#if BUILDFLAG(USE_LIBV4L2)
  if (use_libv4l2_)
    return v4l2_close(fd);
#endif
  return ::close(fd);
}

int V4L2CaptureDeviceImpl::ioctl(int fd, int request, void* argp) {
#if BUILDFLAG(USE_LIBV4L2)
  if (use_libv4l2_)
    return v4l2_ioctl(fd, request, argp);
#endif
  return ::ioctl(fd, request, argp);
}

void* V4L2CaptureDeviceImpl::mmap(void* start,
                                  size_t length,
                                  int prot,
                                  int flags,
                                  int fd,
                                  off_t offset) {
#if BUILDFLAG(USE_LIBV4L2)
  if (use_libv4l2_)
    return v4l2_mmap(start, length, prot, flags, fd, offset);
#endif
  return ::mmap(start, length, prot, flags, fd, offset);
}

int V4L2CaptureDeviceImpl::munmap(void* start, size_t length) {
#if BUILDFLAG(USE_LIBV4L2)
  if (use_libv4l2_)
    return v4l2_munmap(start, length);
#endif
  return ::munmap(start, length);
}

int V4L2CaptureDeviceImpl::poll(struct pollfd* ufds,
                                unsigned int nfds,
                                int timeout) {
  return ::poll(ufds, nfds, timeout);
}

}  // namespace media
