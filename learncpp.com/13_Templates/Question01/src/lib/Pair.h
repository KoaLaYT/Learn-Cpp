#ifndef PAIR_H_2020_02_10
#define PAIR_H_2020_02_10

#include <string>

template <typename T> class Pair1 {
public:
  Pair1(const T &fst, const T &snd) : m_fst{fst}, m_snd{snd} {}
  const T &first() const { return m_fst; }
  const T &second() const { return m_snd; }

private:
  T m_fst;
  T m_snd;
};

template <typename T, typename P> class Pair {
public:
  Pair(const T &fst, const P &snd) : m_fst{fst}, m_snd{snd} {}
  const T &first() const { return m_fst; }
  const P &second() const { return m_snd; }

private:
  T m_fst;
  P m_snd;
};

template <typename T> class StringValuePair : public Pair<std::string, T> {
public:
  StringValuePair(const std::string &s, const T &v)
      : Pair<std::string, T>{s, v} {}
};

#endif
