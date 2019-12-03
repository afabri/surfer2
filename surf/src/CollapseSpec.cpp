#include "CollapseSpec.h"

unsigned CollapseSpec::COUNTER_NT_cmp = 0;

std::ostream&
operator<<(std::ostream& os, const CollapseType a) {
  switch (a) {
    case CollapseType::UNDEFINED:
      os << "UNDEFINED";
      break;
    case CollapseType::FACE_HAS_INFINITELY_FAST_VERTEX:
      os << "FACE_HAS_INFINITELY_FAST_VERTEX";
      break;
    case CollapseType::TRIANGLE_COLLAPSE:
      os << "TRIANGLE_COLLAPSE";
      break;
    case CollapseType::CONSTRAINT_COLLAPSE:
      os << "CONSTRAINT_COLLAPSE";
      break;
    case CollapseType::SPOKE_COLLAPSE:
      os << "SPOKE_COLLAPSE";
      break;
    case CollapseType::SPLIT_OR_FLIP_REFINE:
      os << "SPLIT_OR_FLIP_REFINE";
      break;
    case CollapseType::VERTEX_MOVES_OVER_SPOKE:
      os << "VERTEX_MOVES_OVER_SPOKE";
      break;
    case CollapseType::CCW_VERTEX_LEAVES_CH:
      os << "CCW_VERTEX_LEAVES_CH";
      break;
    case CollapseType::INVALID_EVENT:
      os << "INVALID_EVENT";
      break;
    /*
    case CollapseType::GENERIC_FLIP_EVENT:
      os << "GENERIC_FLIP_EVENT";
      break;
    */
    case CollapseType::NEVER:
      os << "NEVER";
      break;
  }
  return os;
}

std::ostream&
operator<<(std::ostream& os, const CollapseSpec& s) {
  os << "type " << s.type();
  if (s.requires_relevant_edge()) {
    os << "(" << s.relevant_edge() << ")";
  }
  if (s.type() != CollapseType::NEVER) {
    os << " at time " << s.get_printable_time();// << " (" << CGAL::to_double(s.longest_spoke()) << ")";
  }
  os << " (component " << s.component << ")";
  return os;
}

std::ostream&
operator<<(std::ostream& os, const EdgeCollapseType a) {
  switch (a) {
    case EdgeCollapseType::UNDEFINED:
      os << "UNDEFINED";
      break;
    case EdgeCollapseType::PAST:
      os << "PAST";
      break;
    case EdgeCollapseType::FUTURE:
      os << "FUTURE";
      break;
    case EdgeCollapseType::ALWAYS:
      os << "ALWAYS";
      break;
    case EdgeCollapseType::NEVER:
      os << "NEVER";
      break;
  }
  return os;
}

std::ostream&
operator<<(std::ostream& os, const EdgeCollapseSpec& s) {
  os << "type " << s.type();
  if (s.type() == EdgeCollapseType::FUTURE) {
    os << " at time " << s.get_printable_time();// << " (" << CGAL::to_double(s.longest_spoke()) << ")";
  }
  return os;
}
