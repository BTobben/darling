#include <stdint.h>
#include <stddef.h>

/*
 * Temporary Darling/Codex experiment.
 * Minimal vDSP ABI shims for Chromium/Electron.
 */

#define ACCEL_COMPAT_EXPORT __attribute__((visibility("default"), used))

typedef long vDSP_Stride;
typedef unsigned long vDSP_Length;

typedef struct {
    float real;
    float imag;
} DSPComplex;

typedef struct {
    float *realp;
    float *imagp;
} DSPSplitComplex;

typedef void *FFTSetup;

static int codex_fftsetup_token;

static float codex_absf(float x) {
    return x < 0.0f ? -x : x;
}

ACCEL_COMPAT_EXPORT void vDSP_vsadd(const float *A, vDSP_Stride IA, const float *B, float *C, vDSP_Stride IC, vDSP_Length N) {
    float b = B ? *B : 0.0f;
    for (vDSP_Length i = 0; i < N; i++) {
        C[i * IC] = A[i * IA] + b;
    }
}

ACCEL_COMPAT_EXPORT void vDSP_vsmul(const float *A, vDSP_Stride IA, const float *B, float *C, vDSP_Stride IC, vDSP_Length N) {
    float b = B ? *B : 0.0f;
    for (vDSP_Length i = 0; i < N; i++) {
        C[i * IC] = A[i * IA] * b;
    }
}

ACCEL_COMPAT_EXPORT void vDSP_vsma(const float *A, vDSP_Stride IA, const float *B, const float *C, vDSP_Stride IC, float *D, vDSP_Stride ID, vDSP_Length N) {
    float b = B ? *B : 0.0f;
    for (vDSP_Length i = 0; i < N; i++) {
        D[i * ID] = (A[i * IA] * b) + C[i * IC];
    }
}

ACCEL_COMPAT_EXPORT void vDSP_vadd(const float *A, vDSP_Stride IA, const float *B, vDSP_Stride IB, float *C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; i++) {
        C[i * IC] = A[i * IA] + B[i * IB];
    }
}

ACCEL_COMPAT_EXPORT void vDSP_vsub(const float *A, vDSP_Stride IA, const float *B, vDSP_Stride IB, float *C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; i++) {
        C[i * IC] = B[i * IB] - A[i * IA];
    }
}

ACCEL_COMPAT_EXPORT void vDSP_vmul(const float *A, vDSP_Stride IA, const float *B, vDSP_Stride IB, float *C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; i++) {
        C[i * IC] = A[i * IA] * B[i * IB];
    }
}

ACCEL_COMPAT_EXPORT void vDSP_vclip(const float *A, vDSP_Stride IA, const float *low, const float *high, float *C, vDSP_Stride IC, vDSP_Length N) {
    float lo = low ? *low : 0.0f;
    float hi = high ? *high : lo;
    for (vDSP_Length i = 0; i < N; i++) {
        float v = A[i * IA];
        if (v < lo) v = lo;
        if (v > hi) v = hi;
        C[i * IC] = v;
    }
}

ACCEL_COMPAT_EXPORT void vDSP_svesq(const float *A, vDSP_Stride IA, float *C, vDSP_Length N) {
    float sum = 0.0f;
    for (vDSP_Length i = 0; i < N; i++) {
        float v = A[i * IA];
        sum += v * v;
    }
    if (C) *C = sum;
}

ACCEL_COMPAT_EXPORT void vDSP_maxmgv(const float *A, vDSP_Stride IA, float *C, vDSP_Length N) {
    float maxv = 0.0f;
    for (vDSP_Length i = 0; i < N; i++) {
        float v = codex_absf(A[i * IA]);
        if (v > maxv) maxv = v;
    }
    if (C) *C = maxv;
}

ACCEL_COMPAT_EXPORT void vDSP_conv(const float *A, vDSP_Stride IA, const float *F, vDSP_Stride IF, float *C, vDSP_Stride IC, vDSP_Length N, vDSP_Length P) {
    for (vDSP_Length n = 0; n < N; n++) {
        float acc = 0.0f;
        for (vDSP_Length p = 0; p < P; p++) {
            acc += A[(n + p) * IA] * F[p * IF];
        }
        C[n * IC] = acc;
    }
}

ACCEL_COMPAT_EXPORT void vDSP_deq22D(const double *A, vDSP_Stride IA, const double *B, double *C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; i++) {
        C[i * IC] = A ? A[i * IA] : 0.0;
    }
}

ACCEL_COMPAT_EXPORT void vDSP_ctoz(const DSPComplex *C, vDSP_Stride IC, DSPSplitComplex *Z, vDSP_Stride IZ, vDSP_Length N) {
    if (!C || !Z) return;
    for (vDSP_Length i = 0; i < N; i++) {
        Z->realp[i * IZ] = C[i * IC].real;
        Z->imagp[i * IZ] = C[i * IC].imag;
    }
}

ACCEL_COMPAT_EXPORT void vDSP_ztoc(const DSPSplitComplex *Z, vDSP_Stride IZ, DSPComplex *C, vDSP_Stride IC, vDSP_Length N) {
    if (!C || !Z) return;
    for (vDSP_Length i = 0; i < N; i++) {
        C[i * IC].real = Z->realp[i * IZ];
        C[i * IC].imag = Z->imagp[i * IZ];
    }
}

ACCEL_COMPAT_EXPORT void vDSP_zvmul(const DSPSplitComplex *A, vDSP_Stride IA, const DSPSplitComplex *B, vDSP_Stride IB, DSPSplitComplex *C, vDSP_Stride IC, vDSP_Length N, int conjugate) {
    if (!A || !B || !C) return;

    for (vDSP_Length i = 0; i < N; i++) {
        float ar = A->realp[i * IA];
        float ai = A->imagp[i * IA];
        float br = B->realp[i * IB];
        float bi = B->imagp[i * IB];

        if (conjugate) {
            C->realp[i * IC] = ar * br + ai * bi;
            C->imagp[i * IC] = ai * br - ar * bi;
        } else {
            C->realp[i * IC] = ar * br - ai * bi;
            C->imagp[i * IC] = ar * bi + ai * br;
        }
    }
}

ACCEL_COMPAT_EXPORT FFTSetup vDSP_create_fftsetup(vDSP_Length log2n, int radix) {
    return (FFTSetup)&codex_fftsetup_token;
}

ACCEL_COMPAT_EXPORT void vDSP_destroy_fftsetup(FFTSetup setup) {
}

ACCEL_COMPAT_EXPORT void vDSP_fft_zrip(FFTSetup setup, DSPSplitComplex *C, vDSP_Stride IC, vDSP_Length log2n, int direction) {
}
