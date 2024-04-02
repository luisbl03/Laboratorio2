# Definición de compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

# Definición de directorios
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = exec

# Archivos fuente y objeto
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Nombre del ejecutable
EXEC = $(BINDIR)/SSOOIIGLE

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

run_leyesTrabajo:
	./$(EXEC) libros/"17_LEYES_DEL_TRABAJO_EN_EQUIPO.txt" equipo 2

run_leyesLiderazgo:
	./$(EXEC) libros/"21_LEYES_DEL_LIDERAZGO_-_JOHN_C._MAXWELL.txt" liderazgo 4

run_maneras:
	./$(EXEC) libros/"25_MANERAS_DE_GANARSE_A_LA_GENTE_-_.txt" gente 6

run_sirena:
	./$(EXEC) libros/"Abe_Shana_-_La_ultima_sirena.txt" sirena 8

run_actitud:
	./$(EXEC) libros/"ACTITUD_DE_VENCEDOR_-_JOHN_C._MAXWELL.txt" actitud 10

run_oro:
	./$(EXEC) libros/"El_Oro_Y_La_Ceniza_-_Abecassis_Eliette_.txt" oro 12

run_influencia:
	./$(EXEC) libros/"SEAMOS_PERSONAS_DE_INFLUENCIA_-_JOHN_MAXWELL.txt" influencia 14

run_sueno:
	./$(EXEC) libros/"VIVE_TU_SUENO_-_JOHN_MAXWELL.txt" sueño 16

# Phony target para evitar conflictos con archivos que tengan los mismos nombres
.PHONY: all clean
