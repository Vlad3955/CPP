// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protoVariant.proto

#include "protoVariant.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace protoVariant {
PROTOBUF_CONSTEXPR FullName::FullName(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.surname_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.patronymic_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}} {}
struct FullNameDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FullNameDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~FullNameDefaultTypeInternal() {}
  union {
    FullName _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FullNameDefaultTypeInternal _FullName_default_instance_;
PROTOBUF_CONSTEXPR Student::Student(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.grades_)*/{}
  , /*decltype(_impl_._grades_cached_byte_size_)*/{0}
  , /*decltype(_impl_.name_)*/nullptr
  , /*decltype(_impl_.average_)*/0u
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct StudentDefaultTypeInternal {
  PROTOBUF_CONSTEXPR StudentDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~StudentDefaultTypeInternal() {}
  union {
    Student _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 StudentDefaultTypeInternal _Student_default_instance_;
PROTOBUF_CONSTEXPR StudentsGroup::StudentsGroup(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.students_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct StudentsGroupDefaultTypeInternal {
  PROTOBUF_CONSTEXPR StudentsGroupDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~StudentsGroupDefaultTypeInternal() {}
  union {
    StudentsGroup _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 StudentsGroupDefaultTypeInternal _StudentsGroup_default_instance_;
}  // namespace protoVariant
static ::_pb::Metadata file_level_metadata_protoVariant_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_protoVariant_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_protoVariant_2eproto = nullptr;

const uint32_t TableStruct_protoVariant_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::protoVariant::FullName, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::protoVariant::FullName, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::protoVariant::FullName, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::protoVariant::FullName, _impl_.surname_),
  PROTOBUF_FIELD_OFFSET(::protoVariant::FullName, _impl_.patronymic_),
  ~0u,
  ~0u,
  0,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::protoVariant::Student, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::protoVariant::Student, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::protoVariant::Student, _impl_.grades_),
  PROTOBUF_FIELD_OFFSET(::protoVariant::Student, _impl_.average_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::protoVariant::StudentsGroup, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::protoVariant::StudentsGroup, _impl_.students_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, -1, sizeof(::protoVariant::FullName)},
  { 12, -1, -1, sizeof(::protoVariant::Student)},
  { 21, -1, -1, sizeof(::protoVariant::StudentsGroup)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::protoVariant::_FullName_default_instance_._instance,
  &::protoVariant::_Student_default_instance_._instance,
  &::protoVariant::_StudentsGroup_default_instance_._instance,
};

const char descriptor_table_protodef_protoVariant_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022protoVariant.proto\022\014protoVariant\"Q\n\010Fu"
  "llName\022\014\n\004name\030\001 \001(\t\022\017\n\007surname\030\002 \001(\t\022\027\n"
  "\npatronymic\030\003 \001(\tH\000\210\001\001B\r\n\013_patronymic\"P\n"
  "\007Student\022$\n\004name\030\001 \001(\0132\026.protoVariant.Fu"
  "llName\022\016\n\006grades\030\002 \003(\r\022\017\n\007average\030\003 \001(\r\""
  "8\n\rStudentsGroup\022\'\n\010students\030\001 \003(\0132\025.pro"
  "toVariant.Studentb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_protoVariant_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_protoVariant_2eproto = {
    false, false, 265, descriptor_table_protodef_protoVariant_2eproto,
    "protoVariant.proto",
    &descriptor_table_protoVariant_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_protoVariant_2eproto::offsets,
    file_level_metadata_protoVariant_2eproto, file_level_enum_descriptors_protoVariant_2eproto,
    file_level_service_descriptors_protoVariant_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_protoVariant_2eproto_getter() {
  return &descriptor_table_protoVariant_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_protoVariant_2eproto(&descriptor_table_protoVariant_2eproto);
namespace protoVariant {

// ===================================================================

class FullName::_Internal {
 public:
  using HasBits = decltype(std::declval<FullName>()._impl_._has_bits_);
  static void set_has_patronymic(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

FullName::FullName(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:protoVariant.FullName)
}
FullName::FullName(const FullName& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  FullName* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.name_){}
    , decltype(_impl_.surname_){}
    , decltype(_impl_.patronymic_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.surname_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.surname_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_surname().empty()) {
    _this->_impl_.surname_.Set(from._internal_surname(), 
      _this->GetArenaForAllocation());
  }
  _impl_.patronymic_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.patronymic_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_patronymic()) {
    _this->_impl_.patronymic_.Set(from._internal_patronymic(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:protoVariant.FullName)
}

inline void FullName::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.name_){}
    , decltype(_impl_.surname_){}
    , decltype(_impl_.patronymic_){}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.surname_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.surname_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.patronymic_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.patronymic_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

FullName::~FullName() {
  // @@protoc_insertion_point(destructor:protoVariant.FullName)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void FullName::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.Destroy();
  _impl_.surname_.Destroy();
  _impl_.patronymic_.Destroy();
}

void FullName::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void FullName::Clear() {
// @@protoc_insertion_point(message_clear_start:protoVariant.FullName)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.ClearToEmpty();
  _impl_.surname_.ClearToEmpty();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.patronymic_.ClearNonDefaultToEmpty();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* FullName::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "protoVariant.FullName.name"));
        } else
          goto handle_unusual;
        continue;
      // string surname = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_surname();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "protoVariant.FullName.surname"));
        } else
          goto handle_unusual;
        continue;
      // optional string patronymic = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_patronymic();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "protoVariant.FullName.patronymic"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* FullName::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protoVariant.FullName)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protoVariant.FullName.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // string surname = 2;
  if (!this->_internal_surname().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_surname().data(), static_cast<int>(this->_internal_surname().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protoVariant.FullName.surname");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_surname(), target);
  }

  // optional string patronymic = 3;
  if (_internal_has_patronymic()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_patronymic().data(), static_cast<int>(this->_internal_patronymic().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protoVariant.FullName.patronymic");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_patronymic(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protoVariant.FullName)
  return target;
}

size_t FullName::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protoVariant.FullName)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string surname = 2;
  if (!this->_internal_surname().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_surname());
  }

  // optional string patronymic = 3;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_patronymic());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData FullName::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    FullName::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*FullName::GetClassData() const { return &_class_data_; }


void FullName::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<FullName*>(&to_msg);
  auto& from = static_cast<const FullName&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:protoVariant.FullName)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (!from._internal_surname().empty()) {
    _this->_internal_set_surname(from._internal_surname());
  }
  if (from._internal_has_patronymic()) {
    _this->_internal_set_patronymic(from._internal_patronymic());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void FullName::CopyFrom(const FullName& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protoVariant.FullName)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FullName::IsInitialized() const {
  return true;
}

void FullName::InternalSwap(FullName* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.surname_, lhs_arena,
      &other->_impl_.surname_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.patronymic_, lhs_arena,
      &other->_impl_.patronymic_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata FullName::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_protoVariant_2eproto_getter, &descriptor_table_protoVariant_2eproto_once,
      file_level_metadata_protoVariant_2eproto[0]);
}

// ===================================================================

class Student::_Internal {
 public:
  static const ::protoVariant::FullName& name(const Student* msg);
};

const ::protoVariant::FullName&
Student::_Internal::name(const Student* msg) {
  return *msg->_impl_.name_;
}
Student::Student(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:protoVariant.Student)
}
Student::Student(const Student& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Student* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.grades_){from._impl_.grades_}
    , /*decltype(_impl_._grades_cached_byte_size_)*/{0}
    , decltype(_impl_.name_){nullptr}
    , decltype(_impl_.average_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_name()) {
    _this->_impl_.name_ = new ::protoVariant::FullName(*from._impl_.name_);
  }
  _this->_impl_.average_ = from._impl_.average_;
  // @@protoc_insertion_point(copy_constructor:protoVariant.Student)
}

