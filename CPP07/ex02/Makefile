CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = array

SRCS = main.cpp
OBJS = $(SRCS:%.cpp=.obj/%.o)

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@
 
.obj/%.o : %.cpp Makefile Array.hpp
	@if [ ! -d .obj ]; then 	mkdir -p $(@D); fi
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -rf .obj

fclean : clean
	rm -rf $(TARGET)

re : fclean $(TARGET)