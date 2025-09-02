// This is generated file. Do not modify directly.

#include "media/gpu/v4l2/v4l2_stubs.h"

#include <dlfcn.h>   // For dlsym, dlopen, RTLD_LAZY.

#include <cstdarg>

#include "base/compiler_specific.h"
#include "base/logging.h"
namespace  {

void LogDlerror(const char* symbol) {
  VLOG(1) << "Couldn't load " << symbol << ", dlerror() says:\n" << dlerror();
}

}  // namespace 

extern "C" {

// Static pointers that will hold the location of the real function
// implementations after the module has been loaded.
static int (*v4l2_close_ptr)(int fd) = nullptr;
static int (*v4l2_ioctl_ptr)(int fd, unsigned long int request, ...) = nullptr;
static int (*v4l2_fd_open_ptr)(int fd, int v4l2_flags) = nullptr;
static void * (*v4l2_mmap_ptr)(void *start, size_t length, int prot, int flags, int fd, int64_t offset) = nullptr;
static int (*v4l2_munmap_ptr)(void *_start, size_t length) = nullptr;

// Stubs that dispatch to the real implementations.
extern int v4l2_close(int fd) __attribute__((weak));
DISABLE_CFI_ICALL
int  v4l2_close(int fd) {
  return v4l2_close_ptr(fd);
}
extern int v4l2_ioctl(int fd, unsigned long int request, ...) __attribute__((weak));
DISABLE_CFI_ICALL
int  v4l2_ioctl(int fd, unsigned long int request, ...) {
  va_list args___;
  va_start(args___, request);
  int ret___ = v4l2_ioctl_ptr(fd, request, va_arg(args___, void*));
  va_end(args___);
  return ret___;
}
extern int v4l2_fd_open(int fd, int v4l2_flags) __attribute__((weak));
DISABLE_CFI_ICALL
int  v4l2_fd_open(int fd, int v4l2_flags) {
  return v4l2_fd_open_ptr(fd, v4l2_flags);
}
extern void * v4l2_mmap(void *start, size_t length, int prot, int flags, int fd, int64_t offset) __attribute__((weak));
DISABLE_CFI_ICALL
void *  v4l2_mmap(void *start, size_t length, int prot, int flags, int fd, int64_t offset) {
  return v4l2_mmap_ptr(start, length, prot, flags, fd, offset);
}
extern int v4l2_munmap(void *_start, size_t length) __attribute__((weak));
DISABLE_CFI_ICALL
int  v4l2_munmap(void *_start, size_t length) {
  return v4l2_munmap_ptr(_start, length);
}

}  // extern "C"


namespace media_gpu_v4l2 {

// Returns true if all stubs have been properly initialized.
bool IsV4l2Initialized() {
  return v4l2_close_ptr &&
         v4l2_ioctl_ptr &&
         v4l2_fd_open_ptr &&
         v4l2_mmap_ptr &&
         v4l2_munmap_ptr;
}

// Initializes the module stubs.
void InitializeV4l2(void* module) {
  const char v4l2_close_name[] = "v4l2_close";
  v4l2_close_ptr =
    reinterpret_cast<int (*)(int fd)>(
      dlsym(module, v4l2_close_name));
  if (!v4l2_close_ptr)
    LogDlerror(v4l2_close_name);
  const char v4l2_ioctl_name[] = "v4l2_ioctl";
  v4l2_ioctl_ptr =
    reinterpret_cast<int (*)(int fd, unsigned long int request, ...)>(
      dlsym(module, v4l2_ioctl_name));
  if (!v4l2_ioctl_ptr)
    LogDlerror(v4l2_ioctl_name);
  const char v4l2_fd_open_name[] = "v4l2_fd_open";
  v4l2_fd_open_ptr =
    reinterpret_cast<int (*)(int fd, int v4l2_flags)>(
      dlsym(module, v4l2_fd_open_name));
  if (!v4l2_fd_open_ptr)
    LogDlerror(v4l2_fd_open_name);
  const char v4l2_mmap_name[] = "v4l2_mmap";
  v4l2_mmap_ptr =
    reinterpret_cast<void * (*)(void *start, size_t length, int prot, int flags, int fd, int64_t offset)>(
      dlsym(module, v4l2_mmap_name));
  if (!v4l2_mmap_ptr)
    LogDlerror(v4l2_mmap_name);
  const char v4l2_munmap_name[] = "v4l2_munmap";
  v4l2_munmap_ptr =
    reinterpret_cast<int (*)(void *_start, size_t length)>(
      dlsym(module, v4l2_munmap_name));
  if (!v4l2_munmap_ptr)
    LogDlerror(v4l2_munmap_name);
}

// Uninitialize the module stubs.  Reset pointers to nullptr.
void UninitializeV4l2() {
  v4l2_close_ptr = nullptr;
  v4l2_ioctl_ptr = nullptr;
  v4l2_fd_open_ptr = nullptr;
  v4l2_mmap_ptr = nullptr;
  v4l2_munmap_ptr = nullptr;
}

}  // namespace media_gpu_v4l2

namespace media_gpu_v4l2 {
typedef std::map<StubModules, void*> StubHandleMap;
static void CloseLibraries(StubHandleMap* stub_handles) {
  for (StubHandleMap::const_iterator it = stub_handles->begin();
       it != stub_handles->end();
       ++it) {
    dlclose(it->second);
  }

  stub_handles->clear();
}
bool InitializeStubs(const StubPathMap& path_map) {
  StubHandleMap opened_libraries;
  for (int i = 0; i < kNumStubModules; ++i) {
    StubModules cur_module = static_cast<StubModules>(i);
    // If a module is missing, we fail.
    StubPathMap::const_iterator it = path_map.find(cur_module);
    if (it == path_map.end()) {
      CloseLibraries(&opened_libraries);
      return false;
    }

    // Otherwise, attempt to dlopen the library.
    const std::vector<std::string>& paths = it->second;
    bool module_opened = false;
    for (std::vector<std::string>::const_iterator dso_path = paths.begin();
         !module_opened && dso_path != paths.end();
         ++dso_path) {
      void* handle = dlopen(dso_path->c_str(), RTLD_LAZY);
      if (handle) {
        module_opened = true;
        opened_libraries[cur_module] = handle;
      } else {
        VLOG(1) << "dlopen(" << dso_path->c_str() << ") failed.";
        if (char *errstr = dlerror()) {
          VLOG(1) << "dlerror() says:\n" << errstr;
        } else {
          VLOG(1) << "dlerror() is nullptr";
        }

      }
    }

    if (!module_opened) {
      CloseLibraries(&opened_libraries);
      return false;
    }
  }

  // Initialize each module if we have not already failed.
  InitializeV4l2(opened_libraries[kModuleV4l2]);

  // Check that each module is initialized correctly.
  // Close all previously opened libraries on failure.
  if (!IsV4l2Initialized()) {
    UninitializeV4l2();
    CloseLibraries(&opened_libraries);
    return false;
  }

  return true;
}

}  // namespace media_gpu_v4l2
