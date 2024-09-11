# Makefile

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++11 -Wall

# Archivos fuente
SRCS = tester.cpp selectionSort.cpp Mergesort.cpp Quicksort.cpp Iterativocubico.cpp Algoritmoiterativocúbicooptimizado.cpp auxiliar.cpp AlgoritmodeStrassen.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Ejecutable
EXEC = tester

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para ejecutar el programa
run: $(EXEC)
	./$(EXEC)

# Limpiar archivos compilados
clean:
	rm -f $(OBJS) $(EXEC)