inline void Student::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.grades_){arena}
    , /*decltype(_impl_._grades_cached_byte_size_)*/{0}
    , decltype(_impl_.name_){nullptr}
    , decltype(_impl_.average_){0u}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Student::~Student() {
  // @@protoc_insertion_point(destructor:protoVariant.Student)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Student::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.grades_.~RepeatedField();
  if (this != internal_default_instance()) delete _impl_.name_;
}

void Student::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Student::Clear() {
// @@protoc_insertion_point(message_clear_start:protoVariant.Student)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.grades_.Clear();
  if (GetArenaForAllocation() == nullptr && _impl_.name_ != nullptr) {
    delete _impl_.name_;
  }
  _impl_.name_ = nullptr;
  _impl_.average_ = 0u;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Student::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .protoVariant.FullName name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_name(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated uint32 grades = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedUInt32Parser(_internal_mutable_grades(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 16) {
          _internal_add_grades(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 average = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.average_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Student::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protoVariant.Student)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .protoVariant.FullName name = 1;
  if (this->_internal_has_name()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::name(this),
        _Internal::name(this).GetCachedSize(), target, stream);
  }

  // repeated uint32 grades = 2;
  {
    int byte_size = _impl_._grades_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteUInt32Packed(
          2, _internal_grades(), byte_size, target);
    }
  }

  // uint32 average = 3;
  if (this->_internal_average() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(3, this->_internal_average(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protoVariant.Student)
  return target;
}

size_t Student::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protoVariant.Student)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated uint32 grades = 2;
  {
    size_t data_size = ::_pbi::WireFormatLite::
      UInt32Size(this->_impl_.grades_);
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    int cached_size = ::_pbi::ToCachedSize(data_size);
    _impl_._grades_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // .protoVariant.FullName name = 1;
  if (this->_internal_has_name()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.name_);
  }

  // uint32 average = 3;
  if (this->_internal_average() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_average());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Student::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Student::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Student::GetClassData() const { return &_class_data_; }


void Student::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Student*>(&to_msg);
  auto& from = static_cast<const Student&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:protoVariant.Student)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.grades_.MergeFrom(from._impl_.grades_);
  if (from._internal_has_name()) {
    _this->_internal_mutable_name()->::protoVariant::FullName::MergeFrom(
        from._internal_name());
  }
  if (from._internal_average() != 0) {
    _this->_internal_set_average(from._internal_average());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Student::CopyFrom(const Student& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protoVariant.Student)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Student::IsInitialized() const {
  return true;
}

void Student::InternalSwap(Student* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.grades_.InternalSwap(&other->_impl_.grades_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Student, _impl_.average_)
      + sizeof(Student::_impl_.average_)
      - PROTOBUF_FIELD_OFFSET(Student, _impl_.name_)>(
          reinterpret_cast<char*>(&_impl_.name_),
          reinterpret_cast<char*>(&other->_impl_.name_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Student::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_protoVariant_2eproto_getter, &descriptor_table_protoVariant_2eproto_once,
      file_level_metadata_protoVariant_2eproto[1]);
}

// ===================================================================

class StudentsGroup::_Internal {
 public:
};

StudentsGroup::StudentsGroup(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:protoVariant.StudentsGroup)
}
StudentsGroup::StudentsGroup(const StudentsGroup& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  StudentsGroup* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.students_){from._impl_.students_}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:protoVariant.StudentsGroup)
}

