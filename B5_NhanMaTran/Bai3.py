# Hàm nhân hai ma trận 3x3 theo modulo BASE
def multiply_matrix(a, b, BASE):
    res = [[0] * 3 for _ in range(3)]  # Khởi tạo ma trận kết quả 3x3 toàn 0
    for i in range(3):
        for j in range(3):
            for k in range(3):
                # Nhân và cộng các phần tử tương ứng, sau đó lấy modulo
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % BASE
    return res

# Hàm lũy thừa ma trận theo phương pháp "exponentiation by squaring"
def matrix_power(matrix, power, BASE):
    # Khởi tạo ma trận đơn vị (identity matrix)
    result = [[1 if i == j else 0 for j in range(3)] for i in range(3)]
    while power > 0:
        if power % 2 == 1:
            result = multiply_matrix(result, matrix, BASE)  # Nếu power lẻ, nhân vào result
        matrix = multiply_matrix(matrix, matrix, BASE)  # Bình phương ma trận
        power //= 2  # Giảm power đi một nửa
    return result

# Hàm chính tính số Tesla thứ n theo công thức truy hồi
def compute_tesla(n, BASE):
    # Các giá trị cơ bản
    if n == 1:
        return 1
    if n == 2:
        return 2
    if n == 3:
        return 3

    # Ma trận chuyển vị biểu diễn công thức:
    # T(n) = T(n-1) + 2*T(n-2) + 3*T(n-3)
    A = [
        [1, 2, 3],  # hàng đầu tiên tính T(n) từ [T(n-1), T(n-2), T(n-3)]
        [1, 0, 0],  # dịch T(n-1) -> T(n-2)
        [0, 1, 0]   # dịch T(n-2) -> T(n-3)
    ]

    # Tính A^(n-3) để áp dụng vào công thức
    An = matrix_power(A, n - 3, BASE)

    # Vector khởi tạo ban đầu [T(3), T(2), T(1)] = [3, 2, 1]
    # Nhân hàng đầu tiên của ma trận kết quả với vector này
    Tn = (An[0][0] * 3 + An[0][1] * 2 + An[0][2] * 1) % BASE
    return Tn

# Đọc số lượng test
T = int(input())
for _ in range(T):
    n, BASE = map(int, input().split())
    print(compute_tesla(n, BASE))