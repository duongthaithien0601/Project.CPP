# CHƯƠNG TRÌNH VÍ ĐIỆN TỬ

## I. Giới thiệu dự án

Chương trình ví điện tử là một ứng dụng được viết bằng ngôn ngữ lập
trình C++ nhằm mô phỏng các chức năng của một ví điện tử. Người dùng có
thể thực hiện các thao tác như đăng ký tài khoản, đăng nhập, nạp điểm,
chuyển điểm, xác thực OTP, đổi mật khẩu, cập nhật thông tin cá nhân, và
xem lịch sử giao dịch. Hệ thống hỗ trợ vai trò quản lý với các chức năng
như đăng ký người dùng, cập nhật thông tin người dùng khác, và xem danh
sách người dùng. Dữ liệu được lưu trữ cục bộ trong các tệp văn bản
(users.txt, wallets.txt) với cơ chế sao lưu tự động vào các tệp
backup_users.txt và backup_wallets.txt. Ứng dụng đảm bảo tính an toàn
thông qua xác thực OTP và mã hóa mật khẩu cơ bản.

## II. Giới thiệu thành viên và phân công công việc

1. **Họ tên**: Dương Thái Thiện
   - **Vai trò**: Nhóm trưởng, Lập trình viên
   - **Công việc thực hiện**:
     - Thiết kế cấu trúc cốt lõi của hệ thống, bao gồm định nghĩa các lớp Wallet và User.
     - Lập trình chức năng đăng ký tài khoản, bao gồm xác thực OTP và tạo tài khoản mới.
     - Tham gia phát triển chức năng chuyển điểm, bao gồm kiểm tra người dùng và ví.
     - Quản lý nhóm, phân công công việc, và kiểm tra chất lượng mã nguồn.

2. **Họ tên**: Thái Tuấn Vũ
   - **Vai trò**: Lập trình viên
   - **Công việc thực hiện**:
     - Triển khai lưu trữ dữ liệu vào các tệp users.txt, wallets.txt và sao lưu vào backup_users.txt, backup_wallets.txt.
     - Lập trình chức năng đăng nhập, đổi mật khẩu và một phần của cập nhật thông tin cá nhân.
     - Hoàn thiện chức năng chuyển điểm, xem báo cáo ví, và xem danh sách người dùng dành cho quản lý.

3. **Họ tên**: Phan Nguyễn Tiến Vỹ
   - **Vai trò**: Lập trình viên
   - **Công việc thực hiện**:
     - Phát triển các hàm tiện ích bảo mật: mã hóa mật khẩu, sinh mật khẩu ngẫu nhiên, và sinh OTP.
     - Triển khai hàm tải dữ liệu từ tệp chính hoặc tệp sao lưu.
     - Lập trình chức năng nạp điểm, bao gồm xử lý quy đổi tiền và xác thực OTP.

## III. Đặc tả chức năng

### Chương trình bao gồm các chức năng sau:

1. **Đăng ký tài khoản**: 
   - Nhập tên đăng nhập, họ tên, email, mật khẩu và xác thực OTP để tạo tài khoản mới. 
   - Quản lý có thể đăng ký tài khoản với mật khẩu tự sinh.

2. **Đăng nhập**: 
   - Kiểm tra tên đăng nhập và mật khẩu, cho phép truy cập hệ thống. 
   - Tài khoản tự sinh yêu cầu đổi mật khẩu lần đầu.

3. **Nạp điểm**: 
   - Người dùng nhập số tiền và xác thực OTP để nạp điểm vào ví.

4. **Chuyển điểm**: 
   - Chuyển điểm đến tài khoản khác, yêu cầu xác thực OTP và kiểm tra số dư.

5. **Đổi mật khẩu**: 
   - Thay đổi mật khẩu sau khi xác thực OTP.

6. **Cập nhật thông tin**: 
   - Cập nhật họ tên và email, yêu cầu OTP. 
   - Quản lý có thể cập nhật thông tin người dùng khác với OTP xác nhận từ người đó.

