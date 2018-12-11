SOURCES=$(shell find . -name "*.cpp")
TARGETS=$(SOURCES:%.cpp=%)

.PHONY: all
all: $(TARGETS)

# Build with Coverage
coverage: CXXFLAGS += --coverage
.PHONY: coverage
coverage: $(TARGETS)

%: %.cpp
	clang++ $(CXXFLAGS) -fsanitize=address -g -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGETS)