inline void StudentsGroup::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.students_){arena}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

StudentsGroup::~StudentsGroup() {
  // @@protoc_insertion_point(destructor:protoVariant.StudentsGroup)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void StudentsGroup::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.students_.~RepeatedPtrField();
}

void StudentsGroup::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void StudentsGroup::Clear() {
// @@protoc_insertion_point(message_clear_start:protoVariant.StudentsGroup)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.students_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* StudentsGroup::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .protoVariant.Student students = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_students(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* StudentsGroup::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protoVariant.StudentsGroup)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .protoVariant.Student students = 1;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_students_size()); i < n; i++) {
    const auto& repfield = this->_internal_students(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(1, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protoVariant.StudentsGroup)
  return target;
}

size_t StudentsGroup::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protoVariant.StudentsGroup)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .protoVariant.Student students = 1;
  total_size += 1UL * this->_internal_students_size();
  for (const auto& msg : this->_impl_.students_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData StudentsGroup::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    StudentsGroup::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*StudentsGroup::GetClassData() const { return &_class_data_; }


void StudentsGroup::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<StudentsGroup*>(&to_msg);
  auto& from = static_cast<const StudentsGroup&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:protoVariant.StudentsGroup)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.students_.MergeFrom(from._impl_.students_);
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void StudentsGroup::CopyFrom(const StudentsGroup& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protoVariant.StudentsGroup)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StudentsGroup::IsInitialized() const {
  return true;
}

void StudentsGroup::InternalSwap(StudentsGroup* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.students_.InternalSwap(&other->_impl_.students_);
}

::PROTOBUF_NAMESPACE_ID::Metadata StudentsGroup::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_protoVariant_2eproto_getter, &descriptor_table_protoVariant_2eproto_once,
      file_level_metadata_protoVariant_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace protoVariant
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protoVariant::FullName*
Arena::CreateMaybeMessage< ::protoVariant::FullName >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protoVariant::FullName >(arena);
}
template<> PROTOBUF_NOINLINE ::protoVariant::Student*
Arena::CreateMaybeMessage< ::protoVariant::Student >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protoVariant::Student >(arena);
}
template<> PROTOBUF_NOINLINE ::protoVariant::StudentsGroup*
Arena::CreateMaybeMessage< ::protoVariant::StudentsGroup >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protoVariant::StudentsGroup >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
