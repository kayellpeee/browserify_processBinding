# define V8_INLINE inline
class Value;
template <class T> class Local;
template <class T> class Handle;
template<class T> class PersistentBase;
class Function;
class Object;
class Isolate;
class String;
template<typename T> class ReturnValue;
namespace internal {
  class Arguments;
  class Heap;
  class HeapObject;
  class Isolate;
  class Object;
  template<typename T> class CustomArguments;
  class PropertyCallbackArguments;
  class FunctionCallbackArguments;
  class GlobalHandles;
}
#ifndef _STDDEF_H
#define _STDDEF_H

#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#define __NEED_ptrdiff_t
#define __NEED_size_t
#define __NEED_wchar_t

#if __GNUC__ > 3
#define offsetof(type, member) __builtin_offsetof(type, member)
#else
#define offsetof(type, member) ((size_t)( (char *)&(((type *)0)->member) - (char *)0 ))
#endif

#endif

// -----size_t----


  #define _Addr int
  #define _Int64 long long
  #define _Reg int

  #if __GNUC__ >= 3
  #if defined(__NEED_va_list) && !defined(__DEFINED_va_list)
  typedef __builtin_va_list va_list;
  #define __DEFINED_va_list
  #endif

  #if defined(__NEED___isoc_va_list) && !defined(__DEFINED___isoc_va_list)
  typedef __builtin_va_list __isoc_va_list;
  #define __DEFINED___isoc_va_list
  #endif

  #else
  #if defined(__NEED_va_list) && !defined(__DEFINED_va_list)
  typedef struct __va_list * va_list;
  #define __DEFINED_va_list
  #endif

  #if defined(__NEED___isoc_va_list) && !defined(__DEFINED___isoc_va_list)
  typedef struct __va_list * __isoc_va_list;
  #define __DEFINED___isoc_va_list
  #endif

  #endif

  #ifndef __cplusplus
  #ifdef __WCHAR_TYPE__
  #if defined(__NEED_wchar_t) && !defined(__DEFINED_wchar_t)
  typedef __WCHAR_TYPE__ wchar_t;
  #define __DEFINED_wchar_t
  #endif

  #else
  #if defined(__NEED_wchar_t) && !defined(__DEFINED_wchar_t)
  typedef long wchar_t;
  #define __DEFINED_wchar_t
  #endif

  #endif
  #endif
  #if defined(__NEED_wint_t) && !defined(__DEFINED_wint_t)
  typedef unsigned wint_t;
  #define __DEFINED_wint_t
  #endif


  #if defined(__FLT_EVAL_METHOD__) && __FLT_EVAL_METHOD__ == 0
  #if defined(__NEED_float_t) && !defined(__DEFINED_float_t)
  typedef float float_t;
  #define __DEFINED_float_t
  #endif

  #if defined(__NEED_double_t) && !defined(__DEFINED_double_t)
  typedef double double_t;
  #define __DEFINED_double_t
  #endif

  #else
  #if defined(__NEED_float_t) && !defined(__DEFINED_float_t)
  typedef long double float_t;
  #define __DEFINED_float_t
  #endif

  #if defined(__NEED_double_t) && !defined(__DEFINED_double_t)
  typedef long double double_t;
  #define __DEFINED_double_t
  #endif

  #endif

  #if defined(__NEED_time_t) && !defined(__DEFINED_time_t)
  typedef long time_t;
  #define __DEFINED_time_t
  #endif

  #if defined(__NEED_suseconds_t) && !defined(__DEFINED_suseconds_t)
  typedef long suseconds_t;
  #define __DEFINED_suseconds_t
  #endif


  #if defined(__NEED_pthread_attr_t) && !defined(__DEFINED_pthread_attr_t)
  typedef struct { union { int __i[9]; unsigned __s[9]; } __u; } pthread_attr_t;
  #define __DEFINED_pthread_attr_t
  #endif

  #if defined(__NEED_pthread_mutex_t) && !defined(__DEFINED_pthread_mutex_t)
  typedef struct { union { int __i[6]; void *__p[6]; } __u; } pthread_mutex_t;
  #define __DEFINED_pthread_mutex_t
  #endif

  #if defined(__NEED_pthread_cond_t) && !defined(__DEFINED_pthread_cond_t)
  typedef struct { union { int __i[12]; void *__p[12]; } __u; } pthread_cond_t;
  #define __DEFINED_pthread_cond_t
  #endif

  #if defined(__NEED_pthread_rwlock_t) && !defined(__DEFINED_pthread_rwlock_t)
  typedef struct { union { int __i[8]; void *__p[8]; } __u; } pthread_rwlock_t;
  #define __DEFINED_pthread_rwlock_t
  #endif

  #if defined(__NEED_pthread_barrier_t) && !defined(__DEFINED_pthread_barrier_t)
  typedef struct { union { int __i[5]; void *__p[5]; } __u; } pthread_barrier_t;
  #define __DEFINED_pthread_barrier_t
  #endif

  #if defined(__NEED_size_t) && !defined(__DEFINED_size_t)
  typedef unsigned _Addr size_t;
  #define __DEFINED_size_t
  #endif

  #if defined(__NEED_uintptr_t) && !defined(__DEFINED_uintptr_t)
  typedef unsigned _Addr uintptr_t;
  #define __DEFINED_uintptr_t
  #endif

  #if defined(__NEED_ptrdiff_t) && !defined(__DEFINED_ptrdiff_t)
  typedef _Addr ptrdiff_t;
  #define __DEFINED_ptrdiff_t
  #endif

  #if defined(__NEED_ssize_t) && !defined(__DEFINED_ssize_t)
  typedef _Addr ssize_t;
  #define __DEFINED_ssize_t
  #endif

  #if defined(__NEED_intptr_t) && !defined(__DEFINED_intptr_t)
  typedef _Addr intptr_t;
  #define __DEFINED_intptr_t
  #endif

  #if defined(__NEED_regoff_t) && !defined(__DEFINED_regoff_t)
  typedef _Addr regoff_t;
  #define __DEFINED_regoff_t
  #endif

  #if defined(__NEED_register_t) && !defined(__DEFINED_register_t)
  typedef _Reg register_t;
  #define __DEFINED_register_t
  #endif


  #if defined(__NEED_int8_t) && !defined(__DEFINED_int8_t)
  typedef signed char     int8_t;
  #define __DEFINED_int8_t
  #endif

  #if defined(__NEED_int16_t) && !defined(__DEFINED_int16_t)
  typedef short           int16_t;
  #define __DEFINED_int16_t
  #endif

  #if defined(__NEED_int32_t) && !defined(__DEFINED_int32_t)
  typedef int             int32_t;
  #define __DEFINED_int32_t
  #endif

  #if defined(__NEED_int64_t) && !defined(__DEFINED_int64_t)
  typedef _Int64          int64_t;
  #define __DEFINED_int64_t
  #endif

  #if defined(__NEED_intmax_t) && !defined(__DEFINED_intmax_t)
  typedef _Int64          intmax_t;
  #define __DEFINED_intmax_t
  #endif

  #if defined(__NEED_uint8_t) && !defined(__DEFINED_uint8_t)
  typedef unsigned char   uint8_t;
  #define __DEFINED_uint8_t
  #endif

  #if defined(__NEED_uint16_t) && !defined(__DEFINED_uint16_t)
  typedef unsigned short  uint16_t;
  #define __DEFINED_uint16_t
  #endif

  #if defined(__NEED_uint32_t) && !defined(__DEFINED_uint32_t)
  typedef unsigned int    uint32_t;
  #define __DEFINED_uint32_t
  #endif

  #if defined(__NEED_uint64_t) && !defined(__DEFINED_uint64_t)
  typedef unsigned _Int64 uint64_t;
  #define __DEFINED_uint64_t
  #endif

  #if defined(__NEED_u_int64_t) && !defined(__DEFINED_u_int64_t)
  typedef unsigned _Int64 u_int64_t;
  #define __DEFINED_u_int64_t
  #endif

  #if defined(__NEED_uintmax_t) && !defined(__DEFINED_uintmax_t)
  typedef unsigned _Int64 uintmax_t;
  #define __DEFINED_uintmax_t
  #endif


  #if defined(__NEED_mode_t) && !defined(__DEFINED_mode_t)
  typedef unsigned mode_t;
  #define __DEFINED_mode_t
  #endif

  #if defined(__NEED_nlink_t) && !defined(__DEFINED_nlink_t)
  typedef unsigned _Reg nlink_t;
  #define __DEFINED_nlink_t
  #endif

  #if defined(__NEED_off_t) && !defined(__DEFINED_off_t)
  typedef int off_t;
  #define __DEFINED_off_t
  #endif

  #if defined(__NEED_ino_t) && !defined(__DEFINED_ino_t)
  typedef unsigned int ino_t;
  #define __DEFINED_ino_t
  #endif

  #if defined(__NEED_dev_t) && !defined(__DEFINED_dev_t)
  typedef unsigned int dev_t;
  #define __DEFINED_dev_t
  #endif

  #if defined(__NEED_blksize_t) && !defined(__DEFINED_blksize_t)
  typedef long blksize_t;
  #define __DEFINED_blksize_t
  #endif

  #if defined(__NEED_blkcnt_t) && !defined(__DEFINED_blkcnt_t)
  typedef int blkcnt_t;
  #define __DEFINED_blkcnt_t
  #endif

  #if defined(__NEED_fsblkcnt_t) && !defined(__DEFINED_fsblkcnt_t)
  typedef unsigned int fsblkcnt_t;
  #define __DEFINED_fsblkcnt_t
  #endif

  #if defined(__NEED_fsfilcnt_t) && !defined(__DEFINED_fsfilcnt_t)
  typedef unsigned int fsfilcnt_t;
  #define __DEFINED_fsfilcnt_t
  #endif


  #if defined(__NEED_wctype_t) && !defined(__DEFINED_wctype_t)
  typedef unsigned long wctype_t;
  #define __DEFINED_wctype_t
  #endif


  #if defined(__NEED_timer_t) && !defined(__DEFINED_timer_t)
  typedef void * timer_t;
  #define __DEFINED_timer_t
  #endif

  #if defined(__NEED_clockid_t) && !defined(__DEFINED_clockid_t)
  typedef int clockid_t;
  #define __DEFINED_clockid_t
  #endif

  #if defined(__NEED_clock_t) && !defined(__DEFINED_clock_t)
  typedef long clock_t;
  #define __DEFINED_clock_t
  #endif

  #if defined(__NEED_struct_timeval) && !defined(__DEFINED_struct_timeval)
  struct timeval { time_t tv_sec; suseconds_t tv_usec; };
  #define __DEFINED_struct_timeval
  #endif

  #if defined(__NEED_struct_timespec) && !defined(__DEFINED_struct_timespec)
  struct timespec { time_t tv_sec; long tv_nsec; };
  #define __DEFINED_struct_timespec
  #endif


  #if defined(__NEED_pid_t) && !defined(__DEFINED_pid_t)
  typedef int pid_t;
  #define __DEFINED_pid_t
  #endif

  #if defined(__NEED_id_t) && !defined(__DEFINED_id_t)
  typedef unsigned id_t;
  #define __DEFINED_id_t
  #endif

  #if defined(__NEED_uid_t) && !defined(__DEFINED_uid_t)
  typedef unsigned uid_t;
  #define __DEFINED_uid_t
  #endif

  #if defined(__NEED_gid_t) && !defined(__DEFINED_gid_t)
  typedef unsigned gid_t;
  #define __DEFINED_gid_t
  #endif

  #if defined(__NEED_key_t) && !defined(__DEFINED_key_t)
  typedef int key_t;
  #define __DEFINED_key_t
  #endif

  #if defined(__NEED_useconds_t) && !defined(__DEFINED_useconds_t)
  typedef unsigned useconds_t;
  #define __DEFINED_useconds_t
  #endif


  #ifdef __cplusplus
  #if defined(__NEED_pthread_t) && !defined(__DEFINED_pthread_t)
  typedef unsigned long pthread_t;
  #define __DEFINED_pthread_t
  #endif

  #else
  #if defined(__NEED_pthread_t) && !defined(__DEFINED_pthread_t)
  typedef struct __pthread * pthread_t;
  #define __DEFINED_pthread_t
  #endif

  #endif
  #if defined(__NEED_pthread_once_t) && !defined(__DEFINED_pthread_once_t)
  typedef int pthread_once_t;
  #define __DEFINED_pthread_once_t
  #endif

  #if defined(__NEED_pthread_key_t) && !defined(__DEFINED_pthread_key_t)
  typedef unsigned pthread_key_t;
  #define __DEFINED_pthread_key_t
  #endif

  #if defined(__NEED_pthread_spinlock_t) && !defined(__DEFINED_pthread_spinlock_t)
  typedef int pthread_spinlock_t;
  #define __DEFINED_pthread_spinlock_t
  #endif

  #if defined(__NEED_pthread_mutexattr_t) && !defined(__DEFINED_pthread_mutexattr_t)
  typedef struct { unsigned __attr; } pthread_mutexattr_t;
  #define __DEFINED_pthread_mutexattr_t
  #endif

  #if defined(__NEED_pthread_condattr_t) && !defined(__DEFINED_pthread_condattr_t)
  typedef struct { unsigned __attr; } pthread_condattr_t;
  #define __DEFINED_pthread_condattr_t
  #endif

  #if defined(__NEED_pthread_barrierattr_t) && !defined(__DEFINED_pthread_barrierattr_t)
  typedef struct { unsigned __attr; } pthread_barrierattr_t;
  #define __DEFINED_pthread_barrierattr_t
  #endif

  #if defined(__NEED_pthread_rwlockattr_t) && !defined(__DEFINED_pthread_rwlockattr_t)
  typedef struct { unsigned __attr[2]; } pthread_rwlockattr_t;
  #define __DEFINED_pthread_rwlockattr_t
  #endif


  #if defined(__NEED_FILE) && !defined(__DEFINED_FILE)
  typedef struct _IO_FILE FILE;
  #define __DEFINED_FILE
  #endif


  #if defined(__NEED_locale_t) && !defined(__DEFINED_locale_t)
  typedef struct __locale_struct * locale_t;
  #define __DEFINED_locale_t
  #endif


  #if defined(__NEED_sigset_t) && !defined(__DEFINED_sigset_t)
  typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;
  #define __DEFINED_sigset_t
  #endif


  #if defined(__NEED_struct_iovec) && !defined(__DEFINED_struct_iovec)
  struct iovec { void *iov_base; size_t iov_len; };
  #define __DEFINED_struct_iovec
  #endif


  #if defined(__NEED_socklen_t) && !defined(__DEFINED_socklen_t)
  typedef unsigned socklen_t;
  #define __DEFINED_socklen_t
  #endif

  #if defined(__NEED_sa_family_t) && !defined(__DEFINED_sa_family_t)
  typedef unsigned short sa_family_t;
  #define __DEFINED_sa_family_t
  #endif


  #undef _Addr
  #undef _Int64
  #undef _Reg

