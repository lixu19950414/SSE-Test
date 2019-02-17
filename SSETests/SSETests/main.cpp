#include <xmmintrin.h>
#include <iostream>

__m128 add(__m128 a, __m128 b)
{
	__m128 r = _mm_add_ps(a, b);
	return r;
}

__declspec(align(16)) float A[] = { 2.0f, -1.0f, 3.0f, 4.0f };
__declspec(align(16)) float B[] = { 3.0f, -2.0f, 2.0f, 1.0f };
__declspec(align(16)) float C[] = { 0.0f, 0.0f, 0.0f, 0.0f };

int main()
{
	__m128 a = _mm_load_ps(A);
	__m128 b = _mm_load_ps(B);
	__m128 c = _mm_add_ps(a, b);
	_mm_store_ps(&C[0], c);
	printf("%g:%g:%g:%g\n", A[0], A[1], A[2], A[3]);
	printf("%g:%g:%g:%g\n", B[0], B[1], B[2], B[3]);
	printf("%g:%g:%g:%g\n", C[0], C[1], C[2], C[3]);
	system("pause");
	return 0;
}
