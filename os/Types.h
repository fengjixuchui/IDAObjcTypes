#ifndef OS_H_
#define OS_H_

#import "../BaseTypes.h"
#import "../Foundation/Types.h"

#ifdef __EA64__
#define __OS_WORKGROUP_ATTR_SIZE__ 60
#define __OS_WORKGROUP_INTERVAL_DATA_SIZE__ 56
#define __OS_WORKGROUP_JOIN_TOKEN_SIZE__ 36
#else
#define __OS_WORKGROUP_ATTR_SIZE__ 60
#define __OS_WORKGROUP_INTERVAL_DATA_SIZE__ 56
#define __OS_WORKGROUP_JOIN_TOKEN_SIZE__ 28
#endif

typedef struct os_log_s *os_log_t;
typedef struct os_activity_s *os_activity_t;
typedef struct os_transaction_s *os_transaction_t;
typedef struct os_activity_scope_state_s *os_activity_scope_state_t;

struct os_workgroup_attr_opaque_s {
    uint32_t sig;
    char opaque[__OS_WORKGROUP_ATTR_SIZE__];
};

struct os_workgroup_interval_data_opaque_s {
    uint32_t sig;
    char opaque[__OS_WORKGROUP_INTERVAL_DATA_SIZE__];
};

struct os_workgroup_join_token_opaque_s {
    uint32_t sig;
    char opaque[__OS_WORKGROUP_JOIN_TOKEN_SIZE__];
};

typedef struct os_workgroup_interval_data_opaque_s os_workgroup_interval_data_s;
typedef struct os_workgroup_interval_data_opaque_s *os_workgroup_interval_data_t;
typedef struct os_workgroup_attr_opaque_s os_workgroup_attr_s;
typedef struct os_workgroup_attr_opaque_s *os_workgroup_attr_t;
typedef struct os_workgroup_max_parallel_threads_attr_s os_workgroup_mpt_attr_s;
typedef struct os_workgroup_max_parallel_threads_attr_s *os_workgroup_mpt_attr_t;
typedef struct os_workgroup_join_token_opaque_s os_workgroup_join_token_s;
typedef struct os_workgroup_join_token_opaque_s *os_workgroup_join_token_t;

typedef struct os_unfair_lock_s {
    uint32_t _os_unfair_lock_opaque;
} os_unfair_lock, *os_unfair_lock_t;

typedef struct os_unfair_recursive_lock_s {
    os_unfair_lock ourl_lock;
    uint32_t ourl_count;
} os_unfair_recursive_lock, *os_unfair_recursive_lock_t;

#ifdef _OS_STATE_API

typedef struct os_state_hints_s {
    unsigned int var0;
    char *var1;
    unsigned int var2;
    unsigned int var3;
} *os_state_hints_t;

typedef struct os_state_data_decoder_s {
    char var0[64];
    char var1[64];
} *os_state_data_decoder_t;

union os_state_unk_stru_1 {
    __int32 var0 : 32;
    unsigned int var1;
};

typedef struct os_state_data_s {
    unsigned int type;
    os_state_unk_stru_1 var1;
    os_state_data_decoder_s var2;
    char osd_title[64];
    unsigned __int8 osd_data[];
} *os_state_data_t;

#endif

typedef NSObject *os_workgroup_t;
typedef os_workgroup_t *os_workgroup_interval_t;

PS_ENUM(uint8_t, os_log_type_t) {
    OS_LOG_TYPE_DEFAULT = 0x00,
    OS_LOG_TYPE_INFO = 0x01,
    OS_LOG_TYPE_DEBUG = 0x02,
    OS_LOG_TYPE_ERROR = 0x10,
    OS_LOG_TYPE_FAULT = 0x11,
};

PS_ENUM(uint32_t, os_activity_flag_t) {
    OS_ACTIVITY_FLAG_DEFAULT = 0,
    OS_ACTIVITY_FLAG_DETACHED = 0x1,
    OS_ACTIVITY_FLAG_IF_NONE_PRESENT = 0x2
};

typedef uint32_t os_unfair_lock_options_t;
typedef uint32_t os_workgroup_index;

typedef uint64_t os_activity_id_t;
typedef uint64_t os_signpost_id_t;

typedef long os_once_t;
typedef os_once_t os_alloc_token_t;

PS_ENUM(uint8_t, os_signpost_type_t) {
    OS_SIGNPOST_EVENT = 0x00,
    OS_SIGNPOST_INTERVAL_BEGIN = 0x01,
    OS_SIGNPOST_INTERVAL_END = 0x02,
};

struct _os_alloc_once_s {
	os_alloc_token_t once;
	void *ptr;
};

typedef void (*os_function_t)(void *);
typedef void (*os_block_t)(void);

#define OS_LOCK_TYPE_STRUCT(type) const struct _os_lock_type_##type##_s
#define OS_LOCK_TYPE_REF(type) _os_lock_type_##type
#define OS_LOCK(type) os_lock_##type##_s
#define OS_LOCK_STRUCT(type) struct OS_LOCK(type)

#define OS_LOCK_DECL(type, size)                                                                                                                                                                                                                         \
    typedef OS_LOCK_STRUCT(type) {                                                                                                                                                                                                                       \
        OS_LOCK_TYPE_STRUCT(type) *const osl_type;                                                                                                                                                                                                       \
        uintptr_t _osl_##type##_opaque[size - 1];                                                                                                                                                                                                        \
    }                                                                                                                                                                                                                                                    \
    OS_LOCK(type)

#define OS_LOCK_T_MEMBER(type) OS_LOCK_STRUCT(type) * _osl_##type

typedef union os_lock {
    OS_LOCK_T_MEMBER(base);
    OS_LOCK_T_MEMBER(unfair);
    OS_LOCK_T_MEMBER(nospin);
    OS_LOCK_T_MEMBER(spin);
    OS_LOCK_T_MEMBER(handoff);
    OS_LOCK_T_MEMBER(eliding);
    OS_LOCK_T_MEMBER(transactional);
} os_lock_t;

typedef struct os_log_pack_s {
    uint64_t olp_continuous_time;
    struct timespec olp_wall_time;
    const void *olp_mh;
    const void *olp_pc;
    const char *olp_format;
    uint8_t olp_data[0];
} os_log_pack_s, *os_log_pack_t;

typedef struct _os_nospin_lock_s *_os_nospin_lock_t;

typedef bool (*_os_log_NSCF_callback)(const void *obj, char *string_value, size_t string_sz, bool *publicData);

#endif