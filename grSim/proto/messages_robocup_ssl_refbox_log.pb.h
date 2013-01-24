// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messages_robocup_ssl_refbox_log.proto

#ifndef PROTOBUF_messages_5frobocup_5fssl_5frefbox_5flog_2eproto__INCLUDED
#define PROTOBUF_messages_5frobocup_5fssl_5frefbox_5flog_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
#include "messages_robocup_ssl_detection.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
void protobuf_AssignDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
void protobuf_ShutdownFile_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();

class Log_Frame;
class Refbox_Log;

// ===================================================================

class Log_Frame : public ::google::protobuf::Message {
 public:
  Log_Frame();
  virtual ~Log_Frame();
  
  Log_Frame(const Log_Frame& from);
  
  inline Log_Frame& operator=(const Log_Frame& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Log_Frame& default_instance();
  
  void Swap(Log_Frame* other);
  
  // implements Message ----------------------------------------------
  
  Log_Frame* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Log_Frame& from);
  void MergeFrom(const Log_Frame& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required .SSL_DetectionFrame frame = 1;
  inline bool has_frame() const;
  inline void clear_frame();
  static const int kFrameFieldNumber = 1;
  inline const ::SSL_DetectionFrame& frame() const;
  inline ::SSL_DetectionFrame* mutable_frame();
  inline ::SSL_DetectionFrame* release_frame();
  
  // required string refbox_cmd = 2;
  inline bool has_refbox_cmd() const;
  inline void clear_refbox_cmd();
  static const int kRefboxCmdFieldNumber = 2;
  inline const ::std::string& refbox_cmd() const;
  inline void set_refbox_cmd(const ::std::string& value);
  inline void set_refbox_cmd(const char* value);
  inline void set_refbox_cmd(const char* value, size_t size);
  inline ::std::string* mutable_refbox_cmd();
  inline ::std::string* release_refbox_cmd();
  
  // @@protoc_insertion_point(class_scope:Log_Frame)
 private:
  inline void set_has_frame();
  inline void clear_has_frame();
  inline void set_has_refbox_cmd();
  inline void clear_has_refbox_cmd();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::SSL_DetectionFrame* frame_;
  ::std::string* refbox_cmd_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  friend void protobuf_AssignDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  friend void protobuf_ShutdownFile_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  
  void InitAsDefaultInstance();
  static Log_Frame* default_instance_;
};
// -------------------------------------------------------------------

class Refbox_Log : public ::google::protobuf::Message {
 public:
  Refbox_Log();
  virtual ~Refbox_Log();
  
  Refbox_Log(const Refbox_Log& from);
  
  inline Refbox_Log& operator=(const Refbox_Log& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Refbox_Log& default_instance();
  
  void Swap(Refbox_Log* other);
  
  // implements Message ----------------------------------------------
  
  Refbox_Log* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Refbox_Log& from);
  void MergeFrom(const Refbox_Log& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // repeated .Log_Frame log = 1;
  inline int log_size() const;
  inline void clear_log();
  static const int kLogFieldNumber = 1;
  inline const ::Log_Frame& log(int index) const;
  inline ::Log_Frame* mutable_log(int index);
  inline ::Log_Frame* add_log();
  inline const ::google::protobuf::RepeatedPtrField< ::Log_Frame >&
      log() const;
  inline ::google::protobuf::RepeatedPtrField< ::Log_Frame >*
      mutable_log();
  
  // @@protoc_insertion_point(class_scope:Refbox_Log)
 private:
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::RepeatedPtrField< ::Log_Frame > log_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  friend void protobuf_AssignDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  friend void protobuf_ShutdownFile_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  
  void InitAsDefaultInstance();
  static Refbox_Log* default_instance_;
};
// ===================================================================


// ===================================================================

// Log_Frame

// required .SSL_DetectionFrame frame = 1;
inline bool Log_Frame::has_frame() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Log_Frame::set_has_frame() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Log_Frame::clear_has_frame() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Log_Frame::clear_frame() {
  if (frame_ != NULL) frame_->::SSL_DetectionFrame::Clear();
  clear_has_frame();
}
inline const ::SSL_DetectionFrame& Log_Frame::frame() const {
  return frame_ != NULL ? *frame_ : *default_instance_->frame_;
}
inline ::SSL_DetectionFrame* Log_Frame::mutable_frame() {
  set_has_frame();
  if (frame_ == NULL) frame_ = new ::SSL_DetectionFrame;
  return frame_;
}
inline ::SSL_DetectionFrame* Log_Frame::release_frame() {
  clear_has_frame();
  ::SSL_DetectionFrame* temp = frame_;
  frame_ = NULL;
  return temp;
}

// required string refbox_cmd = 2;
inline bool Log_Frame::has_refbox_cmd() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Log_Frame::set_has_refbox_cmd() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Log_Frame::clear_has_refbox_cmd() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Log_Frame::clear_refbox_cmd() {
  if (refbox_cmd_ != &::google::protobuf::internal::kEmptyString) {
    refbox_cmd_->clear();
  }
  clear_has_refbox_cmd();
}
inline const ::std::string& Log_Frame::refbox_cmd() const {
  return *refbox_cmd_;
}
inline void Log_Frame::set_refbox_cmd(const ::std::string& value) {
  set_has_refbox_cmd();
  if (refbox_cmd_ == &::google::protobuf::internal::kEmptyString) {
    refbox_cmd_ = new ::std::string;
  }
  refbox_cmd_->assign(value);
}
inline void Log_Frame::set_refbox_cmd(const char* value) {
  set_has_refbox_cmd();
  if (refbox_cmd_ == &::google::protobuf::internal::kEmptyString) {
    refbox_cmd_ = new ::std::string;
  }
  refbox_cmd_->assign(value);
}
inline void Log_Frame::set_refbox_cmd(const char* value, size_t size) {
  set_has_refbox_cmd();
  if (refbox_cmd_ == &::google::protobuf::internal::kEmptyString) {
    refbox_cmd_ = new ::std::string;
  }
  refbox_cmd_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Log_Frame::mutable_refbox_cmd() {
  set_has_refbox_cmd();
  if (refbox_cmd_ == &::google::protobuf::internal::kEmptyString) {
    refbox_cmd_ = new ::std::string;
  }
  return refbox_cmd_;
}
inline ::std::string* Log_Frame::release_refbox_cmd() {
  clear_has_refbox_cmd();
  if (refbox_cmd_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = refbox_cmd_;
    refbox_cmd_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// -------------------------------------------------------------------

// Refbox_Log

// repeated .Log_Frame log = 1;
inline int Refbox_Log::log_size() const {
  return log_.size();
}
inline void Refbox_Log::clear_log() {
  log_.Clear();
}
inline const ::Log_Frame& Refbox_Log::log(int index) const {
  return log_.Get(index);
}
inline ::Log_Frame* Refbox_Log::mutable_log(int index) {
  return log_.Mutable(index);
}
inline ::Log_Frame* Refbox_Log::add_log() {
  return log_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Log_Frame >&
Refbox_Log::log() const {
  return log_;
}
inline ::google::protobuf::RepeatedPtrField< ::Log_Frame >*
Refbox_Log::mutable_log() {
  return &log_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_messages_5frobocup_5fssl_5frefbox_5flog_2eproto__INCLUDED
