#include "Point2d.h"
#include <cmath>

double Point2d::distance_to(const Point2d &a) const {
  const double dx{m_x - a.m_x};
  const double dy{m_y - a.m_y};
  return std::sqrt(dx * dx + dy * dy);
}

double distance_from(const Point2d &a, const Point2d &b) {
  const double dx{a.m_x - b.m_x};
  const double dy{a.m_y - b.m_y};
  return std::sqrt(dx * dx + dy * dy);
}
