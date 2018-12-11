SOURCES=$(shell find . -name "*.cpp")
TARGETS=$(SOURCES:%.cpp=%)

REV=$(shell git rev-parse HEAD)
PREFIX=$(shell pwd)/
CXXFLAGS=-fsanitize=address -g

define CONFIG_TEMPLATE
[Main]
platform = x86-64
product = simple-crash-$@
product_version = $(REV)
os = linux

[Metadata]
pathPrefix = $(PREFIX)
buildFlags = $(CXXFLAGS)
endef

export CONFIG_TEMPLATE

.PHONY: all
all: $(TARGETS)

# Build with Coverage
coverage: CXXFLAGS += --coverage
.PHONY: coverage
coverage: $(TARGETS)

%: %.cpp
	clang++ $(CXXFLAGS) -o $@ $<
	@echo "$$CONFIG_TEMPLATE" > $@.fuzzmanagerconf

.PHONY: clean
clean:
	rm -f $(TARGETS)
