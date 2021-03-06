/*
 * Copyright (c) 2018, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "unary_op.h"
#include "binary_op.h"


namespace MLCommon {
namespace LinAlg {

/**
 * @defgroup ScalarOps Scalar operations on the input buffer
 * @param out the output buffer
 * @param in the input buffer
 * @param scalar the scalar used in the operations
 * @param len number of elements in the input buffer
 * @{
 */
template <typename math_t>
void scalarAdd(math_t* out, const math_t* in, math_t scalar, int len) {
    unaryOp(out, in, scalar, len, [] __device__ (math_t in, math_t scalar) {
                                      return in + scalar;
                                  });
}

/**
 * @defgroup ScalarOps Scalar operations on the input buffer
 * @param out the output buffer
 * @param in the input buffer
 * @param scalar the scalar used in the operations
 * @param len number of elements in the input buffer
 * @{
 */
template <typename math_t>
void scalarAddMG(math_t* out, const math_t* in, math_t scalar, int len, int n_gpu, bool sync = false) {
    unaryOpMG(out, in, scalar, len, n_gpu, [] __device__ (math_t in, math_t scalar) {
                                      return in + scalar;
                                  }, sync);
}

template <typename math_t>
void scalarMultiply(math_t* out, const math_t* in, math_t scalar, int len) {
    unaryOp(out, in, scalar, len, [] __device__ (math_t in, math_t scalar) {
                                      return in * scalar;
                                  });
}

template <typename math_t>
void scalarMultiplyMG(math_t* out, const math_t* in, math_t scalar, int len, int n_gpu, bool sync = false) {
	unaryOpMG(out, in, scalar, len, n_gpu, [] __device__ (math_t in, math_t scalar) {
	                                      return in * scalar;
	                                  }, sync);
}
/** @} */


/**
 * @defgroup BinaryOps Element-wise binary operations on the input buffers
 * @param out the output buffer
 * @param in1 the first input buffer
 * @param in2 the second input buffer
 * @param len number of elements in the input buffers
 * @{
 */
template <typename math_t>
void eltwiseAdd(math_t* out, const math_t* in1, const math_t* in2, int len) {
    binaryOp(out, in1, in2, len, [] __device__ (math_t a, math_t b) {
                                     return a + b;
                                 });
}

template <typename math_t>
void eltwiseAddMG(TypeMG<math_t>* out, const TypeMG<math_t>* in1, const TypeMG<math_t>* in2, int len, int n_gpu, bool sync) {
	binaryOpMG(out, in1, in2, len, n_gpu, [] __device__ (math_t a, math_t b) {
	                                     return a + b;
	                                 }, sync);
}

template <typename math_t>
void eltwiseSub(math_t* out, const math_t* in1, const math_t* in2, int len) {
    binaryOp(out, in1, in2, len, [] __device__ (math_t a, math_t b) {
                                     return a - b;
                                 });
}

template <typename math_t>
void eltwiseSubMG(TypeMG<math_t>* out, const TypeMG<math_t>* in1, const TypeMG<math_t>* in2, int len, int n_gpu, bool sync) {
	binaryOpMG(out, in1, in2, len, n_gpu, [] __device__ (math_t a, math_t b) {
	                                     return a - b;
	                                 }, sync);
}

template <typename math_t>
void eltwiseMultiply(math_t* out, const math_t* in1, const math_t* in2, int len) {
    binaryOp(out, in1, in2, len, [] __device__ (math_t a, math_t b) {
                                     return a * b;
                                 });
}

template <typename math_t>
void eltwiseMultiplyMG(TypeMG<math_t>* out, const TypeMG<math_t>* in1, const TypeMG<math_t>* in2, int len, int n_gpu, bool sync) {
	binaryOpMG(out, in1, in2, len, n_gpu, [] __device__ (math_t a, math_t b) {
	                                     return a * b;
	                                 }, sync);
}

template <typename math_t>
void eltwiseDivide(math_t* out, const math_t* in1, const math_t* in2, int len) {
    binaryOp(out, in1, in2, len, [] __device__ (math_t a, math_t b) {
                                     return a / b;
                                 });
}

template <typename math_t>
void eltwiseDivideMG(TypeMG<math_t>* out, const TypeMG<math_t>* in1, const TypeMG<math_t>* in2, int len, int n_gpu, bool sync) {
	binaryOpMG(out, in1, in2, len, n_gpu, [] __device__ (math_t a, math_t b) {
	                                     return a / b;
	                                 }, sync);
}

/** @} */

}; // end namespace LinAlg
}; // end namespace MLCommon
