#include <stdio.h>
#include <stdlib.h>

extern imgCvtGrayInttoFloat(unsigned int row, unsigned int col, unsigned int* data);

int main() {
	unsigned const int ARR_SIZE = 1000000;
	unsigned int row, col;
	unsigned long long m_size;
	row = col = 0;

	printf("INPUT ROW SIZE: ");
	scanf_s(" %d", &row);
	printf("INPUT COL SIZE: ");
	scanf_s(" %d", &col);
	m_size = row * col;

	//allocate if needed
	unsigned int* data = malloc(m_size * sizeof(int));
	
	
	// get data
	for (unsigned long long i = 0; i < m_size; i++) {
		scanf_s(" %u", &data[i]);
	}
	
	// function proper
	unsigned long long result = imgCvtGrayInttoFloat(row, col, data);
	if (result != 1) {
		printf("\nERROR");
		return 0;
	}

	// read float data as float type
	float* float_data = data;

	//print
	for (unsigned int i = 0; i < row; i++) {
		for (unsigned int j = 0; j < col; j++) {
			printf("%.2f  ", float_data[i * (col) + j]);
		}
		printf("\n");
	}

	// free malloc'd array
	free(data);
	data = NULL;
	return 0;
}