// ----Local-----

  template <class T> class Local : public Handle<T> {
   public:
    V8_INLINE Local();
    template <class S> V8_INLINE Local(Local<S> that)
        : Handle<T>(reinterpret_cast<T*>(*that)) {
      /**
       * This check fails when trying to convert between incompatible
       * handles. For example, converting from a Handle<String> to a
       * Handle<Number>.
       */
      // TYPE_CHECK(T, S);
    }


    template <class S> V8_INLINE static Local<T> Cast(Local<S> that) {
  #ifdef V8_ENABLE_CHECKS
      // If we're going to perform the type check then we have to check
      // that the handle isn't empty before doing the checked cast.
      if (that.IsEmpty()) return Local<T>();
  #endif
      return Local<T>(T::Cast(*that));
    }
    template <class S> V8_INLINE Local(Handle<S> that)
        : Handle<T>(reinterpret_cast<T*>(*that)) {
      // TYPE_CHECK(T, S);
    }

    template <class S> V8_INLINE Local<S> As() {
      return Local<S>::Cast(*this);
    }

    /**
     * Create a local handle for the content of another handle.
     * The referee is kept alive by the local handle even when
     * the original handle is destroyed/disposed.
     */
    V8_INLINE static Local<T> New(Isolate* isolate, Handle<T> that);
    V8_INLINE static Local<T> New(Isolate* isolate,
                                  const PersistentBase<T>& that);

   private:
    friend class Utils;
    template<class F> friend class Eternal;
    template<class F> friend class PersistentBase;
    template<class F, class M> friend class Persistent;
    template<class F> friend class Handle;
    template<class F> friend class Local;
    template<class F> friend class FunctionCallbackInfo;
    template<class F> friend class PropertyCallbackInfo;
    friend class String;
    friend class Object;
    friend class Context;
    template<class F> friend class internal::CustomArguments;
    friend class HandleScope;
    friend class EscapableHandleScope;
    template<class F1, class F2, class F3> friend class PersistentValueMap;
    template<class F1, class F2> friend class PersistentValueVector;

    template <class S> V8_INLINE Local(S* that) : Handle<T>(that) { }
    V8_INLINE static Local<T> New(Isolate* isolate, T* that);
  };

