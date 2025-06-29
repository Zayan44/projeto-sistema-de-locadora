# Makefile para Sistema de Logística de Entrega de Mercadorias (SLEM)

# Variáveis
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = executavel
SOURCES = main.cpp local.cpp veiculo.cpp pedido.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Regra principal
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Regra para criar arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpeza
clean:
	del *.o $(TARGET).exe 2>nul || true

# Regra para compilação alternativa com diferentes compiladores
mingw:
	x86_64-w64-mingw32-g++ -o $(TARGET) $(SOURCES)

gcc:
	gcc -lstdc++ -o $(TARGET) $(SOURCES)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Declarar regras que não são arquivos
.PHONY: all clean mingw gcc run
