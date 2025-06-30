ifneq (,$(findstring unsafe, $(BUILD)))
	TARGET := unsafe
else
	TARGET := safe
endif

ifneq (,$(findstring ref, $(BUILD)))
	MODE := --ref
else
	MODE :=
endif

CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -g

BUILD_DIR := build

all: $(TARGET)

core:
	$(CXX) $(CXXFLAGS) -c core/logger.cpp -o $(BUILD_DIR)/logger.o
util:
	$(CXX) $(CXXFLAGS) -c util/util.cpp -o $(BUILD_DIR)/util.o
build: clean core util
	$(CXX) $(CXXFLAGS) -c $(TARGET)/$(TARGET)-bank-statistics.cpp -o $(BUILD_DIR)/bank-statistics.o
	$(CXX) $(CXXFLAGS) -c $(TARGET)/$(TARGET)-bank-account.cpp -o $(BUILD_DIR)/bank-account.o
	$(CXX) $(CXXFLAGS) -c main-$(TARGET).cpp -o $(BUILD_DIR)/main.o
	$(CXX) $(CXXFLAGS) $(BUILD_DIR)/*.o -o $(BUILD_DIR)/banking-$(TARGET).exe

clean:
	rm -f build/*.exe build/*.o build/*.log

.PHONY: safe unsafe core util build
$(TARGET): build
	./$(BUILD_DIR)/banking-$(TARGET).exe $(MODE)
