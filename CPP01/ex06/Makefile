CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = harlFilter

SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:%.cpp=.obj/%.o)

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@

.obj/%.o : %.cpp Harl.hpp Makefile
	@if [ ! -d .obj ]; then 	mkdir -p $(@D); fi
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -rf .obj

fclean : clean
	rm -rf $(TARGET)

re : fclean $(TARGET)