# Định nghĩa hàm nhân 2 ma trận 2x2 modulo MOD
def multiply_matrix(a, b, MOD):
    res = [[0, 0], [0, 0]]  # Khởi tạo ma trận kết quả 2x2
    for i in range(2):
        for j in range(2):
            for k in range(2):
                # Nhân từng phần tử và cộng dồn, sau đó lấy modulo
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD
    return res

# Hàm lũy thừa ma trận bằng phương pháp bình phương nhị phân
def matrix_power(matrix, n, MOD):
    # Ma trận đơn vị 2x2
    result = [[1, 0], [0, 1]]
    while n > 0:
        if n % 2 == 1:
            result = multiply_matrix(result, matrix, MOD)
        matrix = multiply_matrix(matrix, matrix, MOD)
        n //= 2
    return result

# Hàm chính để tính F(n) theo ma trận Fibonacci
def fibonacci(n, MOD):
    if n == 0 or n == 1:
        return 1 % MOD

    # Ma trận cơ sở Fibonacci: [[1, 1], [1, 0]]
    base = [[1, 1], [1, 0]]
    result = matrix_power(base, n, MOD)
    return result[0][0]  # F(n) là phần tử ở vị trí [0][0]

# Đọc input và xử lý nhiều test case
t = int(input())
for _ in range(t):
    n, MOD = map(int, input().split())
    print(fibonacci(n, MOD))