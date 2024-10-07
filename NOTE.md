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
- ...
- ...
### 2. Thiết kế nhóm bộ nhớ C++ để tránh cấp phát bộ nhớ động
#### 2.1. Hiểu các trường hợp sử dụng của nhóm bộ nhớ 
- Khi số lượng đối tượng chính xác của một loại nhất định được yêu cầu 
biết trước, ta có thể tạo chính xác số đó khi cần. 
- Thực tế, có nhiều trường hợp số lượng đối tượng chính xác không được biết trước. Điều này có nghĩa là ta cần tạo các đối tượng một cách nhanh chóng bằng cách sử dụng phân bổ bộ nhớ động. 
- Phân bổ bộ nhớ động là một quá trình rất chậm và là một vấn đề đối với các ứng dụng có độ trễ thấp. 
- Thuật ngữ `memory pool` để mô tả một nhóm các đối tượng thuộc một loại nhất định và đó là những gì chúng tôi sẽ xây dựng trong phần này. 
- Giải pháp, chúng ta sẽ phân bổ trước các khối bộ nhớ lớn khi khởi động và phục vụ số lượng cần thiết trong thời gian chạy - nghĩa là tự thực hiện các bước phân bổ bộ nhớ từ nhóm lưu trữ.
