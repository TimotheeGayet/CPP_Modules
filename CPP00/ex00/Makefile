CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = megaphone

SRCS = megaphone.cpp
OBJS = megaphone.o

$(TARGET) : $(OBJS)
	$(CXX) $< -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR) :
	mkdir -p $@

.PHONY : clean
clean :
	rm -rf $(TARGET)
	rm -rf $(OBJS)
