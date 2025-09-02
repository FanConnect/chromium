// This is generated file. Do not modify directly.

#ifndef GEN_MEDIA_GPU_V4L2_V4L2_STUBS_H_
#define GEN_MEDIA_GPU_V4L2_V4L2_STUBS_H_

#include <map>
#include <string>
#include <vector>

namespace media_gpu_v4l2 {
// Individual module initializer functions.
bool IsV4l2Initialized();
void InitializeV4l2(void* module);
void UninitializeV4l2();

// Enum and typedef for umbrella initializer.
enum StubModules {
  kModuleV4l2 = 0,
  kNumStubModules
};

typedef std::map<StubModules, std::vector<std::string>> StubPathMap;

// Umbrella initializer for all the modules in this stub file.
bool InitializeStubs(const StubPathMap& path_map);
}  // namespace media_gpu_v4l2

#endif  // GEN_MEDIA_GPU_V4L2_V4L2_STUBS_H_
