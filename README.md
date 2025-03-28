# NMLT_Project_2
Đồ án 2 NMLT
- Đề: Xây dựng phần mềm quản lý thư viện cho HCMUS
Đồ án này đã được phép sử dụng Struct và đọc file để thực hiện
Xây dụng đồ án này theo hướng Top-down

1. MainMenu sẽ chứa các đơn thể độc lập với nhau
    + Reader: độc giả
    + Book: sách
    + Bookloan: phiếu mượn sách
    + Query/Statistic: Thống kê
    + GetData: Lấy dữ liệu (đọc files)
    => Chia tách ra và xử lý từng đơn thể một
2. Phân tích xem từng đơn thể nó có những công việc gì (theo yêu cầu đề bài của từng cái) và xây dựng bản thô trước.
3. Bắt tay vào code từng cái và kiểm tra nó hoạt động.
4. Hoàn tất code phiên bản đầu tiên.
5. Công việc quan trọng: DEBUG. (lúc đó bạn muốn gọi là phiên bản mấy cũng được: demo, alpha, beta, closed-beta, early-accessed gì đó tùy mọi người code)
6. Debug đến khi chương trình hoạt động ổn (đừng mong hoàn hảo chỉn chu mọi thứ quá, nên ở mức đủ là được).

Nếu có thể để debug dễ dàng hơn thì mình đã định nghĩa các struct ở trong 1 file object.cpp.
Tại file Object.cpp, mình đã lần lượt định nghĩa cho Reader, Book, BookLoan và Date(nhằm mục đích lưu trữ ngày dễ dàng hơn)
Thông thường khi học môn "Nhập môn lập trình" đối với K23 về trước và "Cơ sở lập trình" đối với K24 về sau, struct 
có thể chỉ được học kiểu là lưu các trường thuộc tính trong đó nhưng thật ra chúng ta có thể sử dụng nó như là class một cách bình thường

Lý do mình nói vậy vì hồi mình thi cuối kì OOP, đã có một câu hỏi lý thuyết với câu hỏi như sau
"Tell the difference between struct and class/ Sự khác nhau của struct và class".

Câu trả lời thì mình sẽ dẫn link tham khảo của anh Nguyễn Hồng Đức đã Livestream:
https://github.com/nguyenhongduc2411/Nostalgia/blob/main/OOP/2024-2025-CLC/Cau1.txt

Cho nên nếu hiểu được class thì có thể dùng struct như class và định nghĩa toán tử lại cho chúng.
Mục đích mình định nghĩa chỉ nhằm mục đích tiết kiệm thời gian viết code của mình thôi
Thông thường thì ta sẽ định nghĩa "The big Three" là:
    - Copy constructor (Nếu bạn muốn nhàn hơn thì thêm 1 hàm tạo mặc định với đầy đủ tham số)
    - Assignment operator (cái này giúp mình tiết kiệm kha khá thời gian để viết code).
    - Destructor (Có thể bỏ qua nếu các thuộc tính ta định nghĩa là vùng nhớ Stack, không dùng vùng nhớ Heap)
Vì các struct đều tựu chung lại tại 1 file nên các đơn thể khác có thể gọi file này mà không sợ xung đột

Ngoài ra mình có thêm một file là Method.cpp trong trường hợp cần dùng một số hàm và công việc khác mà có dùng các tham số của struct và nó sẽ là trung gian cho file Object.cpp và các đơn thể khác vì mỗi đơn thể sẽ gọi Method.cpp và trong đó nó gọi lại cho Object.cpp.
Đối với mình thì việc làm như vậy sẽ khiến cho mỗi đơn thể sẽ độc lập với nhau, không đơn thể nào đụng chạm đến đơn thể nào, thậm chí có những hàm mà có thể xài chung được mà không phải gọi các đơn thể lẫn nhau.
Tiếp là đối với những hàm dành cho mục đích trang trí hay là kiểm tra mấy cái lặt vặt (ví dụ như kiểm tra ngày tháng hay mấy khung viền gì đó) thì mình sẽ code nó ở trong file Support.cpp, các hằng số thì định nghĩa ở file Constants.h.
Include 2 file này vào Object.cpp.

Lưu ý: các struct thì 3 struct chính mình chỉ định nghĩa thuộc tính và một số toán tử mình cần.