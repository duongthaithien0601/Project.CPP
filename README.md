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
     - Lập trình chức năng đăng ký tài khoản, tạo mã OTP và tạo tài khoản mới.
     - Tham gia phát triển chức năng chuyển điểm, bao gồm kiểm tra người dùng và ví.
     - Quản lý nhóm, phân công công việc.

2. **Họ tên**: Thái Tuấn Vũ
   - **Vai trò**: Lập trình viên
   - **Công việc thực hiện**:
     - Triển khai lưu trữ dữ liệu vào các tệp users.txt, wallets.txt và sao lưu vào backup_users.txt, backup_wallets.txt.
     - Lập trình chức năng đăng nhập, đổi mật khẩu, gửi mã otp qua email và một phần của cập nhật thông tin cá nhân.
     - Hoàn thiện chức năng chuyển điểm, xem báo cáo ví, và xem danh sách người dùng dành cho quản lý.
     - Kiểm tra chất lượng mã nguồn.
       
3. **Họ tên**: Phan Nguyễn Tiến Vỹ
   - **Vai trò**: Lập trình viên
   - **Công việc thực hiện**:
     - Phát triển các hàm tiện ích bảo mật: mã hóa mật khẩu, sinh mật khẩu ngẫu nhiên.
     - Triển khai hàm tải dữ liệu từ tệp chính hoặc tệp sao lưu.
     - Lập trình chức năng nạp điểm, bao gồm xử lý quy đổi tiền.
     - Viết báo cáo dự án.

## III. Đặc tả chức năng

### Chương trình bao gồm các chức năng sau:

1. **Đăng ký tài khoản**: 
   - Nhập tên đăng nhập, họ tên, email, mật khẩu và xác thực OTP để tạo tài khoản mới. 
   - Quản lý có thể đăng ký tài khoản với mật khẩu tự sinh.

2. **Đăng nhập**: 
   - Nhập tên đăng nhập, email, mật khẩu và xác thực OTP để đăng nhập.
   - Tài khoản tự sinh yêu cầu đổi mật khẩu lần đầu.

3. **Nạp điểm**: 
   - Người dùng nhập số tiền và xác thực OTP để nạp điểm vào ví.

4. **Chuyển điểm**: 
   - Chuyển điểm đến tài khoản khác, yêu cầu xác thực OTP và kiểm tra số dư.

5. **Đổi mật khẩu**: 
   - Thay đổi mật khẩu sau khi xác thực OTP.

6. **Cập nhật thông tin**: 
   - Cập nhật họ tên và email, yêu cầu xác thực OTP. 
   - Quản lý có thể cập nhật tất cả thông tin của người với OTP xác nhận từ người đó.

7. **Xem báo cáo ví**: 
   - Hiển thị số dư, giá trị quy đổi (đô la) và lịch sử giao dịch của ví.

8. **Xem danh sách người dùng**: 
   - Chỉ dành cho quản lý, hiển thị thông tin tất cả người dùng.

9. **Lưu dữ liệu**: 
   - Tự động lưu thông tin người dùng và ví vào tệp văn bản, với sao lưu tự động.

10. **Xác thực OTP**: 
    - Tạo mã OTP 6 chữ số để bảo mật đăng ký, giao dịch, và cập nhật thông tin.

## IV. Hướng dẫn tải và biên dịch chương trình

## Yêu cầu Hệ thống

### Hệ điều hành
- **Windows** (với MSYS2)

### Thư viện bắt buộc
- **Trình biên dịch**: g++ hỗ trợ C++11 trở lên
- **Thư viện bổ sung**: libcurl (để gửi email OTP)

### Các bước biên dịch:

### 1. Cài đặt MSYS2
- Tải và cài đặt MSYS2 từ https://www.msys2.org/
- Mở MSYS2 terminal và cài đặt libcurl:
```bash
pacman -S mingw-w64-x86_64-curl
```

### 2. Tải mã nguồn
```bash
git clone [repository-url]
cd [project-folder]
```
hoặc tải file `Baitaplon.cpp` trực tiếp.

### 3. Biên dịch trên Windows
```bash
# Sử dụng g++ từ MSYS2
C:/msys64/mingw64/bin/g++.exe Baitaplon.cpp -o Baitaplon.exe -I C:/msys64/mingw64/include -L C:/msys64/mingw64/lib -lcurl
```

### 4. Cấu hình VS Code (tùy chọn)
Nếu sử dụng Visual Studio Code, file `tasks.json` đã được cấu hình sẵn trong thư mục `.vscode/` để build tự động.

### 5. Chạy chương trình
```cmd
Baitaplon.exe
```

## Cấu hình Email