// ----FunctionCallbackInfo-----


  template<typename T>
  class FunctionCallbackInfo {
   public:
    V8_INLINE int Length() const;
    V8_INLINE Local<Value> operator[](int i) const;
    V8_INLINE Local<Function> Callee() const;
    V8_INLINE Local<Object> This() const;
    V8_INLINE Local<Object> Holder() const;
    V8_INLINE bool IsConstructCall() const;
    V8_INLINE Local<Value> Data() const;
    V8_INLINE Isolate* GetIsolate() const;
    V8_INLINE ReturnValue<T> GetReturnValue() const;
    // This shouldn't be public, but the arm compiler needs it.
    static const int kArgsLength = 7;

   protected:
    friend class internal::FunctionCallbackArguments;
    friend class internal::CustomArguments<FunctionCallbackInfo>;
    static const int kHolderIndex = 0;
    static const int kIsolateIndex = 1;
    static const int kReturnValueDefaultValueIndex = 2;
    static const int kReturnValueIndex = 3;
    static const int kDataIndex = 4;
    static const int kCalleeIndex = 5;
    static const int kContextSaveIndex = 6;

    V8_INLINE FunctionCallbackInfo(internal::Object** implicit_args,
                     internal::Object** values,
                     int length,
                     bool is_construct_call);
    internal::Object** implicit_args_;
    internal::Object** values_;
    int length_;
    bool is_construct_call_;
  };

