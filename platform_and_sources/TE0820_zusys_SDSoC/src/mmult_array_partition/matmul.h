#ifndef MATMUL_H_
#define MATMUL_H_

// Maximum Array Size
#define MAX_SIZE 64

// Pragma below Specifies sds++ Compiler to Generate a Programmable Logic Design
// Which has Direct Memory Interface with DDR and PL.  
#pragma SDS data zero_copy(in1[0:mat_dim*mat_dim], in2[0:mat_dim*mat_dim], out[0:mat_dim*mat_dim])
void matmul_partition_accel(int *in1,  // Read-Only Matrix 1
                            int *in2,  // Read-Only Matrix 2
                            int *out,  // Output Result
                            int mat_dim); //  Matrix Dim (assumed only square matrix)
#endif
