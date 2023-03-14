CPP = g++
CPP_OPTIONS = -std=c++17 -Wall -O3 -Llib

PROGRAM = malloc2 alloc2 dataIO2 innerprod2 matrixsum matrixproduct\
					sort vectornorm matrixnorm compensatedsum genrand producematrix\
					scalarmult simplegauss gauss

all : $(PROGRAM)

matrix.o : matrix.cpp
	$(CPP) $(CPP_OPTIONS) -o $@ -c $<

malloc2: program2.1_malloc2.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

alloc2: program2.2_allocate_array2.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

dataIO2: program2.3_dataIO2.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

innerprod2: program2.4_inner_product2.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

matrixsum: program2.5_matrix_sum.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

matrixproduct: program2.6_matrix_product.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

sort: program2.7_sort.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

vectornorm: program2.8_vector_norm.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

matrixnorm: program2.9_matrix_norm.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

compensatedsum: program2.10_compensated_summation.cpp
	$(CPP) $(CPP_OPTIONS) -o $@ $^

genrand: program2.11_random.cpp
	$(CPP) $(CPP_OPTIONS) -o $@ $^

producematrix: program2.12_produce_matrix.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

scalarmult: practice2.1_scalar_multiplication.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

simplegauss: program3.1_simple_gauss.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

gauss: program3.2_gauss.cpp matrix.o
	$(CPP) $(CPP_OPTIONS) -o $@ $^

.PHONY : install clean 
clean:
	rm -f *.o
	rm -f $(PROGRAM)
