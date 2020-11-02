#include <iostream>
#include <fstream>
#include <type_traits>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <map>
#include <algorithm>

#include <cstddef>
#include <cstdint>
#include <cmath>

namespace fastio
{
constexpr std::size_t buf_size = 0x100000;
bool ioerror;

char nc()
{
  static char buf[buf_size], * p1 = buf + buf_size, * pend = buf + buf_size;
  if (p1 == pend)
  {
    p1 = buf;
    std::cin.read(buf, buf_size);
    pend = buf + std::cin.gcount();
    if (pend == p1)
    {
      ioerror = true;
      return -1;
    }
  }
  return *p1++;
}

bool blank(char ch)
{ return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }

template<typename IntType>
typename std::enable_if<std::is_signed<IntType>::value, bool>::type read(IntType& x)
{
  bool sign = false;
  char ch = nc();
  x = 0;
  while (blank(ch)) ch = nc();
  if (ioerror) return false;
  if (ch == '-') sign = true, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (sign) x = -x;
  return true;
}

template<typename UIntType>
typename std::enable_if<std::is_unsigned<UIntType>::value, bool>::type read(UIntType& x)
{
  x = 0;
  char ch = nc();
  while (blank(ch)) ch = nc();
  if (ioerror) return false;
  for (; '0' <= ch && ch <= '9'; ch = nc()) x = x * 10 + (ch - '0');
  return true;
}

void read(bool& x)
{
  char ch = nc();
  while (blank(ch)) ch = nc();
  if (ioerror) return;
  x = ch != '0';
}

void read(double& x)
{
  bool sign = false;
  char ch = nc();
  x = 0;
  while (blank(ch)) ch = nc();
  if (ioerror) return;
  if (ch == '-') sign = true, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
  if (ch == '.')
  {
    double tmp = 1;
    ch = nc();
    for (; ch >= '0' && ch <= '9'; ch = nc())tmp /= 10.0, x += tmp * (ch - '0');
  }
  if (sign)x = -x;
}

bool read(std::string& s)
{
  s.clear();
  char ch = nc();
  while (blank(ch)) ch = nc();
  if (ioerror) return false;
  for (; !blank(ch) && !ioerror; ch = nc()) s.push_back(ch);
  return true;
}

void read(char* s)
{
  char ch = nc();
  while (blank(ch)) ch = nc();
  if (ioerror) return;
  for (; !blank(ch) && !ioerror; ch = nc()) *s++ = ch;
  *s = 0;
}

void read(char& c)
{
  c = nc();
  while (blank(c)) c = nc();
  if (ioerror)
  {
    c = -1;
  }
}

void skip(char c)
{
  while (!ioerror && nc() != c);
}

class Ostream
{
public:
  char* buf, * p1, * pend;

  void out(char ch)
  {
    if (p1 == pend)
    {
      std::cout.write(buf, buf_size);
      p1 = buf;
    }
    *p1++ = ch;
  }

  template<typename IntType>
  typename std::enable_if<std::is_signed<IntType>::value>::type print(IntType x)
  {
    static char s[25], * s1;
    s1 = s;
    if (!x) *s1++ = '0';
    if (x < 0) out('-'), x = -x;
    while (x) *s1++ = x % 10 + '0', x /= 10;
    while (s1-- != s) out(*s1);
  }

  template<typename UIntType>
  typename std::enable_if<std::is_unsigned<UIntType>::value>::type print(UIntType x)
  {
    static char s[25], * s1;
    s1 = s;
    if (!x) *s1++ = '0';
    while (x) *s1++ = x % 10 + '0', x /= 10;
    while (s1-- != s) out(*s1);
  }

  void print(double x, int y)
  {
    constexpr std::int_fast64_t mul[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
      100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000,
      100000000000000, 1000000000000000, 10000000000000000, 100000000000000000};
    if (x < -1e-12)out('-'), x = -x;
    x *= mul[y];
    std::int_fast64_t x1 = static_cast<std::int_fast64_t>(floor(x));
    if (x - floor(x) >= 0.5)++x1;
    std::int_fast64_t x2 = x1 / mul[y], x3 = x1 - x2 * mul[y];
    print(x2);
    if (y > 0)
    {
      out('.');
      for (size_t i = 1; i < y && x3 * mul[i] < mul[y]; ++i) out('0');
      print(x3);
    }
  }

  void print(const std::string& s)
  {
    for (const char& ch : s) out(ch);
  }

  void print(const char* s)
  {
    while (*s != '\0') out(*s++);
  }

  void flush()
  {
    if (p1 != buf)
    {
      std::cout.write(buf, p1 - buf);
      p1 = buf;
    }
    std::cout.flush();
  }

  static Ostream& get_instance()
  {
    static Ostream instance;
    return instance;
  }

private:
  Ostream()
  {
    buf = new char[buf_size];
    p1 = buf;
    pend = buf + buf_size;
  }

  Ostream(const Ostream&) = delete;
  Ostream(Ostream&&) = delete;
  Ostream& operator=(const Ostream&) = delete;
  Ostream& operator=(Ostream&&) = delete;

