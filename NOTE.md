<!-- # Lập trình hệ thống C++ bao gồm 
## I. Quản lý bộ nhớ 
- Hiểu và sử dụng con trỏ, cấp phát bộ nhớ với các lệnh như `new`, `delete` `malloc`, `free` để có thể quản lý hiệu quả tài nguyên bộ nhớ của ứng dụng.
- ...
## II. Xử lý File I/O
- Sử dụng các lệnh thao tác hệ thống với tập tin, thư mục, cũng như các thư viện trong C++ để đọc, ghi và xử lý dữ liệu trên đĩa, ổ cứng.
- ...
## III. Quản lý tiến trình và luồng (Process và Threads)
- Viết chương trình có khả năng điều khiển nhiều luồng và tiến trình, tối ưu hóa cho các hệ thống đa nhiệm và đa xử lý.
- ...
## IV. Lập trình mạng (Networking)
- Làm việc với giao thức mạng, xây dựng ứng dụng mạng như máy chủ, máy khách và xử lý kết nối, dữ liệu truyền tải trên mạng.
- ...
## V. Tương tác với thiết bị phần cứng 
- Viết code để điều khiển hoặc truy xuất thông tin từ thiết bị, sử dụng các lệnh hệ thống và API đặc thù cho phần cứng.
- ...
## VI. Quản lý tài nguyên 
- Tối ưu hóa và phân bổ tài nguyên hệ thống, bao gồm cả việc giảm thiểu tài nguyên bị chiếm dụng và đảm bảo tính an toàn cho bộ nhớ.
- ...  -->

## 9. Building the C++ Trading Alogrithm's Buiding Block 
- In this chapter, we build components that make up the intelligence in our trading applications. These are the components that the trading strategies will rely on very heavily to make decisions, send and manage orders, track and manage positions, profits and losses, manage risks.
- ...

### 9.1. Reacting to executions and managing positions, PnLs, and risk 
- A `FeatureEngine`, which will be used to compute simple and complex features/signals that drive the trading strategy decisions.
- A `PositionKeeper`, which will receive executions and compute important measures such as position, PnLs, traded volumes, and more.
- An `OrderManager`, which will be used by the strategies to send orders, manage them, and update these orders when there are updates.
- A `RiskManager` to compute and check the market risk that a trading strategy is attempting to take on, as well as the risk it has realized.

### 9.2. Building the feature and computing complex features
#### 9.2.1. Defining the data members in the feature engine
#### 9.2.2. Initializing the feature engine
#### 9.2.3. Computing the feature on order book changes
#### 9.2.4. Computing the feature on trade events

### 9.3. Using executions to update positions and PnLs
#### 9.3.1. Declaring the data members in `PositionInfo`
#### 9.3.2. Handling order executions in `PositionInfo`
#### 9.3.3. Handling order book changes in `PositionInfo`
#### 9.3.4. Designing `PositionKeeper`
#### 9.3.5. Initializing `PositionKeeper`
#### 9.3.6. Handling order executions and market updates in `PositionKeeper`

### 9.4. Sending and managing orders
#### 9.4.1. Defining the `OMOrder` struct and its related types
#### 9.4.2. Designing the `OrderManager` class
#### 9.4.3. Defining the data members in `OrderManager`
#### 9.4.4. Initializing `OrderManager`
#### 9.4.5. Sending new orders from `OrderManager`
#### 9.4.6. Cancelling orders from `OrderManager`
#### 9.4.7. Adding methods to simplify order management
#### 9.4.8. Handling order updates and updating orders

### 9.5. Computing and managing risk 
#### 9.5.1. Defining the `RiskCfg` structure
#### 9.5.2. Defining the `TradeEngineCfg` structure
#### 9.5.3. Declaring the `RiskCheckResult` enumeration
#### 9.5.4. Defining the `RiskInfo` structure
#### 9.5.5. Performing risk checks in `RiskInfo`
#### 9.5.6. Designing the data members in `RiskManager`
#### 9.5.7. Initializing our `RiskManager` class
#### 9.5.8. Performing risk checks in `RiskManager`
