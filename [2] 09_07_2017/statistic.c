#include <math.h>

float Cauchy (float x) {
	float pi = 3.141592;

	return 1/(pi * (1 + pow(x,2)) );
}

float Gumbel (float x, float mu, float beta) {
	float z = (x - mu)/(beta);

	return (1/(beta)) * (exp((-1)*(z + (exp((-1)*z)))));
}

float Laplace (float x, float mu, float b) {
	return (1/(2*b)) * (exp(((-1)*(fabs(x - mu)))/(b)));
}