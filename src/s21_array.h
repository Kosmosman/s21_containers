#ifndef SRC_S21_ARRAY_H_
#define SRC_S21_ARRAY_H_
namespace s21 {
template <typename T, size_t N>
class Array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  Array();
  Array(std::initializer_list<value_type> const &items);
  Array(const Array &a);
  Array(Array &&a);
  Array<T, N> &operator=(const Array &a);
  Array<T, N> &operator=(Array &&a);
  ~Array() = default;

  constexpr reference at(size_type pos);
  constexpr reference operator[](size_type pos);
  constexpr reference front();
  constexpr reference back();
  constexpr iterator data() noexcept;
  constexpr iterator begin() noexcept;
  constexpr const_iterator begin() const noexcept;
  constexpr iterator end() noexcept;
  constexpr const_iterator end() const noexcept;

  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;
  void swap(Array &other);
  void fill(const_reference value);

 private:
  value_type arr_[N];
  iterator begin_;
  iterator end_;
  size_type size_;
};
};  // namespace s21

#include "s21_array.tpp"
#endif  // SRC_S21_QUEUE_H_