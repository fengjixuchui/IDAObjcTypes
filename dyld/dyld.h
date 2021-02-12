#import "../BaseTypes.h"
#import "Types.h"

int _dyld_func_lookup(const char *dyld_func_name, void **address);

uint32_t dyld_get_program_sdk_version(void);
uint32_t dyld_get_min_os_version(const struct mach_header *mh);
uint32_t dyld_get_program_min_os_version(void);

intptr_t _dyld_get_image_slide(const struct mach_header *mh);

bool dyld_program_sdk_at_least(dyld_build_version_t version);
bool dyld_has_inserted_or_interposing_libraries(void);
bool _dyld_is_memory_immutable(char *ptr, int64_t unk1);
bool _dyld_find_unwind_sections(void *addr, struct dyld_unwind_sections *info);

const char *dyld_image_path_containing_address(const void *addr);

const struct mach_header *dyld_image_header_containing_address(const void *addr);
