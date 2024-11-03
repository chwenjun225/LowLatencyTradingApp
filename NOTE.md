# Lập trình hệ thống C++ bao gồm 
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
- ... 

# XÂY DỰNG ỨNG DỤNG GIAO DỊCH ĐIỆN TỬ ĐỘ TRỄ THẤP VỚI C++

## Chapter 4: Xây dựng các khối block C++ cho các ứng dụng có độ trễ thấp
Trong chương này, chúng ta sẽ đề cập đến các chủ đề như sau:
1. Phân luồng C++ cho các ứng dụng đa luồng, độ trễ thấp
2. Thiết kế nhóm bộ nhớ C++ để tránh cấp phát bộ nhớ bị động 
3. Truyền dữ liệu bằng hàng đợi không khóa 
4. Xây dụng khung ghi nhật ký có độ trễ thấp 
5. Lập trình mạng C++ sử dụng socket

### 1. Phân luồng C++ cho các ứng dụng đa luồng, độ trễ thấp
- ...
### 2. Thiết kế nhóm bộ nhớ C++ để tránh cấp phát bộ nhớ động
#### 2.1. Hiểu các trường hợp sử dụng của nhóm bộ nhớ 
- Khi số lượng đối tượng chính xác của một loại nhất định được yêu cầu 
biết trước, ta có thể tạo chính xác số đó khi cần. 
- Thực tế, có nhiều trường hợp số lượng đối tượng chính xác không được biết trước. Điều này có nghĩa là ta cần tạo các đối tượng một cách nhanh chóng bằng cách sử dụng phân bổ bộ nhớ động. 
- Phân bổ bộ nhớ động là một quá trình rất chậm và là một vấn đề đối với các ứng dụng có độ trễ thấp. 
- Thuật ngữ `memory pool` để mô tả một nhóm các đối tượng thuộc một loại nhất định và đó là những gì chúng tôi sẽ xây dựng trong phần này. 
- Giải pháp, chúng ta sẽ phân bổ trước các khối bộ nhớ lớn khi khởi động và phục vụ số lượng cần thiết trong thời gian chạy - nghĩa là tự thực hiện các bước phân bổ bộ nhớ từ nhóm lưu trữ.
### 3. Truyền dữ liệu bằng hàng đợi không khóa 
- ...
### 4. Xây dựng framework lưu lại nhật ký với độ trễ thấp 
- Bây giờ, ta sẽ xây dựng một khung ghi nhật ký có độ trễ thấp bằng cách sử dụng một số thành phần 
mà chúng ta vừa xây dựng trong các phần trước. Ghi nhật ký là 
một phần quan trọng của bất kỳ ứng dụng nào.
- Một trong những các tiếp cận ghi nhật ký ngây thơ sẽ là xuất 
ra màn hình, trong khi cách tiếp cận tốt hơn một chút sẽ là lưu 
vào một hoặc nhiều tệp nhật ký.
- Trước khi nhảy vào lớp logger, chúng ta sẽ định nghĩa một vài
phương thức tiện ích để lấy thời gian hệ thống hiện tại cũng
như chuyển đổi chúng thành chuỗi cho mục đích ghi nhật ký.
#### 4.1. Thiết kế phương pháp tiện ích cho thời gian 
- ...
#### 4.2. Thiết kế bộ ghi nhật ký độ trễ thấp 
- Để xây dựng framework ghi nhật ký có độ trễ thấp, ta sẽ tạo một luồng
ghi nhật ký nền có nhiệm vụ duy nhất là ghi các dòng nhật ký vào tệp nhật
ký trên đĩa. Ý tưởng ở đây là giảm tải các hoạt động I/O cũng như các hoạt
động định dạng chuỗi ra khỏi luồng quan trọng về hiệu xuất chính vào luồng 
nền.
- Sử dụng hàm multi-threading để tạo logger thread vào gán nó nhiệm vụ ghi
vào log file. 
#### 4.3. Xác định một số cấu trúc logger 
- Trước tiên cần xác định khối thông tin cơ bản được chuyển qua hàng đợi
không khóa từ luồng nhạy cảm với hiệu xuất sang luồng logger.
- ...
### 5. Lập trình mạng C++ sử dụng socket 
- Xây dựng framework để xử lý lập trình mạng bằng cách sử dựng các socket 
Unix. 
- Sử dụng framework này để xây dựng một máy chủ bắt các kết nối TCP đến và
một máy client có khả năng thiết lập kết nối TCP với máy chủ.
#### 5.1. Xây dựng API socket cơ bản 
- Mục tiêu là tạo ra một cơ chế socket mạng và khởi tạo nó với các tham
số chính xác. 
- Phương thức này dùng để tạo ra các socket listener, receiver và sender 
để giao tiếp qua các giao thức UDP và TCP.

