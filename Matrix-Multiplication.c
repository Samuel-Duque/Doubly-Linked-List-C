def matrix_multiplication(matrix1, matrix2):
    rows_matrix1 = len(matrix1)
    columns_matrix2 = len(matrix2[0])
    result = [[0 for _ in range(columns_matrix2)] for _ in range(rows_matrix1)]

    for i in range(rows_matrix1):
        for j in range(columns_matrix2):
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result

matrix_a = [[5, 12, 2], [4, 1, 4, -5]]
matrix_b = [[11, 8], [9, 13], [18, 17]]

result = matrix_multiplication(matrix_a, matrix_b)
for row in result:
    print(row)


