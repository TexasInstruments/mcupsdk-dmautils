/*
 *  Copyright (c) Texas Instruments Incorporated 2020
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*============================================================================*/
/*============================================================================*/

/**
----------------------------------------------------------------------------
@file    edma_utils_autoinc_compression_example.h
@brief   Demostrates a simple example of auto increment DMA to allow DSP to
operate a function on internal memory and transfer back the result with compression.
@version 0.0 (Jan 2020) : First version
----------------------------------------------------------------------------
*/

#ifndef EDMA_UTILS_AUTOINC_COMPRESSION_EXAMPLE_H_
#define EDMA_UTILS_AUTOINC_COMPRESSION_EXAMPLE_H_

typedef enum{
  DMAUTILSAUTOINC_ROW_FLOW = 0,
  DMAUTILSAUTOINC_COLUMN_FLOW
} DmaUtilsAutoInc_AnalyticComp_DataflowType;


typedef struct
{
  uint32_t testcaseId;
  uint32_t requirementId;
  uint32_t featurePlaneWidth;
  uint32_t featurePlaneHeight;
  uint32_t tensorWidth;
  uint32_t tensorHeight;
  uint32_t outProcSize; //Compression
  uint32_t inProcSize;  //decompression
  uint32_t Nco;      //Compression
  uint32_t Nci;       //decompression
  
  uint32_t outDataFlowType; //Compression
  uint32_t inDataFlowType;  //decompression
  
  uint32_t circularity;     //decompression
  uint32_t sbWidth;
  uint32_t sbHeight;
  
  uint8_t  algorithm;
  uint8_t  bias;
}DmautilsAutoInc_AnalyticCompTest_config;


int32_t tensorCopy( uint8_t*  const pInput, 
            uint8_t* const pOutput, 
            uint8_t* const sectr, 
            uint8_t* const cdbTable,
            DmautilsAutoInc_AnalyticCompTest_config *config, 
            uint8_t* pIntMemBase, 
            uint32_t intMemSize,
            uint32_t compress);


/*
 This function accepts an input image in external memory and write back to
 external memory after performing a horizontal flip of the image.
 The function can be called to work on direct external memory with cache
 by setting useDMA = 0
 The function can also be called to work using DMA, in that case user should
 provide internal memory buffer pointed by pIntMmeBase and available size
 by setting intMemSize. In case the internal memory is not sufficient, the
 function returns -1 and prints the required memory size

 whiel using DMA; this function tarnsfers an entire row of data in internal
 memory, then performs the flip operation and writes the result in internal
 memory. The result is then transfered back to external memory using DMA.
 In order to have DMA and CPU operate in parallel, 2 instances of input and
 output are created in internal memory

 The prupose of the function is to act as an example for DMA usage so the
 default core function of fliping the image is in natural C

*/


int32_t blockCopy(
  uint8_t*   const pInput,
  uint8_t*   const pOutput,
  uint8_t*   sectr,
  uint8_t*   cdbTable,
  uint16_t   width,
  uint16_t   height,
  uint8_t*   pIntMemBase,
  uint32_t   intMemSize,
  uint8_t    algorithm,
  uint8_t    bias,
  uint8_t    compress
  );




#endif /*EDMA_UTILS_AUTOINC_COMPRESSION_EXAMPLE_H_*/