### Thiết lập Gmail SMTP
1. Vào Google Account → Security
2. Bật **2-Step Verification** trong tài khoản Gmail
3. Tạo **App Password** cho ứng dụng
4. Cập nhật thông tin trong mã nguồn:

```cpp
const string from = "your-email@gmail.com";  // Email của bạn
const string pass = "your-app-password";     // App Password
```

### Cấu hình SMTP khác
Để sử dụng nhà cung cấp email khác, thay đổi:
```cpp
curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.your-provider.com:465");
```

### Lưu ý quan trọng
Trong mã nguồn, bạn **BẮT BUỘC** phải thay đổi thông tin email và mật khẩu ứng dụng Gmail:

```cpp
const string from = "your-email@gmail.com";  // Thay bằng email của bạn
const string pass = "your-app-password";     // Thay bằng mật khẩu ứng dụng Gmail
```
## Chú ý

### Thông tin tài khoản Admin mặc định
- **Tên đăng nhập**: `admin`
- **Mật khẩu**: `admin@123`
- **Quyền**: Quản trị viên (có thể quản lý tất cả người dùng)
- **Số dư khởi tạo**: 10,000 điểm
- **Đặc biệt**: Không cần OTP khi đăng nhập

### Cấu trúc Files dữ liệu
Chương trình tự động tạo và quản lý các file:
- `users.txt`: Lưu thông tin người dùng
- `wallets.txt`: Lưu thông tin ví và giao dịch  
- `backup_users.txt`: File sao lưu người dùng
- `backup_wallets.txt`: File sao lưu ví

### Lưu ý bảo mật:
- Tất cả giao dịch quan trọng đều yêu cầu xác thực OTP
- Mật khẩu được mã hóa trước khi lưu trữ
- Hệ thống tự động sao lưu dữ liệu
- Email phải hợp lệ để nhận OTP

## Xử lý lỗi thường gặp:
- **"Khong the gui OTP"**: Kiểm tra kết nối internet và cấu hình email
- **"OTP khong hop le"**: Kiểm tra mã OTP trong email (có thể nằm trong spam)
- **"Nguoi dung da ton tai"**: Chọn tên đăng nhập khác
- **"So du khong du"**: Nạp thêm điểm trước khi chuyển
- **"File khong tim thay"**: Chương trình sẽ tự tạo file mới hoặc dùng backup

## V. Hướng dẫn sử dụng chương trình

### Khởi chạy chương trình:

### Giao diện menu chính:
Khi chạy chương trình, bạn sẽ thấy menu với các lựa chọn:
```
1. Dang ky
2. Dang nhap
3. Doi mat khau
4. Cap nhat thong tin
5. Chuyen diem
6. Xem vi
7. Dang ky boi quan ly
8. Xem danh sach nguoi dung (Quan ly)
9. Cap nhat thong tin boi quan ly
10. Nap diem
11. Thoat
```

### Hướng dẫn từng chức năng:

Khi khởi chạy chương trình, hệ thống tải dữ liệu từ users.txt và wallets.txt. Menu chính hiển thị các tùy chọn sau:

#### 1. Đăng ký tài khoản (Lựa chọn 1):
- Nhập tên đăng nhập (không được trùng)
- Nhập họ tên đầy đủ
- Nhập địa chỉ email hợp lệ
- Nhập mật khẩu
- Hệ thống sẽ gửi mã OTP 6 chữ số đến email
- Nhập mã OTP để hoàn tất đăng ký

#### 2. Đăng nhập (Lựa chọn 2):
- Nhập tên đăng nhập
- Nhập mật khẩu
- Với tài khoản thường: hệ thống gửi OTP đến email để xác thực
- Với tài khoản admin mặc định: thì không cần OTP.

#### 3. Đổi mật khẩu (Lựa chọn 3):
- **Yêu cầu**: Phải đăng nhập trước
- Hệ thống gửi OTP đến email đăng ký
- Nhập OTP và mật khẩu mới

#### 4. Cập nhật thông tin cá nhân (Lựa chọn 4):
- **Yêu cầu**: Phải đăng nhập trước
- Hệ thống gửi OTP đến email hiện tại
- Nhập OTP, sau đó nhập họ tên mới, email mới.

#### 5. Chuyển điểm (Lựa chọn 5):
- **Yêu cầu**: Phải đăng nhập trước
- Nhập tên người nhận (phải tồn tại trong hệ thống)
- Nhập số điểm muốn chuyển (phải ≤ số dư hiện tại)
- Xác thực bằng OTP gửi đến email

#### 6. Xem ví (Lựa chọn 6):
- **Yêu cầu**: Phải đăng nhập trước
- Hiển thị:
  - ID ví
  - Số dư hiện tại (điểm và tương đương USD)