7. **Xem báo cáo ví**: 
   - Hiển thị số dư, giá trị quy đổi (đô la) và lịch sử giao dịch của ví.

8. **Xem danh sách người dùng**: 
   - Chỉ dành cho quản lý, hiển thị thông tin tất cả người dùng.

9. **Lưu dữ liệu**: 
   - Tự động lưu thông tin người dùng và ví vào tệp văn bản, với sao lưu tự động.

10. **Xác thực OTP**: 
    - Tạo mã OTP 6 chữ số để bảo mật đăng ký, giao dịch, và cập nhật thông tin.

### Cấu trúc file dữ liệu

- **users.txt**: Lưu thông tin người dùng (tên đăng nhập, mật khẩu mã hóa, họ tên, email, ID ví, trạng thái quản lý, trạng thái tự sinh).
- **wallets.txt**: Lưu thông tin ví (ID ví, số dư, lịch sử giao dịch).
- **backup_users.txt**: Sao lưu dữ liệu người dùng.
- **backup_wallets.txt**: Sao lưu dữ liệu ví.

## IV. Hướng dẫn tải và biên dịch chương trình

- **Bước 1**: Tải mã nguồn từ kho lưu trữ này hoặc từ tệp Baitaplon.cpp đã được chia sẻ.
- **Bước 2**: Mở Visual Studio Code (hoặc bất kỳ IDE nào hỗ trợ C++).
- **Bước 3**: Biên dịch chương trình bằng trình biên dịch g++ (hoặc công cụ tương đương).  
  Ví dụ dòng lệnh: `g++ Baitaplon.cpp -o baitaplon.exe`
- **Bước 4**: Đảm bảo các tệp dữ liệu (users.txt, wallets.txt, backup_users.txt, backup_wallets.txt) nằm trong cùng thư mục với tệp thực thi.

## V. Hướng dẫn sử dụng chương trình

1. Mở Visual Studio Code (hoặc bất kỳ IDE nào hỗ trợ C++).
2. Chạy chương trình: `./baitaplon` (Linux) hoặc `baitaplon.exe` (Windows).
3. Làm theo hướng dẫn hiển thị trên màn hình để:
   - **Đăng ký tài khoản**: Nhập thông tin, xác thực OTP.
   - **Đăng nhập tài khoản**: Yêu cầu đổi mật khẩu nếu tài khoản tự sinh.
   - **Nạp điểm**: Nhập số tiền đô la, xác thực OTP.
   - **Chuyển điểm**: Nhập người nhận, số điểm, xác thực OTP.
   - **Đổi mật khẩu**: Xác thực OTP.
   - **Cập nhật thông tin cá nhân**: Xác thực OTP.
   - **Xem báo cáo ví**: Xem số dư, lịch sử giao dịch.
   - **Quản lý** (nếu là quản lý): Đăng ký người dùng, cập nhật thông tin người dùng khác, xem danh sách người dùng.
   - **Thoát chương trình**: Dữ liệu sẽ tự động lưu vào users.txt, wallets.txt và sao lưu vào backup_users.txt, backup_wallets.txt.

## VI. Mô tả chi tiết cách chương trình hoạt động

Khi khởi chạy chương trình, hệ thống tải dữ liệu từ users.txt và wallets.txt. Nếu không có dữ liệu, hệ thống tạo tài khoản quản trị mặc
định (admin, mật khẩu: admin@123, ví ID: 0, số dư: 10,000 điểm). Menu chính hiển thị các tùy chọn sau:

1. **Đăng ký tài khoản**:
   - Người dùng nhập tên đăng nhập, họ tên, email, và mật khẩu.
   - Hệ thống tạo mã OTP 6 chữ số ngẫu nhiên và yêu cầu người dùng nhập để xác thực.
   - Quản lý có thể đăng ký tài khoản với mật khẩu tự sinh, được đánh dấu là tài khoản tự sinh.
   - Thông tin được lưu vào users.txt, ví mới được tạo và lưu vào wallets.txt.