// ----HandleScope-------

  class HandleScope {
   public:
    HandleScope(Isolate* isolate);

    ~HandleScope();

    /**
     * Counts the number of allocated handles.
     */
    static int NumberOfHandles(Isolate* isolate);

    V8_INLINE Isolate* GetIsolate() const {
      return reinterpret_cast<Isolate*>(isolate_);
    }

   protected:
    V8_INLINE HandleScope() {}

    void Initialize(Isolate* isolate);

    static internal::Object** CreateHandle(internal::Isolate* isolate,
                                           internal::Object* value);

   private:
    // Uses heap_object to obtain the current Isolate.
    static internal::Object** CreateHandle(internal::HeapObject* heap_object,
                                           internal::Object* value);

    // Make it hard to create heap-allocated or illegal handle scopes by
    // disallowing certain operations.
    HandleScope(const HandleScope&);
    void operator=(const HandleScope&);
    void* operator new(size_t size);
    void operator delete(void*, size_t);

    internal::Isolate* isolate_;
    internal::Object** prev_next_;
    internal::Object** prev_limit_;

    // Local::New uses CreateHandle with an Isolate* parameter.
    template<class F> friend class Local;

    // Object::GetInternalField and Context::GetEmbedderData use CreateHandle with
    // a HeapObject* in their shortcuts.
    friend class Object;
    friend class Context;
  };