  ~Ostream()
  { flush(); }
};

void println()
{ Ostream::get_instance().out('\n'); }

template<typename IntType>
void print(IntType x)
{ Ostream::get_instance().print(x); }

void print(char x)
{ Ostream::get_instance().out(x); }

void print(double x, int y)
{ Ostream::get_instance().print(x, y); }

void print(const std::string& s)
{ Ostream::get_instance().print(s); }

void print(const char* s)
{ Ostream::get_instance().print(s); }

template<typename IntType>
void println(IntType x)
{
  print(x);
  println();
}

void println(double x, int y)
{
  print(x, y);
  println();
}

void println(const std::string& s)
{
  print(s);
  println();
}

void println(const char* s)
{
  print(s);
  println();
}

void flush()
{ Ostream::get_instance().flush(); }
} // fastio

using UIntType = std::uint_fast64_t;
using IntType = std::int_fast64_t;

int main()
{
    //freopen("10.in","r",stdin); freopen("std.out","w",stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
	freopen("data.in","r",stdin); freopen("data.out","w",stdout);
  std::string s1;
  std::size_t k;
  std::string s2;
  while (fastio::read(s1) && fastio::read(k) && fastio::read(s2))
  {
    std::vector<std::pair<std::string, std::size_t>> nodes{{s1, k}};
    using Node = std::pair<std::size_t, std::size_t>;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
    q.emplace(0, 0);
    std::vector<std::size_t> distance{0};
    std::map<std::pair<std::string, std::size_t>, std::size_t> indices;
    indices[nodes.front()] = 0;
    while (!q.empty())
    {
      std::size_t u = q.top().second;
      std::size_t dist = q.top().first;
      q.pop();
      if (dist > distance[u])
      {
        continue;
      }
      {
        std::size_t min = 1000000;
        for (std::size_t pos = 0; pos <= s2.size(); ++pos)
        {
          auto iter = indices.find({s2, pos});
          if (iter != indices.end())
          {
            min = std::min(min, distance[iter->second]);
          }
        }
        if (dist >= min)
        {
          continue;
        }
      }
      std::string s = nodes[u].first;
      std::size_t pos = nodes[u].second;
      if (pos > 0)
      {
        std::size_t alt = dist + 1;
        auto iter = indices.find({s, pos - 1});
        if (iter != indices.end())
        {
          if (alt < distance[iter->second])
          {
            distance[iter->second] = alt;
            q.emplace(alt, iter->second);
          }
        }
        else
        {
          nodes.emplace_back(s, pos - 1);
          distance.emplace_back(alt);
          q.emplace(alt, nodes.size() - 1);
          indices[nodes.back()] = nodes.size() - 1;
        }
        alt = dist + 2;
        std::string alt_str = s;
        alt_str.erase(pos - 1, 1);
        iter = indices.find({alt_str, pos - 1});
        if (iter != indices.end())
        {
          if (alt < distance[iter->second])
          {
            distance[iter->second] = alt;
            q.emplace(alt, iter->second);
          }
        }
        else
        {
          nodes.emplace_back(alt_str, pos - 1);
          distance.emplace_back(alt);
          q.emplace(alt, nodes.size() - 1);
          indices[nodes.back()] = nodes.size() - 1;
        }
      }
      if (pos < s.size())
      {
        std::size_t alt = dist + 1;
        auto iter = indices.find({s, pos + 1});
        if (iter != indices.end())
        {
          if (alt < distance[iter->second])
          {
            distance[iter->second] = alt;
            q.emplace(alt, iter->second);
          }
        }
        else
        {
          nodes.emplace_back(s, pos + 1);
          distance.emplace_back(alt);
          q.emplace(alt, nodes.size() - 1);
          indices[nodes.back()] = nodes.size() - 1;
        }
        alt = dist + 2;
        std::string alt_str = s;
        alt_str.erase(pos, 1);
        iter = indices.find({alt_str, pos});
        if (iter != indices.end())
        {
          if (alt < distance[iter->second])
          {
            distance[iter->second] = alt;
            q.emplace(alt, iter->second);
          }
        }
        else
        {
          nodes.emplace_back(alt_str, pos);
          distance.emplace_back(alt);
          q.emplace(alt, nodes.size() - 1);
          indices[nodes.back()] = nodes.size() - 1;
        }
      }
      for (char ch = 'a'; ch <= 'g'; ++ch)
      {
        if (s.find(ch) != std::string::npos)
        {
          continue;
        }
        std::size_t alt = dist + 2;
        std::string alt_str = s;
        alt_str.insert(pos, 1, ch);
        auto iter = indices.find({alt_str, pos + 1});
        if (iter != indices.end())
        {
          if (alt < distance[iter->second])
          {
            distance[iter->second] = alt;
            q.emplace(alt, iter->second);
          }
        }
        else
        {
          nodes.emplace_back(alt_str, pos + 1);
          distance.emplace_back(alt);
          q.emplace(alt, nodes.size() - 1);
          indices[nodes.back()] = nodes.size() - 1;
        }
      }
    }
    std::size_t result = 1000000;
    for (std::size_t pos = 0; pos <= s2.size(); ++pos)
    {
      auto iter = indices.find({s2, pos});
      if (iter != indices.end())
      {
        result = std::min(result, distance[iter->second]);
      }
    }
    fastio::println(result / 2.0, 1);
  }
  return 0;
}
