# Definición de compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Definición de directorios
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = exec

# Archivos fuente y objeto
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Nombre del ejecutable
EXEC = $(BINDIR)/manager

# Regla para construir el ejecutable y compilar todo
all: $(EXEC)

# Regla para construir el ejecutable
$(EXEC): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regla para compilar los archivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Phony target para evitar conflictos con archivos que tengan los mismos nombres
.PHONY: all clean