// ----uint-----------
  // typedef int32_t int_fast16_t;
  // typedef int32_t int_fast32_t;
  typedef unsigned int    uint32_t;
  // typedef uint32_t uint_fast16_t;
  // typedef uint32_t uint_fast32_t;

  // #define INT_FAST16_MIN  INT32_MIN
  // #define INT_FAST32_MIN  INT32_MIN

  // #define INT_FAST16_MAX  INT32_MAX
  // #define INT_FAST32_MAX  INT32_MAX

  // #define UINT_FAST16_MAX UINT32_MAX
  // #define UINT_FAST32_MAX UINT32_MAX

  // #define INTPTR_MIN      INT32_MIN
  // #define INTPTR_MAX      INT32_MAX
  // #define UINTPTR_MAX     UINT32_MAX
  // #define PTRDIFF_MIN     INT32_MIN
  // #define PTRDIFF_MAX     INT32_MAX
  // #define SIZE_MAX        UINT32_MAX

// -----Environment-----
  #define DISALLOW_COPY_AND_ASSIGN(TypeName)                                    \
    void operator=(const TypeName&);                                            \
    TypeName(const TypeName&)
  class Context;
  class Environment;
  class Environment {
   public:
    class AsyncListener {
     public:
      inline uint32_t* fields();
      inline int fields_count() const;
      inline bool has_listener() const;
      inline uint32_t watched_providers() const;

     private:
      friend class Environment;  // So we can call the constructor.
      inline AsyncListener();

      enum Fields {
        kHasListener,
        kWatchedProviders,
        kFieldsCount
      };

      uint32_t fields_[kFieldsCount];

      DISALLOW_COPY_AND_ASSIGN(AsyncListener);
    };

    class DomainFlag {
     public:
      inline uint32_t* fields();
      inline int fields_count() const;
      inline uint32_t count() const;

     private:
      friend class Environment;  // So we can call the constructor.
      inline DomainFlag();

      enum Fields {
        kCount,
        kFieldsCount
      };

      uint32_t fields_[kFieldsCount];

      DISALLOW_COPY_AND_ASSIGN(DomainFlag);
    };

    class TickInfo {
     public:
      inline uint32_t* fields();
      inline int fields_count() const;
      inline bool in_tick() const;
      inline bool last_threw() const;
      inline uint32_t index() const;
      inline uint32_t length() const;
      inline void set_in_tick(bool value);
      inline void set_index(uint32_t value);
      inline void set_last_threw(bool value);

     private:
      friend class Environment;  // So we can call the constructor.
      inline TickInfo();

      enum Fields {
        kIndex,
        kLength,
        kFieldsCount
      };

      uint32_t fields_[kFieldsCount];
      bool in_tick_;
      bool last_threw_;

      DISALLOW_COPY_AND_ASSIGN(TickInfo);
    };

    static inline Environment* GetCurrent(Isolate* isolate);
    static inline Environment* GetCurrent(Local<Context> context);

    // See CreateEnvironment() in src/node.cc.
    static inline Environment* New(Local<Context> context);
    inline void Dispose();

    // Defined in src/node_profiler.cc.
    void StartGarbageCollectionTracking(Local<Function> callback);
    void StopGarbageCollectionTracking();

    void AssignToContext(Local<Context> context);

    inline Isolate* isolate() const;
    inline uv_loop_t* event_loop() const;
    inline bool has_async_listener() const;
    inline bool in_domain() const;
    inline uint32_t watched_providers() const;

    static inline Environment* from_immediate_check_handle(uv_check_t* handle);
    inline uv_check_t* immediate_check_handle();
    inline uv_idle_t* immediate_idle_handle();

    static inline Environment* from_idle_prepare_handle(uv_prepare_t* handle);
    inline uv_prepare_t* idle_prepare_handle();

    static inline Environment* from_idle_check_handle(uv_check_t* handle);
    inline uv_check_t* idle_check_handle();

    inline AsyncListener* async_listener();
    inline DomainFlag* domain_flag();
    inline TickInfo* tick_info();

    static inline Environment* from_cares_timer_handle(uv_timer_t* handle);
    inline uv_timer_t* cares_timer_handle();
    inline ares_channel cares_channel();
    inline ares_channel* cares_channel_ptr();
    inline ares_task_list* cares_task_list();

    inline bool using_smalloc_alloc_cb() const;
    inline void set_using_smalloc_alloc_cb(bool value);

    inline bool using_domains() const;
    inline void set_using_domains(bool value);

    inline bool printed_error() const;
    inline void set_printed_error(bool value);

    inline void ThrowError(const char* errmsg);
    inline void ThrowTypeError(const char* errmsg);
    inline void ThrowRangeError(const char* errmsg);
    inline void ThrowErrnoException(int errorno,
                                    const char* syscall = NULL,
                                    const char* message = NULL,
                                    const char* path = NULL);
    inline void ThrowUVException(int errorno,
                                 const char* syscall = NULL,
                                 const char* message = NULL,
                                 const char* path = NULL);

    // Convenience methods for contextify
    inline static void ThrowError(Isolate* isolate, const char* errmsg);
    inline static void ThrowTypeError(Isolate* isolate, const char* errmsg);
    inline static void ThrowRangeError(Isolate* isolate, const char* errmsg);

    // Strings are shared across shared contexts. The getters simply proxy to
    // the per-isolate primitive.
  #define V(PropertyName, StringValue)                                          \
    inline Local<String> PropertyName() const;
    PER_ISOLATE_STRING_PROPERTIES(V)
  #undef V

  #define V(PropertyName, TypeName)                                             \
    inline Local<TypeName> PropertyName() const;                            \
    inline void set_ ## PropertyName(Local<TypeName> value);
    ENVIRONMENT_STRONG_PERSISTENT_PROPERTIES(V)
  #undef V

   private:
    static const int kIsolateSlot = NODE_ISOLATE_SLOT;

    class GCInfo;
    class IsolateData;
    inline explicit Environment(Local<Context> context);
    inline ~Environment();
    inline IsolateData* isolate_data() const;
    void AfterGarbageCollectionCallback(const GCInfo* before,
                                        const GCInfo* after);

    enum ContextEmbedderDataIndex {
      kContextEmbedderDataIndex = NODE_CONTEXT_EMBEDDER_DATA_INDEX
    };

    Isolate* const isolate_;
    IsolateData* const isolate_data_;
    uv_check_t immediate_check_handle_;
    uv_idle_t immediate_idle_handle_;
    uv_prepare_t idle_prepare_handle_;
    uv_check_t idle_check_handle_;
    AsyncListener async_listener_count_;
    DomainFlag domain_flag_;
    TickInfo tick_info_;
    uv_timer_t cares_timer_handle_;
    ares_channel cares_channel_;
    ares_task_list cares_task_list_;
    bool using_smalloc_alloc_cb_;
    bool using_domains_;
    QUEUE gc_tracker_queue_;
    bool printed_error_;

  #define V(PropertyName, TypeName)                                             \
    v8::Persistent<TypeName> PropertyName ## _;
    ENVIRONMENT_STRONG_PERSISTENT_PROPERTIES(V)
  #undef V

    class GCInfo {
     public:
      inline GCInfo();
      inline GCInfo(Isolate* isolate,
                    v8::GCType type,
                    v8::GCCallbackFlags flags,
                    uint64_t timestamp);
      inline v8::GCType type() const;
      inline v8::GCCallbackFlags flags() const;
      // TODO(bnoordhuis) Const-ify once https://codereview.chromium.org/63693005
      // lands and makes it way into a stable release.
      inline v8::HeapStatistics* stats() const;
      inline uint64_t timestamp() const;
     private:
      v8::GCType type_;
      v8::GCCallbackFlags flags_;
      v8::HeapStatistics stats_;
      uint64_t timestamp_;
    };

    // Per-thread, reference-counted singleton.
    class IsolateData {
     public:
      static inline IsolateData* GetOrCreate(v8::Isolate* isolate);
      inline void Put();
      inline uv_loop_t* event_loop() const;

      // Defined in src/node_profiler.cc.
      void StartGarbageCollectionTracking(Environment* env);
      void StopGarbageCollectionTracking(Environment* env);

  #define V(PropertyName, StringValue)                                          \
      inline v8::Local<v8::String> PropertyName() const;
      PER_ISOLATE_STRING_PROPERTIES(V)
  #undef V

     private:
      inline static IsolateData* Get(v8::Isolate* isolate);
      inline explicit IsolateData(v8::Isolate* isolate);
      inline v8::Isolate* isolate() const;

      // Defined in src/node_profiler.cc.
      static void BeforeGarbageCollection(v8::Isolate* isolate,
                                          v8::GCType type,
                                          v8::GCCallbackFlags flags);
      static void AfterGarbageCollection(v8::Isolate* isolate,
                                         v8::GCType type,
                                         v8::GCCallbackFlags flags);
      void BeforeGarbageCollection(v8::GCType type, v8::GCCallbackFlags flags);
      void AfterGarbageCollection(v8::GCType type, v8::GCCallbackFlags flags);

      uv_loop_t* const event_loop_;
      v8::Isolate* const isolate_;

  #define V(PropertyName, StringValue)                                          \
      v8::Eternal<v8::String> PropertyName ## _;
      PER_ISOLATE_STRING_PROPERTIES(V)
  #undef V

      unsigned int ref_count_;
      QUEUE gc_tracker_queue_;
      GCInfo gc_info_before_;
      GCInfo gc_info_after_;

      DISALLOW_COPY_AND_ASSIGN(IsolateData);
    };

    DISALLOW_COPY_AND_ASSIGN(Environment);
  };