#### 7. Đăng ký bởi quản lý (Lựa chọn 7):
- **Yêu cầu**: Phải đăng nhập với tài khoản quản lý
- Quản lý nhập thông tin người dùng mới
- Hệ thống tự sinh mật khẩu và hiển thị
- Gửi OTP đến email để xác thực

#### 8. Xem danh sách người dùng (Lựa chọn 8):
- **Yêu cầu**: Phải đăng nhập với tài khoản quản lý
- Hiển thị tất cả thông tin người dùng trong hệ thống

#### 9. Cập nhật thông tin bởi quản lý (Lựa chọn 9):
- **Yêu cầu**: Phải đăng nhập với tài khoản quản lý
- Nhập tên đăng nhập người cần cập nhật
- Nhập thông tin mới
- **Quan trọng**: Cần có sự xác nhận từ người dùng bằng OTP

#### 10. Nạp điểm (Lựa chọn 10):
- **Yêu cầu**: Phải đăng nhập trước
- Nhập số tiền (USD) - **Tỷ lệ quy đổi: 10 USD = 1 điểm**
- Xác thực bằng OTP
- Điểm được cộng vào ví tự động

#### 11. Thoát (Lựa chọn 11):
- Lưu tự động toàn bộ dữ liệu
- Tạo file backup
- Kết thúc chương trình

## VI. Sơ đồ mô tả cách chương trình hoạt động

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
    | Đăng ký tài |  |  Đăng nhập  |  |    Thoát    |
    |    khoản    |  |             |  |             |
    +-------------+  +-------------+  +-------------+
                              |
                              v
                    +-------------------+
                    |  Menu người dùng  |
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

## VII. Tài liệu tham khảo

### A. Tài liệu về ngôn ngữ lập trình C++
- **C++ Reference**: [cppreference.com](https://en.cppreference.com/w/) - Tài liệu tham khảo cú pháp C++
- **GeeksforGeeks C++**: [geeksforgeeks.org/cpp-programming-language](https://www.geeksforgeeks.org/cpp-programming-language/) - Hướng dẫn và ví dụ C++ cơ bản
- **Cplusplus.com**: [cplusplus.com](https://www.cplusplus.com/) - Hướng dẫn C++ từ cơ bản đến nâng cao

### B. Thư viện sử dụng trong dự án
- **libcurl Documentation**: [curl.se/libcurl](https://curl.se/libcurl/) - Tài liệu chính thức của thư viện libcurl
- **CURL Programming Tutorial**: [curl.se/libcurl/c](https://curl.se/libcurl/c/) - Hướng dẫn lập trình với libcurl
- **C++ Standard Library Reference**: [cplusplus.com/reference](https://cplusplus.com/reference/) - Tài liệu thư viện chuẩn C++

### C. Kiến thức về bảo mật cơ bản
- **Hash Functions**: Tìm hiểu về hàm băm để mã hóa mật khẩu
- **OTP (One-Time Password)**: Khái niệm mã xác thực một lần

### D. Xử lý file và dữ liệu
- **File I/O in C++**: [cplusplus.com/doc/tutorial/files](https://cplusplus.com/doc/tutorial/files/) - Đọc/ghi file trong C++
- **String Processing**: Xử lý chuỗi và phân tách dữ liệu
- **JSON for Modern C++**: [github.com/nlohmann/json](https://github.com/nlohmann/json) - Thư viện JSON cho C++

### E. Tài liệu về email và SMTP
- **SMTP Protocol RFC 5321**: [tools.ietf.org/rfc/rfc5321.txt](https://tools.ietf.org/rfc/rfc5321.txt) - Giao thức SMTP chính thức
- **Gmail API Documentation**: [developers.google.com/gmail/api](https://developers.google.com/gmail/api) - Tài liệu Gmail API

### F. Cộng đồng hỗ trợ
- **Stack Overflow**: [stackoverflow.com](https://stackoverflow.com/) - Diễn đàn hỏi đáp lập trình
- **Reddit r/cpp**: [reddit.com/r/cpp](https://www.reddit.com/r/cpp/) - Cộng đồng C++
- **C++ Users Group**: [isocpp.org](https://isocpp.org/) - Tổ chức tiêu chuẩn C++
- **GitHub**: [github.com](https://github.com/) - Kho mã nguồn mở
- **Dev.to C++ Community**: [dev.to/t/cpp](https://dev.to/t/cpp) - Cộng đồng chia sẻ kiến thức

### G. Công cụ phát triển
- **Visual Studio Code**: [code.visualstudio.com](https://code.visualstudio.com/) - Trình soạn thảo code miễn phí
- **MSYS2**: [msys2.org](https://www.msys2.org/) - Môi trường biên dịch trên Windows
- **MinGW-w64**: Trình biên dịch C++ cho Windows