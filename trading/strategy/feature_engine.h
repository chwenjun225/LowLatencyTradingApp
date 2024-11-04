// ## 9.2. Building the feature and computing complex features
// #### 9.2.1. Defining the data members in the feature engine
#pragma once
#include "common/macros.h"
#include "common/logging.h"

using namespace Common;

namespace Trading {
	constexpr auto Feature_INVALID = std::numeric_limits<double>::quiet_NaN();

	class FeatureEngine {
		// #### 9.2.2. Initializing the feature engine
		public: 
			FeatureEngine(Common::Logger *logger) : logger_(logger) {
				// ...
			}

			auto getMktPrice() const noexcept {
				return mkt_price_;
				}

			auto getAggTradeQtyRatio() const noexcept {
				return agg_trade_qty_ratio_;
			}







		private:
			std::string time_str_;
			Common::Logger *logger_ = nullptr;
			double mkt_price_ = Feature_INVALID, agg_trade_qty_ratio_ = Feature_INVALID; 
	};
}