// ------Binding------(awww yea)-----

static void Binding(const FunctionCallbackInfo<Value>& args) {
  HandleScope handle_scope(args.GetIsolate());
  Environment* env = Environment::GetCurrent(args.GetIsolate());

  Local<String> module = args[0]->ToString();
  node::Utf8Value module_v(module);

  Local<Object> cache = env->binding_cache_object();
  Local<Object> exports;

  if (cache->Has(module)) {
    exports = cache->Get(module)->ToObject();
    args.GetReturnValue().Set(exports);
    return;
  }

  // Append a string to process.moduleLoadList
  char buf[1024];
  snprintf(buf, sizeof(buf), "Binding %s", *module_v);

  Local<Array> modules = env->module_load_list_array();
  uint32_t l = modules->Length();
  modules->Set(l, OneByteString(env->isolate(), buf));

  node_module* mod = get_builtin_module(*module_v);
  if (mod != NULL) {
    exports = Object::New(env->isolate());
    // Internal bindings don't have a "module" object, only exports.
    assert(mod->nm_register_func == NULL);
    assert(mod->nm_context_register_func != NULL);
};
    Local<Value> unused = Undefined(env->isolate());
    mod->nm_context_register_func(exports, unused,
      env->context(), mod->nm_priv);
    cache->Set(module, exports);
  } else if (!strcmp(*module_v, "constants")) {
    exports = Object::New(env->isolate());
    DefineConstants(exports);
    cache->Set(module, exports);
  } else if (!strcmp(*module_v, "natives")) {
    exports = Object::New(env->isolate());
    DefineJavaScript(env, exports);
    cache->Set(module, exports);
  } else {
    char errmsg[1024];
    snprintf(errmsg,
             sizeof(errmsg),
             "No such module: %s",
             *module_v);
    return env->ThrowError(errmsg);
  }

  args.GetReturnValue().Set(exports);

