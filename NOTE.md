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

# TODO: Dừng lại tất cả, cần hoàn thành powpoint và luận văn trước 