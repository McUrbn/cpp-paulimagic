#pragma once

#include <algorithm>
#include <vector>
#include <cmath>
#include <complex>
#include <iterator>
#include <numeric>
#include <ostream>
#include <utility>

#include "prefix.h"
#include "paulimatrix.h"

class TensorProduct {
 public:
    explicit TensorProduct(size_t n): elements_(n), N(n) {}

  auto operator==(const TensorProduct& rhs) const noexcept -> bool {
    return elements_ == rhs.elements_;
  }

  auto operator!=(const TensorProduct& rhs) const noexcept -> bool {
    return !(*this == rhs);
  }

  auto operator*(const TensorProduct& rhs) const -> TensorProduct {
    auto res = TensorProduct(N);
    for (auto i = 0u; i < N; ++i) {
      res.elements_[i] = elements_[i] * rhs.elements_[i];
    }
    return res;
  }

  auto len() const -> std::size_t {
        return N;
  }
    
  template <typename PMAT>
  auto set(std::size_t i, PMAT&& pm) -> void {
    if (i < N)
        elements_[i] = std::forward<PMAT>(pm);
  }

  template <typename T = int, typename C = std::complex<T>>
  auto trace() const noexcept -> C {
    return std::accumulate(
        std::begin(elements_), std::end(elements_), C{1, 0},
        [](C acc, const PauliMatrix& pm) { return acc * pm.trace(); });
  }
    
 private:
  friend auto operator<<(std::ostream&, const TensorProduct&) -> std::ostream
      &;

  std::vector<PauliMatrix> elements_;
  std::size_t N;
};

auto operator<<(std::ostream& os, const TensorProduct& t) -> std::ostream & {
  os << '[';
  std::copy(std::begin(t.elements_), std::end(t.elements_) - 1,
            std::ostream_iterator<PauliMatrix>(os, " "));
  os << t.elements_[t.len() - 1];
  os << ']';
  return os;
}
