CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -Wl,--stack,67108864

OBJS_ORDENADOR = balde.o bucketsort.o bolhadireta.o bolhacparada.o heapsort.o \
                 insbinaria.o insdireta.o insternaria.o mergesort.o \
                 quicksortfim.o quicksortmediana.o quicksortmeio.o \
                 radixsort.o selectionsort.o shellsort.o main.o

OBJS_GERA = gera.o

EXEC_ORDENADOR = ordenador
EXEC_GERA = gera

all: $(EXEC_ORDENADOR) $(EXEC_GERA)
	@echo "Limpando arquivos objeto..."
	@rm -f *.o
	@echo "Compilacao concluida!"

$(EXEC_ORDENADOR): $(OBJS_ORDENADOR)
	$(CC) $(CFLAGS) -o $(EXEC_ORDENADOR) $(OBJS_ORDENADOR) $(LDFLAGS)

$(EXEC_GERA): $(OBJS_GERA)
	$(CC) $(CFLAGS) -o $(EXEC_GERA) $(OBJS_GERA)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXEC_ORDENADOR) $(EXEC_GERA)

rebuild: clean all


.PHONY: all clean rebuild help
