# define V8_INLINE inline
class Value;
template <class T> class Local;
template <class T> class Handle;
template<class T> class PersistentBase;
class Function;
class Object;
class Isolate;
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
// private:
  // friend class HandleScope;

// ---------

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
    TYPE_CHECK(T, S);
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
    TYPE_CHECK(T, S);
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

// ---------


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

// -----------

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
// class V8_EXPORT HandleScope {
//  public:
//   HandleScope(Isolate* isolate);

//   ~HandleScope();

//   /**
//    * Counts the number of allocated handles.
//    */
//   static int NumberOfHandles(Isolate* isolate);

//   V8_INLINE Isolate* GetIsolate() const {
//     return reinterpret_cast<Isolate*>(isolate_);
//   }

//  protected:
//   V8_INLINE HandleScope() {}

//   void Initialize(Isolate* isolate);

//   static internal::Object** CreateHandle(internal::Isolate* isolate,
//                                          internal::Object* value);

//  private:
//   // Uses heap_object to obtain the current Isolate.
//   static internal::Object** CreateHandle(internal::HeapObject* heap_object,
//                                          internal::Object* value);

//   // Make it hard to create heap-allocated or illegal handle scopes by
//   // disallowing certain operations.
//   HandleScope(const HandleScope&);
//   void operator=(const HandleScope&);
//   void* operator new(size_t size);
//   void operator delete(void*, size_t);

//   internal::Isolate* isolate_;
//   internal::Object** prev_next_;
//   internal::Object** prev_limit_;

//   // Local::New uses CreateHandle with an Isolate* parameter.
//   template<class F> friend class Local;

//   // Object::GetInternalField and Context::GetEmbedderData use CreateHandle with
//   // a HeapObject* in their shortcuts.
//   friend class Object;
//   friend class Context;
// };


