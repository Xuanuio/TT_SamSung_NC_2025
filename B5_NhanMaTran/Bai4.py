MOD = 10**15 + 7

def matrix_mul(A, B):
    """Nhân hai ma trận 4x4 với modulo."""
    res = [[0]*4 for _ in range(4)]
    for i in range(4):
        for k in range(4):
            for j in range(4):
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD
    return res

def matrix_power(matrix, power):
    """Lũy thừa ma trận bằng phương pháp chia để trị."""
    result = [[1 if i == j else 0 for j in range(4)] for i in range(4)]  # Ma trận đơn vị
    while power:
        if power % 2 == 1:
            result = matrix_mul(result, matrix)
        matrix = matrix_mul(matrix, matrix)
        power //= 2
    return result

def solve(n):
    """Tính tổng N phần tử đầu tiên của dãy Tribonacci."""
    if n == 1: return 1
    if n == 2: return 3
    if n == 3: return 6

    # Ma trận chuyển trạng thái
    T = [
        [1, 1, 1, 0],  # T(n) = T(n-1) + T(n-2) + T(n-3)
        [1, 0, 0, 0],  # T(n-1)
        [0, 1, 0, 0],  # T(n-2)
        [1, 1, 1, 1]   # F(n) = F(n-1) + T(n)
    ]

    # Tính T^(n-3)
    Tn = matrix_power(T, n - 3)

    # Base vector tương ứng với [T(3), T(2), T(1), F(3)]
    base = [3, 2, 1, 6]

    # Nhân hàng thứ 4 (index 3) của Tn với vector base để lấy F(n)
    result = sum(Tn[3][i] * base[i] for i in range(4)) % MOD

    return result

t = int(input())
for _ in range(t):
    n = int(input())
    print(solve(n))