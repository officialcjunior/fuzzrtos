// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rtos_protocol_buffers.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_rtos_5fprotocol_5fbuffers_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_rtos_5fprotocol_5fbuffers_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_rtos_5fprotocol_5fbuffers_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_rtos_5fprotocol_5fbuffers_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_rtos_5fprotocol_5fbuffers_2eproto;
class AMessage;
class AMessageDefaultTypeInternal;
extern AMessageDefaultTypeInternal _AMessage_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::AMessage* Arena::CreateMaybeMessage<::AMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class AMessage PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:AMessage) */ {
 public:
  inline AMessage() : AMessage(nullptr) {};
  virtual ~AMessage();

  AMessage(const AMessage& from);
  AMessage(AMessage&& from) noexcept
    : AMessage() {
    *this = ::std::move(from);
  }

  inline AMessage& operator=(const AMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline AMessage& operator=(AMessage&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const AMessage& default_instance();

  enum ValueCase {
    kA = 1,
    VALUE_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AMessage* internal_default_instance() {
    return reinterpret_cast<const AMessage*>(
               &_AMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(AMessage& a, AMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(AMessage* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(AMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline AMessage* New() const final {
    return CreateMaybeMessage<AMessage>(nullptr);
  }

  AMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<AMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const AMessage& from);
  void MergeFrom(const AMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "AMessage";
  }
  protected:
  explicit AMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_rtos_5fprotocol_5fbuffers_2eproto);
    return ::descriptor_table_rtos_5fprotocol_5fbuffers_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAFieldNumber = 1,
  };
  // string a = 1;
  private:
  bool _internal_has_a() const;
  public:
  void clear_a();
  const std::string& a() const;
  void set_a(const std::string& value);
  void set_a(std::string&& value);
  void set_a(const char* value);
  void set_a(const char* value, size_t size);
  std::string* mutable_a();
  std::string* release_a();
  void set_allocated_a(std::string* a);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_a();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_a(
      std::string* a);
  private:
  const std::string& _internal_a() const;
  void _internal_set_a(const std::string& value);
  std::string* _internal_mutable_a();
  public:

  void clear_value();
  ValueCase value_case() const;
  // @@protoc_insertion_point(class_scope:AMessage)
 private:
  class _Internal;
  void set_has_a();

  inline bool has_value() const;
  inline void clear_has_value();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  union ValueUnion {
    ValueUnion() {}
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr a_;
  } value_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_rtos_5fprotocol_5fbuffers_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// AMessage

// string a = 1;
inline bool AMessage::_internal_has_a() const {
  return value_case() == kA;
}
inline void AMessage::set_has_a() {
  _oneof_case_[0] = kA;
}
inline void AMessage::clear_a() {
  if (_internal_has_a()) {
    value_.a_.Destroy(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
    clear_has_value();
  }
}
inline const std::string& AMessage::a() const {
  // @@protoc_insertion_point(field_get:AMessage.a)
  return _internal_a();
}
inline void AMessage::set_a(const std::string& value) {
  _internal_set_a(value);
  // @@protoc_insertion_point(field_set:AMessage.a)
}
inline std::string* AMessage::mutable_a() {
  // @@protoc_insertion_point(field_mutable:AMessage.a)
  return _internal_mutable_a();
}
inline const std::string& AMessage::_internal_a() const {
  if (_internal_has_a()) {
    return value_.a_.Get();
  }
  return *&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void AMessage::_internal_set_a(const std::string& value) {
  if (!_internal_has_a()) {
    clear_value();
    set_has_a();
    value_.a_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.a_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void AMessage::set_a(std::string&& value) {
  // @@protoc_insertion_point(field_set:AMessage.a)
  if (!_internal_has_a()) {
    clear_value();
    set_has_a();
    value_.a_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.a_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:AMessage.a)
}
inline void AMessage::set_a(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  if (!_internal_has_a()) {
    clear_value();
    set_has_a();
    value_.a_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.a_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:AMessage.a)
}
inline void AMessage::set_a(const char* value,
                             size_t size) {
  if (!_internal_has_a()) {
    clear_value();
    set_has_a();
    value_.a_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.a_.Set(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size),
      GetArena());
  // @@protoc_insertion_point(field_set_pointer:AMessage.a)
}
inline std::string* AMessage::_internal_mutable_a() {
  if (!_internal_has_a()) {
    clear_value();
    set_has_a();
    value_.a_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  return value_.a_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* AMessage::release_a() {
  // @@protoc_insertion_point(field_release:AMessage.a)
  if (_internal_has_a()) {
    clear_has_value();
    return value_.a_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  } else {
    return nullptr;
  }
}
inline void AMessage::set_allocated_a(std::string* a) {
  if (has_value()) {
    clear_value();
  }
  if (a != nullptr) {
    set_has_a();
    value_.a_.UnsafeSetDefault(a);
  }
  // @@protoc_insertion_point(field_set_allocated:AMessage.a)
}
inline std::string* AMessage::unsafe_arena_release_a() {
  // @@protoc_insertion_point(field_unsafe_arena_release:AMessage.a)
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (_internal_has_a()) {
    clear_has_value();
    return value_.a_.UnsafeArenaRelease(
        &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  } else {
    return nullptr;
  }
}
inline void AMessage::unsafe_arena_set_allocated_a(std::string* a) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (!_internal_has_a()) {
    value_.a_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  clear_value();
  if (a) {
    set_has_a();
    value_.a_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), a, GetArena());
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:AMessage.a)
}

inline bool AMessage::has_value() const {
  return value_case() != VALUE_NOT_SET;
}
inline void AMessage::clear_has_value() {
  _oneof_case_[0] = VALUE_NOT_SET;
}
inline AMessage::ValueCase AMessage::value_case() const {
  return AMessage::ValueCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_rtos_5fprotocol_5fbuffers_2eproto
