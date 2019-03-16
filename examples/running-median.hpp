#pragma once

#include <cstdint>
#include <memory>
#include <vector>

namespace examples {

void runningMedian(const std::vector<int32_t>& a,
                   std::shared_ptr<std::vector<double>> ans);

}  // namespace examples