typedef void (*FunctionCallback)(const FunctionCallbackInfo<Value>& info);

template<typename T>
FunctionCallbackInfo<T>::FunctionCallbackInfo(internal::Object** implicit_args,
                                              internal::Object** values,
                                              int length,
                                              bool is_construct_call)
    : implicit_args_(implicit_args),
      values_(values),
      length_(length),
      is_construct_call_(is_construct_call) { }


template<typename T>
Local<Value> FunctionCallbackInfo<T>::operator[](int i) const {
  if (i < 0 || length_ <= i) return Local<Value>(*Undefined(GetIsolate()));
  return Local<Value>(reinterpret_cast<Value*>(values_ - i));
}


template<typename T>
Local<Function> FunctionCallbackInfo<T>::Callee() const {
  return Local<Function>(reinterpret_cast<Function*>(
      &implicit_args_[kCalleeIndex]));
}


template<typename T>
Local<Object> FunctionCallbackInfo<T>::This() const {
  return Local<Object>(reinterpret_cast<Object*>(values_ + 1));
}


template<typename T>
Local<Object> FunctionCallbackInfo<T>::Holder() const {
  return Local<Object>(reinterpret_cast<Object*>(
      &implicit_args_[kHolderIndex]));
}


template<typename T>
Local<Value> FunctionCallbackInfo<T>::Data() const {
  return Local<Value>(reinterpret_cast<Value*>(&implicit_args_[kDataIndex]));
}


template<typename T>
Isolate* FunctionCallbackInfo<T>::GetIsolate() const {
  return *reinterpret_cast<Isolate**>(&implicit_args_[kIsolateIndex]);
}


template<typename T>
ReturnValue<T> FunctionCallbackInfo<T>::GetReturnValue() const {
  return ReturnValue<T>(&implicit_args_[kReturnValueIndex]);
}


template<typename T>
bool FunctionCallbackInfo<T>::IsConstructCall() const {
  return is_construct_call_;
}


template<typename T>
int FunctionCallbackInfo<T>::Length() const {
  return length_;
}



// ----------