2. **Đăng nhập hệ thống**:
   - Nhập tên đăng nhập và mật khẩu. Mật khẩu được mã hóa và so sánh với dữ liệu lưu trữ.
   - Nếu là tài khoản tự sinh, yêu cầu đổi mật khẩu ngay lần đăng nhập đầu.
   - Nếu thông tin sai, báo lỗi.

3. **Sau khi đăng nhập**, menu cung cấp các lựa chọn:
   - **Nạp điểm**:
     - Người dùng nhập số tiền
     - Xác thực OTP để hoàn tất.
     - Điểm được cộng vào ví, lịch sử giao dịch cập nhật trong wallets.txt.

   - **Chuyển điểm**:
     - Nhập tên tài khoản người nhận và số điểm.
     - Kiểm tra số dư, yêu cầu xác thực OTP.
     - Trừ điểm từ ví người gửi, cộng điểm cho người nhận, cập nhật lịch sử giao dịch.

   - **Đổi mật khẩu**:
     - Yêu cầu xác thực OTP, nhập mật khẩu mới.
     - Mật khẩu được mã hóa và cập nhật trong users.txt.

   - **Cập nhật thông tin**:
     - Cập nhật họ tên và email, yêu cầu xác thực OTP.
     - Quản lý có thể cập nhật thông tin người dùng khác, yêu cầu OTP từ người đó.
     - Dữ liệu được lưu vào users.txt.

   - **Xem báo cáo ví**:
     - Hiển thị ID ví, số dư (điểm và đô la tương đương), và lịch sử giao dịch.

   - **Xem danh sách người dùng** (chỉ quản lý):
     - Hiển thị thông tin tất cả người dùng: tên đăng nhập, họ tên, email, ID ví, trạng thái quản lý.

   - **Thoát chương trình**:
     - Lưu toàn bộ dữ liệu vào users.txt, wallets.txt.
     - Tạo bản sao lưu vào backup_users.txt, backup_wallets.txt bằng lệnh hệ thống (copy trên Windows, cp trên Unix).

## VII. Sơ đồ mô tả cách chương trình hoạt động

```
                    +-------------------+
                    | Khởi động hệ thống|
                    +-------------------+
                              |
                              v
                    +-------------------+
                    |  Tải dữ liệu từ   |
                    |  users.txt và     |
                    |  wallets.txt      |
                    +-------------------+
                              |
                              v
                    +-------------------+
                    |     Menu chính    |
                    +-------------------+
                              |
            +----------------+----------------+
            |                |                |
            v                v                v
    +-------------+  +-------------+  +-------------+
    | Đăng ký tài |  |  Đăng nhập  |  |   Thoát     |
    |   khoản     |  |             |  |             |
    +-------------+  +-------------+  +-------------+
                              |
                              v
                    +-------------------+
                    |   Menu người dùng |
                    +-------------------+
                              |
      +----------+----------+---------+----------+----------+
      |          |          |         |          |          |      
      v          v          v         v          v          v      
  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
  | Nạp   |  |Chuyển |  | Đổi   |  | Cập   |  | Xem   |  | Xem   |
  | điểm  |  | điểm  |  | mật   |  | nhật  |  | báo   |  | danh  |
  |       |  |       |  | khẩu  |  | thông |  | cáo   |  | sách  |
  |       |  |       |  |       |  | tin   |  | ví    |  | người |
  +-------+  +-------+  +-------+  +-------+  +-------+  | dùng  |
                                                         +-------+
```

## VIII. Tài liệu tham khảo

- Tài liệu C++ từ trang [cppreference.com](https://en.cppreference.com/w/).
- Diễn đàn thảo luận [StackOverflow](https://stackoverflow.com/).
- Trang tài liệu học lập trình: [GeeksforGeeks](https://www.geeksforgeeks.org/cpp-programming-language/).
- Tài liệu về quản lý tệp và bảo mật trong C++: [cplusplus.com](https://www.cplusplus.com/).
