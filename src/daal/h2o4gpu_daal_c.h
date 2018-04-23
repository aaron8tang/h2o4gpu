/*
 * h2o4gpu_daal_c.h
 *
 *  Created on: Apr 2, 2018
 *      Author: monika
 */

#ifndef SRC_CPU_DAAL_H2O4GPU_DAAL_C_H_
#define SRC_CPU_DAAL_H2O4GPU_DAAL_C_H_

#include <daal.h>
#include <cstddef> // for size_t
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>


#define CATCH_DAAL 																				\
	catch(const std::runtime_error &e) { 														\
		fprintf(stderr, "Runtime error: %s in %s at line %d", e.what(), __FILE__, __LINE__); 	\
	} catch(const std::exception &e) {															\
		fprintf(stderr, "Error occurred: %s in %s at line %d", e.what(), __FILE__, __LINE__); 	\
	} catch (...) {																				\
		fprintf(stderr, "Unknown failure occurred. Possible memory corruption.");				\
	}

#ifdef __cplusplus
extern "C" {
#endif

//input to enter algorithms
void *CreateDaalInput(double*, size_t, size_t);

void *CreateDaalInputFeaturesDependent(double*, size_t, size_t, double*, size_t, size_t);
void* GetFeaturesData(void* input);
void* GetDependentTable(void* input);
void *CreateDaalInputFile(const char*);
void *CreateDaalInputFileFeaturesDependent(const char* filename, size_t, size_t);
void DeleteDaalInput(void* input);
void PrintDaalNumericTablePtr(void* input, const char* msg="", size_t rows=0, size_t cols = 0);
void PrintNTP(void*, const char * msg="", size_t rows=0, size_t cols=0);

// Singular value decomposition algorithm
void* CreateDaalSVD(void*);
void DeleteDaalSVD(void*);
void FitDaalSVD(void*);
void* GetDaalSVDSigma(void*);
const void* GetDaalRightSingularMatrix(void*);
const void* GetDaalLeftSingularMatrix(void*);

// Regression
void* CreateDaalRidgeRegression(void*);
void DeleteDaalRidgeRegression(void *);
void TrainDaalRidgeRegression(void *regression);
void PredictDaalRidgeRegression(void* regression, void* input);
const void* GetDaalRidgeRegressionBeta(void* regression);
void* GetDaalRidgeRegressionPredictionData(void* regression);

// Linear Regression
void* CreateDaalLinearRegression(void*);
void DeleteDaalLinearRegression(void*);
void TrainDaalLinearRegression(void *regression);
void PredictDaalLinearRegression(void* regression, void* input);
const void* GetDaalLinearRegressionBeta(void* regression);
const void* GetDaalLinearRegressionPredictionData(void* regression);

#ifdef __cplusplus
}
#endif

#endif /* SRC_CPU_DAAL_H2O4GPU_DAAL_C_H_ */