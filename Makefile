# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -I/opt/homebrew/include -I$(INCDIR)

LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRCDIR = src
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj
BINDIR = $(BUILDDIR)/bin
INCDIR = include
ASSETDIR = assets

# Executable Name
TARGET = $(BINDIR)/team_kendra

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/team_kendra

# Libraries
LIBS = -L/opt/homebrew/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(TARGET): $(OBJDIR) $(BINDIR) $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Build complete. Executable placed in $(TARGET)."

# Compile rule
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

# Copy assets rule
.PHONY: copy-assets
copy-assets: $(BINDIR)
	@mkdir -p $(BINDIR)/$(ASSETDIR)
	@cp -r $(ASSETDIR)/* $(BINDIR)/$(ASSETDIR)/
	@echo "Assets copied to $(BINDIR)/$(ASSETDIR)."

# Build and copy assets
.PHONY: all
all: $(TARGET) copy-assets
	@echo "Build and asset copy complete."
