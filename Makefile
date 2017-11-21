CXX = clang++
CXXFLAGS = -Isource -Ivendor/amirite -std=c++11

SOURCES := $(wildcard tests/*.cpp)
DEPS := $(SOURCES:.cpp=.d)
TESTS := $(SOURCES:.cpp=.test)

-include $(DEPS)

%.d: %.cpp
	@ $(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.test) >$@

%.test: %.cpp
	@ $(CXX) $(CXXFLAGS) -o $@ $<
	@ $@

.PHONY: test
test: $(TESTS)