## Chapter 5: Thiết kế hệ sinh thái giao dịch 
- Chương trước đã nhảy vào một số phát triển thực hành, xây dựng cơ bản 
 các block, với tiêu chí độ trễ thấp và chính xác.
- Trước tiên, hãy thảo luận về thiết kế và kiến trúc cấp cao của các thành
phần hoặc ứng dụng có độ trễ thấp khác nhau mà chúng ta sẽ xây dựng cho hệ 
sinh thái giao dịch điện tử đầu cuối.
- Trong chương này, chúng ta sẽ:
    - Hiểu các bố trí của hệ sinh thái giao dịch điện tử
    - Thiết kế công cụ kết hợp C++ trong sàn giao dịch 
    - Hiểu cách trao đổi xuất bản thông tin cho người tham gia 
    - Xây dựng giao diện cho user và sàn giao dịch 
    - Thiết kế framework cho các thuật toán giao dịch C++ độ trễ thấp
> Lưu ý: Tập trung vào các nguyên tắc khoa học máy tính và C++ và ít hơn 
vào các chi tiết của hệ sinh thái giao dịch. 

## Chapter 6: Building the C++ Matching Engine 
- Trong chương này, chúng ta sẽ:
    - Xác định các hoạt động và tương tác trong công cụ kết hợp 
    - Xây dựng công cụ kết hợp và trao đổi dữ liệu bên ngoài 
    - Xây dựng sổ lệnh và khớp lệnh 

- Xác định một vài điều cơ bản 
    - **OrderId**: Xác định đơn hàng
    - **TickerId**: Xác định công cụ giao dịch 
    - **ClientId**: Xác định các khách hàng khác nhau 
    - **Price**: Giá tiền của đơn hàng 
    - **Qty**: Số lượng để giữ giá trị cho đơn đặt hàng 
    - **Priority**: Ưu tiên, nắm bắt vị trí của một lệnh trong hàng đợi **(FIFO)** 
    - **Side**: Để biểu thị bên mua / bán của một đơn đặt hàng 

# Part 3: Buiding Real-Time C++ Algorithmic Trading Systems 

In this part, we will start building the tradin gclient-side C++ algorithmic trading 
system. We will be building components that interface with the trading exchange. We 
will be building components that interface with the trading exchange to process market 
data and connect to and communicate with the exchange order gateway. We will also build 
the C++ framework on which we will build market-making and liquidity-taking algorithms. 
In the HFT space, this is where participants spend a lot of time and effort trying to reduce latencies and maximize and liquidity-taking algorithms in this framework, run the 
entire trading ecosystems, and understand the interactions between all the components. 

* Chapter 8: Processing Market Data and Sending Orders to the Exchange in C++ 
* Chapter 9: Building the C++ Trading Algorithm Building Blocks 
* Chapter 10: Building the C++ Market-Making and Liquidity-Taking Algorithm 

