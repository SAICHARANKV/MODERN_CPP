
template <typename T> T add(int n1) { return n1; }

template <typename T, typename... Args> T add(T n1, Args... args) {
  return n1 + add(args...);
}