## Chapter 8: Processing Market Data and Sending Orders the the Exchange in C++
In this chapter, we will build the client's C++ system that receives and processes 
market data updates from the trading exhange. We will also have to deal with creating 
and reading from UDP sockets, dealing with packet losses, etc. We will discuss the 
design of and order book on the client side to track the order book maintained at the
trading exchange. We will also implement the C++ components needed to establish and 
maintain TCP connections to the trading exchange. We will also implement functionality
to send orders to the exchange from the strategies and receive and process order responses. 

In this chapter, we will cover the following topics:
- Subcribing to market data and decoding the market data protocol 
- Building order books from market data 
- Connecting to the exchange, sending order requests, and receiving response

### Subscribing to market data and decoding the market data protocol 
The first component we need to build inside the market participant's trading system is the market data consumer. This component is responsible for subscribing to the multicast stream of public market data updates published by the trading exchange. It needs to decode the market data stream generated by the exchange from the public MDPMarketUpdate format we discussed earlier. Because of the choice of the Simple Binary Encoding protocol, the decoding step is straightforward in our application responsibility of this component is 
detecting packet drops on the incremental market data stream and providing mechanism to 
recover and synchronize with the market data stream again. This mechanism is also required for trading systems that subscribe to the market data stream after there is a none-empty order book, i.e. after the trading exchange is already open and accepting client orders. Also, this will be required if the trading application needs to be restarted in the middle of the day. 

We present a detailed diagram of the market data consumer component we have seen before. As
shown in Figure 8.1, it consumes multicast data containing market data updates from the incremental and optionally the snapshot stream. After checking for sequence numbers on the market data updates and potentially needing to synchronize between the snapshot and the 
incremental streams, it decodes the market data updates. It then generates a stream of decoded and in-order market data updates for the trading engine to consume and publishes 
them over a lock-free queue.

#### Defining the data members in the market data consumer 
The `MarketDataConsumer` class we are going to build need couple of important data members as shown in the following bullet list:
- First, it needs a lock-free `incoming_md_updates_` queue instance of the `Exchange::MEMarketUpdateLFQueue` type, which we defined before. This is meant to be used by `MarketDataConsumer` to publish the `MEMarketUpdate` messages to the trading engine component. 
- We will maintain a `next_exp_inc_seq_num_` varibale of the `size_t` type, which will be used to make sure that we process updates from the increase mental market data stream in the correct order and detect packet drops on the incremental market data stream. 
- We will have two mulcast subscriber sockets `incremental_mcast_socket_`. These correspond to the sockets we will use to subscribe to and cosume multicast data from the incremental and the snapshot multicast streams. 
- Finally, we define a type to queue up messages and order them by their corresponding sequence number. We will use the Standard Template Library, `std::map` type here and parameteize to ...

#### Proceesing market data updates and handling packet drops 
This section implements important functionality responsible for processing market data updates received on the incremental and the snapshot streams. Market updates on the incremental stream are received during the entire runtime of the `MarketDataConsumer` component. However, data is received and processed from the snapshot stream only when a sequence number gap is detected on the incremental stream, which causes `MarketDataConsumer` to initialize `snapshot_mcast_socket_` and subscribe to the snapshot multicast stream. Remember that in the constructor of `MarketDataConsumer`, we intentionally did not fully initialize `snapshot_mcast_socket` as we did with the `incremental_mcast_socket_`. The important thing to understand here is that data on the snapshot socket is only received when we are in recovery mode and not otherwise.

Otherwise, we proceed further and read `Exchange::MDPMarketUpdate` messages from the socket buffer using the same code 
that we have seen before. We go through the data contained in the socket->rcv_buffer_ buffer and read it in chunks of size equal to the size of Exchange::MDPMarketUpdate.
The goal here is to read as many full MDPMarketUpdate messages as possible
until we have read them all from the buffer. We use reinterpreter_cast to convert the data in the buffer to and object of the 
Exchagne::MDPMarketUpdate type

